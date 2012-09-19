INCLUDES=-I$(shell gcc $(CFLAGS) -print-file-name=plugin)/include -I$(builddir)include

cc1_path=$(shell $(TESTGCC) --print-prog-name=cc1)
hwi=$(shell objdump -t "$(cc1_path)" | grep target_newline | awk '{print $$5 - 0}')
ACF_PLUGIN_OPT=-fplugin=./acf_plugin.so -fplugin-arg-acf_plugin-verbose -fplugin-arg-acf_plugin-csv_file=$(testdir)/test.csv -fplugin-arg-acf_plugin-host_wide_int=$(hwi)

all: acf_plugin.so

generate-prep-sources:
	mkdir -p $(prepdir)
	$(COMPILER) $(CFLAGS) -E $(INCLUDES) $(srcdir)/plugin-utils.c -o $(prepdir)/plugin-utils_prep.c
	$(COMPILER) $(CFLAGS) -E $(INCLUDES) $(srcdir)/acf_plugin.c -o $(prepdir)/acf_plugin_prep.c
	$(COMPILER) $(CFLAGS) -E $(INCLUDES) $(srcdir)/acf_csv_reader.c -o $(prepdir)/acf_csv_reader_prep.c

test: acf-test-c acf-test-cpp

acf_plugin.so: $(SRC)
	$(COMPILER) $(CFLAGS) -fPIC $(INCLUDES) -c  $(prepdir)/acf_plugin_prep.c -o acf_plugin.o
	$(COMPILER) $(CFLAGS) -fPIC $(INCLUDES) -c  $(prepdir)/plugin-utils_prep.c -o plugin-utils.o
	$(COMPILER) $(CFLAGS) -fPIC $(INCLUDES) -c  $(prepdir)/acf_csv_reader_prep.c -o acf_csv_reader.o
	$(COMPILER) $(CFLAGS) -shared  acf_plugin.o plugin-utils.o acf_csv_reader.o -o $@

acf-test-c: $(TESTC) ./acf_plugin.so $(testdir)/test.csv
	-$(TESTGCC) $(TESTCFLAGS) $(ACF_PLUGIN_OPT) $< -o $@  | tee acf-test-c.log 2>&1
	@echo "Checking diff with reference output:"
	diff acf-test-c.log $(testdir)/acf-test-c.log.ref

acf-test-cpp: $(TESTCPP) ./acf_plugin.so $(testdir)/test.csv
	-$(TESTGPP) $(TESTCFLAGS) $(ACF_PLUGIN_OPT) $< -o $@ | tee acf-test-cpp.log 2>&1
	@echo "Checking diff with reference output:"
	diff acf-test-cpp.log $(testdir)/acf-test-cpp.log.ref

clean:
	\rm -f *.o acf_plugin.so acf-test-c acf-test-cpp acf-test-c.log acf-test-cpp.log