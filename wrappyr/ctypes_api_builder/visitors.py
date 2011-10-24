import string
from wrappyr.ctypes_api_builder.structure import CTypesStructureVisitor, CTypesStructure

class UninterestingCopyConstructorRemover(CTypesStructureVisitor):
    def visit_Method(self, f):
        if f.raw:
            return

        ops_to_remove = []
        for op in f.ops:
            if f.name == '__init__' and len(f.ops) > 1 \
                    and f.parent and len(op.args) == 1 \
                    and op.args[0].type == f.parent:
                ops_to_remove.append(op)
        for op in ops_to_remove:
            f.remove_operation(op)

class ConflictingOverloadRemover(CTypesStructureVisitor):
    def process_function(self, f):
        if f.raw:
            return

        ops = sorted(f.ops, key = lambda op: len(op.args))
        args = []
        ops_to_remove = []
        for op in ops:
            if args and any(left.type != right.type for left, right
                    in zip(args[-1], op.args)):
                ops_to_remove.append(op)
            else:
                args.append(op.args[len(args[-1]) if args else 0:])
        for op in ops_to_remove:
            f.remove_operation(op)

    def visit_Method(self, method):
        self.process_function(method)

    def visit_Function(self, f):
        self.process_function(f)

class AmbigousOverloadRemover(CTypesStructureVisitor):
    def process_function(self, f):
        if f.raw or len(f.ops) <= 1:
            return

        calls_to_remove = []
        arg_lists = []
        for call in f.ops:
            arg_list = tuple(arg.type for arg in call.args)
            if arg_list in arg_lists:
                calls_to_remove.append(call)
            else:
                arg_lists.append(arg_list)
        for call in calls_to_remove:
            f.remove_operation(call)

    def visit_Method(self, method):
        self.process_function(method)

    def visit_Function(self, f):
        self.process_function(f)

class PythonKeywordRemover(CTypesStructureVisitor):
    python_keywords = set(['def', 'class', 'for', 'in', 'pass'])

    def __init__(self):
        self.letters = set(string.ascii_lowercase)

    def process_function(self, f):
        if f.raw:
            return

        available_letters = None
        for call in f.ops:
            for arg in call.args:
                if not arg.name in self.python_keywords:
                    continue

                if not available_letters:
                    available_letters = self.letters - set(arg.name for arg in call.args)
                arg.name = available_letters.pop()

    def visit_Method(self, method):
        self.process_function(method)

    def visit_Function(self, f):
        self.process_function(f)

class Box2DBodyCreateFixtureFixer(CTypesStructureVisitor):
    def visit_Method(self, method):
        if method.parent != self.b2Body or method.name != "CreateFixture":
            return

        to_remove = None
        for call in method.ops:
            if len(call.args) > 1:
                to_remove = call
        if to_remove:
            method.remove_operation(to_remove)

    def process(self, node):
        if isinstance(node, CTypesStructure):
            self.b2Body = node.get_by_path('Box2D.b2Body')

        CTypesStructureVisitor.process(self, node)
