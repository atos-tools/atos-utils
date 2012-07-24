#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS exploration failure"

cat > run.sh <<EOF
#!/bin/sh
$SRCDIR/examples/sha1-c/run.sh
EOF
chmod u+x ./run.sh

$ROOT/bin/atos-init -r "./run.sh" \
    -b "gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c"

echo "echo user 0" >> ./run.sh

$ROOT/bin/atos-explore-inline -S0 -M3
