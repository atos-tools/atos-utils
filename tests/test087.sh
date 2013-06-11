#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS profile --reuse"

[ `gcc -v --help 2>&1 | grep "\-flto" | wc -l` != 0 ] || skip "non lto compiler"

cat > build.sh <<EOF
gcc -c $SRCDIR/examples/sha1-c/sha.c -o sha.o
gcc -c $SRCDIR/examples/sha1-c/sha1.c -o sha1.o
gcc -o sha1-c sha.o sha1.o
EOF

$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" -b "sh ./build.sh"

$ROOT/bin/atos-explore --reuse --cookie=unknown 2>&1 | tee atos.log

[ `cat atos.log | grep "Skipping profile" | wc -l` -eq 3 ]

# negative case (bad use of reuse option)
$ROOT/bin/atos-explore --reuse 2>&1 | tee atos.log

[ `cat atos.log | grep "reuse option must be used with" | wc -l` -ne 0 ]
