from itertools import chain
from lxml.etree import parse as parse_xml
from utils.MultiDict import OrderedMultiDict
from utils.str import SourceBlock

def _add_named_item(prop):
	def add(self, item):
		item.parent = self
		self.children[item.name] = item
		getattr(self, prop)[item.name] = item

	return add

def _add_list_item(prop):
	def add(self, item):
		item.parent = self
		self.children[getattr(item, 'name', None)] = item
		getattr(self, prop).append(item)

	return add

def _add_single_item(prop):
	def add(self, item):
		cur = getattr(self, prop)
		if cur:
			cur.parent = None
		item.parent = self

		if cur:
			_remove_from_children(self, cur)
		self.children[item.name] = item

		setattr(self, prop, item)

	return add

def _remove_from_children(parent, child):
	name = getattr(child, 'name', None)
	children = parent.children.getall(name)
	if len(children) == 1:
		del parent.children[name]
	else:
		children.remove(child)

def _remove_named_item(prop):
	def remove(self, item):
		item.parent = None
		_remove_from_children(self, item)
		del getattr(self, prop)[item.name]

	return remove

def _remove_list_item(prop):
	def remove(self, item):
		item.parent = None
		_remove_from_children(self, item)
		getattr(self, prop).remove(item)

	return remove

def _remove_single_item(prop):
	def remove(self, item = None):
		item = item or getattr(self, prop)

		item.parent = None
		_remove_from_children(self, item)
		setattr(self, prop, None)

	return remove

def _every_named_item(prop):
	def every(self):
		return getattr(self, prop).values()

	return every

def _every_list_item(prop):
	def every(self):
		return getattr(self, prop)

	return every

def _every_single_item(prop):
	""" Returns item in a single-item tuple or an empty tuple

	Needed so CTypesStructure.diplay won't get confused when you return (None,) """

	def every(self):
		item = getattr(self, prop, None)
		return (item,) if item else ()

	return every

def _setup_child(item_type, cls, prop, name, type, singular = None, add = None, remove = None, every = None):
	singular = singular or type.lower()

	children = cls.layout.get('children', {})
	if not children:
		cls.layout['children'] = children

	layout_item = children.get(prop, {})
	if not layout_item:
		children[prop] = layout_item

	layout_item.update({
		'name': name,
		'type': type,
	})
	if add != False:
		layout_item['add'] = add or 'add_' + singular
		add_func = globals()["_add_%s_item" % item_type](prop)
		add_func.__doc__ = 'Add a %s to this %s' % (singular, cls.__name__)
		setattr(cls, layout_item['add'], add_func)
	if remove != False:
		layout_item['remove'] = remove or 'remove_' + singular
		remove_func = globals()["_remove_%s_item" % item_type](prop)
		remove_func.__doc__ = 'Remove a %s from this %s' % (singular, cls.__name__)
		setattr(cls, layout_item['remove'], remove_func)
	if every != False:
		layout_item['every'] = every or 'every_' + singular
		every_func = globals()["_every_%s_item" % item_type](prop)
		every_func.__doc__ = 'Return every %s of this %s' % (singular, cls.__name__)
		setattr(cls, layout_item['every'], every_func)

def _setup_named_child(cls, prop, name, type, singular = None, add = None, remove = None, every = None):
	_setup_child('named', cls, prop, name, type, singular, add, remove, every)

def _setup_list_child(cls, prop, name, type, singular = None, add = None, remove = None, every = None):
	_setup_child('list', cls, prop, name, type, singular, add, remove, every)

def _setup_single_child(cls, prop, name, type, singular = None, add = None, remove = None, every = None):
	_setup_child('single', cls, prop, name, type, singular, add, remove, every)

def _bool_from_string(s, default = False):
	return s.lower() in ('1', 'true') if s else default

