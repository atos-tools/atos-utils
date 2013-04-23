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
# Usage: get usage with atos-graph -h
#

import sys
import re, math, threading, atexit, signal

import atos_lib

try:
    import pylab as pl
except:
    print "pylab matplotlib module is not installed"
    sys.exit(1)


# ####################################################################


class repeattimer():

    allth = []

    def __init__(self, func, pause=1.0):
        self.func = func
        self.pause = pause
        self.ev = threading.Event()
        self.th = threading.Thread(target=self.update)
        self.th.daemon = True
        repeattimer.allth += [self]

    def update(self):
        while True:
            self.ev.wait(self.pause)
            if self.ev.isSet(): break
            self.func()

    def start(self):
        self.th.start()
        return self

    def stop(self):
        self.ev.set()

    @staticmethod
    @atexit.register
    def stopall():
        for th in repeattimer.allth: th.stop()


# ####################################################################

def nowarn(func):
    def wrapper(*args, **kwargs):
        import warnings
        with warnings.catch_warnings():
            warnings.simplefilter("ignore")
            res = func(*args, **kwargs)
        return res
    return wrapper

@nowarn
def draw_graph(getgraph, opts):
    # http://matplotlib.sourceforge.net/index.html
    fg = pl.figure()
    ax = fg.add_subplot(111)

    global graph_plots, all_points
    graph_plots, all_points = [], []

    def draw_tradeoff_plots(ratio, points, attrs):
        # select tradeoff given ratio
        best = atos_lib.atos_client_results.select_tradeoff(points, ratio)
        # graph limits
        xmin = min([p.sizered for p in points])
        xmax = max([p.sizered for p in points])
        ymin = min([p.speedup for p in points])
        ymax = max([p.speedup for p in points])
        # number of points on ratio line
        nbtk = int((ratio >= 1 and 2 or 1 / ratio) * 32)
        # ratio line points coordinates
        xtk = [xmin + i * ((xmax - xmin) / nbtk) for i in range(nbtk + 1)]
        ytk = [best.speedup + (1.0 / ratio) * (best.sizered - x) for x in xtk]
        coords = filter(lambda (x, y): y >= ymin and y <= ymax, zip(xtk, ytk))
        # first plot: selected tradeoff point
        attrs.update({'label': '_nolegend_'})
        attrs.update({'markersize': 20, 'linewidth': 0, 'alpha': 0.4})
        plots = [(([best.sizered], [best.speedup]), dict(attrs))]
        # second plot: ratio line
        attrs.update({'marker': '', 'linewidth': 2, 'linestyle': 'solid'})
        plots += [((zip(*coords)[0], zip(*coords)[1]), dict(attrs))]
        return plots

    def draw_all():
        global graph_plots, all_points, selected_points, similar_points  # :(

        # remove old plots
        old_points = [(p.sizered, p.speedup, p.variant) for p in all_points]
        for x in list(graph_plots):
            graph_plots.remove(x)
            x.remove()

        # get graph values
        scatters, frontiers = getgraph()
        all_points = sum([x[0] for x in scatters + frontiers], [])

        # draw scatters
        for (points, attrs) in scatters:
            attrsmap = {
                's': 20, 'label': '_nolegend_', 'zorder': 2,
                'color': 'r', 'edgecolor': 'k'}
            attrsmap.update(attrs)
            xy = zip(*[(p.sizered, p.speedup) for p in points])
            gr = ax.scatter(*xy, **attrsmap)
            graph_plots.append(gr)

        # draw frontiers (line plots)
        for (points, attrs) in frontiers:
            attrsmap = {
                'color': 'r', 'marker': 'o', 'label': '_nolegend_',
                'zorder': 2, 'markersize': 7,
                'linestyle': 'dashed', 'linewidth': 2}
            attrsmap.update(attrs)
            xy = zip(*sorted([(p.sizered, p.speedup) for p in points]))
            gr, = ax.plot(xy[0], xy[1], **attrsmap)
            graph_plots.append(gr)
            # show tradeoffs for each frontier
            for ratio in opts.tradeoffs or []:
                for ((xcrd, ycrd), attrs) in \
                        draw_tradeoff_plots(ratio, points, dict(attrsmap)):
                    graph_plots.append(ax.plot(xcrd, ycrd, **attrs)[0])

        # draw selected points (hidden)
        if opts.show and all_points:
            # workaround pb with pick_event event ind (4000)
            attrsmap = {
                'color': 'b', 'marker': 'o', 'markersize': 20, 'linewidth': 0,
                'alpha': 0.4}
            xy = zip(*sorted([(p.sizered, p.speedup) for p in all_points]))
            selected_points, = \
                ax.plot(xy[0], xy[1], visible=False, picker=4000, **attrsmap)
            graph_plots.append(selected_points)
            # similar point plot
            attrsmap.update({'color': 'g'})
            similar_points, = ax.plot(None, None, visible=False, **attrsmap)
            graph_plots.append(similar_points)

        # highlight new points
        if opts.follow and old_points:
            new_points = [p for p in all_points if (
                    (p.sizered, p.speedup, p.variant) not in old_points)]
            attrsmap = {
                'color': 'r', 'marker': 'o', 'markersize': 20, 'linewidth': 0,
                'alpha': 0.4, 'zorder': 1}
            if new_points:
                xy = zip(*[(p.sizered, p.speedup) for p in new_points])
                new_points, = ax.plot(*xy, **attrsmap)
                graph_plots.append(new_points)

        # redraw legend and figure
        ax.legend(loc='lower left')
        fg.canvas.draw()

    # dynamic annotations
    def on_pick(event):
        def closest(x, y):
            dp = [(math.hypot(p.sizered - x, p.speedup - y), p)
                  for p in all_points]
            return sorted(dp)[0][1]

        def highlight(p):
            # print point on console
            print '-' * 40 + '\n' + point_str(p)
            # highlight point
            selected_points.set_visible(True)
            selected_points.set_data(p.sizered, p.speedup)
            # highlight similar points (same variant)
            sim = zip(*([(c.sizered, c.speedup) for c in all_points
                         if c.variant == p.variant and c != p]))
            similar_points.set_visible(True)
            similar_points.set_data(sim and sim[0], sim and sim[1])
            # selected point legend
            main_legend = ax.legend_
            lg = point_str(p, short=True, no_id=opts.anonymous)
            lp = pl.legend(
                [selected_points], [lg], loc='lower right', numpoints=1)
            pl.setp(lp.get_texts(), fontsize='medium')
            lp.get_frame().set_alpha(0.5)
            pl.gca().add_artist(main_legend)
            fg.canvas.draw()
            ax.legend_ = main_legend
        highlight(closest(event.mouseevent.xdata, event.mouseevent.ydata))

    # live plotting
    def on_timer():
        draw_all()

    # draw graph for the first time
    draw_all()

    # graph title
    title = 'Optimization Space for %s' % (
        opts.id or opts.targets or (
            all_points and all_points[0].target))
    if opts.refid: title += ' [ref=%s]' % opts.refid
    if opts.filter: title += ' [filter=%s]' % opts.filter

    # redraw axis, set labels, legend, grid, ...
    def labelfmt(x, pos=0): return '%.2f%%' % (100.0 * x)
    ax.xaxis.set_major_formatter(pl.FuncFormatter(labelfmt))
    ax.yaxis.set_major_formatter(pl.FuncFormatter(labelfmt))
    pl.axhspan(0.0, 0.0)
    pl.axvspan(0.0, 0.0)
    pl.title(title)
    pl.xlabel('size reduction (higher is better) -->')
    pl.ylabel('speedup (higher is better) -->')
    if opts.xlim: pl.xlim([float(l) for l in opts.xlim.split(",")])
    if opts.ylim: pl.ylim([float(l) for l in opts.ylim.split(",")])
    pl.grid(True)

    if opts.outfile:
        fg.savefig(opts.outfile)

    if opts.show:
        fg.canvas.mpl_connect('pick_event', on_pick)
        if opts.follow: timer = atos_lib.repeatalarm(on_timer, 5.0).start()
        pl.show()
        if opts.follow: timer.stop()

