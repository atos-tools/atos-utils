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

RST2MAN=$(srcdir)config/docutils rst2man --report=3 # Filter warning with images
RST2HTML=$(srcdir)config/docutils rst2html

CONFIG_SCRIPTS_EXE_IN=atos-run.in atos-play.in atos-graph.in atos-explore-inline.in atos-explore-loop.in atos-explore-optim.in atos-replay.in atos-config.in atos-explore-acf.in atos-explore-staged.in
CONFIG_SCRIPTS_LIB_IN=atos-acf-oprofile.py.in
CONFIG_SCRIPTS_CFG_IN=flags.inline.cfg.in flags.loop.cfg.in flags.optim.cfg.in
PYTHON_LIB_SCRIPTS_IN=$(addprefix atos/, __init__.py globals.py utils.py arguments.py atos_deps.py logger.py process.py)
PYTHON_LIB_EXE_SCRIPTS_IN=$(addprefix atos/, atos_lib.py atos_toolkit.py)
PYTHON_SCRIPTS_IN=atos.py atos-help.py atos-audit.py atos-build.py atos-deps.py atos-explore.py atos-init.py atos-opt.py atos-profile.py atos-raudit.py atos-driver.py atos-timeout.py
SHARED_RSTS_IN=$(addprefix doc/, intro.rst tutorial.rst)
SHARED_MANS_IN=$(SHARED_RSTS_IN)
SHARED_HTMLS_IN=$(SHARED_RSTS_IN)
SHARED_IMAGES_IN=$(addprefix doc/images/, graph-sha1-first.png graph-sha1-staged.png)

CONFIG_SCRIPTS_EXE=$(CONFIG_SCRIPTS_EXE_IN:%.in=bin/%)
CONFIG_SCRIPTS_LIB=$(CONFIG_SCRIPTS_LIB_IN:%.in=lib/atos/%)
CONFIG_SCRIPTS_CFG=$(CONFIG_SCRIPTS_CFG_IN:%.in=lib/atos/config/%)
PYTHON_LIB_SCRIPTS=$(PYTHON_LIB_SCRIPTS_IN:%.py=lib/atos/python/%.py)
PYTHON_LIB_EXE_SCRIPTS=$(PYTHON_LIB_EXE_SCRIPTS_IN:%.py=lib/atos/python/%.py)
PYTHON_SCRIPTS=$(PYTHON_SCRIPTS_IN:%.py=bin/%)
SHARED_RSTS=$(SHARED_RSTS_IN:%=share/atos/%)
SHARED_MANS=$(SHARED_MANS_IN:doc/%.rst=share/atos/man/man1/atos-%.1)
SHARED_HTMLS=$(SHARED_HTMLS_IN:doc/%.rst=share/atos/doc/%.html)
SHARED_IMAGES=$(SHARED_IMAGES_IN:%=share/atos/%)

CONFIG_SCRIPTS=$(CONFIG_SCRIPTS_EXE) $(CONFIG_SCRIPTS_LIB) $(PYTHON_LIB_EXE_SCRIPTS) $(PYTHON_SCRIPTS)

ALL_EXES=$(CONFIG_SCRIPTS)
INSTALLED_EXES=$(addprefix $(PREFIX)/,$(ALL_EXES))

ALL_DATAS=$(CONFIG_SCRIPTS_CFG) $(PYTHON_LIB_SCRIPTS) $(SHARED_IMAGES) $(SHARED_RSTS)
INSTALLED_DATAS=$(addprefix $(PREFIX)/,$(ALL_DATAS))

ALL_DOCS=$(SHARED_MANS) $(SHARED_HTMLS)
INSTALLED_DOCS=$(addprefix $(PREFIX)/,$(ALL_DOCS))

COVERAGE_DIR=$(abspath .)/coverage

.PHONY: all clean distclean install check tests check-python-dependencies examples examples-nograph install-shared

all: all-local all-plugins

all-local: $(ALL_EXES) $(ALL_DATAS)

doc: $(ALL_DOCS)

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
	$(QUIET_DISTCLEAN)rm -fr bin lib share $(VSTAMP)

