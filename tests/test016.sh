#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS lib create_db"

$ROOT/bin/atos-audit gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c
$ROOT/bin/atos-raudit $SRCDIR/examples/sha1-c/run.sh
$ROOT/bin/atos-deps -a
$ROOT/bin/atos-build -a -O2
$ROOT/bin/atos-run -r -a -O2
$ROOT/bin/atos-build -a -O3
$ROOT/bin/atos-run -r -a -O3

(
$ROOT/bin/atos lib create_db -C DBDEF
$ROOT/bin/atos lib push -R DBDEF --force
[ `$ROOT/bin/atos lib query -C DBDEF | grep target | wc -l` -eq 2 ]

$ROOT/bin/atos lib create_db -C DBJSON --type=json
$ROOT/bin/atos lib push -R DBJSON --force
[ `$ROOT/bin/atos lib query -C DBJSON | grep target | wc -l` -eq 2 ]

$ROOT/bin/atos lib create_db -C DBPICKLE --type=pickle
$ROOT/bin/atos lib push -C DBJSON -R DBPICKLE --force
[ `$ROOT/bin/atos lib query -C DBPICKLE | grep target | wc -l` -eq 2 ]
) 2>&1
