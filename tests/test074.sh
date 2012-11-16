#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS deps spaces"

cat > test.c <<EOF
#ifndef XXX
#error XXX is not defined
#endif
main(){}
EOF

$ROOT/bin/atos-init -b "gcc ./test.c -DXXX=\" A\"" -r "echo user 12"

