from wrappyr.code_data_conversion.exports import ClangExport
from wrappyr.utils.str import SourceBlock

class HeaderExport(ClangExport):
    def export_constructors(self, cls, full_name_underscore):
        block = SourceBlock()

        if cls.constructors:
            for constructor in cls.constructors:
                if not self.filter.filter_method_signature(cls, constructor):
                    continue
                block.add_line("void* %s(%s);" % (
                        self.symbol_for_constructor(cls, full_name_underscore, constructor),
                        constructor.args_as_string()
                ))
        else:
            block.add_line("void* %s();" % (
                    self.symbol_for_constructor(cls, full_name_underscore),
            ))

        # Array
        if cls.is_default_constructable():
            block.add_line("void* %s(unsigned int);" % self.symbol_for_array_constructor(
                    cls, full_name_underscore
            ))

        return block

    def export_destructors(self, cls, full_name_underscore):
        block = SourceBlock()
        block.add_line("void %s(void*);" % self.symbol_for_destructor(
                cls, full_name_underscore, cls.destructor))
        block.add_line("void %s(void*);" % self.symbol_for_array_destructor(
                cls, full_name_underscore
        ))
        return block

    def export_methods(self, cls, full_name_underscore):
        block = SourceBlock()

        for method in cls.methods:
            for signature in method.signatures:
                if not self.filter.filter_method_signature(cls, signature):
                    continue

                returns = signature.returns.as_string()
                args = "void*%s%s" % (
                        ", " if signature.args else '',
                        signature.args_as_string() if signature.args else ''
                )
                symbol = self.symbol_for_method_signature(cls,
                                                                                                  full_name_underscore,
                                                                                                  method, signature)
                block.add_line("%s %s(%s);" % (
                        returns,
                        symbol,
                        args
                ))

        return block

    def export_members(self, cls, full_name_underscore):
        block = SourceBlock()

        for member in cls.members:
            if not self.filter.filter_member(cls, member):
                continue

            returns = member.type.as_string()
            getter, setter = self.symbols_for_member(cls, full_name_underscore,
                                                                                             member)

            block.add_line("%s %s(void*);" % (
                    returns,
                    getter
            ))
            block.add_line("void %s(void*, %s);" % (
                    setter,
                    member.type.as_string(),
            ))
        return block

    def export_inheritance_class(self, cls, full_name_underscore):
        block = SourceBlock()
        if cls.constructors:
            for constructor in cls.constructors:
                if not self.filter.filter_method_signature(cls, constructor, inherited = True):
                    continue

                args = constructor.args_as_string()
                if args:
                    args = ", " + args
                symbol = self.symbol_for_inheritance_constructor(cls, full_name_underscore,
                                                                                         constructor)
                block.add_line("void* %s(void*, void*%s);" % (symbol, args))
        else:
            block.add_line("void* %s(void*, void*);" % (
                    self.symbol_for_inheritance_constructor(cls, full_name_underscore, None),
            ))
        return block

    def export_class(self, cls):
        full_name_underscore = cls.get_full_name("__")
        block = SourceBlock()
        block.add_line("")
        block.add_line("//")
        block.add_line("// Begin class '%s'" % cls.get_full_name())
        block.add_line("//")

        # Constructor
        if not cls.is_abstract():
            block.add_block(self.export_constructors(cls, full_name_underscore))

        # Destructor
        if not cls.destructor or cls.destructor.access == 'public':
            block.add_block(self.export_destructors(cls, full_name_underscore))

        # Class size
        block.add_line("unsigned int %s();" % self.symbol_for_class_size(
                cls, full_name_underscore))

        # Get array element
        block.add_line("void* %s(void*, unsigned int);" % self.symbol_for_array_element(
                cls, full_name_underscore
        ))

        # Methods
        block.add_block(self.export_methods(cls, full_name_underscore))

        # Members
        block.add_block(self.export_members(cls, full_name_underscore))

        # C++ class to inherit from a virtual base
        if cls.is_dynamic():
            inheritance_class = self.export_inheritance_class(
                    cls,
                    full_name_underscore
            )
            block.add_block(inheritance_class)

        return block

    def export(self, importer, path):
        self.setup(importer)

        block = SourceBlock('extern "C" {')
        block.add_block(self.export_namespace(importer.root_namespace))
        block.add_line("}")

        with open(path, 'w') as f:
            f.write(block.as_text())
