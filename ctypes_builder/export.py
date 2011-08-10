import os
from collections import defaultdict
from itertools import chain, count
from structure import Package, Class, Method, Member
from utils.str import SourceBlock

class NoCommonArguments(Exception): pass
def get_call_args(f):
	""" Return list of calls with the arguments unique to each call sorted by length of argument list """

	if f.raw:
		return

	ops = sorted(f.ops, key = lambda op: len(op.args))
	args = []
	for op in ops:
		if args and any(left.type != right.type for left, right in zip(args[-1], op.args)):
			raise NoCommonArguments("Arguments of function '%s' don't share common arguments" % f.name)

		args.append(op.args[len(args[-1]) if args else 0:])

	return zip(ops, args)

def get_argument_list(call_args):
	arg_list = []

	first_call = True
	for call, args in call_args:
		for arg in args:
			arg_list.append(arg.name + (" = NoArgument" if not first_call else ""))
		first_call = False

	return ", ".join(arg_list)

def get_converted_argument(arg, name = None):
	name = name or arg.name
	if isinstance(arg.type, Class):
		return "%s._inst" % name
	else:
		return "%s(%s)" % (arg.type, name)

def get_converted_argument_list(call):
	l = [get_converted_argument(arg) for arg in call.args]
	if isinstance(call.parent, (Method, Member)) and call.parent.name != "__init__":
		l.insert(0, "self._inst")
	return ", ".join(l)

def get_calls_per_library(calls):
	calls_per_lib = defaultdict(list)
	for call in calls:
		mod = call.get_closest_parent_module()
		lib = mod.find_library(call.library)
		calls_per_lib[lib].append(call)

	return calls_per_lib.items()

def export_method(cls, method):
	block = SourceBlock()

	if method.name == "__init__":
		action = "self._inst = {callstr}"
	else:
		action = "return self._calls['{call.symbol}'].convert_res({callstr})"

	if not method.raw:
		call_args = get_call_args(method)
		first_call = call_args[0][0]
		arg_list = get_argument_list(call_args)

		block.add_line("def %s(%s):" % (method.name, 'self, ' + arg_list if arg_list else 'self'))
		if len(call_args) > 1:
			for call, args in reversed(call_args[1:]):
				callstr = "self._calls['%s'](%s)" % (
					call.symbol, get_converted_argument_list(call)
				)
				block.add_line("if %s:" % " and ".join("%s != NoArgument" % arg.name for arg in args), 1)
				block.add_line(action.format(call = call, callstr = callstr), 2)

			callstr = "self._calls['%s'](%s)" % (
				first_call.symbol, get_converted_argument_list(first_call)
			)
			block.add_line("else:", 1)
			block.add_line(action.format(call = first_call, callstr = callstr), 2)
		else:
			callstr = "self._calls['%s'](%s)" % (
				first_call.symbol, get_converted_argument_list(first_call)
			)
			block.add_line(action.format(call = first_call, callstr = callstr), 1)
		if method.name == "__init__":
			block.add_line("self._ownership = True", 1)

	return block

def export_member(cls, member):
	block = SourceBlock()

	block.add_line("%s = property(" % member.name)
	if member.getter:
		getter = member.getter
		op = getter.ops[0]
		if not getter.raw:
			block.add_line(("lambda self: self._calls['{call.symbol}']" +
				".convert_res(self._calls['{call.symbol}'](self._inst)),").format(
					call = op), 1)
		else:
			block.add_line("lambda self: %s," % op.code, 1)
	else:
		block.add_line("None,", 1)
	if member.setter:
		setter = member.setter
		op = setter.ops[0]
		if not setter.raw:
			block.add_line(("lambda self, v: self._calls['{call.symbol}']" +
				".convert_res(self._calls['{call.symbol}'](self._inst, {arg}))").format(
					call = op, arg = get_converted_argument(op.args[0], 'v')), 1)
		else:
			block.add_line("lambda self, v: %s" % op.code, 1)
	else:
		block.add_line("None", 1)
	block.add_line(")")

	return block

