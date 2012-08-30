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
PREFIX=/usr/local
VSTAMP=version.stamp
VERSION:=$(shell $(srcdir)config/update_version.sh $(VSTAMP))

CONFIG_SCRIPTS_EXE_IN=atos-audit.in atos-raudit.in atos-build.in atos-run.in atos-profile.in atos-explore.in atos-play.in atos-graph.in atos-explore-inline.in atos-explore-loop.in atos-explore-optim.in atos-opt.in atos-init.in atos-replay.in atos-config.in atos-explore-acf.in atos-explore-staged.in
CONFIG_SCRIPTS_LIB_IN=atos-acf-oprofile.py.in
CONFIG_SCRIPTS_CFG_IN=flags.inline.cfg.in flags.loop.cfg.in flags.optim.cfg.in
PYTHON_LIB_SCRIPTS_IN=$(addprefix atos/, __init__.py globals.py utils.py arguments.py atos_deps.py)
PYTHON_LIB_EXE_SCRIPTS_IN=$(addprefix atos/, atos_lib.py atos_toolkit.py)
PYTHON_SCRIPTS_IN=atos.py atos-help.py atos-deps.py

CONFIG_SCRIPTS_EXE=$(CONFIG_SCRIPTS_EXE_IN:%.in=bin/%)
CONFIG_SCRIPTS_LIB=$(CONFIG_SCRIPTS_LIB_IN:%.in=lib/atos/%)
CONFIG_SCRIPTS_CFG=$(CONFIG_SCRIPTS_CFG_IN:%.in=lib/atos/config/%)
PYTHON_LIB_SCRIPTS=$(PYTHON_LIB_SCRIPTS_IN:%.py=lib/atos/python/%.py)
PYTHON_LIB_EXE_SCRIPTS=$(PYTHON_LIB_EXE_SCRIPTS_IN:%.py=lib/atos/python/%.py)
PYTHON_SCRIPTS=$(PYTHON_SCRIPTS_IN:%.py=bin/%)

CONFIG_SCRIPTS=$(CONFIG_SCRIPTS_EXE) $(CONFIG_SCRIPTS_LIB) $(CONFIG_SCRIPTS_CFG) $(PYTHON_LIB_SCRIPTS) $(PYTHON_LIB_EXE_SCRIPTS) $(PYTHON_SCRIPTS)

ALL_FILES=$(CONFIG_SCRIPTS)

INSTALLED_FILES=$(addprefix $(PREFIX)/,$(CONFIG_SCRIPTS))

.PHONY: all clean distclean install check tests check-python-dependencies examples examples-nograph install-shared

all: all-local all-plugins

all-local: $(ALL_FILES)

all-plugins:
	$(MAKE) -C $(srcdir)plugins/acf-plugin install PREFIX=$(abspath .)

clean: clean-local clean-plugin clean-test

clean-local:
	$(QUIET_CLEAN)rm -f *.tmp

clean-plugin:
	$(MAKE) -C $(srcdir)plugins/acf-plugin clean

clean-test:
	install -d tests && $(MAKE) -C tests -f $(abspath $(srcdir)tests/GNUmakefile) clean

distclean: distclean-local distclean-plugin distclean-test

distclean-local:
	$(QUIET_DISTCLEAN)rm -fr bin lib $(VSTAMP)

distclean-plugin:
	$(MAKE) -C $(srcdir)plugins/acf-plugin distclean

distclean-test:
	install -d tests && $(MAKE) -C tests -f $(abspath $(srcdir)tests/GNUmakefile) distclean

install: $(INSTALLED_FILES) install-plugins

install-plugins:
	$(MAKE) -C $(srcdir)plugins/acf-plugin install PREFIX=$(abspath $(PREFIX))

tests: check

check: check-local check-plugin check-tests

check-local: check-python-dependencies

check-tests: all check-python-dependencies
	install -d tests && $(MAKE) -C tests -f $(abspath $(srcdir)tests/GNUmakefile)

