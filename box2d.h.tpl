extern "C" {
{% for class in nodesByType.nonPODs %}
	struct {{ class.name }};
{% endfor %}

{% for class in nodesByType.nonPODs %}
	{% if class.othersCanCreate %}
	{% if class.constructor %}
	{{ class.name }}* {{ identifier(cls = class, special = "constructor") }}({{ class.constructor.argsAsString }});
	{% else %}
	{{ class.name }}* {{ identifier(cls = class, special = "constructor") }}();
	{% endif %}
	{% endif class.constructor %}
	void {{ class.name }}_Delete(class.constructor.argsAsString);
	{% for method in class.methods %}
	{% if method.args %}
	{{ type2string(method.returns) }} {{ identifier(method, cls = cls) }}({{ class.name }}*, {{ class.constructor.argsAsString }});
	{% else %}
	{{ type2string(method.returns) }} {{ identifier(method, cls = cls) }}({{ class.name }}*);
	{% endif %}
	{% endfor %}
{% endfor %}

{#
if not cls.isAbstract and (not cls.constructor or cls.constructor.access == "public"):
		header.write("{0}* {1}({2});\n".format(cls.name,
			getIdentifier(cls = cls, special = "constructor"),
			cls.constructor.getArgsAsString(getTypeAsString) if cls.constructor else "")
		)

		cpp.write("{0}* {1}({2}){{\n".format(cls.name,
			getIdentifier(cls = cls, special = "constructor"),
			cls.constructor.getArgsAsString(getTypeAsString, argNames) if cls.constructor else "")
		)

		if cls.constructor:
			args = ", ".join(("*" + name if isReference(arg) else name) for name, arg in zip(argNames, cls.constructor.args))
		else:
			args = ""
		cpp.write("\treturn new {cls.name}({args});\n".format(cls = cls, args = args))

		cpp.write("}\n\n")
	header.write("void {func}({cls.name}*);\n".format(cls = cls, func = getIdentifier(cls = cls, special = "destructor")))

	for method in cls.methods:
		args = method.getArgsAsString(getTypeAsString)
		if args:
			args = "{0}*, {1}".format(cls.name, args)
		else:
			args = "{0}*".format(cls.name)
		header.write("{retType} {function}({args});\n".format(retType = getTypeAsString(method.returns), function = getIdentifier(method, cls = cls), args = args))
	header.write("// -- End class %s\n\n" % cls.name)
#}
