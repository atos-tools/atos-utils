#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS audit -C option"

$ROOT/bin/atos-audit gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c
[ -f atos-configurations/build.sh ]

$ROOT/bin/atos-audit -C atos-configurations-$TEST gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c
[ -f atos-configurations-$TEST/build.sh ]

$ROOT/bin/atos-audit -C atos-configurations/$TEST gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c
[ -f atos-configurations/$TEST/build.sh ]
