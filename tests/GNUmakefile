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
TESTS:=$(sort $(notdir $(wildcard $(srcdir)test*.sh $(srcdir)test*.py)))
CHKS=$(addsuffix .chk,$(TESTS))
ERRS=$(addsuffix .err,$(TESTS))
ifeq ($(V),)
V_RUN=@
endif
COVERAGE_DIR=$(abspath .)/coverage
ifneq ($(COVERAGE),)
COVERAGE_OPTS=PYTHONPATH=$(PYTHONPATH):$(srcdir)
COVERAGE_OPTS+=ATOS_COVERAGE_DIR=$(COVERAGE_DIR)
endif
FORCE=.FORCE

.PHONY: all tests clean distclean $(CHKS) .FORCE

all: tests

tests: tests_report

coverage:
	mkdir -p $(COVERAGE_DIR)
	cd $(COVERAGE_DIR) && rm -rf .coverage* coverage
	$(MAKE) COVERAGE=1 -f $(firstword $(MAKEFILE_LIST)) tests
	cd $(COVERAGE_DIR) && coverage combine
	cd $(COVERAGE_DIR) && coverage html -d html --include='/*/bin/*,/*/lib/atos/python/atos/*,/*/lib/atos/atos-*' --omit '/*/atos-graph'
	cd $(COVERAGE_DIR) && coverage report --include='/*/bin/*,/*/lib/atos/python/atos/*,/*/lib/atos/atos-*' --omit '/*/atos-graph' | tail -1 | awk '{print "COVERAGE", $$6 , ":", ($$2 + $$4) - ($$3 + $$5), "/", ($$2 + $$4)}'

clean: clean-coverage
	rm -f *.out *.err *.pyc tests_report.txt

clean-coverage:
	if [ -d $(COVERAGE_DIR) ]; then cd $(COVERAGE_DIR) && rm -rf .coverage* coverage; fi

distclean: clean

tests_report: $(srcdir)report.sh $(ERRS)
	$(V_RUN)$(srcdir)report.sh $(ERRS) >tests_report.txt; \
	res=$$?; cat tests_report.txt; exit $$res

$(CHKS): %.chk: %.err

# Force MAKEFLAGS= as we may run make in tests
# and we do not want to inherit -jxx option
$(ERRS): %.err: $(srcdir)% $(FORCE)
	$(V_RUN)env MAKEFLAGS= ROOT=$${ROOT:-$(abspath ..)} SRCDIR=$${SRCDIR:-$(abspath $(srcdir)..)} $(COVERAGE_OPTS) $(srcdir)$* 2>&1 >$*.out | tee $*.err
