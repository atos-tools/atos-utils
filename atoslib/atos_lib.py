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

import sys, os, re, math, itertools, time, json, hashlib
import cPickle as pickle
import tempfile
import glob

import globals
import jsonlib
import process
import logger

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

    # update the results returned by query with the update_fct
    #   returns the list of results
    #   update_fct must return True if an entry is actually updated
    def update_results(self, query=None, update_fct=None):
        raise NotImplementedError

    #
    @staticmethod
    def db(results_path, no_cache=False):

        if os.path.isdir(results_path):
            atos_configuration = results_path
            # results.pkl  loadtime:  3.50s  filesize: 229M
            db_pckl = os.path.join(atos_configuration, 'results.pkl')
            # results.json loadtime: 27.63s  filesize: 217M
            db_json = os.path.join(atos_configuration, 'results.json')
            # results.db   loadtime:  5.70s  filesize: 579M
            db_dflt = os.path.join(atos_configuration, 'results.db')

            # select db file in atos-config directory
            if os.path.exists(db_pckl):
                db_func, db_file = atos_db_pickle, db_pckl
            elif os.path.exists(db_json):
                db_func, db_file = atos_db_json, db_json
            else:
                db_func, db_file = atos_db_file, db_dflt

        elif os.path.isfile(results_path):
            ext = os.path.splitext(results_path)
            if ext == ".pkl":
                db_func, db_file = atos_db_pickle, results_path
            elif ext == ".json":
                db_func, db_file = atos_db_json, results_path
            else:  # default case: dbfile
                db_func, db_file = atos_db_file, results_path

        else:
            logger.error(
                "results not found: '%s'" % results_path, exit_status=1)

        # create db-cache if necessary
        if not getattr(atos_db, 'db_cache', None):
            atos_db.db_cache = {}

        # use already-opened db if any
        db_file = os.path.abspath(db_file)
        if not no_cache and db_file in atos_db.db_cache.keys():
            return atos_db.db_cache[db_file]
        else:
            new_db = db_func(db_file)
            atos_db.db_cache[db_file] = new_db
            return new_db


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

    def update_results(self, query=None, update_fct=None):
        assert(update_fct != None)
        entries = self.get_results(query)
        updated = False
        for entry in entries:
            if update_fct(entry): updated = True
        if updated: self._write_all()
        return entries

    def _write_entries(self, entries):
        entries_str = ''.join(
            atos_db_file.entry_str(entry) for entry in entries)
        with process.open_locked(self.db_file, 'a') as db_file:
            db_file.write(entries_str)

    def _write_all(self):
        with process.open_locked(self.db_file, 'w') as db_file:
            for entry in self.results:
                db_file.write(atos_db_file.entry_str(entry))

    def _read_results(self):
        if not os.path.exists(self.db_file): return
        curdict, size, time = {}, None, None
        for line in process.open_locked(self.db_file):
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
        with process.open_locked(self.db_file, 'r+') as db_file:
            self.results = json.load(db_file)
            db_file.seek(0)
            db_file.truncate()
            self.results.extend(entries)
            json.dump(self.results, db_file, sort_keys=True, indent=4)

    def update_results(self, query=None, update_fct=None):
        assert(update_fct != None)
        with process.open_locked(self.db_file, 'r+') as db_file:
            self.results = json.load(db_file)
            entries = self.get_results(query)
            updated = False
            for entry in entries:
                if update_fct(entry): updated = True
            if updated:
                db_file.seek(0)
                db_file.truncate()
                json.dump(self.results, db_file, sort_keys=True,
                          indent=4)
        return entries

    def _read_results(self):
        self.results = json.load(process.open_locked(self.db_file))

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
        with process.open_locked(self.db_file, 'r+') as db_file:
            self.results = pickle.load(db_file)
            db_file.seek(0)
            db_file.truncate()
            self.results.extend(entries)
            pickle.dump(self.results, db_file, -1)

    def update_results(self, query=None, update_fct=None):
        assert(update_fct != None)
        with process.open_locked(self.db_file, 'r+') as db_file:
            self.results = pickle.load(db_file)
            entries = self.get_results(query)
            updated = False
            for entry in entries:
                if update_fct(entry): updated = True
            if updated:
                db_file.seek(0)
                db_file.truncate()
                pickle.dump(self.results, db_file, -1)
        return entries

    def _read_results(self):
        self.results = pickle.load(process.open_locked(self.db_file))

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
            self.speedup = ((float(ref.time) / float(self.time)) - 1.0)
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

    def __init__(self, atos_db,
                 group_targets=None, query=None, group_name=None):
        query = query or {}
        self.db = atos_db
        if not group_targets:
            group_targets = list_unique(
                self.db.get_results('$[*].target') or [])
        group_name = group_name or '+'.join(group_targets)
        self.values = (group_targets, query, group_name)
        # results: {variant: [result_obj]}
        self.results = self._get_group_results(
            group_targets, group_name, query)

    def compute_frontier(self):
        self.frontier = []
        if not self.results: return self.frontier
        atos_client_results.set_frontier_field(self.results.values())
        frontier = filter(lambda x: x.on_frontier, self.results.values())
        self.frontier = sorted(frontier, key=lambda x: x.size)
        return self.frontier

    @staticmethod
    def set_frontier_field(results):
        maybe_on_frontier, mustbe_on_frontier = list(results), set()
        for c1 in results:
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
        # speedups must be already computed
        assert all(map(lambda x: getattr(
                    x, 'speedup', None) is not None, frontier))
        # find best tradeoff (ratio * speedup + sizered)
        # this is the higher ordinate value at abscissa 0
        tradeoffs = map(lambda x: (
                (perf_size_ratio * x.speedup) + x.sizered, x),
                        frontier)
        # also sort by variant_id (to get a deterministic behavior)
        tradeoffs = sorted(tradeoffs, key=lambda x: (x[0], x[1].variant))
        # return the "nb_points" best variants
        tradeoffs = map(lambda x: x[1], tradeoffs[-nb_points:])
        return tradeoffs

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

