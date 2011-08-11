======
PyWrap
======

:author: Vincent den Boer

PyWrap is a collection of tools making it easier to create a Ctypes-based API to C/C++ code. It is composed of three parts:

* A Clang_ plugin that dumps classes, functions, etc. from a header file to XML.
* A tool that imports the XML file produced by the Clang plugin and does two things:

  - Generate a C API for your C++ code.

  - Generate an XML file describing how the Python API should look, which C calls should be made where, etc.

* A tool that creates the Ctypes-based Python API from an XML file.

.. _Clang: http://clang.llvm.org/

Status
======
I've been able to get the `Hello World example`_ of the Box2D C++ library working from Python. PyWrap currently ignores functions and methods which use C/C++ language features that are not supported yet. Currently a few language features are missing that prevent most libraries from doing anything useful, like array pointers (needed for the MySQL C API), function pointers and C++ class inheritence (needed for Box2D callbacks). Those features are the highest priority for now. Along with that, desctruction is not implemented yet, so memory will leak. But this is easy to implement. See TODO.rst for more information.

.. _`Hello World example`: http://box2d.org/manual.html#_Toc258082968

Some code is rather messy right now, because I focused on getting a working prototype as soon as possible. Also, I think the project should be restructured a bit to be used as a library. This would allow C/C++ project to ship with a Python script with the classes needed to generate a Python API. Also, the whole process of going from C/C++ code to a Python API through these three steps could maybe be streamlined into a single script to make the process less cumbersome.

Using the Clang plugin
======================
The Clang plugin is a bit of a pain to get running, but I haven't found more convenient way to do it yet.

* Setup LLVM and Clang using `these instructions`, but be careful to use CMake to build Clang (Adjusting Makefiles didn't work for me).
* Copy the ExportHeader/ directory to <llvm_root>/llvm/tools/clang/examples .
* Add the line 'add_directory(ExportHeader)' to <llvm_root>/llvm/tools/clang/examples/CMakeLists.txt
* Run 'make' in <llvm_root>/llvm/tools/clang/

If everything went successful, you should now be able to dump a C/C++ header file to XML with these commands adjusted to your needs::
	For C:
		../../bin/clang -cc1 -load ../../lib/ExportHeader.so -plugin export-hdr \
			-I/usr/include/i386-linux-gnu/ /usr/include/mysql/mysql.h \
			> /tmp/mysql_clang.xml
	For C++:
		../../bin/clang++ -cc1 -load ../../lib/ExportHeader.so -plugin export-hdr -x c++ \
			-I/usr/include/i386-linux-gnu/ /usr/local/include/Box2D/Box2D.h \
			> /tmp/box2d_clang.xml

Processing the Clang XML file
=============================
The clang_convert.py script takes a Clang XML exmport file as input and generates a Ctypes XML file and optionally a C API to C++ code.

You can generate a Ctypes XML file with the --ctypes option::

	./clang_convert box2d_clang.xml --ctypes box2d_ctypes.xml

You can generate a C API for C++ code with the --header and --source options::

	./clang_convert box2d_clang.xml --header box2d_c.h --source box2d_c.cpp

For now the script contains a few hardcoded classes for Box2D and CEGUI that filter out some classes and methods that are not supported. These will eventually be seperated out to indenpent module once I've found a nice way to organize things. You can select them with the --package option, **so the whole command used to export Box2D becomes**::

	./clang_convert box2d_clang.xml --package Box2D --header box2d_c.h --source box2d_c.cpp --ctypes box2d_ctypes.xml

This script will eventually get replaced by something prettier.

Generating the Ctypes-based API from XML
========================================
To generate the Python API from XML, use the generate_ctypes_api.py script::

	./generate_ctypes_api.py box2d_ctypes.xml --output-path=/tmp/

This will create all root-level packages and modules defined in the XML file in /tmp/. In this script some preprocessing is done to replace reserved Python keywords for example. You can also do some cosmetic preprocessing here, like grouping functions to a class (for ex. a MySQL connection), moving classes around to sub-packages or renaming classes and functions to conform to PEP8 naming conventions. See ctypes_builder/README.rst for more information on how the XML file is structured and the API is structured.

This script will eventually get replaced by something prettier.

Requirements
============

Python requirements:

* Python 2.6+
* lxml_ (installable through pip)

.. _lxml: http://lxml.de/