def export_class(cls):
	block = SourceBlock()
	block.add_line("class %s(object):" % cls.name)
	for method in sorted(cls.methods.values(), key = lambda method: method.name):
		block.add_block(export_method(cls, method), 1)
	for member in sorted(cls.members.values(), key = lambda member: member.name):
		block.add_block(export_member(cls, member), 1)

	block.add_line("@staticmethod", 1)
	block.add_line("def _from_c(inst, ownership = False):", 1)
	block.add_line("cls = %s.__new__(%s)" % ((cls.name,) * 2), 2)
	block.add_line("cls._inst = inst", 2)
	block.add_line("cls._ownership = ownership", 2)
	block.add_line("return cls", 2)

	return block

def export_class_setup(cls):
	block = SourceBlock()

	cls_module = cls.get_closest_parent_module()

	calls = []
	for method in cls.methods.values():
		if not method.raw:
			calls.extend(method.ops)
	for member in cls.members.values():
		if member.getter and not member.getter.raw:
			calls.extend(member.getter.ops)
		if member.setter and not member.setter.raw:
			calls.extend(member.setter.ops)

	calls_per_lib = get_calls_per_library(calls)
	calls_per_lib = sorted(calls_per_lib, key =
		lambda lib_calls: cls_module.get_distance_to_parent(lib_calls[0].parent))

	if not calls_per_lib:
		return block

	call_counter = count()
	block.add_line("def init_cls():")
	block.add_line("%s._calls = {}" % cls.name, 1)
	for lib, calls in calls_per_lib:
		distance = cls_module.get_distance_to_parent(lib.parent)
		if distance > 0:
			block.add_line("from %s import _libraries" % ("." * (distance + 1)), 1)
		block.add_line("lib = _libraries['%s']" % lib.name, 1)

		for call, call_num in zip(calls, call_counter):
			if call.returns and isinstance(call.returns.type, Class):
				imp = cls_module.get_node_import(call.returns.type)
				if imp:
					block.add_line("%s as retcls%d" % (imp, call_num), 1)
				else:
					block.add_line("retcls%d = %s" % (call_num, call.returns.type.name), 1)
			block.add_line("call = lib.%s" % call.symbol, 1)
			block.add_line("call.argtypes = [%s]" % ", ".join(chain(
				("ctypes.c_void_p",) if call.parent.name != "__init__" else (),
				(("ctypes.c_void_p" if isinstance(arg.type, Class) else arg.type) for arg in call.args)
			)), 1)
			block.add_line("call.restype = %s" % call.get_return_value_as_ctype(), 1)
			if call.returns and isinstance(call.returns.type, Class):
				block.add_line("call.convert_res = lambda v: retcls%d._from_c(v, %r)\n" %
					(call_num, call.returns.ownership), 1)
			else:
				block.add_line("call.convert_res = lambda v: v", 1)
			block.add_line("%s._calls['%s'] = call\n" % (cls.name, call.symbol), 1)
			block.add_line("")
	block.add_line("init_cls()")

	return block

def export_module(mod, base_dir):
	is_pkg = isinstance(mod, Package)
	name = mod.name if not is_pkg else "__init__"

	block = SourceBlock()

	block.add_line("from __future__ import absolute_import")
	block.add_line("import ctypes")
	block.add_line("")
	if mod.libraries:
		block.add_line("_libraries = {")
		for lib in mod.libraries.values():
			block.add_line("'%s': ctypes.CDLL('%s')," % (lib.name, lib.path), 1)
		block.add_line("}")

	block.add_line("class NoArgument(object): pass")
	for cls in mod.classes.values():
		block.add_block(export_class(cls))

	for cls in mod.classes.values():
		block.add_block(export_class_setup(cls))

	with open(os.path.join(base_dir, "%s.py" % name), 'w') as f:
		f.write(block.as_text())

def export_package(pkg, base_dir):
	base_dir = os.path.join(base_dir, pkg.name)
	os.makedirs(base_dir)

	export_module(pkg, base_dir)
	for subpkg in pkg.packages.values():
		export_package(subpkg, base_dir)
	for mod in pkg.modules.values():
		export_module(mod, base_dir)

def export_structure(s, base_dir):
	for pkg in s.packages.values():
		export_package(pkg, base_dir)
	for mod in s.modules.values():
		export_module(mod, base_dir)