class Node(object):
	layout = {}

	types = {}

	def __init__(self, name = None):
		self.parent = None
		self.name = name
		self.children = OrderedMultiDict()

	def add_nodes_from_xml(self, xml_node, name, cls, add_func):
		for node in xml_node.findall(name):
			add_func(cls.from_xml(node))

	def get_path(self, top = None):
		path = []

		node = self
		while node.parent and (not top or node != top):
			if not node.name:
				return
			path.insert(0, node.name)
			node = node.parent

		if not top or node == top:
			return ".".join(path)

	def get_closest_parent_of_type(self, type):
		parent = self.parent
		while parent:
			if isinstance(parent, type):
				return parent
			parent = parent.parent

	def get_closest_parent_module(self):
		return self.get_closest_parent_of_type(Module)

	def get_distance_to_parent(self, parent):
		i = 0

		node = self
		while node.parent:
			if node == parent:
				return i
			i += 1

			node = node.parent

	def find_lowest_common_parent(self, other):
		a_parents = reversed(list(self.parents()))
		b_parents = reversed(list(other.parents()))
		for a, b in reversed(zip(a_parents, b_parents)): # Zip makes both paths the same height
			if a == b:
				return a

	def parents(self):
		parent = self.parent
		while parent:
			yield parent
			parent = parent.parent

	@classmethod
	def get_layouts(cls):
		layouts = []
		nodecls = cls
		while nodecls != Node:
			layouts.insert(0, nodecls.layout)
			nodecls = nodecls.__base__

		return layouts

	@classmethod
	def from_xml(cls, xml_node):
		kwds = {}

		layouts = cls.get_layouts()
		for layout in layouts:
			for prop, conv in layout.get('properties', {}).items():
				kwds[prop] = conv(xml_node.get(prop))

		node = cls(**kwds)
		for layout in layouts:
			for group in layout.get('children', {}).values():
				add = group['add']
				add = getattr(node, add)
				tp = cls.types[group['type']]

				if isinstance(group['name'], basestring):
					xml_child_nodes = xml_node.findall(group['name'])
				else:
					xml_child_nodes = chain.from_iterable(xml_node.findall(i) for i in group['name'])

				for xml_child_node in xml_child_nodes:
					add(tp.from_xml(xml_child_node))

		return node

class Module(Node):
	layout = {
		'properties': {
			'name': str
		},
	}

	def __init__(self, name):
		Node.__init__(self, name)

		self.libraries = {}
		self.functions = {}
		self.classes = {}
		self.pointers = {}

	class LibraryNotFound(Exception): pass
	def find_library(self, name = None):
		mod = self
		while mod.parent:
			for lib in mod.libraries.values():
				if (name and lib.name == name) or (not name and lib.default):
					return lib
			mod = mod.parent

		if name:
			raise self.LibraryNotFound("Could not find library '%s'" % name)
		else:
			raise self.LibraryNotFound("Could not find default library")

	def get_node_import(self, node):
		if self in node.parents():
			lcp = self
		else:
			lcp = self.find_lowest_common_parent(node)

		if lcp != self:
			distance = self.get_distance_to_parent(lcp)
			return "from %s%s import %s" % (
				("." * (distance + 1)),
				node.get_closest_parent_module().get_path(lcp),
				node.name
			)
		elif node.parent != self:
			return "from .%s import %s" % (node.get_closest_parent_module().get_path(self), node.name)
		else:
			return ""
_setup_named_child(Module, 'libraries', 'library', 'Library')
_setup_named_child(Module, 'functions', 'function', 'Function')
_setup_named_child(Module, 'classes', 'class', 'Class')
_setup_named_child(Module, 'pointers', 'pointer', 'PointerType')

Node.types['Module'] = Module

class Package(Module):
	layout = {}

	def __init__(self, name):
		Module.__init__(self, name)

		self.packages = {}
		self.modules = {}
_setup_named_child(Package, 'packages', 'package', 'Package')
_setup_named_child(Package, 'modules', 'module', 'Module')

Node.types['Package'] = Package

class Library(Node):
	layout = {
		'properties': {
			'name': str,
			'path': str,
			'default': _bool_from_string
		},
	}

	def __init__(self, name, path, default = False):
		Node.__init__(self, name)

		self.name = name
		self.path = path
		self.default = default
Node.types['Library'] = Library

class Class(Node):
	layout = {
		'properties': {
			'name': str
		},
	}

	def __init__(self, name):
		Node.__init__(self, name)

		self.methods = {}
		self.members = {}
		self.pointers = {}

	def is_empty(self):
		return not any((self.methods, self.members))
_setup_named_child(Class, 'methods', 'method', 'Method')
_setup_named_child(Class, 'members', 'member', 'Member')
_setup_named_child(Class, 'pointers', 'pointer', 'PointerType',
				   singular = 'pointer_type')

Node.types['Class'] = Class

