#!/usr/bin/env bash
set -e
dd if=/dev/urandom status=noxfer iflag=fullblock bs=4K count=1K | ./sha1-c
exit ${PIPESTATUS[0]}


