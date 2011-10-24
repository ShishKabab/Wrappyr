import pprint
from itertools import chain
from collections import defaultdict

class AccessSpecifier(object):
    Unknown = 0
    Public = 1
    Protected = 2
    Private = 3

    @classmethod
    def from_string(cls, s):
        return {
            'unknown': cls.Unknown,
            'public': cls.Public,
            'protected': cls.Protected,
            'private': cls.Private
        }.get(s, cls.Unknown)

class Node(object):
    def __init__(self):
        self.context = None # Namespace, class or struct
        self.location = None

    def get_full_name(self, separator = "::"):
        """Returns the full name of this node, separated by sep.

        For class Foo::Bar::Cls:
        - cls.get_full_name() returns "Foo::Bar::Cls"
         - cls.get_full_name(".") returns "Foo.Bar.Cls"
        """

        names = []
        node = self
        while node:
            name = getattr(node, 'name', None)
            if not name:
                break

            names.append(name)
            node = node.context

        return separator.join(reversed(names))

    def get_namespace(self):
        cxt = self.context
        while cxt and not isinstance(cxt, Namespace):
            cxt = cxt.context

        return cxt

class Struct(Node):
    def __init__(self, name):
        super(Struct, self).__init__()

        self.name = name
        self.access = AccessSpecifier.Unknown
        self.members = []

    def as_string(self, c_compat_names = True, c_compat_refs = True, c_compat_const = True,
                  nested = False):
        return self.get_full_name() if not c_compat_names else "void"

class Class(Struct):
    def __init__(self, name):
        super(Class, self).__init__(name)

        self.bases = []
        self.methods = []
        self.constructors = []
        self.destructor = None
        self.operators = []
        # Whether this class (not including bases)
        # contains any pure virtual methods
        self.abstract = None
        # Whether this class (not including bases)
        # contains any virtual methods
        self.dynamic = None

    def determine_abstractness(self):
        """Sets self.abstract property based on whether this class
        contains any pure virtual methods. To test whether this class can be
        instantiated based on whether any (inherited) pure virtual methods
        are not implemented, use the is_abstract() method.

        """

        self.abstract = any(sig.pure
                            for method in self.methods
                            for sig in method.signatures)

    def determine_dynamic(self, non_virtual = None):
        """Sets self.dynamic property based on whether this class
        contains any virtual methods. To test whether this class can be
        instantiated based on whether any (inherited) pure virtual methods
        are not implemented, use the is_dynamic() method.

        """

        self.dynamic = any(sig.virtual
                            for method in self.methods
                            for sig in method.signatures)

    def iter_bases(self, include_self = False):
        """Recursively yields all bases (breadth first)"""
        if include_self:
            yield self
        for base in self.bases:
            yield base
        for base in self.bases:
            for base in base.iter_bases():
                yield base

    def iter_virtual_signatures(self, recursive = True):
        for base in self.iter_bases(True):
            for method in base.methods:
                for sig in method.signatures:
                    if sig.virtual:
                        yield sig
            if not recursive:
                break

    def get_virtual_signatures(self, recursive = True):
        return list(self.iter_virtual_signatures(recursive))

    def get_non_virtual_signatures(self, recursive = True):
        signatures = [signature
                      for method in self.methods
                      for signature in method.signatures
                      if not signature.virtual]
        if recursive:
            for base in self.bases:
                signatures.extend(base.get_non_virtual_signatures())
        return signatures

    def get_pure_virtual_signatures(self, recursive = True):
        signatures = [signature
                      for method in self.methods
                      for signature in method.signatures
                      if signature.pure]
        if recursive:
            for base in self.bases:
                signatures.extend(base.get_pure_virtual_signatures())
        return signatures

    def get_implemented_signatures(self, recursive = True):
        signatures = [signature
            for method in self.methods
            for signature in method.signatures
            if not signature.pure]
        if recursive:
            for base in self.bases:
                signatures.extend(base.get_implemented_signatures())
        return signatures

    def get_overridable_signatures(self):
        non_virtual = self.get_non_virtual_signatures()
        virtual = self.iter_virtual_signatures()

        by_signature = {}
        for sig in chain(non_virtual, virtual):
            unique = (sig.context.name, sig.const)
            unique += tuple(arg.type for arg in sig.args)
            by_signature.setdefault(unique, sig)

        by_method = defaultdict(list)
        for sig in by_signature.itervalues():
            if sig.virtual:
                by_method[sig.context.name].append(sig)

        return [i for i in by_method.itervalues()]

    def is_abstract(self):
        """Determine whether this class has and/or inherits
        any pure virtual methods which are not yet implemented.

        """

        pure = self.get_pure_virtual_signatures()
        pure = [(sig.context.name, sig.const) + tuple((arg.type for arg in sig.args)) for sig in pure]
        pure = set(pure)

        nonpure = self.get_implemented_signatures()
        nonpure = [(sig.context.name, sig.const) + tuple((arg.type for arg in sig.args)) for sig in nonpure]
        nonpure = set(nonpure)

        return bool(pure - nonpure)

    def is_dynamic(self):
        virtual = self.get_virtual_signatures()
        virtual = [(sig.context.name, sig.const) + tuple((arg.type for arg in sig.args)) for sig in virtual]
        virtual = set(virtual)

        nonvirtual = self.get_non_virtual_signatures()
        nonvirtual = [(sig.context.name, sig.const) + tuple((arg.type for arg in sig.args)) for sig in nonvirtual]
        nonvirtual = set(nonvirtual)

        return bool(virtual - nonvirtual)

    def is_valid(self):
        """Do all bases for this class (and their bases) exist?"""

        for base in self.bases:
            if not base or not base.is_valid():
                return False

        return True

    def is_default_constructable(self):
        return not self.constructors or any(
            len(constructor.args) == 0 and constructor.access == AccessSpecifier.Public
            for constructor in self.constructors)

    def get_class_implementing_signature(self, signature):
        if any(i == signature and not i.pure for method in self.methods for i in method.signatures):
            return self

        for base in self.bases:
            cls = base.get_class_implementing_signature(signature)
            if cls:
                return cls

