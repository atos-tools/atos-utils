#!/usr/bin/env bash
set -ex

# atos-init                                             \
#   --build-script="gcc sha1.c sha.c -o sha1-c"         \
#   --run-script="./run_lsf.sh"                         \
#   --remote_path=/home/compwork/$USER/profile          \
#   --build-jobs=50 --run-jobs=50 --nbruns=1
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
/bin/cp ./sha1-c $TMPDIR

cd $TMPDIR

cat > run_qemu.sh <<EOF
#!/usr/bin/env bash
set -ex
tmpfile=\`mktemp \$PWD/run.XXXXXX\`
dd if=/dev/urandom bs=4K count=5K 2>/dev/null | $SWSTBIN/qemu-x86_64 -count-ifetch ./sha1-c 2>\$tmpfile
[ \${PIPESTATUS[0]} = 0 ] || exit 1
awk '{if (\$1 == "qemu:") { print "user " \$10 / 1000000000; }}' <\$tmpfile
EOF
chmod +x run_qemu.sh

echo "### Submitting JOB $JOB_NAME"
$JOBTOOLS/job-submit.sh                           \
    cond="select[rh50 && cpuf > 40]span[hosts=1]" \
    xtra_opt="-n 1" queue=reg timeout=600         \
    sid=$SESSION_ID jname=$JOB_NAME               \
    -- $TMPDIR/run_qemu.sh

echo "### Waiting for JOB $JOB_NAME"
$JOBTOOLS/job-wait.sh sid=$SESSION_ID jname=$JOB_NAME

echo "### JOB Output $JOB_NAME"
$JOBTOOLS/job-output.sh sid=$SESSION_ID jname=$JOB_NAME

echo "### JOB Status $JOB_NAME"
$JOBTOOLS/job-status.sh sid=$SESSION_ID jname=$JOB_NAME

[ "$REMOTE_PROFILE_DIR" = "" ] || cp $REMOTE_PROFILE_DIR/* $LOCAL_PROFILE_DIR