@nowarn
def draw_correl_graph(getgraph, opts):
    # http://matplotlib.sourceforge.net/index.html
    fg = pl.figure()
    ax = fg.add_subplot(111)

    bars = getgraph()

    for (values, attrs) in bars:
        indexes, width = pl.arange(len(values)), 1.0 / len(bars)

        yvalues = [x.speedup for x in values]
        xoffset = width * bars.index((values, attrs))
        ax.bar(indexes + xoffset, yvalues, width, picker=4000, **attrs)

        ax.legend(loc='lower left')
        fg.canvas.draw()

    # dynamic annotations
    def on_pick(event):
        ind = int(event.mouseevent.xdata)
        point = bars[0][0][ind]
        tooltip.set_position(
            (event.mouseevent.xdata, event.mouseevent.ydata))
        tooltip.set_text(point_descr(point))
        tooltip.set_visible(True)
        fg.canvas.draw()

    tooltip = ax.text(
        0, 0, "undef", bbox=dict(facecolor='white', alpha=0.8),
        verticalalignment='bottom', visible=False)

    # graph title
    try:
        title = 'Correlation Graph for %s' % (
            opts.id or opts.targets or bars[0][0][0].target)
    except: title = 'Correlation Graph'

    # redraw axis, set labels, legend, grid, ...
    def labelfmt(x, pos=0): return '%.2f%%' % (100.0 * x)
    ax.yaxis.set_major_formatter(pl.FuncFormatter(labelfmt))
    pl.ylabel('speedup (higher is better) -->')

    pl.xlabel('Configurations (ordered by decreasing speedup of '
              + bars[0][1]['label'] + ') -->')
    pl.title(title)
    pl.axhspan(0.0, 0.0)
    pl.axvspan(0.0, 0.0)
    pl.grid(True)

    if opts.outfile:
        fg.savefig(opts.outfile)

    if opts.show:
        fg.canvas.mpl_connect('pick_event', on_pick)
        pl.show()


