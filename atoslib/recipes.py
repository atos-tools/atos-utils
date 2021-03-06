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

import os, sys

import tempfile
import shutil
import subprocess
from process import commands
from process import list2cmdline
from cmd_interpreter import CmdInterpreterFactory
from obj_storage import ObjStorage
from deep_eq import deep_eq

class RecipeStorage(ObjStorage):

    def store_path_ref(self, path):
        assert(os.path.isfile(path))
        file_digest = self.store_file(path)
        path_ref_digest = self.store_obj({'path': path,
                                          'digest': file_digest})
        return path_ref_digest

    def load_path_ref(self, path_ref_digest):
        path_ref = self.load_obj(path_ref_digest)
        assert(isinstance(path_ref, dict))
        assert('path' in path_ref)
        assert('digest' in path_ref)
        return path_ref

    def store_envs(self, envs):
        assert(isinstance(envs, dict))
        return self.store_obj(envs)

    def load_envs(self, envs_digest):
        envs = self.load_obj(envs_digest)
        assert(isinstance(envs, dict))
        return envs

    def store_cmd_node(self, prog, cwd, args, envs, kind="UNK"):
        # Store env
        envs_digest = self.store_envs(envs)
        # Store command arguments
        cmd_node = {'arg0': prog,
                    'cwd': cwd,
                    'args': args,
                    'envs': envs_digest,
                    'kind': kind}
        cnod_digest = self.store_obj(cmd_node)
        return cnod_digest

    def load_cmd_node(self, cnod_digest):
        cmd = self.load_obj(cnod_digest)
        assert(isinstance(cmd, dict))
        return cmd

    def store_path_ref_list(self, paths):
        # Store all paths as path ref objects
        path_ref_digests = []
        for path in paths:
            path_ref_digest = self.store_path_ref(path)
            path_ref_digests.append(path_ref_digest)
        # Return path ref list digest
        return self.store_obj(path_ref_digests)

    def load_path_ref_list(self, path_ref_list_digest):
        path_ref_digests = self.load_obj(path_ref_list_digest)
        assert(isinstance(path_ref_digests, list))
        return path_ref_digests

    def store_recipe_node(self, cnod_digest, inputs_digest, outputs_digest):
        # Store command context
        rec_node = {'command': cnod_digest,
                    'inputs': inputs_digest,
                    'outputs': outputs_digest
                    }
        rnod_digest = self.store_obj(rec_node)
        return rnod_digest

    def load_recipe_node(self, rnod_digest):
        rnod = self.load_obj(rnod_digest)
        assert(isinstance(rnod, dict))
        return rnod

    def recipes_path(self):
        return self.get_stg_path_("recipes")

    def init_recipes_file(self):
        path = self.recipes_path()
        commands.mkdir(os.path.dirname(path))
        commands.unlink(path)
        commands.touch(path)

    def append_recipes_file(self, rnod_digest):
        with open(self.recipes_path(), "a",
                  len(rnod_digest) + 1) as f:
            f.write("%s\n" % rnod_digest)
            f.flush()

    def blacklist_path(self):
        return self.get_stg_path_("blacklist")

    def blacklist_init(self):
        path = self.blacklist_path()
        commands.mkdir(os.path.dirname(path))
        commands.unlink(path)
        commands.touch(path)

    def blacklist_append(self, rnod_digest):
        with open(self.blacklist_path(), "a",
                  len(rnod_digest) + 1) as f:
            f.write("%s\n" % rnod_digest)
            f.flush()

    def blacklist_recipes(self):
        if not os.path.exists(self.blacklist_path()):
            return []
        with open(self.blacklist_path()) as f:
            blacklist = filter(
                lambda x: x != "" and not x.startswith("#"),
                map(lambda x: x.strip(), f.readlines()))
        return blacklist

    def blacklist_contains(self, rnod_digest):
        return rnod_digest in self.blacklist_recipes()

