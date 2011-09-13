from itertools import chain, count

from utils.str import SourceBlock, as_camelcase
from structure import Class, Function

class ExportFilter(object):
	def __init__(self, importer):
		self.importer = importer

	def filter_namespace(self, ns, **opts):
		return True

	def filter_class(self, cls, **opts):
		return cls.is_valid(self.importer) and \
			cls.access in ('unknown', 'public')

	def filter_method(self, cls, method, **opts):
		return any(self.filter_method_signature(cls, sig)
			for sig in method)

	def filter_method_signature(self, cls, signature, **opts):
		return (self.filter_function(signature)
			# Export only public methods
			and (signature.access == 'public' or
				 (opts.get("inherited") == True and signature.access == "protected"))
			# Static methods are not supported yet
			and not signature.is_static)

	def filter_member(self, cls, member, **opts):
		type = member.type

		return (# Export only public members
			member.access == 'public'
			# Some member names are empty in Clang XML, find out why
			and member.name
			# We don't know how to handle pointers other
			# than C++ object pointers
			# and not (type.type in ('builtin', 'enum') and type.pointers)
			#and (not type.id or self.importer.nodes.get(type.id))

			# If this type is a struct or class, the class
			# must be declared
			and (type.type != 'record' or self.importer.nodes.get(type.id))
			# We don't know how to handle multi-dimensional pointers
			and type.pointers <= 1
			# The type must be something we can handle
			and type.valid)

	def filter_function(self, f, **opts):
		return (
			# Operator overload is not supported
			not f.name.startswith('operator')
			#and all(not arg.type.id or self.importer.nodes.get(arg.type.id) for arg in f.args)
			#and (not f.returns.id or self.importer.nodes.get(f.returns.id))

			# We must be able to handle all argument and
			# return value types
			and f.valid)

class ClangExport(object):
	@staticmethod
	def iletters():
		return (chr(i) for i in xrange(ord('a'), ord('m')))

	def get_filter(self, importer):
		return ExportFilter(importer)

	def symbol_for_constructor(self, cls, cls_name_underscore, constructor = None):
		return "%s__Create%s" % (
			cls_name_underscore,
			(cls.constructors.index(constructor) if len(cls.constructors) > 1 else '')
		)

	def symbol_for_array_constructor(self, cls, cls_name_underscore):
		return "%s__CreateArray" % (
			cls_name_underscore
		)

	def symbol_for_destructor(self, cls, cls_name_underscore, destructor):
		return "%s__Destroy" % cls_name_underscore

	def symbol_for_array_destructor(self, cls, cls_name_underscore):
		return "%s__DestroyArray" % cls_name_underscore

	def symbol_for_class_size(self, cls, cls_name_underscore):
		return "%s__Size" % cls_name_underscore

	def symbol_for_method_signature(self, cls, cls_name_underscore, method, signature):
		return "%s_%s%s" % (
			cls_name_underscore,
			signature.name,
			(method.index(signature) if len(method) > 1 else '')
		)

	def symbols_for_member(self, cls, cls_name_underscore, member):
		camelcased = as_camelcase(member.name)
		return (
			"%s__Get_%s" % (cls_name_underscore, camelcased),
			"%s__Set_%s" % (cls_name_underscore, camelcased)
		)

	def symbol_for_array_element(self, cls, full_name_underscore):
		return "%s__ArrayElement" % full_name_underscore

	def symbol_for_inheritance_constructor(self, cls, cls_name_underscore,
										   constructor):
		return "%s__CreateInherited%s" % (
			cls_name_underscore,
			(cls.constructors.index(constructor) if len(cls.constructors) > 1 else '')
		)

	def setup(self, importer):
		self.importer = importer
		self.filter = self.get_filter(importer)

	def export_namespace(self, ns):
		block = SourceBlock()
		for node in ns.nodes:
			if isinstance(node, Class):
				if self.filter.filter_class(node):
					block.add_block(self.export_class(node))
		for child in ns.children.values():
			block.add_block(self.export_namespace(child))

		return block


