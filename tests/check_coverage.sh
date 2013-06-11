#!/usr/bin/env bash
#
# usage: check_coverage.sh
#
set -e

SRCDIR=`cd \`dirname $0\`; pwd`
COV_INCLUDE='/*/bin/*,/*/lib/atos/python/atoslib/*,/*/lib/atos/atos-*'
COV_EXCLUDE='/*/atos-graph'

[ -d $COVERAGE_DIR ]

cd $COVERAGE_DIR

coverage combine

# print coverage ratio (ignoring #pragma uncovered)
coverage report --include=$COV_INCLUDE --omit $COV_EXCLUDE \
    --rcfile=$SRCDIR/coverage_uncov.rc \
    | tail -1 \
    | awk '{print "COVERAGE", $6 , ":", ($2 + $4) - ($3 + $5), "/", ($2 + $4)}'

# look at uncovered code (not ignoring #pragma uncovered)
coverage report --include=$COV_INCLUDE --omit $COV_EXCLUDE \
    --rcfile=$SRCDIR/coverage.rc > coverage.txt

uncovered=`cat coverage.txt | tail -1 | awk '{print ($3 + $5)}'`

if [ $uncovered -ne 0 ]; then
    # print lines not covered and not ignored using pragma
    echo "COVERAGE_ERROR: non covered code:"
    while read line; do
	[ `echo $line | grep "%" | wc -l` -eq 0 ] \
	    && continue
	[ `echo $line | grep TOTAL | wc -l` -ne 0 ] \
	    && continue
	[ `echo $line | grep "100.0%" | wc -l` -ne 0 ] \
	    && continue
	module=`basename \`echo $line | awk '{ print $1 }'\``
	linenums=`echo $line | sed 's/.*%//'`
	echo "  module: $module, lines: $linenums"
    done < coverage.txt
    # some non-documented uncovered code: classic report
    # (not ignoring "pragma uncovered" lines)
    coverage html  -d html --include=$COV_INCLUDE --omit $COV_EXCLUDE \
	--rcfile=$SRCDIR/coverage.rc
else
    # no non-documented uncovered code: strict report
    # (ignoring "pragma uncovered" lines)
    coverage html  -d html --include=$COV_INCLUDE --omit $COV_EXCLUDE \
	--rcfile=$SRCDIR/coverage_uncov.rc
fi

echo "check_coverage_status: $uncovered"

exit $uncovered
