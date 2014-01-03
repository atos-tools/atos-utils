#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS config"

# Config without configuration
$ROOT/bin/atos config -C undef-configuration --print-cfg 2>&1 | grep -i "error: no configured compiler" >/dev/null
[ ${PIPESTATUS[0]} = 1 ]

# Config with an empty configured compiler list
mkdir -p atos-config
touch atos-config/compilers
$ROOT/bin/atos config -C atos-config --print-cfg 2>&1 | grep -i "error: no compiler found in configuration" >/dev/null
[ ${PIPESTATUS[0]} = 1 ]

# Config with a wrong compiler as arguments
$ROOT/bin/atos config --compiler /undef/gcc --print-cfg 2>&1 | grep -i "error: compiler executable not found" >/dev/null
[ ${PIPESTATUS[0]} = 1 ]

# Config for a specific compiler, note that --print-cfg is implied in this case
$ROOT/bin/atos config --compiler `which gcc`

# Config with a compiler symlink
# gcc-4.x -> gcc -> /usr/bin/gcc
ln -sf `which gcc` gcc
ln -sf gcc gcc-4.x
$ROOT/bin/atos config --compiler gcc-4.x --print-cfg

mkdir -p atos-config

echo "`which g++`" >> atos-config/compilers

$ROOT/bin/atos config -C atos-config

[ `cat atos-config/config.json | grep "\"name\": \"gcc\"" | wc -l` -ne 0 ]

$ROOT/bin/atos config -C atos-config -D UNSAFE_OPTIMS

[ `cat atos-config/flags.optim.cfg | grep fassociative-math | wc -l` -ne 0 ]
