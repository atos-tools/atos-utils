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
# Makefile for ATOS plugins
#

srcdir=$(dir $(MAKEFILE_LIST))
VPATH=$(srcdir)
SHELL=/bin/sh
CC=gcc
LD=$(CC)
CFLAGS=-O2
LDFLAGS=
LIBS=
TARGET_CC=$(CC)
PREFIX=/usr/local
PLUGINS_PREFIX=$(PREFIX)/lib


PLUGINS		=	acf_plugin
SRCS_acf_plugin	=	acf_csv_reader.c \
			acf_plugin.c \
			plugin-utils.c
HDRS_acf_plugin =	acf_plugin.h
OBJS_acf_plugin =	$(SRCS_acf_plugin:.c=.o)

PLUGINS_SOS	=	$(PLUGINS:%=%.so)
PLUGINS_OBJS	=	$(OBJS_acf_plugin)
PLUGINS_CFLAGS	=	-fpic -I $(PLUGINS_DIR)/include -I$(srcdir)include -I$(srcdir)include/config/$(TARGET_ARCH) $(CFLAGS)
PLUGINS_LDFLAGS =	-shared $(LDFLAGS)
PLUGINS_LIBS	=	$(LIBS)
PLUGINS_DIR	:=	$(shell $(TARGET_CC) -print-file-name=plugin)
TARGET_ARCH	:=	$(shell $(TARGET_CC) -dumpmachine | cut -f1 -d-)

all: $(PLUGINS_SOS)

$(PLUGINS_OBJS): %.o: %.c
	$(CC) -c -o $@ $(PLUGINS_CFLAGS) $<

$(PLUGINS_SOS): %.so:
	$(CC) -o $@ $(PLUGINS_LDFLAGS) $(OBJS_$*) $(PLUGINS_LIBS)

acf_plugin.so: $(OBJS_acf_plugin)

$(SRC_acf_plugin): %.c: $(HDRS_acf_plugin)

install: $(PLUGINS_SOS)
	mkdir -p $(PLUGINS_PREFIX)
	cp -a $(PLUGINS_SOS) $(PLUGINS_PREFIX)

uninstall:
	cd $(PLUGINS_PREFIX) 2>dev/null && rm -f $(PLUGINS_SOS) || true

clean:
	rm -f $(PLUGINS_SOS) $(PLUGINS_OBJS)

