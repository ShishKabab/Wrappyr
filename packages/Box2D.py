from wrappyr.code_data_conversion.exports import ExportFilter, HeaderExport, SourceExport, CtypesExport
from wrappyr.ctypes_api_builder.structure import CTypesStructureVisitor, CTypesStructure
from wrappyr.ctypes_api_builder.visitors import UninterestingCopyConstructorRemover, ConflictingOverloadRemover, AmbigousOverloadRemover, PythonKeywordRemover

class Box2DFilter(ExportFilter):
	def filter_namespace(self, ns, **opts):
		return not ns.name

	def filter_class(self, cls, **opts):
		if not ExportFilter.filter_class(self, cls):
			return False
		return cls.name.startswith("b2")

class Box2DHeaderExport(HeaderExport):
	filter_class = Box2DFilter

class Box2DSourceExport(SourceExport):
	filter_class = Box2DFilter

	def get_includes(self):
		return '#include <Box2D.h>\n#include "box2d.h"'

class Box2DCtypesExport(CtypesExport):
	filter_class = Box2DFilter

	def package_for_namespace(self, ns):
		return ns.name or "Box2D"

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

class Box2DPackage(object):
	def get_header_export(self):
		return Box2DHeaderExport()

	def get_source_export(self):
		return Box2DSourceExport()

	def get_ctypes_export(self):
		return Box2DCtypesExport()

	def get_source_language(self):
		return "c++"

	def process_ctypes_structure(self, structure):
		UninterestingCopyConstructorRemover().process(structure)
		Box2DBodyCreateFixtureFixer().process(structure)
		ConflictingOverloadRemover().process(structure)
		AmbigousOverloadRemover().process(structure)
		PythonKeywordRemover().process(structure)