class Function(Node):
	class CannotAddOperation(Exception): pass

	layout = {
		'properties': {
			'name': str
		},
		'children': {
			'ops': {
				'add': 'add_operation',
			}
		}
	}

	def __init__(self, name):
		Node.__init__(self, name)

		self.name = name
		self.ops = []
		self.raw = None
		self.pointers = {}

	_add_operation = _add_list_item('ops')
	def add_operation(self, op):
		if self.raw:
			raise self.CannotAddOperation("Function '%s' has raw code and you tried to add a '%s' operation" %
				(self.name, type(op).__name__))
		if self.raw == False and not isinstance(op, Call):
			raise self.CannotAddOperation("Function '%s' has C calls and you tried to add a '%s' operation" %
				(self.name, type(op).__name__))
		self.raw = isinstance(op, RawCode)

		self._add_operation(op)

	def returns_anything(self):
		return any(call.returns for call in self.ops)
_setup_list_child(Function, 'ops', ('call', 'raw'), 'Operation', add = False)
_setup_named_child(Function, 'pointers', 'pointer', 'PointerType')

Node.types['Function'] = Function

class Method(Function):
	layout = {
		'properties': {
			'static': _bool_from_string
		}
	}

	def __init__(self, name, static = False):
		Function.__init__(self, name)

		self._static = static

	@property
	def static(self):
		return self.is_static()

	def is_static(self):
		if self.name in ('__newarray__', '__delarray__', '__arrayitem__'):
			return True
		return self._static

	def returns_anything(self):
		returns = self.name != "__init__"
		returns = returns or self.name == '__newarray__'
		returns = returns or Function.returns_anything(self)
		return returns

	def takes_self_argument(self):
		return not self._static and self.name not in (
			'__newarray__', '__delarray__', '__arrayitem__'
		)

	def takes_this_pointer(self):
		return not self._static and self.name not in (
			'__init__',
			'__newarray__', '__delarray__', '__arrayitem__'
		)

Node.types['Method'] = Method

class Member(Node):
	layout = {
		'properties': {
			'name': str,
			'static': _bool_from_string
		},
	}

	def __init__(self, name, getter = None, setter = None, static = False):
		Node.__init__(self, name)

		self.name = name
		self.getter = getter
		self.setter = setter
		self.static = static

	def is_static(self):
		return self.static
_setup_single_child(Member, 'getter', 'getter', 'Method', singular = 'getter')
_setup_single_child(Member, 'setter', 'setter', 'Method', singular = 'setter')

Node.types['Member'] = Member

class Operation(Node):
	layout = {}
	op_types = {}

	def __init__(self):
		Node.__init__(self)

	@classmethod
	def from_xml(cls, xml_node):
		if cls == Operation:
			return cls.op_types[xml_node.tag].from_xml(xml_node)
		else:
			return Node.from_xml.__func__(cls, xml_node)
Node.types['Operation'] = Operation

class Call(Operation):
	layout = {
		'properties': {
			'symbol': str,
			'library': lambda v: v and str(v)
		},
	}

	def __init__(self, symbol, library = None):
		Operation.__init__(self)

		self.symbol = symbol
		self.library = library
		self.args = []
		self.returns = None

	def get_return_value_as_ctype(self):
		if not self.returns:
			return "ctypes.c_void_p" if self.parent.name == "__init__" else "None"
		if isinstance(self.returns.type, Class):
			return "ctypes.c_void_p"
		if isinstance(self.returns.type, PointerType):
			return self.returns.type.get_as_ctype()
		return self.returns.type

	def get_library(self):
		return self.get_closest_parent_module().find_library(self.library)
_setup_list_child(Call, 'args', 'argument', 'Argument')
_setup_single_child(Call, 'returns', 'returns', 'ReturnValue', singular = 'return_value')

Operation.op_types['call'] = Call
Node.types['Call'] = Call

class RawCode(Operation):
	layout = {
		'properties': {
			'code': str,
			'args': lambda v: (() if not v else v.split(','))
		}
	}

	def __init__(self, code, args = ''):
		Operation.__init__(self)

		self.code = code
		self.args = args

	def get_code_block(self):
		if isinstance(self.code, SourceBlock):
			return self.code
		return SourceBlock(self.code)

Operation.op_types['raw'] = RawCode
Node.types['Raw'] = RawCode

