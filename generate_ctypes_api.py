#!/usr/bin/python2.6
import sys, os, time
import argparse
import pprint
from itertools import chain
from collections import defaultdict
from lxml.etree import parse as parseXML, fromstring as parseXMLFromString

def addNamedItem(prop):
	def add(self, item):
		getattr(self, prop)[item.name] = item

	return add

class Node(object):
	def __init__(self, parent, name):
		self.parent = parent
		self.name = name

	def addNodesFromXML(self, xml_node, name, cls, add_func):
		for node in xml_node.findall(name):
			add_func(cls.fromXML(self, node))

class Module(Node):
	def __init__(self, parent, name):
		Node.__init__(self, parent, name)

		self.libraries = {}
		self.functions = {}
		self.classes = {}

	addLibrary = addNamedItem('libraries')
	addFunction = addNamedItem('functions')
	addClass = addNamedItem('classes')

	@classmethod
	def fromXML(cls, parent, xml_node):
		mod = cls(parent, xml_node.get('name'))
		mod.addNodesFromXML(xml_node, 'library', Library, mod.addLibrary)
		mod.addNodesFromXML(xml_node, 'function', Function, mod.addFunction)
		mod.addNodesFromXML(xml_node, 'class', Class, mod.addClass)
		return mod

class Package(Module):
	def __init__(self, parent, name):
		Module.__init__(self, parent, name)

		self.packages = {}
		self.modules = {}

	addPackage = addNamedItem('packages')
	addModule = addNamedItem('modules')

	@classmethod
	def fromXML(cls, parent, xml_node):
		pkg = Module.fromXML.__func__(cls, parent, xml_node)
		pkg.addNodesFromXML(xml_node, 'package', Package, pkg.addPackage)
		pkg.addNodesFromXML(xml_node, 'module', Module, pkg.addModule)
		return pkg

class Library(Node):
	def __init__(self, parent, name, path, default = False):
		Node.__init__(self, parent, name)

		self.name = name
		self.path = path
		self.default = default

	@classmethod
	def fromXML(cls, parent, xml_node):
		return cls(parent, xml_node.get('name'), xml_node.get('path'), xml_node.get('default', '').lower() in ('1', 'true'))

class Class(Node):
	def __init__(self, parent, name):
		Node.__init__(self, parent, name)

		self.methods = {}
		self.members = {}

	addMethod = addNamedItem('methods')
	addMember = addNamedItem('members')

	@classmethod
	def fromXML(cls, parent, xml_node):
		cls = cls(parent, xml_node.get('name'))
		cls.addNodesFromXML(xml_node, 'method', Method, cls.addMethod)
		cls.addNodesFromXML(xml_node, 'member', Member, cls.addMember)
		return cls

class Function(Node):
	class CannotAddOperation(Exception): pass

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

	@classmethod
	def fromXML(cls, parent, xml_node):
		f = cls(parent, xml_node.get('name'))
		for op in xml_node.getchildren():
			f.addOperation(Operation.fromXML(cls, op))

		return f

class Method(Function):
	pass

class Member(Node):
	def __init__(self, parent, name, getter = None, setter = None):
		Node.__init__(self, parent, name)

		self.name = name
		self.getter = getter
		self.setter = setter

	@classmethod
	def fromXML(cls, parent, xml_node):
		member = cls(parent, xml_node.get('name'))
		getter = xml_node.find('getter')
		if getter is not None:
			getter = Method.fromXML(member, getter)
		setter = xml_node.find('setter')
		if setter is not None:
			setter = Method.fromXML(member, setter)
		return member

class Operation(object):
	types = {}

	def __init__(self):
		pass

	@classmethod
	def fromXML(cls, parent, xml_node):
		return cls.types[xml_node.tag].fromXML(parent, xml_node)

class Call(Operation):
	def __init__(self, symbol, library = None):
		self.symbol = symbol
		self.library = library
		self.args = []

	@classmethod
	def fromXML(cls, parent, xml_node):
		c = Call(xml_node.get('symbol'))
		for arg in xml_node.findall('argument'):
			c.args.append(Argument.fromXML(c, arg))

		return c
Operation.types['call'] = Call

class RawCode(Operation):
	def __init__(self, code):
		self.code = code

	@classmethod
	def fromXML(cls, parent, xml_node):
		return cls(xml_node.text)
Operation.types['raw'] = RawCode

class Argument(Node):
	def __init__(self, parent, type, name = None, default = None):
		Node.__init__(self, parent, name)

		self.type = type
		self.name = name
		self.default = default

	@classmethod
	def fromXML(cls, parent, xml_node):
		return cls(xml_node.get('type'), xml_node.get('name'), xml_node.get('default', ''))

class CTypesStructure(Node):
	def __init__(self):
		Node.__init__(self, None, None)

		self.packages = {}
		self.modules = {}

	addPackage = addNamedItem('packages')
	addModule = addNamedItem('modules')

	@classmethod
	def load(cls, file_path):
		return cls.fromXML(parseXML(file_path))

	@classmethod
	def fromXML(cls, xml_node):
		s = cls()
		s.addNodesFromXML(xml_node, 'package', Package, s.addPackage)
		s.addNodesFromXML(xml_node, 'module', Module, s.addModule)
		return s

if __name__ == "__main__":
	parser = argparse.ArgumentParser(prog = sys.argv[0])
	parser.add_argument("input")
	parser.add_argument("--output-path", default = os.getcwd())
	args = parser.parse_args()

	print CTypesStructure.load(args.input)
