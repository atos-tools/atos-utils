#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS python sys path"

cat > atos.py <<EOF
print "error"
EOF

export PYTHONPATH=$PWD:$PYTHONPATH

# Check that python scripts execute correctly
for bin in $ROOT/bin/atos*; do
    head -1 $bin | grep python >/dev/null || continue
    [ "`basename $bin`" == "atos-driver" ] \
	&& $bin --atos-version && continue
    $bin -v
done 2>&1
