import os
import wrappyr
from wrappyr.code_data_conversion.exports import ExportFilter, HeaderExport, SourceExport, CtypesExport
from wrappyr.ctypes_api_builder.structure import CTypesStructureVisitor, CTypesStructure, Package
from wrappyr.ctypes_api_builder.visitors import UninterestingCopyConstructorRemover, ConflictingOverloadRemover, AmbiguousOverloadRemover, PythonKeywordRemover

class Box2DFilter(ExportFilter):
    def filter_namespace(self, ns, **opts):
        return not ns.name

    def filter_class(self, cls, **opts):
        if not ExportFilter.filter_class(self, cls):
            return False
        return cls.name.startswith("b2")

class Box2DHeaderExport(HeaderExport):
    filter_class = Box2DFilter

class Box2DSourceExport(SourceExport):
    filter_class = Box2DFilter

    def get_includes(self):
        return '#include <Box2D/Box2D.h>\n#include "box2d.h"'

class Box2DCtypesExport(CtypesExport):
    filter_class = Box2DFilter

    def package_for_namespace(self, ns):
        return ns.name or "Box2D"

    def libraries_for_namespace(self, ns):
        if not ns.name:
            return [('Box2D', './libBox2DC.so', True)]
        return ()

class Box2DBodyCreateFixtureFixer(CTypesStructureVisitor):
    def visit_Method(self, method):
        if method.parent != self.b2Body or method.name != "CreateFixture":
            return

        to_remove = None
        for call in method.calls:
            if len(call.args) > 1:
                to_remove = call
        if to_remove:
            method.remove_call(to_remove)

    def process(self, node):
        if isinstance(node, CTypesStructure):
            self.b2Body = node.get_by_path('Box2D.b2Body')

        CTypesStructureVisitor.process(self, node)

class Box2DPackage(wrappyr.Package):
    source_header_name = "Box2D/Box2D.h"
    generated_wrapper_prefix = "/tmp/box2d"

    def __init__(self):
        self.class_namespaces = None

    def get_header_export(self):
        return Box2DHeaderExport()

    def get_source_export(self):
        return Box2DSourceExport()

    def get_ctypes_export(self):
        return Box2DCtypesExport()

    def get_source_language(self):
        return "c++"

    def process_code_import(self, importer):
        self.class_namespaces = {}

        source_header = self.get_source_header_path()
        base_path = os.path.dirname(source_header) + "/"
        for cls in importer.classes:
            file = cls.location.file
            if not file.startswith(base_path):
                continue
            file = file[len(base_path):]

            ns = file[:-2].lower()
            ns = ns.split(os.sep)
            ns = ".".join(ns[0:-1])
            ns = "Box2D." + ns
            self.class_namespaces[cls.name] = ns

    def process_ctypes_structure(self, structure):
        UninterestingCopyConstructorRemover().process(structure)
        Box2DBodyCreateFixtureFixer().process(structure)
        ConflictingOverloadRemover().process(structure)
        AmbiguousOverloadRemover().process(structure)
        PythonKeywordRemover().process(structure)

        if not self.class_namespaces:
            return

        packages = {}
        for name, namespace in self.class_namespaces.iteritems():
            if "." not in namespace:
                continue

            cls = structure.get_by_path('Box2D.' + name)
            if not cls:
                continue

            package = packages.get(namespace)
            if not package:
                package = namespace[namespace.rfind(".") + 1 :]
                package = packages[namespace] = Package(package)
            cls.parent.remove_class(cls)
            package.add_class(cls)

        for name, package in sorted(packages.iteritems(), key = lambda i: i[0].count(".")):
            parent = structure.get_by_path(name[: name.rfind(".")])
            parent.add_package(package)
