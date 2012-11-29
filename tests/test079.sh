#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS init ccname/ccregexp"

cp -a $ROOT/share/atos/examples/sha1 .
cd sha1

gpp=`which g++`
ar=`which ar`
ld=`which ld`
ln -s $gpp xxx
ln -s $ar yyy
ln -s $ld zzz

ln -s $gpp i386-g++
ln -s $ar i386-ar
ln -s $ld i386-ld

# Build with standard tool names
$ROOT/bin/atos-init -c \
    -r "./run.sh" \
    -b "make clean all" \
    -e sha
md5_REF=`md5sum sha|cut -f1 -d' '`
$ROOT/bin/atos-build -a -O3
md5_O3=`md5sum sha|cut -f1 -d' '`
[ "$md5_O3" != "$md5_REF" ]

# Build with tool names specified by name
$ROOT/bin/atos-init -c \
    -r "./run.sh" \
    -b "make CC=./xxx AR=./yyy LD=./zzz clean all" \
    --ccname xxx --arname yyy --ldname zzz -e sha
md5=`md5sum sha|cut -f1 -d' '`
[ "$md5" = "$md5_REF" ]
$ROOT/bin/atos-build -a -O3
md5=`md5sum sha|cut -f1 -d' '`
[ "$md5" = "$md5_O3" ]

# Build with tool names specified by regexp
$ROOT/bin/atos-init -c \
    -r "./run.sh" \
    -b "make CC=./i386-g++ AR=./i386-ar LD=./i386-ld clean all" \
    --ccregexp '.*-g\+\+' --arregexp '.*-ar' --ldregexp '.*-ld' -e sha
md5=`md5sum sha|cut -f1 -d' '`
[ "$md5" = "$md5_REF" ]
$ROOT/bin/atos-build -a -O3
md5=`md5sum sha|cut -f1 -d' '`
[ "$md5" = "$md5_O3" ]

# Build  --force with tool names specified by name
$ROOT/bin/atos-init -c --force \
    -r "./run.sh" \
    -b "make CC=./xxx AR=./yyy LD=./zzz clean all" \
    --ccname xxx --arname yyy --ldname zzz -e sha
md5=`md5sum sha|cut -f1 -d' '`
[ "$md5" = "$md5_REF" ]
$ROOT/bin/atos-build -a -O3
md5=`md5sum sha|cut -f1 -d' '`
[ "$md5" = "$md5_O3" ]

# Build with tool names specified by regexp
$ROOT/bin/atos-init -c --force \
    -r "./run.sh" \
    -b "make CC=./i386-g++ AR=./i386-ar LD=./i386-ld clean all" \
    --ccregexp '.*-g\+\+' --arregexp '.*-ar' --ldregexp '.*-ld' -e sha
md5=`md5sum sha|cut -f1 -d' '`
[ "$md5" = "$md5_REF" ]
$ROOT/bin/atos-build -a -O3
md5=`md5sum sha|cut -f1 -d' '`
[ "$md5" = "$md5_O3" ]


