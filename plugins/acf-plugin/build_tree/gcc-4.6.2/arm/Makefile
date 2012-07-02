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
	gcc -m32 -E $(INCLUDES) $(srcdir)/plugin-utils.c -o $(prepdir)/plugin-utils_prep.c
	sed -i -e '/^$$/d' $(prepdir)/plugin-utils_prep.c
	gcc -m32 -E $(INCLUDES) $(srcdir)/acf_plugin.c -o $(prepdir)/acf_plugin_prep.c
	sed -i -e '/^$$/d' $(prepdir)/acf_plugin_prep.c
	gcc -m32 -E $(INCLUDES) $(srcdir)/acf_csv_reader.c -o $(prepdir)/acf_csv_reader_prep.c
	sed -i -e '/^$$/d' $(prepdir)/acf_csv_reader_prep.c

test: acf-test-c acf-test-cpp

acf_plugin.so: $(SRC)
	gcc $(CFLAGS) -fPIC $(INCLUDES) -c  $(prepdir)/acf_plugin_prep.c -o acf_plugin.o
	gcc $(CFLAGS) -fPIC $(INCLUDES) -c  $(prepdir)/plugin-utils_prep.c -o plugin-utils.o
	gcc $(CFLAGS) -fPIC $(INCLUDES) -c  $(prepdir)/acf_csv_reader_prep.c -o acf_csv_reader.o
	gcc $(CFLAGS) -shared acf_plugin.o plugin-utils.o acf_csv_reader.o -o $@


### Android ARM gcc 4.6.2
SDKBASE=/work1/ferranti/android-u8500
ANDROIDROOT=/work1/ferranti/android-u8500/out/target/product/u8500

PREFIX=$(SDKBASE)/ndk/toolchains/arm-linux-androideabi-4.6.2/prebuilt/linux-x86/bin/arm-linux-androideabi-

COMPILER_FLAGS=-fno-exceptions -funwind-tables -fstack-protector -Wa,--noexecstack -fno-short-enums -march=armv7-a -mfloat-abi=softfp -mfpu=neon  -mthumb-interwork -finline-functions -fno-inline-functions-called-once -fgcse-after-reload -frerun-cse-after-loop -frename-registers -mthumb -Os -fomit-frame-pointer -fno-strict-aliasing -finline-limit=64

LINKER_FLAGS=-nostdlib -Bdynamic -Wl,-T,$(SDKBASE)/build/core/armelf.x -Wl,-dynamic-linker,/system/bin/linker -Wl,--gc-sections -Wl,-z,nocopyreloc -L$(ANDROIDROOT)/obj/lib -Wl,-rpath-link=$(ANDROIDROOT)/obj/lib -lc -lstdc++ -lm $(ANDROIDROOT)/obj/lib/crtbegin_dynamic.o -Wl,-z,noexecstack -Wl,--fix-cortex-a8 -Wl,--no-undefined $(SDKBASE)/ndk/toolchains/arm-linux-androideabi-4.6.2/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.6.2/armv7-a/libgcc.a $(ANDROIDROOT)/obj/lib/crtend_android.o

gcc_arm=${PREFIX}gcc $(COMPILER_FLAGS)
g++_arm=${PREFIX}g++ $(COMPILER_FLAGS)

ACF_PLUGIN_OPT=-fplugin=./acf_plugin.so -fplugin-arg-acf_plugin-verbose -fplugin-arg-acf_plugin-csv_file=$(testdir)/test.csv

acf-test-c: $(TESTC) ./acf_plugin.so $(testdir)/test.csv
	$(gcc_arm) $(LINKER_FLAGS) $(ACF_PLUGIN_OPT) $< -o $@  > acf-test-c.log 2>&1
	diff acf-test-c.log $(testdir)/acf-test-c.log.ref

acf-test-cpp: $(TESTCPP) ./acf_plugin.so $(testdir)/test.csv
	$(g++_arm) $(LINKER_FLAGS) $(ACF_PLUGIN_OPT) $< -o $@ > acf-test-cpp.log 2>&1
	diff acf-test-cpp.log $(testdir)/acf-test-cpp.log.ref

clean:
	\rm -f *.o acf_plugin.so acf-test-c acf-test-cpp acf-test-c.log acf-test-cpp.log