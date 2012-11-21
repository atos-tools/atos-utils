#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS audit response files"

cat > build.sh <<EOF
#!/bin/sh
# This pattern was detected in the build of fakeroot
echo "-DOK"                 > response-file
echo "#ifndef OK"           > test.c
echo "#error OK undefined" >> test.c
echo "#endif"              >> test.c
echo "void main() { }"     >> test.c
gcc @response-file test.c
rm response-file
EOF

$ROOT/bin/atos-init -r "echo user 12" -b "sh ./build.sh"
