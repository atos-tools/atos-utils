#
# Copyright (C) 2013 STMicroelectronics
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

PLUGGED_ON_KIND=cross
PLUGGED_ON=armv7-linux-gcc

.PHONY: all check version clean

all:
	$(MAKE) all $(QUIET_S) -C plugin

check:
	$(MAKE) check $(QUIET_S) -C plugin
	$(MAKE) all $(QUIET_S) -C example

version:
	$(MAKE) version $(QUIET_S) -C plugin

clean:
	$(MAKE) clean $(QUIET_S) -C plugin
	$(MAKE) clean $(QUIET_S) -C example
