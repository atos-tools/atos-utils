=================
ATOS Introduction
=================

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

Refer to the tutorial for a detailed example of usage:

::

  $ atos help tutorial


