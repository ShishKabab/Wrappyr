=======
Wrappyr
=======

:author: Vincent den Boer

Wrappyr is a collection of tools making it easier to create a Ctypes-based API to C/C++ code. It is composed of three parts:

* A Clang_ plugin that dumps classes, functions, etc. from a header file to XML.
* A tool that imports the XML file produced by the Clang plugin and does two things:

  - Generate a C API for your C++ code.

  - Generate an XML file describing how the Python API should look, which C calls should be made where, etc.

* A tool that creates the Ctypes-based Python API from an XML file.

.. _Clang: http://clang.llvm.org/

Status
======
I've been able to get the `Hello World example`_ of the Box2D C++ library working from Python. Wrappyr currently ignores functions and methods which use C/C++ language features that are not supported yet. Currently some language features like function pointers are still missing. Along with that, destruction is not implemented yet, so memory will leak. But this is easy to implement. See `TODO.rst`_ for more information.

.. _`Hello World example`: http://box2d.org/manual.html#_Toc258082968
.. _`TODO.rst`: ./TODO.rst

Some code is rather messy right now, because I focused on getting a working prototype as soon as possible. I am now working on resturing Wrappyr so it can be used as a library. This would allow C/C++ project to ship with a Python script with the classes needed to generate a Python API. Also, the whole process of going from C/C++ code to a Python API through three steps is going to be simplified so it can be done automatically by using a single script.

Using the Clang plugin
======================
The Clang plugin is a bit of a pain to get running, but I haven't found more convenient way to do it yet. In the future I'll likely make a GCCXML backend, which is easier to install.

* Setup LLVM and Clang using `these instructions`_, but be careful to use CMake to build Clang (Adjusting Makefiles didn't work for me).
* Copy the ExportHeader/ directory to <llvm_root>/llvm/tools/clang/examples .
* Add the line 'add_directory(ExportHeader)' to <llvm_root>/llvm/tools/clang/examples/CMakeLists.txt
* Run 'make' in <llvm_root>/llvm/tools/clang/

.. _`these instructions`: http://clang.llvm.org/get_started.html

If everything went successful, you should now be able to dump a C/C++ header file to XML with these commands adjusted to your needs::

	$ export PYTHONPATH="." # In the root of the Wrappyr project, temporary hack until I've made a setup.py
	$ wrappyr/generate.py generate_code_data --clang-export-plugin <llvm_root>/build/lib/ExportHeader.so /usr/include/mysql/mysql.h /tmp/mysql_clang.xml --language=c # For C code
	$ wrappyr/generate.py generate_code_data --clang-export-plugin <llvm_root>/build/lib/ExportHeader.so /usr/local/include/Box2D/Box2D.h /tmp/box2d_clang.xml --language=c++ # For C++ code

Processing the Clang XML file
=============================
The next steps tales input from a Clang XML export file and generates a Ctypes XML file and optionally a C API to C++ code.

You can generate a Ctypes XML file with the --ctypes option::

	$ export PYTHONPATH="." # In the root of the Wrappyr project, temporary hack until I've made a setup.py
	$ ./wrappyr/generate.py convert_code_data /tmp/box2d_clang.xml --ctypes /tmp/box2d_ctypes.xml

You can generate a C API for C++ code with the --header and --source options::

	$ ./wrappyr/generate.py convert_code_data /tmp/box2d_clang.xml --header /tmp/box2d.h --source /tmp/box2d.cpp

Each library needs some preprocessing. Features which are not supported must be filtered out and the final Python API may need some (cosmetic preprocessing). This is done using the badly named concept of 'packages', classes with methods used to perform some actions. See packages.Box2D.Box2DPackage for an example. You must pass the Pyton import path to the command line if you want to use a package, **so the final commands used to export Box2D are**::

	$ export PYTHONPATH="." # In the root of the Wrappyr project, temporary hack until I've made a setup.py
	$ ./wrappyr/generate.py --package packages.Box2D.Box2DPackage convert_code_data /tmp/box2d_clang.xml --header /tmp/box2d.h --source /tmp/box2d.cpp --ctypes /tmp/box2d_ctypes.xml

Generating the Ctypes-based API from XML
========================================
To generate the Python API from XML, use the generate_ctypes_api command in the wrappyr/generate.py script::

	$ export PYTHONPATH="." # In the root of the Wrappyr project, temporary hack until I've made a setup.py
	./generate_ctypes_api.py --package packages.Box2D.Box2DPackage /tmp/box2d_ctypes.xml --output-path=/tmp/

This will create all root-level packages and modules defined in the XML file in /tmp/. In this script some preprocessing is done to replace reserved Python keywords for example. You can also do some cosmetic preprocessing here, like grouping functions to a class (for ex. a MySQL connection), moving classes around to sub-packages or renaming classes and functions to conform to PEP8 naming conventions. See wrappyr/ctypes_builder/README.rst for more information on how the XML file is structured and the API is structured.

Requirements
============

Python requirements:

* Python 2.6+
* lxml_ (installable through pip)
* argparse, available in standard library in Python >= 2.7
* importlib, available in standard library in Python >= 2.7

.. _lxml: http://lxml.de/