class HeaderExport(ClangExport):
	def export_constructors(self, cls, full_name_underscore):
		block = SourceBlock()

		if cls.constructors:
			for constructor in cls.constructors:
				if not self.filter.filter_method_signature(cls, constructor):
					continue
				block.add_line("void* %s(%s);" % (
					self.symbol_for_constructor(cls, full_name_underscore, constructor),
					constructor.args_as_string()
				))
		else:
			block.add_line("void* %s();" % (
				self.symbol_for_constructor(cls, full_name_underscore),
			))

		# Array
		if cls.is_default_constructable():
			block.add_line("void* %s(int);" % self.symbol_for_array_constructor(
				cls, full_name_underscore
			))

		return block

	def export_destructors(self, cls, full_name_underscore):
		block = SourceBlock()
		block.add_line("void %s(void*);" % self.symbol_for_destructor(
			cls, full_name_underscore, cls.destructor))
		block.add_line("void %s(void*);" % self.symbol_for_array_destructor(
			cls, full_name_underscore
		))
		return block

	def export_methods(self, cls, full_name_underscore):
		block = SourceBlock()

		for method in cls.methods.values():
			for i, signature in enumerate(method):
				if not self.filter.filter_method_signature(cls, signature):
						continue

				returns = signature.returns.as_string()
				args = "void*%s%s" % (
					", " if signature.args else '',
					signature.args_as_string() if signature.args else ''
				)
				symbol = self.symbol_for_method_signature(cls,
														  full_name_underscore,
														  method, signature)
				block.add_line("%s %s(%s);" % (
					returns,
					symbol,
					args
				))

		return block

	def export_members(self, cls, full_name_underscore):
		block = SourceBlock()

		for member in cls.members:
			if not self.filter.filter_member(cls, member):
				continue

			returns = member.type.as_string()
			getter, setter = self.symbols_for_member(cls, full_name_underscore,
													 member)

			block.add_line("%s %s(void*);" % (
				returns,
				getter
			))
			block.add_line("void %s(void*, %s);" % (
				setter,
				member.type.as_string(),
			))
		return block

	def export_inheritance_class(self, cls, full_name_underscore):
		block = SourceBlock()
		if cls.constructors:
			for constructor in cls.constructors:
				if not self.filter.filter_method_signature(cls, constructor, inherited = True):
					continue

				args = constructor.args_as_string()
				if args:
					args = ", " + args
				symbol = self.symbol_for_inheritance_constructor(cls, full_name_underscore,
													 constructor)
				block.add_line("void* %s(void*, void*%s);" % (symbol, args))
		else:
			block.add_line("void* %s(void*, void*);" % (
				self.symbol_for_inheritance_constructor(cls, full_name_underscore, None),
			))
		return block

	def export_class(self, cls):
		full_name_underscore = cls.get_full_name("__")
		block = SourceBlock()
		block.add_line("")
		block.add_line("//")
		block.add_line("// Begin class '%s'" % cls.get_full_name())
		block.add_line("//")

		# Constructor
		if not cls.is_abstract(self.importer):
			block.add_block(self.export_constructors(cls, full_name_underscore))

		# Destructor
		if not cls.destructor or cls.destructor.access == 'public':
			block.add_block(self.export_destructors(cls, full_name_underscore))

		# Class size
		block.add_line("unsigned int %s();" % self.symbol_for_class_size(
			cls, full_name_underscore))

		# Get array element
		block.add_line("void* %s(void*, unsigned int);" % self.symbol_for_array_element(
			cls, full_name_underscore
		))

		# Methods
		block.add_block(self.export_methods(cls, full_name_underscore))

		# Members
		block.add_block(self.export_members(cls, full_name_underscore))

		# C++ class to inherit from a virtual base
		if cls.dynamic:
			inheritance_class = self.export_inheritance_class(
				cls,
				full_name_underscore
			)
			block.add_block(inheritance_class)

		return block

	def export(self, importer, path):
		self.setup(importer)

		with open(path, 'w') as f:
			f.write('extern "C" {\n')
			f.write(self.export_namespace(importer.root_namespace)
				.as_text())
			f.write('\n}\n')

