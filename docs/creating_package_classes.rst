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
   :members: get_header_export, get_source_export, get_ctypes_export,
             get_source_language, get_source_header_path, get_generated_header_path,
             get_generated_source_path, process_code_import, process_ctypes_structure,
             source_header_name
