set -e
DIRNAME=`dirname $0`
SRCDIR=`cd $DIRNAME/.. && pwd`
ROOT=${ROOT:-$SRCDIR}
TEST=`basename $0 .sh`
TMPDIR=${TMPDIR:-/tmp}
KEEPTEST=${KEEPTEST:-0}

cleanup() {
    local exit=$?
    [ ! -d "$TMPTEST" -o "$KEEPTEST" != 0 ] || rm -rf $TMPTEST
    [ $exit != 0 ] || success
    [ $exit = 0 -o $exit -ge 128 ] || failure
    [ $exit = 0 -o $exit -lt 128 ] || interrupted && trap - EXIT && exit $exit
}

trap "cleanup" INT QUIT TERM EXIT

interrupted() {
    echo "INTERRUPTED: $TEST: $TEST_CASE" >&2
}

failure() {
    echo "FAILURE: $TEST: $TEST_CASE" >&2
}

success() {
    echo "SUCCESS: $TEST: $TEST_CASE" >&2
}

skip() {
    echo "SKIPPED: $TEST: $TEST_CASE" >&2
    trap - EXIT && exit 0
}

[ "$DEBUG" = "" ] || set -x

TMPTEST=`mktemp -d $TMPDIR/atos-test.XXXXXX`
[ "$KEEPTEST" = 0 ] || echo "Keeping test directory in: $TMPTEST"
cd $TMPTEST