class SourceExport(ClangExport):
	letters = tuple(ClangExport.iletters())

	def get_includes(self):
		pass

	def args_as_params(self, f):
		args = []
		for arg, letter in zip(f.args, self.letters):
			args.append("%s((%s)%s)" % (
				"*" * (arg.type.refs + int(arg.type.is_cpp_only())),
				arg.type.as_string(False),
				letter
			))

		return ", ".join(args)

	def export_constructors(self, cls, full_name, full_name_underscore):
		block = SourceBlock()
		if cls.constructors:
			for constructor in cls.constructors:
				if not self.filter.filter_method_signature(cls, constructor):
					continue
				block.add_line("void* %s(%s){" % (
					self.symbol_for_constructor(cls, full_name_underscore, constructor),
					constructor.args_as_string(self.letters)
				))
				block.add_line("return new %s(%s);" % (
					full_name,
					self.args_as_params(constructor))
				, 1)
				block.add_line("}")
		else:
			block.add_line("void* %s(){" % (
				self.symbol_for_constructor(cls, full_name_underscore),
			))
			block.add_line("return new %s;" % full_name, 1)
			block.add_line("}")

		# Array
		if cls.is_default_constructable():
			block.add_line("void* %s(int n){" % self.symbol_for_array_constructor(
				cls, full_name_underscore
			))
			block.add_line("return new %s[n];" % full_name, 1)
			block.add_line("}")

		return block

	def export_destructors(self, cls, full_name, full_name_underscore):
		block = SourceBlock()

		block.add_line("void %s(void* cls){" % self.symbol_for_destructor(
			cls, full_name_underscore, cls.destructor))
		block.add_line("delete (%s*)cls;" % full_name, 1)
		block.add_line("}")
		block.add_line("void %s(void* arr){" % self.symbol_for_array_destructor(
			cls, full_name_underscore
		))
		block.add_line("delete[] (%s*)arr;" % full_name, 1)
		block.add_line("}")

		return block

	def export_methods(self, cls, full_name, full_name_underscore):
		block = SourceBlock()

		for method in cls.methods.values():
			for i, signature in enumerate(method):
				if not self.filter.filter_method_signature(cls, signature):
					continue

				returns = signature.returns.as_string()
				args = "void* cls%s%s" % (
					", " if signature.args else '',
					signature.args_as_string(self.letters) if signature.args else ''
				)
				block.add_line("%s %s(%s){" % (
					returns,
					self.symbol_for_method_signature(cls, full_name_underscore, method, signature),
					args
				))

				returns = signature.returns
				stmt = "((%s*)cls)->%s(%s)"
				stmt = stmt % (full_name, signature.name,
							   self.args_as_params(signature))
				if returns.refs:
					stmt = "&" + stmt
				if returns.const and not returns.is_cpp_only():
					args = (returns.name,
							"*" * (returns.refs + returns.pointers),
							stmt)
					stmt = "const_cast<%s%s>(%s)" % args
				if returns.is_cpp_only():
					stmt = "new %s(%s)" % (returns.name, stmt)
				if signature.returns_anything():
					stmt = "return " + stmt
				stmt += ";"

				block.add_line(stmt, 1)
				block.add_line("}")

		return block

	def export_members(self, cls, full_name, full_name_underscore):
		block = SourceBlock()

		for member in cls.members:
			if not self.filter.filter_member(cls, member):
				continue

			getter, setter = self.symbols_for_member(cls, full_name_underscore, member)
			type = member.type

			# Getter
			returns = member.type.as_string()
			block.add_line("%s %s(void* cls){" % (
				returns,
				getter
			))
			block.add_line("return %s%s((%s*)cls)->%s%s;" % (
				("const_cast<%s%s>(" % (type.name, "*" * (type.refs + type.pointers + int(type.is_cpp_only())))
					if type.const else ''),
				'&' if type.is_cpp_only() else '',
				full_name,
				member.name,
				(")" if type.const else ''),
			), 1)
			block.add_line("}")


			# Setter
			block.add_line("void %s(void* cls, %s v){" % (
				setter,
				member.type.as_string(),
			))
			block.add_line("((%s*)cls)->%s = %s((%s%s)v);" % (
				full_name,
				member.name,
				'*' if type.is_cpp_only() else '',
				member.type.name,
				"*" * (type.refs + type.pointers + int(type.is_cpp_only()))
			), 1)
			block.add_line("}")

		return block

	def export_class_vtable(self, full_name_underscore, overridable):
		block = SourceBlock()

		counter = count()
		block.add_line("struct %s__VTable {" % full_name_underscore)
		for method in overridable:
			for signature, num in zip(method, counter):
				args = (num, signature.name)
				block.add_line("void* f%d; // %s" % args, 1)
		block.add_line("};")

		return block

	def export_inherited_constructors(self, cls, full_name, full_name_underscore):
		block = SourceBlock()
		if cls.constructors:
			for constructor in cls.constructors:
				if not self.filter.filter_method_signature(cls, constructor, inherited = True):
					continue

				args = constructor.args_as_string(self.letters, False, False)
				if args:
					args = ", " + args
				block.add_line("%s__Inherited(void* script_obj, void* vtable%s)" % (
					full_name_underscore,
					args
				))
				if args:
					block.add_line(": %s(%s)" % (full_name, self.args_as_params(constructor)), 1)