class RecipeManager():
    """
    A recipe manager class that return a recipe graph from
    a given recipe storage.
    The public interface for this class is:
    - recipe_graph(): returns the recipe graph with an optional targets list
    """
    def __init__(self, storage):
        assert(isinstance(storage, RecipeStorage))
        self.stg = storage

    def recipe_graph(self, targets="all"):
        assert(isinstance(targets, list) or
               targets == "last" or
               targets == "all")
        return RecipeGraph(self.stg, self.load_recipes_file_(),
                           targets)

    def load_recipes_file_(self):
        with open(self.stg.recipes_path()) as f:
            return [x.strip() for x in f.readlines()]

class RecipeNode():
    def __init__(self, storage, recipe, cwd=os.getcwd()):
        self.stg = storage
        self.cwd = cwd
        self.recipe = recipe

    def fetch_input_files(self):
        """
        Get the inputs of the recipe into the expected input paths.
        Fetch from the object storage if the input is not actually
        present in the expected path.
        """
        rnode = self.stg.load_recipe_node(self.recipe)
        for path_ref in [self.stg.load_path_ref(x) for x in
                         self.stg.load_path_ref_list(rnode['inputs'])]:
            path = path_ref['path']
            if not os.path.exists(path):  # pragma: branch_uncovered
                commands.mkdir(os.path.dirname(path))
                commands.copyfile(  # pragma: branch_uncovered
                    self.stg.get_blob_path(path_ref['digest']),
                    path)

    def get_output_files(self):
        """
        Get the output files of the recipe into the expected ouput paths.
        Get from the object storage, whether the file is present or not.
        """
        rnode = self.stg.load_recipe_node(self.recipe)
        for path_ref in [self.stg.load_path_ref(x) for x in
                         self.stg.load_path_ref_list(rnode['outputs'])]:
            path = path_ref['path']
            commands.mkdir(os.path.dirname(path))
            commands.copyfile(  # pragma: branch_uncovered
                self.stg.get_blob_path(path_ref['digest']),
                path)