class Argument(Node):
    def __init__(self, name = None, type = None, optional = False):
        super(Argument, self).__init__()

        self.name = name
        self.type = type
        self.optional = optional

class FunctionSignature(Node):
    def __init__(self):
        super(FunctionSignature, self).__init__()

        self.access = AccessSpecifier.Unknown
        self.constructor = False
        self.destructor = False
        self.operator = False
        self.static = False
        self.const = False
        self.args = []
        self.returns = None
        self.valid = True
        self.extern_c = False
        self.pure = False
        self.virtual = False

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
        if not self.returns:
            return False

        type = self.returns.type
        if not isinstance(type, Builtin):
            return True
        return type.name != "void"

    def as_string(self, c_compat_names = True, c_compat_refs = True, c_compat_const = True,
                  nested = False, name = ""):
        #int (*pt2Func)(float, char, char)
        return "%s (*%s)(%s)" % (self.returns.as_string(), name, self.args_as_string())

    def is_valid(self):
        valid = not self.returns or self.returns.is_valid()
        valid = valid and all(arg.type.is_valid() for arg in self.args)
        return valid

    def iter_types(self):
        """Yields return type and argument types"""

        yield self.returns
        for arg in self.args:
            yield arg.type

class Function(Node):
    def __init__(self, name, signatures = None):
        super(Function, self).__init__()

        self.name = name
        self.signatures = signatures or []

class Method(Function):
    def __init__(self, name, signatures = None, context = None):
        super(Method, self).__init__(name, signatures)

        self.context = context

class Pointer(Node):
    def __init__(self, type = None):
        super(Pointer, self).__init__()

        self.type = type

    def __hash__(self):
        return hash(self.type)

    def __eq__(self, other):
        if not isinstance(other, Pointer):
            return False

        a = self.type
        b = other.type

        return a == b

    def __ne__(self, other):
        return not self.__eq__(other)

    def as_string(self, c_compat_names = True, c_compat_refs = True, c_compat_const = True,
                  nested = False):
        type = self.type.as_string(c_compat_names, c_compat_refs, c_compat_const, True)
        return type + "*"

class Reference(Node):
    def __init__(self, type = None):
        super(Reference, self).__init__()

        self.type = type

    def __hash__(self):
        return hash(self.type)

    def __eq__(self, other):
        if not isinstance(other, Reference):
            return False

        a = self.type
        b = other.type

        return a == b

    def __ne__(self, other):
        return not self.__eq__(other)

    def as_string(self, c_compat_names = True, c_compat_refs = True, c_compat_const = True,
                  nested = False):
        sign = "*" if c_compat_refs else "&"
        type = self.type.as_string(c_compat_names, c_compat_refs, c_compat_const, True)
        return type + sign

class Enumeration(Node):
    def __init__(self, name):
        super(Enumeration, self).__init__()

        self.name = name
        self.fields = []

    def add_field(self, name, value):
        self.fields.append((name, value))

    def as_string(self, c_compat_names = True, c_compat_refs = True, c_compat_const = True,
                  nested = False):
        return "unsigned char" if c_compat_names else self.get_full_name()