#					block.add_line("return new %s(%s);" % (
#						full_name,
#						self.args_as_params(constructor))
#					, 1)
				block.add_line("{")
				block.add_line("m_script_obj = script_obj;", 1)
				block.add_line("m_vtable = vtable;", 1)
				block.add_line("}")
		else:
			block.add_line("%s__Inherited(void* script_obj, void* vtable){" % full_name)
#			block.add_line("m_obj = new %s;" % full_name, 1)
			block.add_line("m_script_obj = script_obj;", 1)
			block.add_line("m_vtable = vtable;", 1)
			block.add_line("}")
		return block

	def get_callback_cast(self, f):
		returns = f.returns
		pointers = returns.pointers + returns.refs
		pointers += int(returns.is_cpp_only())
		pointers = "*" * pointers
		returns = returns.name + pointers

		args = ["void*"]
		for arg in f.args:
			arg_type = arg.type
			const = "const " if arg_type.const else ""
			pointers = arg_type.pointers + arg_type.refs
			pointers += int(arg_type.is_cpp_only())
			pointers = "*" * pointers
			args.append(const + arg_type.name + pointers)

		return "(%s (*)(%s))" % (returns, ", ".join(args))

	def export_inherited_methods(self, cls, full_name, full_name_underscore,
								 overridable):
		block = SourceBlock()

		vtable_name = "%s__VTable" % full_name_underscore
		counter = count()
		for method in overridable:
			for signature, num in zip(method, counter):
				returns = signature.returns.as_string(False, False, False)
				args = signature.args_as_string(self.letters, False, False, False)
				const = " const " if signature.is_const else ""
				sig_str = "%s %s(%s)%s" % (returns, signature.name, args, const)

				returns = "return " if signature.returns_anything() else ""
				args_to_parent = ", ".join(self.letters[0:len(signature.args)])
				fptr_cast = self.get_callback_cast(signature)
				deref = "*" if signature.returns.refs or signature.returns.is_cpp_only() else ""
				nearest_implementation = cls.get_class_implementing_signature(self.importer, signature)

				args_to_callback = ["m_script_obj"]
				for arg, letter in zip(signature.args, self.letters):
					arg_type = arg.type
					pointer = int(bool(arg_type.refs or arg_type.is_cpp_only()))
					pointer = "&" * pointer
					args_to_callback.append(pointer + letter)
				args_to_callback = ", ".join(args_to_callback)

				block.add_line("%s{" % sig_str)
				block.add_line("void* fptr = ((%s*)m_vtable)->f%d;" % (vtable_name, num), 1)
				block.add_line("if(fptr)", 1)
				block.add_line("%s%s(%sfptr)(%s);" % (returns, deref, fptr_cast, args_to_callback), 2)
				if nearest_implementation:
					block.add_line("else", 1)
					block.add_line("%s%s::%s(%s);" % (returns, nearest_implementation.name, signature.name, args_to_parent), 2)
				block.add_line("}")
		return block

	def export_inherited_class(self, cls, full_name, full_name_underscore):
		block = SourceBlock()

		overridable = cls.get_overridable_signatures(self.importer)
		if not overridable:
			return block
#		print "====\n= %s\n====" % cls.name
#		print [i.name for method in overridable for i in method]

		vtable = self.export_class_vtable(full_name_underscore, overridable)
		block.add_block(vtable)

		block.add_line("class %s__Inherited : public %s {" % (full_name_underscore, full_name))
		block.add_line("public:", 1)
		block.add_block(self.export_inherited_constructors(cls, full_name, full_name_underscore), 2)
		block.add_block(self.export_inherited_methods(cls, full_name, full_name_underscore, overridable), 2)
		block.add_line("private:", 1)
