#!/usr/bin/env python
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
# Graph exploration results for comparison
#
# atos tools must be available in $PATH
#
# Usage: cmp_expl.py atos-cfg-11,atos-cfg-12:expl1_name[:color] \
#                    atos-cfg-21,atos-cfg-22:expl2_name[:color] ...
#

import sys, os, commands
import itertools
import pylab as pl

atos_graph_bin = commands.getoutput("which atos-graph")
assert atos_graph_bin, "ATOS tools not found in $$PATH"

bin_dir = os.path.dirname(atos_graph_bin)
lib_dir = os.path.abspath(os.path.join(
      bin_dir, '..', 'lib', 'atos', 'python'))
sys.path.append(lib_dir)

from atoslib import atos_lib

def draw_search_graph(plots):
    fg = pl.figure()
    ax = fg.add_subplot(111)

    for (values, attrs) in plots:
        indexes, width = pl.arange(len(values)), 1.0 / len(plots)

        yvalues = [x.result for x in values]
        xoffset = width * plots.index((values, attrs))
        ax.plot(indexes + xoffset, yvalues, **attrs)

        ax.legend(loc='lower left')
        fg.canvas.draw()

    pl.ylabel('tradeoff result -->')
    pl.xlabel('number of tested configurations -->')
    pl.title('Search Graph')
    pl.axhspan(0.0, 0.0)
    pl.axvspan(0.0, 0.0)
    pl.grid(True)
    pl.show()

def searchgraph(opts, configs):

    colors = ['red', 'blue', 'green', 'magenta', 'yellow']

    # load results from all databases
    db_groups = []
    for (n, config) in enumerate(configs):
        cfg_split = config.split(':')
        dbpathes = cfg_split.pop(0).split(',')
        label = (
            cfg_split and cfg_split.pop(0) or "db-" + str(n))
        color = (
            cfg_split and cfg_split.pop(0) or colors[n % len(colors)])
        optcasesl = map(lambda x: atos_lib.get_results(
                x, atos_lib.default_obj(refid='REF')), dbpathes)
        for optcases in optcasesl:
            for optcase in optcases:
                optcase.result = (
                    (optcase.speedup * opts.tradeoff + optcase.sizered)
                    if opts.tradeoff is not None else optcase.speedup)
        db_groups.append((optcasesl, label, color))
        print label, map(len, optcasesl)

    plots = []
    for (optcasesl, label, color) in db_groups:

        max_optcasesl = []
        for optcases in optcasesl:
            max_optcases = []
            max_opt = len(optcases) and optcases[0] or None
            for optcase in optcases:
                if optcase.result > max_opt.result:
                    max_opt = optcase
                max_optcases += [max_opt]
            max_optcasesl.append(max_optcases)

        # average best result
        attrs = {
            'linewidth': 2,
            'color': color, 'label': label + '-avg-max'}
        avgmax_optcases = []
        max_optcasesl2 = itertools.izip_longest(*max_optcasesl)
        for mx in max_optcasesl2:
            if None in mx: break
            vals = map(lambda x: x.result, list(mx))
            avg = sum(vals) / len(vals)
            optavg = atos_lib.default_obj(result=avg)
            avgmax_optcases.append(optavg)
        plots += [(avgmax_optcases, dict(attrs))]
        attrs['label'] = None

    return plots


if __name__ == "__main__":

   import optparse
   parser = optparse.OptionParser(
      description='Graph for exploration algorithm comparison')
   parser.add_option(
       "--tradeoff", dest="tradeoff", type=float, default=None)

   (opts, args) = parser.parse_args()

   plots = searchgraph(opts, args)

   draw_search_graph(plots)
