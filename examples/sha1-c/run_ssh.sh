#!/usr/bin/env bash
set -ex

# atos-init                                     \
#   --build-script="gcc sha1.c sha.c -o sha1-c" \
#   --run-script="./run_ssh.sh"                 \
#   --remote_path=/tmp                          \
#   --build-jobs=2 --run-jobs=4 --nbruns=2

# allocate target host using run_slot number
run_slot=${RUN_SLOT:-0} # for REF and non-parallelized runs
[ "$run_slot" != "0" ] || hostname=gnx5855
[ "$run_slot" != "1" ] || hostname=gnx5855
[ "$run_slot" != "2" ] || hostname=gnx5855
[ "$run_slot" != "3" ] || hostname=$HOSTNAME # localhost
[ "$hostname" != "" ]

tmpdir=`ssh $hostname mktemp -d`

scp sha1-c $hostname:$tmpdir/sha1-c

ssh $hostname "/bin/dd if=/dev/urandom bs=4K count=1K 2>/dev/null | time -p $tmpdir/sha1-c"

# get profile files back and clean tmp directories on target host
[ "$REMOTE_PROFILE_DIR" = "" ] \
    || scp $hostname:$REMOTE_PROFILE_DIR/* $LOCAL_PROFILE_DIR
[ "$REMOTE_PROFILE_DIR" = "" ] \
    || ssh $hostname /bin/rm -fr $REMOTE_PROFILE_DIR
ssh $hostname /bin/rm -fr $tmpdir
