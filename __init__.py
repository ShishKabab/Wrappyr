from wrappyr.code_data_conversion.exports import HeaderExport, SourceExport, CtypesExport

class Package(object):
	def get_header_export(self):
		return HeaderExport()

	def get_source_export(self):
		return SourceExport()

	def get_ctypes_export(self):
		return CtypesExport()

	def get_source_language(self):
		return "c++"

	def process_ctypes_structure(self, structure):
		pass