distclean-plugin:
	$(MAKE) -C $(srcdir)plugins/acf-plugin distclean

distclean-test:
	install -d tests && $(MAKE) -C tests -f $(abspath $(srcdir)tests/GNUmakefile) distclean

install: $(INSTALLED_EXES) $(INSTALLED_DATAS) install-plugins

install-plugins:
	$(MAKE) -C $(srcdir)plugins/acf-plugin install PREFIX=$(abspath $(PREFIX))

install-doc: $(INSTALLED_DOCS)

tests: check

check: check-local check-plugin check-tests

check-local: check-python-dependencies

check-tests: all check-python-dependencies
	install -d tests && $(MAKE) -C tests -f $(abspath $(srcdir)tests/GNUmakefile)

coverage: check-local check-plugin check-coverage

check-coverage: all check-python-dependencies
	install -d tests && $(MAKE) COVERAGE_DIR=$(COVERAGE_DIR) -C tests -f $(abspath $(srcdir)tests/GNUmakefile) coverage

check-plugin:
	$(MAKE) -C $(srcdir)plugins/acf-plugin check

examples: all check-python-dependencies
	@echo "   Running examples."
	@echo "   Should take around 1-2 minutes per example"
	@echo "   The resulting graph is displayed for each example"
	$(MAKE) -f $(abspath $(srcdir)GNUmakefile) examples-sha1-c examples-sha1 examples-bzip2

examples-nograph: all check-python-dependencies
	@echo "   Running examples."
	@echo "   Should take around 1-2 minutes per example"
	$(MAKE) -f $(abspath $(srcdir)GNUmakefile) NOGRAPH=1 examples-sha1-c examples-sha1 examples-bzip2

examples-sha1-c examples-sha1 examples-bzip2: examples-%: examples-%-play
	[ "$(NOGRAPH)" = 1 ] || (cd $(srcdir)examples/$* && $(abspath bin/atos-graph) &)

examples-sha1-c-play:
	cd $(srcdir)examples/sha1-c && $(abspath bin/atos-explore) -f -e ./sha1-c -b "gcc -O2 -o sha1-c sha.c sha1.c" -r ./run.sh -c && $(abspath bin/atos-play) -p

examples-sha1-play:
	cd $(srcdir)examples/sha1 && $(abspath bin/atos-explore) -b "make clean sha" -r ./run.sh -c && $(abspath bin/atos-play) -p

examples-bzip2-play:
	cd $(srcdir)examples/bzip2 && $(abspath bin/atos-explore) -b "make clean all" -r ./run.sh -c && $(abspath bin/atos-play) -p

#
# Installation of doc and examples
#

SHARED_DIRS=examples/sha1 examples/sha1-c

SHARED_FILES=$(shell cd $(srcdir) && find $(SHARED_DIRS) -type f)

INSTALLED_SHARED_FILES=$(addprefix $(PREFIX)/share/atos/,$(SHARED_FILES))

install-shared: $(INSTALLED_SHARED_FILES)

$(INSTALLED_SHARED_FILES): $(PREFIX)/share/atos/%: $(srcdir)%
	$(QUIET_INSTALL_DATA)install -D -m 755 $< $@


#
# Rules for exes, libs and config files
#
$(ALL_EXES) $(ALL_DATAS) $(ALL_DOCS): $(VSTAMP) $(srcdir)GNUmakefile

$(CONFIG_SCRIPTS_EXE): bin/%: $(srcdir)%.in
	$(QUIET_IN)install -d $(dir $@) && sed -e 's!@VERSION@!$(VERSION)!g' <$< >$@.tmp && chmod 755 $@.tmp && mv $@.tmp $@

$(CONFIG_SCRIPTS_LIB): lib/atos/%: $(srcdir)%.in
	$(QUIET_IN)install -d $(dir $@) && sed -e 's!@VERSION@!$(VERSION)!g' <$< >$@.tmp && chmod 755 $@.tmp && mv $@.tmp $@

