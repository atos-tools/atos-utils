#!/usr/bin/env bash
set -ex

# atos-init                                             \
#   --build-script="gcc sha1.c sha.c -o sha1-c"         \
#   --run-script="./run_qemu.sh"                        \
#   --remote-exec-script="./exec_lsf.sh"                \
#   --build-jobs=30 --run-jobs=30 --nbruns=1
#
# atos-graph --follow &
#
# atos-explore-random                                   \
#   --optim-levels=-O2                                  \
#   --optim-variants=fdo+lto                            \
#   --nbiters=500

JOBTOOLS=/sw/st/gnu_compil/comp/scripts/jobtools/
SWSTBIN=/sw/st/gnu_compil/gnu/linux-rh-ws-4-x86_64/bin/
SESSION_ID=SHA1X
JOB_NAME=R$$

cleanup() {
    [ ! -d "$TMPDIR" ] || /bin/rm -fr $TMPDIR
}
trap "cleanup" INT QUIT TERM EXIT

TMPDIR=`mktemp -d --tmpdir=/home/compwork/$USER/ -t tmp.atos.XXXXXXXXXX`

[ -d "$TMPDIR" ]
[ -f "$ATOS_CARE_SRC" ]

echo "### Decompressing ATOS-CARE archive"
( cd $TMPDIR; tar xzvf $ATOS_CARE_SRC )

echo "### Submitting JOB $JOB_NAME"
$JOBTOOLS/job-submit.sh                           \
    cond="select[rh50 && cpuf > 40]span[hosts=1]" \
    xtra_opt="-n 1" queue=reg timeout=600         \
    sid=$SESSION_ID jname=$JOB_NAME               \
    -- $TMPDIR/exec.sh

echo "### Waiting for JOB $JOB_NAME"
$JOBTOOLS/job-wait.sh sid=$SESSION_ID jname=$JOB_NAME

echo "### JOB Output $JOB_NAME"
$JOBTOOLS/job-output.sh sid=$SESSION_ID jname=$JOB_NAME

echo "### JOB Status $JOB_NAME"
$JOBTOOLS/job-status.sh sid=$SESSION_ID jname=$JOB_NAME

echo "### Pulling ATOS-CARE archive"
cp $TMPDIR/atos.tar.gz $ATOS_CARE_DST
