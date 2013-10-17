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

import sys, os, re

import globals
import atos_lib
import process
from graphs import DGraph

class DependencyGraph(DGraph):
    """
    A class implementing a dependency graph.
    """
    def graph(self):  # pragma: uncovered
        """ Get the graph as a nodes, edges map. """
        return {'nodes': self.nodes(), 'edges': self.edges()}

    def get_makedep(self):  # pragma: uncovered
        """ Get a makefile like output. """
        mk = ""
        for node in self.nodes():
            mk = mk + node + ": " + " ".join(self.succs(node)) + "\n"
        return mk

    def get_targets(self):
        """ Get the list of targets. """
        targets = []
        for node in self.succs("ROOT"):
            for attr, value in self.node_attrs(node):
                if attr == "target":
                    targets.append(value)
        return targets

    def get_objects(self):
        """ Get the list of object files. """
        objects = []
        for node in self.nodes():
            target = None
            dep = None
            for attr, value in self.node_attrs(node):
                if attr == "target":
                    target = value
                if attr == "dependency":
                    dep = value
            if (dep and dep.kind() == "CC" and
                dep.interpreter().ccld_interpreter().has_cc_phase("CC") and
                dep.interpreter().ccld_interpreter().last_cc_phase() == "AS"):
                objects.append(target)
        return objects

    def get_lto_opts(self):
        """ Get the list of options that should be passed to linker
        in case of LTO build. """
        def is_lto_opt(arg):
            return (arg.startswith('-m') or arg.startswith('-f')
                    or arg.startswith('-O'))
        optflags = []
        for node in self.nodes():
            for attr, value in self.node_attrs(node):
                if (attr == 'dependency' and value.kind() == "CC" and
                    value.interpreter().ccld_interpreter().has_cc_phase("CC")):
                    optflags += [x for x in
                                 value.interpreter().get_args()[1:]
                                 if is_lto_opt(x) and x not in optflags]
        optflags_dict = dict(map(lambda x: (x, optflags), self.get_targets()))
        return optflags_dict

    def common_relative_profdir_prefix(self):
        """
        Get the common path prefix of all targets of cc commands designated
        with a relative path.
        """
        outputs = []
        for node in self.nodes():
            for attr, value in self.node_attrs(node):
                if attr != 'dependency' or value.kind() != "CC":
                    continue
                if value.interpreter().ccld_interpreter().has_cc_phase("CC"):
                    # We must use the unmodified output arguments of the
                    # CC command line, not the normalized one returned by
                    # value.outputs() for instance.
                    cc_outputs = \
                        value.interpreter().ccld_interpreter().all_cc_outputs()
                    # In case of multiple outputs in CC phases, all outputs are
                    # in the same directory, thus the first one is sufficient
                    # though it's a TODO to handle multiple outputs
                    assert(len(cc_outputs) >= 1)
                    output = cc_outputs[0]
                    if os.path.isabs(output): continue
                    outputs.extend(value.outputs())
                    # no common prefix longer than cwd
                    outputs.append(value.command()['cwd'])
        return os.path.commonprefix(outputs)

    def get_compilers(self):
        """ Get the list of compilers. """
        compilers = set()
        for node in self.nodes():
            for attr, value in self.node_attrs(node):
                if (attr != 'dependency' or
                    value.kind() != "CC"):
                    continue
                compilers.add(value.command()['arg0'])
        return list(compilers)

    def recipe_args(self, dependency):
        """ Fixup some options that may not support mixed .c and .o files. """
        # TODO: we should uses interpreter.args() after response
        # file expansion and build a response file when detecting
        # large lines
        args = dependency.command()['args']
        i = 0
        new_args = []
        while i < len(args):
            m = re.search("^--hash-style", args[i])
            if m != None:  # pragma: uncovered
                new_args.append("-Wl," + args[i])
            else:
                new_args.append(args[i])
            i = i + 1
        return new_args

    def output_makefile(self, makefile):
        """ Get a parallelizable makefile for rebuilding the target. """
        mkfile = open(makefile, "w")
        mkfile.write("#!/usr/bin/make -f\n")
        mkfile.write("SHELL=/bin/sh\n")
        mkfile.write("FORCE=FORCE\n")
        mkfile.write("QUIET=@\n")
        mkfile.write(".PHONY: ROOT all\n")
        mkfile.write(".SUFFIXES:\n")
        mkfile.write("all: ROOT\n")
        mkfile.write("FORCE:\n")
        # TODO: may include per target/file flags,
        #       a better solution should be implemented
        #mkfile.write("MAKEDIR:=$(dir $(MAKEFILE_LIST))\n")
        #mkfile.write("-include $(MAKEDIR)/build-target-flags.mk\n")
        #mkfile.write("-include $(MAKEDIR)/build-file-flags.mk\n")
        mkfile.write("\n")
        for node in self.nodes():
            target = node
            recipe = None
            for attr, value in self.node_attrs(node):
                if attr == "target":
                    target = value
                if attr == "dependency":
                    recipe = (
                        "$(QUIET)cd " + value.command()['cwd'] +
                        " && $(ATOS_DRIVER) " +
                        process.list2cmdline(self.recipe_args(value)))
            deps = []
            for dep in self.succs(node):
                for attr, value in self.node_attrs(dep):
                    if attr == "target":
                        deps.append(value)
            mkfile.write(target + ": $(FORCE) " + " ".join(deps) + "\n")
            if recipe == None:
                mkfile.write("\n")
            else:
                mkfile.write("\t" + recipe + "\n")
        mkfile.close()

