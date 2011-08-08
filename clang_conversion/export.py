import sys
import os
import time
import re
import argparse
import pprint
from itertools import chain
from collections import defaultdict

from lxml.etree import parse as parse_xml, fromstring as parse_xml_from_string

from structure import Class, Function

class SourceBlock(object):
	def __init__(self):
		self.lines = []

	def add_line(self, text, level = 0):
		self.lines.append((level, text))

	def add_block(self, block, base_level = 0):
		for level, text in block.lines:
			self.lines.append((base_level + level, text))

	def as_text(self, base_level = 0):
		return "\n".join("%s%s" % ("\t" * (base_level + level), text)
			for level, text in self.lines)

camelcase_regex = re.compile("_([A-Za-z0-9])")
def as_camelcase(s):
	if not s:
		return s
	s = s[0].upper() + s[1:]
	s = camelcase_regex.sub(lambda match: match.group(1).upper(), s)
	return s

class ExportFilter(object):
	def __init__(self, importer):
		self.importer = importer

	def filter_namespace(self, ns):
		return True

	def filter_class(self, cls):
		return cls.is_valid(self.importer) and cls.access in ('unknown', 'public')

	def filter_method(self, cls, method):
		return any(self.filter_method_signature(cls, sig) for sig in method)

	def filter_method_signature(self, cls, signature):
		return self.filter_function(signature) and \
			signature.access == 'public' and \
			not signature.is_static

	def filter_member(self, cls, member):
		type = member.type

		return (member.access == 'public' and member.name
			and not (type.type in ('builtin', 'enum') and type.pointers)
			#and (not type.id or self.importer.nodes.get(type.id))
			and (type.type != 'record' or self.importer.nodes.get(type.id))
			and type.pointers <= 1
			and type.valid)

	def filter_function(self, f):
		return (not f.name.startswith('operator')
			#and all(not arg.type.id or self.importer.nodes.get(arg.type.id) for arg in f.args)
			#and (not f.returns.id or self.importer.nodes.get(f.returns.id))
			and f.valid)

class ClangExport(object):
	@staticmethod
	def iletters():
		return (chr(i) for i in xrange(ord('a'), ord('m')))

	def get_filter(self, importer):
		return ExportFilter(importer)

	def symbol_for_constructor(self, cls, cls_name_underscore, constructor = None):
		return "%s__Create%s" % (
			cls_name_underscore,
			(cls.constructors.index(constructor) if len(cls.constructors) > 1 else '')
		)

	def symbol_for_destructor(self, cls, cls_name_underscore, destructor):
		return "%s__Destroy" % cls_name_underscore

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

class HeaderExport(ClangExport):
	def export_class(self, cls):
		full_name_underscore = cls.get_full_name("__")
		block = SourceBlock()
		block.add_line("")
		block.add_line("//")
		block.add_line("// Begin class '%s'" % cls.get_full_name())
		block.add_line("//")

		# Constructor
		if not cls.is_abstract(self.importer):
			if cls.constructors:
				for i, constructor in enumerate(cls.constructors):
					if not self.filter.filter_method_signature(cls, constructor):
						continue
					block.add_line("void* %s(%s);" % (
						self.symbol_for_constructor(cls, full_name_underscore, constructor),
						constructor.args_as_string()
					))
			else:
				block.add_line("void* %s();" % (
					self.symbol_for_constructor(cls, full_name_underscore),
				))

		# Destructor
		if not cls.destructor or cls.destructor.access == 'public':
			block.add_line("void %s(void*);" % self.symbol_for_destructor(
				cls, full_name_underscore, cls.destructor))

		# Methods
		for method in cls.methods.values():
			for i, signature in enumerate(method):
				if not self.filter.filter_method_signature(cls, signature):
						continue

				returns = signature.returns.as_string()
				args = "void*%s%s" % (
					", " if signature.args else '',
					signature.args_as_string() if signature.args else ''
				)
				block.add_line("%s %s(%s);" % (
					returns,
					self.symbol_for_method_signature(cls, full_name_underscore, method, signature),
					args
				))

		# Members
		for member in cls.members:
			if not self.filter.filter_member(cls, member):
				continue

			returns = member.type.as_string()
			getter, setter = self.symbols_for_member(cls, full_name_underscore, member)

			block.add_line("%s %s(void*);" % (
				returns,
				getter
			))
			block.add_line("void %s(void*, %s);" % (
				setter,
				member.type.as_string(),
			))

		return block

	def export(self, importer, path):
		self.setup(importer)

		with open(path, 'w') as f:
			f.write('extern "C" {\n')
			f.write(self.export_namespace(importer.root_namespace)
				.as_text())
			f.write('\n}\n')

