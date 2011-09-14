#!/usr/bin/env python2.6
import os
import subprocess
import sys
import argparse
from importlib import import_module

from wrappyr.code_data_conversion.exports.header import HeaderExport
from wrappyr.code_data_conversion.exports.source import SourceExport
from wrappyr.code_data_conversion.exports.ctypes import CtypesExport
from wrappyr.code_data_conversion.imports.clang import ClangImporter
from wrappyr.ctypes_api_builder.structure import CTypesStructure
from wrappyr.ctypes_api_builder.export import export_structure

def import_object(path):
	# Taken from django.core.handlers.base
	try:
		dot = path.rindex('.')
	except ValueError:
		raise ImportError('%s isn\'t a module' % path)

	mod, obj = path[:dot], path[dot+1:]
	try:
		mod = import_module(mod)
	except ImportError, e:
		raise ImportError('Error importing module %s: "%s"' % (mod, e))

	try:
		obj = getattr(mod, obj)
	except AttributeError:
		raise ImportError('Module "%s" does not contain "%s"' % (mod, obj))

	return obj

def generate_code_data(input, output = None, backend = 'clang', language = 'c++',
					   clang_binary = 'clang', clang_export_plugin = None):

	# TODO: cleanup

	can_capture_output = False
	if backend == 'clang':
		if not clang_export_plugin:
			raise TypeError("clang_export_plugin argument required "
							"for 'clang' backend")

		cmd = [clang_binary, '-cc1', '-load', clang_export_plugin]
		cmd += ['-plugin', 'export-hdr']
		if language != 'c':
			cmd += ['-x', language]
		cmd += ['-I/usr/include/i386-linux-gnu/', input]

		can_capture_output = True
	elif backend == 'clang-pch':
		cmd = [clang_binary, '-cc1']
		if language != 'c':
			cmd += ['-x', 'c++']
		cmd += [input, '-I/usr/include/i386-linux-gnu/', '-emit-pch', '-o', output]
	elif backend == 'gccxml':
		cmd = ['gccxml', '-o', output, input]

	if can_capture_output:
		stdout = open(output, 'w') if output else subprocess.PIPE
	else:
		stdout = None
	stderr = subprocess.PIPE
	proc = subprocess.Popen(cmd, stdout = stdout, stderr = stderr)
	stdout, stderr = proc.communicate()

	if not output:
		return proc.returncode == 0, stdout, stderr
	else:
		print stderr

def convert_code_data(input, header = None, source = None, ctypes = None, package = None):
	if isinstance(package, basestring):
		package = import_object(package)()

	importer = ClangImporter(input)
	if header:
		header_export = package.get_header_export() if package else HeaderExport()
		header_export.export(importer, header)
	if source:
		source_export = package.get_source_export() if package else SourceExport()
		source_export.export(importer, source)
	if ctypes:
		ctypes_export = package.get_ctypes_export() if package else CtypesExport()
		ctypes_export.export(importer, ctypes)

def generate_ctypes_api(input, output_path, package = None,
						display_unprocessed = False, display_processed = True):
	if isinstance(package, basestring):
		package = import_object(package)()

	structure = CTypesStructure.load(input)
	if display_unprocessed:
		structure.display()
	if package:
		package.process_ctypes_structure(structure)
	if display_processed:
		structure.display()

	export_structure(structure, output_path)

def main():
	parser = argparse.ArgumentParser(prog = sys.argv[0])
	parser.add_argument('--package')
	subparsers = parser.add_subparsers(dest = 'command')

	parser_generate_code_data = subparsers.add_parser('generate_code_data')
	parser_generate_code_data.add_argument('input')
	parser_generate_code_data.add_argument('output')
	parser_generate_code_data.add_argument('--language', default = 'c++', choices = ('c', 'c++'))
	parser_generate_code_data.add_argument('--backend', default = 'clang', choices = ('clang', 'clang-pch', 'gccxml'))
	parser_generate_code_data.add_argument('--clang-binary', default = 'clang')
	parser_generate_code_data.add_argument('--clang-export-plugin')

	parser_convert_code_data = subparsers.add_parser('convert_code_data')
	parser_convert_code_data.add_argument('input')
	parser_convert_code_data.add_argument('--backend', default = 'clang', choices = ('clang',))
	parser_convert_code_data.add_argument('--header')
	parser_convert_code_data.add_argument('--source')
	parser_convert_code_data.add_argument('--ctypes')

	parser_generate_ctypes_api = subparsers.add_parser('generate_ctypes_api')
	parser_generate_ctypes_api.add_argument('input')
	parser_generate_ctypes_api.add_argument("--output-path", default = os.getcwd())
	parser_generate_ctypes_api.add_argument('--display-unprocessed', action = 'store_true')
	parser_generate_ctypes_api.add_argument('--display-processed', action = 'store_true')

	args = parser.parse_args()
	if args.command == "generate_code_data":
		generate_code_data(args.input, args.output, args.backend, args.language,
						   args.clang_binary, args.clang_export_plugin)
	if args.command == "convert_code_data":
		convert_code_data(args.input, args.header, args.source, args.ctypes,
						  args.package)
	elif args.command == "generate_ctypes_api":
		generate_ctypes_api(args.input, args.output_path, args.package,
							args.display_unprocessed, args.display_processed)

if __name__ == '__main__':
	main()
