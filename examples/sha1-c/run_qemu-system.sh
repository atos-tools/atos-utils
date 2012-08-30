#!/usr/bin/env bash
set -e
tmpfile=`mktemp /tmp/run.XXXXXX`
arch=arm
case arch in
    i386|i586|i686) arch=i386
	;;
esac
dd if=/dev/urandom status=noxfer iflag=fullblock bs=4K count=1K 2>/dev/null | qemu-system-$arch  -tcg-plugin icount -cpu cortex-a9 -semihosting -nographic -kernel ./sha1-c 2>$tmpfile
[ ${PIPESTATUS[0]} = 0 ] || exit 1
awk '{if ($1 == "<system>") { print "user " $11; }}' <$tmpfile


