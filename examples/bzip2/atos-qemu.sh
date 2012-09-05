#!/usr/bin/env bash
set -e
arch=`uname -m`
case $arch in
    i486|i586|i686) arch=i386
	;;
esac

QEMU=${QEMU:-qemu-$arch}
QEMU_INST="$QEMU -count-ifetch"

cleanup() {
    local code=$?
    trap - EXIT
    [ ! -f $tmpfile ] || rm -f $tmpfile
    exit $code
}
trap cleanup INT QUIT TERM EXIT
tmpfile=`mktemp /tmp/run.XXXXXX`

${QEMU_INST} "$@" 2>$tmpfile
code=$?
cat <$tmpfile >&2
awk '{if ($1 == "qemu:") { print "user " $10 / 1000000000; }}' <$tmpfile >&2
exit $code
