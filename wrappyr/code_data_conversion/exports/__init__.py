from __future__ import absolute_import
from wrappyr.code_data_conversion.structure import Class, AccessSpecifier, Pointer, Builtin, Array, Method
from wrappyr.utils.str import as_camelcase, SourceBlock

class ExportFilter(object):
    def __init__(self, importer):
        self.importer = importer

    def filter_namespace(self, ns, **opts):
        return True

    def filter_class(self, cls, **opts):
        valid = cls.is_valid()
        valid = valid and cls.access in (
            AccessSpecifier.Unknown,
            AccessSpecifier.Public
        )
        return valid

    def filter_method(self, cls, method, **opts):
        signatures = method.signatures if isinstance(method, Method) else method
        return any(self.filter_method_signature(cls, sig, **opts)
            for sig in signatures)

    def filter_method_signature(self, cls, signature, inherited = False, **opts):
        return (self.filter_function_signature(signature)
            # Export only public methods
            and (signature.access == AccessSpecifier.Public or
                 # And protected methods if we're generating a class for inheritance
                 (inherited and signature.access == AccessSpecifier.Protected))
            # Static methods are not supported yet
            and not signature.static)

    def filter_member(self, cls, member, **opts):
        type = member.type
        stripped = type.strip_pointers_and_references()

        return (# Export only public members
            member.access == AccessSpecifier.Public
            # TODO: Some member names are empty in Clang XML, find out why
            and member.name
            # The type must be valid, e.g. exist in memory
            and type.is_valid()
            # We don't know how to handle multi-dimensional pointers
            and type.get_total_pointers() <= 1
            # We don't know how to handle members pointing to builtins
            and not (isinstance(type.type, Pointer) and isinstance(stripped, Builtin))
            # TODO: We do know how to handle an array member, implement in Ctypes export
            and not isinstance(type.type, Array)
        )

    def filter_function(self, f, **opts):
        return all(self.filter_function_signature(sig) for sig in f.signatures)

    def filter_function_signature(self, sig):
        return sig.is_valid()

class ClangExport(object):
    filter_class = ExportFilter

    def __init__(self, filter_class = None):
        if filter_class:
            self.filter_class = filter_class

    @staticmethod
    def iletters():
        return (chr(i) for i in xrange(ord('a'), ord('m')))

    def get_filter(self, importer):
        return self.filter_class(importer)

    def symbol_for_constructor(self, cls, cls_name_underscore, constructor = None):
        return "%s__Create%s" % (
            cls_name_underscore,
            (cls.constructors.index(constructor) if len(cls.constructors) > 1 else '')
        )

    def symbol_for_array_constructor(self, cls, cls_name_underscore):
        return "%s__CreateArray" % (
            cls_name_underscore
        )

    def symbol_for_destructor(self, cls, cls_name_underscore, destructor):
        return "%s__Destroy" % cls_name_underscore

    def symbol_for_array_destructor(self, cls, cls_name_underscore):
        return "%s__DestroyArray" % cls_name_underscore

    def symbol_for_class_size(self, cls, cls_name_underscore):
        return "%s__Size" % cls_name_underscore

    def symbol_for_method_signature(self, cls, cls_name_underscore, method, signature):
        signatures = method.signatures
        return "%s_%s%s" % (
            cls_name_underscore,
            method.name,
            (signatures.index(signature) if len(signatures) > 1 else '')
        )

    def symbols_for_member(self, cls, cls_name_underscore, member):
        camelcased = as_camelcase(member.name)
        return (
            "%s__Get_%s" % (cls_name_underscore, camelcased),
            "%s__Set_%s" % (cls_name_underscore, camelcased)
        )

    def symbol_for_array_element(self, cls, full_name_underscore):
        return "%s__ArrayElement" % full_name_underscore

    def symbol_for_inheritance_constructor(self, cls, cls_name_underscore,
                                           constructor):
        return "%s__CreateInherited%s" % (
            cls_name_underscore,
            (cls.constructors.index(constructor) if constructor and len(cls.constructors) > 1 else '')
        )

    def setup(self, importer):
        self.importer = importer
        self.filter = self.get_filter(importer)

    def export_namespace(self, ns):
        block = SourceBlock()
        if not self.filter.filter_namespace(ns):
            return block

        for node in ns.nodes:
            if isinstance(node, Class):
                if self.filter.filter_class(node):
                    block.add_block(self.export_class(node))
        for child in ns.children.values():
            block.add_block(self.export_namespace(child))

        return block

    def export_class(self, cls):
        raise NotImplemented

from wrappyr.code_data_conversion.exports.header import HeaderExport
from wrappyr.code_data_conversion.exports.source import SourceExport
from wrappyr.code_data_conversion.exports.ctypes import CtypesExport