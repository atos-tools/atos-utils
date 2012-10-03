set -e
DIRNAME=`dirname $0`
SRCDIR=${SRCDIR:-`cd $DIRNAME/.. && pwd`}
ROOT=${ROOT:-$SRCDIR}
TEST=`basename $0 .sh`
TMPDIR=${TMPDIR:-/tmp}
KEEPTEST=${KEEPTEST:-0}
_skipped=0

cleanup() {
    local exit=$?
    cd $TMPDIR # ensure not in TMPTEST before cleaning
    [ ! -d "$TMPTEST" -o "$KEEPTEST" != 0 ] || rm -rf $TMPTEST
    [ $exit != 0 -o $_skipped = 1 ] || success
    [ $exit = 0 -o $exit -ge 128 ] || failure
    [ $exit = 0 -o $exit -lt 128 ] || interrupted && trap - EXIT && exit $exit
}

trap "cleanup" INT QUIT TERM EXIT

interrupted() {
    echo "***INTERRUPTED: $TEST: $TEST_CASE" >&2
}

failure() {
    local reason=${1+": $1"}
    echo "***FAIL: $TEST: $TEST_CASE$reason" >&2
}

success() {
    echo "SUCCESS: $TEST: $TEST_CASE" >&2
}

skip() {
    local reason=${1+": $1"}
    echo "---SKIP: $TEST: $TEST_CASE$reason" >&2
    _skipped=1
    exit 0
}

[ "$DEBUG" = "" ] || set -x

[ "$KEEPTEST" != 0 ] || TMPTEST=`mktemp -d $TMPDIR/atos-test.XXXXXX`
[ "$KEEPTEST" = 0 ] || TMPTEST=`rm -rf $TEST.dir && mkdir -p $TEST.dir && echo $TEST.dir`
[ "$KEEPTEST" = 0 ] || echo "Keeping test directory in: $TMPTEST"
cd $TMPTEST
