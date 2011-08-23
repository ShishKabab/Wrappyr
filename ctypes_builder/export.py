import os
from collections import defaultdict
from itertools import chain, count, izip_longest
from structure import Package, Class, Method, Member
from utils.str import SourceBlock

class NoCommonArguments(Exception): pass
def get_call_args(f):
	"""
	Return list of calls with the arguments unique to
	each call sorted by length of argument list
	"""

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

	return arg_list

def get_converted_argument(arg, name = None):
	name = name or arg.name
	if isinstance(arg.type, Class):
		return "%s._inst" % name
	else:
		return "%s(%s)" % (arg.type, name)

def get_converted_argument_list(call, arg_names = ()):
	pass_inst = isinstance(call.parent, (Method, Member))
	pass_inst = pass_inst and call.parent.name != "__init__"
	pass_inst = pass_inst and not call.parent.is_static()

	l = [get_converted_argument(arg, name)
		 for arg, name in izip_longest(call.args, arg_names)]
	if pass_inst:
		l.insert(0, "self._inst")
	return ", ".join(l)

def get_calls_per_library(calls):
	calls_per_lib = defaultdict(list)
	for call in calls:
		mod = call.get_closest_parent_module()
		lib = mod.find_library(call.library)
		calls_per_lib[lib].append(call)

	return calls_per_lib.items()

def get_call_key(call, library = None):
	"""
	Since all calls will be stored in a dict, we need a consistent way to
	determine the key for a given call.
	"""
	library = library or call.get_library()

	return "{library.name}_{call.symbol}".format(call = call, library = library)

def get_call(call):
	if isinstance(call.parent, Method):
		register = "self._calls"
	else:
		register = "_calls"

	return "%s['%s']" % (register, get_call_key(call))

def sort_methods(key):
	def inner(left, right):
		left = key(left)
		right = key(right)

		if "__init__" in (left, right):
			return -1 if left == "__init__" else 1
		if left.startswith("__") ^ right.startswith("__"):
			return -1 if left.startswith("__") else 1
		return cmp(left, right)

	return inner

def export_function_signature(f, call_args = None):
	is_static = isinstance(f, Method) and f.is_static()
	if not f.raw:
		args = ['self'] if not is_static else []
		args += get_argument_list(call_args)
	else:
		args = f.ops[0].args

	block = SourceBlock()
	if is_static:
		block.add_line("@staticmethod")
	block.add_line("def %s(%s):" % (f.name, ", ".join(args)))

	return block

def export_call(call, result_name = "", arg_names = ()):
	if result_name:
		action = "{result_name} = call({args})"
	else:
		action = "call({args})"

	block = SourceBlock()
	block.add_line("call = " + get_call(call))
	block.add_line(action.format(
		result_name = result_name,
		args = get_converted_argument_list(call, arg_names)
	))
	if result_name:
		block.add_line("{0} = call.convert_res({0})".format(result_name))

	return block

def export_calls(f, result_name = "", call_args = None):
	block = SourceBlock()

	call_args = call_args or get_call_args(f)

	if len(call_args) > 1:
		call, args = call_args[-1]
		block.add_line("if %s:" % " and ".join(
			"%s != NoArgument" % arg.name for arg in args))
		block.add_block(export_call(call, result_name), 1)
	for call, args in reversed(call_args[1:-1]):
		block.add_line("elif %s:" % " and ".join(
			"%s != NoArgument" % arg.name for arg in args))
		block.add_block(export_call(call, result_name), 1)
	if len(call_args) > 1:
		block.add_line("else:")
	block.add_block(export_call(call_args[0][0], result_name),
					int(len(call_args) > 1))

	return block

def export_method(cls, method):
	block = SourceBlock()

	if not method.raw:
		call_args = get_call_args(method)

		keep_result = (method.name == "__init__" or method.returns_anything())
		keep_result = "result" if keep_result else ""
		block.add_block(export_function_signature(method, call_args))
		block.add_block(export_calls(method, keep_result, call_args), 1)

		if method.name == "__init__":
			block.add_line("self._inst = result", 1)
			block.add_line("self._ownership = True", 1)
		if method.returns_anything():
			block.add_line("return result", 1)
	else:
		block.add_block(export_function_signature(method))
		block.add_block(method.ops[0].get_code_block(), 1)

	return block

def export_member(cls, member):
	block = SourceBlock()

	if member.getter:
		getter = member.getter
		getter_name = "__get_%s" % member.name
		op = getter.ops[0]

		block.add_line("def %s(self):" % getter_name)
		if getter.raw:
			block.add_block(op.get_code_block(), 1)
		else:
			block.add_block(export_call(op, "result"), 1)
			block.add_line("return result", 1)

	if member.setter:
		setter = member.setter
		setter_name = "__set_%s" % member.name
		op = setter.ops[0]

		block.add_line("def %s(self, v):" % setter_name)
		if setter.raw:
			block.add_block(op.get_code_block(), 1)
		else:
			block.add_block(export_call(op, arg_names = ('v',)), 1)

	prop = "property(%s, %s)" % (
		getter_name if member.getter else "None",
		setter_name if member.setter else "None",
	)
	block.add_line("%s = %s" % (member.name, prop))
	if member.getter:
		block.add_line("del " + getter_name)
	if member.setter:
		block.add_line("del " + setter_name)

	return block

def export_class(cls):
	members = []
	for method in sorted(cls.methods.values(),
						 cmp = sort_methods(lambda method: method.name)):
		members.append(export_method(cls, method))
	for member in sorted(cls.members.values(), key = lambda member: member.name):
		members.append(export_member(cls, member))

	from_c = SourceBlock()
	from_c.add_line("@staticmethod")
	from_c.add_line("def _from_c(inst, ownership = False):")
	from_c.add_line("cls = %s.__new__(%s)" % (cls.name, cls.name), 1)
	from_c.add_line("cls._inst = inst", 1)
	from_c.add_line("cls._ownership = ownership", 1)
	from_c.add_line("return cls", 1)
	members.append(from_c)

	block = SourceBlock()
	block.add_line("class %s(object):" % cls.name)
	block.add_block(SourceBlock("").join(members, 1))
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
			# Import return class or just assign it to the right variable
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
			block.add_line("%s._calls['%s'] = call\n" % (cls.name, get_call_key(call)), 1)
			block.add_line("")
	block.add_line("init_cls()")

	return block

def export_module(mod, base_dir):
	is_pkg = isinstance(mod, Package)
	name = mod.name if not is_pkg else "__init__"

	blocks = []

	block = SourceBlock()
	block.add_line("from __future__ import absolute_import")
	block.add_line("import ctypes")
	blocks.append(block)

	if mod.libraries:
		block = SourceBlock()
		block.add_line("_libraries = {")
		for lib in mod.libraries.values():
			block.add_line("'%s': ctypes.CDLL('%s')," % (lib.name, lib.path), 1)
		block.add_line("}")
		blocks.append(block)

	blocks.append(SourceBlock("class NoArgument(object): pass"))
	for cls in mod.classes.values():
		blocks.append(export_class(cls))

	for cls in mod.classes.values():
		blocks.append(export_class_setup(cls))

	block = SourceBlock("").join(blocks)
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

