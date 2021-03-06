#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS init remote profile path"

$ROOT/bin/atos-init -B /work1/tmp1 \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c"

[ "`$ROOT/bin/atos lib config --get default_values.remote_profile_path`" = "/work1/tmp1" ]

$ROOT/bin/atos-init -B /work1/tmp2

[ "`$ROOT/bin/atos lib config --get default_values.remote_profile_path`" = "/work1/tmp2" ]
