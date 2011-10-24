from _collections import defaultdict
from ctypes import Structure, CFUNCTYPE
import ctypes

class CArray(object):
    class UnknownSize(Exception): pass

    def __init__(self, ptr, cls = None, size = None, ownership = False,
                             dimensions = 1):
        self.ptr = ptr
        self.cls = cls
        self.size = size
        self.ownership = ownership
        self.dimensions = dimensions

    def __del__(self):
        if not self.ownership:
            return

        if self.cls:
            self.cls.__delarray__(self.ptr)

    def elements(self, size = None):
        size = size or self.size
        if size is None:
            raise self.UnknownSize("No size passed or stored in class")

        for i in xrange(size):
            yield self[i]

    def __iter__(self):
        return self.elements()

    def __getitem__(self, item):
        assert isinstance(item, int)

        if self.size and item >= self.size:
            msg = "Tried to access element %d of array with size %d"
            raise IndexError(msg % (item, self.size))

        if self.dimensions > 1:
            return CArray(self.ptr[item], self.cls, False, self.dimensions - 1)

        if self.cls:
            item = self.cls.__arrayitem__(self.ptr, item)
            item = self.cls._from_c(item, False)
        else:
            item = self.ptr[item].value
        return item

def arrayof(cls, size):
    return CArray(cls.__newarray__(size), cls, size, True)

class Overridable(object):
    def __init__(self, name):
        self.name = name
        self.argtypes = []
        self.arg_converters = []
        self.restype = None
        self.res_cls = None

    def convert_args(self, *args):
        return (conv(arg) if conv else arg
                        for conv, arg
                        in zip(self.arg_converters, args))

    def convert_result(self, res):
        res_cls = self.res_cls
        if not res_cls:
            return res

        assert isinstance(res, res_cls)
        return res._inst

class PolymorphismInfo(object):
    def __init__(self, create_inherited_call = None):
        self.create_inherited_call = create_inherited_call
        self.overridables = []
        self.overridables_by_name = defaultdict(list)

    def add_overridable(self, overridable):
        self.overridables.append(overridable)
        self.overridables_by_name[overridable.name].append(overridable)

class CPPClassMeta(type):
    def __new__(mcs, name, bases, dct):
        polyinfo = dct.get('_polymorphism_info_')
        if polyinfo:
            dct['_vtable_cls_'] = mcs._create_vtable_cls(polyinfo)
            return type.__new__(mcs, name, bases, dct)

        polyinfo = getattr(bases[0], '_polymorphism_info_', None)
        if not polyinfo:
            return type.__new__(mcs, name, bases, dct)
        vtable_cls = bases[0].__dict__.get('_vtable_cls_')
        vtable = vtable_cls()
        dct['_vtable_'] = vtable

        cls = type.__new__(mcs, name, bases, dct)
        for name in polyinfo.overridables_by_name.keys():
            mcs._adjust_vtable(cls, name)
        return cls

    @classmethod
    def _create_vtable_cls(mcs, polyinfo):
        class VTable(Structure):
            _fields_ = []
#                       _functypes_ = []
            for i, overridable in enumerate(polyinfo.overridables):
                functype = CFUNCTYPE(overridable.restype, ctypes.py_object, *overridable.argtypes)
                _fields_.append(('f%d' % i, functype))
#                               _functypes_.append(functype)
        return VTable

    def _adjust_vtable(cls, name):
        vtable = cls._vtable_
        polyinfo = cls._polymorphism_info_
        overridables = [overridable for overridable
                                                                in polyinfo.overridables
                                                                if overridable.name == name]
        fields = [field for field, overridable
                                        in zip(vtable._fields_, polyinfo.overridables)
                                        if overridable.name == name]

        method = getattr(cls, name, None)
        for field, overridable in zip(fields, overridables):
            if method:
                callback = cls._create_c_callback(overridable, method)
                callback = field[1](callback)
            elif not getattr(vtable, field[0]) or not overridable.required:
                callback = field[1]()
            else:
                raise RuntimeError("You must implement method '%s'" % overridable.name)
            setattr(vtable, field[0], callback)

    def _create_c_callback(cls, overridable, method = None):
        if not method:
            method = getattr(cls, overridable.name)
        convert_args = overridable.convert_args
        convert_result = overridable.convert_result

        def inner(self, *args):
            args = convert_args(*args)
            res = method(self, *args)
            return convert_result(res)
        return inner

    def __setattr__(cls, key, value):
        type.__setattr__(cls, key, value)
        if key == "_polymorphism_info_":
            cls._vtable_cls_ = cls._create_vtable_cls(value)
        elif hasattr(cls, "_polymorphism_info_") and key in cls._polymorphism_info_.overridables_by_name:
            cls._adjust_vtable(key)

    def __delattr__(cls, key):
        type.__delattr__(cls, key)
        if key in cls._polymorphism_info_.overridables_by_name:
            cls._adjust_vtable(key)

class CPPClass(object):
    __metaclass__ = CPPClassMeta

    def __init__(self):
        pass

class NoArgument(object):
    pass
