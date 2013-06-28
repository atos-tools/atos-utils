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

SRCDIR:=$(abspath $(dir $(firstword $(MAKEFILE_LIST))))
BUILDDIR=$(abspath .)
PREFIX=/usr/local
PLUGIN_PREFIX=$(PREFIX)/lib/gcc-plugins/acf-plugins
PROOT=$(BUILDDIR)/devimage/bin/proot
DISTROS=$(SRCDIR)/distros
PREBUILT=$(SRCDIR)/prebuilt
GUEST_SRCDIR=/opt/gcc-plugins
GUEST_BUILDDIR=$(GUEST_SRCDIR)
GUEST_PREBUILT=$(GUEST_SRCDIR)/prebuilt

PREP_BUILDDIR=$(BUILDDIR)/build_tree
PLUGIN_BUILDDIR=$(BUILDDIR)/build
PROOT32=env PATH=/usr/local/bin:/usr/bin:/bin $(PROOT) -B -w . -r $(DISTROS)/rhlinux-i586-5el-rootfs
PROOT64=env PATH=/usr/local/bin:/usr/bin:/bin $(PROOT) -B -w . -r $(DISTROS)/rhlinux-x86_64-5el-rootfs
RUN_i386=$(PROOT32) -b $(BUILDDIR)
RUN_x86_64=$(PROOT64) -b $(BUILDDIR)
PREP_RUN_i386=$(PROOT32) -b $(BUILDDIR):$(GUEST_BUILDDIR) 
PREP_RUN_x86_64=$(PROOT64) -b $(BUILDDIR):$(GUEST_BUILDDIR) 

GCC_COMPILERS=gcc-4.5.2 gcc-4.6.2 gcc-4.7.2 g++-4.7.2 
GCC_HOSTS=x86_64 i386
GCC_NATIVE_TARGETS_HOSTS=$(foreach host, $(GCC_HOSTS), $(host)/$(host))
GCC_CROSS_TARGETS=arm sh4
GCC_TARGETS_HOSTS=$(GCC_NATIVE_TARGETS_HOSTS) $(foreach host, $(GCC_HOSTS), $(addsuffix /$(host), $(GCC_CROSS_TARGETS)))
# Subset of GCC_TARGETS_HOSTS that can be actually tested.
# For now we are unable to test non native plugins without more effort.
GCC_CHECK_COMPILERS=gcc-4.5.2 gcc-4.6.2 g++-4.7.2
GCC_CHECK_TARGETS_HOSTS=$(GCC_NATIVE_TARGETS_HOSTS)
GCC_CHECK_COMPILER=

GCC_SUBDIRS:=$(foreach version, $(GCC_COMPILERS), $(addprefix $(version)/, $(GCC_TARGETS_HOSTS)))
GCC_CHECK_SUBDIRS:=$(foreach version, $(GCC_CHECK_COMPILERS), $(addprefix $(version)/, $(GCC_CHECK_TARGETS_HOSTS)))
CONFIGURE_PREP_PLUGINS:=$(addsuffix /Makefile.prep, $(addprefix $(PREP_BUILDDIR)/, $(GCC_SUBDIRS)))
ALL_PREP_PLUGINS:=$(addsuffix /all.phony, $(addprefix $(PREP_BUILDDIR)/, $(GCC_SUBDIRS)))
CC=gcc
CXX=g++
PLUGIN_gcc=$(CC)
PLUGIN_gpp=$(CXX)
PLUGIN_CFLAGS=-O2 -Wall

