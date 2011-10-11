============
Introduction
============

Wrappyr is a collection of tools aiming for tight integration both-way between Python and C/C++ using Ctypes. This means that when this goal is reached, you can write parts of your code in Python or C/C++ and switch between them without needing to change the rest of your program.

It is composed of three parts:

* A tool that imports the XML file produced by the Clang plugin and does two things:

  - Optional: Generate a C API for your C++ code.

  - Generate an XML file describing how the Python API should look, which C calls should be made where, etc.

* A tool that creates the Ctypes-based Python API from an XML file.

* A Clang_ plugin that dumps classes, functions, etc. from a header file to XML, which you can use when GCCXML produces incomplete output.

.. _Clang: http://clang.llvm.org/

Requirements
============

General requirements:

* Recommended: GCCXML, which you can probably install through your package manager.

Python requirements:

* Python 2.6+
* lxml_ (installable through pip)
* argparse, available in standard library in Python >= 2.7 and through pip for earlier versions
* importlib, available in standard library in Python >= 2.7 and through pip for earlier versions

.. _lxml: http://lxml.de/

Getting started
===============
To go from C/C++ to a working Python API, quite some things need to happen. First some data about the C/C++ code must be extracted. Then some code needs to be generated and compiled to make your code accessible through Ctypes. Also, an XML file needs to be generated which describes the final Python API and how it exactly it will use Ctypes wich will be used to generate the final Python code. You can do all these steps by hand using the commmands available in wrappyr/generate.py, but since you'll need to do these steps more than once, it's better to write a class (called a Package) that helps Wrappyr do most of these things by itself. We'll use the Box2D package shipped with Wrappyr for this example.

To generate all files needed for a working Python API, you can use the following commands (in the Wrappyr directory) to generate all needed code::

    $ export PYTHONPATH="."
    $ wrappyr/generate.py --package path.to.Package generate_from_package /tmp/ # Will create Python packages in /tmp/

So to generate a Python API for Box2D (assuming it's installed on your system), use this command::

    $ wrappyr/generate.py --package packages.Box2D.Box2DPackage generate_from_package /tmp/ # Will generate /tmp/Box2D

After that you'll need to compile the C API to your C++ yourself. The code generated for Box2D is located in /tmp/ and you can compile it with the following commands::

    $ cd /tmp/
    $ g++ -shared -o libBox2DC.so box2d.cpp -lBox2D

Then after ensuring both the wrappyr and your generated packages are in your Python path, you're ready to use the generated Python API::

    >>> from Box2D.common import b2Vec2
    >>> v = b2Vec2(1.0, 3.1)
    >>> v.Normalize()
    3.2572994232177734
    >>> v.x
    0.30700278282165527

If you have any trouble setting getting started, feel free to contact me.

Where to go from here
=====================
Since the chances of Wrappyr generating a Python API that fully satisfies all your needs straight out of the box is very small, you'll want to write your own Package class to adapt the generation of the Python API to your needs. See :doc:`creating_package_classes` for information on how to do this.