class DependencyGraphBuilder:
    """ Class for building dependency list. """
    def __init__(self, deplist, targets):
        """ Constructor. Takes a DependencyList as argument
        and a list of output_file targets. """
        self.graph = DependencyGraph()
        self.deplist = deplist
        self.targets = targets

    def target_match(self, target, output):
        """ Check if output matches a target.
        Assume that target is a suffix of output. """
        m = re.search(re.escape(os.path.normpath(target)) + "$", output)
        return m != None

    def build_graph(self):
        """ Builds Add a dependency consisting of a node
        and input/output lists. """
        self.graph.add_node("ROOT")
        referenced_outputs = set()
        if (self.targets == "all" or self.targets == "last"
            ):  # pragma: branch_uncovered
            for i in range(len(self.deplist)):
                dependency = self.deplist[len(self.deplist) - i - 1]
                if (dependency.kind() == "CC" and
                    (dependency.interpreter().ccld_interpreter().
                     is_ld_kind("program") or
                     dependency.interpreter().ccld_interpreter().
                     is_ld_kind("shared"))):
                    assert(len(dependency.outputs()) == 1)
                    referenced_outputs.add(dependency.outputs()[0])
                    if self.targets == "last":  # pragma: uncovered
                        break
            targets = list(referenced_outputs)
        else:  # pragma: uncovered
            targets = self.targets
        unmatched_targets = targets[:]  # keep targets untouched
        available_inputs = set()
        last_target_node = None
        referenced_outputs = set()

        for i in range(len(self.deplist)):
            dependency = self.deplist[len(self.deplist) - i - 1]
            if len(dependency.outputs()) != 1:  # pragma: uncovered
                # TODO: should handle multiple outputs
                continue
            output = dependency.outputs()[0]
            found = False
            for target in unmatched_targets:
                if self.target_match(target, output):
                    if output in referenced_outputs:
                        # TODO: should allow multiple references
                        raise Exception(
                            "Output file referenced several times: " + output)
                    unmatched_targets.remove(target)
                    found = True
                    referenced_outputs.add(output)
                    self.graph.add_node(output, attrs=[
                            ('target', output), ('dependency', dependency)])
                    self.graph.add_edge("ROOT", output)
                    # Ensure that targets are serialized, this ensure that
                    # shared libraries are compiled before executables as for
                    # now we do not track shared lib dependencies
                    if last_target_node:
                        self.graph.add_edge(last_target_node, output)
                    last_target_node = output
                    for inp in dependency.inputs():
                        available_inputs.add(inp)
                        if not self.graph.has_node(inp):
                            self.graph.add_node(inp, attrs=[('target', inp)])
                        if not self.graph.has_edge(  # pragma: branch_uncovered
                            output, inp):
                            self.graph.add_edge(output, inp)
            if not found:
                if output in available_inputs:  # pragma: branch_uncovered
                    if output in referenced_outputs:
                        # TODO: should allow multiple references
                        raise Exception(
                            "Output file referenced several times: " + output)
                    referenced_outputs.add(output)
                    available_inputs.remove(output)
                    if not self.graph.has_node(output):
                        raise Exception(
                            "Expected to have seen output in dependencies: " +
                            output)
                    self.graph.set_node_attrs(output,
                                              [('target', output),
                                               ('dependency', dependency)])
                    for inp in dependency.inputs():
                        available_inputs.add(inp)
                        if not self.graph.has_node(inp):
                            self.graph.add_node(inp, attrs=[('target', inp)])
                        if not self.graph.has_edge(  # pragma: branch_uncovered
                            output, inp):
                            self.graph.add_edge(output, inp)
        # Check for unmatched targets
        if len(unmatched_targets) > 0:  # pragma: uncovered (error)
            for target in unmatched_targets:
                print >> sys.stderr, "warning: unmatched target executable, " \
                    "will not be optimized: " + target
        # Prune nodes with no recipe (remove speculated inputs)
        for node in self.graph.nodes():
            if node == "ROOT":
                continue
            real = False
            for attr, value in self.graph.node_attrs(node):
                if attr == "dependency":
                    real = True
            if not real:
                self.graph.del_node(node)

    def get_graph(self):
        """ Returns the dependency graph. """
        return self.graph

