#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS response file"

gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c
mv sha1-c sha1-c.org
cat >args.txt <<EOF
-o sha1-c
$SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c
EOF
$ROOT/bin/atos-audit gcc @args.txt
diff sha1-c sha1-c.org >/dev/null
$ROOT/bin/atos-deps -a
make -f atos-configurations/build.mk
diff sha1-c sha1-c.org >/dev/null
