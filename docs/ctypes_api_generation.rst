=====================
Ctypes API generation
=====================
One of the parts of the Wrappyr project is the Ctypes API builder. It loads a description of a Ctypes based API (typically from XML) and generates Python code from that. The code that does this lives in :mod:`wrappyr.ctypes_api_builder`. Before Wrappyr generates the Python code, it gives you the chance to manipulate the API by calling the the `process_ctypes_structure` of your Package class. Here you can do things like:

* Grouping C functions into classes
* Renaming classes, methods, parameter names to match PEP8 naming conventions
* Organizing the API into packages
* And more...

This document describes all classes used to represent a Python API that you can manipulate and examples on how to use this API.

Reference
=========

.. module:: wrappyr.ctypes_api_builder.structure

.. testsetup:: *

   from wrappyr.ctypes_api_builder.structure import *

.. class:: Node

    The base class for all classes used to represent the API.

    .. attribute:: name

        The name of this node, which will be used to look up Nodes by path.

    .. attribute:: parent

        The parent node of this node. It will be set automatically if you
        you make this node a child of another node, like when you add
        a :class:`Method` to a :class:`Class`

    .. method:: get_path([top])

        Get the dotted path from *top* to this node. If top is not given, the path from the furthest ancestor is returned.

            >>> struct = CTypesStructure()
            >>> Box2D = Package("Box2D")
            >>> dyn = Package("dynamics")
            >>> Box2D.add_package(dyn)
            >>> dyn.get_path()
            'dynamics'
            >>> struct.add_package(Box2D)
            >>> dyn.get_path()
            'Box2D.dynamics'
            >>> dyn.get_path(Box2D)
            'dynamics'

    .. method:: get_closest_parent_of_type(type)

        Get the closest ancestor of *type*

            >>> p = Package("package")
            >>> m = Module("module")
            >>> c = Class("class")
            >>> p.add_module(m)
            >>> m.add_class(c)
            >>> m == c.get_closest_parent_of_type(Module)
            True
            >>> p == c.get_closest_parent_of_type(Package)
            True

    .. method:: get_closest_parent_module()

        Shorthand for get_closest_parent_of_type(Module)

    .. method:: get_distance_to_parent(parent)

        Returns the depth of this node calculated from *parent* or None if *parent* is not an ancestor of this node.

            >>> p = Package("package")
            >>> m = Module("module")
            >>> c = Class("class")
            >>> p.add_module(m)
            >>> m.add_class(c)
            >>> c.get_distance_to_parent(m)
            1
            >>> c.get_distance_to_parent(p)
            2

    .. method:: find_lowest_common_parent(other)

        Returns the first ancestor that this node shares with *other*

            >>> dynamics = Package("dynamics")
            >>> b2Body = Class("b2Body")
            >>> joints = Package("joints")
            >>> b2WeldJoint = Class("b2WeldJoint")
            >>> dynamics.add_class(b2Body)
            >>> dynamics.add_package(joints)
            >>> joints.add_class(b2WeldJoint)
            >>> dynamics == b2WeldJoint.find_lowest_common_parent(b2Body)
            True

    .. method:: parents()

        Returns a generator that iterates over all ancestors starting with the closest one.

            >>> dynamics = Package("dynamics")
            >>> joints = Package("joints")
            >>> b2WeldJoint = Class("b2WeldJoint")
            >>> dynamics.add_package(joints)
            >>> joints.add_class(b2WeldJoint)
            >>> tuple(b2WeldJoint.parents()) == (joints, dynamics)
            True

.. class:: Module(Node)

    Class used to represent a Python module. A module can contain:

        * :class:`Library` instances
        * :class:`Function` instances
        * :class:`Class` instances
        * :class:`PointerType` instances

    You can create a :class:`Module` from XML by using the <module> tag:

    .. code-block:: xml

        <module name="test">
            ...
        </module>

    .. method:: find_library([name])

        Find :class:`Library` with specified `name` in this :class:`Module` or one of it's parents.
        If *name* is not given, it will search for a library specified as default.

    .. method:: add_library(library)

        Add :class:`Library` instance *library* to this module and set its parent to this node.
        This does not remove it from its current parent, so you must remove it from its parent first (if it has one of course).

    .. method:: remove_library(library)

        Remove :class:`Library` instance *library* from this module and set its parent to ``None``.

    .. method:: every_library()

        Returns all :class:`Library` instances that this module contains.

    .. method:: add_class(class)

        Add :class:`Class` instance *class* to this module and set its parent to this node.
        This does not remove it from its current parent, so you must remove it from its parent first (if it has one of course).

    .. method:: remove_class(class)

        Remove :class:`Class` instance *class* from this module and set its parent to ``None``.

    .. method:: every_class()

        Returns all :class:`Class` instances that this module contains.

    .. method:: add_function(function)

        Add :class:`Function` instance *function* to this module and set its parent to this node.
        This does not remove it from its current parent, so you must remove it from its parent first (if it has one of course).

    .. method:: remove_function(function)

        Remove :class:`Function` instance *function* from this module and set its parent to ``None``.

    .. method:: every_function()

        Returns all :class:`Function` instances that this module contains.

    .. method:: add_pointer(pointer)

        Add :class:`PointerType` instance *pointer* to this module and set its parent to this node.
        This does not remove it from its current parent, so you must remove it from its parent first (if it has one of course).

        Since a :class:`PointerType` does not need to be a child of a Node to be used, this is probably only useful for loading from XML.

    .. method:: remove_pointer(pointer)

        Remove :class:`PointerType` instance *pointer* from this module and set its parent to ``None``.

    .. method:: every_pointer()

        Returns all :class:`PointerType` instances that this module contains.

    .. exception:: LibraryNotFound(Exception)

        Exception thrown by :meth:`Module.find_library` when it cannot find the requested :class:`Library`.

