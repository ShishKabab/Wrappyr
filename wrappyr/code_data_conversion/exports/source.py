from wrappyr.code_data_conversion.exports import ClangExport
from wrappyr.utils.str import SourceBlock

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
