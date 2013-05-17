#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="atos-audit transparency"


cat >makefile.tst <<EOF
SHELL=/bin/sh
OUT1=\$(shell gcc --version 2>/dev/null)
OUT2=\$(shell gcc /failure 2>&1 >/dev/null)

.PHONY: all

all:
	@echo STDOUT: "\$(OUT1)" >make.out
	@echo STDERR: "\$(OUT2)" >make.err

EOF

# Run makefile and backup make.out/make.err
make -f makefile.tst
mv make.out make.out.bak
mv make.err make.err.bak

rm -rf atos-configurations make.out make.err
# Run audit and check output
$ROOT/bin/atos-audit make -f makefile.tst
diff make.out make.out.bak
diff make.err make.err.bak

rm -rf atos-configurations make.out make.err
# Run audit in debug mode and check output
$ROOT/bin/atos-audit --debug make -f makefile.tst 2>&1
diff make.out make.out.bak
diff make.err make.err.bak

rm -rf atos-configurations make.out make.err
# Run audit and build in force mode and check output
$ROOT/bin/atos-audit --force make -f makefile.tst
$ROOT/bin/atos-build --debug 2>&1
diff make.out make.out.bak
diff make.err make.err.bak