.. class:: Package(Module)

    Class used to represent a Python package. In addition to everything a :class:`Module` can contain, a package can contain:

        * :class:`Package` instances
        * :class:`Module` instances

    You can create a :class:`Package` from XML by using the <package> tag:

    .. code-block:: xml

        <package name="test">
            ...
        </module>

.. class:: Library(Node)

    Class used to represent a C library.

    You can create a :class:`Library` from XML by using the <library> tag:

    .. code-block:: xml

        <package name="test">
            <library name="libA" path="libA.so" default="true" />
            <library name="libB" path="libB.so" />

            <function name="func_a">
                <call symbol="funcA">
                    <!--
                    Since libA is the default for this Package,
                    the symbol funcA will be retrieved from libA.so
                    -->
                    ...
                </call>
            </function>
            <function name="func_b">
                <call symbol="funcB" library="libB">
                    <!--
                    We've explicitly chosen libB, so the symbol funcB
                    will be retrieved from libB.so
                    -->
                    ...
                </call>
            </function>
        </module>

.. class:: Function(Node)

    Class used to represent a Python function.

    You can create a :class:`Function` from XML by using the <function> tag:

    .. code-block:: xml

        <function name="func_a">
            <call symbol="funcA">
                <!-- A function can make calls to C functions. -->
            </call>
        </function>

        <function name="func_b">
            <raw><![CDATA[
        # Or it can contain raw Python code.
        print "Hello world!"
        ]]>
            </raw>
        </function>

.. class:: Method(Function)

    Class used to represent a method of a Python class.

    You can create a :class:`Method` from XML by using the <method> tag:

    .. code-block:: xml

        <class name="Test">
            <method name="spam">
                <!-- Python likes spam and eggs, C like foo and bar ;) -->
                <call symbol="foo" />
            </method>
        </class>

.. class:: Member(Node)

    Class used to represent a member Python of a class.

    You can create a :class:`Member` from XML by using the <member> tag and specify its getter and setter using the <getter> and <setter> tags respectively:

    .. code-block:: xml

        <class name="Vector">
            <member name="x">
                <getter>
                    <!-- You could also put raw python code here using the <raw> tag -->
                    <call symbol="Vector_GetX">
                        <returns type="ctypes.c_float" />
                    </call>
                </getter>
                <setter>
                    <call symbol="Vector_SetX">
                        <argument type="ctypes.c_float" />
                    </call>
                </setter>
            </method>
        </class>

.. class:: Operation(Node)

    The base class for the :class:`Call` and :class:`RawCode` classes.

.. class:: Call(Operation)

    Class used to represent a call to a C function.

    You can create a :class:`Call` from XML by using the <call> tag:

    .. code-block:: xml

        <function name="take_over_the_world">
            <!--
            Obviously much more effecient in C, altough things
            will probably crash before anything useful happens.
            -->
            <call symbol="conquerWorld">
                <argument name="timeout" type="ctypes.c_uint" />
                <returns type="ctypes.c_bool">
            </call>
        </function>

.. class:: RawCode(Operation)

    Class used to hold a block of raw Python code.

    You can create a :class:`RawCode` instance from XML by using the <raw> tag:

    .. code-block:: xml

        <function name="test">
            <raw>return "something"</raw>
        </function>

.. class:: Argument(Node)

    Class used to represent an argument to a C function.

    You can create an :class:`Argument` instance from XML by using the <argument> tag:

    .. code-block:: xml

        <module name="module">
            <class name="Class" />

            <function name="func">
                <call symbol="func">
                    <!-- You can reference existing classes by using full dotted paths -->
                    <argument name="a" type="module.Class" />

                    <!-- You can also use ctypes.* types -->
                    <argument name="b" type="ctypes.c_int" />
                </call>
            </function>
        </module>

    .. attribute:: steals

        Boolean value indicating whether passing an object as this argument to a call will steal the ownership over the object.
        See :doc:`memory_management` for more information.

    .. attribute:: invalidates

        Boolean value indicating whether passing an object as this argument to a call will invalidate the object.
        See :doc:`memory_management` for more information.