class Dependency:
    """
    Class representing a build command dependency.
    """
    def __init__(self, command, interpreter):
        assert(interpreter.is_wellformed())
        self.command_ = command
        self.interpreter_ = interpreter

    def kind(self):
        """
        Returns dependency recipe kind as returned by the command
        interpreter.
        """
        return self.interpreter_.get_kind()

    def outputs(self):
        """
        Returns dependency recipe outputs as returned by the command
        interpreter.
        """
        return self.interpreter_.get_output_files()

    def inputs(self):
        """
        Returns dependency recipe inputs as returned by the command
        interpreter.
        """
        return self.interpreter_.get_input_files()

    def command(self):
        """
        Returns the associated command.
        """
        return self.command_

    def interpreter(self):
        """
        Returns the associated command interpreter.
        """
        return self.interpreter_

class DependencyListBuilder:
    """ Class for building dependency list. """
    def __init__(self):
        """ Constructor. """
        self.deps = []

    def add_dependency(self, command, interpreter):
        """
        Add a dependency, i.e. a command and its associated interpreter.
        """
        self.deps.append(Dependency(command, interpreter))

    def get_dependencies(self):
        """ Returns the dependency list. """
        return self.deps

class CommandDependencyListFactory:
    """
    Creates a build dependency list from a command parser and a
    command interpreter factory.
    """
    def __init__(self, parser, interp_factory):
        """ Constructor. """
        self.deps_ = DependencyListBuilder()
        self.parser_ = parser
        self.interp_factory_ = interp_factory

    def get_dependencies(self):
        """ Returns the build dependencies. """
        return self.deps_.get_dependencies()

    def build_dependencies(self):
        """ Compute dependencies.  """
        self.parser_.parse()
        for command in self.parser_.get_commands():
            interpreter = self.interp_factory_.get_interpreter(command)
            if not (interpreter and interpreter.is_wellformed()
                    ):  # pragma: uncovered
                continue
            # Filter commands that we need for dependencies
            # TODO: for now we do not support separate CC and AS
            # compilation. I.e. objects built like this will not be
            # optimized.
            if (interpreter.get_kind() == "AR" or  # pragma: branch_uncovered
                interpreter.get_kind() == "CC" and
                (interpreter.ccld_interpreter().has_cc_phase("CC") or
                 interpreter.ccld_interpreter().has_cc_phase("LD"))):
                self.deps_.add_dependency(command, interpreter)

class CCDEPSParser:
    """ Parses the output of a cc_deps addon file. """
    def __init__(self, input_file):
        """ Constructor, takes the input_file as argument. """
        self.input_file = input_file
        self.commands = []

    def parse(self):
        """ Parses the input_file. """
        for line in self.input_file:
            self.commands.append(self.parse_line(line))

    def parse_line(self, line):
        """ Parses a single input_file. """
        try:
            m = re.search(
                "^CC_DEPS: \"([^\"]*)\": (.*): : \"([^\"]*)\"$", line)
            arg0 = m.group(1)
            args = m.group(2)
            cwd = m.group(3)
            len(arg0)
            len(args)
            len(cwd)
        except Exception:
            raise Exception("unexpected cc_deps command line: " + line)
        arg_list = args.split(", ")
        command = {'arg0': arg0, 'args': [], 'cwd': cwd}
        for arg in arg_list:
            try:
                m = re.search("^\"(.*)\"$", arg)
                opt = m.group(1)
                len(opt)
            except Exception:
                raise Exception("unexpected argument in command: " + arg)
            command['args'].append(opt)
        if len(command['args']) == 0:
            raise Exception("unexpected empty command: " + str(arg_list))
        return command

    def get_commands(self):
        """ Returns the constructed command list.  """
        return self.commands
