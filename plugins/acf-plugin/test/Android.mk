LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE_TAGS := tests

LOCAL_SRC_FILES:= hello.cpp

LOCAL_MODULE := acf-test-cpp

LOCAL_CFLAGS += $(ACF_OPT) -fplugin=out/host/linux-x86/obj/lib/acf_plugin.so -fplugin-arg-acf_plugin-verbose -fplugin-arg-acf_plugin-csv_file=external/gcc-plugins/acf-plugin/test/test.csv

LOCAL_LDFLAGS += $(ACF_LDOPT)

LOCAL_ADDITIONAL_DEPENDENCIES := out/host/linux-x86/obj/lib/acf_plugin.so external/gcc-plugins/acf-plugin/test/test.csv

include $(BUILD_EXECUTABLE)



include $(CLEAR_VARS)

LOCAL_MODULE_TAGS := tests

LOCAL_SRC_FILES:= hello.c

LOCAL_MODULE := acf-test-c

LOCAL_CFLAGS += $(ACF_OPT) -fplugin=out/host/linux-x86/obj/lib/acf_plugin.so -fplugin-arg-acf_plugin-verbose -fplugin-arg-acf_plugin-csv_file=external/gcc-plugins/acf-plugin/test/test.csv

LOCAL_LDFLAGS += $(ACF_LDOPT)

LOCAL_ADDITIONAL_DEPENDENCIES := out/host/linux-x86/obj/lib/acf_plugin.so external/gcc-plugins/acf-plugin/test/test.csv

include $(BUILD_EXECUTABLE)