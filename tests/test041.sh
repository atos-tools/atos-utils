#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="atos -v/-h/help options"

version=`$ROOT/bin/atos -v 2>&1 | awk '{print $1, $2;}'`
[ "$version" == "atos version" ]
version=`$ROOT/bin/atos --version 2>&1 | awk '{print $1, $2;}'`
[ "$version" == "atos version" ]

version=`$ROOT/bin/atos help -v 2>&1 | awk '{print $1, $2;}'`
[ "$version" == "atos version" ]
version=`$ROOT/bin/atos help --version 2>&1 | awk '{print $1, $2;}'`
[ "$version" == "atos version" ]

usage=`$ROOT/bin/atos -h 2>&1 | head -n 1 | awk '{print $1, $2;}'`
[ "$usage" == "usage: atos" ]
usage=`$ROOT/bin/atos --help 2>&1 | head -n 1 | awk '{print $1, $2;}'`
[ "$usage" == "usage: atos" ]

version=`$ROOT/bin/atos help -v 2>&1 | awk '{print $1, $2;}'`
[ "$version" == "atos version" ]
version=`$ROOT/bin/atos help --version 2>&1 | awk '{print $1, $2;}'`
[ "$version" == "atos version" ]

usage=`$ROOT/bin/atos help -h 2>&1 | head -n 1 | awk '{print $1, $2, $3;}'`
[ "$usage" == "usage: atos help" ]
usage=`$ROOT/bin/atos help --help 2>&1 | head -n 1 | awk '{print $1, $2, $3;}'`
[ "$usage" == "usage: atos help" ]

help=`$ROOT/bin/atos help | grep "ATOS auto tuning optimization system manual"`
[ "$help" != "" ]

help=`$ROOT/bin/atos help intro | grep "ATOS Introduction"`
[ "$help" != "" ]

help=`env PAGER= $ROOT/bin/atos help tutorial | grep "ATOS Tutorial"`
[ "$help" != "" ]
