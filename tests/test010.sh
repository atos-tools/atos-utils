#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS run -n option"

$ROOT/bin/atos-audit gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c
$ROOT/bin/atos-raudit $SRCDIR/examples/sha1-c/run.sh
$ROOT/bin/atos-deps -a
$ROOT/bin/atos-run -r -n 2
[ `grep "REF: time: " atos-configurations/results.db | wc -l` -eq 2 ]

$ROOT/bin/atos-explore -n 0
[ `grep "OPT-O3: time: " atos-configurations/results.db | wc -l` -eq 0 ]
[ `grep "^Running variant OPT-O3$" atos-configurations/logs/*.log | wc -l` -eq 0 ]