def merge_results(results):
    # filter out failures
    results = filter(
        lambda x: "FAILURE" not in x.values(), results)
    if not results: return None
    # transform into result objects
    results = map(
        atos_client_results.result, results)
    # compute merged results for each variant
    variants = list_unique(map(lambda x: x.variant, results))
    variant_results = []
    for variant in variants:
        filtered_results = filter(lambda x: x.variant == variant, results)
        targets = list_unique(map(lambda x: x.target, filtered_results))
        # merge multiple runs
        targets_results = map(
            atos_client_results.result.merge_multiple_runs,
            map(lambda x: filter(
                    lambda y: y.target == x, filtered_results), targets))
        # merge multiple targets
        variant_results.append(
            atos_client_results.result.merge_targets(
                'group', targets_results))
    return variant_results


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

    def update_results(self, query, update_fct):
        return self.db.update_results(query, update_fct)

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
            result_keys = set(results.keys())
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
        self.add_compiler_entry(new_cpl)

    def add_compiler_entry(self, new_cpl):
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
        return flags

    def prepare_flag_files(self, configuration_path, compilers, addflags):
        preprocessors = filter(bool, map(
                lambda x: re.search("(cc|\+\+)", os.path.basename(x)) and x,
                compilers))
        assert preprocessors
        preprocessor = preprocessors[0]
        assert os.path.isfile(preprocessor)

        tmpdir = tempfile.mkdtemp()
        flags_files = glob.glob(
            os.path.join(globals.LIBDIR, "config", "flags.*.cfg"))
        for flags_file in flags_files:
            base = os.path.basename(flags_file)
            tmpf = os.path.join(tmpdir, base + ".c")
            flags = map(lambda x: "-D" + x, addflags or [])
            process.commands.copyfile(flags_file, tmpf)
            ppflags = process.system(
                [preprocessor, tmpf, "-C", "-P", "-E"] +
                self.flags_for_flagfiles() + flags,
                check_status=True, get_output=True, no_debug=True)
            with open(os.path.join(configuration_path, base), "w") as destf:
                print >>destf, ppflags
        process.commands.rmtree(tmpdir)

    @staticmethod
    def compiler_config(compiler):

        def get_executable_host(compiler):
            repl = {
                "Intel80386": "i386", "Intel80486": "i386",
                "Intel80586": "i386", "Intel80686": "i386",
                "x86-64": "x86_64"}
            status, host = process.system(
                ["file", compiler], get_output=True)
            host = host.split(",")[1].strip().replace(" ", "")
            return repl.get(host, "unknown")

        def get_triplet_alias(triplet):
            repl = {
                "i486": "i386", "i586": "i386", "i686": "i386", "sh": "sh4"}
            alias = triplet.split("-")[0]
            return repl.get(alias, alias)

        def find_plugin(plugin_name, target_alias, host_alias):
            plugin_name = plugin_name + ".so"
            # ex: ${libdir}/plugins/gcc-4.4.3/i386/i386/acf_plugin.so
            plugin_path = os.path.join(
                globals.LIBDIR, "plugins", "gcc-" + version,
                target_alias, host_alias, plugin_name)
            if not os.path.isfile(plugin_path):
                # retry using only major/minor version numbers
                patchlevels = ".".join(version.split(".")[:2] + ["*"])
                plugins = glob.glob(
                    os.path.join(
                        globals.LIBDIR, "plugins", "gcc-" + patchlevels,
                        target_alias, host_alias, plugin_name))
                plugin_path = sorted(plugins)[-1]
            plugin_path = os.path.isfile(
                plugin_path or "") and plugin_path or "none"
            return plugin_path

        def resolve_links(path):
            """
            Resolve symlinks in order to perform queries on actual file.
            In particular the 'file' command does not follow symlinks.
            """
            while os.path.islink(path):
                path = os.path.join(os.path.dirname(path),
                                    os.readlink(path))
            return path

        assert(os.path.isfile(compiler))
        compiler = resolve_links(compiler)
        compiler_basename = os.path.basename(compiler)

        compiler_config = {}

        if compiler_basename in ["armcc", "armlink"]:
            # arm rvct compiler

            version_string = process.system(
                [compiler], get_output=True, check_status=True)
            driver_version = version_string.split("\n")[0]
            if compiler_basename == "armcc":
                version = driver_version.split()[3]
            else:
                version = driver_version.split()[2]

            compiler_config.update(
                {"name": "rvct",
                 "target": "ARM",
                 "target_alias": "arm",
                 "host_alias": get_executable_host(compiler),
                 "id": "%s-%s-%s" % (name, target, version),
                 "driver_version": driver_version,
                 "lto_enabled": "0",
                 "fto_enabled": "0",
                 "graphite_enabled": "0",
                 "libgomp_enabled": "0",
                 "plugins_enabled": "0",
                 "plugin_acf": "none"
                 })

        else:
            # other compilers: gcc, clang, ...

            #
            # compiler version, ...
            #
            version_string = process.system(
                [compiler, "-v"], get_output=True, check_status=True,
                output_stderr=True)
            name = re.search(
                "(\w*) version", version_string).group(1)
            version = re.search(
                " version ([^ ]*)", version_string).group(1)
            target = process.system(
                [compiler, "-dumpmachine"], get_output=True,
                check_status=True).strip()
            compiler_config["id"] = "%s-%s-%s" % (name, target, version)
            compiler_config["name"] = name
            compiler_config["version"] = version
            compiler_config["target"] = target
            compiler_config["driver_version"] = version_string

            target_alias = get_triplet_alias(target)
            host_alias = get_executable_host(compiler)
            compiler_config["target_alias"] = target_alias
            compiler_config["host_alias"] = host_alias

            #
            # acf plugin
            #
            acf_path = find_plugin("acf_plugin", target_alias, host_alias)
            compiler_config["plugin_acf"] = acf_path

            cc1_path = process.system(
                [compiler, "--print-prog-name=cc1"], get_output=True,
                check_status=True).strip()
            try:
                assert os.path.isfile(cc1_path)
                obj_t = process.system(
                    ["objdump", "-t", cc1_path], get_output=True,
                    check_status=True, no_debug=True)
                hwi = int(re.search("(\w*)\W*target_newline", obj_t).group(1))
                expected_hwi = (
                    (host_alias == "i386" and target_alias != "x86_64")
                    and 4 or 8)
                valid_host_wide_int = int(hwi == expected_hwi)
            except:
                # check hwi value on other cases
                valid_host_wide_int = 1
            compiler_config["valid_host_wide_int"] = str(valid_host_wide_int)

            #
            # available compiler optimizations and features
            #
            tmpdir = tempfile.mkdtemp()
            test_c = os.path.join(tmpdir, "test.c")
            test_o = os.path.join(tmpdir, "test.o")
            with open(test_c, "w") as testf:
                print >>testf, "#include <stdio.h>"
                print >>testf, "int main(void)"
                print >>testf, "{"
                print >>testf, "  int i;"
                print >>testf, "  for (i = 0; i < 10; i++)"
                print >>testf, "  {"
                print >>testf, "      printf(\"hello\\n\");"
                print >>testf, "  }"
                print >>testf, "  return 0;"
                print >>testf, "}"

            lto_enabled = int(process.system([
                    compiler, "-O2", "-flto", "-o", test_o, "-c", test_c
                    ]) == 0)
            graphite_enabled = int(process.system([
                    compiler, "-O2", "-floop-block", "-o", test_o, "-c", test_c
                    ]) == 0)
            plugins_enabled = int(os.path.isfile(acf_path) and process.system([
                        compiler, "-O2", "-o", test_o, "-c", test_c,
                        "-fplugin=" + acf_path, "-fplugin-arg-acf_plugin-test"
                        ]) == 0)

            compiler_config["lto_enabled"] = str(lto_enabled)
            compiler_config["fdo_enabled"] = "1"
            compiler_config["graphite_enabled"] = str(graphite_enabled)
            compiler_config["libgomp_enabled"] = "0"
            compiler_config["plugins_enabled"] = str(plugins_enabled)
            process.commands.rmtree(tmpdir)

        return compiler_config


