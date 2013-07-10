#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS run -n option"

$ROOT/bin/atos-audit gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c
$ROOT/bin/atos-raudit $SRCDIR/examples/sha1-c/run.sh
$ROOT/bin/atos-deps -a

# Verify that -n/--nbruns 0 works for atos-run
$ROOT/bin/atos-run -r -n 2
[ `grep "REF: time: " atos-configurations/results.db | wc -l` -eq 2 ]

# Verify that -n/--nbruns 0 works for atos-explore
$ROOT/bin/atos-explore --optim-levels -O2 -V base -n 0
[ `grep "OPT-O2: time: " atos-configurations/results.db | wc -l` -eq 0 ]
[ `grep "Running variant OPT-O2" atos-configurations/logs/run-*.log | wc -l` -eq 0 ]

# Verify that the last nbruns setting by atos-explore is preserved (0 runs)
$ROOT/bin/atos-explore --optim-levels -O2 -V base
[ `grep "OPT-O2: time: " atos-configurations/results.db | wc -l` -eq 0 ]
[ `grep "Running variant OPT-O2" atos-configurations/logs/run-*.log | wc -l` -eq 0 ]

# Reset number of runs to 3
$ROOT/bin/atos-init --nbruns 3
[ `grep "OPT-O2: time: " atos-configurations/results.db | wc -l` -eq 0 ]
[ `grep "Running variant OPT-O2" atos-configurations/logs/run-*.log | wc -l` -eq 0 ]

# Verify that atos-explore runs 3 times
$ROOT/bin/atos-explore --optim-levels -O2 -V base
[ `grep "OPT-O2: time: " atos-configurations/results.db | wc -l` -eq 3 ]
[ `grep "Running variant OPT-O2" atos-configurations/logs/run-*.log | wc -l` -eq 3 ]

# Test that passing a negative value raised a user error
$ROOT/bin/atos-init --nbruns -1 2>&1 | grep -i "error: number of runs must be >= 0"
[ ${PIPESTATUS[0]} = 1 ]