class RecipeGraph():
    """
    A recipe graph class that holds all recipes and dependencies for a
    given recipe storage, recipes list, and expected targets list.
    The public interface for this class is:
    - write_makefile() : outputs a makefile for rebuilding the targets
    - get_targets() : get the list of inferred final targets
    - get_objects() : get the list of inferred objects
    - get_compilers() : get the list of involved compilers
    - get_lto_opts() : get the list of collected options to be passed to LTO
    - common_relative_profdir_prefix() : get the prefix path for profiling
    """
    def __init__(self, storage, recipes, expected_targets="all",
                 cwd=os.getcwd()):
        assert(isinstance(storage, RecipeStorage))
        assert(isinstance(recipes, list))
        assert(isinstance(expected_targets, list) or
               expected_targets == "last" or
               expected_targets == "all")
        assert(isinstance(cwd, str))
        self.stg = storage
        self.recipes = recipes
        self.cwd = cwd
        self.expected_targets = expected_targets
        self.final_targets_cache_ = None
        self.final_objects_cache_ = None
        self.final_compilers_cache_ = None
        self.build_deps_()

    def build_deps_(self):
        """
        Build the dependecy graph of recipes.
        The graph includes edges for input/output of commands in recipes_deps.
        It also includes additional edges used for serialization of executables
        and shared objects in recipe_xdeps.
        It also includes additional edges used for serialisation of outputs
        that share a common path (anti and output deps) in recipe_pdeps.
        """
        assert(isinstance(self.recipes, list))
        # Compute recipes inputs/outputs
        rnodes = dict([(x, self.stg.load_recipe_node(x))
                       for x in self.recipes])
        recipe_outputs = dict([(x[0],
                                self.stg.load_path_ref_list(x[1]['outputs']))
                               for x in rnodes.items()])
        recipe_inputs = dict([(x[0],
                               self.stg.load_path_ref_list(x[1]['inputs']))
                              for x in rnodes.items()])

        # Build recipes dependencies
        # Set .ROOT node dependent on recipes for which some output is not used
        # Set recipes for which some input is not seen dependent on .TAIL node
        recipe_deps = {'.ROOT': [], '.TAIL': []}
        inpref_recipes = {}
        for recipe in reversed([".TAIL"] + self.recipes):
            outrefs = (recipe_outputs[recipe] if recipe != ".TAIL"
                       else inpref_recipes.keys())
            inprefs = (recipe_inputs[recipe] if recipe != ".TAIL"
                      else [])
            for outref in outrefs:
                use_recipes = inpref_recipes.pop(outref, ['.ROOT'])
                for use_recipe in use_recipes:
                    if recipe not in recipe_deps[use_recipe]:
                        recipe_deps[use_recipe].insert(0, recipe)
            for inpref in inprefs:
                if inpref not in inpref_recipes:
                    inpref_recipes[inpref] = []
                inpref_recipes[inpref].append(recipe)
            recipe_deps[recipe] = []

        # We add extra deps between shared objects and programs as it
        # may cause issue if the shared objects dependencies are not correctly
        # tracked.
        recipe_xdeps = {'.ROOT': [], '.TAIL': []}
        last_exec = None
        for recipe in reversed(self.recipes):
            if self.is_exec_or_shared_(recipe):
                if last_exec != None:
                    recipe_xdeps[last_exec].append(recipe)
                last_exec = recipe
            recipe_xdeps[recipe] = []

        # We add additional deps between outputs that share the same path.
        # Actually we record all anti and output dependencies based on path.
        # TODO: do we need to distinguish xdeps and pdeps?
        recipe_pdeps = {'.ROOT': [], '.TAIL': []}
        last_output_recipes = {}
        for recipe in reversed(self.recipes):
            recipe_pdeps[recipe] = []
            for inpath in [self.stg.load_path_ref(x)['path'] for x in
                           recipe_inputs[recipe]]:
                last_recipe = last_output_recipes.get(inpath, None)
                if last_recipe != None:  # pragma: uncovered
                    recipe_pdeps[last_recipe].append(recipe)
            for outpath in [self.stg.load_path_ref(x)['path'] for x in
                            recipe_outputs[recipe]]:
                last_recipe = last_output_recipes.get(outpath, None)
                if last_recipe != None:  # pragma: uncovered
                    recipe_pdeps[last_recipe].append(recipe)
            for outpath in [self.stg.load_path_ref(x)['path'] for x in
                            recipe_outputs[recipe]]:
                last_output_recipes[outpath] = recipe

        self.recipe_deps = recipe_deps
        self.recipe_xdeps = recipe_xdeps
        self.recipe_pdeps = recipe_pdeps

    def get_recipe_deps_(self, node, xdeps=True):
        if xdeps: deps = (self.recipe_deps[node] +
                          self.recipe_xdeps[node] +
                          self.recipe_pdeps[node])
        else: deps = self.recipe_deps[node]
        return deps

    def get_dfs_recipes_(self, root=".ROOT", xdeps=True):
        def dfs_(current, seen, out):
            if current in seen: return
            seen.add(current)
            deps = self.get_recipe_deps_(current, xdeps)
            for recipe in deps:
                dfs_(recipe, seen, out)
            if current not in [".ROOT", ".TAIL"]:
                out.append(current)
            return out
        return dfs_(root, set(), [])

    def write_makefile(self, f, prefix="", root="all"):
        """
        Build the makefile from the recipe dependencies.
        Simply outputs recipes with an additional prefix to the
        commands if specified.
        It does a reverse dfs walk such that we have a topological sort
        of targets which makes the build more readable.
        For root targets, we only emit recipes that are actually
        final link or relocatable link targets.
        We explicitly serialize final link targets as the actual
        dependency between shared objects and executables for
        instance may not be always caught by the audit.
        TODO: currently the environment is not enforced at all, we
        should add an environment file and export it before the
        command execution.
        """
        # Note: did not report atos_deps.recipe_args() processing
        # which fixes some LD arguments, we should find a better
        # way. This only affect cases where we add .c files to a
        # pure link command, though this feature is not used in
        # current tools.
        final_targets = self.get_targets_recipes_()
        target_path_seen = set()
        f.write("SHELL=/bin/sh\n")
        f.write("QUIET=@\n")
        f.write("XDEPS=1\n")
        f.write("TARGET_XDEPS=0\n")
        f.write("FORCE=.FORCE\n")
        f.write("TARGETS=%s\n" % " ".join(final_targets))
        f.write(".SUFFIXES:\n")
        f.write(".PHONY: %s .ROOT .TAIL\n" % root)
        f.write("%s: .ROOT\n\n" % root)
        f.write(".ROOT: $(TARGETS)\n\n")
        for recipe in reversed(self.get_dfs_recipes_()):
            rnode = self.stg.load_recipe_node(recipe)
            deps = self.recipe_deps[recipe]
            pdeps = self.recipe_pdeps[recipe]
            xdeps = self.recipe_xdeps[recipe]
            if recipe in final_targets:
                # We add an explicit target for the last built target path
                # when it's a link (relocatable, shared object, executables).
                # The topological order including xdeps ensures that the
                # first we see is actually the last built when several
                # targets are built at the same path.
                path = self.stg.load_path_ref(
                    self.stg.load_path_ref_list(rnode['outputs'])[0])['path']
                if not path in target_path_seen:  # pragma: branch_uncovered
                    target_path_seen.add(path)
                    f.write("%s: $(FORCE)\n" % path)
                    f.write("\t$(QUIET)$(MAKE) -f $(MAKEFILE_LIST) "
                            "--no-print-directory XDEPS=$(TARGET_XDEPS) %s\n"
                            % recipe)

            f.write(".PHONY: %s\n" % recipe)
            if xdeps:
                f.write("%s_xdeps_1=%s\n" % (recipe, " ".join(xdeps)))
                f.write("%s_xdeps=$(%s_xdeps_$(XDEPS))\n" % (recipe, recipe))
                f.write(" ".join(["%s: $(%s_xdeps)" % (recipe, recipe)] +
                                 pdeps + deps)
                        + "\n")
            else:
                f.write(" ".join(["%s:" % recipe] + pdeps + deps) + "\n")
            cmd = self.stg.load_cmd_node(rnode['command'])
            f.write("\t$(QUIET)cd %s && %s %s\n\n" %
                    (list2cmdline([cmd['cwd']]), prefix,
                     list2cmdline(cmd['args'])))
        f.write(".TAIL:\n")
        f.write(".FORCE:\n")

    def is_exec_or_shared_(self, recipe):
        """
        Returns True is the output of the recipe is a linked shared object
        or an executable program.
        """
        if recipe in [".ROOT", ".TAIL"]:  # pragma: uncovered
            return False
        rnode = self.stg.load_recipe_node(recipe)
        cmd = self.stg.load_cmd_node(rnode['command'])
        interpreter = \
            CmdInterpreterFactory().get_interpreter(cmd, cmd['kind'])
        assert(interpreter != None)
        is_exec_or_shared = ((interpreter.get_kind() == "CC" or
                              interpreter.get_kind() == "LD") and
                             (interpreter.ccld_interpreter().has_final_link()))
        assert(not is_exec_or_shared or
               len(interpreter.ccld_interpreter().all_cc_outputs()) == 1)
        return is_exec_or_shared

    def is_reloc_(self, recipe):
        """
        Returns True is the output of the recipe is a relocatable object.
        """
        if recipe in [".ROOT", ".TAIL"]:  # pragma: uncovered
            return False
        rnode = self.stg.load_recipe_node(recipe)
        cmd = self.stg.load_cmd_node(rnode['command'])
        interpreter = \
            CmdInterpreterFactory().get_interpreter(cmd, cmd['kind'])
        assert(interpreter != None)
        is_reloc = ((interpreter.get_kind() == "CC" or
                     interpreter.get_kind() == "LD") and
                    (interpreter.ccld_interpreter().has_reloc_link()))
        assert(not is_reloc or
               len(interpreter.ccld_interpreter().all_cc_outputs()) == 1)
        return is_reloc

    def is_candidate_target_(self, recipe):
        """
        Returns True if the output of the recipe is a candidate target, i.e.
        a shared object, an executable or a relocatable object.
        The final target set is a subset of the candidate targets set.
        """
        has_link = (self.is_exec_or_shared_(recipe) or
                    self.is_reloc_(recipe))
        return has_link

    def target_match_(self, target, output_path):
        """
        Check if the output_path matches a target specification.
        There is a match as soon as target is a suffix of output_path.
        """
        assert(target != "")
        if os.path.dirname(target):
            target = os.path.normpath(
                os.path.join(self.cwd, target))
        idx = output_path.rfind(target)
        return idx >= 0 and idx + len(target) == len(output_path)

    def get_candidate_target_recipes_(self):
        """
        Returns all candidate targets recipes in a valid order of construction.
        The returned list is not yet filtered and may contain targets that
        are not final targets and are not in the expected targets list.
        The final target set is a subset of the candidate targets set.
        """
        return filter(self.is_candidate_target_,
                      self.get_dfs_recipes_())

    def get_targets(self):
        """
        Returns the list of targets paths in a valid order of construction.
        Note that there may be duplicate paths if a target path is built
        more than once.
        If expected_targets is given in the constructor,
        it filters out all targets output paths not in this list.
        Ref to target_match_() method called from get_targets_recipes_pair_().
        """
        return map(lambda x: x[0], self.get_targets_recipes_pairs_())

    def get_targets_recipes_(self):
        """
        Returns the list of selected targets recipes.
        """
        return map(lambda x: x[1], self.get_targets_recipes_pairs_())

    def get_targets_recipes_pairs_(self):
        """
        Build a filtered list of (output_path, target_recipe) pairs.
        The candidate targets (shared, exec, relocatables) are filtered
        to get the final targets list:
        - relocatable targets that are not leaf of the graph are filtered out
        - targets that do not match the expected target list are filtered out
        """
        if self.final_targets_cache_ != None:
            return self.final_targets_cache_
        last_target_pair = None
        targets_pairs = []
        root_recipes = self.get_recipe_deps_(".ROOT")
        for recipe in self.get_candidate_target_recipes_():
            rnode = self.stg.load_recipe_node(recipe)
            outrefs = self.stg.load_path_ref_list(rnode['outputs'])
            assert(len(outrefs) == 1)
            if self.is_reloc_(recipe) and recipe not in root_recipes:
                continue
            output_path = self.stg.load_path_ref(outrefs[0])['path']
            last_target_pair = (output_path, recipe)
            if isinstance(self.expected_targets, list):
                matches = filter(lambda x: self.target_match_(x, output_path),
                                 self.expected_targets)
            if (self.expected_targets == "all" or
                isinstance(self.expected_targets, list) and matches):
                targets_pairs.append(last_target_pair)
        if self.expected_targets == "last" and last_target_pair:
            targets_pairs.append(last_target_pair)
        self.final_targets_cache_ = targets_pairs
        return self.final_targets_cache_

    def get_objects(self):
        """
        Returns the list of objects paths in a valid order of construction.
        Note that there may be duplicate paths if an object path is built
        more than once.
        """
        return map(lambda x: x[0], self.get_objects_recipes_triplets_())

    def get_objects_recipes_(self):
        """
        Returns the list of selected objects recipes.
        """
        return map(lambda x: x[1], self.get_objects_recipes_triplets_())

    def get_objects_recipes_triplets_(self):
        """
        Returns a list of triplets (output_path, recipe, target_recipe).
        """
        if self.final_objects_cache_ != None:
            return self.final_objects_cache_
        objects_triplets = []
        for target_recipe in self.get_targets_recipes_():
            for recipe in self.get_dfs_recipes_(root=target_recipe,
                                               xdeps=False):
                rnode = self.stg.load_recipe_node(recipe)
                cmd = self.stg.load_cmd_node(rnode['command'])
                interpreter = \
                    CmdInterpreterFactory().get_interpreter(cmd, cmd['kind'])
                assert(interpreter != None)
                if interpreter.get_kind() != "CC": continue
                has_cc = interpreter.ccld_interpreter().has_cc_phase("CC")
                has_link = (interpreter.ccld_interpreter().has_final_link() or
                            interpreter.ccld_interpreter().has_reloc_link())
                if has_cc and not has_link:
                    outrefs = self.stg.load_path_ref_list(rnode['outputs'])
                    for x in outrefs:
                        triplet = (self.stg.load_path_ref(x)['path'],
                                   recipe, target_recipe)
                        if (triplet not in  # pragma: branch_uncovered
                            objects_triplets):
                            objects_triplets.append(triplet)
        self.final_objects_cache_ = objects_triplets
        return self.final_objects_cache_

    def get_compilers(self):
        """
        Returns the list of compilers used in recipes that are compiler
        drivers (i.e. CC interpreters) and have a CC phase or a final
        link phase.
        TODO: check whether we really need to filter phase ot just need
        to get all CC interpreters.
        """
        if self.final_compilers_cache_ != None:
            return self.final_compilers_cache_
        compilers = []
        for recipe in (self.get_objects_recipes_() +
                       self.get_targets_recipes_()):
            rnode = self.stg.load_recipe_node(recipe)
            cmd = self.stg.load_cmd_node(rnode['command'])
            interpreter = \
                CmdInterpreterFactory().get_interpreter(cmd, cmd['kind'])
            assert(interpreter != None)
            if interpreter.get_kind() != "CC":  # pragma: uncovered
                continue
            has_cc = interpreter.ccld_interpreter().has_cc_phase("CC")
            has_final_link = interpreter.ccld_interpreter().has_final_link()
            if has_cc or has_final_link:  # pragma: branch_uncovered
                compiler = cmd['arg0']
                if not compiler in compilers: compilers.append(compiler)
        self.final_compilers_cache_ = compilers
        return self.final_compilers_cache_

    def get_lto_opts(self):
        """
        Get the list of options that should be passed to linker
        in case of LTO build.
        TODO: a duplicate of atos_deps.get_lto_opts for the moment,
        should move all this into a specific class or into
        the CCInterpreter class.
        """
        def is_lto_opt(arg):
            return (arg.startswith('-m') or arg.startswith('-f')
                    or arg.startswith('-O'))

        optflags = {}
        for target_recipe in self.get_targets_recipes_():
            rnode_target = self.stg.load_recipe_node(target_recipe)
            target_path = self.stg.load_path_ref(
                self.stg.load_path_ref_list(
                    rnode_target['outputs'])[0])['path']
            for recipe in self.get_dfs_recipes_(root=target_recipe,
                                               xdeps=False):
                rnode = self.stg.load_recipe_node(recipe)
                cmd = self.stg.load_cmd_node(rnode['command'])
                interpreter = \
                    CmdInterpreterFactory().get_interpreter(cmd, cmd['kind'])
                assert(interpreter != None)
                if interpreter.get_kind() != "CC": continue
                if interpreter.ccld_interpreter().has_cc_phase("CC"):
                    optflags.setdefault(target_path, [])
                    optflags[target_path].extend(
                        [x for x in interpreter.get_args()[1:]
                         if is_lto_opt(x) and x not in optflags[target_path]])
        return optflags

    def common_relative_profdir_prefix(self):
        """
        Get the common path prefix of all targets of cc commands designated
        with a relative path.
        TODO: a duplicate of atos_deps.common_relative_profdir_prefix
        for the moment,  should move all this into a specific class or into
        the CCInterpreter class.
        """
        outputs = []
        for recipe in (self.get_objects_recipes_() +
                       self.get_targets_recipes_()):
            rnode = self.stg.load_recipe_node(recipe)
            cmd = self.stg.load_cmd_node(rnode['command'])
            interpreter = \
                CmdInterpreterFactory().get_interpreter(cmd, cmd['kind'])
            assert(interpreter != None)
            if interpreter.get_kind() != "CC":  # pragma: uncovered
                continue
            if interpreter.ccld_interpreter().has_cc_phase("CC"):
                # We must use the unmodified output arguments of the
                # CC command line, not the normalized one returned by
                # value.outputs() for instance.
                cc_outputs = interpreter.ccld_interpreter().all_cc_outputs()
                # In case of multiple outputs in CC phases, all outputs are
                # in the same directory, thus the first one is sufficient
                # though it's a TODO to handle multiple outputs
                assert(len(cc_outputs) >= 1)
                output = cc_outputs[0]
                if os.path.isabs(output): continue
                outputs.extend(interpreter.get_output_files())
                # no common prefix longer than cwd
                outputs.append(cmd['cwd'])
        return os.path.commonprefix(outputs)

    @staticmethod
    def test():  # pragma: uncovered (ignore test funcs)
        print "TESTING RecipeManager..."
        tmpdir = tempfile.mkdtemp()
        try:
            stgdir = os.path.join(tmpdir, "stg")
            stg = RecipeStorage(stgdir)
            stg.init_recipes_file()
            with open(os.path.join(tmpdir, "a.c"), "w") as f:
                f.write("int main() { return foo(); }\n")
            with open(os.path.join(tmpdir, "b.c"), "w") as f:
                f.write("int foo() { return 0; }\n")
            with open(os.path.join(tmpdir, "c.c"), "w") as f:
                f.write("int foo() { return 1; }\n")
            prog = "/usr/bin/gcc"
            envs = {'PATH': "/usr/bin:/bin", 'HOME': "/home/undef"}
            cwd = tmpdir
            for base in ["a", "b", "c"]:
                src = "%s.c" % base
                args = ["gcc", "-c", src]
                inps_digest = stg.store_path_ref_list([
                    os.path.join(tmpdir, src)])
                cnod_digest = stg.store_cmd_node(prog, cwd, args, envs, "CC")
                if subprocess.Popen(args, cwd=cwd, env=envs).wait() != 0:
                    return False
                outs_digest = stg.store_path_ref_list([
                    os.path.join(tmpdir, "%s.o" % base)])
                rnod_digest = stg.store_recipe_node(
                    cnod_digest, inps_digest, outs_digest)
                print "%s rnod %s" % (base, rnod_digest)
                stg.append_recipes_file(rnod_digest)
                cnod = stg.load_obj(cnod_digest)
                env = stg.load_envs(cnod['envs'])
                print "env", env
                recipe_node = RecipeNode(stg, rnod_digest, cwd)
                recipe_node.fetch_input_files()
                recipe_node.get_output_files()
                # commands.unlink(os.path.join(tmpdir, src))
                # recipe_node.fetch_input_files()

            assert not stg.blacklist_recipes()
            stg.blacklist_init()
            print "blacklist_path", stg.blacklist_path()
            stg.blacklist_append(rnod_digest)
            print "blacklist_recipes", stg.blacklist_recipes()
            assert stg.blacklist_contains(rnod_digest)

            for dest, objs in (("main.exe", ("a.o", "b.o")),
                               ("main2.exe", ("a.o", "c.o"))):
                args = ["gcc", "-o", dest] + list(objs)
                inps_digest = stg.store_path_ref_list(
                    [os.path.join(tmpdir, x) for x in objs])
                cnod_digest = stg.store_cmd_node(prog, cwd, args, envs, "CC")
                if subprocess.Popen(args, cwd=cwd, env=envs).wait() != 0:
                    return False
                outs_digest = stg.store_path_ref_list([
                        os.path.join(tmpdir, dest)])
                rnod_digest = stg.store_recipe_node(
                    cnod_digest, inps_digest, outs_digest)
                print "%s rnod %s" % (dest, rnod_digest)
                stg.append_recipes_file(rnod_digest)

            graph = RecipeManager(stg).recipe_graph()
            # Test compilers (2 times for testing cache)
            for i in range(2):
                deep_eq(graph.get_compilers(), ['/usr/bin/gcc'],
                        _assert=True)
            # Test targets (2 times for testing cache)
            for i in range(2):
                deep_eq(graph.get_targets(),
                        map(lambda x: '%s/%s' % (tmpdir, x),
                            ['main.exe', 'main2.exe']),
                        _assert=True)
            # Test objects (2 times for testing cache)
            for i in range(2):
                deep_eq(graph.get_objects(),
                        map(lambda x: '%s/%s' % (tmpdir, x),
                            ['a.o', 'b.o',
                             'a.o', 'c.o']),
                        _assert=True)
            deep_eq(graph.get_compilers(), ['/usr/bin/gcc'], _assert=True)

            mkfile = os.path.join(tmpdir, "Makefile")
            with open(mkfile, "w") as f:
                graph.write_makefile(f)
            with open(mkfile, "r") as f:
                print f.read()
            if subprocess.Popen(["make", "-j8"],
                                cwd=cwd, env=envs).wait() != 0:
                return False
        finally:
            shutil.rmtree(tmpdir)
        print "SUCCESS RecipeManager"
        return True

if __name__ == "__main__":
    passed = RecipeGraph.test()
    if not passed: sys.exit(1)
