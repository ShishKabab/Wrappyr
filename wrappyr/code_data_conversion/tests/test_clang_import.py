import os
from wrappyr.code_data_conversion.imports.clang import ClangImporter
from wrappyr.code_data_conversion.tests.test_import import TestImport

class TestClangImport(TestImport):
    @classmethod
    def setUpClass(cls):
        test_file = os.path.dirname(__file__)
        test_file = os.path.join(test_file, 'box2d_clang.xml')
        cls.imp = ClangImporter(test_file)
