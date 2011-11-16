from contextlib import contextmanager
from ctypes import CDLL, c_int
import inspect
import os
import shutil
import subprocess
from tempfile import mkstemp, mkdtemp
from importlib import import_module
import sys
import unittest2 as unittest
from lxml.etree import fromstring as xml_from_string
from wrappyr.ctypes_api_builder.export import export_structure
from wrappyr.ctypes_api_builder.structure import CTypesStructure, Package, Call, Argument, Function, ReturnValue, Library

@contextmanager
def confirm_flag(test, name):
    flag = c_int.in_dll(test.mock, name)
    flag.value = 0
    yield
    test.assertTrue(flag.value, "Expected flag %s to be true" % name)

class TestExport(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.mock_source = os.path.join(os.path.dirname(__file__), 'mock.c')
        cls.mock_library_path = mkstemp(suffix='.so')[1]
        args = ["gcc", "-shared", "-g", "-o", cls.mock_library_path, cls.mock_source]
        subprocess.call(args)
        cls.mock = CDLL(cls.mock_library_path)

        cls.package_tests_path = os.environ.get('WRAPPYR_EXPORT_TESTS_PATH')
        if not cls.package_tests_path:
            cls.package_tests_path = mkdtemp()
        sys.path.append(cls.package_tests_path)

    @classmethod
    def tearDownClass(cls):
        os.remove(cls.mock_library_path)
        if 'WRAPPYR_EXPORT_TESTS_PATH' not in os.environ:
            shutil.rmtree(cls.package_tests_path)

    def create_and_import(self, xml):
        name = inspect.stack()[1][3]
        path = os.path.join(self.package_tests_path, name)
        if os.access(path, os.F_OK):
            shutil.rmtree(path)

        xml = xml.format(root = name)
        structure = CTypesStructure.from_xml(xml_from_string(xml))
        structure.packages[name].add_library(Library("mock", self.mock_library_path, True))
        export_structure(structure, self.package_tests_path)

        mod = import_module(name)
        return mod

    def test_function_single_call(self):
        mod = self.create_and_import("""
        <ctypes>
            <package name="{root}">
                <function name="func">
                    <call symbol="first">
                        <returns type="ctypes.c_int" />
                    </call>
                </function>
            </package>
        </ctypes>
        """)

        with confirm_flag(self, 'gFirstCalled'):
            mod.func()

    def test_function_multiple_calls(self):
        mod = self.create_and_import("""
        <ctypes>
            <package name="{root}">
                <function name="func">
                    <call symbol="first">
                        <returns type="ctypes.c_int" />
                    </call>
                    <call symbol="second">
                        <argument type="ctypes.c_int" name="v" />
                        <returns type="ctypes.c_int" />
                    </call>
                </function>
            </package>
        </ctypes>
        """)

        with confirm_flag(self, 'gFirstCalled'):
            mod.func()
        with confirm_flag(self, 'gSecondCalled'):
            mod.func(475)

    def test_function_return_primitive(self):
        mod = self.create_and_import("""
        <ctypes>
            <package name="{root}">
                <function name="func">
                    <call symbol="second">
                        <argument type="ctypes.c_int" name="v" />
                        <returns type="ctypes.c_int" />
                    </call>
                </function>
            </package>
        </ctypes>
        """)

        with confirm_flag(self, 'gSecondCalled'):
            self.assertEqual(mod.func(348), 348)

    def test_function_return_class_without_ownership(self):
        mod = self.create_and_import("""
        <ctypes>
            <package name="{root}">
                <class name="Animal" />

                <function name="create_animal">
                    <call symbol="Animal_Create">
                        <returns type="{root}.Animal" ownership="false" />
                    </call>
                </function>
            </package>
        </ctypes>
        """)

        with confirm_flag(self, 'gAnimalCreated'):
            animal = mod.create_animal()
        self.assertFalse(animal._ownership)

    def test_function_return_class_with_ownership(self):
        mod = self.create_and_import("""
        <ctypes>
            <package name="{root}">
                <class name="Animal" />

                <function name="create_animal">
                    <call symbol="Animal_Create">
                        <returns type="{root}.Animal" ownership="true" />
                    </call>
                </function>
            </package>
        </ctypes>
        """)

        with confirm_flag(self, 'gAnimalCreated'):
            animal = mod.create_animal()
        self.assertTrue(animal._ownership)

    def test_function_argument_steals(self):
        mod = self.create_and_import("""
        <ctypes>
            <package name="{root}">
                <class name="Point">
                    <method name="__alloc__">
                        <call symbol="Point_CreateZero" />
                    </method>
                </class>

                <function name="distance_squared">
                    <call symbol="Point_DistanceSquared">
                        <argument type="{root}.Point" name="p" steals="true" />
                        <returns type="ctypes.c_int" />
                    </call>
                </function>
            </package>
        </ctypes>
        """)

        with confirm_flag(self, 'gZeroPointCreated'):
            p = mod.Point()
        with confirm_flag(self, 'gPointDistanceSquared'):
            mod.distance_squared(p)
        self.assertFalse(p._ownership)

    def test_function_argument_invalidates(self):
        mod = self.create_and_import("""
        <ctypes>
            <package name="{root}">
                <class name="Point">
                    <method name="__alloc__">
                        <call symbol="Point_CreateZero" />
                    </method>
                </class>

                <function name="distance_squared">
                    <call symbol="Point_DistanceSquared">
                        <argument type="{root}.Point" name="p" invalidates="true" />
                        <returns type="ctypes.c_int" />
                    </call>
                </function>
            </package>
        </ctypes>
        """)

        with confirm_flag(self, 'gZeroPointCreated'):
            p = mod.Point()
        with confirm_flag(self, 'gPointDistanceSquared'):
            mod.distance_squared(p)
        self.assertFalse(p._valid)

    def test_class_creation(self):
        mod = self.create_and_import("""
        <ctypes>
            <package name="{root}">
                <class name="Point">
                    <method name="__alloc__">
                        <call symbol="Point_CreateZero" />
                    </method>
                </class>
            </package>
        </ctypes>
        """)

        with confirm_flag(self, 'gZeroPointCreated'):
            self.assertIsInstance(mod.Point(), mod.Point)

    def test_class_method_call(self):
        mod = self.create_and_import("""
        <ctypes>
            <package name="{root}">
                <class name="Point">
                    <method name="__alloc__">
                        <call symbol="Point_CreateZero" />
                        <call symbol="Point_Create">
                            <argument type="ctypes.c_int" name="x" />
                            <argument type="ctypes.c_int" name="y" />
                        </call>
                    </method>
                    <method name="distance_squared">
                        <call symbol="Point_DistanceSquared">
                            <returns type="ctypes.c_int" />
                        </call>
                    </method>
                </class>
            </package>
        </ctypes>
        """)

        with confirm_flag(self, 'gZeroPointCreated'):
            self.assertEqual(mod.Point().distance_squared(), 0)
        with confirm_flag(self, 'gPointCreated'):
            self.assertEqual(mod.Point(2, 2).distance_squared(), 8)

    def test_class_static_method_call(self):
        mod = self.create_and_import("""
        <ctypes>
            <package name="{root}">
                <class name="Spam">
                    <method name="static" static="true">
                        <call symbol="first"></call>
                    </method>
                </class>
            </package>
        </ctypes>
        """)

        with confirm_flag(self, 'gFirstCalled'):
            mod.Spam.static()

    def test_class_member_calls(self):
        mod = self.create_and_import("""
        <ctypes>
            <package name="{root}">
                <class name="Point">
                    <method name="__alloc__">
                        <call symbol="Point_CreateZero" />
                        <call symbol="Point_Create">
                            <argument type="ctypes.c_int" name="x" />
                            <argument type="ctypes.c_int" name="y" />
                        </call>
                    </method>
                    <member name="x">
                        <getter>
                            <call symbol="Point_GetX">
                                <returns type="ctypes.c_int" />
                            </call>
                        </getter>
                        <setter>
                            <call symbol="Point_SetX">
                                <argument type="ctypes.c_int" name="v" />
                            </call>
                        </setter>
                    </member>
                </class>
            </package>
        </ctypes>
        """)

        with confirm_flag(self, 'gZeroPointCreated'):
            p = mod.Point()
        self.assertEqual(p.x, 0)
        p.x = 5
        self.assertEqual(p.x, 5)

        with confirm_flag(self, 'gPointCreated'):
            p = mod.Point(37, 81)
        self.assertEqual(p.x, 37)
        p.x *= 4
        self.assertEqual(p.x, 37 * 4)

    def test_class_inheritence_with_constructor(self):
        mod = self.create_and_import("""
        <ctypes>
            <package name="{root}">
                <class name="Animal">
                    <vtable>
                        <overridable name="speak" />
                    </vtable>

                    <method name="__alloc__">
                        <call symbol="Animal_Create" />
                    </method>
                    <method name="__alloc_derived__">
                        <call symbol="UserAnimal_Create">
                            <argument name="obj" type="ctypes.py_object" />
                            <argument name="vtable" type="ctypes.c_void_p" />
                            <returns type="ctypes.c_void_p" />
                        </call>
                    </method>
                </class>

                <function name="speak">
                    <call symbol="Animal_Speak">
                        <argument type="{root}.Animal" name="animal" />
                    </call>
                </function>
            </package>
        </ctypes>
        """)

        with confirm_flag(self, 'gAnimalCreated'):
            animal = mod.Animal()
        with confirm_flag(self, 'gAnimalSpeakDispatched'):
            with confirm_flag(self, 'gAnimalSpeakDefault'):
                mod.speak(animal)

        spoken = [False]
        class Python(mod.Animal):
            def speak(self):
                spoken[0] = True

        with confirm_flag(self, 'gUserAnimalCreated'):
            python = Python()
        with confirm_flag(self, 'gAnimalSpeakDispatched'):
            with confirm_flag(self, 'gUserAnimalSpeakDispatched'):
                mod.speak(python)
        self.assertTrue(spoken[0])

    def test_class_inheritence_without_constructor(self):
        mod = self.create_and_import("""
        <ctypes>
            <package name="{root}">
                <class name="Animal">
                    <vtable>
                        <overridable name="speak" />
                    </vtable>

                    <method name="__alloc_derived__">
                        <call symbol="UserAnimal_Create">
                            <argument name="obj" type="ctypes.py_object" />
                            <argument name="vtable" type="ctypes.c_void_p" />
                            <returns type="ctypes.c_void_p" />
                        </call>
                    </method>
                </class>

                <function name="speak">
                    <call symbol="Animal_Speak">
                        <argument type="{root}.Animal" name="animal" />
                    </call>
                </function>
            </package>
        </ctypes>
        """)

        spoken = [False]
        class Python(mod.Animal):
            def speak(self):
                spoken[0] = True

        with confirm_flag(self, 'gUserAnimalCreated'):
            python = Python()
        with confirm_flag(self, 'gAnimalSpeakDispatched'):
            with confirm_flag(self, 'gUserAnimalSpeakDispatched'):
                mod.speak(python)
        self.assertTrue(spoken[0])

    def test_class_cleanup(self):
        mod = self.create_and_import("""
        <ctypes>
            <package name="{root}">
                <class name="Point">
                    <method name="__alloc__">
                        <call symbol="Point_CreateZero" />
                    </method>
                    <method name="__dealloc__">
                        <call symbol="Point_Destroy" />
                    </method>
                </class>
            </package>
        </ctypes>
        """)

        with confirm_flag(self, 'gZeroPointCreated'):
            p = mod.Point()
        with confirm_flag(self, 'gPointDestroyed'):
            p.__del__()
        self.assertFalse(p._valid)

    def test_derived_class_cleanup(self):
        mod = self.create_and_import("""
        <ctypes>
            <package name="{root}">
                <class name="Animal">
                    <vtable>
                        <overridable name="speak" />
                    </vtable>

                    <method name="__alloc_derived__">
                        <call symbol="UserAnimal_Create">
                            <argument name="obj" type="ctypes.py_object" />
                            <argument name="vtable" type="ctypes.c_void_p" />
                            <returns type="ctypes.c_void_p" />
                        </call>
                    </method>
                    <method name="__dealloc_derived__">
                        <call symbol="UserAnimal_Destroy" />
                    </method>
                </class>
            </package>
        </ctypes>
        """)

        spoken = [False]
        class Python(mod.Animal):
            def speak(self):
                spoken[0] = True

        with confirm_flag(self, 'gUserAnimalCreated'):
            python = Python()
        with confirm_flag(self, 'gUserAnimalDestroyed'):
            python.__del__()
        self.assertFalse(python._valid)

    def test_cleanup_invalidated_class(self):
        mod = self.create_and_import("""
        <ctypes>
            <package name="{root}">
                <class name="Point">
                    <method name="__alloc__">
                        <call symbol="Point_CreateZero" />
                    </method>
                    <method name="__dealloc__">
                        <call symbol="Point_Destroy" />
                    </method>
                </class>
            </package>
        </ctypes>
        """)

        with confirm_flag(self, 'gZeroPointCreated'):
            p = mod.Point()
        with confirm_flag(self, 'gPointDestroyed'):
            p.__del__()
        
        self.assertFalse(p._valid)
        p.__del__()
        self.assertFalse(p._valid)

    def test_cleanup_unowned_class(self):
        mod = self.create_and_import("""
        <ctypes>
            <package name="{root}">
                <class name="Animal">
                    <method name="__dealloc__">
                        <call symbol="Animal_Destroy" />
                    </method>
                </class>

                <function name="create_animal">
                    <call symbol="Animal_Create">
                        <returns type="{root}.Animal" ownership="false" />
                    </call>
                </function>
            </package>
        </ctypes>
        """)

        with confirm_flag(self, 'gAnimalCreated'):
            animal = mod.create_animal()
        self.assertFalse(animal._ownership)
        self.assertTrue(animal._valid)
        
        animal.__del__()
        self.assertFalse(animal._ownership)
        self.assertTrue(animal._valid)

    def test_internal_inheritance(self):
        mod = self.create_and_import("""
        <ctypes>
            <package name="{root}">
                <class name="Animal">
                    <method name="__alloc__">
                        <call symbol="Animal_Create" />
                    </method>
                </class>

                <class name="Dog">
                    <base type="{root}.Animal" />

                    <method name="__alloc__">
                        <call symbol="Dog_Create" />
                    </method>
                </class>

                <function name="speak">
                    <call symbol="Animal_Speak">
                        <argument type="{root}.Animal" name="animal" />
                    </call>
                </function>
            </package>
        </ctypes>
        """)

        with confirm_flag(self, 'gAnimalCreated'):
            animal = mod.Animal()
        with confirm_flag(self, 'gAnimalSpeakDefault'):
            mod.speak(animal)
        with confirm_flag(self, 'gDogCreated'):
            dog = mod.Dog()

        self.assertIsInstance(dog, mod.Animal)
        with confirm_flag(self, 'gDogSpeak'):
            mod.speak(dog)
