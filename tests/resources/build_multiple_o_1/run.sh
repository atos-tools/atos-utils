#!/bin/sh
set -e

./main.exe > out.log
grep 'foo' out.log
./main1.exe > out.log
grep 'bar' out.log