class Argument(Node):
	layout = {
		'properties': {
			'type': str,
			'name': str,
			'default': str,
		}
	}

	def __init__(self, type, name = None, default = None):
		Node.__init__(self, name)

		self.type = type
		self.name = name
		self.default = default
Node.types['Argument'] = Argument

class ReturnValue(Node):
	layout = {
		'properties': {
			'type': str,
			'ownership': _bool_from_string
		}
	}

	def __init__(self, type, ownership = False):
		Node.__init__(self)

		self.type = type
		self.ownership = ownership
Node.types['ReturnValue'] = ReturnValue

class PointerType(Node):
	"""
	Since a C pointer is used for numerous purposes in C, a PointerType
	describes what type it points to and what a C call intends to do
	with the pointer. You can create a PointerType in XML with the
	<pointer> tag and reference it by path in any type attribute.
	Three pointer use cases and their combinations are supported.

	A pointer that is just used to pass an object by reference, like:
		void print_foo_object(foo*);

	A pointer used to point to an array, like:
		void print_array(int* arr, int num);
		void b2PolygonShape__SetVertices(b2Vec*);
	The array can have multiple dimensions, like:
		char** get_names(group*);

	A pointer used to return a value from a function (outparam):
		bool get_foo(foo* out);

	These can be combined in the following ways:
		outparam and array, for functions like:
			int sprintf(char* buffer, char* fmt, ...);
		outparam and reference:
			bool get_foo_ref(foo** out);
	"""
	layout = {
		'properties': {
			'type': str,
			'name': str,
			'array': _bool_from_string,
			'reference': _bool_from_string,
			'outparam': _bool_from_string,
			'array_dimensions': lambda v: v and int(v)
		}
	}

	def __init__(self, type, name = None, array = False,
				 reference = False, outparam = False,
				 array_dimensions = None):
		Node.__init__(self)

		self.type = type
		self.name = name
		self.array = array
		self.reference = reference
		self.outparam = outparam
		self.dimensions = array_dimensions or (1 if self.array else None)

	def get_as_ctype(self):
		if self.array:
			pointers = self.dimensions
		else:
			pointers = 1

		ctype = self.type
		if not isinstance(ctype, basestring):
			ctype = "ctypes.c_void_p"
		if ctype == "ctypes.c_void_p":
			pointers -= 1

		for i in xrange(pointers):
			ctype = "ctypes.POINTER(%s)" % ctype

		return ctype

Node.types['PointerType'] = PointerType

class CTypesStructure(Node):
	layout = {}

	def __init__(self):
		Node.__init__(self)

		self.packages = {}
		self.modules = {}

	#add_package = add_named_item('packages')
	#add_module = add_named_item('modules')

	def get_by_path(self, path):
		node = self
		for name in path.split("."):
			node = node.children.get(name)
			if not node:
				break

		return node

	def resolve_types(self, node = None):
		if not node:
			node = self

		type = getattr(node, 'type', False)
		if isinstance(type, basestring):
			type = self.get_by_path(type)
			if type:
				node.type = type

		for child in node.children.allvalues():
			self.resolve_types(child)

	def display(self, node = None, depth = 0):
		if not node:
			node = self

		padding = "\t" * depth
		props = []
		for layout in node.get_layouts():
			for name in layout.get('properties', {}).keys():
				prop = getattr(node, name)
				if isinstance(prop, Node):
					path = prop.get_path()
					if path:
						prop = "<%s '%s'>"  % (type(prop).__name__, path)
				props.append("%s = %r" % (name, prop))

		print "%s%s(%s){" % (padding, type(node).__name__, ", ".join(props))
		for layout in node.get_layouts():
			for group in layout.get('children', {}).values():
				group_children = group['every']
				group_children = getattr(node, group_children)

				for child in group_children():
					self.display(child, depth + 1)
		print "%s}" % padding

	@classmethod
	def load(cls, file_path):
		return cls.from_xml(parse_xml(file_path))

	@classmethod
	def from_xml(cls, xml_node):
		s = cls()
		s.add_nodes_from_xml(xml_node, 'package', Package, s.add_package)
		s.add_nodes_from_xml(xml_node, 'module', Module, s.add_module)
		s.resolve_types()
		return s
_setup_named_child(CTypesStructure, 'packages', 'package', 'Package')
_setup_named_child(CTypesStructure, 'modules', 'module', 'Module')
