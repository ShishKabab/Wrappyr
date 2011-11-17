==========
To do list
==========

Code data conversion
====================
* Functions

  * How should I name global functions in the C API?

* Static class methods and members
* Unions
* Overloaded operators
* Function returns pointer to copy created by copy constructor when a C++ class is returned. Find more elegant solution.
* Generate classes for multiple inheritance?
* Template classes and functions - how?

    * Generate classes for all typedef'ed classes and functions, e.g.: typedef List<String> StringList;

* Exceptions - how?
* Tests

Ctypes API generator
====================
* Null pointers and None
* Enums
* Static class members
* Add support for argument and return values, useful for strings, arrays, conversion between classes like points and tuples
* Function overloading
* Overloaded operators
* Nested classes
* Pointers and arrays

  * Some work has already been done, but not all pointer use cases are handled yet.

* Export Python classes to C++

  * Would be nice so you can re-implement Python classes in C++ and vice versa without changing any client code.
  * Would require hints (in the form of decorators?) about the arguments and return values of methods.

* Memory management in overridden methods?
* Add support for idioms, indicating wich classes / methods represent strings, hash tables, lists, iterators, etc.
* Exceptions - how?
* Tests

Clang export
============
* Overloaded operators
* Unions
