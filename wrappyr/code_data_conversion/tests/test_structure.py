from itertools import combinations
import unittest2
from wrappyr.code_data_conversion.structure import Class, Enumeration, Array, QualifiedType, Pointer, Reference, Method, Namespace, FunctionSignature

class TestStructure(unittest2.TestCase):
    def test_qualified_type_equality(self):
        clsA = Class("ClsA")
        clsB = Class("ClsB")

        self.assertEqual(QualifiedType(clsA), QualifiedType(clsA))
        self.assertNotEqual(QualifiedType(clsA, True), QualifiedType(clsA, False))
        self.assertNotEqual(QualifiedType(clsA), QualifiedType(clsB))

    def test_array_equality(self):
        clsA = Class("ClsA")
        clsB = Class("ClsB")

        self.assertEqual(Array(QualifiedType(clsA)), Array(QualifiedType(clsA)))
        self.assertNotEqual(Array(QualifiedType(clsA)), Array(QualifiedType(clsB)))

    def test_pointer_equality(self):
        clsA = Class("ClsA")
        clsB = Class("ClsB")

        self.assertEqual(Pointer(QualifiedType(clsA)), Pointer(QualifiedType(clsA)))
        self.assertNotEqual(Pointer(QualifiedType(clsA)), Pointer(QualifiedType(clsB)))

    def test_reference_equality(self):
        clsA = Class("ClsA")
        clsB = Class("ClsB")

        self.assertEqual(Reference(QualifiedType(clsA)), Reference(QualifiedType(clsA)))
        self.assertNotEqual(Reference(QualifiedType(clsA)), Reference(QualifiedType(clsB)))

    def test_type_equality(self):
        clsA = Class("ClsA")
        clsB = Class("ClsB")

        for type in (Pointer, Reference, Array):
            self.assertEqual(type(QualifiedType(clsA)), type(QualifiedType(clsA)))
            self.assertNotEqual(type(QualifiedType(clsA)), type(QualifiedType(clsB)))

            # Test != operator
            self.assertFalse(type(QualifiedType(clsA)) != type(QualifiedType(clsA)))

    def test_different_type_equality(self):
        cls = Class("ClsA")

        for l, r in combinations((Array, Pointer, Reference, QualifiedType), 2):
            self.assertNotEqual(l(cls), r(cls))

    def test_total_pointers(self):
        cls = Class("ClsA")

        self.assertEqual(QualifiedType(Pointer(QualifiedType(cls))).get_total_pointers(), 1)

    def test_full_name(self):
        root = Namespace()
        child = root.get_child("A::B")
        cls = Class("ClsA")
        cls.context = child

        self.assertEqual(cls.get_full_name(), "A::B::ClsA")
        self.assertEqual(cls.get_full_name("_"), "A_B_ClsA")

    def test_overridden_signatures(self):
        clsA = Class("ClsA")
        clsB = Class("ClsB")
        clsB.bases.append(clsA)

        methodA = Method("test")
        methodA.signatures.append(FunctionSignature())
        methodA.signatures[0].context = methodA
        methodA.signatures[0].virtual = True
        methodB = Method("test")
        methodB.signatures.append(FunctionSignature())
        methodB.signatures[0].context = methodB

        clsA.methods.append(methodA); methodA.context = clsA
        clsB.methods.append(methodB); methodB.context = clsB

        self.assertEqual(clsA.get_overridable_signatures(), [[methodA.signatures[0]]])
        self.assertEqual(clsB.get_overridable_signatures(), [])

        methodB.signatures[0].virtual = True
        self.assertEqual(clsB.get_overridable_signatures(), [[methodB.signatures[0]]])

        methodB.signatures[0].const = True
        self.assertEqual(clsB.get_overridable_signatures(),
                                        [[methodB.signatures[0], methodA.signatures[0]]])
