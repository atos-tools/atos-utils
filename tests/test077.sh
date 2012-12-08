#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS audit response files"

cat > build.sh <<EOF
#!/bin/sh
# This pattern was detected in the build of fakeroot
set -e
echo "-DOK"                 > response-file
echo "#ifndef OK"           > test.c
echo "#error OK undefined" >> test.c
echo "#endif"              >> test.c
echo "void main() { }"     >> test.c
gcc @response-file test.c
rm response-file
EOF

$ROOT/bin/atos-init -r "echo user 12" -b "sh ./build.sh"

cat > build.sh <<EOF
#!/bin/sh
# Test with a recursive response file
set -e
echo "@response-file2" > response-file
echo "@response-file4 -DOK" >> response-file
echo "@response-file3 -DOK2" > response-file2
echo "-DOK3" > response-file3
echo "-DOK4" > response-file4
echo "#ifndef OK"           > test.c
echo "#error OK undefined" >> test.c
echo "#endif"              >> test.c
echo "#ifndef OK2"         >> test.c
echo "#error OK2 undefined">> test.c
echo "#endif"              >> test.c
echo "#ifndef OK3"         >> test.c
echo "#error OK3 undefined">> test.c
echo "#endif"              >> test.c
echo "#ifndef OK4"         >> test.c
echo "#error OK4 undefined">> test.c
echo "#endif"              >> test.c
echo "void main() { }"     >> test.c
gcc @response-file test.c
rm -f response-file*
EOF

$ROOT/bin/atos-init -c -r "echo user 12" -b "sh ./build.sh"
