import os
from collections import defaultdict
from itertools import chain, count, izip_longest
from wrappyr.ctypes_api_builder.structure import PointerType
from wrappyr.ctypes_api_builder.structure import Package, Class, Method, Member
from wrappyr.utils.str import SourceBlock

class NoCommonArguments(Exception): pass
class UnsupportedPointerType(Exception):
	def __init__(self, pointer):
			types = ('array', 'reference', 'outparam')
			types = tuple(('an ' + i) for i in types if getattr(pointer, i))
			msg = "A pointer which is " + " and ".join(types)

			Exception.__init__(msg)

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

	if len(call_args) > 1:
		first_call = True
		for call, args in call_args:
			for arg in args:
				arg = arg.name
				if not first_call:
					arg += " = wrappyr.runtime.NoArgument"
				arg_list.append(arg)
			first_call = False
	else:
		for arg in call_args[0][1]:
			arg_str = arg.name
			if arg.default:
				arg_str += " = " + arg.default
			arg_list.append(arg_str)

	return arg_list

def get_converted_argument(arg, name = None):
	name = name or arg.name
	if isinstance(arg.type, Class):
		return "%s._inst" % name
	elif isinstance(arg.type, PointerType):
		return "%s.ptr" % name
	elif arg.name == "vtable": # TODO: Remove hack!
		return "ctypes.pointer(%s)" % name
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
		register = "%s._calls" % call.get_closest_parent_of_type(Class).name
	else:
		register = "_calls"

	return "%s['%s']" % (register, get_call_key(call))

def get_node_import(module, node, result_name):
	imp = module.get_node_import(node)
	if imp:
		imp = "%s as %s" % (imp, result_name)
	else:
		imp = "%s = %s" % (result_name, node.name)
	return imp

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

def export_library_import(module, library, result_name):
	block = SourceBlock()

	distance = module.get_distance_to_parent(library.parent)
	if distance > 0:
		block.add_line("from %s import _libraries" % ("." * (distance + 1)))
	block.add_line("%s = _libraries['%s']" % (result_name, library.name))

	return block

def export_function_signature(f, call_args = None):
	takes_self = isinstance(f, Method) and f.takes_self_argument()
	if not f.raw:
		args = ['self'] if takes_self else []
		args += get_argument_list(call_args)
	else:
		args = f.ops[0].args

	block = SourceBlock()
	if isinstance(f, Method) and f.is_static():
		block.add_line("@staticmethod")
	block.add_line("def %s(%s):" % (f.name, ", ".join(args)))

	return block

def export_type_check(name, type, type_var):
	block = SourceBlock()

	if isinstance(type, PointerType):
		pointee_type = type.type

		if type.outparam:
			if type.reference:
				raise UnsupportedPointerType(type)
			elif type.array:
				raise UnsupportedPointerType(type)
			else:
				raise UnsupportedPointerType(type)
		elif type.array:
			if type.reference:
				raise UnsupportedPointerType(type)

			if isinstance(pointee_type, Class):
				check = ("if not isinstance({0}, wrappyr.runtime.CArray) "
						 "or not issubclass({0}.cls, {2}):")
			else:
				check = ("if not issubclass({0}, {1}):")

			error = ("\"Expected array of '{0}' type for '{1}', "
				"got '%s'\" % {1}.__class__.__name__")
			error = error.format(pointee_type.name, name)

			block.add_line(check.format(name, pointee_type, type_var))
			block.add_line("raise TypeError(%s)" % error, 1)
		else:
			raise UnsupportedPointerType(type)
	elif isinstance(type, Class):
		error = ("\"Expected '{0}' type for '{1}', "
			"got '%s'\" % {1}.__class__.__name__")
		error = error.format(type.name, name)

		block.add_line("if not isinstance(%s, %s):" % (name, type_var))
		block.add_line("raise TypeError(%s)" % error, 1)

	return block

def export_type_checks_for_call(call, call_var = "call"):
	block = SourceBlock()
	for arg, num in zip(call.args, count()):
		type_var = "%s.arg_classes[%d]" % (call_var, num)
		type_check = export_type_check(arg.name, arg.type, type_var)
		block.add_block(type_check)

	return block

def export_call(call, result_name = "", arg_names = (),
				export_type_checks = True, call_var = None):
	if result_name:
		action = "{result_name} = call({args})"
	else:
		action = "call({args})"

	block = SourceBlock()
	if not call_var:
		call_var = "call"
		block.add_line("%s = %s" % (call_var, get_call(call)))
	if export_type_checks:
		block.add_block(export_type_checks_for_call(call))
	block.add_line(action.format(
		result_name = result_name,
		args = get_converted_argument_list(call, arg_names)
	))
	if not result_name or not call.returns:
		return block

	if isinstance(call.returns.type, Class):
		conversion = "{0} = {1}.res_cls._from_c({0}, {2})"
		conversion = conversion.format(result_name, call_var,
									   repr(call.returns.ownership))
	elif isinstance(call.returns, PointerType):
		conversion = ""
	else:
		conversion = ""

	if conversion:
		block.add_line(conversion)

	return block

