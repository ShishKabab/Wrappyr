========================
Creating Package classes
========================

Create a Package class is the preferred way to customize to generation of a Python API. In a Package class you can:

* Tell Wrappyr some basic stuff about your project, like whether you're using C or C++, which header file read, etc.

* Tell Wrappyr to use your custom classes when generating the C API and the initial XML file describing the Python API.

* Preprocess the data exported from GCCXML or Clang.

* Preprocess the final Python API just before the code is generated.

To create a Package, subclass from :class:`wrappyr.Package`. Below, I will describe each method you can override and how you can use it.

.. class:: wrappyr.Package

    Base class for all Wrappyr packages.

    Overriding the methods of this class is the preferred way to hook into
    the wrappyr/generate.py script. To use your Package subclass, pass the
    dotted path to it to the ``--package`` option of the wrappyr/generate.py
    script.

    .. method:: get_header_export()

        Returns class used to generate the header of the C API.

        You will almost always want to return a subclass of
        :class:`wrappyr.code_data_conversion.HeaderExport`.
        The main reason to do this is to use a custom export filter
        controlling which classes and functions get exported to the Python API.

    .. method:: get_source_export()

        Returns class used to generate the source of the C API.

        You will almost always want to return a subclass of
        :class:`wrappyr.code_data_conversion.SourceExport`.
        The main reasons to do this are to use a custom export filter
        controlling which classes and functions get exported to the
        Python API and to add custom includes to the source of the C API.

    .. method:: get_ctypes_export()

        Returns class used to generate the XML describing the Python API.

        You will almost always want to return a subclass of
        :class:`wrappyr.code_data_conversion.CtypesExport`.
        Such a subclass can have a custom filter used to control which classes
        and functions get exported to the Python API. You can also use this
        to provide a basic namespace to package mapping.

    .. method:: get_source_language()

        Returns which language your C/C++ is using as a string.

        Return either lowercase ``c`` or ``c+``.

    .. method:: get_source_header_path()

        Returns the path of the header used to generate the Python API.

        The default implementation searches /usr/local/include and /usr/include
        for the header file in the :attr:`source_header_name` attribute.

    .. method:: get_generated_header_path()

        Returns the path where to write the header of the generated C API.

        By default this generates a random temporary file ending in .h and
        stores it name in :attr:`generated_wrapper_prefix` so
        :attr:`get_generated_source_path` can use the same name
        ending in .cpp .

    .. method:: get_generated_source_path()

        Returns the path where to write the source of the generated C API.

        By default this generates a random temporary file ending in .cpp and
        stores it name in :attr:`generated_wrapper_prefix` so
        :attr:`get_generated_header_path` can use the same name
        ending in .h .

    .. method:: process_code_import(importer)

        Preprocess the imported code data.

        You can use this to store information about the C/C++ code. See the
        Box2D package in packages/Box2D.py which uses this to store the location
        of classes, which it uses in :attr:`process_ctypes_structure` to
        organize the final Python API into packages.

    .. method:: process_ctypes_structure(structure)

        Preprocess the final Python API imported from XML.

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

    .. attribute:: source_header_name

        Property used by the default implementation of get_source_header_path to
        find the header file used as a starting point for generating everything
        necessary for the Python API. You can set this to something
        like ``Box2D/Box2D.h``.