#		block.add_line("%s* m_obj;" % full_name, 2)
		block.add_line("void* m_script_obj;", 2)
		block.add_line("void* m_vtable;", 2)
		block.add_line("};")

		if cls.constructors:
			for constructor in cls.constructors:
				if not self.filter.filter_method_signature(cls, constructor, inherited = True):
					continue

				args = constructor.args_as_string(self.letters)
				if args:
					args = ", " + args

				params = self.args_as_params(constructor)
				if params:
					params = "script_obj, vtable, " + params
				else:
					params = "script_obj, vtable"

				symbol = self.symbol_for_inheritance_constructor(cls, full_name_underscore,
													 constructor)
				block.add_line("void* %s(void* script_obj, void* vtable%s){" % (symbol, args))
				block.add_line("return new %s__Inherited(%s);" % (full_name_underscore, params), 1)
				block.add_line("}")
		else:
			block.add_line("void* %s(void* script_obj, void* vtable){" % (
				self.symbol_for_inheritance_constructor(cls, full_name_underscore, None),
			))
			block.add_line("return new %s__Inherited(script_obj, vtable);" % full_name_underscore, 1)
			block.add_line("}")

		return block

	def export_class(self, cls):
		full_name = cls.get_full_name()
		full_name_underscore = cls.get_full_name("__")

		block = SourceBlock()
		block.add_line("")
		block.add_line("//")
		block.add_line("// Begin class '%s'" % cls.get_full_name())
		block.add_line("//")

		# Constructor
		if not cls.is_abstract(self.importer):
			constructors = self.export_constructors(cls, full_name,
													full_name_underscore)
			block.add_block(constructors)

		# Destructor
		if not cls.destructor or cls.destructor.access == 'public':
			destructors = self.export_destructors(cls, full_name, full_name_underscore)
			block.add_block(destructors)

		# Class size
		block.add_line("unsigned int %s(){" % self.symbol_for_class_size(
			cls, full_name_underscore))
		block.add_line("return sizeof(%s);" % full_name, 1)
		block.add_line("}")

		# Get array element
		block.add_line("void* %s(void* arr, unsigned int idx){" % self.symbol_for_array_element(
			cls, full_name_underscore
		))
		block.add_line("return &((%s*)arr)[idx];" % full_name, 1)
		block.add_line("}")

		# Methods
		block.add_block(self.export_methods(cls, full_name,
												full_name_underscore))

		# Members
		block.add_block(self.export_members(cls, full_name,
												full_name_underscore))

		# C++ class to inherit from a virtual base
		if cls.dynamic:
			inheritance_class = self.export_inherited_class(
				cls,
				full_name,
				full_name_underscore
			)
			block.add_block(inheritance_class)

		return block

	def export(self, importer, path):
		self.setup(importer)

		with open(path, 'w') as f:
			includes = self.get_includes()
			if includes:
				f.write('%s\n\n' % includes)
			f.write(self.export_namespace(importer.root_namespace)
				.as_text())

