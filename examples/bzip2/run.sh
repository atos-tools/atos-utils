#!/bin/sh
set -e
dir=`dirname $0`

[ "$1" != "" ] || set -- ./bzip2
$dir/compress.sh "$@"
$dir/decompress.sh "$@"

