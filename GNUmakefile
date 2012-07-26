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

srcdir:=$(dir $(lastword $(MAKEFILE_LIST)))
pluginsdir:=$(srcdir/plugin)
PREFIX=/usr/local
VSTAMP=version.stamp
VERSION:=$(shell $(srcdir)/config/update_version.sh $(VSTAMP))

CONFIG_SCRIPTS_EXE_IN=atos-audit.in atos-raudit.in atos-deps.in atos-build.in atos-run.in atos-profile.in atos-explore.in atos-play.in atos-graph.in atos-explore-inline.in atos-explore-loop.in atos-explore-optim.in atos-opt.in atos-init.in atos-replay.in atos-config.in atos-explore-acf.in atos-explore-staged.in
CONFIG_SCRIPTS_LIB_IN=atos_toolkit.py.in atos_lib.py.in atos-acf-oprofile.py.in
CONFIG_SCRIPTS_CFG_IN=flags.inline.cfg.in flags.loop.cfg.in flags.optim.cfg.in

CONFIG_SCRIPTS_EXE=$(CONFIG_SCRIPTS_EXE_IN:%.in=bin/%)
CONFIG_SCRIPTS_LIB=$(CONFIG_SCRIPTS_LIB_IN:%.in=lib/atos/%)
CONFIG_SCRIPTS_CFG=$(CONFIG_SCRIPTS_CFG_IN:%.in=lib/atos/config/%)

CONFIG_SCRIPTS=$(CONFIG_SCRIPTS_EXE) $(CONFIG_SCRIPTS_LIB) $(CONFIG_SCRIPTS_CFG)

ALL_FILES=$(CONFIG_SCRIPTS)

INSTALLED_FILES=$(addprefix $(PREFIX)/,$(CONFIG_SCRIPTS))

.PHONY: all clean distclean install check tests check-python-dependencies examples examples-nograph install-shared

all: $(ALL_FILES) all_plugins

all_plugins:
	$(MAKE) -C plugins/acf-plugin all

clean:
	$(QUIET_CLEAN)rm -f *.tmp
	$(MAKE) -C plugins/acf-plugin clean

distclean:
	$(QUIET_DISTCLEAN)rm -fr $(srcdir)/bin $(srcdir)/lib $(VSTAMP)
	$(MAKE) -C plugins/acf-plugin clean

install: $(INSTALLED_FILES)
	$(MAKE) -C plugins/acf-plugin all install

check tests: all check-python-dependencies
	$(MAKE) -C tests

examples: all check-python-dependencies
	@echo "   Running examples."
	@echo "   Should take around 1-2 minutes per example"
	@echo "   The resulting graph is displayed for each example"
	$(MAKE) examples-sha1-c examples-sha1

examples-nograph: all check-python-dependencies
	@echo "   Running examples."
	@echo "   Should take around 1-2 minutes per example"
	$(MAKE) NOGRAPH=1 examples-sha1-c examples-sha1

examples-sha1-c: examples-sha1-c-play
	[ "$(NOGRAPH)" = 1 ] || (cd examples/sha1-c && ../../bin/atos-graph &)

examples-sha1-c-play:
	cd examples/sha1-c && ../../bin/atos-explore -f -e ./sha1-c -b "gcc -O2 -o sha1-c sha.c sha1.c" -r ./run.sh -c

examples-sha1: examples-sha1-play
	[ "$(NOGRAPH)" = 1 ] || (cd examples/sha1 && ../../bin/atos-graph &)

examples-sha1-play:
	cd examples/sha1 && ../../bin/atos-explore -b "make clean sha" -r ./run.sh -c

#
# Installation of doc and examples
#

SHARED_DIRS=examples/sha1 examples/sha1-c

SHARED_FILES=$(shell find $(SHARED_DIRS) -type f)

INSTALLED_SHARED_FILES=$(addprefix $(PREFIX)/share/atos/,$(SHARED_FILES))

install-shared: $(INSTALLED_SHARED_FILES)

$(INSTALLED_SHARED_FILES): $(PREFIX)/share/atos/%: %
	$(QUIET_INSTALL_FILE)install -D -m 755 $< $(PREFIX)/share/atos/$<

#
# Rules for config files
#
$(srcdir)/bin $(srcdir)/lib/atos $(srcdir)/lib/atos/config:
	$(QUIET_IN)mkdir -p $@

$(CONFIG_SCRIPTS): $(VSTAMP) $(srcdir)/bin $(srcdir)/lib/atos $(srcdir)/lib/atos/config

$(CONFIG_SCRIPTS_EXE): bin/%: %.in
	$(QUIET_IN)sed -e 's!@VERSION@!$(VERSION)!g' <$< >$@.tmp && chmod 755 $@.tmp && mv $@.tmp $@

$(CONFIG_SCRIPTS_LIB): lib/atos/%: %.in
	$(QUIET_IN)sed -e 's!@VERSION@!$(VERSION)!g' <$< >$@.tmp && chmod 755 $@.tmp && mv $@.tmp $@

$(CONFIG_SCRIPTS_CFG): lib/atos/config/%: %.in
	$(QUIET_IN) cp $< $@

#
# Rules for python-checks
#
check-python-dependencies: config/python_checks
	$(QUIET_CHECK)$<

#
# Rules for installation
#
$(PREFIX)/bin $(PREFIX)/lib/atos:
	$(QUIET_INSTALL_DIR)install -d $@

$(INSTALLED_FILES): $(PREFIX)/bin $(PREFIX)/lib/atos

$(INSTALLED_FILES): $(PREFIX)/%: %
	$(QUIET_INSTALL_EXE)install -D -m 755 $< $(PREFIX)/$<

#
# Manage verbose output
#
ifeq ($(V),1)
QUIET_IN=
QUIET_CLEAN=
QUIET_DISTCLEAN=
QUIET_INSTALL_DIR=
QUIET_INSTALL_EXE=
QUIET_INSTALL_FILE=
QUIET_CHECK=
else
QUIET_IN=@echo "CONFIGURE $@" &&
QUIET_CLEAN=@echo "CLEAN" &&
QUIET_DISTCLEAN=@echo "DISTCLEAN" &&
QUIET_INSTALL_DIR=@echo "INSTALL DIR $@" &&
QUIET_INSTALL_FILE=@echo "INSTALL FILE $@" &&
QUIET_CHECK=@echo "CHECK $@" &&
endif


