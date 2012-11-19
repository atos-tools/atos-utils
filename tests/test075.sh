#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS build link options"

cat > build.sh <<EOF
g++ -c -O2 -Wall -D_FILE_OFFSET_BITS=64 -fpic -o sha1_s.o $SRCDIR/examples/sha1/sha1.cpp
g++ -o sha.so -shared sha1_s.o 
g++ -c -O2 -Wall -D_FILE_OFFSET_BITS=64 -o sha.o $SRCDIR/examples/sha1/sha.cpp
g++ -c -O2 -Wall -D_FILE_OFFSET_BITS=64 -o sha1.o $SRCDIR/examples/sha1/sha1.cpp
ar cr libsha1.a sha1.o
g++ -o sha sha.o -L. -lsha1 
EOF

$ROOT/bin/atos-init -b "sh ./build.sh" \
    -r "$SRCDIR/examples/sha1/run.sh"

ATOS_DEBUG_FILE=log.txt \
    $ROOT/bin/atos-build -a -O2 -g -O2

[ `cat log.txt | grep "\-o sha.so" | grep "\-lgcov \-lc" | wc -l` -eq 1 ]

[ `cat log.txt | grep "\-o sha " | wc -l` -eq 1 ]

[ `cat log.txt | grep "\-o sha " | grep "\-lgcov \-lc" | wc -l` -eq 0 ]

