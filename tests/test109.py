#!/usr/bin/env python
#
#

import common
import os
import random
import itertools
import re

from atoslib import utils
from atoslib import atos_lib
from atoslib import process
from atoslib import generators
from atoslib import profile


TEST_CASE = "ATOS oprofile hot funcs"


oprof_file = os.path.join(
    common.SRCDIR, "tests", "resources", "proot_profile", "proot.oprof.out")
proot_file = os.path.join(
    common.SRCDIR, "tests", "resources", "proot_profile", "proot.oprof.out")

process.commands.copyfile(oprof_file, "oprof.out")
process.commands.copyfile(proot_file, "proot")

oprofile_format = profile.check_format("oprof.out")
assert oprofile_format

binary_list = profile.parse_binary_list(
    "oprof.out", oprofile_format, "", ".")
assert binary_list

samples = profile.parse_profile(
    "oprof.out", oprofile_format, binary_list)
assert samples

cold_hot_part = profile.partition_symbols(samples, 70)
cold, hot = cold_hot_part['proot']
print cold
print hot

assert len(hot) == 3
