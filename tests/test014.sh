#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS inline exploration"

flags_list=""

# temporary fix
# atos should be able to know compiler version

gcc_version=`gcc --version | head -1 | sed 's/.* //' | sed 's/\.[^.]*$//'`
if [ "$gcc_version" = "4.4" ]; then
    flags_list=$ROOT/lib/atos/config/flags.inline.gcc.4.4.cfg
elif [ "$gcc_version" = "4.5" ]; then
    flags_list=$ROOT/lib/atos/config/flags.inline.gcc.4.5.cfg
elif [ "$gcc_version" = "4.6" ]; then
    flags_list=$ROOT/lib/atos/config/flags.inline.gcc.4.6.cfg
else
    skip
fi

(
$ROOT/bin/atos-init \
    -r "$ROOT/examples/sha1-c/run.sh" \
    -b "gcc -o sha1-c $ROOT/examples/sha1-c/sha.c $ROOT/examples/sha1-c/sha1.c" \

$ROOT/bin/atos-explore-inline -M5 -Vbase,fdo -F $flags_list
) 2>&1
    
[ -d atos-configurations ]
[ `$ROOT/lib/atos/atos_lib.py query -q'variant:OPT-.*' | wc -l` -eq 10 ]

