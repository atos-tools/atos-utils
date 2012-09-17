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
# Usage: get usage with atos-lib -h
#

import sys, os, re, math, itertools, time, fcntl, json, hashlib
import cPickle as pickle

import globals
import jsonlib
import process

# ####################################################################


class atos_db():

    keys = ['target', 'environment', 'compiler', 'dataset', 'session']

    required_keys = ['target', 'environment', 'compiler', 'session']

    required_fields = ['target', 'variant', 'size', 'time']

    def __init__(self): raise NotImplementedError

    # add new result records
    #   ex: add_results([
    #           {'target': 'x', 'variant': 'REF', 'time': 14.0, 'size': 10}])
    def add_results(self, entries): raise NotImplementedError

    # return list of records
    #   [{'target': 'x', 'variant': 'REF', 'time': ...}, {...}, ...]
    #   query can be a dict or a jsonlib search string
    #   ex: get({}): all records
    #   ex: get({'target': 'x', 'variant': 'REF'})
    #   ex: get('$[?(@.target="x" && @.variant="REF")]'
    def get_results(self, query=None): raise NotImplementedError

    #
    @staticmethod
    def db(atos_configuration):
        # results.pkl  loadtime:  3.50s  filesize: 229M
        db_file = os.path.join(atos_configuration, 'results.pkl')
        if os.path.exists(db_file): return atos_db_pickle(db_file)
        # results.json loadtime: 27.63s  filesize: 217M
        db_file = os.path.join(atos_configuration, 'results.json')
        if os.path.exists(db_file): return atos_db_json(db_file)
        # results.db   loadtime:  5.70s  filesize: 579M
        db_file = os.path.join(atos_configuration, 'results.db')
        return atos_db_file(db_file)


# ####################################################################


class atos_db_file(atos_db):

    def __init__(self, db_file):
        self.db_file = db_file
        self.results = []
        self._create()
        self._read_results()

    def get_results(self, query=None):
        return results_filter(self.results, query)

    def add_results(self, entries):
        self.results.extend(entries)
        self._write_entries(entries)

    def _write_entries(self, entries):
        entries_str = ''.join(
            atos_db_file.entry_str(entry) for entry in entries)
        with open_locked(self.db_file, 'a') as db_file:
            db_file.write(entries_str)

    def _read_results(self):
        if not os.path.exists(self.db_file): return
        curdict, size, time = {}, None, None
        for line in open_locked(self.db_file):
            words = line.split(':', 4)
            if len(words) < 4: continue
            # ATOS: target: variant_id: key: value
            target, variant, key, value = [
                w.strip() for w in words[1:]]
            curdict[key] = value
            if key == 'size': size = value
            if key == 'time': time = value
            if not (size and time): continue
            curdict['target'] = target
            curdict['variant'] = variant
            self.results += [result_entry(curdict)]
            curdict, size, time = {}, None, None

    def _create(self):
        if os.path.exists(self.db_file): return
        open(self.db_file, 'w').write('')

    @staticmethod
    def entry_str(entry):
        entry_str = ''
        entry_keys = list(entry.keys())
        # no need for target and variant lines
        entry_keys.remove('target')
        entry_keys.remove('variant')
        # last line must be one of the required field (time or size)
        entry_keys.remove('time')
        entry_keys += ['time']
        for key in entry_keys:
            entry_str += 'ATOS: %s: %s: %s: %s\n' % (
                entry['target'], entry['variant'], key, entry[key])
        return entry_str


# ####################################################################


class atos_db_json(atos_db):

    def __init__(self, db_file):
        self.db_file = db_file
        self.results = []
        self._create()
        self._read_results()

    def get_results(self, query=None):
        return results_filter(self.results, query)

    def add_results(self, entries):
        with open_locked(self.db_file, 'r+') as db_file:
            self.results = json.load(db_file)
            db_file.seek(0)
            db_file.truncate()
            self.results.extend(entries)
            json.dump(self.results, db_file, sort_keys=True, indent=4)

    def _read_results(self):
        self.results = json.load(open_locked(self.db_file))

    def _create(self):
        if os.path.exists(self.db_file): return
        json.dump([], open(self.db_file, 'w'))


# ####################################################################


class atos_db_pickle(atos_db):

    def __init__(self, db_file):
        self.db_file = db_file
        self.results = []
        self._create()
        self._read_results()

    def get_results(self, query=None):
        return results_filter(self.results, query)

    def add_results(self, entries):
        with open_locked(self.db_file, 'r+') as db_file:
            self.results = pickle.load(db_file)
            db_file.seek(0)
            db_file.truncate()
            self.results.extend(entries)
            pickle.dump(self.results, db_file, -1)

    def _read_results(self):
        self.results = pickle.load(open_locked(self.db_file))

    def _create(self):
        if os.path.exists(self.db_file): return
        pickle.dump([], open(self.db_file, 'w'), -1)


# ####################################################################


