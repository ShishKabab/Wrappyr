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
    """Base class for all Wrappyr packages.

    Overriding the methods of this class is the preferred way to hook into
    the wrappyr/generate.py script. To use your Package subclass, pass the
    dotted path to it to the ``--package`` option of the wrappyr/generate.py
    script.
    """

    #: Property used by the default implementation of get_source_header_path to
    #: find the header file used as a starting point for generating everything
    #: necessary for the Python API. You can set this to something
    #: like ``Box2D/Box2D.h``.
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
        """Returns class used to generate the header of the C API.

        You will almost always want to return a subclass of
        :class:`wrappyr.code_data_conversion.HeaderExport`.
        The main reason to do this is to use a custom export filter
        controlling which classes and functions get exported to the Python API.
        """

        return HeaderExport(filter_class = self.filter_class)

    def get_source_export(self):
        """Returns class used to generate the source of the C API.

        You will almost always want to return a subclass of
        :class:`wrappyr.code_data_conversion.SourceExport`.
        The main reasons to do this are to use a custom export filter
        controlling which classes and functions get exported to the
        Python API and to add custom includes to the source of the C API.
        """

        return SourceExport(filter_class = self.filter_class)

    def get_ctypes_export(self):
        """Returns class used to generate the XML describing the Python API.

        You will almost always want to return a subclass of
        :class:`wrappyr.code_data_conversion.CtypesExport`.
        Such a subclass can have a custom filter used to control which classes
        and functions get exported to the Python API. You can also use this
        to provide a basic namespace to package mapping.
        """

        return CtypesExport(filter_class = self.filter_class)

    def get_source_language(self):
        """Returns which language your C/C++ is using as a string.

        Returns either lowercase ``c`` or ``c+``.
        """

        return "c++"

    def get_preferred_code_data_backend(self):
        """Returns which backend to use when exporting.

        Valid return values are ``gccxml`` and ``clang``.
        """

        return "gccxml"

    def get_source_header_path(self):
        """Returns the path of the header used to generate the Python API.

        The default implementation searches /usr/local/include and /usr/include
        for the header file in the :attr:`source_header_name` attribute.
        """

        if self.source_header_name:
            return self.find_header(self.source_header_name)

    def get_generated_header_path(self):
        """Returns the path where to write the header of the generated C API.

        By default this generates a random temporary file ending in .h and
        stores it name in :attr:`generated_wrapper_prefix` so
        :attr:`get_generated_source_path` can use the same name
        ending in .cpp .
        """

        if not self.generated_wrapper_prefix:
            self.generated_wrapper_prefix = mkstemp()[1]

        return self.generated_wrapper_prefix + ".h"

    def get_generated_source_path(self):
        """Returns the path where to write the source of the generated C API.

        By default this generates a random temporary file ending in .cpp and
        stores it name in :attr:`generated_wrapper_prefix` so
        :attr:`get_generated_header_path` can use the same name
        ending in .h .
        """

        if not self.generated_wrapper_prefix:
            self.generated_wrapper_prefix = mkstemp()[1]

        return self.generated_wrapper_prefix + ".cpp"

    def process_code_import(self, importer):
        """Preprocess the imported code data.

        You can use this to store information about the C/C++ code. See the
        Box2D package in packages/Box2D.py which uses this to store the location
        of classes, which it uses in :attr:`process_ctypes_structure` to
        organize the final Python API into packages.
        """

        pass

    def process_ctypes_structure(self, structure):
        """Preprocess the final Python API imported from XML.

        This method is passed an argument named *structure*,
        which is an instance of the class
        :class:`wrappyr.ctypes_api_builder.structure.CTypesStructure`.

        Use this to do both changes that are cosmetic and changes that are
        necessary for the Python API to work. Cosmetic changes include
        converting method names to PEP8 convention and organizing classes
        into packages. Necessary changes include renaming arguments that are
        reserved Python keywords and removing ambiguous overloads.

        See :doc:`ctypes_api_generation` for the docs you'll need and some examples.
        Also, see the Box2D package in packages/Box2D.py for a real life example.
        """

        pass

    def find_header(self, name):
        for prefix in ('/usr/include', '/usr/local/include'):
            path = os.path.join(prefix, name)
            if os.access(path, F_OK):
                return path
        raise HeaderNotFound(name)
