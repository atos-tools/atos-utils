#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS timeout tty"

tty -s || skip "needs a tty"

# Verify that atos-timeout is not stopped due to TTY access on some shells.
# /bin/sh is dash on Ubuntu, with dash, timeout must be careful regarding process groups.
# Warning: if atos-timeout does not handle this correctly, the processes will be stopped
# in this case this test will not terminate.
/bin/sh -c "$ROOT/bin/atos-timeout 1 /bin/sh -c 'read line'" 2>&1 | grep "Terminated after timeout"
/usr/bin/env bash -c "$ROOT/bin/atos-timeout 1 /bin/sh -c 'read line'" 2>&1 | grep "Terminated after timeout"
