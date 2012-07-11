#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS lib reports"

$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c"

$ROOT/bin/atos-opt -r -a "-O2"

$ROOT/bin/atos-opt -r -a "-O3"

$ROOT/lib/atos/atos_lib.py report > tmp_report.txt
#         |      sha1-c
#  OPT-O2 | 140  +85.7%
#  OPT-O3 | 150  +73.3%
#  REF    | 260   +0.0%
[ `cat tmp_report.txt | wc -l` -eq 4 ]

$ROOT/lib/atos/atos_lib.py report -X  > tmp_report.txt
#         |      OPT-O2 |      OPT-O3 |         REF
#  sha1-c | 150  +73.3% | 120 +116.7% | 260   +0.0%
[ `cat tmp_report.txt | wc -l` -eq 2 ]

$ROOT/lib/atos/atos_lib.py report -X -tG1:sha1-c+G2:sha1-c,sha1-c  > tmp_report.txt
#     |      OPT-O2 |      OPT-O3 |         REF
#  G1 | 150  +73.3% | 120 +116.7% | 260   +0.0%
#  G2 | 150  +73.3% | 120 +116.7% | 260   +0.0%

$ROOT/lib/atos/atos_lib.py report -v REF,OPT-O2  > tmp_report.txt
#         |      sha1-c
#  REF    | 260   +0.0%
#  OPT-O2 | 150  +73.3%

$ROOT/lib/atos/atos_lib.py report -mstdev -vOPT-O2 > tmp_report.txt
#  OPT-O2 |    AVG | NOISE | STDEV
#  sha1-c | 150.00 | 0.00% | 0.00%






