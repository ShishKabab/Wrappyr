#!/usr/bin/python2.6
import sys, os, time
import argparse
import pprint
from itertools import chain
from collections import defaultdict

from lxml.etree import parse as parseXML, fromstring as parseXMLFromString
from jinja2 import Environment, FileSystemLoader
from jinja2.runtime import Context
from jinja2.utils import concat

parser = argparse.ArgumentParser(prog = sys.argv[0])
parser.add_argument("input")
parser.add_argument("--template", action = 'append', required = True, nargs = '+')
parser.add_argument("--template-dir")
args = parser.parse_args()
args.template_dir = args.template_dir or os.path.dirname(args.input)

class Node(object):
	def __init__(self, parent, xml_node):
		self.parent = parent
		self.name = xml_node.get('name')
		self.context = xml_node.get('context')
		self.file = xml_node.get('file')

class NodeReference(Node):
	def __init__(self, parent, xml_node):
		Node.__init__(self, parent, xml_node)

		self.id = xml_node.get('id')

	def get(self):
		return self.parent.nodes.get(self.id)

class Class(Node):
	def __init__(self, parent, xml_node):
		Node.__init__(self, parent, xml_node)

		#self.isStruct = (node.tag == "Struct")
		self.bases = tuple(NodeReference(self.parent, i) for i in xml_node.findall('Base'))
		self.methods = defaultdict(list)
		for i in xml_node.findall('Method'):
			if '1' not in (i.get('constructor'), i.get('destructor')) and ">" not in i.get('name'):
				self.methods[ i.get('name') ].append(Function(self.parent, i))
		self.members = tuple(Member(self.parent, i) for i in xml_node.findall('Field'))
		self.constructors = tuple(Function(self.parent, i) for i in xml_node.findall('Method') if i.get('constructor') == '1')
		self.destructor = tuple(Function(self.parent, i) for i in xml_node.findall('Method') if i.get('destructor') == '1')
		self.destructor = self.destructor and self.destructor[0]
		self.abstract = any(i.isPure for methods in self.methods.values() for i in methods)

class Argument(Node):
	def __init__(self, parent, xml_node):
		Node.__init__(self, parent, xml_node)

		self.optional = (xml_node.get('optional') == '1')
		self.type = Type(self.parent, xml_node.find('Type'))

class Type(Node):
	def __init__(self, parent, xml_node):
		Node.__init__(self, parent, xml_node)

		self.pointers = 0
		self.refs = 0
		self.name = None
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
			elif tp in ('builtin', 'record'):
				self.name = xml_node.get('name')
				if self.name == '_Bool':
					self.name = 'unsigned char'
			elif tp == 'enum':
				self.name = 'unsigned int'
			else:
				self.valid = False
			self.type = tp
			self.const = self.const or (xml_node.get('const') == '1')

			break

	def isCppOnly(self): # We can pass pointers to objects to C, but not the objects themselves
		#print self.name, self.type, self.pointers, self.refs
		return self.type == 'record' and not self.pointers and not self.refs

	def asString(self, c_compat = True):
		return str(self.name) + ("*" * self.pointers) + (("*" if c_compat else "&") * self.refs)

class Function(Node):
	def __init__(self, parent, xml_node):
		Node.__init__(self, parent, xml_node)

		self.access = xml_node.get('access')
		#self.isFunctionPointer = (xml_node.tag == 'FunctionType')
		self.isMethod = (xml_node.tag == 'Method')
		self.isVirtual = (xml_node.get('virtual') == '1')
		self.isPure = (xml_node.get('pure') == '1')
		self.isStatic = (xml_node.get('pure') == '1')
		self.args = tuple(Argument(self.parent, i) for i in xml_node.findall('Argument'))
		self.returns = Type(self.parent, xml_node.find('Returns').find('Type'))
		self.valid = (not any(not i.type.valid for i in self.args)) and self.returns.valid

	def argsAsString(self, names = ()):
		if len(names) < len(self.args):
			names = names + (None,) * (len(self.args) - len(names))
		names = tuple(" " + name if name else "" for name in names)

		return ", ".join(arg.type.asString() + name for arg, name in zip(self.args, names))

	def toFunctionPointer(self, name = ""):
		#int (*pt2Func)(float, char, char)
		return "%s (*%s)(%s)" % (getTypeAsString(self.returns), name, self.argsAsString())

class Member(Node):
	def __init__(self, parent, xml_node):
		Node.__init__(self, parent, xml_node)

		self.access = xml_node.get('access')
		self.type = Type(self.parent, xml_node.find('Type'))

class ClangImporter(object):
	def __init__(self, path):
		self.nodes = {}
		self.classes = {}
		self.namespaces = {}
		self.doc = parseXML(path)
		for cls in self.doc.xpath('//Class'):
			self.parseClass(cls)

	def parseClass(self, cls):
		id = cls.get('id')
		cls = Class(self, cls)
		self.nodes[ id ] = cls
		self.classes[ id ] = cls

	def render(self, template):
		return template.render(
			classes = self.classes,
			letters = lambda begin, end: [chr(i) for i in xrange(ord(begin), ord(end))]
		)

env = Environment(
	loader = FileSystemLoader([args.template_dir]),
)
importer = ClangImporter(args.input)
for template in args.template:
	inPath = template[0]
	if len(template) == 1:
		outPath = template[0]
		outPath = outPath[0 : outPath.rfind('.')]
	else:
		outPath = template[1]

	template = env.get_template(inPath)
	content = importer.render(template)
	open(outPath, 'w').write(content)