$(CONFIG_SCRIPTS_CFG): lib/atos/config/%: $(srcdir)%.in
	$(QUIET_IN)install -D $< $@

$(PYTHON_SCRIPTS): bin/%: $(srcdir)%.py
	$(QUIET_CHECK)$(srcdir)config/python_checker $<
	$(QUIET_IN)install -d $(dir $@) && sed -e 's!@VERSION@!$(VERSION)!g' <$< >$@.tmp && chmod 755 $@.tmp && mv $@.tmp $@

$(PYTHON_LIB_SCRIPTS): lib/atos/python/%.py: $(srcdir)%.py
	$(QUIET_CHECK)$(srcdir)config/python_checker $<
	$(QUIET_IN)install -d $(dir $@) && sed -e 's!@VERSION@!$(VERSION)!g' <$< >$@.tmp && mv $@.tmp $@

$(PYTHON_LIB_EXE_SCRIPTS): lib/atos/python/%.py: $(srcdir)%.py
	$(QUIET_CHECK)$(srcdir)config/python_checker $<
	$(QUIET_IN)install -d $(dir $@) && sed -e 's!@VERSION@!$(VERSION)!g' <$< >$@.tmp && chmod 755 $@.tmp && mv $@.tmp $@

$(SHARED_RSTS): share/atos/%: $(srcdir)%
	$(QUIET_IN)install -d $(dir $@) && sed -e 's!@VERSION@!$(VERSION)!g' <$< >$@.tmp && mv $@.tmp $@

$(SHARED_MANS): share/atos/man/man1/atos-%.1: $(srcdir)doc/%.rst
	$(QUIET_RST2MAN)install -d $(dir $@) && sed -e 's!@VERSION@!$(VERSION)!g' <$< | $(RST2MAN) >$@

$(SHARED_HTMLS): share/atos/doc/%.html: $(srcdir)doc/%.rst
	$(QUIET_RST2HTML)install -d $(dir $@) && sed -e 's!@VERSION@!$(VERSION)!g' <$< | $(RST2HTML) >$@

$(SHARED_IMAGES): share/atos/%: $(srcdir)%
	$(QUIET_CP_DATA)install -d $(dir $@) && cp $< $@

#
# Rules for python-checks
#
check-python-dependencies: $(srcdir)config/python_checks
	$(QUIET_CHECK)$<

#
# Rules for installation
#
$(INSTALLED_EXES): $(PREFIX)/%: %
	$(QUIET_INSTALL_EXE)install -D -m 755 $< $(PREFIX)/$<

$(INSTALLED_DATAS): $(PREFIX)/%: %
	$(QUIET_INSTALL_DATA)install -D -m 644 $< $(PREFIX)/$<

$(INSTALLED_DOCS): $(PREFIX)/%: %
	$(QUIET_INSTALL_DOC)install -D -m 644 $< $(PREFIX)/$<

#
# Manage verbose output
#
ifeq ($(V),1)
QUIET_CHECK=
QUIET_IN=
QUIET_CP=
QUIET_RST2MAN=
QUIET_RST2HTML=
QUIET_CLEAN=
QUIET_DISTCLEAN=
QUIET_INSTALL_EXE=
QUIET_INSTALL_DATA=
QUIET_INSTALL_DOC=
QUIET_CHECK=
else
QUIET_CHECK=@echo "CHECK $@" &&
QUIET_IN=@echo "CONFIGURE $@" &&
QUIET_CP=@echo "CP $@" &&
QUIET_RST2MAN=@echo "RST2MAN $@" &&
QUIET_RST2HTML=@echo "RST2HTML $@" &&
QUIET_CLEAN=@echo "CLEAN" &&
QUIET_DISTCLEAN=@echo "DISTCLEAN" &&
QUIET_INSTALL_EXE=@echo "INSTALL EXE $@" &&
QUIET_INSTALL_DATA=@echo "INSTALL DATA $@" &&
QUIET_INSTALL_DOC=@echo "INSTALL DOC $@" &&
QUIET_CHECK=@echo "CHECK $@" &&
endif