# ####################################################################


def point_descr(point):
    res = point.target + ' '
    res += (len(point.variant) >= 45
            and point.variant[:25] + '...' + point.variant[-15:]
            or point.variant)
    return res


def point_str(point, short=False, no_id=False):
    res = ''
    if not no_id:
        if short and len(point.variant) >= 45:
            legend_id = point.variant[:25] + '...' + point.variant[-15:]
        else: legend_id = point.variant
        res = legend_id + '\n'
    res += 'speedup=%.2f%% runtime=%.2f\n' % (
        point.speedup * 100, point.time)
    res += 'reduction=%.2f%% binsize=%d' % (
        point.sizered * 100, point.size)
    if not no_id:
        res += '\nid=%s' % (atos_lib.hashid(point.variant))
    return res


def getoptcases(dbpath, opts):
    variant_results = atos_lib.get_results(dbpath, opts)
    atos_lib.atos_client_results.set_frontier_field(variant_results)
    frontier = filter(lambda x: x.on_frontier, variant_results)
    print '%d points, %d on frontier' % (len(variant_results), len(frontier))
    return variant_results

def optgraph(opts):

    optcases = getoptcases(
        opts.dbfile and opts.dbfile[0] or opts.configuration_path, opts)

    scatters, frontiers = [], []

    # scatters definition
    scatters_def = []
    if opts.highlight:
        scatters_def += [
            (opts.highlight, {
                    's': 40, 'color': 'y', 'label': 'ref cases', 'zorder': 4})
            ]
    if opts.xd == 0:
        scatters_def += [
            ('.*', {'label': 'opt cases', 'color': 'b'})
            ]
    elif opts.xd == 1:
        scatters_def += [
            ('OPT(-fprofile-use)?-Os.*$',
             {'label': '[-Os]', 'color': 'green'}),
            ('OPT(-fprofile-use)?-O1.*$',
             {'label': '[-O1]', 'color': 'cyan'}),
            ('OPT(-fprofile-use)?-O2.*$',
             {'label': '[-O2]', 'color': 'blue'}),
            ('OPT(-fprofile-use)?-O3.*$',
             {'label': '[-O3]', 'color': 'red'}),
            ('.*',
             {'label': '_nolegend_', 'color': 'white'})
            ]
    elif opts.xd == 2:
        scatters_def += [
            ('OPT-fprofile-use.*-flto$',
             {'label': '[fdo+lto]', 'color': 'red'}),
            ('OPT-fprofile-use.*$',
             {'label': '[fdo]', 'color': 'blue'}),
            ('.*-flto$',
             {'label': '[lto]', 'color': 'green'}),
            ('.*',
             {'label': '_nolegend_', 'color': 'white'})
            ]
    elif opts.xd == 3:
        scatters_def += [
            ('OPT-fprofile-use-O3.*-flto$',
             {'label': '[O3 fdo+lto]', 'color': 'red'}),
            ('OPT-fprofile-use-O2.*-flto$',
             {'label': '[O2 fdo+lto]', 'color': 'green'}),
            ('OPT-fprofile-use-O3.*$',
             {'label': '[O3 fdo]', 'color': 'blue'}),
            ('OPT-fprofile-use-O2.*$',
             {'label': '[O2 fdo]', 'color': 'cyan'}),
            ('.*',
             {'label': '_nolegend_', 'color': 'white'})
            ]

    # scatters list
    if not opts.frontier_only:
        # partionning of points into scatters
        partitions, attrs_values = {}, dict(scatters_def)
        for c in optcases:
            for (opt, val) in scatters_def:
                if not re.match(opt, c.variant): continue
                partitions.setdefault(opt, []).append(c)
                break
        partkeys = [x[0] for x in scatters_def if x[0] in partitions.keys()]
        for opt in partkeys:
            scatters += [(partitions[opt], attrs_values[opt])]

    # frontiers list
    attrs = {'label': 'frontier'}
    if opts.xd != 0:
        attrs = {'marker': 'x', 'zorder': 1, 'mew': 2,
                 'markersize': 9, 'label': '_nolegend_'}
    if optcases:
        frontiers += [([c for c in optcases if c.on_frontier], attrs)]

    return scatters, frontiers


