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
    [ "`basename $bin`" == "atos-driver" ] \
	&& $bin --atos-version && continue
    $bin -v
done 2>&1
