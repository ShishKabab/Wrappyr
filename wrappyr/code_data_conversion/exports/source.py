from itertools import count
from wrappyr.code_data_conversion.exports import ClangExport
from wrappyr.utils.str import SourceBlock

class SourceExport(ClangExport):
    letters = tuple(ClangExport.iletters())

    def get_includes(self):
        pass

    def args_as_params(self, f, from_c = True):
        args = []
        for arg, letter in zip(f.args, self.letters):
            arg_type = arg.type
            if from_c:
                cast = "(%s)" % arg_type.as_string(c_compat_names = False)
                derefs = int(arg_type.is_reference())
                derefs += int(arg_type.is_cpp_only())
            else:
                cast = ""
                derefs = 0
            derefs *= "*"

            args.append("%s(%s%s)" % (derefs, cast, letter))

        return ", ".join(args)

    def export_constructors(self, cls, full_name, full_name_underscore):
        block = SourceBlock()
        if cls.constructors:
            for constructor in cls.constructors:
                if not self.filter.filter_method_signature(cls, constructor):
                    continue
                block.add_line("void* %s(%s){" % (
                self.symbol_for_constructor(cls, full_name_underscore, constructor),
                constructor.args_as_string(self.letters)
                ))
                block.add_line("return new %s(%s);" % (
                full_name,
                self.args_as_params(constructor))
                               , 1)
                block.add_line("}")
        else:
            block.add_line("void* %s(){" % (
            self.symbol_for_constructor(cls, full_name_underscore),
            ))
            block.add_line("return new %s;" % full_name, 1)
            block.add_line("}")

        # Array
        if cls.is_default_constructable():
            block.add_line("void* %s(unsigned int n){" % self.symbol_for_array_constructor(
                cls, full_name_underscore
            ))
            block.add_line("return new %s[n];" % full_name, 1)
            block.add_line("}")

        return block

    def export_destructors(self, cls, full_name, full_name_underscore):
        block = SourceBlock()

        block.add_line("void %s(void* cls){" % self.symbol_for_destructor(
            cls, full_name_underscore, cls.destructor))
        block.add_line("delete (%s*)cls;" % full_name, 1)
        block.add_line("}")
        block.add_line("void %s(void* arr){" % self.symbol_for_array_destructor(
            cls, full_name_underscore
        ))
        block.add_line("delete[] (%s*)arr;" % full_name, 1)
        block.add_line("}")

        return block

    def export_methods(self, cls, full_name, full_name_underscore):
        block = SourceBlock()

        for method in cls.methods:
            for i, signature in enumerate(method.signatures):
                if not self.filter.filter_method_signature(cls, signature):
                    continue

                returns = signature.returns.as_string()
                args = "void* cls%s%s" % (
                    ", " if signature.args else '',
                    signature.args_as_string(self.letters) if signature.args else ''
                )
                block.add_line("%s %s(%s){" % (
                    returns,
                    self.symbol_for_method_signature(cls, full_name_underscore, method, signature),
                    args
                ))

                returns = signature.returns
                returns_stripped = returns.strip_pointers_and_references()
                stmt = "((%s*)cls)->%s(%s)"
                stmt = stmt % (full_name, method.name,
                               self.args_as_params(signature))
                if returns.is_reference():
                    stmt = "&" + stmt
                if returns_stripped.const and not returns.is_cpp_only():
                    pointers = returns.get_total_pointers()
                    pointers += int(returns.is_reference())
                    args = (returns.get_type_name(), "*" * pointers, stmt)
                    stmt = "const_cast<%s%s>(%s)" % args
                if returns.is_cpp_only():
                    stmt = "new %s(%s)" % (returns.get_type_name(), stmt)
                if signature.returns_anything():
                    stmt = "return " + stmt
                stmt += ";"

                block.add_line(stmt, 1)
                block.add_line("}")

        return block

    def export_members(self, cls, full_name, full_name_underscore):
        block = SourceBlock()

        for member in cls.members:
            if not self.filter.filter_member(cls, member):
                continue

            getter, setter = self.symbols_for_member(cls, full_name_underscore, member)
            type = member.type
            stripped = type.strip_pointers_and_references()

            # Getter
            returns = type.as_string()
            block.add_line("%s %s(void* cls){" % (
                returns,
                getter
            ))

            stmt = "((%s*)cls)->%s" % (cls.name, member.name)
            if type.is_cpp_only():
                stmt = "&" + stmt
            if stripped.const:
                pointers = type.get_total_pointers()
                pointers += int(type.is_reference())
                pointers += int(type.is_cpp_only())
                args = (type.get_type_name(), "*" * pointers, stmt)
                stmt = "const_cast<%s%s>(%s)" % args
            stmt = "return %s;" % stmt

            block.add_line(stmt, 1)
            block.add_line("}")

            # Setter
            block.add_line("void %s(void* cls, %s v){" % (
                setter,
                member.type.as_string(),
            ))

            pointers = int(type.is_reference())
            pointers += type.get_total_pointers()
            pointers += int(type.is_cpp_only())
            pointers = "*" * pointers

            stmt = "((%s%s)v);" % (type.get_type_name(), pointers)
            if type.is_cpp_only():
                stmt = "*" + stmt
            stmt = "((%s*)cls)->%s = "  % (full_name, member.name) + stmt
            block.add_line(stmt, 1)
            block.add_line("}")

        return block

    def get_callback_cast(self, f):
        returns = f.returns
        pointers = returns.get_total_pointers() + int(returns.is_reference())
        pointers += int(returns.is_cpp_only())
        pointers = "*" * pointers
        returns = returns.get_type_name() + pointers

        args = ["void*"]
        for arg in f.args:
            arg_type = arg.type
            stripped = arg_type.strip_pointers_and_references()
            const = "const " if stripped.const else ""
            pointers = arg_type.get_total_pointers() + int(arg_type.is_reference())
            pointers += int(arg_type.is_cpp_only())
            pointers = "*" * pointers
            args.append(const + arg_type.get_type_name() + pointers)

        return "(%s (*)(%s))" % (returns, ", ".join(args))

    def export_class_vtable(self, full_name_underscore, overridable):
        block = SourceBlock()

        counter = count()
        block.add_line("struct %s__VTable {" % full_name_underscore)
        for method in overridable:
            for signature, num in zip(method, counter):
                args = (num, signature.context.name)
                block.add_line("void* f%d; // %s" % args, 1)
        block.add_line("};")

        return block

    def export_inherited_constructors(self, cls, full_name, full_name_underscore):
        block = SourceBlock()
        if cls.constructors:
            for constructor in cls.constructors:
                if not self.filter.filter_method_signature(cls, constructor, inherited = True):
                    continue

                args = constructor.args_as_string(self.letters, False, False)
                if args:
                    args = ", " + args
                block.add_line("%s__Inherited(void* script_obj, void* vtable%s)" % (
                    full_name_underscore,
                    args
                ))
                if args:
                    args = self.args_as_params(constructor, False)
                    block.add_line(": %s(%s)" % (full_name, args), 1)
                block.add_line("{")
                block.add_line("m_script_obj = script_obj;", 1)
                block.add_line("m_vtable = vtable;", 1)
                block.add_line("}")
        else:
            block.add_line("%s__Inherited(void* script_obj, void* vtable){" % full_name)
            block.add_line("m_script_obj = script_obj;", 1)
            block.add_line("m_vtable = vtable;", 1)
            block.add_line("}")
        return block

    def export_inherited_methods(self, cls, full_name, full_name_underscore,
                                 overridable):
        block = SourceBlock()

        vtable_name = "%s__VTable" % full_name_underscore
        counter = count()
        for method in overridable:
            for signature, num in zip(method, counter):
                returns = signature.returns.as_string(False, False, False)
                args = signature.args_as_string(self.letters, False, False, False)
                const = " const " if signature.const else ""
                sig_str = "%s %s(%s)%s" % (returns, signature.context.name, args, const)

                returns = "return " if signature.returns_anything() else ""
                args_to_parent = ", ".join(self.letters[0:len(signature.args)])
                fptr_cast = self.get_callback_cast(signature)
                deref = "*" if signature.returns.is_reference() or signature.returns.is_cpp_only() else ""
                nearest_implementation = cls.get_class_implementing_signature(signature)

                args_to_callback = ["m_script_obj"]
                for arg, letter in zip(signature.args, self.letters):
                    arg_type = arg.type
                    pointer = int(bool(arg_type.is_reference() or arg_type.is_cpp_only()))
                    pointer = "&" * pointer
                    args_to_callback.append(pointer + letter)
                args_to_callback = ", ".join(args_to_callback)

                block.add_line("%s{" % sig_str)
                block.add_line("void* fptr = ((%s*)m_vtable)->f%d;" % (vtable_name, num), 1)
                block.add_line("if(fptr)", 1)
                block.add_line("%s%s(%sfptr)(%s);" % (returns, deref, fptr_cast, args_to_callback), 2)
                if nearest_implementation:
                    block.add_line("else", 1)
                    block.add_line("%s%s::%s(%s);" % (returns, nearest_implementation.name, signature.context.name, args_to_parent), 2)
                block.add_line("}")
        return block

    class PureMethodNotOverridden(Exception): pass
    def export_inherited_class(self, cls, full_name, full_name_underscore):
        block = SourceBlock()

        overridable = cls.get_overridable_signatures()
        if not overridable:
            return block

        filtered_out = [i for method in overridable
                          for i in method
                          if not self.filter.filter_method_signature(cls, i, True)]
        if any(sig.pure for sig in filtered_out):
            msg = ("A pure virtual signature for class %s "
                   "was not overridden because it was filtered out.")
            raise self.PureMethodNotOverridden(msg % full_name)

        overridable = [[i for i in method if i not in filtered_out]
                        for method in overridable]
        overridable = [method for method in overridable if method]

        vtable = self.export_class_vtable(full_name_underscore, overridable)
        block.add_block(vtable)

        block.add_line("class %s__Inherited : public %s {" % (full_name_underscore, full_name))
        block.add_line("public:", 1)
        block.add_block(self.export_inherited_constructors(cls, full_name, full_name_underscore), 2)
        block.add_block(self.export_inherited_methods(cls, full_name, full_name_underscore, overridable), 2)
        block.add_line("private:", 1)
        #               block.add_line("%s* m_obj;" % full_name, 2)
        block.add_line("void* m_script_obj;", 2)
        block.add_line("void* m_vtable;", 2)
        block.add_line("};")

        if cls.constructors:
            for constructor in cls.constructors:
                if not self.filter.filter_method_signature(cls, constructor, inherited = True):
                    continue

                args = constructor.args_as_string(self.letters)
                if args:
                    args = ", " + args

                params = self.args_as_params(constructor)
                if params:
                    params = "script_obj, vtable, " + params
                else:
                    params = "script_obj, vtable"

                symbol = self.symbol_for_inheritance_constructor(cls, full_name_underscore,
                                                                 constructor)
                block.add_line("void* %s(void* script_obj, void* vtable%s){" % (symbol, args))
                block.add_line("return new %s__Inherited(%s);" % (full_name_underscore, params), 1)
                block.add_line("}")
        else:
            block.add_line("void* %s(void* script_obj, void* vtable){" % (
            self.symbol_for_inheritance_constructor(cls, full_name_underscore, None),
            ))
            block.add_line("return new %s__Inherited(script_obj, vtable);" % full_name_underscore, 1)
            block.add_line("}")

        return block

    def export_class(self, cls):
        full_name = cls.get_full_name()
        full_name_underscore = cls.get_full_name("__")

        block = SourceBlock()
        block.add_line("")
        block.add_line("//")
        block.add_line("// Begin class '%s'" % cls.get_full_name())
        block.add_line("//")

        # Constructor
        if not cls.is_abstract():
            constructors = self.export_constructors(cls, full_name,
                                                    full_name_underscore)
            block.add_block(constructors)

        # Destructor
        if not cls.destructor or cls.destructor.access == 'public':
            destructors = self.export_destructors(cls, full_name, full_name_underscore)
            block.add_block(destructors)

        # Class size
        block.add_line("unsigned int %s(){" % self.symbol_for_class_size(
            cls, full_name_underscore))
        block.add_line("return sizeof(%s);" % full_name, 1)
        block.add_line("}")

        # Get array element
        block.add_line("void* %s(void* arr, unsigned int idx){" % self.symbol_for_array_element(
            cls, full_name_underscore
        ))
        block.add_line("return &((%s*)arr)[idx];" % full_name, 1)
        block.add_line("}")

        # Methods
        block.add_block(self.export_methods(cls, full_name,
                                            full_name_underscore))

        # Members
        block.add_block(self.export_members(cls, full_name,
                                            full_name_underscore))

        # C++ class to inherit from a virtual base
        if cls.is_dynamic():
            inheritance_class = self.export_inherited_class(
                cls,
                full_name,
                full_name_underscore
            )
            block.add_block(inheritance_class)

        return block

    def export(self, importer, path):
        self.setup(importer)

        block = SourceBlock()
        includes = self.get_includes()
        if includes:
            block.add_line('%s\n\n' % includes)
        block.add_block(self.export_namespace(importer.root_namespace))

        with open(path, 'w') as f:
            f.write(block.as_text())
