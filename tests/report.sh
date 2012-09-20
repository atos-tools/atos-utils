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

while read line; do
    if [[ "$line" == *SUCCESS:* ]]; then
	success=$((success+1))
	nb=$((nb+1))
    elif [[ "$line" == *INTERRUPTED:* ]]; then
	interrupted=$((interrupted+1))
	nb=$((nb+1))
    elif [[ "$line" == *FAIL:* ]]; then
	fail=$((fail+1))
	nb=$((nb+1))
    elif [[ "$line" == *SKIP:* ]]; then
	skip=$((skip+1))
	nb=$((nb+1))
    fi
done

echo "### $nb tests"
echo "### $success success"
echo "### $skip skipped"
echo "### $fail fail"
[ $interrupted == 0 ] || echo "### $interrupted interrupted"
[ $interrupted == 0 ] || exit 2
[ $fail == 0 ] || exit 1



	
