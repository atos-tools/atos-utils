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

TESTS:=$(wildcard test*.sh)
DEPS=$(TESTS:.sh=)
ifeq ($(V),)
V_RUN=@
endif

.PHONY: all tests clean $(DEPS)

all: tests

tests: $(DEPS)

clean:
	rm -f *.out

# Force MAKEFLAGS= as we may run make in tests
# and we do not want to inherit -jxx option
$(DEPS): %: %.sh
	$(V_RUN)env MAKEFLAGS= ./$< >$(<:.sh=.out)

# Describe here possible tests dependencies
# For instance to put all tests under dependency of test001: 
# $(filter-out test001,$(DEPS)): test001