class atos_client_results():

    class result():

        def __init__(self, result):
            for (key, val) in result.items():
                exec 'self.%s = type(%s)("%s")' % (key, 'val', val)

        def __repr__(self):
            return '<%s:%s>' % (self.target, self.variant)

        def __str__(self):
            return str(self.dict())

        def dict(self):
            return dict(
                filter(lambda x: x[0][0] != '_', self.__dict__.items()))

        def compute_speedup(self, ref):
            self.speedup = ((ref.time / self.time) - 1.0)
            self.sizered = (1.0 - (float(self.size) / float(ref.size)))
            return self.speedup, self.sizered

        @staticmethod
        def merge_multiple_runs(results):
            newobj = atos_client_results.result(results[0].__dict__)
            # average of execution times
            newobj.time = average(map(lambda x: x.time, results))
            newobj._results = results
            return newobj

        @staticmethod
        def merge_targets(group_name, results):
            newobj = atos_client_results.result(results[0].__dict__)
            # geometric mean of execution times, sum of binary sizes
            newobj.time = geometric_mean(map(lambda x: x.time, results))
            newobj.size = sum(map(lambda x: x.size, results))
            newobj.target = group_name
            # last group results - last result of each target
            newobj._last = atos_client_results.result(newobj.__dict__)
            newobj._last.time = geometric_mean(
                map(lambda x: x._results[-1].time, results))
            newobj._results = results
            return newobj

    def __init__(self, atos_db, group_targets, query=None, group_name=None):
        query = query or {}
        self.db = atos_db
        if not group_targets:
            group_targets = list(set(self.db.get_results('$[*].target') or []))
        group_name = group_name or '+'.join(group_targets)
        self.values = (group_targets, query, group_name)
        # results: {variant: [result_obj]}
        self.results = self._get_group_results(
            group_targets, group_name, query)

    def compute_frontier(self):
        if not self.results: return []
        maybe_on_frontier, mustbe_on_frontier = self.results.values(), set()
        for (variant, c1) in self.results.items():
            on_frontier = True
            maybe_on_frontier.remove(c1)
            for c2 in itertools.chain(mustbe_on_frontier, maybe_on_frontier):
                if c2.time == c1.time and c2.size == c1.size:
                    pass
                elif c2.time <= c1.time and c2.size <= c1.size:
                    on_frontier = False
                    break
            if on_frontier: mustbe_on_frontier.add(c1)
            c1.on_frontier = on_frontier
        self.frontier = sorted(
            mustbe_on_frontier, key=lambda x: x.size)
        return self.frontier

    def compute_speedups(self, ref_variant='REF'):
        if not self.results: return []
        assert ref_variant in self.results.keys()
        for (variant, result) in self.results.items():
            result.compute_speedup(self.results[ref_variant])
        return self.results.values()

    def get_last_result(self, variant):
        if variant not in self.results.keys():
            return None
        return self.results[variant]._last

    def get_results(self, only_frontier=False, objects=False):
        if only_frontier:
            if not hasattr(self, 'frontier'):
                self.compute_frontier()
            results = self.frontier
        else: results = self.results.values()
        if not objects:
            results = map(lambda x: x.dict(), results)
        return results

    def tradeoff(self, perf_size_ratio=4):
        return atos_client_results.select_tradeoff(
            getattr(self, 'frontier', None) or self.compute_frontier(),
            perf_size_ratio)

    @staticmethod
    def select_tradeoff(frontier, perf_size_ratio=4):
        res_point = atos_client_results.select_tradeoffs(
            frontier, perf_size_ratio, 1)
        return res_point and res_point[0] or None

    @staticmethod
    def select_tradeoffs(frontier, perf_size_ratio=4, nb_points=3):
        if not frontier: return None
        # copy frontier points
        frontier_orig = sorted(
            frontier, key=lambda x: x.size)
        frontier_copy = map(
            lambda x: atos_client_results.result(x.dict()), frontier_orig)
        # fake reference
        ref = atos_client_results.result(
            {'time': frontier_copy[0].time, 'size': frontier_copy[-1].size})
        # compute speedups/sizereds
        map(lambda x: x.compute_speedup(ref), frontier_copy)
        # find best tradeoff (ratio * sizered + speedup)
        tradeoffs = sorted(map(lambda x: (
                    (perf_size_ratio * x.speedup) + x.sizered, x),
                               frontier_copy))
        tradeoffs = map(lambda x: x[1], tradeoffs[-nb_points:])
        # return corresponding points
        tradeoffs_points = map(
            lambda x: frontier_orig[frontier_copy.index(x)], tradeoffs)
        return tradeoffs_points

    def _get_group_results(self, group_targets, group_name, query):
        if not group_targets: return {}
        # get results for each target of the group
        results, target_results = {}, {}
        for target in group_targets:
            target_results[target] = self._get_target_results(target, query)
        # find list of variants common to all targets
        common_variants = set(target_results[group_targets[0]].keys())
        for target in group_targets:
            common_variants = common_variants.intersection(
                target_results[target].keys())
        # compute group results
        for variant in common_variants:
            results[variant] = atos_client_results.result.merge_targets(
                group_name,
                map(lambda x: target_results[x][variant], group_targets))
        return results

    def _get_target_results(self, target, query):
        full_query = dict.fromkeys(atos_db.keys, '.*')
        full_query.update(query)
        full_query.update({'target': target})
        # query results for given target
        reslist = self.db.get_results(full_query)
        # create results dict
        results = {}  # {variant: [result_obj]}
        for res in reslist:
            if 'FAILURE' in [res['size'], res['time']]: continue
            results.setdefault(res['variant'], []).append(
                atos_client_results.result(res))
        # merge multiple runs (average execution times)
        for variant in results.keys():
            results[variant] = atos_client_results.result.merge_multiple_runs(
                results[variant])
        return results


