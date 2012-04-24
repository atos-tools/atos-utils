set -e
ROOT=${ROOT:-`cd .. && pwd`}
TEST=`basename $0 .sh`

cleanup() {
    local exit=$?
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
}

[ "$DEBUG" = "" ] || set -x
