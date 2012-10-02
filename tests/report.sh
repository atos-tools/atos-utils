#!/usr/bin/env bash
#
# usage: test_report.sh <test_log
#
set -e
declare -i nb=0
declare -i success=0
declare -i interrupted=0
declare -i fail=0
declare -i skip=0
declare -i bad=0
declare -i status=0

while [ $# -ne 0 ]; do
    line=`tail -1 "$1"`
    shift
    nb=$((nb+1))
    if [[ "$line" == *SUCCESS:* ]]; then
	success=$((success+1))
    elif [[ "$line" == *INTERRUPTED:* ]]; then
	interrupted=$((interrupted+1))
    elif [[ "$line" == *FAIL:* ]]; then
	fail=$((fail+1))
    elif [[ "$line" == *SKIP:* ]]; then
	skip=$((skip+1))
    else
	bad=$((bad+1))
    fi
done

echo "### $nb tests"
echo "### $success success"
echo "### $skip skipped"
echo "### $fail fail"
[ $interrupted == 0 ] || echo "### $interrupted interrupted"
[ $interrupted == 0 ] || status=2
[ $bad == 0 ] || echo "### $bad bad"
[ $fail == 0 -a $bad == 0 ] || status=1
exit $status


	