class Member(Node):
    def __init__(self, name):
        super(Member, self).__init__()

        self.name = name
        self.access = AccessSpecifier.Unknown
        self.type = None

class QualifiedType(Node):
    def __init__(self, type = None, const = False):
        super(QualifiedType, self).__init__()

        self.type = type
        self.const = const

    def __hash__(self):
        return hash((self.type, self.const))

    def __eq__(self, other):
        if not isinstance(other, QualifiedType):
            return False

        a = (self.type, self.const)
        b = (other.type, other.const)

        return a == b

    def __ne__(self, other):
        return not self.__eq__(other)

    def get_total_pointers(self):
        """Returns how many pointers are nested"""
        pointers = 0

        qualtype = self
        while isinstance(qualtype.type, (Pointer, Reference)):
            if isinstance(qualtype.type, Pointer):
                pointers += 1
            qualtype = qualtype.type.type

        return pointers

    def is_reference(self):
        return isinstance(self.type, Reference)

    def is_cpp_only(self):
        return isinstance(self.type, Struct)

    def strip_pointers_and_references(self):
        qualtype = self
        while isinstance(qualtype.type, (Pointer, Reference)):
            qualtype = qualtype.type.type

        return qualtype

    def get_type_name(self, sep = "::"):
        """Get name of type ultimately reference or pointed to, separated by sep.

        As an example, for type Test::Foo**&, Test::Foo is returned (if sep == "::")
        """

        return self.strip_pointers_and_references().type.get_full_name(sep)

    def as_string(self, c_compat_names = True, c_compat_refs = True, c_compat_const = True,
                  nested = False):
        type = self.type.as_string(c_compat_names, c_compat_refs, c_compat_const, nested)
        if c_compat_refs and not nested and isinstance(self.type, (Class, Struct)):
            type += "*"
        if not c_compat_const and self.const:
            if isinstance(self.type, (Reference, Pointer)):
                type += " const"
            else:
                type = "const " + type
        return type

    def is_valid(self):
        if isinstance(self.type, (Pointer, Reference, Array)):
            return self.type.type.is_valid()
        else:
            return bool(self.type)

class Typedef(Node):
    def __init__(self, type = None):
        super(Typedef, self).__init__()

        self.type = type

class Array(Node):
    def __init__(self, type = None, size = None):
        super(Array, self).__init__()

        self.type = type
        self.size = size

    def __hash__(self):
        return hash((self.type, self.size))

    def __eq__(self, other):
        if not isinstance(other, Array):
            return False

        a = (self.type, self.size)
        b = (other.type, other.size)

        return a == b

    def __ne__(self, other):
        return not self.__eq__(other)

    def as_string(self, c_compat_names = True, c_compat_refs = True, c_compat_const = True,
                  nested = False):
        type = self.type.as_string(c_compat_names, c_compat_refs, c_compat_const, True)
        return type + "*"

class Builtin(Node):
    def __init__(self, name):
        super(Builtin, self).__init__()

        self.name = name

    def __hash__(self):
        return hash(self.name)

    def __eq__(self, other):
        if not isinstance(other, Builtin):
            return False

        return self.name == other.name

    def __ne__(self, other):
        return not self.__eq__(other)

    def as_string(self, c_compat_names = True, c_compat_refs = True, c_compat_const = True,
                  nested = False):
        if c_compat_names and self.name == "bool":
            return "unsigned char"

        return self.name

class FunctionPointer(FunctionSignature):
    def __init__(self):
        super(FunctionPointer, self).__init__()

class Namespace(Node):
    def __init__(self, context = None, name = ''):
        super(Namespace, self).__init__()

        self.context = context
        self.name = name
        self.children = {}
        self.nodes = []

    def get_child(self, name):
        if not name:
            return self

        ns = self
        for part in name.split("::"):
            if not part:
                continue

            child = ns.children.get(part)
            if not child:
                child = ns.children[part] = Namespace(ns, part)
            ns = child
        return ns

    def get_by_full_name(self, name):
        ns = self

        parts = name.split("::")
        for part in parts[0:-1]:
            ns = ns.children.get(part)
            if not ns:
                return

        name = parts[-1]
        for node in ns.nodes:
            if node.name == name:
                return node

class SourceLocation(Node):
    def __init__(self, file = None, line = None, column = None):
        super(SourceLocation, self).__init__()

        self.file = file
        self.line = line
        self.column = column