# ####################################################################


class atos_client_db():

    def __init__(self, atos_db):
        self.db = atos_db

    def query(self, query=None, replacement=None):
        return atos_client_db.db_query(self.db, query, replacement)

    def add_result(self, entry):
        required_fields = set(atos_db.required_fields)
        if not set(entry.keys()).issuperset(required_fields):
            missing_fields = list(
                required_fields.difference(set(entry.keys())))
            return False, 'missing fields: %s' % str(missing_fields)
        entry = result_entry(entry)
        self.db.add_results([entry])
        return True, entry

    @staticmethod
    def db_load(inf):
        return json.load(inf)

    @staticmethod
    def db_dump(results, outf):
        pprint_list(results, outf)
        return True, len(results)

    @staticmethod
    def db_query(db, query=None, replacement=None):
        results = db.get_results(query)
        if replacement:
            for result in results:
                result.update(replacement)
        return results

    @staticmethod
    def db_transfer(db, results, force):
        required_keys, missing_keys = set(atos_db.required_keys), set()
        if not force:
            result_keys = set(result.keys())
            for result in results:
                if not result_keys.issuperset(required_keys):
                    missing_keys |= required_keys.difference(result_keys)
        if missing_keys:
            return False, 'missing keys: %s' % str(missing_keys)
        db.add_results(results)
        return True, len(results)


# ####################################################################


class json_config():

    def __init__(self, cfgpath):
        filename = os.path.isdir(cfgpath) and os.path.join(
            cfgpath, 'config.json') or cfgpath
        self.filename = filename
        self._create()
        with open(self.filename) as inf:
            self.config = json.load(inf)

    def _create(self):
        if os.path.exists(self.filename): return
        self.config = {}
        self._dump()

    def _dump(self):
        json.dump(self.config, open(self.filename, 'w'),
                  sort_keys=True, indent=4)

    def _compiler_features(self):
        feature_sets = []
        for compiler in self.config.setdefault('compilers', []):
            feature_sets += [
                set([k for (k, v) in compiler.items() if k.endswith('_enabled')
                      and v == '1'])]
        if not feature_sets: return []
        enabled = feature_sets[0]
        for features in feature_sets:
            enabled = enabled.intersection(features)
        return enabled

    def query(self, query, print_res=False):
        results = jsonlib.search(self.config, query)
        if print_res: pprint_list(results, text=True)
        return results

    def add_compiler(self, descr_file):
        new_cpl = {}
        for line in open(descr_file):
            k, v = line.strip().split(' ', 1)
            new_cpl[k] = v
        self.config.setdefault('compilers', []).append(new_cpl)
        self._dump()

    def add_value(self, key, value):
        jsonlib.set_item(self.config, key, value)
        self._dump()

    def get_value(self, key):
        return jsonlib.get_item(self.config, key)

    @staticmethod
    def compiler_version_number(version_str):
        vspl = version_str.split('.', 2)
        major = int((len(vspl) >= 1) and vspl[0] or 0)
        minor = int((len(vspl) >= 2) and vspl[1] or 0)
        patch = int((len(vspl) >= 3) and vspl[2] or 0)
        nstr = '%d%02d%02d' % (major, minor, patch)
        return int(nstr)

    def flags_for_flagfiles(self):
        compilers = self.config.get('compilers', [])
        if not compilers: return ''
        flags = []
        # compiler name
        # temporary fix for multiple compilers pb
        compiler_name = '_'.join(
            sorted(list(set([c['name'].upper() for c in compilers]))))
        flags.append('-D%s' % compiler_name.upper())
        # compiler versions
        versions = sorted([c['version'] for c in compilers])
        if versions:
            # min version
            flags.extend(['-D%s_VERSION=%d' % (
                    compiler_name,
                    json_config.compiler_version_number(versions[0]))])
            # max version
            flags.extend(['-D%s_MAX_VERSION=%d' % (
                    compiler_name,
                    json_config.compiler_version_number(versions[-1]))])
        # compiler features
        flags.extend(['-D%s' % (f.upper()) for f in self._compiler_features()])
        return ' '.join(flags)


# ####################################################################


def timer(func):
    def wrapper(*args, **kwargs):
        t0 = time.time()
        res = func(*args, **kwargs)
        t1 = time.time()
        print 'timer: %r %.2fs' % (func.__name__, t1 - t0)
        return res
    return wrapper

def average(l):
    return sum(l) / len(l)

def geometric_mean(l):
    return (10 ** (sum(map(math.log10, l)) / len(l)))

def standard_deviation(l):
    avg = average(l)
    variance = average([((x - avg) ** 2) for x in l])
    return math.sqrt(variance)

def variation_coefficient(l):
    return (standard_deviation(l) / average(l))

def md5sum(s):
    return hashlib.md5(s).hexdigest()

def hashid(s):
    # return same results as 'echo s | md5sum'
    return md5sum(s + '\n')

