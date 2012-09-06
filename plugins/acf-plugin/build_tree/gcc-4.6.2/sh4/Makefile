#
# Copyright (C) STMicroelectronics Ltd. 2012
#
# This file is part of ATOS.
#
# ATOS is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License v2.0
# as published by the Free Software Foundation
#
# ATOS is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# v2.0 along with ATOS. If not, see <http://www.gnu.org/licenses/>.
#
# Makefile for per-function optimization plugin 
#
srcdir:=../../../src
testdir:=../../../test
builddir:=$(dir $(lastword $(MAKEFILE_LIST)))
prepdir=$(builddir)src

SRC= $(wildcard $(prepdir)/*.c)

TESTC=$(wildcard $(testdir)/*.c)
TESTCPP=$(wildcard $(testdir)/*.cpp)

INCLUDES=-I$(shell gcc -m32 -print-file-name=plugin)/include -I$(builddir)include
CFLAGS=-O2 -m32

gcc_st40=/sw/st/gnu_compil/comp/st40/st40-linux/4.6.3-107/bin/sh4-linux-gcc
g++_st40=/sw/st/gnu_compil/comp/st40/st40-linux/4.6.3-107/bin/sh4-linux-g++

all: acf_plugin.so

generate-prep-sources:
	mkdir -p $(prepdir)
	gcc -m32 -E $(INCLUDES) $(srcdir)/plugin-utils.c -o $(prepdir)/plugin-utils_prep.c
	gcc -m32 -E $(INCLUDES) $(srcdir)/acf_plugin.c -o $(prepdir)/acf_plugin_prep.c
	gcc -m32 -E $(INCLUDES) $(srcdir)/acf_csv_reader.c -o $(prepdir)/acf_csv_reader_prep.c

test: acf-test-c acf-test-cpp

acf_plugin.so: $(SRC)
	gcc $(CFLAGS) -fPIC $(INCLUDES) -c  $(prepdir)/acf_plugin_prep.c -o acf_plugin.o
	gcc $(CFLAGS) -fPIC $(INCLUDES) -c  $(prepdir)/plugin-utils_prep.c -o plugin-utils.o
	gcc $(CFLAGS) -fPIC $(INCLUDES) -c  $(prepdir)/acf_csv_reader_prep.c -o acf_csv_reader.o
	gcc $(CFLAGS) -shared  acf_plugin.o plugin-utils.o acf_csv_reader.o -o $@

ACF_PLUGIN_OPT=-fplugin=./acf_plugin.so -fplugin-arg-acf_plugin-verbose -fplugin-arg-acf_plugin-csv_file=$(testdir)/test.csv

acf-test-c: $(TESTC) ./acf_plugin.so $(testdir)/test.csv
	-$(gcc_st40) $(ACF_PLUGIN_OPT) $< -o $@  | tee acf-test-c.log 2>&1
	@echo "Checking diff with reference output:"
	diff acf-test-c.log $(testdir)/acf-test-c.log.ref

acf-test-cpp: $(TESTCPP) ./acf_plugin.so $(testdir)/test.csv
	-$(g++_st40) $(ACF_PLUGIN_OPT) $< -o $@ | tee acf-test-cpp.log 2>&1
	@echo "Checking diff with reference output:"
	diff acf-test-cpp.log $(testdir)/acf-test-cpp.log.ref

clean:
	\rm -f *.o acf_plugin.so acf-test-c acf-test-cpp acf-test-c.log acf-test-cpp.log