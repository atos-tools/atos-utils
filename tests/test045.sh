#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS python sys path"

cat > atos.py <<EOF
print "error"
EOF

export PYTHONPATH=$PWD:$PYTHONPATH

for bin in $ROOT/bin/atos*; do
    [ "`basename $bin`" == "atos-graph" ] && $bin --version \
	|| $bin -v
done
