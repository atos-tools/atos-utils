#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS toolkit base variants"

$ROOT/bin/atos-init \
    -r "$SRCDIR/examples/sha1-c/run.sh" \
    -b "gcc -o sha1-c $SRCDIR/examples/sha1-c/sha.c $SRCDIR/examples/sha1-c/sha1.c"

$ROOT/bin/atos-opt -r -a "-O2"

$ROOT/bin/atos-opt -r -a "-O3"

# default optim_levels are -Os,-O2,-O3
$ROOT/bin/atos gen \
    --seed=0 --optim-variants=base --generator=gen_base \
    OPT-O2 OPT-O3

# Number of runs: 9
# REF (atos-init) + OPT-O2 + OPT-O3 + |OPT-O2, OPT-O3| x | -Os -O2, -O3|
[ `grep " REF: time:" atos-configurations/results.db | wc -l` -eq 1 ]
[ `grep " OPT-O2: time:" atos-configurations/results.db | wc -l` -eq 1 ]
[ `grep " OPT-O3: time:" atos-configurations/results.db | wc -l` -eq 1 ]
[ `grep " OPT-O2-Os: time:" atos-configurations/results.db | wc -l` -eq 1 ]
[ `grep " OPT-O2-O2: time:" atos-configurations/results.db | wc -l` -eq 1 ]
[ `grep " OPT-O2-O3: time:" atos-configurations/results.db | wc -l` -eq 1 ]
[ `grep " OPT-O3-Os: time:" atos-configurations/results.db | wc -l` -eq 1 ]
[ `grep " OPT-O3-O2: time:" atos-configurations/results.db | wc -l` -eq 1 ]
[ `grep " OPT-O3-O3: time:" atos-configurations/results.db | wc -l` -eq 1 ]
[ `cat atos-configurations/results.db | grep " time: " | wc -l` -eq 9 ]
