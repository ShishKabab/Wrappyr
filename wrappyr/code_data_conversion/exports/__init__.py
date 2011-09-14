from __future__ import absolute_import
from wrappyr.code_data_conversion.structure import Class
from wrappyr.utils.str import as_camelcase, SourceBlock

class ExportFilter(object):
	def __init__(self, importer):
		self.importer = importer

	def filter_namespace(self, ns, **opts):
		return True

	def filter_class(self, cls, **opts):
		return cls.is_valid(self.importer) and \
			cls.access in ('unknown', 'public')

	def filter_method(self, cls, method, **opts):
		return any(self.filter_method_signature(cls, sig)
			for sig in method)

	def filter_method_signature(self, cls, signature, **opts):
		return (self.filter_function(signature)
			# Export only public methods
			and (signature.access == 'public' or
				 (opts.get("inherited") == True and signature.access == "protected"))
			# Static methods are not supported yet
			and not signature.is_static)

	def filter_member(self, cls, member, **opts):
		type = member.type

		return (# Export only public members
			member.access == 'public'
			# Some member names are empty in Clang XML, find out why
			and member.name
			# We don't know how to handle pointers other
			# than C++ object pointers
			# and not (type.type in ('builtin', 'enum') and type.pointers)
			#and (not type.id or self.importer.nodes.get(type.id))

			# If this type is a struct or class, the class
			# must be declared
			and (type.type != 'record' or self.importer.nodes.get(type.id))
			# We don't know how to handle multi-dimensional pointers
			and type.pointers <= 1
			# The type must be something we can handle
			and type.valid)

	def filter_function(self, f, **opts):
		return (
			# Operator overload is not supported
			not f.name.startswith('operator')
			#and all(not arg.type.id or self.importer.nodes.get(arg.type.id) for arg in f.args)
			#and (not f.returns.id or self.importer.nodes.get(f.returns.id))

			# We must be able to handle all argument and
			# return value types
			and f.valid)

class ClangExport(object):
	filter_class = ExportFilter

	@staticmethod
	def iletters():
		return (chr(i) for i in xrange(ord('a'), ord('m')))

	def get_filter(self, importer):
		return self.filter_class(importer)

	def symbol_for_constructor(self, cls, cls_name_underscore, constructor = None):
		return "%s__Create%s" % (
			cls_name_underscore,
			(cls.constructors.index(constructor) if len(cls.constructors) > 1 else '')
		)

	def symbol_for_array_constructor(self, cls, cls_name_underscore):
		return "%s__CreateArray" % (
			cls_name_underscore
		)

	def symbol_for_destructor(self, cls, cls_name_underscore, destructor):
		return "%s__Destroy" % cls_name_underscore

	def symbol_for_array_destructor(self, cls, cls_name_underscore):
		return "%s__DestroyArray" % cls_name_underscore

	def symbol_for_class_size(self, cls, cls_name_underscore):
		return "%s__Size" % cls_name_underscore

	def symbol_for_method_signature(self, cls, cls_name_underscore, method, signature):
		return "%s_%s%s" % (
			cls_name_underscore,
			signature.name,
			(method.index(signature) if len(method) > 1 else '')
		)

	def symbols_for_member(self, cls, cls_name_underscore, member):
		camelcased = as_camelcase(member.name)
		return (
			"%s__Get_%s" % (cls_name_underscore, camelcased),
			"%s__Set_%s" % (cls_name_underscore, camelcased)
		)

	def symbol_for_array_element(self, cls, full_name_underscore):
		return "%s__ArrayElement" % full_name_underscore

	def symbol_for_inheritance_constructor(self, cls, cls_name_underscore,
										   constructor):
		return "%s__CreateInherited%s" % (
			cls_name_underscore,
			(cls.constructors.index(constructor) if len(cls.constructors) > 1 else '')
		)

	def setup(self, importer):
		self.importer = importer
		self.filter = self.get_filter(importer)

	def export_namespace(self, ns):
		block = SourceBlock()
		for node in ns.nodes:
			if isinstance(node, Class):
				if self.filter.filter_class(node):
					block.add_block(self.export_class(node))
		for child in ns.children.values():
			block.add_block(self.export_namespace(child))

		return block

from wrappyr.code_data_conversion.exports.header import HeaderExport
from wrappyr.code_data_conversion.exports.source import SourceExport
from wrappyr.code_data_conversion.exports.ctypes import CtypesExport