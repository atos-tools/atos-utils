#!/usr/bin/env bash
#
#

source `dirname $0`/common.sh

TEST_CASE="ATOS run android board"

# this test must only be run manually
[ "$MAKELEVEL" == "" ] || skip "interactive test"

[ -d "$SDKBASE" -a -d "$ANDROIDROOT" -a -f `which adb-remote.sh` ]

cat > ./android-build.sh <<EOF
#!/usr/bin/env bash
export PREFIX=$SDKBASE/ndk/toolchains/arm-linux-androideabi-4.6.2/prebuilt/linux-x86/bin/arm-linux-androideabi-
export COMPILER_FLAGS="-fno-exceptions -fpic -ffunction-sections -funwind-tables -fstack-protector -Wa,--noexecstack -fno-short-enums -march=armv7-a -mfloat-abi=softfp -mfpu=neon  -mthumb-interwork -finline-functions -fno-inline-functions-called-once -fgcse-after-reload -frerun-cse-after-loop -frename-registers -mthumb -Os -fomit-frame-pointer -fno-strict-aliasing -finline-limit=64"
export LINKER_FLAGS="-nostdlib -Bdynamic -Wl,-T,$SDKBASE/build/core/armelf.x -Wl,-dynamic-linker,/system/bin/linker -Wl,--gc-sections -Wl,-z,nocopyreloc -L$ANDROIDROOT/obj/lib -Wl,-rpath-link=$ANDROIDROOT/obj/lib -lc -lstdc++ -lm $ANDROIDROOT/obj/lib/crtbegin_dynamic.o -Wl,-z,noexecstack -Wl,--fix-cortex-a8 -Wl,--no-undefined $SDKBASE/ndk/toolchains/arm-linux-androideabi-4.6.2/prebuilt/linux-x86/bin/../lib/gcc/arm-linux-androideabi/4.6.2/armv7-a/libgcc.a $ANDROIDROOT/obj/lib/crtend_android.o"
\${PREFIX}gcc \$COMPILER_FLAGS -c $SRCDIR/examples/sha1-c/sha.c -o sha.o
\${PREFIX}gcc \$COMPILER_FLAGS -c $SRCDIR/examples/sha1-c/sha1.c -o sha1.o
\${PREFIX}g++ \$LINKER_FLAGS sha.o sha1.o -o sha1-c
EOF

cat > ./android-run.sh <<EOF
#!/usr/bin/env bash
source `which adb-remote.sh` +r
adb-remote.sh push ./sha1-c /mnt/mmc1p1/sha1-c
adb-remote.sh command "dd if=/dev/urandom bs=20K count=1K 2>/dev/null | time -p /mnt/mmc1p1/sha1-c"
[ "\$REMOTE_PROFILE_DIR" = "" ] || adb-remote.sh getprof "\$REMOTE_PROFILE_DIR" "\$LOCAL_PROFILE_DIR"
EOF

chmod u+x ./android-build.sh ./android-run.sh

$ROOT/bin/atos-init -r ./android-run.sh -b ./android-build.sh -B /work1

atos-opt -r -a "-O2"

atos-opt -r -a "-O2" -f

[ `find atos-configurations/profiles -name "*.gcda" | wc -l` -eq 2 ]