check-plugin:
	$(MAKE) -C $(srcdir)plugins/acf-plugin check

examples: all check-python-dependencies
	@echo "   Running examples."
	@echo "   Should take around 1-2 minutes per example"
	@echo "   The resulting graph is displayed for each example"
	$(MAKE) -f $(abspath $(srcdir)GNUmakefile) examples-sha1-c examples-sha1

examples-nograph: all check-python-dependencies
	@echo "   Running examples."
	@echo "   Should take around 1-2 minutes per example"
	$(MAKE) -f $(abspath $(srcdir)GNUmakefile) NOGRAPH=1 examples-sha1-c examples-sha1

examples-sha1-c: examples-sha1-c-play
	[ "$(NOGRAPH)" = 1 ] || (cd $(srcdir)examples/sha1-c && $(abspath bin/atos-graph) &)

examples-sha1-c-play:
	cd $(srcdir)examples/sha1-c && $(abspath bin/atos-explore) -f -e ./sha1-c -b "gcc -O2 -o sha1-c sha.c sha1.c" -r ./run.sh -c

examples-sha1: examples-sha1-play
	[ "$(NOGRAPH)" = 1 ] || (cd $(srcdir)examples/sha1 && $(abspath bin/atos-graph) &)

examples-sha1-play:
	cd $(srcdir)examples/sha1 && $(abspath bin/atos-explore) -b "make clean sha" -r ./run.sh -c

#
# Installation of doc and examples
#

SHARED_DIRS=examples/sha1 examples/sha1-c doc

SHARED_FILES=$(shell cd $(srcdir) && find $(SHARED_DIRS) -type f)

INSTALLED_SHARED_FILES=$(addprefix $(PREFIX)/share/atos/,$(SHARED_FILES))

install-shared: $(INSTALLED_SHARED_FILES)

$(INSTALLED_SHARED_FILES): $(PREFIX)/share/atos/%: $(srcdir)%
	$(QUIET_INSTALL_FILE)install -D -m 755 $< $@

#
# Rules for exes, libs and config files
#
$(CONFIG_SCRIPTS): $(VSTAMP)

$(CONFIG_SCRIPTS_EXE): bin/%: $(srcdir)%.in
	$(QUIET_IN)install -d $(dir $@) && sed -e 's!@VERSION@!$(VERSION)!g' <$< >$@.tmp && chmod 755 $@.tmp && mv $@.tmp $@

$(CONFIG_SCRIPTS_LIB): lib/atos/%: $(srcdir)%.in
	$(QUIET_IN)install -d $(dir $@) && sed -e 's!@VERSION@!$(VERSION)!g' <$< >$@.tmp && chmod 755 $@.tmp && mv $@.tmp $@

$(CONFIG_SCRIPTS_CFG): lib/atos/config/%: $(srcdir)%.in
	$(QUIET_IN)install -D $< $@

$(PYTHON_SCRIPTS): bin/%: $(srcdir)%.py
	$(QUIET_IN)install -d $(dir $@) && sed -e 's!@VERSION@!$(VERSION)!g' <$< >$@.tmp && chmod 755 $@.tmp && mv $@.tmp $@

$(PYTHON_LIB_SCRIPTS): lib/atos/python/%.py: $(srcdir)%.py
	$(QUIET_IN)install -d $(dir $@) && sed -e 's!@VERSION@!$(VERSION)!g' <$< >$@.tmp && mv $@.tmp $@

$(PYTHON_LIB_EXE_SCRIPTS): lib/atos/python/%.py: $(srcdir)%.py
	$(QUIET_IN)install -d $(dir $@) && sed -e 's!@VERSION@!$(VERSION)!g' <$< >$@.tmp && chmod 755 $@.tmp && mv $@.tmp $@

#
# Rules for python-checks
#
check-python-dependencies: $(srcdir)config/python_checks
	$(QUIET_CHECK)$<

#
# Rules for installation
#
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