class SourceExport(ClangExport):
	letters = tuple(ClangExport.iletters())

	def get_includes(self):
		pass

	def args_as_params(self, f):
		args = []
		for arg, letter in zip(f.args, self.letters):
			args.append("%s((%s)%s)" % (
				"*" * (arg.type.refs + int(arg.type.is_cpp_only())),
				arg.type.as_string(False),
				letter
			))

		return ", ".join(args)

	def export_class(self, cls):
		full_name = cls.get_full_name()
		full_name_underscore = cls.get_full_name("__")

		block = SourceBlock()
		block.add_line("")
		block.add_line("//")
		block.add_line("// Begin class '%s'" % cls.get_full_name())
		block.add_line("//")

		#if cls.name == 'b2Body':
			#import ipdb; ipdb.set_trace()

		# Constructor
		if not cls.is_abstract(self.importer):
			if cls.constructors:
				for constructor in cls.constructors:
					if not self.filter.filter_method_signature(cls, constructor):
						continue
					block.add_line("void* %s(%s){" % (
						self.symbol_for_constructor(cls, full_name_underscore, constructor),
						constructor.args_as_string(self.letters)
					))
					block.add_line("return new %s(%s);" % (
						full_name,
						self.args_as_params(constructor))
					, 1)
					block.add_line("}")
			else:
				block.add_line("void* %s(){" % (
					self.symbol_for_constructor(cls, full_name_underscore),
				))
				block.add_line("return new %s;" % full_name, 1)
				block.add_line("}")

		# Destructor
		if not cls.destructor or cls.destructor.access == 'public':
			block.add_line("void %s(void* cls){" % self.symbol_for_destructor(
				cls, full_name_underscore, cls.destructor))
			block.add_line("delete (%s*)cls;" % full_name, 1)
			block.add_line("}")

		# Methods
		for method in cls.methods.values():
			for i, signature in enumerate(method):
				if not self.filter.filter_method_signature(cls, signature):
					continue

				returns = signature.returns.as_string()
				args = "void* cls%s%s" % (
					", " if signature.args else '',
					signature.args_as_string(self.letters) if signature.args else ''
				)
				block.add_line("%s %s(%s){" % (
					returns,
					self.symbol_for_method_signature(cls, full_name_underscore, method, signature),
					args
				))

				returns = signature.returns
				block.add_line("%s%s%s%s((%s*)cls)->%s(%s)%s%s;" % (
					("return " if returns.pointers or returns.name != 'void' else ''),
					("new %s(" % returns.name if returns.is_cpp_only() else ''),
					("const_cast<%s%s>(" % (returns.name, "*" * (returns.refs + returns.pointers))
						if returns.const and not returns.is_cpp_only() else ''),
					"&" if returns.refs else '',
					full_name,
					signature.name,
					self.args_as_params(signature),
					(")" if returns.const and not returns.is_cpp_only() else ''),
					(")" if returns.is_cpp_only() else '')
				), 1)
				block.add_line("}")

		# Members
		for member in cls.members:
			if not self.filter.filter_member(cls, member):
				continue

			getter, setter = self.symbols_for_member(cls, full_name_underscore, member)
			type = member.type

			# Getter
			returns = member.type.as_string()
			block.add_line("%s %s(void* cls){" % (
				returns,
				getter
			))
			block.add_line("return %s%s((%s*)cls)->%s%s;" % (
				("const_cast<%s%s>(" % (type.name, "*" * (type.refs + type.pointers + int(type.is_cpp_only())))
					if type.const else ''),
				'&' if type.is_cpp_only() else '',
				full_name,
				member.name,
				(")" if type.const else ''),
			), 1)
			block.add_line("}")


			# Setter
			block.add_line("void %s(void* cls, %s v){" % (
				setter,
				member.type.as_string(),
			))
			block.add_line("((%s*)cls)->%s = %s((%s%s)v);" % (
				full_name,
				member.name,
				'*' if type.is_cpp_only() else '',
				member.type.name,
				"*" * (type.refs + type.pointers + int(type.is_cpp_only()))
			), 1)
			block.add_line("}")

		return block

	def export(self, importer, path):
		self.setup(importer)

		with open(path, 'w') as f:
			includes = self.get_includes()
			if includes:
				f.write('%s\n\n' % includes)
			f.write(self.export_namespace(importer.root_namespace)
				.as_text())

