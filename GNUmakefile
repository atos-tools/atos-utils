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
PREFIX=/usr/local
VSTAMP=version.stamp
VERSION:=$(shell $(srcdir)/config/update_version.sh $(VSTAMP))

CONFIG_SCRIPTS_IN=atos-audit.in atos-raudit.in atos-deps.in atos-opt.in atos-run.in atos-profile.in atos-explore.in atos-play.in atos-graph.in
CONFIG_SCRIPTS=$(CONFIG_SCRIPTS_IN:%.in=%)

ALL_CONFIG_FILES_IN=$(CONFIG_SCRIPTS_IN)

ALL_CONFIG_FILES=$(ALL_CONFIG_FILES_IN:%.in=%)

ALL_FILES=$(ALL_CONFIG_FILES)

INSTALL_EXES=atos-audit atos-raudit atos-deps atos-opt atos-run atos-profile atos-explore atos-play atos-graph
INSTALLED_EXES=$(addprefix $(PREFIX)/bin/,$(INSTALL_EXES))

.PHONY: all clean distclean install check check-python-dependencies examples examples-nograph

all: $(ALL_FILES)

clean:
	$(QUIET_CLEAN)rm -f *.tmp

distclean:
	$(QUIET_DISTCLEAN)rm -f $(ALL_CONFIG_FILES) $(VSTAMP)

install: $(INSTALLED_EXES)

check: check-python-dependencies

examples:
	@echo "   Running examples."
	@echo "   Should take around 1-2 minutes per example"
	@echo "   The resulting graph is displayed for each example"
	$(MAKE) all check
	$(MAKE) examples-sha1-c examples-sha1

examples-nograph:
	@echo "   Running examples."
	@echo "   Should take around 1-2 minutes per example"
	$(MAKE) all check
	$(MAKE) NOGRAPH=1 examples-sha1-c examples-sha1

examples-sha1-c:
	cd examples/sha1-c && ../../atos-explore -f -b "gcc -O2 -o sha1-c sha.c sha1.c" -r ./run.sh -c && [ "$(NOGRAPH)" = 1 ] || (../../atos-graph &)

examples-sha1:
	cd examples/sha1 && ../../atos-explore -b "make clean sha" -r ./run.sh -c && [ "$(NOGRAPH)" = 1 ] || (../../atos-graph &)


#
# Rules for config files
#
$(CONFIG_SCRIPTS): $(VSTAMP)
$(CONFIG_SCRIPTS): %: %.in
	$(QUIET_IN)sed -e 's!@VERSION@!$(VERSION)!g' <$< >$@.tmp && chmod 755 $@.tmp && mv $@.tmp $@

#
# Rules for python-checks
#
check-python-dependencies: config/python_checks
	$(QUIET_CHECK)$<

#
# Rules for installation
#
$(PREFIX)/bin $(PREFIX)/lib:
	$(QUIET_INSTALL_DIR)install -d $@

$(INSTALLED_EXES): $(PREFIX)/bin

$(INSTALLED_EXES): $(PREFIX)/bin/%: %
	$(QUIET_INSTALL_EXE)install -m 755 $< $(PREFIX)/bin

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
endif


