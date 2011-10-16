=======
Wrappyr
=======

:author: Vincent den Boer

Wrappyr is a collection of tools aiming for tight integration both-way between Python and C/C++ using Ctypes. This means that when this goal is reached, you can write parts of your code in Python or C/C++ and switch between them without needing to change the rest of your program.

It is composed of three parts:

* A tool that imports the XML file produced by the Clang plugin and does two things:

  - Optional: Generate a C API for your C++ code.

  - Generate an XML file describing how the Python API should look, which C calls should be made where, etc.

* A tool that creates the Ctypes-based Python API from an XML file.

* A Clang_ plugin that dumps classes, functions, etc. from a header file to XML, which you can use when GCCXML produces incomplete output.

.. _Clang: http://clang.llvm.org/

Status
======
I've been using the Box2D physics library for testing so far because it's a relatively simple API. Basic features like using C++ classes and inheriting from them are implemented, but need testing and documentation. Aside from that, there are other things that need to be imlemented before this project becomes really useful, like memory management (it currently leaks a lot). Also, I have not yet started working on accessing your Python classes/functions from C/C++. See `TODO.rst`_ for more information on what needs to be done.

Also, my main development platform is Linux. While the concepts used by Wrappyr should be portable across different platform, you'll need to make some adjustments to make it work. You can contact me if you need some help with this.

.. _`TODO.rst`: https://github.com/ShishKabab/Wrappyr/blob/master/TODO.rst

Requirements
============

General requirements:

* Recommended: GCCXML, which you can probably install through your package manager.

Python requirements:

* Python 2.6+
* lxml_ (installable through pip)
* argparse, available in standard library in Python >= 2.7
* importlib, available in standard library in Python >= 2.7

.. _lxml: http://lxml.de/

Documentation
=============
Further documentation, which includes how get started, is available in the docs/ directory and on `Read the Docs`_.

.. _`Read the Docs`: http://readthedocs.org/docs/wrappyr/en/latest/
