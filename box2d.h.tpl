{% from 'common.tpl' import capitalize -%}

extern "C" {
{% for class in classes.values() if class.name and class.name.startswith("b2") %}
	struct {{ class.name }};
{%- endfor %}

{% for class in classes.values() if class.name and class.name.startswith("b2") %}

{% if not class.abstract %}
	{% for constructor in class.constructors if constructor.access == 'public' and constructor.valid %}
	{{ class.name }}* {{ class.name }}__Create{{ loop.index0 if loop.length > 1 else '' }}({{ constructor.argsAsString() }});
	{%- endfor %}
{%- endif %} {# End constructor #}
{% if not class.destructor or class.destructor.access == 'public' %}
	void {{ class.name }}__Destroy({{ class.name }}*);
{% endif %} {# End destructor #}

{% for method in class.methods.values() %}
	{% for signature in method if signature.access == 'public' and not signature.isStatic and not signature.name.startswith('operator') and signature.valid %}
	{{ signature.returns.asString() }} {% if signature.returns.isCppOnly() %}* {% endif -%}
	{{ class.name }}_{{ signature.name }}{{ loop.index0 if loop.length > 1 else '' }}(
		{%- if signature.args -%}
		{{ class.name }}*, {{ signature.argsAsString() }}
		{%- else -%}
		{{ class.name }}*
		{%- endif -%}
	);
	{%- endfor %}
{%- endfor %}  {# End method #}

{% for member in class.members if member.access == 'public' and member.name and member.type.valid %}
{{ member.type.asString() }} {% if member.type.isCppOnly() %}* {% endif -%}
{{ class.name }}__Get{{ capitalize(member.name) }}({{ class.name }}*);
void {{ class.name }}__Set{{ capitalize(member.name) }}({{ class.name }}*, {{ member.type.asString() }}
	{%- if member.type.isCppOnly() %}*{% endif -%});
{%- endfor %}  {# End member #}

{%- endfor %}  {# End class #}

}