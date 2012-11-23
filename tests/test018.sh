#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS init audits"

# check user errors

$ROOT/bin/atos-init -b "undef" 2>&1 | grep -i "error: in build command, 'undef' executable not found"
[ ${PIPESTATUS[0]} = 1 ]
$ROOT/bin/atos-init -t "undef" 2>&1 | grep -i "error: in results command, 'undef' executable not found"
[ ${PIPESTATUS[0]} = 1 ]
$ROOT/bin/atos-init --size-cmd "undef" 2>&1 | grep -i "error: in size command, 'undef' executable not found"
[ ${PIPESTATUS[0]} = 1 ]
$ROOT/bin/atos-init --time-cmd "undef" 2>&1 | grep -i "error: in time command, 'undef' executable not found"
[ ${PIPESTATUS[0]} = 1 ]

# Check that init errors failed before creation of config dir
[ ! -d atos-configurations ]

$ROOT/bin/atos-init -c \
    -b "gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c" \
    -r "undef" 2>&1 | grep -i "error: in run command, 'undef' executable not found"
[ ${PIPESTATUS[0]} = 1 ]
$ROOT/bin/atos-init -c \
    -b "gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c" \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -p "undef" 2>&1 | grep -i "error: in profile command, 'undef' executable not found"
[ ${PIPESTATUS[0]} = 1 ]

rm -rf atos-configurations

# Check correct configuration and targets

$ROOT/bin/atos-init -C atos-config \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c" \
    --time-cmd "/usr/bin/time -p" \
    --size-cmd "/usr/bin/size" \
    -n 2

[ `$ROOT/bin/atos lib query -C atos-config | grep target | wc -l` -eq 2 ]

# check for clean config on rebuild

$ROOT/bin/atos-init -C atos-config \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c" \

[ `cat atos-config/config.json | grep driver_version | wc -l` -eq 1 ]

# force option

$ROOT/bin/atos-init -C atos-config-1 \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c" \
    -f -e $PWD/sha1-c

[ `cat atos-config-1/build.force` = "1" ]

[ `$ROOT/bin/atos lib query -C atos-config-1 | grep target | wc -l` -eq 1 ]

# clean option

$ROOT/bin/atos-init -C atos-config \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c" \
    -c

[ `$ROOT/bin/atos lib query -C atos-config | grep target | wc -l` -eq 1 ]

# no-ref-run option

$ROOT/bin/atos-init -C atos-config-2 \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c" \
    --no-run

[ `$ROOT/bin/atos lib query -C atos-config-2 | grep target | wc -l` -eq 0 ]
