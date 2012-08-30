#!/usr/bin/env bash
#
#
KEEPTEST=1
source `dirname $0`/common.sh

TEST_CASE="ATOS opt build/run"

$ROOT/bin/atos-audit -C atos-config gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c
$ROOT/bin/atos-raudit -C atos-config $SRCDIR/examples/sha1-c/run.sh
$ROOT/bin/atos-deps -C atos-config -a

$ROOT/bin/atos-opt -C atos-config -r

$ROOT/bin/atos-opt -C atos-config -r -a "-O2"

$ROOT/bin/atos-opt -C atos-config -r -a "-O2" -f

[ `$ROOT/lib/atos/python/atos/atos_lib.py query -C atos-config | grep target | wc -l` -eq 3 ]

if [ `gcc -v --help 2>&1 | grep "\-flto" | wc -l` -ne 0 ]; then

    $ROOT/bin/atos-opt -C atos-config -r -a "-O2" -l

    $ROOT/bin/atos-opt -C atos-config -r -a "-O2" -f -l

    $ROOT/bin/atos-opt -C atos-config -r -a "-O2" -f -u "-O2"

    [ `$ROOT/lib/atos/python/atos/atos_lib.py query -C atos-config | grep target | wc -l` -eq 6 ]

fi

[ `find atos-config/logs -name *.log -exec grep "gcda not found" {} ";" | wc -l` -eq 0 ]

[ `find atos-config/logs -name *.log -exec grep "coverage mismatch" {} ";" | wc -l` -eq 0 ]

[ `find atos-config/profiles -name *.gcda | wc -l` -eq 2 ]

