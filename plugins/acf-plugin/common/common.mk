
cc1_path=$(shell $(TESTGCC) --print-prog-name=cc1)
ACF_PLUGIN_OPT=-fplugin=./acf_plugin.so -fplugin-arg-acf_plugin-verbose -fplugin-arg-acf_plugin-csv_file=$(testdir)/test.csv

all: acf_plugin.so

check: test

test:

acf_plugin.so: $(SRC)
	$(COMPILER) $(CFLAGS) $(CPPFLAGS) -fPIC -shared  $(SRC) -o $@

clean:
	\rm -f *.o acf_plugin.so
