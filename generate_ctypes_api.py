#!/usr/bin/python2.6
import sys, os, time
import argparse
import pprint
from itertools import chain
from collections import defaultdict
from lxml.etree import parse as parseXML, fromstring as parseXMLFromString
from MultiDict import OrderedMultiDict

def addNamedItem(prop):
	def add(self, item):
		self.children[item.name] = item
		getattr(self, prop)[item.name] = item

	return add

def boolFromString(s):
	return s.lower() in ('1', 'true')

class Node(object):
	types = {}

	def __init__(self, parent, name = None):
		self.parent = parent
		self.name = name
		self.children = OrderedMultiDict()

	def addNodesFromXML(self, xml_node, name, cls, add_func):
		for node in xml_node.findall(name):
			add_func(cls.fromXML(self, node))

	def getPath(self):
		path = []

		node = self
		while node.parent:
			if not node.name:
				return
			path.insert(0, node.name)
			node = node.parent

		return ".".join(path)

	@classmethod
	def getLayouts(cls):
		layouts = []
		nodecls = cls
		while nodecls != Node:
			layouts.insert(0, nodecls.layout)
			nodecls = nodecls.__base__

		return layouts

	@classmethod
	def fromXML(cls, parent, xml_node):
		kwds = {}

		layouts = cls.getLayouts()
		for layout in layouts:
			for prop, conv in layout.get('properties', {}).items():
				kwds[prop] = conv(xml_node.get(prop))

		node = cls(parent, **kwds)
		for layout in layouts:
			for name, group in layout.get('children', {}).items():
				add = group.get('add') or 'add' + group['type']
				add = getattr(node, add)
				tp = cls.types[group['type']]

				if isinstance(group['name'], basestring):
					xml_child_nodes = xml_node.findall(group['name'])
				else:
					xml_child_nodes = chain.from_iterable(xml_node.findall(i) for i in group['name'])

				for xml_child_node in xml_child_nodes:
					add(tp.fromXML(node, xml_child_node))

		return node

class Module(Node):
	layout = {
		'properties': {
			'name': str
		},
		'children': {
			'libraries': {
				'name': 'library',
				'type': 'Library'
			},
			'functions': {
				'name': 'function',
				'type': 'Function'
			},
			'classes': {
				'name': 'class',
				'type': 'Class'
			},
		}
	}

	def __init__(self, parent, name):
		Node.__init__(self, parent, name)

		self.libraries = {}
		self.functions = {}
		self.classes = {}

	addLibrary = addNamedItem('libraries')
	addFunction = addNamedItem('functions')
	addClass = addNamedItem('classes')

	def getDefaultLibrary(self):
		mod = self
		while mod:
			for lib in mod.libraries.values():
				if lib.default:
					return lib
			mod = mod.parent
Node.types['Module'] = Module

class Package(Module):
	layout = {
		'children': {
			'packages': {
				'name': 'package',
				'type': 'Package'
			},
			'modules': {
				'name': 'module',
				'type': 'Module'
			},
		}
	}

	def __init__(self, parent, name):
		Module.__init__(self, parent, name)

		self.packages = {}
		self.modules = {}

	addPackage = addNamedItem('packages')
	addModule = addNamedItem('modules')
		#return pkg
Node.types['Package'] = Package

class Library(Node):
	layout = {
		'properties': {
			'name': str,
			'path': str,
			'default': boolFromString
		},
	}

	def __init__(self, parent, name, path, default = False):
		Node.__init__(self, parent, name)

		self.name = name
		self.path = path
		self.default = default
Node.types['Library'] = Library

class Class(Node):
	layout = {
		'properties': {
			'name': str
		},
		'children': {
			'methods': {
				'name': 'method',
				'type': 'Method'
			},
			'members': {
				'name': 'member',
				'type': 'Member'
			},
		}
	}

	def __init__(self, parent, name):
		Node.__init__(self, parent, name)

		self.methods = {}
		self.members = {}

	addMethod = addNamedItem('methods')
	addMember = addNamedItem('members')
Node.types['Class'] = Class

class Function(Node):
	class CannotAddOperation(Exception): pass

	layout = {
		'properties': {
			'name': str
		},
		'children': {
			'ops': {
				'name': ('call', 'raw'),
				'type': 'Operation',
				'add': 'addOperation',
				'all': 'getAllOperations'
			}
		}
	}

	def __init__(self, parent, name):
		Node.__init__(self, parent, name)

		self.name = name
		self.ops = []
		self.raw = None

	def addOperation(self, op):
		if self.raw:
			raise self.CannotAddOperation("Function '%s' has raw code and you tried to add a '%s' operation" %
				(self.name, type(op).__name__))

		self.ops.append(op)
		self.children[None] = op

	def getAllOperations(self):
		return self.ops
Node.types['Function'] = Function

class Method(Function):
	layout = {}
Node.types['Method'] = Method

class Member(Node):
	layout = {
		'properties': {
			'name': str
		},
		'children': {
			'getter': {
				'name': 'getter',
				'type': 'Method',
				'add': 'setGetter',
				'all': 'getGetters'
			},
			'setter': {
				'name': 'setter',
				'type': 'Method',
				'add': 'setSetter',
				'all': 'getSetters'
			},
		}
	}

	def __init__(self, parent, name, getter = None, setter = None):
		Node.__init__(self, parent, name)

		self.name = name
		self.getter = getter
		self.setter = setter

	def setGetter(self, getter):
		self.getter = getter
		self.children[None] = getter

	def setSetter(self, setter):
		self.setter = setter
		self.children[None] = setter

	def getGetters(self):
		return (self.getter,) if self.getter else ()

	def getSetters(self):
		return (self.setter,) if self.setter else ()
