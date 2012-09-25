#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS init audits"

$ROOT/bin/atos-init -C atos-config \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c" \
    -n 2

[ `$ROOT/lib/atos/python/atos/atos_lib.py query -C atos-config | grep target | wc -l` -eq 2 ]

# force option

$ROOT/bin/atos-init -C atos-config-1 \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c" \
    -f -e $PWD/sha1-c

[ `cat atos-config-1/build.force` = "1" ]

[ `$ROOT/lib/atos/python/atos/atos_lib.py query -C atos-config-1 | grep target | wc -l` -eq 1 ]

# clean option

$ROOT/bin/atos-init -C atos-config \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c" \
    -c

[ `$ROOT/lib/atos/python/atos/atos_lib.py query -C atos-config | grep target | wc -l` -eq 1 ]

# no-ref-run option

$ROOT/bin/atos-init -C atos-config-2 \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c" \
    --no-run

[ `$ROOT/lib/atos/python/atos/atos_lib.py query -C atos-config-2 | grep target | wc -l` -eq 0 ]
