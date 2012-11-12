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
    print >>oprof, "00012080 312       2.9365  libjpeg.so.8             cjpeg                    forward_DCT.2772.1911"
    print >>oprof, "000121c0 282       2.6541  libjpeg.so.8             cjpeg                    forward_DCT_float.3017.1920"
    print >>oprof, "00010340 282       2.6541  libjpeg.so.8             cjpeg                    jpeg_fdct_float"
    print >>oprof, "000117c0 260       2.4471  libjpeg.so.8             cjpeg                    encode_mcu_gather.3441.1678"
    print >>oprof, "0000fe20 250       2.3529  libjpeg.so.8             cjpeg                    jpeg_fdct_islow"
    print >>oprof, "0000ad00 85        0.8000  libjpeg.so.8             djpeg                    decompress_onepass.8133"
    print >>oprof, "0005d524 78        0.7341  libc-2.10.2.so           cjpeg                    memccpy"
    print >>oprof, "0005daac 72        0.6776  libc-2.10.2.so           djpeg                    _wordcopy_fwd_dest_aligned"
    print >>oprof, "0005d000 47        0.4424  libc-2.10.2.so           djpeg                    memset"
    print >>oprof, "0005d5e0 44        0.4141  libc-2.10.2.so           cjpeg                    memcpy"
    print >>oprof, "00029080 38        0.3576  libjpeg.so.8             djpeg                    jpeg_huff_decode.9136"
    print >>oprof, "0005daac 36        0.3388  libc-2.10.2.so           cjpeg                    _wordcopy_fwd_dest_aligned"
    print >>oprof, "0002cbb0 21        0.1976  libjpeg.so.8             cjpeg                    __sdivsi3_i4i"
    print >>oprof, "00005420 20        0.1882  libjpeg.so.8             cjpeg                    compress_output.2452"
    print >>oprof, "0005d5e0 15        0.1412  libc-2.10.2.so           djpeg                    memcpy"
    print >>oprof, "0002cae0 12        0.1129  libjpeg.so.8             cjpeg                    __udivsi3_i4i"
    print >>oprof, "0000aa20 11        0.1035  libjpeg.so.8             cjpeg                    compress_data.2444"
    print >>oprof, "00022f80 6         0.0565  libjpeg.so.8             cjpeg                    pre_process_data.5513"
    print >>oprof, "00402760 5         0.0471  cjpeg                    cjpeg                    get_raw_row.1953"
    print >>oprof, "0005da20 5         0.0471  libc-2.10.2.so           cjpeg                    _wordcopy_fwd_aligned"
    print >>oprof, "00008040 4         0.0376  ld-2.10.2.so             djpeg                    _dl_relocate_object"
    print >>oprof, "00024880 4         0.0376  libjpeg.so.8             djpeg                    fill_input_buffer.7774"
    print >>oprof, "00023160 4         0.0376  libjpeg.so.8             djpeg                    jzero_far"
    print >>oprof, "00008040 3         0.0282  ld-2.10.2.so             cjpeg                    _dl_relocate_object"
    print >>oprof, "00053a20 3         0.0282  libc-2.10.2.so           cjpeg                    _IO_file_xsgetn"
    print >>oprof, "000541d6 3         0.0282  libc-2.10.2.so           cjpeg                    __underflow"
    print >>oprof, "00049e44 3         0.0282  libc-2.10.2.so           cjpeg                    fread"
    print >>oprof, "0008303c 3         0.0282  libc-2.10.2.so           cjpeg                    re_search_internal"
    print >>oprof, "00052778 3         0.0282  libc-2.10.2.so           djpeg                    new_do_write"
    print >>oprof, "00024a00 3         0.0282  libjpeg.so.8             cjpeg                    empty_output_buffer.7454"
    print >>oprof, "00012f80 3         0.0282  libjpeg.so.8             cjpeg                    jpeg_gen_optimal_table.3507"
    print >>oprof, "0001dfc0 3         0.0282  libjpeg.so.8             djpeg                    jpeg_read_scanlines"
    print >>oprof, "00010800 3         0.0282  libjpeg.so.8             djpeg                    sep_upsample.11564"
    print >>oprof, "00006c70 2         0.0188  ld-2.10.2.so             djpeg                    check_match.7927"
    print >>oprof, "00006dc0 2         0.0188  ld-2.10.2.so             djpeg                    do_lookup_x"
    print >>oprof, "00052860 2         0.0188  libc-2.10.2.so           cjpeg                    _IO_file_xsputn@@GLIBC_2.2"
    print >>oprof, "000236c0 2         0.0188  libjpeg.so.8             cjpeg                    access_virt_barray.14245"
    print >>oprof, "000292c0 2         0.0188  libjpeg.so.8             cjpeg                    jcopy_sample_rows"
    print >>oprof, "00014240 2         0.0188  libjpeg.so.8             cjpeg                    jpeg_write_scanlines"
    print >>oprof, "00011600 2         0.0188  libjpeg.so.8             cjpeg                    process_data_simple_main.3766.1637"
    print >>oprof, "0001e360 2         0.0188  libjpeg.so.8             djpeg                    process_data_simple_main.9855.1664"
    print >>oprof, "00400ec0 1         0.0094  cjpeg                    cjpeg                    main"
    print >>oprof, "00403720 1         0.0094  cjpeg                    cjpeg                    parse_switches.1623.constprop.0.1637"
    print >>oprof, "00403620 1         0.0094  djpeg                    djpeg                    keymatch"
    print >>oprof, "00400d20 1         0.0094  djpeg                    djpeg                    main"
    print >>oprof, "0000b220 1         0.0094  ld-2.10.2.so             cjpeg                    _dl_check_map_versions"
    print >>oprof, "0000a94c 1         0.0094  ld-2.10.2.so             cjpeg                    _dl_debug_initialize"
    print >>oprof, "000098b0 1         0.0094  ld-2.10.2.so             cjpeg                    _dl_fixup"
    print >>oprof, "0000681c 1         0.0094  ld-2.10.2.so             cjpeg                    _dl_load_cache_lookup"
    print >>oprof, "000070c4 1         0.0094  ld-2.10.2.so             cjpeg                    _dl_lookup_symbol_x"
    print >>oprof, "0000a484 1         0.0094  ld-2.10.2.so             cjpeg                    _dl_sort_fini"
    print >>oprof, "00006c70 1         0.0094  ld-2.10.2.so             cjpeg                    check_match.7927"
    print >>oprof, "00006dc0 1         0.0094  ld-2.10.2.so             cjpeg                    do_lookup_x"
    print >>oprof, "00011780 1         0.0094  ld-2.10.2.so             djpeg                    __udivsi3_i4i"
    print >>oprof, "0000c6cc 1         0.0094  ld-2.10.2.so             djpeg                    _dl_allocate_tls_init"
    print >>oprof, "000539d0 1         0.0094  libc-2.10.2.so           cjpeg                    _IO_file_read"
    print >>oprof, "0005411c 1         0.0094  libc-2.10.2.so           cjpeg                    _IO_switch_to_get_mode"
    print >>oprof, "000c8b10 1         0.0094  libc-2.10.2.so           cjpeg                    __udivsi3_i4i"
    print >>oprof, "000c785a 1         0.0094  libc-2.10.2.so           cjpeg                    _dl_addr"
    print >>oprof, "000556a0 1         0.0094  libc-2.10.2.so           cjpeg                    malloc_init_state"
    print >>oprof, "00054438 1         0.0094  libc-2.10.2.so           djpeg                    _IO_default_xsputn"
    print >>oprof, "000529a4 1         0.0094  libc-2.10.2.so           djpeg                    _IO_file_write@@GLIBC_2.2"
    print >>oprof, "00052860 1         0.0094  libc-2.10.2.so           djpeg                    _IO_file_xsputn@@GLIBC_2.2"
    print >>oprof, "000544dc 1         0.0094  libc-2.10.2.so           djpeg                    _IO_sgetn"
    print >>oprof, "0005411c 1         0.0094  libc-2.10.2.so           djpeg                    _IO_switch_to_get_mode"
    print >>oprof, "000c8b10 1         0.0094  libc-2.10.2.so           djpeg                    __udivsi3_i4i"
    print >>oprof, "000541d6 1         0.0094  libc-2.10.2.so           djpeg                    __underflow"
    print >>oprof, "0008f970 1         0.0094  libc-2.10.2.so           djpeg                    __write_nocancel"
    print >>oprof, "000c785a 1         0.0094  libc-2.10.2.so           djpeg                    _dl_addr"
    print >>oprof, "00049e44 1         0.0094  libc-2.10.2.so           djpeg                    fread"
    print >>oprof, "0004a354 1         0.0094  libc-2.10.2.so           djpeg                    fwrite"
    print >>oprof, "0005d0a0 1         0.0094  libc-2.10.2.so           djpeg                    mempcpy"
    print >>oprof, "0008303c 1         0.0094  libc-2.10.2.so           djpeg                    re_search_internal"
    print >>oprof, "00009780 1         0.0094  libgcc_s-4.6.3.so.1      cjpeg                    __gmon_start__"
    print >>oprof, "00009ee0 1         0.0094  libjpeg.so.8             cjpeg                    alloc_small.14217.1907"
    print >>oprof, "0000a780 1         0.0094  libjpeg.so.8             cjpeg                    compress_first_pass.2448"
    print >>oprof, "00029400 1         0.0094  libjpeg.so.8             cjpeg                    fullsize_downsample.5821"
    print >>oprof, "0002c400 1         0.0094  libjpeg.so.8             cjpeg                    jpeg_default_colorspace"
    print >>oprof, "00007ac0 1         0.0094  libjpeg.so.8             cjpeg                    jpeg_finish_compress"
    print >>oprof, "000053a0 1         0.0094  libjpeg.so.8             cjpeg                    start_iMCU_row.2201"
    print >>oprof, "000107a0 1         0.0094  libjpeg.so.8             djpeg                    fullsize_upsample.11573"
    print >>oprof, "0001cf60 1         0.0094  libjpeg.so.8             djpeg                    jpeg_set_marker_processor"
    print >>oprof, "0001f6e0 1         0.0094  libjpeg.so.8             djpeg                    start_pass_dpost.10975"

oprofile_format = profile.check_format("prof6.out")
assert oprofile_format
binary_list = profile.parse_binary_list("prof6.out", oprofile_format, "", ".")
assert binary_list
samples = profile.parse_profile("prof6.out", oprofile_format, binary_list)
assert samples
cold_hot_part = profile.partition_symbols(samples, 70)
assert cold_hot_part
cold, hot = cold_hot_part["libjpeg.so.8"]
assert len(cold) == 32
assert len(hot) == 7
