#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS deps spaces"

cat > test.c <<EOF
#include <stdio.h>
/* XXX is ' A' (ignore the single quotes). */
#ifndef XXX
#error XXX is not defined
#endif
/* YYY is '" A"' (ignore the single quotes). */
#ifndef YYY
#error YYY is not defined
#endif
/* ZZZ is ''A'' (ignore the surrounding single quotes). */
#ifndef ZZZ
#error ZZZ is not defined
#endif
/* Define A such that XXX expands into " A". */
#define A " A"
int main(){
   printf("XXX: <%s>\n", XXX);
   printf("YYY: <\"%s\">\n", YYY);
   printf("ZZZ: <\'%c\'>\n", ZZZ);
   return 0;
}
EOF

$ROOT/bin/atos-init -b 'gcc ./test.c -DXXX=" A" -DYYY=\"\ A\" -DZZZ='"\'A\'" -r "./a.out"

