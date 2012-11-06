#!/usr/bin/env python
#
#


import common
import os, sys
from atos import profile
from atos import process

TEST_CASE = "ATOS profile defect test 1 - Should be expected to fail"

resdir = os.path.join(common.SRCDIR, "tests", "resources", "profile_defect_1")
fct_map = profile.read_function_to_file_map(os.path.join(resdir, "fctmap.out"))
# Main appears in three different executables
assert(len(fct_map['main']) == 3)

# Fake sha executable, it is actually an artificial dependency
process.commands.touch("sha")
cold_files, hot_files = profile.partition_object_files(
    imgpath="sha", hot_th=80, fct_map=fct_map,
    oprof_output=os.path.join(resdir, "oprof.out"))

# The hot files list is actually sha1.o plus all three
# files associated to main.
# This should be changed such that only object files
# associated to sha binary are taken.
# Commented out, for now 4 files are returned.
#assert(len(hot_files) == 2)
assert(len(hot_files) == 4)


