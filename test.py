#!/usr/bin/python2.6
import sys, os, time
import argparse
import pprint
from itertools import chain
from collections import defaultdict

import lxml.etree
from jinja2 import Environment, FileSystemLoader
from jinja2.runtime import Context
from jinja2.utils import concat

parser = argparse.ArgumentParser(prog = sys.argv[0])
parser.add_argument("input")
parser.add_argument("-o", "--output")
parser.add_argument("--cpp")
parser.add_argument("--header")
parser.add_argument("--template")
parser.add_argument("--template-dir")
args = parser.parse_args()
args.output = args.output or os.path.splitext(args.input)[0]
args.cpp = args.cpp or args.output + ".cpp"
args.header = args.header or args.output + ".h"
args.template = args.template or args.output + ".tpl"
args.template_dir = args.template_dir or os.path.dirname(args.template)

headerPath = args.input
headerDoc = lxml.etree.parse(headerPath)

class Node(object):
	def __init__(self, node):
		self.name = node.get('name')
		self.context = node.get('context')
		self.file = node.get('file')

class Class(Node):
	def __init__(self, node):
		Node.__init__(self, node)

		self.isStruct = (node.tag == "Struct")
		self.bases = tuple(i.get('type') for i in node.findall('Base'))
		self.methods = []
		self.members = []
		self.constructor = None
		self.destructor = None

	def process(self):
		self.isAbstract = False
		for method in self.methods:
			if method.isPureVirtual:
				self.isAbstract = True
				break

		conflicts = defaultdict(list)
		for method in self.methods:
			conflicts[method.name].append(method)
		for conflict in conflicts.values():
			if len(conflict) > 1:
				resolveNameConflict(funcs = conflict, cls = self)

class Function(Node):
	def __init__(self, node):
		Node.__init__(self, node)

		self.name = node.get('name')
		self.access = node.get('access')
		self.isFunctionPointer = (node.tag == 'FunctionType')
		self.isMethod = (node.tag == 'Method')
		self.isVirtual = (node.get('virtual') == '1')
		self.isPureVirtual = (node.get('pure_virtual') == '1')
		self.args = tuple(i.get('type') for i in node.findall('Argument'))
		self.returns = node.get('returns')

	def getArgsAsString(self, argConverter, names = ()):
		if len(names) < len(self.args):
			names = names + (None,) * (len(self.args) - len(names))
		names = tuple(" " + name if name else "" for name in names)

		return ", ".join(argConverter(arg) + name for arg, name in zip(self.args, names))

	def toFunctionPointer(self, argConverter, name = ""):
		#int (*pt2Func)(float, char, char)
		return "%s (*%s)(%s)" % (argConverter(self.returns), name, self.getArgsAsString(argConverter))

class Member(Node):
	def __init__(self, node):
		Node.__init__(self, node)

		self.name = node.get('name')
		self.type = node.get('type')
		self.access = node.get('access')

class Enumeration(Node):
	def __init__(self, node):
		Node.__init__(self, node)

		self.name = node.get('name')
		self.values = dict((i.get('name'), i.get('init')) for i in node.findall('EnumValue'))

class Pointer(object):
	def __init__(self, node):
		self.type = node.get('type')

class Reference(object):
	def __init__(self, node):
		self.type = node.get('type')

class Namespace(Node):
	def __init__(self, node):
		Node.__init__(self, node)

class FundamentalType(Node):
	def __init__(self, node):
		Node.__init__(self, node)

class Typedef(Node):
	def __init__(self, node):
		Node.__init__(self, node)

		self.type = node.get('type')

class File(Node):
	def __init__(self, node):
		Node.__init__(self, node)

		self.path = self.name

def getTypeAsString(tp):
	numPointers = 0
	numRefs = 0
	name = None

	while True:
		if tp.endswith("c"):
			tp = tp[0:-1]

		node = nodesByID.get(tp)
		if hasattr(node, 'type'):
			if isinstance(node, Pointer):
				numPointers += 1
			elif isinstance(node, Reference):
				numRefs += 1

			tp = node.type
			continue

		if isinstance(node, (Class, FundamentalType)):
			name = node.name
		if isinstance(node, Enumeration):
			name = "int"
		if isinstance(node, Function):
			numPointers -= 1
			name = node.toFunctionPointer(getTypeAsString)

		#print tp
		break

	if name:
		return "%s%s" % (name, "*" * (numPointers + numRefs))
	else:
		return "<unknown type>"

def isReference(tp):
	while True:
		if tp.endswith("c"):
			tp = tp[0:-1]

		node = nodesByID.get(tp)
		if hasattr(node, 'type'):
			if isinstance(node, Reference):
				return True

			tp = node.type
		else:
			break

		break

	return False

