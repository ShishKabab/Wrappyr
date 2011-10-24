from functools import partial
from itertools import chain
from types import NoneType
import unittest2
from wrappyr.code_data_conversion.structure import (
        Class, Struct, Enumeration,
        Function, Method, FunctionSignature, Argument,
        Array, QualifiedType, Pointer, Reference,
        Node, Namespace, Member, Builtin)

# TODO: Write missing tests!
class TestImport(unittest2.TestCase):
    """Base class testing all specific import classes"""

    imp = None # Shut up my IDE complaining about missing property ;)

    def __init__(self, *args, **kwds):
        unittest2.TestCase.__init__(self, *args, **kwds)

        self.get_class = partial(self.get_node, registry = "classes")
        self.get_struct = partial(self.get_node, registry = "structs")
        self.get_function = partial(self.get_node, registry = "functions")
        self.get_enum = partial(self.get_node, registry = "enums")

    @classmethod
    def setUpClass(cls):
        """
        Derived classes are expected to override this method and
        assign an importer to self.imp here."""

        # We don't want any tests to run for this base class
        if type(cls) == TestImport:
            raise unittest2.SkipTest("Ignoring test in TestImport base class")
        else:
            raise unittest2.SkipTest("setUp method not overridden, see TestImport.setUp docs")

    def get_node(self, name, registry):
        try:
            return (i for i in getattr(self.imp, registry) if i.name == name).next()
        except StopIteration:
            pass

    def get_method(self, cls, name):
        try:
            return (i for i in cls.methods if i.name == name).next()
        except StopIteration:
            pass

    def get_member(self, cls, name):
        try:
            return (i for i in cls.members if i.name == name).next()
        except StopIteration:
            pass

    def iter_all_signatures(self):
        for f in self.imp.functions:
            for sig in f.signatures:
                yield sig
        for cls in self.imp.classes:
            for method in cls.methods:
                for sig in method.signatures:
                    yield sig
            for operator in cls.operators:
                for sig in operator.signatures:
                    yield sig

    def iter_signature_types(self, sig):
        """Yields return type and argument types"""

        yield sig.returns
        for arg in sig.args:
            yield arg.type

    def test_struct_import(self):
        pass

    def test_function_import(self):
        pass

    def test_function_signature_returns(self):
        pass

    def test_function_signature_arguments(self):
        pass

    def test_class_import(self):
        for cls in self.imp.classes:
            self.assertIsInstance(cls, Class)

            self.assertIsInstance(cls.constructors, list)
            for constructor in cls.constructors:
                self.assertIsInstance(constructor, FunctionSignature)
            if cls.destructor is not None:
                self.assertIsInstance(cls.destructor, FunctionSignature)

            for method in cls.methods:
                self.assertIsInstance(method, Method)
            for member in cls.members:
                self.assertIsInstance(member, Member)

        b2World = self.get_class('b2World')
        self.assertIsInstance(b2World, Class)
        self.assertIsInstance(b2World.constructors, list)
        self.assertTrue(b2World.constructors)

    def test_class_access(self):
        pass

    def test_class_bases(self):
        b2PolygonShape = self.get_class('b2PolygonShape')
        self.assertIsInstance(b2PolygonShape.bases, list)
        self.assertTrue(b2PolygonShape.bases)
        self.assertIsInstance(b2PolygonShape.bases[0], Class)
        self.assertEqual(b2PolygonShape.bases[0].name, 'b2Shape')

    def test_class_abstract(self):
        b2Shape = self.get_class('b2Shape')
        b2PolygonShape = self.get_class('b2PolygonShape')
        self.assertTrue(b2Shape.is_abstract())
        self.assertFalse(b2PolygonShape.is_abstract())

    def test_class_dynamic(self):
        b2Shape = self.get_class('b2Shape')
        b2PolygonShape = self.get_class('b2PolygonShape')
        b2World = self.get_class('b2World')
        self.assertTrue(b2Shape.is_dynamic())
