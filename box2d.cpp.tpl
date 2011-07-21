{% from 'common.tpl' import capitalize -%}

#include <Box2D.h>
#include "box2d.h"

{% set args = letters('a', 'z') %}
{%- macro argsAsParameters(function) %}
{%- for arg in function.args -%}
{% if arg.type.refs %}*{% endif -%}
{#- {% if isEnumeration(arg) %}({{ nodesByID[arg].name }}){% endif -%} -#}
{{ args[loop.index0] }}{% if not loop.last %}, {% endif %}
{%- endfor -%}
{% endmacro -%}

{% for class in classes.values() if class.name and class.name.startswith("b2") %}

{% if not class.abstract %}
	{% for constructor in class.constructors if constructor.access == 'public' and constructor.valid %}
	{{ class.name }}* {{ class.name }}__Create{{ loop.index0 if loop.length > 1 else '' }}({{ constructor.argsAsString(args) }}){
		return new {{ class.name }}({{ argsAsParameters(constructor) }});
	}
	{%- endfor %}
{%- endif %} {# End constructor #}
{% if not class.destructor or class.destructor.access == 'public' %}
	void {{ class.name }}__Destroy({{ class.name }}* cls){
		delete cls;
	}
{% endif %} {# End destructor #}

{% for method in class.methods.values() %}
	{% for signature in method if signature.access == 'public' and not signature.isStatic and not signature.name.startswith('operator') and signature.valid %}
	{{ signature.returns.asString() }} {% if signature.returns.isCppOnly() %}* {% endif -%}
	{{ class.name }}_{{ signature.name }}{{ loop.index0 if loop.length > 1 else '' }}(
		{%- if signature.args -%}
		{{ class.name }}* cls, {{ signature.argsAsString(args) }}
		{%- else -%}
		{{ class.name }}* cls
		{%- endif -%}
	){
		{% if signature.returns.pointers or signature.returns.name != 'void' %}return {% endif -%}
		{% if signature.returns.isCppOnly() %}new {{ signature.returns.name }}({% endif -%}
		{% if signature.returns.const %}const_cast<{{ signature.returns.asString() }}>({% endif -%}
		{% if signature.returns.refs %}&{% endif -%}
		cls->{{ signature.name }}({{ argsAsParameters(signature) }}
		{%- if signature.returns.const %}){% endif -%}
		{%- if signature.returns.isCppOnly() %}){% endif -%}
		);
	}
	{%- endfor %}
{%- endfor %}  {# End method #}

{% for member in class.members if member.access == 'public' and member.name and member.type.valid %}
	{{ member.type.asString() }} {% if member.type.isCppOnly() %}* {% endif -%}
	{{ class.name }}__Get{{ capitalize(member.name) }}({{ class.name }}* cls){
		return {% if member.type.isCppOnly() %}new {{ member.type.name }}({% endif -%}
		{% if member.type.const %}const_cast<{{ member.type.asString() }}>({% endif -%}
		{% if member.type.refs %}&{% endif -%}
		cls->{{ member.name }}
		{%- if member.type.const %}){% endif -%}
		{%- if member.type.isCppOnly() %}){% endif -%};
	}
	void {{ class.name }}__Set{{ capitalize(member.name) }}({{ class.name }}* cls, {{ member.type.asString() }}
		{%- if member.type.isCppOnly() %}*{% endif %} value){
		cls->{{ member.name }} = {% if member.type.isCppOnly() %}*{% endif -%}value;
	}
{%- endfor %}  {# End member #}

{%- endfor %}  {# End class #}

