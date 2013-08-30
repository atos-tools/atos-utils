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
import itertools, functools, operator

atos_graph_bin = commands.getoutput("which atos-graph")
assert atos_graph_bin, "ATOS tools not found in $$PATH"

bin_dir = os.path.dirname(atos_graph_bin)
lib_dir = os.path.abspath(os.path.join(
      bin_dir, '..', 'lib', 'atos', 'python'))
sys.path.append(lib_dir)

from atoslib import atos_lib

def draw_search_graph(plots):
    import pylab as pl

    fg = pl.figure()
    ax = fg.add_subplot(111)

    for (values, attrs) in plots:
        indexes, width = pl.arange(len(values)), 1.0 / len(plots)

        yvalues = [x.result for x in values]
        xoffset = width * plots.index((values, attrs))
        ax.plot(indexes + xoffset, yvalues, **attrs)

        legend = ax.legend(loc='best')
        legend.get_frame().set_alpha(0.2)

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
        # load results from all atos_config directories
        results = map(lambda x: atos_lib.get_results(
            x, atos_lib.default_obj(refid='REF')), dbpathes)
        # compute result field (perf/size tradeoff) for each result
        def set_result(optcase): optcase.result = (
            (optcase.speedup * opts.tradeoff + optcase.sizered)
            if opts.tradeoff is not None else optcase.speedup)
        filter(functools.partial(filter, set_result), results)
        if opts.nbiters: results = map(lambda r: r[:opts.nbiters], results)
        db_groups.append((results, label, color))
        # print label, map(len, results)

    plots = []
    for (results, label, color) in db_groups:

        # compute best point at each iteration of all exploration
        all_bests = []
        for optcases in results:
            max_optcases = []
            max_opt = len(optcases) and optcases[0] or None
            for optcase in optcases:
                if optcase.result > max_opt.result:
                    max_opt = optcase
                max_optcases += [max_opt]
            all_bests.append(max_optcases)

        # compute average of best points at each iteration
        best_avg = []
        # list of list of best at each iteration
        all_bests_it = itertools.izip_longest(*all_bests)
        for mx in all_bests_it:
            if None in mx: break # one of the explorations is over
            values = map(lambda x: x.result, list(mx))
            average = sum(values) / len(values)
            optavg = atos_lib.default_obj(result=average)
            best_avg.append(optavg)

        # graph plots
        attrs = {
            'linewidth': 2,
            'color': color, 'label': label + '-avg-max'}
        plots += [(best_avg, dict(attrs))]
        attrs['label'] = None

        # output: nb_iterations, last_result, and average
        best_avg_res = map(operator.attrgetter('result'), best_avg)
        best_avg_avg = sum(best_avg_res) / len(best_avg_res)

        stdev_last_bests = atos_lib.standard_deviation(
            map(lambda results: results[-1].result, all_bests))
        stdev_avg_bests = atos_lib.standard_deviation(
            best_avg_res)

        print "%-10s last=%.4f (stdv=%.4f) avg=%.4f (stdv=%.4f) nbiter=%d" % (
            label, best_avg_res[-1], stdev_last_bests,
            best_avg_avg, stdev_avg_bests, len(best_avg_res))

    return plots


if __name__ == "__main__":

   import optparse
   parser = optparse.OptionParser(
      description='Graph for exploration algorithm comparison')
   parser.add_option(
       "--tradeoff", dest="tradeoff", type=float, default=None)
   parser.add_option(
       "--nograph", dest="graph", action='store_false', default=True)
   parser.add_option(
       "--nbiters", dest="nbiters", type=int, default=None)

   (opts, args) = parser.parse_args()

   plots = searchgraph(opts, args)

   if opts.graph: draw_search_graph(plots)