class CtypesExport(ClangExport):
	builtin_dict = {
		'bool': 'ctypes.c_ubyte',
		'char': 'ctypes.c_char',
		'wchar_t': 'ctypes.c_wchar',
		'unsigned char': 'ctypes.c_ubyte',
		'short': 'ctypes.c_short',
		'unsigned short': 'ctypes.c_ushort',
		'int': 'ctypes.c_int',
		'unsigned int': 'ctypes.c_uint',
		'long': 'ctypes.c_long',
		'unsigned long': 'ctypes.c_ulong',
		'long long': 'ctypes.c_longlong',
		'unsigned long long': 'ctypes.c_ulonglong',
		'float': 'ctypes.c_float',
		'double': 'ctypes.c_double',
		'long double': 'ctypes.c_longdouble',
	}

	def package_for_namespace(self, ns):
		return ns.name or "exported"

	def export_function(self, f):
		block = SourceBlock()
		if not f.extern_c:
			return block

		block.add_line('<function name="%s">' % f.name)
		block.add_line('</function>')
		return block

	def export_method(self, cls, method):
		block = SourceBlock()
		if not method:
			return block

		first_signature = method[0]
		if first_signature.is_constructor:
			name = "__init__"
		elif first_signature.is_destructor:
			name = "__del__"
		else:
			name = first_signature.name

		block.add_line('<method name="%s">' % name)
		for signature in method:
			if self.filter.filter_method_signature(cls, signature):
				block.add_block(self.export_call(signature, cls, method), 1)
		block.add_line('</method>')

		return block

	def export_constructor(self, cls):
		block = SourceBlock()

		block.add_line('<method name="__init__">')
		for constructor in cls.constructors:
			if self.filter.filter_method_signature:
				block.add_block(self.export_call(constructor, cls), 1)
		block.add_line('</method>')
		
		return block

	def export_call(self, f, cls = None, method = None):
		cls_name_underscore = cls.get_full_name("__")

		if f.is_constructor:
			symbol = self.symbol_for_constructor(
				cls, cls_name_underscore, f)
		elif f.is_destructor:
			symbol = self.symbol_for_destructor(
				cls, cls_name_underscore, f)
		else:
			symbol = self.symbol_for_method_signature(
				cls, cls_name_underscore, method, f)

		returns_nothing = (f.is_constructor or f.is_destructor
			or (f.returns.name == 'void' and not f.returns.pointers))

		block = SourceBlock()
		if returns_nothing and not f.args:
			block.add_line('<call symbol="%s" />' % symbol)
			return block

		block.add_line('<call symbol="%s">' % symbol)
		for arg, letter in zip(f.args, self.iletters()):
			block.add_line('<argument name="%s" type="%s" />' % (
				arg.name or letter,
				self.type_as_ctype(arg.type))
			, 1)
		if not returns_nothing:
			block.add_line('<returns type="%s" ownership="%d" />' % (
				self.type_as_ctype(f.returns),
				int(bool(method and f.returns.is_cpp_only())))
			, 1)

		block.add_line('</call>')

		return block

	def type_as_ctype(self, type):
		if type.type == 'builtin' and not type.refs:
			if type.pointers == 1:
				if type.name == 'void':
					return "ctypes.c_void_p"
				if type.name == 'char':
					return "ctypes.c_char_p"
				if type.name == 'wchar':
					return "ctypes.c_wchar_p"
			if not type.pointers:
				return self.builtin_dict[type.name]
			return "ctypes.c_void_p"
		elif type.type == 'enum':
			return "ctypes.c_uint"
		elif (type.pointers + type.refs) <= 1 and type.type in ('record', 'enum'):
			path = self.package_for_namespace(self.importer.root_namespace)
			path = [path] if path else []
			path += type.name.split("::")

			return ".".join(path)

		raise Exception("Don't know how to export type '%s%s%s'" % (type.name,
			'*' * type.pointers,
			'&' * type.refs))

	def export_destructor(self, cls):
		block = SourceBlock()
		return block

	def export_member(self, cls, member):
		getter, setter = self.symbols_for_member(cls, cls.get_full_name("__"), member)
		type = self.type_as_ctype(member.type)

		block = SourceBlock()
		block.add_line('<member name="%s">' % member.name)

		block.add_line('<getter>', 1)
		block.add_line('<call symbol="%s">' % getter, 2)
		block.add_line('<returns type="%s" />' % type, 3)
		block.add_line('</call>', 2)
		block.add_line('</getter>', 1)

		block.add_line('<setter>', 1)
		block.add_line('<call symbol="%s">' % setter, 2)
		block.add_line('<argument type="%s" />' % type, 3)
		block.add_line('</call>', 2)
		block.add_line('</setter>', 1)

		block.add_line('</member>')
		return block

	def export_array_class_methods(self, cls):
		cls_name_underscore = cls.get_full_name("__")

		block = SourceBlock()

		if not cls.is_abstract(self.importer) and cls.is_default_constructable():
			symbol = self.symbol_for_array_constructor(cls, cls_name_underscore)

			block.add_line('<method name="__newarray__">')
			block.add_line('<call symbol="%s">' % symbol, 1)
			block.add_line('<argument name="size" type="ctypes.c_int" />', 2)
			block.add_line('<returns type="ctypes.c_void_p" />', 2)
			block.add_line('</call>', 1)
			block.add_line('</method>')
		if not cls.destructor or cls.destructor.access == 'public':
			symbol = self.symbol_for_array_destructor(cls, cls_name_underscore)

			block.add_line('<method name="__delarray__">')
			block.add_line('<call symbol="%s">' % symbol, 1)
			block.add_line('<argument name="a" type="ctypes.c_void_p" />', 2)
			block.add_line('</call>', 1)
			block.add_line('</method>')

		symbol = self.symbol_for_array_element(cls, cls_name_underscore)
		block.add_line('<method name="__arrayitem__">')
		block.add_line('<call symbol="%s">' % symbol, 1)
		block.add_line('<argument name="a" type="ctypes.c_void_p" />', 2)
		block.add_line('<argument name="idx" type="ctypes.c_uint" />', 2)
		block.add_line('<returns type="ctypes.c_void_p" />', 2)
		block.add_line('</call>', 1)
		block.add_line('</method>')

		return block

	def export_inherited_constructors(self, cls):
		cls_name_underscore = cls.get_full_name("__")
		block = SourceBlock()

		filter = lambda sig: self.filter.filter_method_signature(cls, sig, inherited = True)
		constructors = [i for i in cls.constructors if filter(i)]
		
		if constructors:
			block.add_line('<method name="__newinherited__">')
			for constructor in constructors:
				symbol = self.symbol_for_inheritance_constructor(
					cls, cls_name_underscore, constructor)
				block.add_line('<call symbol="%s">' % symbol, 1)
				block.add_line('<argument name="obj" type="ctypes.py_object" />', 2)
				block.add_line('<argument name="vtable" type="ctypes.c_void_p" />', 2)
				for arg, letter in zip(constructor.args, self.iletters()):
					arg_type = self.type_as_ctype(arg.type)
					arg_name = arg.name or letter
					
					block.add_line('<argument name="%s" type="%s" />' % (
						arg_name,
						arg_type)
					, 2)
				block.add_line('</call>', 1)
			block.add_line('</method>')
		else:
			symbol = self.symbol_for_inheritance_constructor(
				cls, cls_name_underscore, None)

			block.add_line('<method name="__newinherited__">')
			block.add_line('<call symbol="%s">' % symbol, 1)
			block.add_line('<argument name="obj" type="ctypes.py_object" />', 2)
			block.add_line('<argument name="vtable" type="ctypes.c_void_p" />', 2)
			block.add_line('<returns type="ctypes.c_void_p" />', 2)
			block.add_line('</call>', 1)
			block.add_line('</method>')

		return block

	def export_inherited(self, cls):
		block = SourceBlock()

		overridable = cls.get_overridable_signatures(self.importer)
		if not overridable:
			return block

		block.add_line("<vtable>")
		for method in overridable:
			for signature in method:
				block.add_line('<overridable name="%s">' % signature.name, 1)
				for arg, letter in zip(signature.args, self.iletters()):
					arg_name = arg.name or letter
					arg_type = self.type_as_ctype(arg.type)
					block.add_line('<argument name="%s" type="%s" />' % (
						arg_name,
						arg_type
					), 2)

				returns_nothing = (signature.returns.name == 'void' and
					not signature.returns.pointers)
				if not returns_nothing:
					returns = self.type_as_ctype(signature.returns)
					block.add_line('<returns type="%s" />' % returns, 2)

				block.add_line('</overridable>', 1)
		block.add_line("</vtable>")

		block.add_block(self.export_inherited_constructors(cls))

		return block

	def export_class(self, cls):
