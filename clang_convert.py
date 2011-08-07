#!/usr/bin/python2.6
import sys
import os
import time
import re
import argparse
import pprint
from itertools import chain
from collections import defaultdict

from lxml.etree import parse as parseXML, fromstring as parseXMLFromString

class Node(object):
	def __init__(self, xml_node):
		self.name = xml_node.get('name')

		context = xml_node.find('Context')
		self.file = context.xpath('Physical/@path') if context != None else None
		self.file = self.file[0] if self.file else None
		self.namespace = context.xpath('Namespace/text()') if context != None else None
		self.namespace = self.namespace[0].split("::") if self.namespace else []
		self.context_cls = context.xpath('Class/text()') if context != None else None
		self.context_cls = self.context_cls[0].split("::") if self.context_cls else []

	def getContextAsString(self, sep = "::"):
		return sep.join(self.namespace + self.context_cls)

	def getFullName(self, sep = "::"):
		ctx = self.getContextAsString(sep)
		return "%s%s%s" % (ctx, sep, self.name) if ctx else self.name

class NodeReference(Node):
	def __init__(self, xml_node):
		Node.__init__(self, xml_node)

		self.id = xml_node.get('id')

class Class(Node):
	def __init__(self, xml_node):
		Node.__init__(self, xml_node)

		self.access = xml_node.get('access')
		self.struct = (xml_node.tag == "Struct")
		self.bases = tuple(NodeReference(i) for i in xml_node.findall('Base'))
		self.methods = defaultdict(list)
		for i in xml_node.findall('Method'):
			if '1' not in (i.get('constructor'), i.get('destructor')) and ">" not in i.get('name'):
				self.methods[ i.get('name') ].append(Function(i))
		self.members = tuple(Member(i) for i in xml_node.findall('Field'))
		self.constructors = tuple(Function(i) for i in xml_node.findall('Method') if i.get('constructor') == '1')
		self.destructor = tuple(Function(i) for i in xml_node.findall('Method') if i.get('destructor') == '1')
		self.destructor = self.destructor and self.destructor[0]
		self.abstract = any(i.isPure for methods in self.methods.values() for i in methods)

	def isAbstract(self, importer):
		return self.abstract or any(importer.nodes[base.id].isAbstract(importer) for base in self.bases)

	def isValid(self, importer):
		return self.name != None and len(self.name) > 0 and \
			all(importer.nodes.get(base.id) is not None for base in self.bases) and \
			all(importer.nodes[base.id].isValid(importer) for base in self.bases)

class Argument(Node):
	def __init__(self, xml_node):
		Node.__init__(self, xml_node)

		self.optional = (xml_node.get('optional') == '1')
		self.type = Type(xml_node.find('Type'))
		self.name = xml_node.get('name')

class Type(Node):
	def __init__(self, xml_node):
		Node.__init__(self, xml_node)

		self.pointers = 0
		self.refs = 0
		self.name = None
		self.id = None
		self.valid = True
		self.const = False

		while True:
			tp = xml_node.get('type')
			if tp == 'pointer':
				self.pointers += 1
				xml_node = xml_node.find('Type')
				continue
			elif tp == 'reference':
				self.refs += 1
				xml_node = xml_node.find('Type')
				continue
			elif tp in ('builtin', 'record', 'enum'):
				self.id = xml_node.get('id')
				self.name = xml_node.get('name')
				#if self.name == '_Bool':
					#self.name = 'bool'
			else:
				self.valid = False
			self.type = tp
			self.const = self.const or (xml_node.get('const') == '1')

			break

	def isCppOnly(self): # We can pass pointers to objects to C, but not the objects themselves
		#print self.name, self.type, self.pointers, self.refs
		return self.type == 'record' and not self.pointers and not self.refs

	def asString(self, c_compat_names = True, c_compat_refs = True):
		if c_compat_names and self.type == "record":
			name = "void"
		elif c_compat_names and self.type == "enum":
			name = "unsigned int"
		elif c_compat_names and self.type == "builtin" and self.type == "bool":
			name = "unsigned char"
		else:
			name = str(self.name)

		return "".join((
			name,
			("*" * self.pointers),
			(("*" if c_compat_refs else "&") * self.refs),
			("*" if c_compat_refs and self.isCppOnly() else "")
		))

	def as_parameter_type(self):
		return "(%s)" % (self.asString(False))