# ####################################################################


class default_obj(object):
    """
    Simple attributes holder.
    """
    def __init__(self, **kwargs):
        self.__dict__.update(kwargs)

    def update(self, **kwargs):
        self.__dict__.update(kwargs)
        return self

    def copy(self, **kwargs):
        return type(self)(**vars(self))

    def __repr__(self):
        items = map(lambda (k, v): (str(k) + '=' + str(v)), vars(self).items())
        return 'obj(%s)' % ', '.join(items)

    def __getattr__(self, name):
        return None

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

def sha1sum(s):
    return hashlib.sha1(s).hexdigest()

def list_unique(seq):
    """
    Returns a new list with no duplicate elements.
    The initial list order is preserved.
    This function should be used in favor of list(set(seq))
    which does not preserve order.
    """
    seen = set()
    return [x for x in seq if x not in seen and not seen.add(x)]

def hashid(s):
    # return same results as 'echo s | md5sum'
    return md5sum(s + '\n')

def variant_id(options=None, gopts=None, uopts=None):
    if options == None: options = ""
    if options == "" and gopts == None and uopts == None:
        return "REF"
    res_variant = "OPT"
    if gopts != None:
        res_variant += "-fprofile-generate" + "".join(gopts.split())
    elif uopts != None:
        res_variant += "-fprofile-use" + "".join(uopts.split())
    else: pass
    if options != None:
        res_variant += "".join(options.split())
    return res_variant

