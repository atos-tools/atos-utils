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

[ `cat run.log | grep "time:" | wc -l` -eq 2 ]
[ `cat run.log | grep "time:" | awk '{ print $5 }' | grep -v 25000 | wc -l` -eq 0 ]
