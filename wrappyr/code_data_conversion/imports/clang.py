from functools import partial
from collections import defaultdict
from lxml.etree import parse as parse_xml
from wrappyr.code_data_conversion.structure import (
	Class, Function, Enumeration, Namespace,
	AccessSpecifier, Member, Method,
	FunctionSignature, Struct, SourceLocation, Argument, QualifiedType, Builtin, Pointer, Reference, Array, Node)

class ClangImporter(object):
	class ParseError(Exception): pass

	def __init__(self, path):
		self.root_namespace = Namespace()
		self.functions = []
		self.classes = []
		self.structs = []
		self.enums = []

		# Begin temporary, the variables only exist during import,
		# meaning while __init__ runs

		# A dict of {namespace: {function: [signatures]}}
		self.function_signatures = defaultdict(partial(defaultdict, list))
		self.qualtypes = []
		self.nodes = {}

		# End temporary variables

		doc = parse_xml(path)
		for xml_node in doc.xpath('/HeaderExport/Class'):
			self.parse_class(xml_node)
		for xml_node in doc.xpath('/HeaderExport/Struct'):
			self.parse_struct(xml_node)
		for xml_node in doc.xpath('/HeaderExport/Function'):
			self.parse_function(xml_node)
		for xml_node in doc.xpath('/HeaderExport/Enum'):
			self.parse_enumeration(xml_node)
		self.process_functions()
		self.process_contexts()
		self.process_types()
		self.process_bases()

		del self.nodes

	def process_contexts(self):
		for node in self.nodes.itervalues():
			cls = node.context['cls']
			if cls:
				ctx = self.nodes[cls]
			else:
				ctx = self.root_namespace.get_child(node.context['ns'])
			node.context = ctx
			ctx.nodes.append(node)

	def process_functions(self):
		for ns, functions in self.function_signatures.iteritems():
			for name, signatures in functions.iteritems():
				f = Function(name)
				for sig in signatures:
					sig.context = f
				f.signatures = signatures
				self.functions.append(f)
		del self.function_signatures

	def process_type(self, type):
		if isinstance(type.type, basestring):
			type.type = self.root_namespace.get_by_full_name(type.type)
		elif isinstance(type.type, (Reference, Pointer, Array)):
			self.process_type(type.type)

	def process_types(self):
		for type in self.qualtypes:
			self.process_type(type)
		del self.qualtypes

	def process_bases(self):
		for node in self.classes:
			node.bases = [self.nodes.get(i) for i in node.bases]

	def postprocess(self):
		pass

	def parse_class(self, xml_node):
		ctx = xml_node.find('Context')
		cls = Class(xml_node.get('name'))
		cls.context = self.parse_context(ctx)
		cls.location = self.parse_source_location(ctx)
		cls.access = AccessSpecifier.from_string(xml_node.get('access'))
		cls.bases = [i.get('id') for i in xml_node.findall('Base')]
		cls.dynamic = xml_node.get('dynamic') == '1'

		cls.members = [self.parse_member(i) for i in xml_node.findall('Field')]

		methods = defaultdict(list)
		for i in xml_node.findall('Method'):
			sig = self.parse_function_signature(i)
			if sig.constructor:
				sig.context = cls
				cls.constructors.append(sig)
			elif sig.destructor:
				sig.context = cls
				cls.destructor = sig
			else:
				methods[i.get('name')].append(sig)

		cls.methods = []
		for name, signatures in methods.items():
			method = Method(name, signatures, cls)
			for sig in signatures:
				sig.context = method
			cls.methods.append(method)
		cls.determine_abstractness()

		for child_node in xml_node.findall('Class'):
			self.parse_class(child_node)
		for child_node in xml_node.findall('Enum'):
			self.parse_enumeration(child_node)

		self.nodes[xml_node.get('id')] = cls
		self.classes.append(cls)
		return cls

	def parse_member(self, xml_node, context = None):
		member = Member(xml_node.get('name'))
		member.context = context
		member.access = AccessSpecifier.from_string(xml_node.get('access'))
		member.type = self.parse_type(xml_node.find('Type'))
		return member

	def parse_function(self, xml_node):
		sig = self.parse_function_signature(xml_node)
		ns = sig.context['ns']
		self.function_signatures[ns][xml_node.get('name')].append(sig)

	def parse_function_signature(self, xml_node):
		ctx = xml_node.find('Context')
		sig = FunctionSignature()
		sig.context = self.parse_context(ctx)
		sig.location = self.parse_source_location(ctx)
		sig.access = AccessSpecifier.from_string(xml_node.get('access'))
		sig.constructor = (xml_node.get('constructor') == '1')
		sig.destructor = (xml_node.get('destructor') == '1')
		sig.virtual = (xml_node.get('virtual') == '1')
		sig.pure = (xml_node.get('pure') == '1')
		sig.static = (xml_node.get('static') == '1')
		sig.const = (xml_node.get('const') == '1')
		sig.extern_c =(xml_node.get('extern_c') == '1')
		sig.args = [self.parse_argument(i, sig) for i in xml_node.findall('Argument')]

		returns = xml_node.findall('Returns')
		if returns:
			sig.returns = self.parse_type(returns[0].find('Type'))

		return sig

	def parse_struct(self, xml_node):
		ctx = xml_node.find('Context')
		struct = Struct(xml_node.get('name'))
		struct.context = self.parse_context(ctx)
		struct.location = self.parse_source_location(ctx)
		struct.access = AccessSpecifier.from_string(xml_node.get('access'))
		struct.members = [self.parse_member(i) for i in xml_node.findall('Field')]

		self.nodes[xml_node.get('id')] = struct
		self.structs.append(struct)
		return struct

	def parse_enumeration(self, xml_node):
		ctx = xml_node.find('Context')
		enum = Enumeration(xml_node.get('name'))
		enum.context = self.parse_context(ctx)
		enum.location = self.parse_source_location(ctx)
		for child_node in xml_node.findall('Constant'):
			enum.add_field(child_node.get('name'), int(child_node.get('value')))

		self.nodes[xml_node.get('id')] = enum
		self.enums.append(enum)
		return enum

	def parse_argument(self, xml_node, context = None):
		arg = Argument(xml_node.get('name'))
		arg.context = context
		arg.optional = (xml_node.get('optional') == '1')
		arg.type = self.parse_type(xml_node.find('Type'), arg)
		return arg

	def parse_type(self, xml_node, context = None):
		type = xml_node.get('type')
		const = (xml_node.get('const') == '1')
		if type == 'builtin':
			name = xml_node.get('name')
			if name == '_Bool':
				name = "bool"
			type = Builtin(name)
		elif type == 'pointer':
			subtype = self.parse_type(xml_node.find('Type'))
			type = Pointer(subtype)
			subtype.context = type
		elif type == 'reference':
			subtype = self.parse_type(xml_node.find('Type'))
			type = Reference(subtype)
			subtype.context = type
		elif type == 'array':
			subtype = self.parse_type(xml_node.find('Type'))
			size = xml_node.get('size')
			size = int(size) if size != None else None
			type = Array(subtype, size)
			subtype.context = type
		elif type == 'function':
#			type = self.parse_function_signature(xml_node)
			type = None
		elif type in ('record', 'struct', 'enum'):
			type = xml_node.get('name')
		else:
			type = None

		qualtype = QualifiedType(type, const)
		if isinstance(type, Node):
			type.context = qualtype
		qualtype.context = context

		self.qualtypes.append(qualtype)
		return qualtype

	def parse_source_location(self, xml_node):
		if xml_node == None:
			return None

		physical = xml_node.find("Physical")
		if physical == None:
			return None

		return SourceLocation(physical.get('file'), physical.get('line'), physical.get('column'))

	def parse_context(self, xml_node):
		if xml_node == None:
			return {'ns': None, 'cls': None}

		ns = xml_node.xpath('Namespace/text()')
		ns = ns[0] if ns else None
		cls = xml_node.xpath('Class/@id')
		cls = cls[0] if cls else None

		return {'ns': ns, 'cls': cls}

