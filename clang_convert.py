#!/usr/bin/python2.6
import sys
import argparse

from clang_conversion.structure import ClangImporter, Class
from clang_conversion.export import ExportFilter, HeaderExport, SourceExport, CtypesExport

class CeguiFilter(ExportFilter):
	def filter_class(self, cls, **opts):
		if not ExportFilter.filter_class(self, cls, **opts):
			return False
		if not cls.namespace or cls.namespace[0] != "CEGUI":
			return False
		if cls.name.endswith("Exception"):
			return False
		if cls.name.endswith("Iterator"):
			return False

		return True

	def filter_method_signature(self, cls, sig, **opts):
		if not ExportFilter.filter_method_signature(self, cls, sig, **opts):
			return False

		return all(self.filter_type(arg.type) for arg in sig.args) and self.filter_type(sig.returns)

	def filter_type(self, tp, **opts):
		if tp.type == "builtin":
			return True
		if not tp.name.startswith("CEGUI::"):
			return False
		if tp.name.endswith("Iterator"):
			return False
		if tp.name.endswith("RefCounted"):
			return False
		return True

class CeguiHeaderExport(HeaderExport, CeguiFilter):
	def get_filter(self, importer):
		return CeguiFilter(importer)

class CeguiSourceExport(SourceExport):
	def get_filter(self, importer):
		return CeguiFilter(importer)

	def get_includes(self):
		return '#include <CEGUI.h>\n#include "cegui.h"'

class CeguiCtypesExport(CtypesExport):
	def package_for_namespace(self, ns):
		return ns.name

class Box2DFilter(ExportFilter):
	def filter_namespace(self, ns, **opts):
		return not ns.name

	def filter_class(self, cls, **opts):
		if not ExportFilter.filter_class(self, cls):
			return False
		return cls.name.startswith("b2")

class Box2DHeaderExport(HeaderExport):
	def get_filter(self, importer):
		return Box2DFilter(importer)

class Box2DSourceExport(SourceExport):
	def get_filter(self, importer):
		return Box2DFilter(importer)

	def get_includes(self):
		return '#include <Box2D.h>\n#include "box2d.h"'

class Box2DCtypesExport(CtypesExport):
	def get_filter(self, importer):
		return Box2DFilter(importer)

	def package_for_namespace(self, ns):
		return ns.name or "Box2D"

pkgs = {
	'__default__': {
		'header': HeaderExport,
		'source': SourceExport,
		'ctypes': CtypesExport,
	},
	'Box2D': {
		'header': Box2DHeaderExport,
		'source': Box2DSourceExport,
		'ctypes': Box2DCtypesExport,
	},
	'CEGUI': {
		'header': CeguiHeaderExport,
		'source': CeguiSourceExport,
		'ctypes': CeguiCtypesExport,
	},
}

if __name__ == "__main__":
	parser = argparse.ArgumentParser(prog = sys.argv[0])
	parser.add_argument("input")
	parser.add_argument("--header")
	parser.add_argument("--source")
	parser.add_argument("--ctypes")
	parser.add_argument("--package", default = "__default__")
	args = parser.parse_args()

	importer = ClangImporter(args.input)
	for i in ('header', 'source', 'ctypes'):
		arg = getattr(args, i)
		if arg:
			pkgs[args.package][i]().export(importer, arg)

