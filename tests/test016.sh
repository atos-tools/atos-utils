#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS lib create_db"

$ROOT/bin/atos-audit gcc -o sha1-c $ROOT/examples/sha1-c/sha.c $ROOT/examples/sha1-c/sha1.c
$ROOT/bin/atos-raudit $ROOT/examples/sha1-c/run.sh
$ROOT/bin/atos-deps -a
$ROOT/bin/atos-build -a -O2
$ROOT/bin/atos-run -r -a -O2
$ROOT/bin/atos-build -a -O3
$ROOT/bin/atos-run -r -a -O3

(
$ROOT/lib/atos/atos_lib.py create_db -C DBDEF
$ROOT/lib/atos/atos_lib.py push -R DBDEF --force
[ `$ROOT/lib/atos/atos_lib.py query -C DBDEF | grep target | wc -l` -eq 2 ]

$ROOT/lib/atos/atos_lib.py create_db -C DBJSON --type=json
$ROOT/lib/atos/atos_lib.py push -R DBJSON --force
[ `$ROOT/lib/atos/atos_lib.py query -C DBJSON | grep target | wc -l` -eq 2 ]

$ROOT/lib/atos/atos_lib.py create_db -C DBPICKLE --type=pickle
$ROOT/lib/atos/atos_lib.py push -C DBJSON -R DBPICKLE --force
[ `$ROOT/lib/atos/atos_lib.py query -C DBPICKLE | grep target | wc -l` -eq 2 ]
) 2>&1
