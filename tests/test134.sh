#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS relocatable objects"

cp -a $SRCDIR/tests/resources/build_reloc_1/* .

# Build a .exe with two .o
# Check that objects contains two .o that targets is the single main.exe
$ROOT/bin/atos-init -b "make clean final_exe" -r "echo user 1" -c
[ `cat atos-configurations/objects | grep -v '^#' | wc -l` -eq 2 ]
[ `cat atos-configurations/objects | grep -v '^#' | grep -v '\.o' | wc -l` -eq 0 ]
[ `cat atos-configurations/targets | grep -v '^#' | wc -l` -eq 1 ]
[ `cat atos-configurations/targets | grep -v '^#' | grep main.exe | wc -l` -eq 1 ]

# Build a relocatable .ro with two .o
# Check that objects contains two .o that targets is the single main.ro
$ROOT/bin/atos-init -b "make clean final_reloc" -r "echo user 1" -c
[ `cat atos-configurations/objects | grep -v '^#' | wc -l` -eq 2 ]
[ `cat atos-configurations/objects | grep -v '^#' | grep -v '\.o' | wc -l` -eq 0 ]
[ `cat atos-configurations/targets | grep -v '^#' | wc -l` -eq 1 ]
[ `cat atos-configurations/targets | grep -v '^#' | grep main.ro | wc -l` -eq 1 ]

# Build an exe from two .o with an intermediate .ro
# Check that objects contains two .o that targets is the single main_ro.exe
$ROOT/bin/atos-init -b "make clean intermediate_reloc" -r "echo user 1" -c
[ `cat atos-configurations/objects | grep -v '^#' | wc -l` -eq 2 ]
[ `cat atos-configurations/objects | grep -v '^#' | grep -v '\.o' | wc -l` -eq 0 ]
[ `cat atos-configurations/targets | grep -v '^#' | wc -l` -eq 1 ]
[ `cat atos-configurations/targets | grep -v '^#' | grep main_ro.exe | wc -l` -eq 1 ]


# Build a .exe with two .o using ld (instead of the driver)
# Check that objects contains two .o that targets is the single main_ld.exe
$ROOT/bin/atos-init -b "make clean final_ld_exe" -r "echo user 1" -c
[ `cat atos-configurations/objects | grep -v '^#' | wc -l` -eq 2 ]
[ `cat atos-configurations/objects | grep -v '^#' | grep -v '\.o' | wc -l` -eq 0 ]
[ `cat atos-configurations/targets | grep -v '^#' | wc -l` -eq 1 ]
[ `cat atos-configurations/targets | grep -v '^#' | grep main_ld.exe | wc -l` -eq 1 ]

# Build a relocatable .ro with two .o using ld (instead of the driver)
# Check that objects contains two .o that targets is the single main_ld.ro
$ROOT/bin/atos-init -b "make clean final_ld_reloc" -r "echo user 1" -c
[ `cat atos-configurations/objects | grep -v '^#' | wc -l` -eq 2 ]
[ `cat atos-configurations/objects | grep -v '^#' | grep -v '\.o' | wc -l` -eq 0 ]
[ `cat atos-configurations/targets | grep -v '^#' | wc -l` -eq 1 ]
[ `cat atos-configurations/targets | grep -v '^#' | grep main_ld.ro | wc -l` -eq 1 ]

# Build an exe from two .o with an intermediate .ro using ld (instead of the driver)
# Check that objects contains two .o that targets is the single main_ld_ro.exe
$ROOT/bin/atos-init -b "make clean intermediate_ld_reloc" -r "echo user 1" -c
[ `cat atos-configurations/objects | grep -v '^#' | wc -l` -eq 2 ]
[ `cat atos-configurations/objects | grep -v '^#' | grep -v '\.o' | wc -l` -eq 0 ]
[ `cat atos-configurations/targets | grep -v '^#' | wc -l` -eq 1 ]
[ `cat atos-configurations/targets | grep -v '^#' | grep main_ld_ro.exe | wc -l` -eq 1 ]

# Build all six targets at once
# Check that objects contains 8 .o and that targets contain the 4 executables
# Chack that no .ro relocatable is in the targets (they are non final in this case)
$ROOT/bin/atos-init -b "make clean all" -r "echo user 1" -c
[ `cat atos-configurations/objects | grep -v '^#' | wc -l` -eq 8 ]
[ `cat atos-configurations/objects | grep -v '^#' | grep -v '\.o' | wc -l` -eq 0 ]
[ `cat atos-configurations/targets | grep -v '^#' | wc -l` -eq 4 ]
[ `cat atos-configurations/targets | grep -v '^#' | grep '\.exe' | wc -l` -eq 4 ]
[ `cat atos-configurations/targets | grep -v '^#' | grep '\.ro' | wc -l` -eq 0 ]