def multgraph(opts):

    dbpathes = [opts.configuration_path] + opts.configuration_pathes
    nbdb = len(dbpathes)
    optcasesl = [getoptcases(f, opts) for f in dbpathes]

    scatters, frontiers = [], []

    # dbfiles labels and colors
    labels = opts.labels and opts.labels.split(',') or []
    for i in range(nbdb - len(labels)): labels.append(str(i))
    colors = ['red', 'blue', 'green', 'magenta']

    # scatters list
    if not opts.frontier_only:
        for i in range(nbdb):
            attrs = {'color': colors[i % len(colors)], 'label': labels[i]}
            scatters += [(optcasesl[i], attrs)]

    # frontiers
    attrs = {'marker': 'x', 'zorder': 1, 'mew': 2}
    for i in range(nbdb):
        attrs.update({'color': colors[i % len(colors)]})
        if opts.frontier_only: attrs.update({'label': 'frontier-' + labels[i]})
        frontiers += [
            ([c for c in optcasesl[i] if c.on_frontier], dict(attrs))]

    return scatters, frontiers


def correlgraph(opts):

    dbpathes = [opts.configuration_path] + opts.configuration_pathes

    # load results from all databases
    optcasesl = []
    targets = opts.targets and opts.targets.split('+') or None
    for dbpath in dbpathes:
        client = atos_lib.atos_client_results(
            atos_lib.atos_db.db(dbpath, no_cache=True),
            targets and targets.split(',') or None,
            atos_lib.strtoquery(opts.query), opts.id)
        client.compute_speedups(opts.refid)
        optcasesl.append({client.values[2]: client.results})

    # dbfiles labels and colors
    nbdb = len(dbpathes)
    labels = opts.labels and opts.labels.split(',') or []
    for i in range(nbdb - len(labels)): labels.append(str(i))
    colors = ['red', 'blue', 'green', 'magenta']

    # targets common to all dbs
    common_targets = (
        list(reduce(lambda acc, s: acc.intersection(s),
                    map(lambda d: set(d.keys()), optcasesl))))

    # couples of (target, variant) common to all dbs, REF removed
    common_target_variant = list(
        reduce(lambda acc, s: acc.intersection(s),
               map(lambda c: set([(t, v) for t in common_targets
                                  for v in c[t].keys() if v != opts.refid]),
                   optcasesl)))

    # couples of common (target, variant), sorted by speedups
    sorted_common_target_variant = list(reversed(
            sorted(common_target_variant,
                   key=lambda (t, v): optcasesl[0][t][v].speedup)))

    #
    bars = []
    for i in range(nbdb):
        attrs = {'color': colors[i % len(colors)], 'label': labels[i]}
        optcs = map(
            lambda (t, v): optcasesl[i][t][v], sorted_common_target_variant)
        bars += [(optcs, attrs)]

    return bars
