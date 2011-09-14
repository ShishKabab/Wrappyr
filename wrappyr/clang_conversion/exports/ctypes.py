from wrappyr.clang_conversion.exports import ClangExport
from wrappyr.utils.str import SourceBlock

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