Node.types['Member'] = Member

class Operation(Node):
	layout = {}
	op_types = {}

	def __init__(self, parent):
		Node.__init__(self, parent)

	@classmethod
	def fromXML(cls, parent, xml_node):
		if cls == Operation:
			return cls.op_types[xml_node.tag].fromXML(parent, xml_node)
		else:
			return Node.fromXML.__func__(cls, parent, xml_node)
Node.types['Operation'] = Operation

class Call(Operation):
	layout = {
		'properties': {
			'symbol': str,
			'library': lambda v: v and str(v)
		},

		'children': {
			'args': {
				'name': 'argument',
				'type': 'Argument',
				'add': 'addArgument',
				'all': 'getAllArguments'
			},
			'returns': {
				'name': 'returns',
				'type': 'ReturnValue',
				'add': 'setReturnValue',
				'all': 'getReturnValues'
			}
		}
	}

	def __init__(self, parent, symbol, library = None):
		Operation.__init__(self, parent)

		self.symbol = symbol
		self.library = library
		self.args = []
		self.returns = None

	def addArgument(self, arg):
		self.args.append(arg)
		self.children[None] = arg

	def getAllArguments(self):
		return self.args

	def setReturnValue(self, ret):
		self.returns = ret
		self.children[None] = ret

	def getReturnValues(self):
		return (self.returns,) if self.returns else ()
Operation.op_types['call'] = Call
Node.types['Call'] = Call

class RawCode(Operation):
	layout = {
		'properties': {
			'code': str
		}
	}

	def __init__(self, parent, code):
		Operation.__init__(self, parent)

		self.code = code
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

	def __init__(self, parent, type, name = None, default = None):
		Node.__init__(self, parent, name)

		self.type = type
		self.name = name
		self.default = default
Node.types['Argument'] = Argument

class ReturnValue(Node):
	layout = {
		'properties': {
			'type': str,
			'ownership': lambda v: False if v is None else boolFromString(v)
		}
	}

	def __init__(self, parent, type, ownership = False):
		Node.__init__(self, parent)

		self.type = type
		self.ownership = ownership
Node.types['ReturnValue'] = ReturnValue

class CTypesStructure(Node):
	layout = {
		'children': {
			'packages': {
				'name': 'package',
				'type': 'Package'
			},
			'modules': {
				'name': 'module',
				'type': 'Module'
			},
		}
	}

	def __init__(self):
		Node.__init__(self, None)

		self.packages = {}
		self.modules = {}

	addPackage = addNamedItem('packages')
	addModule = addNamedItem('modules')

	def getByPath(self, path):
		node = self
		for name in path.split("."):
			node = node.children.get(name)
			if not node:
				break

		return node

	def resolveTypes(self, node = None):
		if not node:
			node = self

		type = getattr(node, 'type', False)
		if isinstance(type, basestring):
			type = self.getByPath(type)
			if type:
				node.type = type

		for child in node.children.allvalues():
			self.resolveTypes(child)

	def display(self, node = None, depth = 0):
		if not node:
			node = self

		layouts = []
		cls = type(node)
		while cls != Node:
			layouts.insert(0, cls.layout)
			cls = cls.__base__

		padding = "\t" * depth
		props = []
		for layout in layouts:
			for name in layout.get('properties', {}).keys():
				prop = getattr(node, name)
				if isinstance(prop, Node):
					path = prop.getPath()
					if path:
						prop = "<%s '%s'>"  % (type(prop).__name__, path)
				props.append("%s = %r" % (name, prop))

		print "%s%s(%s){" % (padding, type(node).__name__, ", ".join(props))
		for layout in layouts:
			for groupName, group in layout.get('children', {}).items():
				groupChildren = group.get('all')
				if groupChildren:
					groupChildren = getattr(node, groupChildren)
				else:
					groupChildren = getattr(node, groupName).values

				for child in groupChildren():
					self.display(child, depth + 1)
		print "%s}" % padding

	@classmethod
	def load(cls, file_path):
		return cls.fromXML(parseXML(file_path))

	@classmethod
	def fromXML(cls, xml_node):
		s = cls()
		s.addNodesFromXML(xml_node, 'package', Package, s.addPackage)
		s.addNodesFromXML(xml_node, 'module', Module, s.addModule)
		s.resolveTypes()
		return s

def writePackage(pkg, base_dir):
	base_dir = os.path.join(base_dir, pkg.name)
	os.makedirs(base_dir)

	open(os.path.join(base_dir, "__init__.py"), 'w').close()
	for subpkg in pkg.packages.values():
		writePackage(subpkg, base_dir)

if __name__ == "__main__":
	parser = argparse.ArgumentParser(prog = sys.argv[0])
	parser.add_argument("input")
	parser.add_argument("--output-path", default = os.getcwd())
	args = parser.parse_args()

	s = CTypesStructure.load(args.input)
	s.display()
	#for pkg in s.packages.values():
		#writePackage(pkg, args.output_path)