def strtodict(s):
    # 'aa:xx,bb:yy' -> {'aa':'xx','bb':'yy'}
    d = {}
    if s == '': return d
    if s[0] == '[':
        return json.loads(s)[0]
    if s[0] == '{':
        return json.loads(s)
    for kv in s.split(','):
        k, v = kv.split(':')
        d[k] = v
    return d

def strtoquery(s):
    if not s:
        return {}
    if s[0].isalpha():
        return strtodict(s)
    return s

def strtolist(s):
    return s.split(',')

def results_filter(results, query):
    if not query: return results
    if isinstance(query, str):
        return jsonlib.search(results, query)
    return (filter(lambda x: all(
                map(lambda (k, v): re.match('^%s$' % v, x.get(k, '')),
                    query.items())), results))

def result_entry(d):
    try:
        d['time'] = float(d['time'])
        d['size'] = int(d['size'])
        assert d['time'] and d['size']
    except:
        d['time'] = d['size'] = 'FAILURE'
    return d

def open_locked(filename, mode='r'):
    while True:
        outf = open(filename, mode)
        try:
            fcntl.flock(outf, fcntl.LOCK_EX | fcntl.LOCK_NB)
            return outf
        except: outf.close()
        time.sleep(1)

def pprint_list(list, out=None, text=False):
    out = out or sys.stdout
    if not list:
        print >>out, None
        return
    if text:
        for x in list: print x
        return
    print >>out, '[',
    nb_elems = len(list)
    for i in range(nb_elems):
        print >>out, '%s%s%s' % (
            i > 0 and '  ' or '',
            json.dumps(list[i]), ((i + 1) < nb_elems) and ',\n' or ''),
    print >>out, ']'

def pprint_table(results, out=None, reverse=False):
    out = out or sys.stdout
    xmax, ymax = len(results[0]), len(results)
    # swap line/columns
    if reverse: results = [
        [(results[y] and results[y][x] or '')
         for y in range(ymax)] for x in range(xmax)]
    # max col width
    xmax, ymax = len(results[0]), len(results)
    colwidth = [
        max([(results[y] and len(results[y][x]) or 0) for y in range(ymax)])
        for x in range(xmax)]
    for y in range(ymax):
        print >>out, ' ',
        if not results[y]:
            print ''
            continue
        for x in range(xmax):
            fmt = ('%%%s%ds' % ((x == 0) and '-' or '', colwidth[x]))
            print >>out, fmt % ('%s' % (results[y][x])),
            if x < xmax - 1: print >>out, '|',
        print >>out, ''

def info(msg):
    # do not print info on stdout (as it can be used for dump/load)
    # could be replaced by logging.info
    print >> sys.stderr, msg

def fatal(msg):
    print >> sys.stderr, '%s:' % (os.path.basename(sys.argv[0])),
    print >> sys.stderr, 'error:',
    print >> sys.stderr, msg
    sys.exit(1)

def execpath(file):
    """
    Gets the full executable path for the given file.
    Returns None if the command is not found or not executable.
    """
    status, output = process.system(["which", file], get_output=True)
    if output == "": return None
    return output.rstrip("\n")

def pager_cmd():
    """
    Gets a cmd array for executing a pager.
    Returns None if no pager is available
    """
    pager = os.getenv("ATOS_PAGER")
    if pager == None:
        pager = os.getenv("PAGER")
    if pager == "":
        return None
    if pager != None:
        return process.cmdline2list(pager)
    pager = "less"
    if execpath(pager) != None:
        return [pager]
    pager = "more"
    if execpath(pager) != None:
        return [pager]
    return None

def pagercall(cmd):
    """
    Executes a command and page the output.
    Returns the exit status of the command.
    """
    pager_args = pager_cmd()
    if pager_args != None:
        cmd = '%s | %s' % (cmd, ' '.join(pager_args))
    try:
        status = os.system(cmd)
    except Exception:
        print >>sys.stderr, "error during pager command: " + cmd
        sys.exit(1)
    return status

def mancall(page):
    """
    Execute man for the given page.
    Returns the exit status of the command.
    """
    cmd = "env MANPATH=" + globals.MANDIR + " man " + page
    try:
        status = os.system(cmd)
    except Exception:
        print >>sys.stderr, "error during man command: " + cmd
        sys.exit(1)
    return status

def help_man(topic):
    """
    Displays the manpage for topic.
    Returns non 0 if man command or manpage are not available.
    Do not return error if the mancall fails. For instance
    the user may interrupt the display, but this is not an error.
    """
    man = execpath("man")
    page = "atos-" + topic
    manpage = os.path.join(globals.MANDIR, "man1", page + ".1")
    if man and os.path.exists(manpage):
        mancall(page)
        return 0
    return 1


def help_text(topic):
    """
    Displays the textual form of the manual for topic.
    Returns non 0 if rst file is not available.
    Do not return error if the pagercall fails. Ref comment in help_man().
    """
    rst_file = os.path.join(globals.DOCDIR, topic + ".rst")
    if os.path.exists(rst_file):
        pagercall("cat " + rst_file)
        return 0
    return 1


def getarg(key, default=None):
    # TODO: to be removed when argument parsing will be factorized
    import inspect
    lastframe = inspect.stack()[-1][0]
    argstruct = 'args' in lastframe.f_globals and 'args' or 'opts'
    try:
        return eval('lastframe.f_globals["%s"].%s' % (argstruct, key))
    except: return default

