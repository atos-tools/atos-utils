#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS audit -f option"

$ROOT/atos-audit -f gcc -o sha1-c  $ROOT/examples/sha1-c/sha.c $ROOT/examples/sha1-c/sha1.c
mv sha1-c sha1-c.ref
[ -f atos-configurations/build.sh ]
[ -f atos-configurations/build.force ]
force=`cat atos-configurations/build.force`
[ "$force" = 1 ]
atos-configurations/build.sh
cmp sha1-c sha1-c.ref
