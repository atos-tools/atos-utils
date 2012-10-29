#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS audit -f option"

# Test on sha1-c
$ROOT/bin/atos-audit -f gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c
mv sha1-c sha1-c.ref
[ -f atos-configurations/build.sh ]
[ -f atos-configurations/build.force ]
force=`cat atos-configurations/build.force`
[ "$force" = 1 ]
atos-configurations/build.sh
cmp sha1-c sha1-c.ref

# Test on sha1
cp -a $SRCDIR/examples/sha1 .
cd sha1
make clean
$ROOT/bin/atos-audit -f make clean all
mv sha sha.ref
atos-configurations/build.sh
cmp sha sha.ref
