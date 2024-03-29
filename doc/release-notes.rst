=============
ATOS RELEASES
=============

ATOS 4.1
========

Special release to prepare for ATOS externalization, following the ST FOSS-OUT
process outcomes (https://hostname/foss-out.php?code=FOSS-OUT-15027).
The release is directly derived from ATOS 4.0, adding no additional features,
but applying the following adaptations, to take into account the ST FOSS-OUT
audit requirements:
 * Removal of the Atos web interface commands enabling communication with ATOS
portal, to get rid of the Python requests package usage (Apache2 licensed, not
compatible with the GPLv2 license)
 * Modification of all header files for licensing the code as GPLv2 or later
 * Addition of missing Samuel Sutch copyright in atoslib/deep_eq.py


ATOS 4.0
========

Restricted to ST internal use.

ATOS is an Auto Tuning Optimization System that is able to find automatically
the best performance/size tradeoff from a build system and a training
application.

A recent presentation of ATOS tools can be found here:
  https://hostname/plugins/docman/?group_id=1806&action=show&id=348353

Refer to the ATOS Codex Project at:
  http://hostname/projects/atos

For other project resources and links, refer to the release certificate at:
  http://hostname/wiki/index.php?pagename=SRCATOS400&group_id=2626

The tutorial of ATOS tools is available online at:
  https://hostname/wiki/?group_id=2626&pagename=ATOS_Tutorial

Release content
===============

New features and Improvements:
 * Added kernel build support
 * Extended GCC compiler support (GCC-4.8)
 * Accelerated explorations using weighted flags
 * Accelerated explorations reusing existing results
 * Parallel and remote execution (build, run) using CARE tools,
   refer to http://reproducible.io and http://proot.me for details
 * Added Flags pruning exploration

Installation and Usage
======================

Download the binary package from:
  https://hostname/file/showfiles.php?group_id=2626

Install with::

    $sh cd $PREFIX
    $sh tar xvzf atos-4.0.tgz
    $sh export PATH=$PREFIX/atos-4.0/bin:$PATH

Read the tutorial::

    $sh atos help

For instance, run a basic exploration with::

    $sh atos-explore -b ./build.sh -r ./run.sh

And get the performance first result with::

    $sh atos-play -T

Or get the size first result with::

    $sh atos-play -T -f size

Results
=======

* SH4 STLinux 2.4 gcc-4.7.3, STIH207 board

See results in ATOS portal:
  * lib jpeg: http://hostname:8001/projects/20/experiments/33
  * lib zlib: http://hostname:8001/projects/20/experiments/34

+----------------+------------------+--------------+--------------+
| Library        | trade-off        | speed-up     |size-reduction|
+================+==================+==============+==============+
| jpeg           | perf driven      |  +29.65%     |   -8.64%     |
+----------------+------------------+--------------+--------------+
|                | perf-size driven |  +20.92%     |   -1.19%     |
+----------------+------------------+--------------+--------------+
|                | size driven      |   +7.79%     |   +2.14%     |
+----------------+------------------+--------------+--------------+
| zlib           | perf driven      |  +11.31%     |   -9.36%     |
+----------------+------------------+--------------+--------------+
|                | perf-size driven |   +7.18%     |   +1.09%     |
+----------------+------------------+--------------+--------------+
|                | size driven      |   -0.82%     |  +12.80%     |
+----------------+------------------+--------------+--------------+

* ARM STLinux 2.4 gcc-4.7.3, ORLY2 b2020 board

See results in ATOS portal:
  * lib jpeg: http://hostname:8001/projects/20/experiments/35
  * lib zlib: http://hostname:8001/projects/20/experiments/36

+----------------+------------------+--------------+--------------+
| Library        | trade-off        | speed-up     |size-reduction|
+================+==================+==============+==============+
| jpeg           | perf driven      |  +28.00%     |  -10.29%     |
+----------------+------------------+--------------+--------------+
|                | perf-size driven |  +17.07%     |   -0.27%     |
+----------------+------------------+--------------+--------------+
|                | size driven      |   +4.35%     |   +1.70%     |
+----------------+------------------+--------------+--------------+
| zlib           | perf driven      |  +17.53%     |   -7.99%     |
+----------------+------------------+--------------+--------------+
|                | perf-size driven |  +10.64%     |   -1.10%     |
+----------------+------------------+--------------+--------------+
|                | size driven      |   -1.15%     |   +8.05%     |
+----------------+------------------+--------------+--------------+

Release Resources
=================

Refer to the Software Release Certificate for the full release links:
  http://hostname/wiki/index.php?pagename=SRCATOS400&group_id=2626

No blocking defects known. The list of remaining bugs and enhancements is
included in the release certificate.

ATOS 3.0
========

Restricted to ST internal use.

ATOS is an Auto Tuning Optimization System that is able to find automatically
the best performance/size tradeoff from a build system and a training
application.

The inputs of ATOS tools are a build command and a run command. From the build
command, ATOS will infer an internal build configuration that it will run with
different sets of compiler options. These build configurations are then
executed with the run command from which code size and performance will be
extracted.

From the set of build configurations that ATOS explores, one can extract the
preferred trade-off between code size and performance.

The extracted build configuration can be archived and replayed later in order
to generate the optimized executable without any modification into the initial
build system.

Access the tutorial with::

    $sh atos help tutorial

The tutorial is also available online at: https://hostname/wiki/?group_id=2626&pagename=ATOS_Tutorial

Refer to the ATOS Codex Project at: http://hostname/projects/atos

This release note is also available along each file release at: https://hostname/file/showfiles.php?group_id=2626

For other project resources and links, refer to the release certificate at: http://hostname/wiki/index.php?pagename=SRCATOS300&group_id=2626

Installation and Usage
======================

Download the binary package from: https://hostname/file/showfiles.php?group_id=2626

Install with::

    $sh cd $PREFIX
    $sh tar xvzf atos-3.0.tgz
    $sh export PATH=$PREFIX/atos-3.0/bin:$PATH

Read the tutorial::

    $sh atos help

For instance, run a basic exploration with::

    $sh atos-explore -b ./build.sh -r ./run.sh

And get the performance first result with::

    $sh atos-play -T

Or get the size first result with::

    $sh atos-play -T -f size

Release content
===============

New features:
 * Exploration of optimization sequences using genetic algorithm
   (explore-genetic).
 * Exploration on all optimization flags at a time (atos-explore-random).
 * Fine exploration of parameter values (atos-explore-flag-values).
 * Atos web commands enabling communication with ATOS portal (atos-web).
 * Basic support of stxp70cc compiler.

Improvements:
 * Refined ranges of explored parameter flag values.
 * Status line displaying exploration progress.
 * Improved atos-graph results visualization.
 * Various bug fixes.


Results
=======

Results are shown with two selected objective: perf driven or size driven.
A positive speed-up is a performance improvement and a positive size-reduction
is a code size improvement. Higher is better for both figures.

 * SH4 Libraries on STLinux 2.4

STLinux 2.4 libraries. The reference is the default STLinux2.4
build setting.  Compiled with gcc-4.7.2. Executed on STIH207 for
libs jpeg and zlib and HDK7108 for lib png.

See results in ATOS portal:

* lib jpeg: http://hostname:8001/projects/11/experiments/19
* lib zlib: http://hostname:8001/projects/8/experiments/23
* lib png: http://hostname:8001/projects/12/experiments/26

+----------------+-----------------+--------------+--------------+
| Library        | trade-off       | speed-up     |size-reduction|
+================+=================+==============+==============+
| lib jpeg       | perf driven     |  +30.53%     |  -13.50%     |
+----------------+-----------------+--------------+--------------+
|                | size driven     |   +5.83%     |   +1.71%     |
+----------------+-----------------+--------------+--------------+
| lib zlib       | perf driven     |   +8.37%     |  +14.90%     |
+----------------+-----------------+--------------+--------------+
|                | size driven     |   -2.58%     |  +25.98%     |
+----------------+-----------------+--------------+--------------+
| lib png        | perf driven     |  +17.93%     |   +8.85%     |
+----------------+-----------------+--------------+--------------+
|                | size driven     |  +10.89%     |  +10.90%     |
+----------------+-----------------+--------------+--------------+

 * HEVC Decode ARM/Orly

Run on Orly b2000 h416 board of HEVC NEON optimized version 2012130.
The reference is -O3.

See results in ATOS portal:

* HEVC Decode: http://hostname:8001/projects/2/experiments/5

+----------------+-----------------+--------------+--------------+
| Application    | trade-off       | speed-up     |size-reduction|
+================+=================+==============+==============+
| HEVC Decode    | perf driven     |  +9.22%      |  +21.21%     |
+----------------+-----------------+--------------+--------------+
|                | size driven     |  +3.12%      |  +32.71%     |
+----------------+-----------------+--------------+--------------+

 * CoreMark Benchmark on SH4/HDK7108

Compiled with OS21 gcc-4.7.3 and run on HDK7108 with OS21 runtime.

See Results in ATOS portal:

* CoreMark: http://hostname:8001/projects/15/experiments/24

+-------------------------------+-----------------+--------------+
| Benchmark                     | trade-off       | speed-up     |
+===============================+=================+==============+
| CoreMark 1.0                  | perf driven     | +18.53%      |
+-------------------------------+-----------------+--------------+

 * SPEC2000 Benchmark on ARM/Android

Run on board u9540 (android 4.1.1), build with gcc-4.6.x-google
small explorations of 125 configurations, reference is -Os

See results in ATOS portal:

* SPEC2000: http://hostname:8001/projects/9/experiments/16

+-------------------------------+-----------------+--------------+
| Benchmark                     | trade-off       | speed-up     |
+===============================+=================+==============+
| SPECint2000 164.gzip.train    | perf driven     | +24.8%       |
+-------------------------------+-----------------+--------------+
| SPECint2000 175.vpr.train     | perf driven     | +16.8%       |
+-------------------------------+-----------------+--------------+
| SPECint2000 176.gcc.train     | perf driven     | +25.4%       |
+-------------------------------+-----------------+--------------+
| SPECint2000 181.mcf.train     | perf driven     |  +5.0%       |
+-------------------------------+-----------------+--------------+
| SPECint2000 186.crafty.train  | perf driven     | +21.1%       |
+-------------------------------+-----------------+--------------+
| SPECint2000 197.parser.train  | perf driven     | +29.3%       |
+-------------------------------+-----------------+--------------+
| SPECint2000 252.eon.train     | perf driven     | +80.1%       |
+-------------------------------+-----------------+--------------+
| SPECint2000 253.perlbmk.train | perf driven     | +22.2%       |
+-------------------------------+-----------------+--------------+
| SPECint2000 254.gap.train     | perf driven     |  +8.6%       |
+-------------------------------+-----------------+--------------+
| SPECint2000 255.vortex.train  | perf driven     | +85.6%       |
+-------------------------------+-----------------+--------------+
| SPECint2000 256.bzip2.train   | perf driven     | +17.7%       |
+-------------------------------+-----------------+--------------+
| SPECint2000 300.twolf.train   | perf driven     | +28.3%       |
+-------------------------------+-----------------+--------------+

+-------------------------------+-----------------+--------------+
| Benchmark id                  | trade-off       | speed-up     |
+===============================+=================+==============+
| SPECfp2000 177.mesa.train     | perf driven     | +54.4%       |
+-------------------------------+-----------------+--------------+
| SPECfp2000 179.art.train      | perf driven     |  +9.2%       |
+-------------------------------+-----------------+--------------+
| SPECfp2000 183.equake.train   | perf driven     |  +6.4%       |
+-------------------------------+-----------------+--------------+
| SPECfp2000 188.ammp.train     | perf driven     | +82.1%       |
+-------------------------------+-----------------+--------------+

Release Resources
=================

Refer to the Software Release Certificate for the full release links:

    http://hostname/wiki/index.php?pagename=SRCATOS300&group_id=2626

No blocking defects known. The list of remaining bugs and enhancements is
included in the release certificate.

ATOS 2.0
========

Restricted to ST internal use.

ATOS is an Auto Tuning Optimization System that is able to find automatically
the best performance/size tradeoff from a build system and a training
application.

The input of ATOS tools are a build command and a run command. From the build
command, ATOS will infer an internal build configuration that it will run with
different sets of compiler options. These build configurations are executed
with the run command from which code size and performance will be extracted.

From the set of build configurations that ATOS explores, one can extract the
preferred trade-off between code size and performance.

The extracted build configuration can be archived and replayed later in order
to generate the optimized executable without any modification into the initial
build system.

Access the tutorial with::

    $sh atos help tutorial

Or through the online version: https://hostname/wiki/?group_id=2626&pagename=ATOS_Tutorial

Refer to the ATOS Codex Project at: http://hostname/projects/atos/
 
This release note is available at: http://hostname/file/shownotes.php?group_id=2626&release_id=21198

For other project resources and links, refer to the release certificate at: https://hostname/plugins/docman/?group_id=2626&action=show&id=272680

Installation and Usage
======================

Download binary package from: https://hostname/file/showfiles.php?group_id=2626

Install with::

    $sh cd $PREFIX
    $sh tar xvzf atos-2.0.tgz
    $sh export PATH=$PREFIX/atos-2.0/bin:$PATH

Read the tutorial::

    $sh atos help

For instance, run a basic exploration with::

    $sh atos-explore -b ./build.sh -r ./run.sh

And get the performance first result with::

    $sh atos-play -T

Or get the size first result with::

    $sh atos-play -T -f size

Release content
===============

New features:
 * File-by-file exploration of optimization sequences
 * Unified global and per function/file multilevel exploration
 * Support of perf tool in addition to oprofile for profile based explorations
 * Support of per function optimization flags in LTO mode and support for per
   function optimization parameters
 * Support for ARM RVCT compilers 4.1 and 5.0 in addition to ARM/SH4/x86 gcc 
   4.5/4.6/4.7 and ARM/x86 llvm 3.1
 * Interactive documentation with atos-help

Improvements:
  * Refactored tools into a single command atos and unified user command line
    interface
  * Rewrote core tools in python for improving extensibility and
    allowing tools obfuscation with static python compilers in case of
    externalization

Results
=======

Results are shown with two selected objective; perf driven (resp. size driven),
a positive speed-up is a performance improvement and a positive size-reduction
is a code size improvement. Higher is better for both figures.

 * sh4 STLinux gcc-4.7.1

+-------------------+-----------------+--------------+--------------+
| Benchmark id      | trade-off       | speed-up     |size-reduction|
+===================+=================+==============+==============+
| jpeg              | perf driven     |  +26.39%     |  -13.37%     |
+-------------------+-----------------+--------------+--------------+
|                   | size driven     |   +4.40%     |   +1.54%     |
+-------------------+-----------------+--------------+--------------+
| zlib              | perf driven     |   +12.54%    |   -1.41%     |
+-------------------+-----------------+--------------+--------------+
|                   | size driven     |   +0.75%     |  +12.39%     |
+-------------------+-----------------+--------------+--------------+

 * x86_64 QEMU gcc-4.7.2

+-------------------+-----------------+--------------+--------------+
| Benchmark id      | trade-off       | speed-up     |size-reduction|
+===================+=================+==============+==============+
| sha1              | perf driven     |  +30.39%     |  -15.52%     |
+-------------------+-----------------+--------------+--------------+
|                   | size driven     |   -4.42%     |  +11.05%     |
+-------------------+-----------------+--------------+--------------+
| bzip2             | perf driven     |   +1.73%     |  +18.65%     |
+-------------------+-----------------+--------------+--------------+
|                   | size driven     |   -1.55%     |  +21.05%     |
+-------------------+-----------------+--------------+--------------+

 * ARM/Android QEMU gcc-4.6.2

+-------------------+-----------------+--------------+--------------+
| Benchmark id      | trade-off       | speed-up     |size-reduction|
+===================+=================+==============+==============+
| SPEC 401.bzip2    | perf driven     |   +7.15%     |   +1.92%     |
+-------------------+-----------------+--------------+--------------+
|                   | size driven     |   +1.36%     |   +4.21%     |
+-------------------+-----------------+--------------+--------------+
| SPEC 429.mcf      | perf driven     |  +23.18%     |   -2.09%     |
+-------------------+-----------------+--------------+--------------+
|                   | size driven     |  +21.56%     |   +0.73%     |
+-------------------+-----------------+--------------+--------------+
| SPEC 470.lbm      | perf driven     |  +39.87%     |  +11.33%     |
+-------------------+-----------------+--------------+--------------+
|                   | size driven     |  +36.61%     |  +14.41%     |
+-------------------+-----------------+--------------+--------------+
| SPEC 164.gzip     | perf driven     |  +20.15%     |   -2.83%     |
+-------------------+-----------------+--------------+--------------+
|                   | size driven     |  +19.71%     |   -1.79%     |
+-------------------+-----------------+--------------+--------------+
| SPEC 181.mcf      | perf driven     |  +41.44%     |   -2.43%     |
+-------------------+-----------------+--------------+--------------+
|                   | size driven     |  +40.19%     |   -0.95%     |
+-------------------+-----------------+--------------+--------------+
| SPEC 255.vortex   | perf driven     |  +21.97%     |  +11.45%     |
+-------------------+-----------------+--------------+--------------+
|                   | size driven     |  +21.45%     |  +12.78%     |
+-------------------+-----------------+--------------+--------------+

Previous Results - ATOS-1.0
===========================

 * sh4 STLinux gcc-4.6.3, sdk7108

+-------------------+-----------------+--------------+--------------+
| Benchmark id      | trade-off       | speed-up     |size-reduction|
+===================+=================+==============+==============+
| jpeg              | perf driven     |  +19.9%      |   -8.5%      |
+-------------------+-----------------+--------------+--------------+
| zlib              | perf driven     |   +3.3%      |   -1.41%     |
+-------------------+-----------------+--------------+--------------+
| openssl           |  perf driven    |   +8.9% (*)  |   +6.7%      |
+-------------------+-----------------+--------------+--------------+

(*) max speed-up on the 26 crypto algos

 * sh4 STLinux gcc-4.6.3, QEMU

+-------------------+-----------------+--------------+--------------+
| Benchmark id      | trade-off       | speed-up     |size-reduction|
+===================+=================+==============+==============+
| directfb (*)      | perf driven     |  +11.7%      |  -16.4%      |
+-------------------+-----------------+--------------+--------------+

(*) no gain if HW accelerated

 * armv7 STLinux gcc-4.6.2, pandaboard

+-------------------+-----------------+--------------+--------------+
| Benchmark id      | trade-off       | speed-up     |size-reduction|
+===================+=================+==============+==============+
| jpeg              | perf driven     |  +19.2%      |   -4.2%      |
+-------------------+-----------------+--------------+--------------+
| zlib              | perf driven     |   +3.5%      |  -15.4%      |
+-------------------+-----------------+--------------+--------------+
| directfb          | perf driven     |   +5.5%      |   -2.2%      |
+-------------------+-----------------+--------------+--------------+
| openssl           | perf driven     |   +6.4% (**) |   +3.2%      |
+-------------------+-----------------+--------------+--------------+

 * ARM/Android gcc-4.6.2, u8500

+-------------------+-----------------+--------------+--------------+
| Benchmark id      | trade-off       | speed-up     |size-reduction|
+===================+=================+==============+==============+
| EEMBC automotive  | perf driven     |  +68.61%     |  -15.81%     |
+-------------------+-----------------+--------------+--------------+
| EEMBC consumer    | perf driven     |   +8.46%     |   -0.81%     |
+-------------------+-----------------+--------------+--------------+
| EEMBC networking  | perf driven     |  +58.39%     |   +4.09%     |
+-------------------+-----------------+--------------+--------------+
| EEMBC office      | perf driven     |   +8.81%     |   -0.35%     |
+-------------------+-----------------+--------------+--------------+
| EEMBC telecom     | perf driven     |  +40.68%     |   -1.13%     |
+-------------------+-----------------+--------------+--------------+

Release Resources
=================

Refer to the Software Release Certificate for the full release links: https://hostname/plugins/docman/?group_id=2626&action=show&id=272680

No blocking defects known. List of remaining bugs and enhancements is included
in release certificate.

ATOS 1.0
========

The release 1.0 of Auto-Tuning Optimization System (ATOS) tools is now
available for ST internal use: http://hostname/projects/atos

Both binaries and sources are provided along with this release:

* https://hostname/file/showfiles.php?group_id=2626
* git://hostname:atos/atos-build.git

ATOS provides tools for automatic tuning of applications, allowing
transparent search and replay of best performance/size trade-offs.

Release content
===============

  * Audit of unmodified build and run systems
  * Automatic tuning of GCC and LLVM compilers based build systems
    * Support of GCC 4.4, 4.5, 4.6, 4.7 and LLVM 3.0 compilers
    * Validated on ST40, ARM, x86_64 and i386
  * Exploration of optimization sequences
    * Run of advanced optimizations
    * Support of inlining, unrolling and other optimization options
    * Global and per function multilevel exploration using GCC plugins
  * Delivery of bests performance/size trade-offs

The next release, scheduled for the end of September, should include
support tools for parallelization and enhanced file/function level
exploration.

Documentation
=============

A tutorial is available here: https://hostname/wiki/?group_id=2626&pagename=ATOS_Tutorial

Steps for building ATOS tools from sources are described here: http://hostname/wiki/?group_id=2626&pagename=HowToBuildATOS

Support
=======

For any question, comment, suggestion or bug report, feel free to contact
the OKLA developers at okla-team@lists.hostname or to use the
tracker on the Codex project page: http://hostname/projects/atos
