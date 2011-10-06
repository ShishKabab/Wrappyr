import os
from wrappyr.code_data_conversion.imports.gccxml import GCCXMLImporter
from wrappyr.code_data_conversion.tests.test_import import TestImport

class TestGCCXMLImport(TestImport):
	@classmethod
	def setUpClass(cls):
		test_file = os.path.dirname(__file__)
		test_file = os.path.join(test_file, 'box2d_gccxml.xml')
		cls.imp = GCCXMLImporter(test_file)
