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
DEPS=$(addprefix dep_,$(TESTS))

.PHONY: all $(DEPS)

all: $(DEPS)

$(DEPS): dep_%: %
	./$<

# Describe here possible tests dependencies
# For instance: dep_testYYY.sh: dep_testYYY.sh
$(filter-out dep_test001.sh,$(DEPS)): dep_test001.sh
