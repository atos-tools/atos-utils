#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS intermediate files"

cat >hello.c <<EOF
#include <stdio.h>
int main() {
   printf("Hello world!\n");
   printf("user 1\n");
   return 0;
}
EOF

cat >build.sh <<EOF
cc -c hello.c
rm -f hello.c
cc -o hello.exe hello.o
EOF

# Build an verify whether we can rebuild even with intermediate
# file (hello.c) removed
$ROOT/bin/atos-init -c -b "sh ./build.sh" -r ./hello.exe