#               self.assertFalse(b2PolygonShape.is_dynamic()) ???
        self.assertFalse(b2World.is_dynamic())

    def test_class_members(self):
        for cls in self.imp.classes:
            for member in cls.members:
                self.assertIsInstance(member, Member)
                self.assertIsInstance(member.type, QualifiedType)

    def test_method_import(self):
        b2World = self.get_class("b2World")
        b2World_Step = self.get_method(b2World, "Step")
        self.assertIsInstance(b2World_Step, Method)

    def test_method_signature_virtual(self):
        b2Draw = self.get_class("b2Draw")
        b2Draw_DrawPolygon = self.get_method(b2Draw, "DrawPolygon")
        self.assertTrue(b2Draw_DrawPolygon.signatures[0].virtual)
        self.assertTrue(b2Draw_DrawPolygon.signatures[0].pure)

    def test_method_signature_const(self):
        b2Shape = self.get_class("b2Shape")
        b2Shape_TestPoint = self.get_method(b2Shape, "TestPoint")
        self.assertTrue(b2Shape_TestPoint.signatures[0].const)

    def test_method_signature_arguments(self):
        for cls in self.imp.classes:
            for method in cls.methods:
                for signature in method.signatures:
                    self.assertIsInstance(signature, FunctionSignature)

                    for arg in signature.args:
                        self.assertIsInstance(arg, Argument)
                        self.assertIsInstance(arg.type, QualifiedType)

    def test_method_signature_argument_constness(self):
        b2World = self.get_class("b2World")
        self.assertTrue(b2World.constructors)

        sig = b2World.constructors[0]
        arg = sig.args[0]
        self.assertIsInstance(arg.type, QualifiedType)
        self.assertIsInstance(arg.type.type, Reference)
        self.assertIsInstance(arg.type.type.type, QualifiedType)
        self.assertTrue(arg.type.type.type.const)

    def test_method_signature_access(self):
        pass

    def test_method_signature_constructor(self):
        pass

    def test_method_signature_destructor(self):
        pass

    def test_method_signature_static(self):
        pass

    def test_method_signature_returns(self):
        pass

    def test_enum_import(self):
        for enum in self.imp.enums:
            self.assertIsInstance(enum, Enumeration)

        b2BodyType = self.get_enum('b2BodyType')
        self.assertIsInstance(b2BodyType, Enumeration)

    def test_enum_access(self):
        pass

    def test_enum_fields(self):
        b2BodyType = self.get_enum('b2BodyType')
        self.assertIsInstance(b2BodyType.fields, list)
        for name, value in b2BodyType.fields:
            self.assertIsInstance(name, basestring)
            self.assertIsInstance(value, int)

        self.assertEqual(b2BodyType.fields[0], ('b2_staticBody', 0))
        self.assertEqual(b2BodyType.fields[1], ('b2_kinematicBody', 1))

    def test_contexts(self):
        # I'm not sure whether I want unique qualified types everywhere one is used
        # since it would not allow sharing of qualified types. Therefore the contexts
        # of (qualified, pointer, etc.) types are not tested. The rest should be ;)

        for node in chain(self.imp.classes, self.imp.enums, self.imp.structs):
            self.assertIsInstance(node.context, (Class, Struct, Namespace))
        for cls in self.imp.classes:
            for method in cls.methods:
                self.assertIs(method.context, cls)
            for member in cls.methods:
                self.assertIs(member.context, cls)
            for operator in cls.operators:
                self.assertIs(operator.context, cls)

        functions = self.imp.functions
        methods = (method for cls in self.imp.classes for method in cls.methods)
        operators = (op for cls in self.imp.classes for op in cls.operators)
        for f in chain(functions, methods, operators):
            for sig in f.signatures:
                self.assertIs(sig.context, f)

                for arg in sig.args:
                    self.assertIs(arg.context, sig)

    def test_types(self):
        """Check whether all types are QualifiedTypes

        Member, argument, return value, pointer, reference and
        array types must be indicated by a QualifiedType instance.
        """

        signatures = self.iter_all_signatures()
        signature_types = chain.from_iterable(self.iter_signature_types(sig) for sig in signatures)

        nodes = chain(self.imp.classes, self.imp.structs)
        members = (member for node in nodes for member in node.members)
        member_types = (member.type for member in members)

        for type in chain(signature_types, member_types):
            self.assertIsInstance(type, QualifiedType)
            self.assertIsInstance(type.type, (NoneType, Node))
            while isinstance(type.type, (Reference, Pointer, Array)):
                pointee = type.type.type
                self.assertIsInstance(pointee, QualifiedType)
                self.assertIsInstance(pointee.type, (NoneType, Node))
                type = pointee

        # Class pointer
        b2Fixture = self.get_class("b2Fixture")
        self.assertIsInstance(b2Fixture, Class)
        b2Fixture_GetShape = self.get_method(b2Fixture, "GetShape")
        self.assertIsInstance(b2Fixture_GetShape, Method)
        sig = b2Fixture_GetShape.signatures[0]
        self.assertIsInstance(sig, FunctionSignature)
        self.assertIsInstance(sig.returns, QualifiedType)
        self.assertIsInstance(sig.returns.type, Pointer)
        self.assertIsInstance(sig.returns.type.type, QualifiedType)
        self.assertIsInstance(sig.returns.type.type.type, Class)

        # Builtin
        b2World = self.get_class("b2World")
        self.assertIsInstance(b2World, Class)
        flags = self.get_member(b2World, "m_flags")
        self.assertIsInstance(flags, Member)
        self.assertIsInstance(flags.type, QualifiedType)
        self.assertIsInstance(flags.type.type, Builtin)

    def test_namespaces(self, ns = None):
        ns = ns or self.imp.root_namespace
        for node in ns.nodes:
            self.assertIsInstance(node, (Function, Struct, Class, Enumeration))
        for child in ns.children.values():
            self.test_namespaces(child)

    def test_locations(self):
        pass