def proot_atos():
    status, uname = process.system('/bin/uname -m', get_output=True)
    arch = uname.rstrip('\n')
    if arch in ['i386', 'i486', 'i586', 'i686']: arch = 'i386'
    proot_exec = os.path.join(globals.LIBDIR, arch, 'bin', 'proot')
    if os.path.isfile(proot_exec):
        return proot_exec
    else:
        return "proot"

def expand_response_file(args):
    """ Return the actual args list, after response expansion. """
    # TODO: should use the SimpleCmdInterpreter interface
    def expand_arg(arg):
        m = re.search("^@(.+)$", arg)
        if m:
            f = open(m.group(1))
            args = sum([i.strip().split() for i in f.readlines()], [])
            f.close()
        else:
            args = [arg]
        return args
    return sum([expand_arg(arg) for arg in args], [])

def get_output_option_value(args):
    """ Get value of -o option from CC command line args. """
    # TODO: should use the SimpleCmdInterpreter interface
    args = expand_response_file(args)
    output = None
    i = 0
    while i + 1 < len(args):
        i = i + 1
        m = re.search("^-o(.*)$", args[i])
        if m != None:
            output = m.group(1)
            if output == "":
                if i + 1 < len(args):
                    output = args[i + 1]
                    i = i + 1
                continue
    return output

def get_input_source_files(args):
    """ Get input source file of CC command. """
    # TODO: should use the SimpleCmdInterpreter interface
    args = expand_response_file(args)
    inputs = []
    i = 0
    while i + 1 < len(args):
        i = i + 1
        m = re.search("^-o(.*)$", args[i])
        if m != None:
            if m.group(1) == "": i = i + 1
            continue
        m = re.search("\\.(c|cc|cxx|cpp|c\+\+|C|i|ii)$", args[i])
        if m != None:
            inputs.append(args[i])
    return inputs

# ####################################################################


