#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS lto flags"

cat > build.sh <<EOF
gcc -c $SRCDIR/examples/sha1-c/sha.c -o sha.o
gcc -c $SRCDIR/examples/sha1-c/sha1.c -o sha1.o
gcc -o sha1-c sha.o sha1.o
gcc -O2 -funroll-loops -DTEST -c $SRCDIR/examples/sha1-c/sha.c -o xsha.o
gcc -O2 -DTEST -c $SRCDIR/examples/sha1-c/sha1.c -o xsha1.o
gcc -o sha2-c xsha.o xsha1.o
EOF

cat > run.sh <<EOF
dd if=/dev/urandom bs=4K count=1K 2>/dev/null | ./sha1-c
EOF


$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" -b "sh ./build.sh"

export ATOS_DEBUG_FILE=atos.log

$ROOT/bin/atos-opt -r -l

[ `cat atos.log | grep "\-o sha2-c" | grep "\-O2" | grep "\-funroll-loops" | wc -l` -ne 0 ]

[ `cat atos.log | grep "\-o sha1-c" | grep "\-funroll-loops" | wc -l` -eq 0 ]



$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" -b "sh ./build.sh" --legacy

export ATOS_DEBUG_FILE=atos2.log

$ROOT/bin/atos-opt -r -l

[ `cat atos2.log | grep "\-o sha2-c" | grep "\-O2" | grep "\-funroll-loops" | wc -l` -ne 0 ]

# in legacy mode, lto flags are shared by all targets
[ `cat atos2.log | grep "\-o sha1-c" | grep "\-funroll-loops" | wc -l` -ne 0 ]


