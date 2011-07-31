#!/usr/bin/python2.6
import sys, os, time
import argparse
import pprint

from ctypes_builder.structure import CTypesStructure
from ctypes_builder.generation import generate_structure

if __name__ == "__main__":
	parser = argparse.ArgumentParser(prog = sys.argv[0])
	parser.add_argument("input")
	parser.add_argument("--output-path", default = os.getcwd())
	args = parser.parse_args()

	s = CTypesStructure.load(args.input)
	s.display()
	#print s.getByPath('Box2D.collision.test').findLowestCommonParent(s.getByPath('Box2D.dynamics.b2World')).getPath()
	#print s.getByPath('Box2D.collision.test').getPath(s.getByPath('Box2D'))
	generate_structure(s, args.output_path)
	#for pkg in s.packages.values():
		#writePackage(pkg, args.output_path)
