#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS deps -C option"

$ROOT/bin/atos-audit gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c
$ROOT/bin/atos-deps -a
[ -f atos-configurations/build.mk ]

$ROOT/bin/atos-audit -C atos-configurations-1 gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c
$ROOT/bin/atos-deps -a -C atos-configurations-1
[ -f atos-configurations-1/build.mk -a -f atos-configurations-1/targets ]
[ `diff atos-configurations-1/build.mk atos-configurations/build.mk | wc -l` -eq 0 ]

mkdir atos-configurations-2
$ROOT/bin/atos-deps -a -C atos-configurations-2 -i atos-configurations-1/build.audit
[ -f atos-configurations-2/build.mk -a -f atos-configurations-2/targets ]
[ `diff atos-configurations-1/build.mk atos-configurations-2/build.mk | wc -l` -eq 0 ]

mkdir atos-configurations-3
$ROOT/bin/atos-deps -a -C atos-configurations-1 -o atos-configurations-3/build.mk
[ -f atos-configurations-3/build.mk ]
[ `diff atos-configurations-1/build.mk atos-configurations-3/build.mk | wc -l` -eq 0 ]