def getIdentifier(function = None, member = None, cls = None, namespaces = None, special = None):
	if cls:
		if member:
			pass
		else:
			if special == "constructor":
				return "%s_New" % (cls.name)
			elif special == "destructor":
				return "%s_Delete" % (cls.name)
			return "%s_%s" % (cls.name, function.name)

def fileFilter(file):
	return "Box2D" in nodesByID[file].path

def resolveNameConflict(funcs = None, cls = None, namespaces = None):
	for i, f in enumerate(funcs):
		f.name += str(i)

classFilter = lambda i: i.get('name') and "<" not in i.get("name") and not bool(i.get("incomplete"))
nodeTypes = {
	'File': {'type': File},
	'Class': {'type': Class, 'filter': classFilter},
	'Struct': {'type': Class, 'filter': classFilter},
	'Function': {'type': Function},
	'PointerType': {'type': Pointer},
	'ReferenceType': {'type': Reference},
	'FundamentalType': {'type': FundamentalType},
	'Typedef': {'type': Typedef},
	'Enumeration': {'type': Enumeration},
	'FunctionType': {'type': Function},
	'Namespace': {'type': Namespace},
	'Constructor': {'type': Function},
	'Method':  {'type': Function},
	'Field': {'type': Member},
}
nodesByID = {}
nodesByType = {}
for nodeName, nodeType in nodeTypes.items():
	nodeList = headerDoc.xpath('/GCC_XML/' + nodeName)
	newNodes = dict((i.get('id'), nodeType['type'](i)) for i in nodeList if
		nodeType.get('filter', lambda node: True)(i))
	nodesByID.update(newNodes)
	nodesByType[nodeName] = newNodes

for constructor in nodesByType['Constructor'].values():
	cls = nodesByType['Class'].get(constructor.context) or nodesByType['Struct'].get(constructor.context)
	if not cls:
		continue

	cls.constructor = constructor

for method in nodesByType['Method'].values():
	cls = nodesByType['Class'].get(method.context) or nodesByType['Struct'].get(method.context)
	if not cls:
		continue

	cls.methods.append(method)

for field in nodesByType['Field'].values():
	cls = nodesByType['Class'].get(field.context) or nodesByType['Struct'].get(field.context)
	if not cls:
		continue

	cls.members.append(field)

for cls in chain(nodesByType['Class'].values(), nodesByType['Struct'].values()):
	cls.process()

argNamesCls = tuple(chain('cls', (chr(i) for i in xrange(ord('a'), ord('m')))))
argNames = tuple(chr(i) for i in xrange(ord('a'), ord('m')))
header = open(args.header, 'w')
cpp = open(args.cpp, 'w')
cpp.write("""#include <Box2D.h>
#include "%s"

""" % args.header)

header.write('extern "C" {\n')
for cls in chain(nodesByType['Class'].values(), nodesByType['Struct'].values()):
	if not fileFilter(cls.file):
		continue

	header.write("struct {0};\n".format(cls.name))

header.write("\n// ----\n\n")
for cls in chain(nodesByType['Class'].values(), nodesByType['Struct'].values()):
	if not fileFilter(cls.file):
		continue

	header.write("// -- Begin class %s\n" % cls.name)
	if not cls.isAbstract and (not cls.constructor or cls.constructor.access == "public"):
		header.write("{0}* {1}({2});\n".format(cls.name,
			getIdentifier(cls = cls, special = "constructor"),
			cls.constructor.getArgsAsString(getTypeAsString) if cls.constructor else "")
		)

		cpp.write("{0}* {1}({2}){{\n".format(cls.name,
			getIdentifier(cls = cls, special = "constructor"),
			cls.constructor.getArgsAsString(getTypeAsString, argNames) if cls.constructor else "")
		)

		if cls.constructor:
			args = ", ".join(("*" + name if isReference(arg) else name) for name, arg in zip(argNames, cls.constructor.args))
		else:
			args = ""
		cpp.write("\treturn new {cls.name}({args});\n".format(cls = cls, args = args))

		cpp.write("}\n\n")
	header.write("void {func}({cls.name}*);\n".format(cls = cls, func = getIdentifier(cls = cls, special = "destructor")))

	for method in cls.methods:
		args = method.getArgsAsString(getTypeAsString)
		if args:
			args = "{0}*, {1}".format(cls.name, args)
		else:
			args = "{0}*".format(cls.name)
		header.write("{retType} {function}({args});\n".format(
			retType = getTypeAsString(method.returns),
			function = getIdentifier(method, cls = cls), args = args))
	header.write("// -- End class %s\n\n" % cls.name)
header.write('}\n')

header.close()
cpp.close()
