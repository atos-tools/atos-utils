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

all: acf_plugin.so

generate-prep-sources:
	mkdir -p $(prepdir)
	g++ -m32 -E $(INCLUDES) $(srcdir)/plugin-utils.c -o $(prepdir)/plugin-utils_prep.c
	sed -i -e '/^$$/d' $(prepdir)/plugin-utils_prep.c
	g++ -m32 -E $(INCLUDES) $(srcdir)/acf_plugin.c -o $(prepdir)/acf_plugin_prep.c
	sed -i -e '/^$$/d' $(prepdir)/acf_plugin_prep.c
	g++ -m32 -E $(INCLUDES) $(srcdir)/acf_csv_reader.c -o $(prepdir)/acf_csv_reader_prep.c
	sed -i -e '/^$$/d' $(prepdir)/acf_csv_reader_prep.c

test: acf-test-c acf-test-cpp

acf_plugin.so: $(SRC)
	g++ $(CFLAGS) -fPIC $(INCLUDES) -c  $(prepdir)/acf_plugin_prep.c -o acf_plugin.o
	g++ $(CFLAGS) -fPIC $(INCLUDES) -c  $(prepdir)/plugin-utils_prep.c -o plugin-utils.o
	g++ $(CFLAGS) -fPIC $(INCLUDES) -c  $(prepdir)/acf_csv_reader_prep.c -o acf_csv_reader.o
	g++ $(CFLAGS) -shared  acf_plugin.o plugin-utils.o acf_csv_reader.o -o $@

ACF_PLUGIN_OPT=-fplugin=./acf_plugin.so -fplugin-arg-acf_plugin-verbose -fplugin-arg-acf_plugin-csv_file=$(testdir)/test.csv

acf-test-c: $(TESTC) ./acf_plugin.so $(testdir)/test.csv
	-gcc -m32 $(ACF_PLUGIN_OPT) $< -o $@  > acf-test-c.log 2>&1
	diff acf-test-c.log $(testdir)/acf-test-c.log.ref

acf-test-cpp: $(TESTCPP) ./acf_plugin.so $(testdir)/test.csv
	-g++ -m32 $(ACF_PLUGIN_OPT) $< -o $@ > acf-test-cpp.log 2>&1
	diff acf-test-cpp.log $(testdir)/acf-test-cpp.log.ref

clean:
	\rm -f *.o acf_plugin.so acf-test-c acf-test-cpp acf-test-c.log acf-test-cpp.log