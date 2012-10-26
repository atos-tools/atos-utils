#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS cookie"

c1=`$ROOT/bin/atos-cookie`
c2=`$ROOT/bin/atos-cookie`
[ "$c1" != "$c2" ] # check that they differ
[ `echo "$c1" | wc -c` = 41 ] # sha1 hexdigest is 40 chars (+ \n of echo)

# If a single cookie is given, return it
c3=`$ROOT/bin/atos-cookie --cookie single`
[ "$c3" = "single" ]

# If multiple cookies are given, merge thenm into a new digest
c4=`$ROOT/bin/atos-cookie --cookie first --cookie second`
[ `echo "$c4" | wc -c` = 41 ] # sha1 hexdigest is 40 chars (+ \n of echo)
