class CArray(object):
	class UnknownSize(Exception): pass

	def __init__(self, ptr, cls = None, size = None, ownership = False,
				 dimensions = 1):
		self.ptr = ptr
		self.cls = cls
		self.size = size
		self.ownership = ownership
		self.dimensions = dimensions

	def __del__(self):
		if not self.ownership:
			return

		if self.cls:
			self.cls.__delarray__(self.ptr)

	def elements(self, size = None):
		size = size or self.size
		if size is None:
			raise self.UnknownSize("No size passed or stored in class")

		for i in xrange(size):
			yield self[i]

	def __iter__(self):
		return self.elements()

	def __getitem__(self, item):
		assert isinstance(item, int)

		if self.size and item >= self.size:
			msg = "Tried to access element %d of array with size %d"
			raise IndexError(msg % (item, self.size))

		if self.dimensions > 1:
			return CArray(self.ptr[item], self.cls, False, self.dimensions - 1)

		if self.cls:
			item = self.cls.__arrayitem__(self.ptr, item)
			item = self.cls._from_c(item, False)
		else:
			item = self.ptr[item].value
		return item

class CPPClassMeta(type):
	pass

class CPPClass(object):
	__metaclass__ = CPPClassMeta

	def __init__(self):
		pass

class NoArgument(object):
	pass

def arrayof(cls, size):
	return CArray(cls.__newarray__(size), cls, size, True)