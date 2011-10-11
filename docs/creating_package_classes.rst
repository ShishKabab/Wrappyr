========================
Creating Package classes
========================

Create a Package class is the preferred way to customize to generation of a Python API. In a Package class you can:

* Tell Wrappyr some basic stuff about your project, like whether you're using C or C++, which header file read, etc.

* Tell Wrappyr to use your custom classes when generating the C API and the initial XML file describing the Python API.

* Preprocess the data exported from GCCXML or Clang.

* Preprocess the final Python API just before the code is generated.

To create a Package, subclass from :class:`wrappyr.Package`. Below, I will describe each method you can override and how you can use it.

.. autoclass:: wrappyr.Package

    Test from Sphinx.

    .. automethod:: wrappyr.Package.get_header_export

        Some extra text

    .. automethod:: wrappyr.Package.get_source_export

    .. automethod:: wrappyr.Package.get_ctypes_export

    .. automethod:: wrappyr.Package.get_source_language

    .. automethod:: wrappyr.Package.get_source_header_path

    .. automethod:: wrappyr.Package.get_generated_header_path

    .. automethod:: wrappyr.Package.get_generated_source_path

    .. automethod:: wrappyr.Package.process_code_import

    .. automethod:: wrappyr.Package.process_ctypes_structure

    .. autoattribute:: wrappyr.Package.source_header_name