.. class:: ReturnValue(Node)

    Class used to represent the return value of a C function.

    You can create a :class:`ReturnValue` instance from XML by using the <returns> tag:

    .. code-block:: xml

        <function name="func">
            <call symbol="func">
                <returns type="ctypes.c_float" />
            </call>
        </function>

    .. attribute:: ownership

        Boolean value indicating whether we have ownership over objects returned by this call.
        See :doc:`memory_management` for more information.

.. class:: CTypesStructure(Node)

    The root of the structure that describes the Python API. This will contain the root :class:`Package` s and :class:`Module` s of the Python API.

    This class is represented by the XML tag <ctypes>. Since this is the root of the structure, this must also be the root node of the XML document:

    .. code-block:: xml

        <?xml version="1.0"?>
        <ctypes>
            <package name="MyPackage">
                ...
            </package>
        </ctypes>

    .. method:: get_by_path(path)

        Return the :class:`Node` found under the dotted path *path*:

                >>> structure = CTypesStructure()
                >>> mod = Module("mod")
                >>> cls = Class("Class")
                >>> structure.add_module(module)
                >>> mod.add_class(cls)
                >>> cls == structure.get_by_path("mod.Class")
                True

.. class:: CTypesStructureVisitor

    A convenience class that takes a :class:`CTypesStructure` and calls visit_<class name> on itself for every node it finds. So as an example, it will call visit_Method(method) for every method it finds.

    Example:

    .. code-block:: python

        class ClassPrinter(CTypesStructureVisitor):
            def visit_Class(cls):
                print "Found class: " + cls.name

    .. method:: process(node)

        Will start at *node* and call the corresponding visit_* method for *node* and all of its descendents.

Examples
========

The recommended way to use this API is to process a :class:`CTypesStructure` from within a :class:`wrappyr.Package`. See :doc:`creating_package_classes` for an introduction on Packages. This section gives a few exmples of how you might preprocess a Python API.

Reorganize an API that doesn't use namespaces into packages:

.. code-block:: python

        import wrappyr
        from wrappyr.ctypes_api_builder.structure import Package

        class Box2DPackage(wrappyr.Package):
            CLASS_TO_PACKAGE = {
                'b2Vec2': 'Box2D.common',
                'b2Vec3': 'Box2D.common',
                'b2Shape': 'Box2D.collision',
                'b2PolygonShape': 'Box2D.collision',
                'b2World': 'Box2D.dynamics',
                'b2Body': 'Box2D.dynamics',
                'b2Joint': 'Box2D.dynamic.joints',
                'b2WeldJoint': 'Box2D.dynamic.joints',
            }

            def process_ctypes_structure(structure):
                # Get all unique package paths
                package_paths = set(self.CLASS_TO_PACKAGE.values())
                # Sort by depth in tree
                package_paths = sorted(packages, lambda name: name.count("."))

                # Dictionary to hold all packages to be looked up by path
                packages = {}
                for path in package_paths:
                    last_dot = path.rfind(".")

                    # The name of the package is the part after the last dot
                    name = path[last_dot + 1 :]
                    package = Package(name)
                    packages[path] = package

                    # Add the package to its parent in the tree.
                    # We assume that the Box2D package already exists.
                    parent_path = path[: last_dot]
                    parent = structure.get_by_path(parent_path)
                    parent.add_package(package)

                # Now we remove classes from their current parent and
                # add them to their new package.
                for class_name, package_path in self.CLASS_TO_PACKAGE.items():
                    cls = structure.get_by_path("Box2D." + class_name)
                    cls.parent.remove_class(cls)
                    packages[package_path].add_class(cls)

Convert camelCase method names into lowercase_with_underscores:

.. code-block:: python

        import re
        import wrappyr
        from wrappyr.ctypes_api_builder.structure import CTypesStructureVisitor

        class CamelCaseTerminator(CTypesStructureVisitor):
            def __init__(self):
                self.to_rename = []

            def visit_Method(self, method):
                self.to_rename.append(method)

            def terminate(self):
                regex = re.compile(r'([a-z])([A-Z])')
                to_underscore = lambda match: "%s_%s" % (match.group(1), match.group(2).lower())
                for method in self.to_rename:
                    parent = method.parent
                    parent.remove_method(method)
                    method.name = regex.sub(to_underscore, method.name)
                    parent.add_method(method)

        class MyPackage(wrappyr.Package):
            def process_ctypes_structure(structure):
                terminator = CamelCaseTerminator()
                terminator.process(structure)
                terminator.terminate()
