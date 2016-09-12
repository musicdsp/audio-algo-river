#!/usr/bin/python
import lutin.module as module
import lutin.tools as tools
import lutin.debug as debug


def get_type():
	return "BINARY"

def get_sub_type():
	return "TEST"

def get_desc():
	return "test for River ALGO"

def get_licence():
	return "APACHE-2"

def get_compagny_type():
	return "com"

def get_compagny_name():
	return "atria-soft"

def get_maintainer():
	return "authors.txt"

def create(target, module_name):
	my_module = module.Module(__file__, module_name, get_type())
	my_module.add_src_file([
		'test/main.cpp'
		])
	my_module.add_depend(['audio-algo-river', 'test-debug'])
	return my_module









