#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS lib query/push/pull"

$ROOT/bin/atos-audit gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c
$ROOT/bin/atos-raudit $SRCDIR/examples/sha1-c/run.sh
$ROOT/bin/atos-deps -a
$ROOT/bin/atos-build -a -O2
$ROOT/bin/atos-run -r -a -O2
$ROOT/bin/atos-build -a -O3
$ROOT/bin/atos-run -r -a -O3

(
# simple jsonpath query (must return 2 sizes)
[ `$ROOT/bin/atos lib query -q'$[?(@.target="sha1-c")].size' | wc -l` -eq 2 ]

# db push (must export 2 results)
$ROOT/bin/atos lib create_db -C NEWDB
$ROOT/bin/atos lib push -R NEWDB --force
[ `$ROOT/bin/atos lib query -C NEWDB | grep target | wc -l` -eq 2 ]

# db pull (must import 2 results)
$ROOT/bin/atos lib create_db -C NEWDB2
$ROOT/bin/atos lib pull -C NEWDB2 -R NEWDB --force
[ `$ROOT/bin/atos lib query -C NEWDB2 | grep target | wc -l` -eq 2 ]

# db dump/load on standard input/output
$ROOT/bin/atos lib create_db -C NEWDB3
$ROOT/bin/atos lib push -CNEWDB2 -R- \
    | $ROOT/bin/atos lib pull -C NEWDB3 -R- --force
[ `$ROOT/bin/atos lib query -C NEWDB3 | grep target | wc -l` -eq 2 ]
) 2>&1