def pvariant_id(popts=None):
    assert(popts != None)
    res_variant = "OPT"
    res_variant += "-fprofile-generate" + "".join(popts.split())
    return res_variant

def target_id(executables):
    """ Returns the target id given the list of executables. """
    return "-".join(map(os.path.basename, executables))

def get_profile_path(configuration_path, variant):
    """ Returns the local profile path for the given variant. """
    return os.path.abspath(os.path.join(configuration_path,
                                        "profiles", hashid(variant)))

def get_oprofile_path(configuration_path, variant):
    """ Returns the local oprofile path for the given variant. """
    return os.path.abspath(
        os.path.join(configuration_path, "oprofiles", hashid(variant)))

def get_config_value(configuration_path, key, default=None):
    config_file = os.path.join(configuration_path, 'config.json')
    if not os.path.isfile(config_file): return default
    client = json_config(config_file)
    return client.get_value(key) or default

def query_config_values(configuration_path, query, default=None):
    config_file = os.path.join(configuration_path, 'config.json')
    if not os.path.isfile(config_file): return default
    client = json_config(config_file)
    return client.query(strtoquery(query)) or default

def get_available_optim_variants(configuration_path):
    variants = ['lto', 'fdo', 'lipo']
    enabled = ['base']
    for variant in variants:
        variant_enabled = query_config_values(
            configuration_path, "$.compilers[*].%s_enabled" % variant)
        variant_enabled = variant_enabled and all(map(int, variant_enabled))
        if variant_enabled: enabled.append(variant)
    if 'fdo' in enabled and 'lto' in enabled:
        enabled.append('fdo+lto')
    return enabled

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

def results_filter_cookie(results, cookie):
    if not cookie: return results
    return filter(
        lambda x: cookie in x.get('cookies', '').split(','), results)

def results_filter_cookies(results, cookies):
    if not cookies: return results
    return filter(
        lambda x: not set(cookies).isdisjoint(
            set(x.get('cookies', '').split(','))),
        results)

