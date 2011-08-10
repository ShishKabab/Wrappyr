import re

class SourceBlock(object):
	def __init__(self):
		self.lines = []

	def add_line(self, text, level = 0):
		self.lines.append((level, text))
		return self

	def add_block(self, block, base_level = 0):
		for level, text in block.lines:
			self.lines.append((base_level + level, text))
		return self

	def as_text(self, base_level = 0):
		return "\n".join("%s%s" % ("\t" * (base_level + level), text)
			for level, text in self.lines)

camelcase_regex = re.compile("_([A-Za-z0-9])")
def as_camelcase(s):
	if not s:
		return s
	s = s[0].upper() + s[1:]
	s = camelcase_regex.sub(lambda match: match.group(1).upper(), s)
	return s
