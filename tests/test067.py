#!/usr/bin/env python
#
#

import common
import os
import random
import itertools
import re

from atos import utils
from atos import atos_lib
from atos import process
from atos import generators
from atos import profile


TEST_CASE = "ATOS oprofile output formats"

# todo: add test for formats 1, 2, 3, 5

# format == 4
process.commands.touch("libjpeg.so.8")

with open("prof6.out", "w") as oprof:
    print >>oprof, "warning: /no-vmlinux could not be found."
    print >>oprof, "CPU: CPU with timer interrupt, speed 0 MHz (estimated)"
    print >>oprof, "Profiling through timer interrupt"
    print >>oprof, "vma      samples  %        image name               app name                 symbol name"
    print >>oprof, "000145a0 1626     15.3035  libjpeg.so.8             djpeg                    decode_mcu.9173"
    print >>oprof, "0000e800 1004      9.4494  libjpeg.so.8             cjpeg                    jpeg_fdct_16x16"
    print >>oprof, "00008980 956       8.9976  libjpeg.so.8             djpeg                    jpeg_idct_float"
    print >>oprof, "00003a80 943       8.8753  libjpeg.so.8             cjpeg                    rgb_ycc_convert.2715"
    print >>oprof, "00007f60 910       8.5647  libjpeg.so.8             djpeg                    jpeg_idct_islow"
    print >>oprof, "00005720 843       7.9341  libjpeg.so.8             cjpeg                    encode_mcu_huff.3430"
    print >>oprof, "000286e0 750       7.0588  libjpeg.so.8             djpeg                    ycc_rgb_convert.8429"
    print >>oprof, "00028f40 573       5.3929  libjpeg.so.8             djpeg                    jpeg_fill_bit_buffer.8851"
    print >>oprof, "00000000 527       4.9600  no-vmlinux               djpeg                    /no-vmlinux"
    print >>oprof, "00000000 512       4.8188  no-vmlinux               cjpeg                    /no-vmlinux"
oprofile_format = profile.check_format("prof6.out")
assert oprofile_format
binary_list = profile.parse_binary_list("prof6.out", oprofile_format, "", ".")
assert binary_list
samples = profile.parse_profile("prof6.out", oprofile_format, binary_list)
assert samples
assert len(samples.values()[0]) == 2 # cjpeg, djpeg