#		full_name = cls.get_full_name()
#		full_name_underscore = cls.get_full_name("__")

		block = SourceBlock()
		block.add_line('<class name="%s">' % cls.name)

		if cls.dynamic:
			block.add_block(self.export_inherited(cls), 1)
		if (not cls.is_abstract(self.importer) and cls.constructors
			and self.filter.filter_method(cls, cls.constructors)):
			block.add_block(self.export_constructor(cls), 1)
		if not cls.destructor or cls.destructor.access == 'public':
			block.add_block(self.export_destructor(cls), 1)
		block.add_block(self.export_array_class_methods(cls), 1)

		for method in cls.methods.values():
			if self.filter.filter_method(cls, method):
				block.add_block(self.export_method(cls, method), 1)
		for member in cls.members:
			if self.filter.filter_member(cls, member):
				block.add_block(self.export_member(cls, member), 1)

		block.add_line('</class>')
		return block

	def export_namespace(self, ns):
		package_name = self.package_for_namespace(ns)

		block = SourceBlock()
		if package_name:
			block.add_line('<package name="%s">' % package_name)
			for node in ns.nodes:
				if isinstance(node, Class):
					if self.filter.filter_class(node):
						block.add_block(self.export_class(node), 1)
				if isinstance(node, Function):
					if self.filter.filter_function(node):
						block.add_block(self.export_function(node), 1)

		child_indent = int(bool(package_name))
		for child in ns.children.values():
			if self.filter.filter_namespace(child):
				block.add_block(self.export_namespace(child), child_indent)

		if package_name:
			block.add_line('</package>')

		return block

	def export(self, importer, path):
		self.setup(importer)

		with open(path, 'w') as f:
			f.write("<ctypes>\n")
			f.write(self.export_namespace(importer.root_namespace)
				.as_text(1))
			f.write("\n</ctypes>")
