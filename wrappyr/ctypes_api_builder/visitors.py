import string
from wrappyr.ctypes_api_builder.structure import CTypesStructureVisitor, CTypesStructure

class UninterestingCopyConstructorRemover(CTypesStructureVisitor):
    def visit_Method(self, f):
        calls_to_remove = []
        for call in f.calls:
            if f.name == '__alloc__' and len(f.calls) > 1 \
                    and f.parent and len(call.args) == 1 \
                    and call.args[0].type == f.parent:
                calls_to_remove.append(call)
        for call in calls_to_remove:
            f.remove_call(call)

class ConflictingOverloadRemover(CTypesStructureVisitor):
    def process_function(self, f):
        calls = sorted(f.calls, key = lambda call: len(call.args))
        args = []
        calls_to_remove = []
        for call in calls:
            if args and any(left.type != right.type for left, right
                    in zip(args[-1], call.args)):
                calls_to_remove.append(call)
            else:
                args.append(call.args[len(args[-1]) if args else 0:])
        for call in calls_to_remove:
            f.remove_call(call)

    def visit_Method(self, method):
        self.process_function(method)

    def visit_Function(self, f):
        self.process_function(f)

class AmbiguousOverloadRemover(CTypesStructureVisitor):
    def process_function(self, f):
        if len(f.calls) <= 1:
            return

        calls_to_remove = []
        arg_lists = []
        for call in f.calls:
            arg_list = tuple(arg.type for arg in call.args)
            if arg_list in arg_lists:
                calls_to_remove.append(call)
            else:
                arg_lists.append(arg_list)
        for call in calls_to_remove:
            f.remove_call(call)

    def visit_Method(self, method):
        self.process_function(method)

    def visit_Function(self, f):
        self.process_function(f)

class PythonKeywordRemover(CTypesStructureVisitor):
    python_keywords = set(['def', 'class', 'for', 'in', 'pass'])

    def __init__(self):
        self.letters = set(string.ascii_lowercase)

    def process_function(self, f):
        available_letters = None
        for call in f.calls:
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
