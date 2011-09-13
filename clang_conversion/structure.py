import pprint
from itertools import chain
from collections import defaultdict

from lxml.etree import parse as parse_xml, fromstring as parse_xml_from_string

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

	def get_context_as_string(self, sep = "::"):
		return sep.join(self.namespace + self.context_cls)

	def get_full_name(self, sep = "::"):
		ctx = self.get_context_as_string(sep)
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
		self.abstract = any(i.is_pure for methods in self.methods.values() for i in methods)
		self.dynamic = xml_node.get('dynamic') == '1'

	def get_pure_virtual_signatures(self, importer = None, recursive = True):
		signatures = [signature
			for method in self.methods.values()
			for signature in method
			if signature.is_pure]
		if recursive:
			for base_ref in self.bases:
				base = importer.nodes[base_ref.id]
				signatures.extend(base.get_pure_virtual_signatures(importer))
		return signatures

	def get_implemented_signatures(self, importer = None, recursive = True):
		signatures = [signature
			for method in self.methods.values()
			for signature in method
			if not signature.is_pure]
		if recursive:
			for base_ref in self.bases:
				base = importer.nodes[base_ref.id]
				signatures.extend(base.get_pure_virtual_signatures(importer))
		return signatures

	def is_abstract(self, importer):
		pure = self.get_pure_virtual_signatures(importer)
		pure = [(sig.name,) + tuple((arg.type for arg in sig.args)) for sig in pure]
		pure = set(pure)

		nonpure = self.get_implemented_signatures(importer)
		nonpure = [(sig.name,) + tuple((arg.type for arg in sig.args)) for sig in nonpure]
		nonpure = set(nonpure)

		return bool(pure - nonpure)
		#return self.abstract or any(importer.nodes[base.id].is_abstract(importer) for base in self.bases)

	def get_overridable_signatures(self, importer, implemented = None):
		implemented = implemented or self.get_implemented_signatures(importer)

		methods = []
		for name, method in self.methods.items():
			signatures = [i for i in method if i.is_virtual and i not in implemented]
			if signatures:
				methods.append(signatures)

		for base_ref in self.bases:
			base = importer.nodes[base_ref.id]
			methods += base.get_overridable_signatures(importer, implemented)

		return methods

	def is_valid(self, importer):
		return self.name != None and len(self.name) > 0 and \
			all(importer.nodes.get(base.id) is not None for base in self.bases) and \
			all(importer.nodes[base.id].is_valid(importer) for base in self.bases)

	def is_default_constructable(self):
		return not self.constructors or any(
			len(constructor.args) == 0 and constructor.access == 'public'
			for constructor in self.constructors)

	def get_class_implementing_signature(self, importer, signature):
		if any(i == signature and not i.is_pure for method in self.methods for i in method):
			return self

		for base_ref in self.bases:
			base = importer.nodes[base_ref.id]
			cls = base.get_class_implementing_signature(importer, signature)
			if cls:
				return cls

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
				if self.name == '_Bool':
					self.name = 'bool'
			else:
				self.valid = False
			self.type = tp
			self.const = self.const or (xml_node.get('const') == '1')

			break

	def is_cpp_only(self): # We can pass pointers to objects to C, but not the objects themselves
		#print self.name, self.type, self.pointers, self.refs
		return self.type == 'record' and not self.pointers and not self.refs

	def as_string(self, c_compat_names = True, c_compat_refs = True,
				  c_compat_const = True):
		if c_compat_names and self.type == "record":
			name = "void"
		elif c_compat_names and self.type == "enum":
			name = "unsigned int"
		elif c_compat_names and self.type == "builtin" and self.name == "bool":
			name = "unsigned char"
		else:
			name = str(self.name)

		if not c_compat_const:
			const = "const " if self.const else ""
		else:
			const = ""

		return "".join((
			const,
			name,
			("*" * self.pointers),
			(("*" if c_compat_refs else "&") * self.refs),
			("*" if c_compat_refs and self.is_cpp_only() else "")
		))

	def as_parameter_type(self):
		return "(%s)" % (self.as_string(False))

	def __hash__(self):
		return hash((self.pointers, self.refs, self.name,
			self.id, self.valid, self.const))

	def __eq__(self, other):
		a = (self.pointers, self.refs, self.name,
			self.id, self.valid, self.const)
		b = (other.pointers, other.refs, other.name,
			other.id, other.valid, other.const)

		return a == b

class Function(Node):
	def __init__(self, xml_node):
		Node.__init__(self, xml_node)

		self.access = xml_node.get('access')
		self.is_constructor = (xml_node.get('constructor') == '1')
		self.is_destructor = (xml_node.get('destructor') == '1')
		#self.is_function_pointer = (xml_node.tag == 'Function_type')
		self.is_method = (xml_node.tag == 'Method')
		self.is_virtual = (xml_node.get('virtual') == '1')
		self.is_pure = (xml_node.get('pure') == '1')
		self.is_static = (xml_node.get('static') == '1')
		self.is_const = (xml_node.get('const') == '1')
		self.args = tuple(Argument(i) for i in xml_node.findall('Argument'))
		self.returns = Type(xml_node.find('Returns').find('Type'))
		self.valid = all(i.type.valid for i in self.args) and self.returns.valid
		self.extern_c = (xml_node.get('extern_c') == '1')

	def args_as_string(self, names = (), c_compat_names = True,
					   c_compat_refs = True, c_compat_const = True):
		if len(names) < len(self.args):
			names = names + (None,) * (len(self.args) - len(names))
		names = tuple(" " + name if name else "" for name in names)

		conv = lambda arg, name: (arg.type.as_string(c_compat_names,
													 c_compat_refs,
													 c_compat_const) + name)
		args = (conv(arg, name) for arg, name in zip(self.args, names))
		return ", ".join(args)

	def returns_anything(self):
		returns_anything = self.returns.pointers
		returns_anything = returns_anything or self.returns.name != 'void'
		returns_anything = bool(returns_anything)
		return returns_anything

	def to_function_pointer(self, name = ""):
		#int (*pt2Func)(float, char, char)
		return "%s (*%s)(%s)" % (self.returns.as_string(), name, self.args_as_string())

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

	def get_child(self, name):
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

		self.doc = parse_xml(path)
		for cls in self.doc.xpath('/HeaderExport/Class'):
			self.parse_node(cls, Class, self.classes)
		for cls in self.doc.xpath('/HeaderExport/Struct'):
			self.parse_node(cls, Class, self.classes)
		for func in self.doc.xpath('/HeaderExport/Function'):
			self.parse_node(func, Function, self.functions)
		for enum in self.doc.xpath('/HeaderExport/Enum'):
			self.parse_node(cls, Enum, self.enums)
		self.process_namespaces()

	def parse_node(self, xml_node, cls, register):
		id = xml_node.get('id')
		node = cls(xml_node)
		self.nodes[ id ] = node
		register[ id ] = node

	def process_namespaces(self):
		root_namespace = self.root_namespace = Namespace()
		for node in self.nodes.values():
			root_namespace.get_child("::".join(node.namespace)).nodes.append(node)
