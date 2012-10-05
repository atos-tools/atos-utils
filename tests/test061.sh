#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh
export ROOT # needed for the test scripts

TEST_CASE="ATOS ACF attribs and params"

# This is a long test
[ "$LONG_TESTS" == "1" -o "$MAKELEVEL" = "" ] || skip "long test skipped unless LONG_TESTS=1"

config_query() {
    $ROOT/bin/atos lib config -u -t -q $*
}

cp -a $SRCDIR/tests/resources/acf_attribs_and_params/* .

$ROOT/bin/atos-init \
    -r "make -s none" \
    -b "make config" --no-run

# Check if acf plugin is available for host compiler
if [ ! -f "`config_query '$.compilers[*].plugin_acf'`" ]; then
    skip "acf plugins not available for compiler"
fi

# Check if host compiler has plugin support
if [ "`config_query '$.compilers[*].plugins_enabled'`" != "1" ]; then
    skip "plugins not supported by compiler"
fi

export GCC_VERSION=`config_query '$.compilers[*].version'`
export GCC_TARGET=`config_query '$.compilers[*].target'`
export LTO_ENABLED=`config_query '$.compilers[*].lto_enabled'`

GCC_MAJ_MIN=`echo $GCC_VERSION | sed -e "s:\.[0-9]*$::"`;

./acf_test.sh 2>&1 | tee acf_test.log
sed -n -e "/^.*FAILED$/p" acf_test.log | sort > acf_test_FAILED.log
cp expected_FAILED.$GCC_MAJ_MIN.txt expected_tmp.log
diff acf_test_FAILED.log expected_tmp.log || exit 1

if [ $LTO_ENABLED -eq 1 ]; then
    LTO=1 ./acf_test.sh 2>&1 | tee acf_test_lto.log
    sed -n -e "/^.*FAILED$/p" acf_test_lto.log | sort > acf_test_FAILED.log
    sed -e "s/ => / LTO=1 => /" expected_FAILED.$GCC_MAJ_MIN.txt > expected_tmp.log
    diff acf_test_FAILED.log expected_tmp.log || exit 1
fi

exit 0
