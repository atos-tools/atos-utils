LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE_TAGS := optional

LOCAL_SRC_FILES:= acf_plugin.c plugin-utils.c acf_csv_reader.c

LOCAL_MODULE := acf_plugin

LOCAL_ALLOW_UNDEFINED_SYMBOLS := 1

LOCAL_C_INCLUDES += $(shell $(TARGET_CC) -print-file-name=plugin)/include

LOCAL_CFLAGS += $(ACF_OPT)

include $(BUILD_HOST_SHARED_LIBRARY)
