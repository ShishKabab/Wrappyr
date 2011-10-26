=================
Memory management
=================

.. warning::

    This is not actually implemented yet, but I'm writing this in the spirit of Documentation Driven Development. Memory management is currently broken in Wrappyr and will crash your program or leak memory if you're lucky. Yes, I'm working on it :).

Memory management is quite an important part of programming in C/C++. When working in Python however, we expect this to work automatically. For this to happen, we need to provide some hints to Wrappyr how it can safely clean up after the Python programmer.

By default Wrappyr is extremely careful not to free memory it does not manage and will leak a lot of memory as a result. This is because there are different models of memory management. Let's say for example that you have a Window class with a method createWindow that returns a pointer to to newly created Window. Does Wrappyr need to destroy the Window after we're done with it, or will the parent Window destroy it? And when you pass a Window pointer to a its parent's removeWindow method, can we continue to work with that Window? Wrappyr relies on you for answers to the questions, because only you as a human fully know what is going on.

When Wrappyr runs, it ask the following questions to manage memory:

* I have a pointer; does it still point to a *valid* object so I can safely apply operations to it?
* I have a pointer; do I have *ownership* and do I need to deallocate the object when I'm done with it?
* I'm passing an object as an argument to a function; will the call *invalidate* my object?
* I'm passing an object as an argument to a function; will the call *steal* my *ownership* over the object?
* A function returned an object; do I now have the *ownership* over the object?

By default Wrappyr assumes the following to answer these questions:

* When a funtion returns an object that Wrappyr copied to the heap, Wrappyr has *ownership* over that copy.
  This applies to functions like:

  .. code-block:: c++

        Vector2 Cross(Vector2 a, Vector2 b);

* When a function returns a pointer or reference to an object, Wrappyr does **not** have *ownership* over the object,
  so you must deallocate it manually if necessary.
* Passing an object to a function **not** change whether the object is *valid* or wheter Wrappyr has *ownership* over it.

Providing memory management hints
=================================

Wrappyr uses memory management hints when generating the Python API, so to provide memory management hints to Wrappyr, you modify the Python API representation (which you typically do in a :class:`wrappyr.Package`, specifically the :meth:`wrappyr.Package.process_ctypes_structure` method).

Now I'll provide a list of hints you can give. Before you read this, make sure you have read and understood the concepts of *valid*, *ownership* and *stealing* is explained in the previous section.

.. currentmodule:: wrappyr.ctypes_api_builder.structure

* To indicate that passing an object as argument to a call will *invalidate* the object, set the :attr:`Argument.invalidates` attribute to ``True``. If you then pass an object to this call, the object will be marked as invalid and its internal pointer to None. If you then try to pass the object to another call, an exception will be raised.
* To indicate that the *ownership* of an object will be *stolen* when passing it as an argument to a function, set the :attr:`Argument.steals` attribute to ``True``. After this, the object won't be deallocated when it's not used in Python anymore. When you then try to pass the object to another call that will try to *steal* the ownership, an exception will be raised. To mark that it's safe to pass the object that is not owned to the stealing call, set the :attr:`Argument.steals` attribute to the string ``safe``.
* To indicate a call gives you *ownership* over the object it returns, set the :attr:`ReturnValue.ownership` attribute to true.

Examples
========

Provide hints about memory management for some calls in the API:

.. code-block:: python

    import wrappyr

    class hint(object):
        def __init__(name, argument = None, steals = None, invalidates = None, ownership = None):
            self.name = name
            self.argument = argument
            self.steals = steals
            self.invalidates = invalidates
            self.ownership = ownership

        def apply(self, call):
            for prop in ("steals", "invalidates"):
                value = getattr(self, prop)
                if value is not None:
                    for arg in call.args:
                        if arg.name == self.argument:
                            setattr(arg, prop, value)
            if self.ownership is not None and call.returns:
                call.returns.ownership = self.ownership

    class MyGuiPackage(wrappyr.Package):
        HINTS = [
            hint("MyGui.Window.add_child", "child", ownership = True),
            hint("MyGui.Window.destroy_child", "child", invalidates = True),
            hint("MyGui.Window.detach_child", ownership = True),
        ]

        def process_ctypes_structure(self, structure):
            for hint in self.hints:
                f = structure.get_by_path(hint.name)
                for call in f.ops:
                    hint.apply(call)

Assume that all methods that begin with ``destroy_`` invalidate the arguments passed to them:

.. code-block:: python

    import wrappyr
    from wrappyr.ctypes_api_builder.structure import CTypesStructureVisitor

    class FixDestroyMethods(CTypesStructureVisitor):
        def visit_Method(self, method):
            if method.raw:
                return # Method only conains Python code, so skip it.
            if not method.name.startswith("destroy_"):
                return # Method does not start with destroy_

            for call in method.ops:
                for arg in call.args:
                    arg.invalidates = True

    class MyPackage(wrappyr.Package):
        def process_ctypes_structure(self, structure):
            FixDestroyMethods().process(structure)
