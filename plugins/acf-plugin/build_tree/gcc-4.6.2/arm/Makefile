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

COMPILER=gcc
### Android ARM gcc 4.6.2
SDKBASE=/work1/ferranti/android-u8500
ANDROIDROOT=/work1/ferranti/android-u8500/out/target/product/u8500
PREFIX=$(SDKBASE)/ndk/toolchains/arm-linux-androideabi-4.6.2/prebuilt/linux-x86/bin/arm-linux-androideabi-
COMPILER_FLAGS=-fno-exceptions -funwind-tables -fstack-protector -Wa,--noexecstack -fno-short-enums -march=armv7-a -mfloat-abi=softfp -mfpu=neon  -mthumb-interwork -finline-functions -fno-inline-functions-called-once -fgcse-after-reload -frerun-cse-after-loop -frename-registers -mthumb -Os -fomit-frame-pointer -fno-strict-aliasing -finline-limit=64
LINKER_FLAGS=-nostdlib -Bdynamic -Wl,-T,$(SDKBASE)/build/core/armelf.x -Wl,-dynamic-linker,/system/bin/linker -Wl,--gc-sections -Wl,-z,nocopyreloc -L$(ANDROIDROOT)/obj/lib -Wl,-rpath-link=$(ANDROIDROOT)/obj/lib -lc -lstdc++ -lm $(ANDROIDROOT)/obj/lib/crtbegin_dynamic.o -Wl,-z,noexecstack -Wl,--fix-cortex-a8 -Wl,--no-undefined $(SDKBASE)/ndk/toolchains/arm-linux-androideabi-4.6.2/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.6.2/armv7-a/libgcc.a $(ANDROIDROOT)/obj/lib/crtend_android.o
TESTGCC=${PREFIX}gcc $(COMPILER_FLAGS)
TESTGPP=${PREFIX}g++ $(COMPILER_FLAGS)
TESTCFLAGS=-O2 $(LINKER_FLAGS)

CFLAGS=-O2 -m32

include ../../common/common.mk
