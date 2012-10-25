
cc1_path=$(shell $(TESTGCC) --print-prog-name=cc1)
hwi=$(shell objdump -t "$(cc1_path)" | grep target_newline | awk '{print $$5 - 0}')
ACF_PLUGIN_OPT=-fplugin=./acf_plugin.so -fplugin-arg-acf_plugin-verbose -fplugin-arg-acf_plugin-csv_file=$(testdir)/test.csv -fplugin-arg-acf_plugin-host_wide_int=$(hwi)

all: acf_plugin.so

check: test

test: acf-test-c acf-test-cpp

acf_plugin.so: $(SRC)
	$(COMPILER) $(CFLAGS) $(CPPFLAGS) -fPIC -shared  $(SRC) -o $@

acf-test-c: $(TESTC) ./acf_plugin.so $(testdir)/test.csv
	-$(TESTGCC) $(TESTCFLAGS) $(ACF_PLUGIN_OPT) $< -o $@  2>&1 | tee acf-test-c.log
	@echo "Checking diff with reference output:"
	diff acf-test-c.log $(testdir)/acf-test-c.log.ref

acf-test-cpp: $(TESTCPP) ./acf_plugin.so $(testdir)/test.csv
	-$(TESTGPP) $(TESTCFLAGS) $(ACF_PLUGIN_OPT) $< -o $@ 2>&1 | tee acf-test-cpp.log
	@echo "Checking diff with reference output:"
	diff acf-test-cpp.log $(testdir)/acf-test-cpp.log.ref

clean:
	\rm -f *.o acf_plugin.so acf-test-c acf-test-cpp acf-test-c.log acf-test-cpp.log