class Function(Node):
	def __init__(self, xml_node):
		Node.__init__(self, xml_node)

		self.access = xml_node.get('access')
		self.is_constructor = (xml_node.get('constructor') == '1')
		self.is_destructor = (xml_node.get('destructor') == '1')
		#self.isFunctionPointer = (xml_node.tag == 'FunctionType')
		self.isMethod = (xml_node.tag == 'Method')
		self.isVirtual = (xml_node.get('virtual') == '1')
		self.isPure = (xml_node.get('pure') == '1')
		self.isStatic = (xml_node.get('pure') == '1')
		self.args = tuple(Argument(i) for i in xml_node.findall('Argument'))
		self.returns = Type(xml_node.find('Returns').find('Type'))
		self.valid = all(i.type.valid for i in self.args) and self.returns.valid
		self.extern_c = (xml_node.get('extern_c') == '1')

	def argsAsString(self, names = ()):
		if len(names) < len(self.args):
			names = names + (None,) * (len(self.args) - len(names))
		names = tuple(" " + name if name else "" for name in names)

		return ", ".join(arg.type.asString() + name for arg, name in zip(self.args, names))

	def toFunctionPointer(self, name = ""):
		#int (*pt2Func)(float, char, char)
		return "%s (*%s)(%s)" % (self.returns.asString(), name, self.argsAsString())

class Member(Node):
	def __init__(self, xml_node):
		Node.__init__(self, xml_node)

		self.access = xml_node.get('access')
		self.type = Type(xml_node.find('Type'))

class Enum(Node):
	def __init__(self, xml_node):
		Node.__init__(self, xml_node)

		self.constants = tuple((constant.get('name'), int(constant.get('value'))) for constant in xml_node.findall('Constant'))

class Namespace(object):
	def __init__(self, parent = None, name = None):
		self.parent = parent
		self.name = name
		self.children = {}
		self.nodes = []

	def getChild(self, name):
		ns = self
		for part in name.split("::"):
			if not part:
				continue

			child = ns.children.get(part)
			if not child:
				child = ns.children[part] = Namespace(self, part)
			ns = child
		return ns

class ClangImporter(object):
	def __init__(self, path):
		self.nodes = {}
		self.classes = {}
		self.functions = {}
		self.enums = {}

		self.doc = parseXML(path)
		for cls in self.doc.xpath('/HeaderExport/Class'):
			self.parseNode(cls, Class, self.classes)
		for cls in self.doc.xpath('/HeaderExport/Struct'):
			self.parseNode(cls, Class, self.classes)
		for func in self.doc.xpath('/HeaderExport/Function'):
			self.parseNode(func, Function, self.functions)
		for enum in self.doc.xpath('/HeaderExport/Enum'):
			self.parseNode(cls, Enum, self.enums)
		self.processNamespaces()

	def parseNode(self, xml_node, cls, register):
		id = xml_node.get('id')
		node = cls(xml_node)
		self.nodes[ id ] = node
		register[ id ] = node

	def processNamespaces(self):
		root_namespace = self.root_namespace = Namespace()
		for node in self.nodes.values():
			root_namespace.getChild("::".join(node.namespace)).nodes.append(node)

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
		return cls.isValid(self.importer) and cls.access in ('unknown', 'public')

	def filter_method(self, cls, method):
		return all(self.filter_method_signature(cls, sig) for sig in method)

	def filter_method_signature(self, cls, signature):
		return self.filter_function(signature) and \
			signature.access == 'public' and \
			not signature.isStatic

	def filter_member(self, cls, member):
		return member.access == 'public' and member.name \
			and (member.type.type != 'builtin' or not member.type.pointers) \
			and member.type.pointers <= 1 \
			and member.type.valid

	def filter_function(self, f):
		return not f.name.startswith('operator') \
			and f.valid

