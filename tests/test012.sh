#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS deps with archives"

cp -a $SRCDIR/examples/sha1 .
cd sha1
# Explicit .a in arguments
cat >build.sh <<EOF
c++ sha1.cpp -c
ar cru sha1.a sha1.o
c++ -o sha sha.cpp sha1.a
EOF
$ROOT/bin/atos-audit sh ./build.sh
$ROOT/bin/atos-deps sha
rm *.o *.a
$ROOT/bin/atos-build
rm *.o *.a

# -l specified .a with multiple -L
cat >build.sh <<EOF
c++ sha1.cpp -c
ar cru libsha1.a sha1.o
c++ -o sha sha.cpp -Lfoo -L.. -L. -L. -lsha1
EOF
$ROOT/bin/atos-audit sh ./build.sh
$ROOT/bin/atos-deps sha
rm *.o *.a
$ROOT/bin/atos-build
rm *.o *.a

# multiple -l specified .a with multiple -L
cat >build.sh <<EOF
c++ sha1.cpp -c
ar cru libsha1.a sha1.o
mkdir foo
cp libsha1.a foo
c++ -o sha sha.cpp -Lfoo -lsha1 -L.. -L. -lsha1 libsha1.a
EOF
$ROOT/bin/atos-audit sh ./build.sh
$ROOT/bin/atos-deps sha
rm *.o *.a
$ROOT/bin/atos-build
rm *.o *.a

