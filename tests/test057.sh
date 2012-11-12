#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS process interrupt"

build_process_cmd() {
    cat >>process.py <<EOF
#!/usr/bin/env python

import sys
sys.path.insert(0, "$ROOT/lib/atos/python")
from atoslib import process
print "Executing command..."
status = process.system("/bin/sleep 10", print_output=True)
print "should not get there"
sys.exit(1)
EOF
    chmod 755 process.py
}

build_process_cmd
./process.py 2>&1 &
child=$!
sleep 1
kill -2 $child
sleep 1
kill -2 $child 2>&1 && there=yes
if [ "$there" = "yes" ]; then
    # If still there, we kill it, but it's an error
    kill -15 $child
    exit 1
fi
