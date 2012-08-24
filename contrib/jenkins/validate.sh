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

echo "Getting parameters..."
WORKSPACE=${WORKSPACE:-$PWD}
GITROOT=${GITROOT:-$WORKSPACE/atos-utils}

echo "Preparing workspace..."
cd $WORKSPACE
LOGS=$WORKSPACE/logs
DEVIMAGE=$WORKSPACE/devimage
mkdir -p $LOGS $DEVIMAGE
rm -rf $LOGS/* $DEVIMAGE/*

echo "Retrieving binary build of proot tool..."
wget -q -O proot-devimage.tgz http://aci-hostname:8000/job/cec-okla-proot-dev-guillon/lastStableBuild/artifact/proot-devimage.tgz
tar xvzf proot-devimage.tgz -C $DEVIMAGE
export PATH=$PATH:$DEVIMAGE/usr/local/bin

echo "Retrieving binary build of python-graph package..."
wget -q -O python-graph-core.tgz http://aci-hostname:8000/job/cec-okla-python-graph/lastStableBuild/artifact/python-graph-core.tgz
tar xvzf python-graph-core.tgz -C $DEVIMAGE

echo "Retrieving binary build of python-jsonlib package..."
wget -q -O python-jsonlib.tgz http://aci-hostname:8000/job/cec-okla-python-jsonlib/lastStableBuild/artifact/python-jsonlib.tgz
tar xvzf python-jsonlib.tgz -C $DEVIMAGE

echo "Retrieving binary build of python-argparse package..."
wget -q -O python-argparse.tgz http://aci-hostname:8000/job/cec-okla-python-argparse/lastStableBuild/artifact/python-argparse.tgz
tar xvzf python-argparse.tgz -C $DEVIMAGE

export PYTHONPATH=$DEVIMAGE/usr/local/lib/python

echo "Building atos-utils..."
cd $GITROOT
make all

echo "Checking atos-utils..."
make check
make examples-nograph

echo "Installing atos-utils..."
make install PREFIX=$DEVIMAGE/usr/local

echo "Checking installed version of atos-utils..."
ROOT=$DEVIMAGE/usr/local make check

echo "Archiving atos-utils..."
cd $DEVIMAGE
tar cvzf $WORKSPACE/atos-utils-devimage.tgz usr

echo "Completed."
