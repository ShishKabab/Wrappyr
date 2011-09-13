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
* Overloaded operators
* Function returns pointer to copy created by copy constructor when a C++ class is returned. Find more elagant solution.
* Generate classes for multiple inheritance?
* Template classes and functions - how?
* Exceptions - how?
* Unions
* Tests

Ctypes API generator
====================
* PEP8
* Cleanup code
* Pointers and arrays

  * Some work has already been done, but not all pointer use cases are handled yet.

* Enums
* Destruction, ownership, stealing ownership, also in overriden methods
* Deal with inheritance (b2Shape and b2PolygonShape)
* Static class methods and members
* Function overloading
* Overloaded operators
* Null pointers and None
* Export Python classes to C++

  * Would be nice so you can re-implement Python classes in C++ and vice versa without changing any client code.
  * Would require hints (in the form of decorators?) about the arguments and return values of methods.

* Add support for idioms, indicating wich classes / methods represent strings, hash tables, lists, iterators, etc.
* Template classes and functions - how?
* Exceptions - how?
* Tests
