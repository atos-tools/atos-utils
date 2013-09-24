
cc1_path=$(shell $(TESTGCC) --print-prog-name=cc1)
ACF_PLUGIN_OPT=-fplugin=./acf_plugin.so -fplugin-arg-acf_plugin-verbose -fplugin-arg-acf_plugin-csv_file=$(testdir)/test.csv

all: acf_plugin.so

check: test

test: acf-test-c acf-test-cpp acf-test-param acf-test-param-lto acf-test-args

acf_plugin.so: $(SRC)
	$(COMPILER) $(CFLAGS) $(CPPFLAGS) -fPIC -shared  $(SRC) -o $@

acf-test-c: $(TESTC) ./acf_plugin.so $(testdir)/test.csv
	-$(TESTGCC) $(TESTCFLAGS) $(ACF_PLUGIN_OPT) $< -o $@.out > $@.log 2>&1
	if `diff -q -N $@.log $(testdir)/$@.log.ref`; then \
		echo "$@: SUCCESS"; \
	else \
		echo "$@: Diff with reference output"; \
		exit 1; \
	fi

acf-test-cpp: $(TESTCPP) ./acf_plugin.so $(testdir)/test.csv
	-$(TESTGPP) $(TESTCPPFLAGS) $(ACF_PLUGIN_OPT) $< -o $@.out > $@.log 2>&1
	if `diff -q -N $@.log $(testdir)/$@.log.ref`; then \
		echo "$@: SUCCESS"; \
	else \
		echo "$@: Diff with reference output"; \
		exit 1; \
	fi

acf-test-param acf-test-param-lto: $(TESTPARAM) ./acf_plugin.so $(testdir)/test.csv
	if [ "$@" = "acf-test-param" ]; then \
		$(TESTGCC) $(TESTCFLAGS) $(ACF_PLUGIN_OPT) $(TESTPARAM) -o $@.out > $@.log 2>&1; \
	else \
		$(TESTGCC) $(TESTCFLAGS) $(ACF_PLUGIN_OPT) $(TESTPARAM) -flto -o $@.out > $@.log 2>&1; \
	fi
	nm $@.out --print-size --radix=d | grep func_unroll > size.log 2>&1
	size1=`grep unroll1 size.log | sed -e "s/^[0-9]* \([0-9]*\\) T .*/\1/"`; \
	size2=`grep unroll2 size.log | sed -e "s/^[0-9]* \([0-9]*\\) T .*/\1/"`; \
	size4=`grep unroll4 size.log | sed -e "s/^[0-9]* \([0-9]*\\) T .*/\1/"`; \
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
	-$(TESTGCC) $(TESTCFLAGS) $(ACF_PLUGIN_OPT) $(TESTARGS) -o $@.out > $@.log 2>&1
	if ! `diff -i -q $@.log $(testdir)/$(TESTNAME).ref` 2>/dev/null; then \
	    echo "ERROR at $(TESTNAME)" ; \
	    exit 1 ; \
        fi ; \
	echo "$(TESTNAME): SUCCESS"

acf-test-args: $(TESTARGS) ./acf_plugin.so $(testdir)/test.csv
	$(MAKE) -f $(builddir)/Makefile.plugin acf-test-arg \
	ACF_PLUGIN_OPT="-fplugin=./acf_plugin.so -fplugin-arg-acf_plugin-test" TESTNAME=test-args1

	$(MAKE) -f $(builddir)/Makefile.plugin acf-test-arg \
	ACF_PLUGIN_OPT="-fplugin=./acf_plugin.so -fplugin-arg-acf_plugin-verbose" TESTNAME=test-args2

	$(MAKE) -f $(builddir)/Makefile.plugin acf-test-arg \
	ACF_PLUGIN_OPT="-fplugin=./acf_plugin.so -fplugin-arg-acf_plugin-test -fplugin-arg-acf_plugin-verbose" TESTNAME=test-args3

	$(MAKE) -f $(builddir)/Makefile.plugin acf-test-arg \
	ACF_PLUGIN_OPT="-fplugin=./acf_plugin.so -fplugin-arg-acf_plugin-verbose -fplugin-arg-acf_plugin-test" TESTNAME=test-args4

	$(MAKE) -f $(builddir)/Makefile.plugin acf-test-arg \
	ACF_PLUGIN_OPT="-fplugin=./acf_plugin.so -fplugin-arg-acf_plugin-verbose -fplugin-arg-acf_plugin-csv_file=$(testdir)/test-args.csv" TESTNAME=test-args5

	$(MAKE) -f $(builddir)/Makefile.plugin acf-test-arg \
	ACF_PLUGIN_OPT="-fplugin=./acf_plugin.so -fplugin-arg-acf_plugin-verbose -fplugin-arg-acf_plugin-csv_file=$(testdir)/test-args.csv -fplugin-arg-acf_plugin-csv_file=$(testdir)/test-args.csv" TESTNAME=test-args6

	$(MAKE) -f $(builddir)/Makefile.plugin acf-test-arg \
	ACF_PLUGIN_OPT="-fplugin=./acf_plugin.so -fplugin-arg-acf_plugin-csv_file=$(testdir)/test-args.csv -fplugin-arg-acf_plugin-csv_file=$(testdir)/test-argsf.csv -fplugin-arg-acf_plugin-verbose" TESTNAME=test-args7


clean:
	\rm -f *.o acf_plugin.so acf-test-c.* acf-test-cpp.* acf-test-param.* acf-test-param-lto.* acf-test-arg.* size.log
