#!/usr/bin/env bash
#
# Copyright (C) STMicroelectronics Ltd. 2012
#
# This file is part of ATOS.
#
# ATOS is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License v2.0
# as published by the Free Software Foundation
#
# ATOS is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# v2.0 along with ATOS. If not, see <http://www.gnu.org/licenses/>.
#
#
# Script for building dependencies and atos-utils and validating with Jenkins.
#
# This script can be also from a user environment but note that:
# - WORKSPACE envvar must be defined to a working directory (default: $PWD),
# - GITROOT envvar must be defined to the git root (default: $WORKSPACE/atos-utils),
# - DEBUG=1 for verbose output,
# - the script is working for local build from hostname machines.
#
# Usage: env DEBUG=1 WORKSPACE=<tmpdir> GITROOT=<gitroot> validate.sh
#
# The output of the script is an archive of the installed image in usr/local.
#

set -e
[ "$DEBUG" = "" ] || set -x

dir=`dirname $0`
dir=`cd $dir && pwd`
srcdir=`cd $dir/../.. && pwd`

echo "Getting parameters..."
WORKSPACE=${WORKSPACE:-$PWD}
GITROOT=${GITROOT:-$srcdir}

echo "Setting clean environment"
export PATH=/usr/local/bin:/usr/bin:/bin
unset LD_LIBRARY_PATH
unset PYTHONPATH

echo "Preparing workspace..."
cd $WORKSPACE
LOGS=$WORKSPACE/logs
DEVIMAGE=$WORKSPACE/devimage
BUILD=$WORKSPACE/build
mkdir -p $LOGS $DEVIMAGE $BUILD
rm -rf $LOGS/* $DEVIMAGE/* $BUILD/* atos-utils-devimage.tgz

echo "Retrieving binary build of proot tool..."
wget -q -O proot-devimage.tgz http://aci-hostname:8000/job/cec-okla-proot-dev-guillon/lastStableBuild/artifact/proot-devimage.tgz
tar xvzf proot-devimage.tgz -C $DEVIMAGE

echo "Retrieving binary build of python-graph package..."
wget -q -O python-graph-core.tgz http://aci-hostname:8000/job/cec-okla-python-graph/lastStableBuild/artifact/python-graph-core.tgz
tar xvzf python-graph-core.tgz -C $DEVIMAGE

echo "Retrieving binary build of python-jsonlib package..."
wget -q -O python-jsonlib.tgz http://aci-hostname:8000/job/cec-okla-python-jsonlib/lastStableBuild/artifact/python-jsonlib.tgz
tar xvzf python-jsonlib.tgz -C $DEVIMAGE

echo "Retrieving binary build of python-argparse package..."
wget -q -O python-argparse.tgz http://aci-hostname:8000/job/cec-okla-python-argparse/lastStableBuild/artifact/python-argparse.tgz
tar xvzf python-argparse.tgz -C $DEVIMAGE

echo "Retrieving binary build of python-docutils package..."
wget -q -O python-docutils.tgz http://aci-hostname:8000/job/cec-okla-python-docutils/lastStableBuild/artifact/python-docutils.tgz
tar xvzf python-docutils.tgz -C $DEVIMAGE


echo "Adding local PATH/PYTHONPATH"
export PATH=$DEVIMAGE/usr/local/bin:$PATH
export PYTHONPATH=$DEVIMAGE/usr/local/lib/python

echo "Building atos-utils..."
cd $BUILD
make -f $GITROOT/GNUmakefile -j 4 distclean
make -f $GITROOT/GNUmakefile -j 4 all doc

echo "Checking atos-utils..."
make -f $GITROOT/GNUmakefile -j 4 check
make -f $GITROOT/GNUmakefile examples-nograph

echo "Installing atos-utils..."
make -f $GITROOT/GNUmakefile -j 4 install install-doc PREFIX=$DEVIMAGE/usr/local

echo "Checking installed version of atos-utils..."
ROOT=$DEVIMAGE/usr/local make -f $GITROOT/GNUmakefile -j 4 check

echo "Archiving atos-utils..."
cd $DEVIMAGE
tar cvzf $WORKSPACE/atos-utils-devimage.tgz usr

echo "Completed."
