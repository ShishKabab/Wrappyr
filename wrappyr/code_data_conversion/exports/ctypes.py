from wrappyr.code_data_conversion.exports import ClangExport
from wrappyr.code_data_conversion.structure import Class, Function, Builtin, Enumeration, Struct, AccessSpecifier
from wrappyr.utils.str import SourceBlock

class CtypesExport(ClangExport):
    builtin_dict = {
        'bool': 'ctypes.c_ubyte',
        'char': 'ctypes.c_char',
        'wchar_t': 'ctypes.c_wchar',
        'unsigned char': 'ctypes.c_ubyte',
        'short': 'ctypes.c_short',
        'short int': 'ctypes.c_short',
        'unsigned short': 'ctypes.c_ushort',
        'short unsigned int': 'ctypes.c_ushort',
        'int': 'ctypes.c_int',
        'unsigned int': 'ctypes.c_uint',
        'long': 'ctypes.c_long',
        'long int': 'ctypes.c_long',
        'unsigned long': 'ctypes.c_ulong',
        'long unsigned int': 'ctypes.c_ulong',
        'long long': 'ctypes.c_longlong',
        'long long int': 'ctypes.c_longlong',
        'unsigned long long': 'ctypes.c_ulonglong',
        'long long unsigned int': 'ctypes.c_longlong',
        'float': 'ctypes.c_float',
        'double': 'ctypes.c_double',
        'long double': 'ctypes.c_longdouble',
    }

    def package_for_namespace(self, ns):
        return ns.name or "exported"

    def libraries_for_namespace(self, ns):
        return ()

    def export_function(self, f):
        block = SourceBlock()
        if not f.extern_c:
            return block

        block.add_line('<function name="%s">' % f.name)
        block.add_line('</function>')
        return block

    def export_method(self, cls, method):
        block = SourceBlock()
        if not method:
            return block

        first_signature = method.signatures[0]
        if first_signature.constructor:
            name = "__alloc__"
        elif first_signature.destructor:
            name = "__dealloc__"
        else:
            name = method.name

        block.add_line('<method name="%s">' % name)
        for signature in method.signatures:
            if self.filter.filter_method_signature(cls, signature):
                block.add_block(self.export_call(signature, cls, method), 1)
        block.add_line('</method>')

        return block

    def export_constructors(self, cls):
        block = SourceBlock()

        block.add_line('<method name="__alloc__">')
        for constructor in cls.constructors:
            if self.filter.filter_method_signature(cls, constructor):
                block.add_block(self.export_call(constructor, cls), 1)
        block.add_line('</method>')

        return block

    def export_call(self, sig, cls = None, method = None):
        cls_name_underscore = cls.get_full_name("__")

        if sig.constructor:
            symbol = self.symbol_for_constructor(
                cls, cls_name_underscore, sig)
        elif sig.destructor:
            symbol = self.symbol_for_destructor(
                cls, cls_name_underscore, sig)
        else:
            symbol = self.symbol_for_method_signature(
                cls, cls_name_underscore, method, sig)

        returns_anything = sig.returns_anything()

        block = SourceBlock()
        if not returns_anything and not sig.args:
            block.add_line('<call symbol="%s" />' % symbol)
            return block

        block.add_line('<call symbol="%s">' % symbol)
        for arg, letter in zip(sig.args, self.iletters()):
            block.add_line('<argument name="%s" type="%s" />' % (
                arg.name or letter,
                self.type_as_ctype(arg.type))
            , 1)
        if returns_anything:
            block.add_line('<returns type="%s" ownership="%d" />' % (
                self.type_as_ctype(sig.returns),
                int(bool(method and sig.returns.is_cpp_only())))
            , 1)

        block.add_line('</call>')

        return block

    def node_as_ctype(self, stripped):
        path = [stripped.type.name]
        ns = stripped.type.get_namespace()
        while ns:
            part = self.package_for_namespace(ns)
            if part:
                path.insert(0, part)
            ns = ns.context
        return ".".join(path)

    def type_as_ctype(self, type):
        stripped = type.strip_pointers_and_references()
        if isinstance(stripped.type, Builtin) and not type.is_reference():
            builtin = stripped.type
            if type.get_total_pointers() == 1:
                if builtin.name == 'void':
                    return "ctypes.c_void_p"
                if builtin.name == 'char':
                    return "ctypes.c_char_p"
                if builtin.name == 'wchar':
                    return "ctypes.c_wchar_p"
            if not type.get_total_pointers() and builtin.name != 'void':
                return self.builtin_dict[builtin.name]
            return "ctypes.c_void_p"
        elif isinstance(type.type, Enumeration):
            return "ctypes.c_uint"
        elif ((type.get_total_pointers() + int(type.is_reference())) <= 1 and
                isinstance(stripped.type, (Struct, Enumeration))):
            return self.node_as_ctype(stripped)

        raise Exception("Don't know how to export type '%s'" % type.as_string(False, False, False))

    def export_destructors(self, cls):
        cls_name_underscore = cls.get_full_name("__")

        block = SourceBlock()

        symbol = self.symbol_for_destructor(cls, cls_name_underscore)
        block.add_line('<method name="__dealloc__">')
        block.add_line('<call symbol="%s" />' % symbol, 1)
        block.add_line('</method>')

        symbol = self.symbol_for_array_destructor(cls, cls_name_underscore)
        block.add_line('<method name="__delarray__">')
        block.add_line('<call symbol="%s" />' % symbol, 1)
        block.add_line('</method>')

        return block

    def export_member(self, cls, member):
        getter, setter = self.symbols_for_member(cls, cls.get_full_name("__"), member)
        type = self.type_as_ctype(member.type)

        block = SourceBlock()
        block.add_line('<member name="%s">' % member.name)

        block.add_line('<getter>', 1)
        block.add_line('<call symbol="%s">' % getter, 2)
        block.add_line('<returns type="%s" />' % type, 3)
        block.add_line('</call>', 2)
        block.add_line('</getter>', 1)

        block.add_line('<setter>', 1)
        block.add_line('<call symbol="%s">' % setter, 2)
        block.add_line('<argument name="v" type="%s" />' % type, 3)
        block.add_line('</call>', 2)
        block.add_line('</setter>', 1)

        block.add_line('</member>')
        return block

    def export_array_class_methods(self, cls):
        cls_name_underscore = cls.get_full_name("__")

        block = SourceBlock()

        if not cls.is_abstract() and cls.is_default_constructable():
            symbol = self.symbol_for_array_constructor(cls, cls_name_underscore)

            block.add_line('<method name="__newarray__">')
            block.add_line('<call symbol="%s">' % symbol, 1)
            block.add_line('<argument name="size" type="ctypes.c_uint" />', 2)
            block.add_line('<returns type="ctypes.c_void_p" />', 2)
            block.add_line('</call>', 1)
            block.add_line('</method>')
        if not cls.destructor or cls.destructor.access == 'public':
            symbol = self.symbol_for_array_destructor(cls, cls_name_underscore)

            block.add_line('<method name="__delarray__">')
            block.add_line('<call symbol="%s">' % symbol, 1)
            block.add_line('<argument name="a" type="ctypes.c_void_p" />', 2)
            block.add_line('</call>', 1)
            block.add_line('</method>')

        symbol = self.symbol_for_array_element(cls, cls_name_underscore)
        block.add_line('<method name="__arrayitem__">')
        block.add_line('<call symbol="%s">' % symbol, 1)
        block.add_line('<argument name="a" type="ctypes.c_void_p" />', 2)
        block.add_line('<argument name="idx" type="ctypes.c_uint" />', 2)
        block.add_line('<returns type="ctypes.c_void_p" />', 2)
        block.add_line('</call>', 1)
        block.add_line('</method>')

        return block

    def export_inherited_constructors(self, cls):
        cls_name_underscore = cls.get_full_name("__")
        block = SourceBlock()

        filter = lambda sig: self.filter.filter_method_signature(cls, sig, inherited = True)
        constructors = [i for i in cls.constructors if filter(i)]

        if constructors:
            block.add_line('<method name="__newinherited__">')
            for constructor in constructors:
                symbol = self.symbol_for_inheritance_constructor(
                    cls, cls_name_underscore, constructor)
                block.add_line('<call symbol="%s">' % symbol, 1)
                block.add_line('<argument name="obj" type="ctypes.py_object" />', 2)
                block.add_line('<argument name="vtable" type="ctypes.c_void_p" />', 2)
                for arg, letter in zip(constructor.args, self.iletters()):
                    arg_type = self.type_as_ctype(arg.type)
                    arg_name = arg.name or letter

                    block.add_line('<argument name="%s" type="%s" />' % (
                        arg_name,
                        arg_type)
                    , 2)
                block.add_line('<returns type="ctypes.c_void_p" />', 2)
                block.add_line('</call>', 1)
            block.add_line('</method>')
        elif not cls.constructors:
            symbol = self.symbol_for_inheritance_constructor(
                cls, cls_name_underscore, None)

            block.add_line('<method name="__newinherited__">')
            block.add_line('<call symbol="%s">' % symbol, 1)
            block.add_line('<argument name="obj" type="ctypes.py_object" />', 2)
            block.add_line('<argument name="vtable" type="ctypes.c_void_p" />', 2)
            block.add_line('<returns type="ctypes.c_void_p" />', 2)
            block.add_line('</call>', 1)
            block.add_line('</method>')

        return block

    def export_inherited(self, cls):
        block = SourceBlock()

        overridable = cls.get_overridable_signatures()
        if not overridable:
            return block

        constructors = self.export_inherited_constructors(cls)
        if not constructors:
            return block

        block.add_line("<vtable>")
        for method in overridable:
            for sig in method:
                if not self.filter.filter_method_signature(cls, sig, True):
                    continue

                block.add_line('<overridable name="%s">' % sig.context.name, 1)
                for arg, letter in zip(sig.args, self.iletters()):
                    arg_name = arg.name or letter
                    arg_type = self.type_as_ctype(arg.type)
                    block.add_line('<argument name="%s" type="%s" />' % (
                        arg_name,
                        arg_type
                    ), 2)

                if sig.returns_anything():
                    returns = self.type_as_ctype(sig.returns)
                    block.add_line('<returns type="%s" />' % returns, 2)

                block.add_line('</overridable>', 1)
        block.add_line("</vtable>")

        block.add_block(constructors)

        return block

    def export_class(self, cls):
        block = SourceBlock()
        block.add_line('<class name="%s">' % cls.name)

        if cls.is_dynamic():
            block.add_block(self.export_inherited(cls), 1)
        if (not cls.is_abstract() and cls.constructors
            and self.filter.filter_method(cls, cls.constructors)):
            block.add_block(self.export_constructors(cls), 1)
        if not cls.destructor or cls.destructor.access == AccessSpecifier.Public:
            block.add_block(self.export_destructors(cls), 1)
        block.add_block(self.export_array_class_methods(cls), 1)

        for method in cls.methods:
            if self.filter.filter_method(cls, method):
                block.add_block(self.export_method(cls, method), 1)
        for member in cls.members:
            if self.filter.filter_member(cls, member):
                block.add_block(self.export_member(cls, member), 1)

        block.add_line('</class>')
        return block

    def export_namespace(self, ns):
        package_name = self.package_for_namespace(ns)

        block = SourceBlock()
        if package_name:
            block.add_line('<package name="%s">' % package_name)
            for name, path, default in self.libraries_for_namespace(ns):
                default = repr(default).lower()
                library = '<library name="%s" path="%s" default="%s" />'
                block.add_line(library % (name, path, default), 1)

            for node in ns.nodes:
                if isinstance(node, Class):
                    if self.filter.filter_class(node):
                        block.add_block(self.export_class(node), 1)
#                if isinstance(node, Function):
#                    if self.filter.filter_function(node):
#                        block.add_block(self.export_function(node), 1)

        child_indent = int(bool(package_name))
        for child in ns.children.values():
            if self.filter.filter_namespace(child):
                block.add_block(self.export_namespace(child), child_indent)

        if package_name:
            block.add_line('</package>')

        return block

    def export(self, importer, path):
        self.setup(importer)

        block = SourceBlock("<ctypes>")
        block.add_block(self.export_namespace(importer.root_namespace), 1)
        block.add_line("</ctypes>")

        with open(path, 'w') as f:
            f.write(block.as_text())