def export_calls(f, result_name = "", call_args = None):
	block = SourceBlock()

	call_args = call_args or get_call_args(f)

	if len(call_args) > 1:
		call, args = call_args[-1]
		block.add_line("if %s:" % " and ".join(
			"%s != wrappyr.runtime.NoArgument" % arg.name for arg in args))
		block.add_block(export_call(call, result_name), 1)
	for call, args in reversed(call_args[1:-1]):
		block.add_line("elif %s:" % " and ".join(
			"%s != wrappyr.runtime.NoArgument" % arg.name for arg in args))
		block.add_block(export_call(call, result_name), 1)
	if len(call_args) > 1:
		block.add_line("else:")
	block.add_block(export_call(call_args[0][0], result_name),
					int(len(call_args) > 1))

	return block

def export_constructor(cls):
	block = SourceBlock()
	vtable = cls.vtable
	constructor = cls.methods.get('__init__')
	call_args = get_call_args(constructor) if constructor and not constructor.raw else None

	if constructor:
		if vtable:
			block.add_block(export_function_signature(constructor, call_args))
			block.add_line("if type(self) == %s:" % cls.name, 1)
			if not constructor.raw:
				block.add_block(export_calls(constructor, 'inst', call_args), 2)
			else:
				block.add_block(constructor.ops[0].get_code_block(), 2)
			block.add_line("else:", 1)

			args = [arg.name for call, args in call_args for arg in args]
			args = ["self", "self._vtable_"] + args
			args = ", ".join(args)

			block.add_line("inst = self.__newinherited__(%s)" % args, 2)
		else:
			block.add_block(export_method(cls, constructor, 'inst'))
	elif vtable:
		newinherited = cls.methods['__newinherited__']
		args = newinherited.ops[0].args
		args = args[2:] # First two arguments are obj and vtable
		args = [arg.name for arg in args]

		sigargs = ["self"] + args
		block.add_line("def __init__(%s):" % ", ".join(sigargs))

		args = ["self", "self._vtable_"] + args
		block.add_line("inst = self.__newinherited__(%s)" % ", ".join(args), 1)
	else:
		return block
	
	block.add_line("self._inst = inst", 1)
	block.add_line("self._ownership = True", 1)

	return block

def export_method(cls, method, result_name = ""):
	"""
	Exports method and stores result in result_name variable in generated code
	if result_name is given. If it is not given, the result will be returned.
	"""

	block = SourceBlock()

	if not method.raw:
		call_args = get_call_args(method)

		if not result_name:
			result_name = (method.name == "__init__" or method.returns_anything())
			result_name = "result" if result_name else ""
			return_result = True
		else:
			return_result = False
		block.add_block(export_function_signature(method, call_args))
		block.add_block(export_calls(method, result_name, call_args), 1)

		if return_result and method.returns_anything():
			block.add_line("return " + result_name, 1)
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
			type = op.args[0].type
			block.add_line("call = " + get_call(op), 1)
			if isinstance(type, (Class, PointerType)):
				check = export_type_check('v', type, "call.arg_classes[0]")
				block.add_block(check, 1)

			call = export_call(op, arg_names = ('v',),
							   export_type_checks = False,
							   call_var = "call")
			block.add_block(call, 1)

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
	if cls.vtable:
		members.append(SourceBlock("_polymorphism_info_ = wrappyr.runtime.PolymorphismInfo()"))

	constructor = export_constructor(cls)
	if constructor:
		members.append(constructor)

	for method in sorted(cls.methods.values(),
						 cmp = sort_methods(lambda method: method.name)):
		if method.name != '__init__':
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
	block.add_line("class %s(wrappyr.runtime.CPPClass):" % cls.name)
	block.add_block(SourceBlock("").join(members, 1))
	return block

def export_call_setup(call, result_name, lib, tmp_suffix = ""):
	tmp_suffix = str(tmp_suffix)

	block = SourceBlock()
	parent_module = call.get_closest_parent_module()

	store_res_cls = call.returns and isinstance(call.returns.type, Class)
	if store_res_cls:
		res_cls = call.returns.type
		res_cls = get_node_import(parent_module, res_cls, "res_cls")
		block.add_line(res_cls)
	result_ctype = call.get_return_value_as_ctype()

	argtypes = []
	if call.parent.takes_this_pointer():
		argtypes.append("ctypes.c_void_p")