class CtypesExport(ClangExport):
	builtin_dict = {
		'_Bool': 'ctypes.c_bool',
		'char': 'ctypes.c_char',
		'wchar_t': 'ctypes.c_wchar',
		'char': 'ctypes.c_byte',
		'unsigned char': 'ctypes.c_ubyte',
		'short': 'ctypes.c_short',
		'unsigned short': 'ctypes.c_ushort',
		'int': 'ctypes.c_int',
		'unsigned int': 'ctypes.c_uint',
		'long': 'ctypes.c_long',
		'unsigned long': 'ctypes.c_ulong',
		'long long': 'ctypes.c_longlong',
		'unsigned long long': 'ctypes.c_ulonglong',
		'float': 'ctypes.c_float',
		'double': 'ctypes.c_double',
		'long double': 'ctypes.c_longdouble',
	}

	def package_for_namespace(self, ns):
		return ns.name or "exported"

	def export_function(self, f):
		block = SourceBlock()
		if not f.extern_c:
			return block

		block.add_line('<function name="%s">' % f.name)
		block.add_line('</function>')
		return block

	def export_method(self, cls, method):
		block = SourceBlock()
		if not method:
			return block

		first_signature = method[0]
		if first_signature.is_constructor:
			name = "__init__"
		elif first_signature.is_destructor:
			name = "__del__"
		else:
			name = first_signature.name

		block.add_line('<method name="%s">' % name)
		for signature in method:
			if self.filter.filter_method_signature(cls, signature):
				block.add_block(self.export_call(signature, cls, method), 1)
		block.add_line('</method>')

		return block

	def export_constructor(self, cls):
		block = SourceBlock()

		cls_name_underscore = cls.get_full_name("__")
		block.add_line('<method name="__init__">')

		for constructor in cls.constructors:
			if self.filter.filter_method_signature:
				block.add_block(self.export_call(constructor, cls), 1)

		block.add_line('</method>')
		return block

	def export_call(self, f, cls = None, method = None):
		cls_name_underscore = cls.get_full_name("__")

		if f.is_constructor:
			symbol = self.symbol_for_constructor(
				cls, cls_name_underscore, f)
		elif f.is_destructor:
			symbol = self.symbol_for_destructor(
				cls, cls_name_underscore, f)
		else:
			symbol = self.symbol_for_method_signature(
				cls, cls_name_underscore, method, f)

		returns_nothing = (f.is_constructor or f.is_destructor
			or (f.returns.name == 'void' and not f.returns.pointers))

		block = SourceBlock()
		if returns_nothing and not f.args:
			block.add_line('<call symbol="%s" />' % symbol)
			return block

		block.add_line('<call symbol="%s">' % symbol)
		for arg, letter in zip(f.args, self.iletters()):
			block.add_line('<argument name="%s" type="%s" />' % (
				arg.name or letter,
				self.type_as_ctype(arg.type))
			, 1)
		if not returns_nothing:
			block.add_line('<returns type="%s" ownership="%d" />' % (
				self.type_as_ctype(f.returns),
				bool(method and f.returns.is_cpp_only()))
			, 1)

		block.add_line('</call>')

		return block

	def type_as_ctype(self, type):
		if type.type == 'builtin' and not type.refs:
			if type.pointers == 1:
				if type.name == 'void':
					return "ctypes.c_void_p"
				if type.name == 'char':
					return "ctypes.c_char_p"
				if type.name == 'wchar':
					return "ctypes.c_wchar_p"
			elif not type.pointers:
				return self.builtin_dict[type.name]
		elif type.type == 'enum':
			return "ctypes.c_uint"
		elif (type.pointers + type.refs) <= 1 and type.type in ('record', 'enum'):
			path = self.package_for_namespace(self.importer.root_namespace)
			path = [path] if path else []
			path += type.name.split("::")

			return ".".join(path)

		raise Exception("Don't know how to export type '%s%s%s'" % (type.name,
			'*' * type.pointers,
			'&' * type.refs))

	def export_destructor(self, cls):
		block = SourceBlock()
		return block

	def export_member(self, cls, member):
		getter, setter = self.symbols_for_member(cls, cls.get_full_name("__"), member)
		type = self.type_as_ctype(member.type)

		block = SourceBlock()
		block.add_line('<member name="%s">' % member.name)

		block.add_line('<getter>', 1)
		block.add_line('<call symbol="%s">' % getter, 2)
		block.add_line('<returns type="%s" />' % type, 3)
		block.add_line('</call>', 2)
		block.add_line('</getter>', 1)

		block.add_line('<setter>', 1)
		block.add_line('<call symbol="%s">' % setter, 2)
		block.add_line('<argument type="%s" />' % type, 3)
		block.add_line('</call>', 2)
		block.add_line('</setter>', 1)

		block.add_line('</member>')
		return block

	def export_class(self, cls):
		full_name = cls.get_full_name()
		full_name_underscore = cls.get_full_name("__")

		block = SourceBlock()
		block.add_line('<class name="%s">' % cls.name)

		if not cls.is_abstract(self.importer) and cls.constructors and self.filter.filter_method(cls, cls.constructors):
			block.add_block(self.export_constructor(cls), 1)
		if not cls.destructor or cls.destructor.access == 'public':
			block.add_block(self.export_destructor(cls), 1)
		for method in cls.methods.values():
			if self.filter.filter_method(cls, method):
				block.add_block(self.export_method(cls, method), 1)
		for member in cls.members:
			if self.filter.filter_member(cls, member):
				block.add_block(self.export_member(cls, member), 1)

		block.add_line('</class>')
		return block

	def export_namespace(self, ns):
		package_name = self.package_for_namespace(ns)

		block = SourceBlock()
		if package_name:
			block.add_line('<package name="%s">' % package_name)
			for node in ns.nodes:
				if isinstance(node, Class):
					if self.filter.filter_class(node):
						block.add_block(self.export_class(node), 1)
				if isinstance(node, Function):
					if self.filter.filter_function(node):
						block.add_block(self.export_function(node), 1)

		child_indent = int(bool(package_name))
		for child in ns.children.values():
			if self.filter.filter_namespace(child):
				block.add_block(self.export_namespace(child), child_indent)

		if package_name:
			block.add_line('</package>')

		return block

	def export(self, importer, path):
		self.setup(importer)

		with open(path, 'w') as f:
			f.write("<ctypes>\n")
			f.write(self.export_namespace(importer.root_namespace)
				.as_text(1))
			f.write("\n</ctypes>")
