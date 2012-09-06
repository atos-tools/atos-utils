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

ARMGCC=arm-linux-androideabi-gcc

INCLUDES=-I$(shell $(ARMGCC) -print-file-name=plugin)/include -I$(builddir)include
CFLAGS=-O2 -m32

all: acf_plugin.so

generate-prep-sources:
	mkdir -p $(prepdir)
	gcc -m32 -E $(INCLUDES) $(srcdir)/plugin-utils.c -o $(prepdir)/plugin-utils_prep.c
	gcc -m32 -E $(INCLUDES) $(srcdir)/acf_plugin.c -o $(prepdir)/acf_plugin_prep.c
	gcc -m32 -E $(INCLUDES) $(srcdir)/acf_csv_reader.c -o $(prepdir)/acf_csv_reader_prep.c

acf_plugin.so: $(SRC)
	gcc $(CFLAGS) -fPIC $(INCLUDES) -c  $(prepdir)/acf_plugin_prep.c -o acf_plugin.o
	gcc $(CFLAGS) -fPIC $(INCLUDES) -c  $(prepdir)/plugin-utils_prep.c -o plugin-utils.o
	gcc $(CFLAGS) -fPIC $(INCLUDES) -c  $(prepdir)/acf_csv_reader_prep.c -o acf_csv_reader.o
	gcc $(CFLAGS) -shared acf_plugin.o plugin-utils.o acf_csv_reader.o -o $@

clean:
	\rm -f *.o acf_plugin.so acf-test-c acf-test-cpp acf-test-c.log acf-test-cpp.log
