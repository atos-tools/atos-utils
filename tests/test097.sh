#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="/dev/null files"

# Test that audit is robust to /dev/null given
# as input ot output to gcc commands

cat >build.sh <<EOF
#!/bin/sh
set -e

gcc -c -xc /dev/null -o empty1.o
gcc -c -xc /dev/null -o empty2.o
gcc -c -xc /dev/null -o /dev/null
echo "" >empty.c
gcc -c empty.c -o empty3.o
gcc -c empty.c -o /dev/null

echo "#include <stdio.h>"      >void.c
echo "int main() { printf(\"user 1\\\\\n\"); return 0; }" >>void.c
gcc -o void.exe void.c

EOF
chmod 755 build.sh

# Check that autdit works correctly
$ROOT/bin/atos init -c -b ./build.sh -r ./void.exe
[ -f void.exe ]

# Clear all input and outputs
rm -f *.c *.o *.exe
$ROOT/bin/atos-build
[ -f void.c ]
[ -f void.exe ]

# Check that all /dev/null related commands were not run
[ ! -f empty.c ]
[ ! -f empty1.o ]
[ ! -f empty2.o ]
[ ! -f empty3.o ]
