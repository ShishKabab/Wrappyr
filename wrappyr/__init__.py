import os
from os import F_OK
from tempfile import mkstemp
from wrappyr.code_data_conversion.exports import HeaderExport, SourceExport, CtypesExport

class HeaderNotFound(Exception): pass
class Package(object):
	source_header_name = None
	generated_wrapper_prefix = None

	def get_header_export(self):
		return HeaderExport()

	def get_source_export(self):
		return SourceExport()

	def get_ctypes_export(self):
		return CtypesExport()

	def get_source_language(self):
		return "c++"

	def get_preferred_code_data_backend(self):
		return "gccxml"

	def get_source_header_path(self):
		if self.source_header_name:
			return self.find_header(self.source_header_name)

	def get_generated_header_path(self):
		if not self.generated_wrapper_prefix:
			self.generated_wrapper_prefix = mkstemp()[1]

		return self.generated_wrapper_prefix + ".h"

	def get_generated_source_path(self):
		if not self.generated_wrapper_prefix:
			self.generated_wrapper_prefix = mkstemp()[1]

		return self.generated_wrapper_prefix + ".cpp"

	def process_code_import(self, importer):
		pass

	def process_ctypes_structure(self, structure):
		pass

	def find_header(self, name):
		for prefix in ('/usr/include', '/usr/local/include'):
			path = os.path.join(prefix, name)
			if os.access(path, F_OK):
				return path
		raise HeaderNotFound(name)
