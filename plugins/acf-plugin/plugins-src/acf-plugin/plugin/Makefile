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

include ../../common.mk

# if version.mk exists, add -DVERSION=<sha1>
-include ../../version.mk

CPPLINT=../../contrib/cpplint/cpplint.py

.PHONY: all clean check check-style

all: DumpBanner acf_plugin.so

# acf gcc plugin
%.o: src/%.c
	$(PLUGIN_CC) $(PLUGIN_CFLAGS) -c $< -o $@

acf_plugin.so: acf_csv_reader.o plugin-utils.o acf_plugin.o
	$(PLUGIN_CC) $(PLUGIN_LDFLAGS) $^ -o $@

check: check-style

check-style:
	$(CPPLINT) --filter=-readability/casting,-build/include,-build/header_guard src/*.h src/*.c

clean:
	rm -f *.o *.so
