#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS play options"

# Init w/o running REF variant
$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c" --no-run

$ROOT/bin/atos-play -C undef/ 2>&1 | grep -i "error: configuration path missing"
[ ${PIPESTATUS[0]} = 1 ]

$ROOT/bin/atos-play -p 2>&1 | grep -i "error: no result found"
[ ${PIPESTATUS[0]} = 1 ]

$ROOT/bin/atos-opt -r -a "-O2"
md5_O2=`md5sum sha1-c|cut -f1 -d' '`
[ "$md5_O2" != "$md5_REF" ]

$ROOT/bin/atos-opt -r -a "-O3"
md5_O3=`md5sum sha1-c|cut -f1 -d' '`
[ "$md5_O3" != "$md5_REF" ]
[ "$md5_O3" != "$md5_O2" ]

$ROOT/bin/atos-play -p --refid OPT-O2

$ROOT/bin/atos-play -p --ref --refid OPT-O2 2>&1 | grep -i "error: REF variant not found"
[ ${PIPESTATUS[0]} = 1 ]

# Build and run REF variant now
$ROOT/bin/atos-opt -r
md5_REF=`md5sum sha1-c|cut -f1 -d' '`

$ROOT/bin/atos-play -p

$ROOT/bin/atos-play -p -i sha1-c

$ROOT/bin/atos-play -n -f size 2>&1

$ROOT/bin/atos-play -P -s 5 2>&1

$ROOT/bin/atos-play -T -s 5 -s 1 -s 0.2  2>&1

$ROOT/bin/atos-play -T -X -s 5 -s 1 -s 0.2 2>&1

[ `$ROOT/bin/atos-play -p --ref | grep "ATOS: sha1-c: REF" | wc -l` -ne 0 ]

[ `$ROOT/bin/atos-play -p -l d82cd2 | grep "ATOS: sha1-c: REF" | wc -l` -ne 0 ]

[ `$ROOT/bin/atos-play -p -w RE | grep "ATOS: sha1-c: REF" | wc -l` -ne 0 ]

[ `$ROOT/bin/atos-play -p -w OPT-O3 | grep "ATOS: sha1-c: OPT-O3" | wc -l` -ne 0 ]

$ROOT/bin/atos-play -p -w OPT-O4 2>&1 | grep -i "error: variant not found"
[ ${PIPESTATUS[0]} = 1 ]

$ROOT/bin/atos-play -p -w OPT 2>&1 | grep -i "error: multiple variant found"
[ ${PIPESTATUS[0]} = 1 ]

# Rebuild REF
$ROOT/bin/atos-play --ref
md5=`md5sum sha1-c|cut -f1 -d' '`
[ "$md5" = "$md5_REF" ]

# Rebuild -O2
$ROOT/bin/atos-play -w OPT-O2
md5=`md5sum sha1-c|cut -f1 -d' '`
[ "$md5" = "$md5_O2" ]

# Rebuild -O2 with additional flag -O3.
# We should get -O3 as "-O2 -O3" is eqauivalent to -O3 with gcc.
$ROOT/bin/atos-play -w OPT-O2 -a "-O3"
md5=`md5sum sha1-c|cut -f1 -d' '`
[ "$md5" = "$md5_O3" ]

$ROOT/bin/atos-play -N 2 2>&1 | grep -i "error: more than one build requested"
[ ${PIPESTATUS[0]} = 1 ]

