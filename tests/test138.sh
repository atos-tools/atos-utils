#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS deps targets subset"

# If some .o is shared between several executables
# and only a subset of these executables are specified
# as configured targets, there may be an issue
# when options must be present both at compile and link time.
# In particular -fprofile-generate must be passed
# at link time as soon as some .o was compiled with
# this option.

cp -a $ROOT/share/atos/examples/sha1 .
cd sha1

# Case 1:
# The build links both sha and shatest
# but the user wants only sha.
# The link of shatest may fail as both
# executable share the same sha1.o object
$ROOT/bin/atos-audit make clean shatest sha
$ROOT/bin/atos-deps sha
$ROOT/bin/atos-build -a "-fprofile-generate"

# Case 2:
# The build links both sha, sha.so and sha-shared
# but the user wants only sha-shared.
# The link of sha-shared may fail as both
# executable share the same sha.o object.
$ROOT/bin/atos-audit make clean sha sha.so sha-shared
$ROOT/bin/atos-deps sha-shared
$ROOT/bin/atos-build -a "-fprofile-generate"
