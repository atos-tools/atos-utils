#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS generators - open64 flags"

# export PATH=$BASE/STxP70/STxP70_Toolset_2012.2/bin:$PATH
# export PATH=$BASE/STxP70/STxP70_Toolset_2012.2/stxp70cc/4.3/bin:$PATH
# export PATH=$BASE/STxP70/STxP70_Toolset_2012.2/gnu/4.5.2/bin:$PATH
# export PATH=$BASE/STxP70/STxP70_Toolset_2012.2/gnu/4.5.2/i686-pc-linux-gnu/bin:$PATH
# export PATH=$BASE/STxP70/STxP70_Toolset_2012.2/jre/bin:$PATH
# export SX=$BASE/STxP70/STxP70_Toolset_2012.2
# export STXP70CC_VERSION=4.3

[ "`which stxp70cc 2>/dev/null`" != "" ] || skip "stxp70cc compiler not found"
[ "`which sxrun 2>/dev/null`" != "" ]    || skip "stxp70cc compiler not found"
[ "$SX" != "" ]                          || skip "stxp70cc environment not defined"
[ "$STXP70CC_VERSION" != "" ]            || skip "stxp70cc environment not defined"

cat > build.sh <<EOF
stxp70cc -O2 -o sha.o -c $SRCDIR/examples/sha1-c/sha.c
stxp70cc -O2 -o sha1.o -c $SRCDIR/examples/sha1-c/sha1.c
stxp70cc -O2 -o sha1-c sha.o sha1.o
EOF

$ROOT/bin/atos-init \
    -b "sh build.sh" -r "sxrun sha1-c sha.o"

$ROOT/bin/atos-explore --log-file="expl.log"

[ `cat expl.log | grep flto | wc -l` -eq 0 ]
[ `cat expl.log | grep ipa | wc -l` -ne 0 ]
[ `cat expl.log | grep profile-arcs | wc -l` -ne 0 ]
[ `cat expl.log | grep branch-probabilities | wc -l` -ne 0 ]
[ `cat expl.log | grep profile-dir | wc -l` -eq 0 ]
[ `find atos-configurations/profiles | grep gcda | wc -l` -ne 0 ]
[ `find atos-configurations/profiles | grep gcno | wc -l` -ne 0 ]
[ `cat expl.log | grep "gcda not found" | wc -l` -eq 0 ]

$ROOT/bin/atos-explore-optim \
    --nbiters=5 --optim-variants=base --log-file="expl2.log"

