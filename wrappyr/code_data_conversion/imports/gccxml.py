from functools import partial
from collections import defaultdict
from itertools import chain
from lxml.etree import parse as parse_xml
from wrappyr.code_data_conversion.structure import (
    Class, Function, Enumeration, Namespace,
    AccessSpecifier, Member, Method,
    FunctionSignature, Struct, SourceLocation, Argument, QualifiedType, Builtin, Pointer, Reference, Array, Node, Typedef)

class GCCXMLImporter(object):
    class ParseError(Exception): pass

    def __init__(self, path):
        self.functions = []
        self.classes = []
        self.structs = []
        self.enums = []

        # Begin temporaries
        self.nodes = {}
        self.namespaces = []

        # A dict of {context: {function: [signatures]}}
        self.signatures = defaultdict(partial(defaultdict, list))
        # End temporaries

        parsers = {
            'Struct': self.parse_class, # Not all Struct tags are POD
            'Class': self.parse_class,
            'Function': self.parse_function,
            'Method': self.parse_method,
            'Constructor': self.parse_method,
            'Destructor': self.parse_method,
            'Field': self.parse_field,
            'Enumeration': self.parse_enum,
            'ArrayType': self.parse_array,
            'PointerType': self.parse_pointer,
            'ReferenceType': self.parse_reference,
            'CvQualifiedType': self.parse_qualified_type,
            'FundamentalType': self.parse_builtin,
            'Typedef': self.parse_typedef,
            'File': self.parse_file,
            'Namespace': self.parse_namespace,
        }

        doc = parse_xml(path)
        for xml_node in doc.getroot().iterchildren():
            parser = parsers.get(xml_node.tag)
            if parser:
                parser(xml_node)

        self.process_locations()
        self.process_contexts()
        self.process_namespaces()
        self.process_signatures()
        self.process_classes()
        self.process_types()

        del self.nodes
        del self.namespaces