# Functions
gcc_version=$(shell echo $1 | sed 's!g..-\([^/]*\)/.*!\1!')
gcc_major=$(shell echo $1 | sed 's!g..-\([^.]*\)\.[^.]*\.[^/]*/.*!\1!')
gcc_minor=$(shell echo $1 | sed 's!g..-[^.]*\.\([^.]*\)\.[^/]*/.*!\1!')
gcc_patch=$(shell echo $1 | sed 's!g..-[^.]*\.[^.]*\.\([^/]*\)/.*!\1!')
gcc_target=$(shell echo $1 | sed 's!g..-[^/]*/\([^/]*\).*!\1!')
gcc_host=$(shell echo $1 | sed 's!g..-[^/]*/[^/]*/\([^/]*\).*!\1!')
gcc_or_gpp=$(shell echo $1 | sed 's!\(g..\)-[^/]*/.*!\1!')
compiler_varname=$(shell echo $(call gcc_or_gpp,$1) | sed 's!g++!gpp!')
plugin_subdir=$(call gcc_or_gpp,$1)-$(call gcc_version,$1)/$(call gcc_target,$1)/$(call gcc_host,$1)
prebuilt_subdir=$(call gcc_host,$1)/gcc-$(call gcc_version,$1)
prep_compiler=$(call prebuilt_subdir,$1)/bin/$(PLUGIN_$(call compiler_varname,$1))
prep_cppflags=$(shell if [ "$(call gcc_target,$1)" = arm -o "$(call gcc_target,$1)" = sh4 ]; then echo "-DNEED_64BIT_HOST_WIDE_INT"; else echo ""; fi)
prep_cflags=-O2 -Wall
# Avoid builtins that may vary with compilers versions.
prep_cflags+=-fno-builtin -ansi
# Tell files that include string.h that it defines correct C++ protos, this avoids use of builtins for string functions in gcc >= 4.6.
prep_cflags+=-D__CORRECT_ISO_CPP_STRING_H_PROTO
prep_run=$(PREP_RUN_$(call gcc_host,$1))
run=$(RUN_$(call gcc_host,$1))
plugin_compiler=$(PLUGIN_$(call compiler_varname,$1))
plugin_cppflags=
plugin_cflags=$(shell if [ "$(call gcc_host,$1)" = i386 ]; then echo "-m32 $(PLUGIN_CFLAGS)"; else echo "$(PLUGIN_CFLAGS)"; fi)
prebuilt_gcc=$(call prebuilt_subdir,$1)/bin/$(PLUGIN_gcc)
prebuilt_gpp=$(call prebuilt_subdir,$1)/bin/$(PLUGIN_gpp)
test_gcc=$(RUN_$(call gcc_host,$1)) $(PREBUILT)/$(call prebuilt_gcc,$1)
test_gpp=$(RUN_$(call gcc_host,$1)) $(PREBUILT)/$(call prebuilt_gpp,$1)

CONFIGURE_PLUGINS:=$(addsuffix /Makefile.plugin, $(addprefix $(PLUGIN_BUILDDIR)/, $(GCC_SUBDIRS)))
ALL_PLUGINS:=$(addsuffix /all.phony, $(addprefix $(PLUGIN_BUILDDIR)/, $(GCC_SUBDIRS)))
INSTALLED_PLUGINS:=$(addsuffix /acf_plugin.so, $(addprefix $(PLUGIN_PREFIX)/, $(GCC_SUBDIRS)))
CHECK_PLUGINS=$(addsuffix /check.phony, $(addprefix $(PLUGIN_BUILDDIR)/, $(GCC_CHECK_SUBDIRS)))

.FORCE:
.PHONY: all configure clean distclean install check tests prep all-prep clean-prep distclean-prep

default:
	echo $(ALL_PREP_PLUGINS)

all: $(ALL_PLUGINS)

configure: $(CONFIGURE_PLUGINS)

$(CONFIGURE_PLUGINS): $(PLUGIN_BUILDDIR)/%/Makefile.plugin: $(SRCDIR)/Makefile.plugin.in
	@echo "Configure plugin for $* with compiler $(call plugin_compiler,$*) $(call plugin_cflags,$*) $(call plugin_cppflags,$*) from prep $(call plugin_subdir,$*)"
	mkdir -p $(PLUGIN_BUILDDIR)/$(call plugin_subdir,$*) && \
	cd $(PLUGIN_BUILDDIR)/$(call plugin_subdir,$*) && \
	$(SRCDIR)/configure --configure-plugin --with-prep=$(PREP_BUILDDIR)/$(call plugin_subdir,$*) CC="$(call plugin_compiler,$*)" CFLAGS="$(call plugin_cflags,$*)" CPPFLAGS="$(call plugin_cppflags,$*)"

$(ALL_PLUGINS): $(PLUGIN_BUILDDIR)/%/all.phony: $(PLUGIN_BUILDDIR)/%/Makefile.plugin
	@echo "Building plugin for $*"
	$(QUIET)\
	$(MAKE) $(QUIET_S) -C $(PLUGIN_BUILDDIR)/$(call plugin_subdir,$*) -f Makefile.plugin all

clean:
	$(QUIET_CLEAN)for dir in $(dir $(ALL_PLUGINS)); do [ -d "$$dir" -a -f "$$dir/Makefile.plugin" ] && $(MAKE) -s -C $$dir -f Makefile.plugin clean || true; done

distclean: clean
	$(QUIET_DISCLEAN)for dir in $(dir $(ALL_PLUGINS)); do rm -f $$dir/Makefile.plugin $$dir/config.status; done

