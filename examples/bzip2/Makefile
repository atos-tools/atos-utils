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
#
# Simple Makefile for bzip2 example.
# Ref to source files for bzip2 licence.
#

SRCS=blocksort.c bzip2.c bzlib.c compress.c crctable.c decompress.c huffman.c randtable.c
OBJS=$(SRCS:.c=.o)
CC=gcc
CFLAGS=-O2
LDFLAGS=
LIBS=

all: bzip2

bzip2: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

run: bzip2
	./run.sh ./bzip2

run-qemu: bzip2
	./run-qemu.sh ./bzip2

clean:
	rm -f bzip2 $(OBJS) *.bz2

$(OBJS): Makefile
