import re
from unittest import TestCase

class SourceBlock(object):
	""" Collection of lines that remember indentation.

	Useful when returning text from functions that you may need
	to indent further. """

	def __init__(self, first_line = None):
		self.lines = []
		if first_line is not None:
			self.add_line(first_line)

	def __nonzero__(self):
		return bool(self.lines)

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

	def join(self, blocks, indent = 0):
		retval = SourceBlock()

		for i, block in enumerate(blocks):
			if i > 0:
				retval.add_block(self)

			retval.add_block(block, indent)

		return retval

class SourceBlockTest(TestCase):
	def test_empty(self):
		block = SourceBlock()
		self.assertEquals(len(block.lines), 0)

	def test_single_line_constructor(self):
		block = SourceBlock("test")
		self.assertEqual(block.as_text(), "test")

	def test_add_line(self):
		block = SourceBlock()
		block.add_line("first")
		block.add_line("second", 1)
		self.assertEqual(block.as_text(), "first\n\tsecond")

	def test_add_block(self):
		expected = """root
	child 1
		child 2"""

		block = SourceBlock()
		block.add_line("root")

		indented = SourceBlock()
		indented.add_line("child 1")
		indented.add_line("child 2", 1)
		block.add_block(indented, 1)

		self.assertEqual(block.as_text(), expected)

	def test_join(self):
		expected = """0
sep
	1
sep
	2
sep"""

		sep = SourceBlock("sep")
		parts = [SourceBlock(str(i) for i in range(3))]
		joined = sep.join(parts, 1)
		self.assertEqual(expected, joined)

camelcase_regex = re.compile("_([A-Za-z0-9])")
def as_camelcase(s):
	if not s:
		return s
	s = s[0].upper() + s[1:]
	s = camelcase_regex.sub(lambda match: match.group(1).upper(), s)
	return s