def new_cookie():
    """ Generates a new universally unique cookie. """
    return compute_cookie(os.uname(), os.getpid(), os.getppid(), time.time())

def compute_cookie(*args):
    """ Generate a cookie from the given list. """
    return sha1sum(str(args))

def unique_cookie(cookies):
    """ Generate a unique or new cookie from the given list of cookies. """
    if cookies:
        assert(isinstance(cookies, list))
        cookie = cookies[0] if len(cookies) == 1 else compute_cookie(*cookies)
    else: cookie = new_cookie()
    return cookie

def result_entry(d):
    try:
        d['time'] = float(d['time'])
        d['size'] = int(d['size'])
        assert d['time'] and d['size']
    except:
        d['time'] = d['size'] = 'FAILURE'
    return d

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

def pprint_speedups(results, out=None, reverse=False):
    """
    Simple print of speedup and size reductions as a table.
    """
    table = [['speedup', 'sizered', 'target', 'variant_id']]
    for result in results:
        table += [['%+6.2f%%' % (result['speedup'] * 100),
                   '%+6.2f%%' % (result['sizered'] * 100),
                   result['target'],
                   hashid(result['variant'])]]
    pprint_table(table, out, reverse)

def execpath(file):
    """
    Gets the full executable path for the given file.
    Returns None if the command is not found or not executable.
    """
    try:
        status, output = process.system(
            ["/usr/bin/which", file], get_output=True)
    except OSError:
        output = ""
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

def pagercall(txtfile):
    """
    Executes a pager call for displaying the given text file.
    """
    pager_args = pager_cmd()
    if pager_args != None:
        cmd = process.list2cmdline(pager_args + [txtfile])
        try:
            status = os.system(cmd)
        except Exception:
            print >>sys.stderr, "error during pager command: " + cmd
            status = 1
    else:
        for line in open(txtfile).readlines():
            print line,
        status = 0
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
        return pagercall(rst_file)
    return 1


def generate_script(script_path, command, environ=None):
    """
    Generates a wrapper script from the given command.
    The command may be a list or a correctly quoted string.
    The command is executed within the current directory
    and the given environment (current environment at the
    time of this call if None).
    """
    from process import list2cmdline, commands
    assert(isinstance(command, (list, str, unicode)))
    if isinstance(command, list):
        command = list2cmdline(command, sh_quote=True)
    cwd = list2cmdline([os.getcwd()], sh_quote=True)
    environ = os.environ if (environ is None) else environ
    with open(script_path, 'w') as f:
        f.write("#!/bin/sh\n")
        f.write("set -e\n")
        f.write("cd " + cwd + "\n")
        for key, value in environ.items():
            quoted_value = list2cmdline([value], sh_quote=True)
            f.write(key + "=" + quoted_value + " && ")
            f.write("export " + key + "\n")
        f.write("exec " + command + "\n")
    commands.chmod(script_path, 0755)

def proot_command(**kwargs):
    status, uname = process.system('/bin/uname -m', get_output=True)
    arch = uname.rstrip('\n') if uname else 'i386'
    if arch in ['i386', 'i486', 'i586', 'i686']: arch = 'i386'
    proot_exec = os.path.join(globals.LIBDIR, arch, 'bin', 'proot')
    proot_bin = proot_exec if os.path.isfile(proot_exec) else "proot"
    command = ["env"]
    for key, value in kwargs.items():
        if value is None: continue
        command.append("%s=%s" % (str(key), str(value)))
    command.append(proot_bin)
    command.extend(["-w", os.getcwd(), "/"])
    return command

def timeout_command():
    timeout = os.getenv("TIMEOUT")
    if timeout == None:
        timeout = [os.path.join(globals.BINDIR, "atos-timeout"), "3600"]
    else:
        timeout = timeout and process.cmdline2list(timeout) or []
    return timeout

def open_atos_log_file(configuration_path, name_prefix, variant_id):
    logs_dir = os.path.join(configuration_path, "logs")
    process.commands.mkdir(logs_dir)
    log_file = os.path.join(
        logs_dir, "%s-%s.log" % (name_prefix, hashid(variant_id)))
    return open(log_file, "w")

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

def is_shared_lib_link(args):
    """ Returns true if building a shared lib. """
    args = expand_response_file(args)
    i = 0
    while i + 1 < len(args):
        i = i + 1
        m = re.search("^-shared$", args[i])
        if m != None:
            return True
    return False

# ####################################################################
