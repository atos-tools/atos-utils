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

HOSTCC=gcc
ifeq ($(PLUGGED_ON),)
 $(error PLUGGED_ON need to be set)
endif
PLUGGED_ON_GCC:=$(shell which $(PLUGGED_ON))

# Automatically detect gcc version, plugin include dir, if compiler is cpp, if compiler is 64 bits.
IS_CPP=$(shell nm $(PLUGGED_ON_GCC) | grep -w -c _Z5errorPKcz)
IS_64BITS=$(shell file $(PLUGGED_ON_GCC) | grep -c 'ELF 64-bit')

ifeq ($(PLUGGED_ON_KIND),target)
  GCC_VERSION=$(shell strings $(PLUGGED_ON_GCC) | grep 'STMicroelectronics/Linux Base' | cut -d' ' -f1 )
  GCC_PLUGIN_INCLUDE=$(wildcard $(shell dirname $(PLUGGED_ON_GCC))/../lib/gcc/*/$(GCC_VERSION)/plugin/include)
else
  GCC_VERSION=$(shell $(PLUGGED_ON_GCC) -dumpversion)
  GCC_PLUGIN_INCLUDE=$(shell $(PLUGGED_ON_GCC) -print-file-name=plugin)/include
endif



ifeq ($(PLUGGED_ON_KIND),host)
  PLUGIN_CC=$(shell which $(HOSTCC))
  RUNTIMELIB_CC=$(shell which $(HOSTCC))
else 
ifeq ($(PLUGGED_ON_KIND),cross)
  PLUGIN_CC=$(shell which $(HOSTCC))
  RUNTIMELIB_CC=$(PLUGGED_ON_GCC)
else
ifeq ($(PLUGGED_ON_KIND),target)
  PLUGIN_CC=$(shell which $(CROSSCC))
  RUNTIMELIB_CC=$(shell which $(CROSSCC))
else
 $(error PLUGGED_ON_KIND need to be set to one of the following host/cross/target)
endif
endif
endif




ifeq ($(wildcard $(PLUGGED_ON_GCC)),)
 $(error Cannot find compiler $(PLUGGED_ON_GCC))
endif
ifeq ($(wildcard $(GCC_PLUGIN_INCLUDE)/tree.h),)
 $(error Cannot find the plugin include directory $(GCC_PLUGIN_INCLUDE))
endif


PLUGIN_CFLAGS+=-fPIC -O2 -g3 -Wall
PLUGIN_CFLAGS+=-Iinclude -I$(GCC_PLUGIN_INCLUDE) -Iinclude/$(GCC_VERSION)
PLUGIN_LDFLAGS+=-fPIC -O2 -g3 -Wall -shared

ifneq ($(IS_CPP),0)
 PLUGIN_CFLAGS+=-xc++
endif
ifneq ($(PLUGGED_ON_KIND),target)
ifeq ($(IS_64BITS),0)
 PLUGIN_CFLAGS+=-m32 -DNEED_64BIT_HOST_WIDE_INT
 PLUGIN_LDFLAGS+=-m32
endif
endif



DumpBanner:
	@echo ""
	@echo "============= $(PLUGGED_ON_KIND) gcc =============="
	@echo "PLUGGED_ON_GCC       = $(PLUGGED_ON_GCC)"
	@echo "GCC_VERSION          = $(GCC_VERSION)"
	@echo "IS_CPP               = $(IS_CPP)"
	@echo "IS_64BITS            = $(IS_64BITS)"
	@echo "PLUGIN_INCLUDE       = $(GCC_PLUGIN_INCLUDE)"
	@echo "PLUGIN CFLAGS        = $(PLUGIN_CFLAGS)"
	@echo "======================================"


