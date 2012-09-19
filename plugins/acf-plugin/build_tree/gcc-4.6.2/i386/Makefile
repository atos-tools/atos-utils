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
TESTGCC=/sw/st/gnu_compil/gnu/linux-rh-ws-4/gcc/gcc-4.6.2/bin/gcc
TESTGPP=/sw/st/gnu_compil/gnu/linux-rh-ws-4/gcc/gcc-4.6.2/bin/g++
TESTCFLAGS=-O2 -m32

CFLAGS=-O2 -m32

include ../../common/common.mk
