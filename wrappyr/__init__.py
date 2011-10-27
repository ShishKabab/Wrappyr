import os
from os import F_OK
from tempfile import mkstemp
from wrappyr.code_data_conversion.exports import HeaderExport, SourceExport, CtypesExport

VERSION = (0, 1, 0, 'alpha', 1)

def get_version():
    version = '%s.%s' % (VERSION[0], VERSION[1])
    if VERSION[2]:
        version = '%s.%s' % (version, VERSION[2])
    if VERSION[3:] == ('alpha', 0):
        version = '%s pre-alpha' % version
    else:
        if VERSION[3] != 'final':
            version = "%s %s" % (version, VERSION[3])
            if VERSION[4] != 0:
                version = '%s %s' % (version, VERSION[4])
    return version

class HeaderNotFound(Exception): pass
class Package(object):
    source_header_name = None

    #: Property used by default implementation of `get_generated_header_path`
    #: and `get_generated_source_path` to create file paths for the generated
    #: C API files. If you set this to something like ``/tmp/test``, the files
    #: /tmp/test.h and /tmp/test.cpp will be created for the C API.
    generated_wrapper_prefix = None

    #: The filter class that will be passed to export classes by the default
    #: implementation of `get_header_export`, `get_source_export` and
    #: `get_ctypes_export`.
    filter_class = None

    def get_header_export(self):
        return HeaderExport(filter_class = self.filter_class)

    def get_source_export(self):
        return SourceExport(filter_class = self.filter_class)

    def get_ctypes_export(self):
        return CtypesExport(filter_class = self.filter_class)

    def get_source_language(self):
        return "c++"

    def get_preferred_code_data_backend(self):
        return "gccxml"

    def get_source_header_path(self):
        if self.source_header_name:
            return self.find_header(self.source_header_name)

    def get_generated_header_path(self):
        if not self.generated_wrapper_prefix:
            self.generated_wrapper_prefix = mkstemp()[1]

        return self.generated_wrapper_prefix + ".h"

    def get_generated_source_path(self):
        if not self.generated_wrapper_prefix:
            self.generated_wrapper_prefix = mkstemp()[1]

        return self.generated_wrapper_prefix + ".cpp"

    def process_code_import(self, importer):
        pass

    def process_ctypes_structure(self, structure):
        pass

    def find_header(self, name):
        for prefix in ('/usr/include', '/usr/local/include'):
            path = os.path.join(prefix, name)
            if os.access(path, F_OK):
                return path
        raise HeaderNotFound(name)
