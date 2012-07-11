#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS run add_result"

$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c" \
    -C atos-config

$ROOT/bin/atos-run -C atos-config -a "-O2" 2> tmp_result_1
[ -f tmp_result_1 ]
[ `cat tmp_result_1 | grep "ATOS: sha1-c: OPT-O2: size:" | wc -l` -eq 1 ]

$ROOT/bin/atos-run -C atos-config -a "-O2" -o tmp_result_2
[ -f tmp_result_2 ]
[ `cat tmp_result_2 | grep "ATOS: sha1-c: OPT-O2: size:" | wc -l` -eq 1 ]

$ROOT/bin/atos-run -C atos-config -a "-O2" -r
[ -f atos-config/results.db ]
[ `cat atos-config/results.db | grep "ATOS: sha1-c: OPT-O2: size:" | wc -l` -eq 1 ]