#		for prop in temp:
#			delattr(self, prop)

    def process_contexts(self):
        nodes = self.nodes
        for node in nodes.itervalues():
            if not isinstance(node, Node):
                continue

            context = node.context
            if context:
                context = nodes.get(context)
            node.context = context

            if isinstance(context, Namespace) and isinstance(node, (Function, Struct, Class, Enumeration)):
                context.nodes.append(node)

        # Weed out contextless nodes, which are probably members of templates
        self.classes = [cls for cls in self.classes if cls.context]
        self.structs = [struct for struct in self.structs if struct.context]
        self.enums = [enum for enum in self.enums if enum.context]

    def process_locations(self):
        nodes = self.nodes
        for node in nodes.itervalues():
            if not isinstance(node, Node):
                continue

            location = node.location
            if location:
                location = location.split(":")
                path = nodes.get(location[0])
                line = int(location[1])
                node.location = SourceLocation(path, line)

    def process_types(self):
        # Eliminate all typdefs
        updates = {}
        for id, node in self.nodes.iteritems():
            if not isinstance(node, Typedef):
                continue

            type = self.nodes.get(node.type)
            while isinstance(type, Typedef):
                type = self.nodes.get(type.type)
            updates[id] = type
        self.nodes.update(updates)

        # Make sure all pointers, references and arrays point to a qualified type
        # and all qualified types point to a type
        for id, node in self.nodes.iteritems():
            if not isinstance(node, (QualifiedType, Pointer, Reference, Array)):
                continue
            if not isinstance(node.type, basestring):
                continue

            type = self.nodes.get(node.type)
            if not isinstance(node, QualifiedType) and not isinstance(type, QualifiedType):
                type = QualifiedType(type)
            node.type = type

        members = (member for cls in self.classes for member in cls.members)
        signature_args = (arg for function in self.signatures.itervalues()
                                for sigs in function.itervalues()
                                for sig in sigs
                                for arg in sig.args)
        for node in chain(members, signature_args):
            if not isinstance(node, Node):
                continue

            type = self.nodes.get(node.type)
            if not isinstance(type, QualifiedType):
                type = QualifiedType(type)
            node.type = type

        signatures = (sig for function in self.signatures.itervalues()
                            for sigs in function.itervalues()
                            for sig in sigs)
        for node in signatures:
            if not node.returns:
                continue

            type = self.nodes.get(node.returns)
            if not isinstance(type, QualifiedType):
                type = QualifiedType(type)
            node.returns = type

    def process_namespaces(self):
        self.root_namespace = self.nodes['_1']
        self.root_namespace.name = ""
        for ns in self.namespaces:
            cxt = ns.context
            if cxt:
                cxt.children[ns.name] = ns

    def process_signatures(self):
        for context, function in self.signatures.iteritems():
            for name, signatures in function.iteritems():
                cxt = self.nodes.get(context)
                if not cxt:
                    continue

                f = None
                if isinstance(cxt, (Class, Struct)):
                    if all(sig.constructor for sig in signatures):
                        cxt.constructors = signatures
                    elif signatures[0].destructor:
                        cxt.destructor = signatures[0]
                    else:
                        f = Method(name)
                        cxt.methods.append(f)
                else:
                    f = Function(name)
                    cxt.nodes.append(f)

                if f:
                    f.context = cxt
                    f.signatures = signatures
                    for sig in signatures:
                        sig.context = f

    def process_classes(self):
        for cls in self.classes:
            cls.bases = [self.nodes.get(base) for base in cls.bases]

            members = []
            for member in cls.members:
                member = self.nodes.get(member)
                if not isinstance(member, Member):
                    continue
                members.append(member)
            cls.members = members

            cls.determine_abstractness()
            cls.determine_dynamic()

    def parse_node(self, xml_node, node_type, registry = None, **kwds):
        node = node_type(**kwds)
        node.context = xml_node.get('context')
        node.location = xml_node.get('location')

        if registry:
            getattr(self, registry).append(node)
        id = xml_node.get('id')
        if id:
            self.nodes[id] = node
        return node

    def parse_struct(self, xml_node, node_type = Struct, registry = "structs"):
        name = xml_node.get('name', '')
        if not name or "<" in name:
            return
        if xml_node.get('incomplete') == '1': # TODO: Do something useful with incomplete types
            return

        struct = self.parse_node(xml_node, node_type, registry, name = name)
        struct.access = AccessSpecifier.from_string(xml_node.get('access', 'public'))
        struct.bases = [i.get('type') for i in xml_node.findall('Base')]
        struct.members = xml_node.get('members', '').split(" ")

        return struct

    def parse_class(self, xml_node):
        cls = self.parse_struct(xml_node, Class, "classes")
        return cls

    def parse_function_signature(self, xml_node, registry = None):
        name = xml_node.get('name', '')
        if not name or "<" in name:
            return

        sig = self.parse_node(xml_node, FunctionSignature, registry)
        sig.access = AccessSpecifier.from_string(xml_node.get('access', 'public'))
        sig.constructor = (xml_node.tag == 'Constructor')
        sig.destructor = (xml_node.tag == 'Destructor')
        sig.virtual = (xml_node.get('virtual') == '1')
        sig.pure = (xml_node.get('pure_virtual') == '1')
        sig.static = (xml_node.get('static') == '1')
        sig.const = (xml_node.get('const') == '1')

        sig.args = [self.parse_argument(arg_node, sig) for arg_node in xml_node.findall("Argument")]
        sig.returns = xml_node.get('returns')

        if sig.constructor:
            name = "+init" # Invalid method name so it won't class with normal methods
        elif sig.destructor:
            name = "+del"
        self.signatures[sig.context][name].append(sig)
        return sig

    def parse_function(self, xml_node):
        return self.parse_function_signature(xml_node)

    def parse_method(self, xml_node):
        return self.parse_function_signature(xml_node)

    def parse_argument(self, xml_node, context = None):
        arg = self.parse_node(xml_node, Argument, name = xml_node.get("name"))
        arg.context = context
        arg.type = xml_node.get('type')
        arg.optional = bool(xml_node.get('default'))

        return arg

    def parse_enum(self, xml_node):
        enum = self.parse_node(xml_node, Enumeration, "enums",
                               name = xml_node.get("name"))
        enum.access = AccessSpecifier.from_string(xml_node.get('access', 'public'))
        for value in xml_node.findall('EnumValue'):
            enum.add_field(value.get('name'), int(value.get('init')))

        return enum

    def parse_field(self, xml_node):
        member = self.parse_node(xml_node, Member, name = xml_node.get('name'))
        member.access = AccessSpecifier.from_string(xml_node.get('access', 'public'))
        member.type = xml_node.get('type')

        return member

    def parse_pointer(self, xml_node):
        ptr = self.parse_node(xml_node, Pointer)
        ptr.type = xml_node.get('type')
        return ptr

    def parse_reference(self, xml_node):
        ref = self.parse_node(xml_node, Reference)
        ref.type = xml_node.get('type')
        return ref

    def parse_array(self, xml_node):
        arr = self.parse_node(xml_node, Array)
        arr.type = xml_node.get('type')
        return arr

    def parse_builtin(self, xml_node):
        builtin = self.parse_node(xml_node, Builtin, name = xml_node.get('name'))
        return builtin

    def parse_qualified_type(self, xml_node):
        qualtype = self.parse_node(xml_node, QualifiedType)
        qualtype.type = xml_node.get('type')
        qualtype.const = (xml_node.get('const') == '1')
        return qualtype

    def parse_typedef(self, xml_node):
        typedef = self.parse_node(xml_node, Typedef)
        typedef.type = xml_node.get('type')
        return typedef

    def parse_file(self, xml_node):
        self.nodes[xml_node.get('id')] = xml_node.get('name')

    def parse_namespace(self, xml_node):
        ns = self.parse_node(xml_node, Namespace, 'namespaces', name = xml_node.get('name'))
        return ns
