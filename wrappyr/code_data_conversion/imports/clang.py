from lxml.etree import parse as parse_xml, fromstring as parse_xml_from_string
from wrappyr.code_data_conversion.structure import Class, Function, Enum, Namespace

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
			self.parse_node(enum, Enum, self.enums)
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
