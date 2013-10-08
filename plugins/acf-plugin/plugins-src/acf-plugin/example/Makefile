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

PLUGGED_ON_GCC=$(shell which $(PLUGGED_ON))

ACF_PLUGIN=-fplugin=../plugin/acf_plugin.so
ACF_PLUGIN_OPT=-fplugin-arg-acf_plugin-verbose -fplugin-arg-acf_plugin-csv_file=./test.csv

ifneq ($(PLUGGED_ON_KIND),target)
TO_TEST=acf-test-c acf-test-cpp acf-test-param acf-test-param-lto acf-test-args
endif

.PHONY: all check test clean $(TO_TEST)

all: check

check: test

test: $(TO_TEST)

acf-test-c: ./hello*.c ./test.csv
	$(QUIET) $(PLUGGED_ON_GCC) $(TESTCFLAGS) $(ACF_PLUGIN) $(ACF_PLUGIN_OPT) $< -o $@.out > $@.log 2>&1
	$(QUIET) if [ -z "`diff -q -N -i $@.log ./$@.log.ref`" ]; then \
		echo "$@: SUCCESS"; \
	else \
		echo "$@: Diff with reference output"; \
		exit 1; \
	fi

acf-test-cpp: ./hello*.cpp ./test.csv
	$(QUIET) $(PLUGGED_ON_GCC) -xc++ $(TESTCPPFLAGS) $(ACF_PLUGIN) $(ACF_PLUGIN_OPT) $< -o $@.out > $@.log 2>&1
	$(QUIET) if [ -z "`diff -q -N -i $@.log ./$@.log.ref`" ]; then \
		echo "$@: SUCCESS"; \
	else \
		echo "$@: Diff with reference output"; \
		exit 1; \
	fi

acf-test-param acf-test-param-lto: test-param*.c ./test.csv
	$(QUIET) if [ "$@" = "acf-test-param" ]; then \
		$(PLUGGED_ON_GCC) $(TESTCFLAGS) $(ACF_PLUGIN) $(ACF_PLUGIN_OPT) test-param*.c -o $@.out > $@.log 2>&1; \
	else \
		$(PLUGGED_ON_GCC) $(TESTCFLAGS) $(ACF_PLUGIN) $(ACF_PLUGIN_OPT) test-param*.c -flto -o $@.out > $@.log 2>&1; \
	fi
	$(QUIET) nm $@.out --print-size --radix=d | grep func_unroll > size.log 2>&1
	size1=`grep unroll1 size.log | sed -e "s/^[0-9]* \([0-9]*\\) [tT] .*/\1/"`; \
	size2=`grep unroll2 size.log | sed -e "s/^[0-9]* \([0-9]*\\) [tT] .*/\1/"`; \
	size4=`grep unroll4 size.log | sed -e "s/^[0-9]* \([0-9]*\\) [tT] .*/\1/"`; \
	if [ $$size1 -ge $$size2 ]; then \
	   echo "$@: --param max-unroll-times has no effect" ; \
	   exit 1; \
	elif [ $$size2 -ge $$size4 ]; then \
	   echo "$@: --param max-unroll-times has no effect" ; \
	   exit 1; \
	else \
	   echo "$@: SUCCESS"; \
	fi;

acf-test-arg:
	-$(QUIET) $(PLUGGED_ON_GCC) $(TESTCFLAGS) $(ACF_PLUGIN) $(ACF_PLUGIN_OPT) test-args.c -o $@.out > $@.log 2>&1
	if [ -n "`diff -q -N -i $@.log ./$(TESTNAME).ref`" ]; then \
	    echo "$(TESTNAME): FAILED" ; \
	    exit 1 ; \
        fi ; \
	echo "$(TESTNAME): SUCCESS"

acf-test-args: $(TESTARGS) ../plugin/acf_plugin.so ./test.csv
	$(MAKE) $(QUIET_S) acf-test-arg \
	ACF_PLUGIN_OPT="-fplugin-arg-acf_plugin-test" TESTNAME=acf-test-args1

	$(MAKE) $(QUIET_S) acf-test-arg \
	ACF_PLUGIN_OPT="-fplugin-arg-acf_plugin-verbose" TESTNAME=acf-test-args2

	$(MAKE) $(QUIET_S) acf-test-arg \
	ACF_PLUGIN_OPT="-fplugin-arg-acf_plugin-test -fplugin-arg-acf_plugin-verbose" TESTNAME=acf-test-args3

	$(MAKE) $(QUIET_S) acf-test-arg \
	ACF_PLUGIN_OPT="-fplugin-arg-acf_plugin-verbose -fplugin-arg-acf_plugin-test" TESTNAME=acf-test-args4

	$(MAKE) $(QUIET_S) acf-test-arg \
	ACF_PLUGIN_OPT="-fplugin-arg-acf_plugin-verbose -fplugin-arg-acf_plugin-csv_file=./test-args.csv" TESTNAME=acf-test-args5

	$(MAKE) $(QUIET_S) acf-test-arg \
	ACF_PLUGIN_OPT="-fplugin-arg-acf_plugin-verbose -fplugin-arg-acf_plugin-csv_file=./test-args.csv -fplugin-arg-acf_plugin-csv_file=./test-args.csv" TESTNAME=acf-test-args6

	$(MAKE) $(QUIET_S) acf-test-arg \
	ACF_PLUGIN_OPT="-fplugin-arg-acf_plugin-csv_file=./test-args.csv -fplugin-arg-acf_plugin-csv_file=./test-argsf.csv -fplugin-arg-acf_plugin-verbose" TESTNAME=acf-test-args7


clean:
	rm -f *.o *.log *.out
