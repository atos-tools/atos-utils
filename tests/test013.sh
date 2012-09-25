#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS run results from log"

cat > run.sh <<EOF
echo "user 10"
echo "user 15"
EOF

chmod u+x run.sh

$ROOT/bin/atos-run -e test -n 2 ./run.sh 2>&1 | tee run.log

if [ "${PIPESTATUS[0]}" != "0" ]; then
    echo "atos-run exited with non-zero status" 1>&2
    $ROOT/bin/atos-run -d -e test -n 2 ./run.sh 1>&2
    false
fi

[ `cat run.log | grep "time:" | wc -l` -eq 2 ] || error=1
[ `cat run.log | grep "time:" | awk '{ print $5 }' | grep -v 25000 | wc -l` -eq 0 ] || error=1

if [ "$error" = "1" ]; then
    echo "test postamble failure" 1>&2
    cat run.log 1>&2
    false
fi
