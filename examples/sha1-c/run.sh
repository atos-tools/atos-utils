#!/usr/bin/env bash
set -e
dd if=/dev/urandom status=noxfer bs=4K count=1K 2>/dev/null | ./sha1-c
exit ${PIPESTATUS[0]}


