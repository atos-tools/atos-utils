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
# Makefile for ATOS tests
#

srcdir:=$(dir $(firstword $(MAKEFILE_LIST)))
TESTS:=$(notdir $(wildcard $(srcdir)test*.sh))
DEPS=$(TESTS:.sh=)
ERRS=$(TESTS:.sh=.err)
ifeq ($(V),)
V_RUN=@
endif
FORCE=.FORCE

.PHONY: all tests clean distclean $(DEPS) .FORCE

all: tests

tests: tests_report

clean:
	rm -f *.out *.err tests_report.txt

distclean: clean

tests_report: $(srcdir)report.sh $(ERRS)
	$(V_RUN)cat $(ERRS) | $(srcdir)report.sh >tests_report.txt; \
	res=$$?; cat tests_report.txt; exit $$res

$(DEPS): %: %.err

# Force MAKEFLAGS= as we may run make in tests
# and we do not want to inherit -jxx option
$(ERRS): %.err: $(srcdir)%.sh $(FORCE)
	$(V_RUN)env MAKEFLAGS= ROOT=$${ROOT:-$(abspath ..)} SRCDIR=$${SRCDIR:-$(abspath $(srcdir)..)} $(srcdir)$*.sh 2>&1 >$*.out | tee $*.err