if __name__ == '__main__':

    # ################################################################
    import __init__
    import optparse

    help_lines = [
        '',
        'Available actions:',
        '  create_db   create a new database',
        '  add_result  add result entry',
        '  push        export results to another database',
        '  pull        import results from another database',
        '  query       query results',
        '  speedups    list results',
        '',
        'type \'%s <action> -h\' for more help on a specific action.' % (
            os.path.basename(sys.argv[0])), '']

    parser = optparse.OptionParser(
        usage='%prog action [options]',
        version="%prog version " + globals.VERSION)
    parser.format_epilog = lambda x: '\n'.join(help_lines)

    if len(sys.argv) < 2: parser.error('action expected')

    (opts, args) = parser.parse_args([sys.argv[1]])

    # ################################################################

    if args[0] == 'create_db':

        subparser = optparse.OptionParser(
            description='Create a new empty database',
            usage='%%prog %s [options]' % args[0])
        subparser.add_option('-C', dest='configuration_path',
                action='store', type='string', default='./atos-configurations',
                help='configuration path (default: ./atos-configurations)')
        subparser.add_option('-t', '--type', dest='type',
                action='store', type='choice', default='results_db',
                choices=['results_db', 'json', 'pickle'],
                help='database type '
                     '[results_db|json|pickle] (default: results_db)')
        subparser.add_option('--shared', dest='shared',
                action='store_true', default=False,
                help='create a shared database '
                             '(group has write permission) (default: False)')
        subparser.epilog = 'Example: create_db -C. -tjson'
        (opts, args) = subparser.parse_args(sys.argv[2:])

        if not os.path.exists(opts.configuration_path):
            os.makedirs(opts.configuration_path)
        if opts.type == 'results_db':
            db_file = os.path.join(opts.configuration_path, 'results.db')
            db = atos_db_file(db_file)
        elif opts.type == 'json':
            db_file = os.path.join(opts.configuration_path, 'results.json')
            db = atos_db_json(db_file)
        elif opts.type == 'pickle':
            db_file = os.path.join(opts.configuration_path, 'results.pkl')
            db = atos_db_pickle(db_file)
        else: assert 0
        if opts.shared: os.chmod(db_file, 0660)
        info('created new database in "%s"' % db_file)

    # ################################################################

    elif args[0] == 'query':

        subparser = optparse.OptionParser(
            description='Query database results',
            usage='%%prog %s [options]' % args[0])
        subparser.add_option('-C', dest='configuration_path',
                action='store', type='string', default='./atos-configurations',
                help='configuration path (default: ./atos-configurations)')
        subparser.add_option('-q', '--query', dest='query',
                action='store', type='string', default='',
                help='results query values (default: None)')
        subparser.add_option('-t', '--text', dest='text',
                action='store_true', default=False,
                help='text output format (default: json)')
        subparser.epilog = 'Examples: \n' \
            '    query -q "variant:REF,compiler:gcc-4.*"\n' \
            '    query -q "$[?(@.target="aaa" && @.variant="REF")]"\n' \
            '    query -q "$[?(@.target="aaa")].size"\n'
        subparser.format_epilog = lambda x: subparser.epilog
        (opts, args) = subparser.parse_args(sys.argv[2:])

        if opts.configuration_path == '-':
            results = results_filter(
                atos_client_db.db_load(sys.stdin), strtoquery(opts.query))

        else:
            client = atos_client_db(atos_db.db(opts.configuration_path))
            results = client.query(strtoquery(opts.query))

        pprint_list(results, text=opts.text)

    # ################################################################

    elif args[0] == 'add_result':

        subparser = optparse.OptionParser(
            description='Add result to database',
            usage='%%prog %s [options] [dbfile]' % args[0])
        subparser.add_option('-C', dest='configuration_path',
                action='store', type='string', default='./atos-configurations',
                help='configuration path (default: ./atos-configurations)')
        subparser.add_option('-r', '--result', dest='result',
                action='store', type='string', default='',
                help='results values (default: None)')
        subparser.epilog = 'Example: addres -r"target:X,compiler:gcc,time:12"'
        (opts, args) = subparser.parse_args(sys.argv[2:])

        result = strtodict(opts.result)

        if opts.configuration_path == '-':
            print atos_db_file.entry_str(result),

        else:
            db = (args and atos_db_file(args[0])
                  or atos_db.db(opts.configuration_path))
            status, output = atos_client_db(db).add_result(result)
            if not status: fatal(output)

    # ################################################################

    elif args[0] == 'push':

        subparser = optparse.OptionParser(
            description='Export results to another database',
            usage='%%prog %s [options]' % args[0])
        subparser.add_option('-C', '--C1', dest='configuration_path',
                action='store', type='string', default='./atos-configurations',
                help='configuration path (default: ./atos-configurations)')
        subparser.add_option('-R', '--C2', dest='remote_configuration_path',
                action='store', type='string', default=None,
                help='remote configuration path (default: None)')
        subparser.add_option('-q', '--query', dest='query',
                action='store', type='string', default='',
                help='query for exported results (default: None)')
        subparser.add_option('-r', '--repl', dest='replacement',
                action='store', type='string', default='',
                help='values replacement (default: None)')
        subparser.add_option('-f', '--force', dest='force',
                action='store_true', default=False,
                help='ignore missing keys (default: False)')
        subparser.epilog = 'Example: ' \
            'push -q"compiler:gcc,variant=OPT.*" -renvironment:u8500'
        (opts, args) = subparser.parse_args(sys.argv[2:])
        if not opts.remote_configuration_path:
            subparser.error(
                'expected a remote configuration_path (set with -R option)')

        db = atos_db.db(opts.configuration_path)
        results = atos_client_db.db_query(
            db, strtoquery(opts.query), strtodict(opts.replacement))

        if opts.remote_configuration_path == '-':
            status, output = atos_client_db.db_dump(results, sys.stdout)
        else:
            other_db = atos_db.db(opts.remote_configuration_path)
            status, output = atos_client_db.db_transfer(
                other_db, results, opts.force)

        if status:
            info('exported %d results' % (output))
        else:
            fatal(output)

    # ################################################################

    elif args[0] == 'pull':

        subparser = optparse.OptionParser(
            description='Import results from another database',
            usage='%%prog %s [options]' % args[0])
        subparser.add_option('-C', '--C1', dest='configuration_path',
                action='store', type='string', default='./atos-configurations',
                help='configuration path (default: ./atos-configurations)')
        subparser.add_option('-R', '--C2', dest='remote_configuration_path',
                action='store', type='string', default=None,
                help='remote configuration path (default: None)')
        subparser.add_option('-q', '--query', dest='query',
                action='store', type='string', default='',
                help='query for exported results (default: None)')
        subparser.add_option('-r', '--repl', dest='replacement',
                action='store', type='string', default='',
                help='values replacement (default: None)')
        subparser.add_option('-f', '--force', dest='force',
                action='store_true', default=False,
                help='ignore missing keys (default: False)')
        subparser.epilog = 'Example: ' \
            'pull -q"compiler:gcc,variant=OPT.*" -renvironment:u8500'
        (opts, args) = subparser.parse_args(sys.argv[2:])
        if not opts.remote_configuration_path:
            subparser.error(
                'expected a remote configuration_path (set with -R option)')

        db = atos_db.db(opts.configuration_path)

        if opts.remote_configuration_path == '-':
            results = atos_client_db.db_load(sys.stdin)
        else:
            other_db = atos_db.db(opts.remote_configuration_path)
            results = atos_client_db.db_query(
                other_db, strtoquery(opts.query), strtodict(opts.replacement))

        status, output = atos_client_db.db_transfer(db, results, opts.force)

        if status:
            info('imported %d results' % (output))
        else:
            fatal(output)

    # ################################################################

    elif args[0] == 'speedups':

        subparser = optparse.OptionParser(
            description='Get results',
            usage='%%prog %s [options]' % args[0])
        subparser.add_option('-C', dest='configuration_path',
                action='store', type='string', default='./atos-configurations',
                help='configuration path (default: ./atos-configurations)')
        subparser.add_option('-t', '--targets', dest='targets',
                action='store', type='string', default='',
                help='target list (default: None)')
        subparser.add_option('-q', '--query', dest='query',
                action='store', type='string', default='',
                help='results query values (default: None)')
        subparser.add_option('-g', '--group_name', dest='group_name',
                action='store', type='string', default=None,
                help='target group name (default: None)')
        subparser.add_option('-r', '--refid', dest='ref',
                action='store', type='string', default='REF',
                help='reference variant id (default: None)')
        subparser.add_option('-f', '--frontier', dest='frontier',
                action='store_true', default=False,
                help='only print frontier points (default: False)')
        subparser.add_option('-s', '--tradeoff', dest='tradeoffs',
                action='append', type='float', default=[],
                help='selected tradeoff given size/perf ratio')
        subparser.epilog = \
            'Example: speedups -C. -q"target:bzip2,compiler:gcc" -rREF -f'
        (opts, args) = subparser.parse_args(sys.argv[2:])

        client = atos_client_results(
            atos_db.db(opts.configuration_path),
            opts.targets and strtolist(opts.targets),
            strtoquery(opts.query), opts.group_name)

        if opts.ref: client.compute_speedups(opts.ref)

        if opts.tradeoffs:
            pprint_list(
                map(lambda x: client.tradeoff(x).dict(), opts.tradeoffs))
        else:
            pprint_list(client.get_results(opts.frontier))

    # ################################################################

    elif args[0] == 'report':

        subparser = optparse.OptionParser(
            description='Print results',
            usage='%%prog %s [options]' % args[0])
        subparser.add_option('-C', dest='configuration_path',
                action='store', type='string', default='./atos-configurations',
                help='configuration path (default: ./atos-configurations)')
        subparser.add_option('-t', '--targets', dest='targets',
                action='store', type='string', default='',
                help='target list (default: ALL)')
        subparser.add_option('-v', '--variants', dest='variants',
                action='store', type='string', default=None,
                help='variants list (default: ALL)')
        subparser.add_option('-q', '--query', dest='query',
                action='store', type='string', default='',
                help='results query values (default: None)')
        subparser.add_option('-r', '--refid', dest='ref',
                action='store', type='string', default='REF',
                help='reference variant id (default: None)')
        subparser.add_option('-X', dest='reverse',
                action='store_true', default=False,
                help='swap line/columns')
        subparser.add_option('-m', '--mode', dest='mode',
                action='store', type='choice', default='speedup',
                choices=['speedup', 'sizered', 'stdev'],
                help='report type [speedup|sizered|stdev] (default: speedup)')
        subparser.epilog = \
            'Example: report -C. -rREF --stdev'
        (opts, args) = subparser.parse_args(sys.argv[2:])

        db = atos_db.db(opts.configuration_path)

        # targets 'group1:targ1,targ2,targ3+group2:targ4,targ5+targ6'
        group_targets, group_names = [], []
        if opts.targets:
            for group in opts.targets.split('+'):
                spl = group.split(':')
                if len(spl) > 1:
                    group_targets += [spl[1].split(',')]
                    group_names += [spl[0]]
                else:
                    group_targets += [spl[0].split(',')]
                    group_names += ['+'.join(group_targets[-1])]
        else:
            results = db.get_results(strtoquery(opts.query))
            group_targets = sorted(
                [list(set(results_filter(results, '$[*].target')))])
            group_names = map('+'.join, group_targets)

        # groups not supported in stdev mode
        assert (opts.mode != 'stdev') or all(
            map(lambda g: len(g) == 1, group_targets))

        # results
        all_results = {}
        for num in range(len(group_targets)):
            targets, name = group_targets[num], group_names[num]
            client = atos_client_results(
                db, targets, strtoquery(opts.query), name)
            if opts.ref: client.compute_speedups(opts.ref)
            all_results[group_names[num]] = client.results

        # variants
        variants = opts.variants and opts.variants.split(',') or sorted(list(
            reduce(lambda acc, s: acc.intersection(s),
                   map(lambda v: set(v.keys()), all_results.values()))))

        table = (opts.mode != 'stdev') and [[''] + group_names] or []

        for variant in variants:

            table += [[variant]]
            if opts.mode == 'stdev':
                table[-1] += ['AVG', 'NOISE', 'STDEV']

            for target in group_names:

                if opts.mode == 'speedup':
                    table[-1] += ['%.0f %+6.1f%%' % (
                            all_results[target][variant].time,
                            all_results[target][variant].speedup * 100)]

                elif opts.mode == 'sizered':
                    table[-1] += ['%.0f %+6.1f%%' % (
                            all_results[target][variant].size,
                            all_results[target][variant].sizered * 100)]

                elif opts.mode == 'stdev':
                    table += [[target]]
                    results = map(
                        lambda r: r.time,
                        all_results[target][variant]._results[0]._results)
                    avg_res, min_res, max_res = (
                        average(results), min(results), max(results))
                    max_avg_diff = max(avg_res - min_res, max_res - avg_res)
                    table[-1] += ['%.2f' % avg_res]
                    table[-1] += ['%.2f%%' % ((max_avg_diff / avg_res) * 100)]
                    table[-1] += ['%.2f%%' % (
                            (standard_deviation(results) / avg_res) * 100)]

                else: assert 0

            if opts.mode == 'stdev': table += [None]

        pprint_table(table, reverse=opts.reverse)

    # ################################################################

    elif args[0] == 'play':

        subparser = optparse.OptionParser(prog='atos-play')
        subparser.add_option('-C', dest='configuration_path',
            action='store', type='string', default="./atos-configurations",
            help='set configuration path (default: ./atos-configurations)')
        subparser.add_option('-s', '--tradeoff', dest='tradeoffs',
            action='append', type='float', default=[],
            help='selected tradeoff given size/perf ratio')
        subparser.add_option('-N', '--nb', dest='nb',
            action='store', type='int', default=1,
            help='get nb points (default: 1)')
        subparser.add_option('-v', '--variant', dest='variant',
            action='store', type='string', default=None,
            help='selected variant')
        subparser.add_option('-a', '--hash', dest='hash_id',
            action='store', type='string', default=None,
            help='selected variant hash_id')
        subparser.add_option('-i', dest='identifier',
            action='store', type='string', default=None,
            help='identifier of run (default: executables basename)')
        subparser.add_option('-n', dest='dryrun',
            action='store_true', default=False,
            help='dry run, output build commands only')
        subparser.add_option('-p', dest='print_config',
            action='store_true', default=False,
            help='print configuration only')
        subparser.add_option('-P', dest='print_variant',
            action='store_true', default=False,
            help='print configuration only')
        subparser.add_option('-q', dest='quiet',
            action='store_true', default=False,
            help='quiet mode')

        (opts, args) = subparser.parse_args(sys.argv[2:])

        atos_db = atos_db.db(opts.configuration_path)

        results = []

        if opts.variant:
            results = atos_client_db(atos_db).query(
                {'variant': opts.variant, 'target': opts.identifier})

        elif opts.hash_id:
            results = atos_client_db(atos_db).query(
                {'target': opts.identifier}) or []
            results = filter(
                lambda x: hashid(x['variant']).startswith(opts.hash_id),
                results)
            if len(results) > 1:
                subparser.error('ambiguous local_id: %s' % opts.hash_id)

        else:
            all_points = list(atos_client_results(
                atos_db, [opts.identifier]).results.values())
            nbtr = max(1, opts.nb / len(opts.tradeoffs))
            results = []
            for trade in opts.tradeoffs:
                selected = atos_client_results.select_tradeoffs(
                    all_points, trade, nbtr) or []
                results.extend(selected)
                map(all_points.remove, selected)
            results = map(lambda x: x.dict(), results)

        if not results:
            subparser.error('no results found')

        if opts.print_variant:
            for result in results:
                print result['variant']

        elif opts.print_config:
            for result in results:
                print atos_db_file.entry_str(result),

        else:
            rcode = 0
            for result in results:
                if not opts.quiet:
                    print 'Playing optimized build %s:%s...' % (
                        opts.identifier, result['variant'])

                atos_build = os.path.join(globals.BINDIR, 'atos-build')
                command = ['-a', result.get('conf', '')]
                if result.has_key('uconf'):
                    command += ['-u', result['uconf']]
                elif result.has_key('gconf'):
                    command += ['-g', result['gconf']]
                if opts.dryrun:
                    command += ['-n']
                rcode = max(
                    process.system([atos_build] + command + args), rcode)
            sys.exit(rcode)

    # ################################################################

    elif args[0] == 'config':

        subparser = optparse.OptionParser()
        subparser.add_option('-C', dest='configuration_path',
            action='store', type='string', default="./atos-configurations",
            help='set configuration path (default: ./atos-configurations)')
        subparser.add_option('-q', '--query', dest='query',
                action='store', type='string', default='',
                help='results query values (default: None)')
        subparser.add_option('-t', '--text', dest='text',
                action='store_true', default=False,
                help='text output format (default: json)')
        subparser.add_option('-u', '--uniq', dest='uniq',
                action='store_true', default=False,
                help='omit repeated results (default: False)')
        subparser.add_option('-a', '--add', dest='add_item',
                action='store', type='string', default=None,
                help='add config item (key:value) (default: None)')
        subparser.add_option('-g', '--get', dest='get_item',
                action='store', type='string', default=None,
                help='get config item (default: None)')
        subparser.add_option('--add-cpl', dest='add_cpl',
                action='store', type='string', default=None,
                help='add compiler description (default: None)')
        subparser.add_option('--cpl-flags', dest='cpl_flags',
                action='store_true', default=False,
                help='print flags for flags file (default: False)')

        (opts, args) = subparser.parse_args(sys.argv[2:])

        config_file = os.path.join(opts.configuration_path, 'config.json')

        if opts.query:
            client = json_config(config_file)
            results = client.query(strtoquery(opts.query))
            if opts.uniq: results = list(set(results))
            pprint_list(results, text=opts.text)

        elif opts.add_item:
            client = json_config(config_file)
            key, value = opts.add_item.split(':')
            client.add_value(key, value)

        elif opts.get_item:
            if os.path.isfile(config_file):
                client = json_config(config_file)
                print client.get_value(opts.get_item) or ''

        elif opts.add_cpl:
            client = json_config(config_file)
            client.add_compiler(opts.add_cpl)

        elif opts.cpl_flags:
            if os.path.isfile(config_file):
                client = json_config(config_file)
                print client.flags_for_flagfiles()

        else: pass

    # ################################################################

    else:
        parser.error("unknown action '%s'" % args[0])



# ####################################################################
