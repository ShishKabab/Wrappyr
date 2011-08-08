import os
from collections import defaultdict
from itertools import chain
from structure import Package, Class, Method, Member

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

def write_module(mod, base_dir):
	is_pkg = isinstance(mod, Package)
	name = mod.name if not is_pkg else "__init__"

	with open(os.path.join(base_dir, "%s.py" % name), 'w') as f:
		f.write("from __future__ import absolute_import\nimport ctypes\n\n")

		if mod.libraries:
			f.write("_libraries = {%s}\n" % ",".join(
				"\n\t'%s': ctypes.CDLL('%s')\n\n" % (lib.name, lib.path) for lib in mod.libraries.values()
			))

		f.write("class NoArgument(object): pass\n")
		for cls in mod.classes.values():
			f.write("\nclass %s(object):\n" % cls.name)
			for method in cls.methods.values():
				#print "%s.%s" % (cls.name, method.name)

				if method.name == "__init__":
					action = "self._inst = {callstr}"
				else:
					action = "return self._calls['{call.symbol}'].convert_res({callstr})"

				if not method.raw:
					call_args = get_call_args(method)
					first_call = call_args[0][0]
					arg_list = get_argument_list(call_args)

					f.write("\tdef %s(%s):\n" % (method.name, 'self, ' + arg_list if arg_list else 'self'))
					if len(call_args) > 1:
						for call, args in reversed(call_args[1:]):
							callstr = "self._calls['%s'](%s)" % (
								call.symbol, get_converted_argument_list(call)
							)
							f.write("\t\tif %s:\n" % " and ".join("%s != NoArgument" % arg.name for arg in args))
							f.write("\t\t\t%s\n" % action.format(call = call, callstr = callstr))

						callstr = "self._calls['%s'](%s)" % (
							first_call.symbol, get_converted_argument_list(first_call)
						)
						f.write("\t\telse:\n\t\t\t%s\n" % action.format(call = first_call, callstr = callstr))
					else:
						callstr = "self._calls['%s'](%s)" % (
							first_call.symbol, get_converted_argument_list(first_call)
						)
						f.write("\t\t%s\n" % action.format(call = first_call, callstr = callstr))
					if method.name == "__init__":
						f.write("\t\tself._ownership = True\n")
			for member in cls.members.values():
				f.write("\t%s = property(\n" % member.name)
				if member.getter:
					getter = member.getter
					op = getter.ops[0]
					if not getter.raw:
						f.write(("\t\tlambda self: self._calls['{call.symbol}']" +
							".convert_res(self._calls['{call.symbol}'](self._inst)),\n").format(
								call = op))
					else:
						f.write("\t\tlambda self: %s,\n" % op.code)
				else:
						f.write("\t\tNone,\n")
				if member.setter:
					setter = member.setter
					op = setter.ops[0]
					if not setter.raw:
						f.write(("\t\tlambda self, v: self._calls['{call.symbol}']" +
							".convert_res(self._calls['{call.symbol}'](self._inst, {arg}))\n").format(
								call = op, arg = get_converted_argument(op.args[0], 'v')))
					else:
						f.write("\t\tlambda self: %s\n" % op.code)
				else:
						f.write("\t\tNone\n")
				f.write("\t)\n")

			f.write("\t@staticmethod\n\tdef _from_c(inst, ownership = False):\n")
			f.write("\t\tcls = %s.__new__(%s)\n" % ((cls.name,) * 2))
			f.write("\t\tcls._inst = inst\n")
			f.write("\t\tcls._ownership = ownership\n")
			f.write("\t\treturn cls\n")

		for cls in mod.classes.values():
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
				continue

			calls_processed = 0
			f.write("def init_cls():\n")
			f.write("\t%s._calls = {}\n\n" % cls.name)
			for lib, calls in calls_per_lib:
				distance = cls_module.get_distance_to_parent(lib.parent)
				if distance > 0:
					f.write("\tfrom %s import _libraries\n" % ("." * (distance + 1)))
				f.write("\tlib = _libraries['%s']\n\n" % lib.name)

				for call in calls:
					if call.returns and isinstance(call.returns.type, Class):
						imp = cls_module.get_node_import(call.returns.type)
						if imp:
							f.write("\t%s as retcls%d\n" % (imp, calls_processed))
						else:
							f.write("\tretcls%d = %s\n" % (calls_processed, call.returns.type.name))
					f.write("\tcall = lib.%s\n" % call.symbol)
					f.write("\tcall.argtypes = [%s]\n" % ", ".join(chain(
						("ctypes.c_void_p",) if call.parent.name != "__init__" else (),
						(("ctypes.c_void_p" if isinstance(arg.type, Class) else arg.type) for arg in call.args)
					)))
					f.write("\tcall.restype = %s\n" % call.get_return_value_as_ctype())
					if call.returns and isinstance(call.returns.type, Class):
						f.write("\tcall.convert_res = lambda v: retcls%d._from_c(v, %r)\n" %
							(calls_processed, call.returns.ownership))
					else:
						f.write("\tcall.convert_res = lambda v: v\n")
					f.write("\t%s._calls['%s'] = call\n" % (cls.name, call.symbol))
					f.write("\n")

					calls_processed += 1
			f.write("init_cls()\n\n")

def write_package(pkg, base_dir):
	base_dir = os.path.join(base_dir, pkg.name)
	os.makedirs(base_dir)

	write_module(pkg, base_dir)
	for subpkg in pkg.packages.values():
		write_package(subpkg, base_dir)
	for mod in pkg.modules.values():
		write_module(mod, base_dir)

def export_structure(s, base_dir):
	for pkg in s.packages.values():
		write_package(pkg, base_dir)
	for mod in s.modules.values():
		write_module(mod, base_dir)

