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
# Makefile for ATOS tools
#

srcdir:=$(dir $(firstword $(MAKEFILE_LIST)))
builddir=$(srcdir)build_tree
PREFIX=/usr/local
PLUGIN_PREFIX=$(PREFIX)/lib/atos/plugins
VSTAMP=version.stamp

ALL_FILES_SUB=gcc-4.5.2/i386/acf_plugin.so gcc-4.5.2/x86_64/acf_plugin.so gcc-4.5.2/sh4/acf_plugin.so gcc-4.6.2/i386/acf_plugin.so gcc-4.6.2/x86_64/acf_plugin.so gcc-4.6.2/sh4/acf_plugin.so gcc-4.6.2/arm/acf_plugin.so gcc-4.7.0/i386/acf_plugin.so gcc-4.7.0/x86_64/acf_plugin.so gcc-4.7.1/arm/acf_plugin.so

ALL_FILES=$(addprefix $(builddir)/,$(ALL_FILES_SUB))

INSTALLED_FILES=$(addprefix $(PLUGIN_PREFIX)/,$(ALL_FILES_SUB))

.PHONY: all clean distclean install check tests

all: $(ALL_FILES)

$(builddir)/%/acf_plugin.so:
	$(MAKE) -C $(builddir)/$* all

clean: $(dir $(ALL_FILES))
	for direc in $^; do make -C $${direc} clean ; done

distclean: clean

install: $(INSTALLED_FILES) 

check: all

tests: check

#
# Rules for installation
#
$(INSTALLED_FILES): $(PLUGIN_PREFIX)/%: $(builddir)/%
	$(QUIET_INSTALL_EXE)install -D -m 755 $< $@

#
# Manage verbose output
#
ifeq ($(V),1)
QUIET_IN=
QUIET_CLEAN=
QUIET_DISTCLEAN=
QUIET_INSTALL_DIR=
QUIET_INSTALL_EXE=
QUIET_CHECK=
else
QUIET_IN=@echo "CONFIGURE $@" &&
QUIET_CLEAN=@echo "CLEAN" &&
QUIET_DISTCLEAN=@echo "DISTCLEAN" &&
QUIET_INSTALL_DIR=@echo "INSTALL DIR $@" &&
QUIET_INSTALL_EXE=@echo "INSTALL EXE $@" &&
QUIET_CHECK=@echo "CHECK $@" &&
QUIET_LOCAL_INSTALL_DIR=@echo "MKDIR $@" &&
QUIET_LOCAL_INSTALL_EXE=@echo "COPY EXE $@" &&
endif