#	elif call.parent.name == "__newinherited__":
#		argtypes += ["ctypes.c_void_p", "ctypes.c_void_p"]
	for arg in call.args:
		arg_type = arg.type
		if isinstance(arg_type, Class):
			argtypes.append("ctypes.c_void_p")
		elif isinstance(arg_type, PointerType):
			argtypes.append(arg_type.get_as_ctype())
		else:
			argtypes.append(arg_type)

	arg_classes = []
	for arg, num in zip(call.args, count()):
		if not isinstance(arg.type, (Class, PointerType)):
			arg_classes.append("None")
			continue

		if isinstance(arg.type, Class):
			arg_type = arg.type
		else:
			arg_type =  arg.type.type
		arg_cls_var = "arg_cls%d" % num
		imp = get_node_import(parent_module, arg_type, arg_cls_var)
		block.add_line(imp)
		arg_classes.append(arg_cls_var)

	block.add_line("%s = %s.%s" % (result_name, lib, call.symbol))
	block.add_line("%s.arg_classes = [%s]" % (result_name,
											  ", ".join(arg_classes)))
	block.add_line("%s.argtypes = [%s]" % (result_name, ", ".join(argtypes)))
	block.add_line("%s.restype = %s" % (result_name, result_ctype))
	if store_res_cls:
		block.add_line("%s.res_cls = res_cls" % result_name)

#	if call.returns and isinstance(call.returns.type, Class):
#		block.add_line("call.convert_res = lambda v: res_cls%s._from_c(v, %r)\n" %
#			(tmp_suffix, call.returns.ownership), 1)
#	else:
#		block.add_line("call.convert_res = lambda v: v", 1)

	return block

def export_overridable_setup(cls, overridable, polyinfo_var = "polyinfo"):
	block = SourceBlock()
	parent_module = cls.get_closest_parent_module()

	argtypes = []
	for arg in overridable.args:
		if isinstance(arg.type, Class):
			argtypes.append("ctypes.c_void_p")
		elif isinstance(arg.type, PointerType):
			argtypes.append(arg.type.get_as_ctype())
		else:
			argtypes.append(arg.type)

	arg_converters = []
	for i, arg in enumerate(overridable.args):
		arg_type = arg.type
		if isinstance(arg_type, Class):
			arg_cls_var = "arg_cls%d" % i
			imp = get_node_import(parent_module, arg_type, arg_cls_var)
			block.add_line(imp)
			arg_converters.append("%s._from_c" % arg_cls_var)
		else:
			arg_converters.append("None")

	result_ctype = overridable.get_return_value_as_ctype()
	if overridable.returns and isinstance(overridable.returns.type, Class):
		res_cls = "res_cls"
		returns = overridable.returns
		imp = get_node_import(parent_module, returns.type, res_cls)
		block.add_line(imp)
	else:
		res_cls = None

	block.add_line("overridable = wrappyr.runtime.Overridable(%r)" % overridable.name)
	block.add_line("overridable.argtypes = [%s]" % ", ".join(argtypes))
	block.add_line("overridable.arg_converters = [%s]" % ", ".join(arg_converters))
	block.add_line("overridable.restypes = %s" % result_ctype)
	if res_cls:
		block.add_line("overridable.res_cls = %s" % res_cls)
	block.add_line("%s.add_overridable(overridable)" % polyinfo_var)
	return block

def export_vtable_setup(cls):
	blocks = [SourceBlock("polyinfo = %s._polymorphism_info_" % cls.name)]

	vtable = cls.vtable
	for overridable in vtable.overridables:
		blocks.append(export_overridable_setup(cls, overridable))
	blocks.append(SourceBlock("%s._polymorphism_info_ = polyinfo" % cls.name))

	return SourceBlock("").join(blocks)

def export_class_setup(cls):
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

	sort_key = lambda lib_calls: cls_module.get_distance_to_parent(lib_calls[0].parent)
	calls_per_lib = get_calls_per_library(calls)
	calls_per_lib = sorted(calls_per_lib, key = sort_key)

	blocks = []

	call_counter = count()
	for lib, calls in calls_per_lib:
		blocks.append(export_library_import(cls_module, lib, "lib"))

		for call, call_num in zip(calls, call_counter):
			block = SourceBlock()
			block.add_block(export_call_setup(call, "call", "lib"))
			block.add_line("%s._calls['%s'] = call" % (cls.name,
													   get_call_key(call)))
			blocks.append(block)
	if cls.vtable:
		blocks.append(export_vtable_setup(cls))

	block = SourceBlock()
	block.add_line("def init_cls():")
	block.add_line("%s._calls = {}" % cls.name, 1)
	block.add_line("", 1)
	block.add_block(SourceBlock("").join(blocks, 1))
	block.add_line("init_cls()")

	return block

def export_module(mod, base_dir):
	is_pkg = isinstance(mod, Package)
	name = mod.name if not is_pkg else "__init__"

	blocks = []

	block = SourceBlock()
	block.add_line("from __future__ import absolute_import")
	block.add_line("import ctypes")
	block.add_line("import functools")
	block.add_line("import wrappyr.runtime")
	blocks.append(block)

	if mod.libraries:
		block = SourceBlock()
		block.add_line("_libraries = {")
		for lib in mod.libraries.values():
			block.add_line("'%s': ctypes.CDLL('%s')," % (lib.name, lib.path), 1)
		block.add_line("}")
		blocks.append(block)

	classes = mod.classes.values()
	for cls in classes:
		blocks.append(export_class(cls))
	for cls in classes:
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

