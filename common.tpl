{% macro capitalize(string) -%}
{{ string[0]|upper }}{{ string[1:] }}
{%- endmacro -%}