install: $(INSTALLED_PLUGINS) 

check: $(CHECK_PLUGINS)

tests: check

$(CHECK_PLUGINS): $(PLUGIN_BUILDDIR)/%/check.phony: $(PLUGIN_BUILDDIR)/%/all.phony $(PROOT)
	$(QUIET_CHECK)\
	$(MAKE) $(QUIET_S) -C $(PLUGIN_BUILDDIR)/$(call plugin_subdir,$*) -f Makefile.plugin check TESTGCC="$(call test_gcc,$*)" TESTGPP="$(call test_gpp,$*)"

#
# Section for preprocessed file
#
prep: all-prep

all-prep: $(ALL_PREP_PLUGINS)

$(CONFIGURE_PREP_PLUGINS): $(PREP_BUILDDIR)/%/Makefile.prep: $(SRCDIR)/Makefile.prep.in $(PROOT)
	@echo "Configure prep plugin for $* with compiler $(call prep_compiler,$*) $(call prep_cflags,$*) $(call prep_cppflags,$*)" 
	$(QUIET)\
	mkdir -p $(PREP_BUILDDIR)/$(call plugin_subdir,$*) && \
	cd $(PREP_BUILDDIR)/$(call plugin_subdir,$*) && \
	$(call prep_run,$*) $(GUEST_SRCDIR)/configure --configure-prep CC="$(GUEST_PREBUILT)/$(call prep_compiler,$*)" CFLAGS="$(call prep_cflags,$*)" CPPFLAGS="$(call prep_cppflags,$*)"

$(ALL_PREP_PLUGINS): $(PREP_BUILDDIR)/%/all.phony: $(PREP_BUILDDIR)/%/Makefile.prep
	@echo "Building prep plugin for $*"
	$(QUIET)\
	cd $(PREP_BUILDDIR)/$(call plugin_subdir,$*) && \
	$(call prep_run,$*) $(MAKE) $(QUIET_S) -f Makefile.prep all

clean-prep:
	$(QUIET_CLEAN)for dir in $(dir $(ALL_PREP_PLUGINS)); do rm -f $$dir/prep/*.c; done

distclean-prep: clean-prep
	$(QUIET_DISTCLEAN)for dir in $(dir $(ALL_PREP_PLUGINS)); do rm -f $$dir/Makefile.prep $$dir/config.status; done


#
# Section for proot local build
#
$(BUILDDIR)/devimage/bin/proot:
	mkdir -p $(BUILDDIR)/build/proot
	$(MAKE) $(QUIET_S) -C $(BUILDDIR)/build/proot -f $(SRCDIR)/proot/src/GNUmakefile all
	$(MAKE) $(QUIET_S) -C $(BUILDDIR)/build/proot -f $(SRCDIR)/proot/src/GNUmakefile install PREFIX=$(BUILDDIR)/devimage


#
# Rules for installation
#
$(INSTALLED_PLUGINS): $(PLUGIN_PREFIX)/%/acf_plugin.so: $(PLUGIN_BUILDDIR)/%/all.phony
	$(QUIET_INSTALL_EXE)install -D -m 755 $(PLUGIN_BUILDDIR)/$*/acf_plugin.so $@

#
# Manage verbose output
#
ifeq ($(V),1)
QUIET_CONFIGURE=
QUIET_ALL=
QUIET_CHECK=
QUIET_PREP_CONFIGURE=
QUIET_PREP_ALL=
QUIET_CLEAN=
QUIET_DISTCLEAN=
QUIET_INSTALL_DIR=
QUIET_INSTALL_EXE=
QUIET_MAKE=$(MAKE)
QUIET_S=
else
QUIET_CONFIGURE=@echo "CONFIGURE PLUGIN $*" &&
QUIET_ALL=@echo "BUILD PLUGIN $*" &&
QUIET_CHECK=@echo "CHECK PLUGIN $*" &&
QUIET_PREP_CONFIGURE=@echo "CONFIGURE PREP $*" &&
QUIET_PREP_ALL=@echo "BUILD PREP $*" &&
QUIET_CLEAN=@echo "CLEAN" &&
QUIET_DISTCLEAN=@echo "DISTCLEAN" &&
QUIET_INSTALL_DIR=@echo "INSTALL DIR $@" &&
QUIET_INSTALL_EXE=@echo "INSTALL EXE $@" &&
QUIET_LOCAL_INSTALL_DIR=@echo "MKDIR $@" &&
QUIET_LOCAL_INSTALL_EXE=@echo "COPY EXE $@" &&
QUIET_S=-s
QUIET=@
endif
