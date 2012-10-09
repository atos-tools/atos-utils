#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS remote profile path"

profdir=$PWD/xxxx
mkdir $profdir

cat > run.sh <<EOF
#!/bin/sh
echo "HELLO" 1>&2
$SRCDIR/examples/sha1-c/run.sh
echo "\$REMOTE_PROFILE_DIR -> \$LOCAL_PROFILE_DIR" 1>&2
[ "\$REMOTE_PROFILE_DIR" = "" ] || mv \$REMOTE_PROFILE_DIR \$LOCAL_PROFILE_DIR
EOF

chmod u+x run.sh

$ROOT/bin/atos-init \
    -r "./run.sh" \
    -b "gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c" \
    -B $profdir 2>&1

$ROOT/bin/atos-opt -r -a -O2

$ROOT/bin/atos-opt -r -f -a -O2

[ `find atos-configurations/profiles -name "*.gcda" | wc -l` -eq 2 ]
