==========
To do list
==========

Clang export
============
* Find a way to get plugin running more easily
* Overloaded operators
* Unions

Clang import
============
* PEP8

  * Naming conventions are already PEP8
  * But things like long lines and inconsistent quoting styles need to be fixed

* Functions

  * How should I name global functions in the C API?

* Static class methods and members
* Generate classes for inheritance

  * I plan to create a subclass wrapped in a C API for each class that you want to subclass in Python.
  * The class can then be constructed with a struct of function pointers (the vtable) and a void* which is a Python object
  * Each re-implemented method checks the struct whether it was implemented in Python and calls that or the parent method.

* Overloaded operators
* Function returns pointer to copy created by copy constructor when a C++ class is returned. Find more elagant solution.
* Template classes and functions - how?
* Exceptions - how?
* Unions
* Tests

Ctypes API generator
====================
* PEP8
* Cleanup code
* Pointers and arrays
* Type checking
* Default arguments
* Enums
* Destruction, ownership, stealing ownership
* Deal with inheritance (b2Shape and b2PolygonShape)
* Static class methods and members
* Inherit from C++ classes

  * See above for the C API part.
  * For each class you should be able to specify:

    * how the vtable of that class looks
    * how the members of the vtable correspond to the methods you can re-implement
    * which function to call to create an instance of the inherited class

  * When you inherit from a C++ class a vtable should be constructed

    * This means that you cannot change the class after it's created

  * And the contructor of the C++ class in the Python API should decide whether the normal constructor or
      the constructor for an inherited class should be used.

* Function overloading
* Overloaded operators
* Export Python classes to C++
* Template classes and functions - how?
* Exceptions - how?
* Tests
