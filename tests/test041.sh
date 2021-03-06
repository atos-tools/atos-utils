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

help=`$ROOT/bin/atos-help | grep "ATOS auto tuning optimization system manual"`
[ "$help" != "" ]

help=`$ROOT/bin/atos help intro | grep "ATOS Introduction"`
[ "$help" != "" ]

help=`env PAGER= $ROOT/bin/atos help tutorial | grep "ATOS Tutorial"`
[ "$help" != "" ]

help=`PAGER=less $ROOT/bin/atos help -t intro | grep "ATOS Introduction"`
[ "$help" != "" ]

help=`PAGER= $ROOT/bin/atos help -t intro | grep "ATOS Introduction"`
[ "$help" != "" ]

help=`unset PAGER && $ROOT/bin/atos help -t intro | grep "ATOS Introduction"`
[ "$help" != "" ]

python=`which python`
help=`PATH= PAGER= $python $ROOT/bin/atos help intro | grep "ATOS Introduction"`
[ "$help" != "" ]

help=`$ROOT/bin/atos help not_found_section 2>&1 | grep "manual not found"`
[ "$help" != "" ]

# Either we get an output if manpage is available or an error.
# We are not strict there as the tools may have been installed
# without 'make doc'.
help=`$ROOT/bin/atos help -m intro 2>&1 | grep -e "ATOS Introduction" -e  "manual not found for"`
[ "$help" != "" ]

help_default=`$ROOT/bin/atos -h | wc -l`
help_verbose=`$ROOT/bin/atos -h -v | wc -l`
[ $help_default -lt $help_verbose ]

help_default=`$ROOT/bin/atos-explore -h | wc -l`
help_verbose=`$ROOT/bin/atos-explore -h -v | wc -l`
[ $help_default -lt $help_verbose ]