class ClangExport(object):
	@staticmethod
	def iletters():
		return (chr(i) for i in xrange(ord('a'), ord('m')))

	def get_filter(self, importer):
		return ExportFilter(importer)

	def symbol_for_constructor(self, cls, cls_name_underscore, constructor):
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
		full_name_underscore = cls.getFullName("__")
		block = SourceBlock()
		block.add_line("")
		block.add_line("//")
		block.add_line("// Begin class '%s'" % cls.getFullName())
		block.add_line("//")

		# Constructor
		if not cls.isAbstract(self.importer):
			for i, constructor in enumerate(cls.constructors):
				if not self.filter.filter_method_signature(cls, constructor):
					continue
				block.add_line("void* %s(%s);" % (
					self.symbol_for_constructor(cls, full_name_underscore, constructor),
					constructor.argsAsString()
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

				returns = signature.returns.asString()
				args = "void*%s%s" % (
					", " if signature.args else '',
					signature.argsAsString() if signature.args else ''
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

			returns = member.type.asString()
			getter, setter = self.symbols_for_member(cls, full_name_underscore, member)

			block.add_line("%s %s(void*);" % (
				returns,
				getter
			))
			block.add_line("void %s(void*, %s);" % (
				setter,
				member.type.asString(),
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
				"*" * (arg.type.refs + int(arg.type.isCppOnly())),
				arg.type.asString(False),
				letter
			))

		return ", ".join(args)

	def export_class(self, cls):
		full_name = cls.getFullName()
		full_name_underscore = cls.getFullName("__")

		block = SourceBlock()
		block.add_line("")
		block.add_line("//")
		block.add_line("// Begin class '%s'" % cls.getFullName())
		block.add_line("//")

		# Constructor
		if not cls.isAbstract(self.importer):
			for constructor in cls.constructors:
				if not self.filter.filter_method_signature(cls, constructor):
					continue
				block.add_line("void* %s(%s){" % (
					self.symbol_for_constructor(cls, full_name_underscore, constructor),
					constructor.argsAsString(self.letters)
				))
				block.add_line("return new %s(%s);" % (
					full_name,
					self.args_as_params(constructor))
				, 1)
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

				returns = signature.returns.asString()
				args = "void* cls%s%s" % (
					", " if signature.args else '',
					signature.argsAsString(self.letters) if signature.args else ''
				)
				block.add_line("%s %s(%s){" % (
					returns,
					self.symbol_for_method_signature(cls, full_name_underscore, method, signature),
					args
				))

				returns = signature.returns
				block.add_line("%s%s%s%s((%s*)cls)->%s(%s)%s%s;" % (
					("return " if returns.pointers or returns.name != 'void' else ''),
					("new %s(" % returns.name if returns.isCppOnly() else ''),
					("const_cast<%s%s>(" % (returns.name, "*" * (returns.refs + returns.pointers))
						if returns.const and not returns.isCppOnly() else ''),
					"&" if returns.refs else '',
					full_name,
					signature.name,
					self.args_as_params(signature),
					(")" if returns.const and not returns.isCppOnly() else ''),
					(")" if returns.isCppOnly() else '')
				), 1)
				block.add_line("}")

		# Members
		for member in cls.members:
			if not self.filter.filter_member(cls, member):
				continue

			getter, setter = self.symbols_for_member(cls, full_name_underscore, member)
			type = member.type

			# Getter
			returns = member.type.asString()
			block.add_line("%s %s(void* cls){" % (
				returns,
				getter
			))
			block.add_line("return %s%s((%s*)cls)->%s%s;" % (
				("const_cast<%s%s>(" % (type.name, "*" * (type.refs + type.pointers + int(type.isCppOnly())))
					if type.const else ''),
				'&' if type.isCppOnly() else '',
				full_name,
				member.name,
				(")" if type.const else ''),
			), 1)
			block.add_line("}")


			# Setter
			block.add_line("void %s(void*, %s){" % (
				setter,
				member.type.asString(),
			))
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

class CtypesFilter(ExportFilter):
	pass

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

		cls_name_underscore = cls.getFullName("__")
		block.add_line('<method name="__init__">')

		for constructor in cls.constructors:
			block.add_block(self.export_call(constructor, cls), 1)

		block.add_line('</method>')
		return block

	def export_call(self, f, cls = None, method = None):
		cls_name_underscore = cls.getFullName("__")

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
				bool(method and f.returns.isCppOnly()))
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
		getter, setter = self.symbols_for_member(cls, cls.getFullName("__"), member)
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
		full_name = cls.getFullName()
		full_name_underscore = cls.getFullName("__")

		block = SourceBlock()
		block.add_line('<class name="%s">' % cls.name)

		if not cls.isAbstract(self.importer) and cls.constructors:
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

class CeguiFilter(ExportFilter):
	def filter_class(self, cls):
		if not ExportFilter.filter_class(self, cls):
			return False
		if not cls.namespace or cls.namespace[0] != "CEGUI":
			return False
		if cls.name.endswith("Exception"):
			return False
		if cls.name.endswith("Iterator"):
			return False

		return True

	def filter_method_signature(self, cls, sig):
		if not ExportFilter.filter_method_signature(self, cls, sig):
			return False

		return all(self.filter_type(arg.type) for arg in sig.args) and self.filter_type(sig.returns)

	def filter_type(self, tp):
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
	def filter_namespace(self, ns):
		return not ns.name

	def filter_class(self, cls):
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
