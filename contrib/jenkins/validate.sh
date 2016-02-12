#!/usr/bin/env bash
#
# Copyright (C) STMicroelectronics Ltd. 2012
#
# This file is part of ATOS.
#
# ATOS is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
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
LONG_TESTS=${LONG_TESTS:-1}

echo "Setting clean environment"
export PATH=/usr/local/bin:/usr/bin:/bin
unset LD_LIBRARY_PATH
unset PYTHONPATH

echo "Preparing workspace..."
cd $WORKSPACE
LOGS=$WORKSPACE/logs
DEVIMAGE=$WORKSPACE/devimage
DEPENDENCIES=$WORKSPACE/dependencies
BUILD=$WORKSPACE/build
mkdir -p $LOGS $DEVIMAGE $BUILD $DEPENDENCIES
rm -rf $LOGS/* $DEVIMAGE/* $BUILD/* $DEPENDENCIES/* atos-utils-devimage.tgz

echo "Retrieving binary build of proot tool..."
wget -q -O proot-devimage.tgz http://aci-hostname:8000/job/cec-okla-proot-dev-guillon/lastStableBuild/artifact/proot-devimage.tgz
tar xvzf proot-devimage.tgz -C $DEVIMAGE

echo "Retrieving binary build of python-jsonlib package..."
wget -q -O python-jsonlib.tgz http://aci-hostname:8000/job/cec-okla-python-jsonlib/lastStableBuild/artifact/python-jsonlib.tgz
tar xvzf python-jsonlib.tgz -C $DEVIMAGE

echo "Retrieving binary build of python-argparse package..."
wget -q -O python-argparse.tgz http://aci-hostname:8000/job/cec-okla-python-argparse/lastStableBuild/artifact/python-argparse.tgz
tar xvzf python-argparse.tgz -C $DEVIMAGE

echo "Retrieving binary build of python-docutils package..."
wget -q -O python-docutils.tgz http://aci-hostname:8000/job/cec-okla-python-docutils/lastStableBuild/artifact/python-docutils.tgz
tar xvzf python-docutils.tgz -C $DEVIMAGE

echo "Retrieving binary build of python-coverage package..."
wget -q -O python-coverage.tgz http://aci-hostname:8000/job/cec-okla-python-coverage/lastStableBuild/artifact/python-coverage.tgz
tar xvzf python-coverage.tgz -C $DEPENDENCIES

echo "Retrieving binary build of qemu-system-arm package..."
wget -q -O qemu-system-arm-devimage.tgz http://aci-hostname:8000/job/cec-okla-atos-qemu-system-arm/lastStableBuild/artifact/qemu-system-arm-devimage.tgz
tar xvzf qemu-system-arm-devimage.tgz -C $DEVIMAGE

echo "Extracting gcc-4.7.2 native build"
rm -rf prebuilt/gcc-4.7.2
git clone gitolite@hostname:atos/gcc-prebuilt-ubuntu-10.04-x86-64-gcc-4.7.2.git prebuilt/gcc-4.7.2

# echo "export path and license file for rvct toolset..."
# export ARMLMD_LICENSE_FILE=8224@gmx333:8224@gnx334:8224@gnx335
# ARMCCPATH=/sw/st/gnu_compil/comp/arm/rvds/ds5.01-build-64/linux/bin
# export PATH=${PATH}:${ARMCCPATH}

echo "Adding local PATH/PYTHONPATH/LD_LIBRARY_PATH"
export PATH=$DEVIMAGE/usr/local/bin:$DEPENDENCIES/usr/local/bin:$PATH
export PYTHONPATH=$DEVIMAGE/usr/local/lib/python:$DEPENDENCIES/usr/local/lib/python
export LD_LIBRARY_PATH=$DEVIMAGE/usr/local/lib/

echo "Building atos-utils..."
cd $BUILD
make -f $GITROOT/GNUmakefile -j 4 distclean
make -f $GITROOT/GNUmakefile -j 4 all doc

#
# Add gcc-4.7.2 to path only for tests as this compiler does not
# support -m32 and thus cannot compile ATOS plugins
#
PATH=$WORKSPACE/prebuilt/gcc-4.7.2/bin:$PATH
echo "Checking atos-utils..."
make -f $GITROOT/GNUmakefile -j 4 all install install-doc PREFIX=$DEVIMAGE/usr/local
make ROOT=$DEVIMAGE/usr/local COVERAGE_DIR=$WORKSPACE/coverage -f $GITROOT/GNUmakefile -j 4 coverage
make -f $GITROOT/GNUmakefile examples-nograph

echo "Archiving atos-utils..."
cd $DEVIMAGE
tar cvzf $WORKSPACE/atos-utils-devimage.tgz usr

echo "Completed."
