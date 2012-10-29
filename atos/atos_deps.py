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
# Usage: get usage with atos-deps -h
#

import sys, os, re

import globals
import atos_lib

VERBOSE = 0

class DGraph:
    """ A class implementing a directed graph.  """
    def __init__(self):
        self.nodes_ = {}
        self.edges_ = {}
        self.node_attrs_ = {}
        return

    def add_node(self, node, attrs=None):
        if attrs == None: attrs = []
        self.nodes_[node] = node
        self.node_attrs_[node] = attrs

    def has_node(self, node):
        return node in self.nodes_

    def del_node(self, node):
        for (edge, val) in self.edges_.items():
            (src, dst) = edge
            if src == node or dst == node:
                self.edges_.pop((src, dst))
        self.nodes_.pop(node)
        self.node_attrs_.pop(node)

    def add_edge(self, edge):
        self.edges_[edge] = edge

    def has_edge(self, edge):
        return edge in self.edges_

    def del_edge(self, edge):
        self.edges_.pop(edge)

    def nodes(self):
        return list(self.nodes_)

    def edges(self):
        return list(self.edges_)

    def neighbors(self, node):
        neighbors = []
        for (src, dst) in self.edges_:
            if src == node:
                neighbors.append(dst)
        return neighbors

    def node_attrs(self):
        return self.node_attrs_

class DGraphTest:
    """ Test class for DGraph. Test with DGraphTest().test(). """
    def __init__(self):
        self.dg = DGraph()

    def test(self):
        def print_graph():
            print "test graph:"
            for node in self.dg.nodes():
                print "node: " + node + " : ",
                print " ".join(
                    [str(x) for x in self.dg.node_attrs()[node]]) + " : ",
                print " ".join(self.dg.neighbors(node))
            print "edges: " + " ".join([str(x) for x in self.dg.edges()])
        print_graph()
        self.dg.add_node('ROOT')
        self.dg.add_node('./file1.o', [
                ('target', 'file1.o'), ('srcs', ['file1.c', 'file3.h'])])
        self.dg.add_node('./file2.o', [
                ('target', 'file2.o'), ('srcs', ['file2.c', 'file3.h'])])
        self.dg.add_edge(('./main.exe', './file1.o'))
        self.dg.add_edge(('./main.exe', './file2.o'))
        self.dg.add_edge(('./file2.o', './file3.h'))
        self.dg.add_edge(('./file1.o', './file3.h'))
        self.dg.add_node('./file3.h', [
                ('target', 'file3.h'), ('srcs', ['file3.h.in'])])
        self.dg.add_node('./main.exe', [
                ('target', 'main.exe'), ('srcs', ['file1.o', 'file2.o'])])
        self.dg.add_edge(('ROOT', './main.exe'))
        print_graph()
        if self.dg.has_node('./file1.o'): self.dg.del_node('./file1.o')
        if self.dg.has_edge(('ROOT', './main.exe')):
            self.dg.del_edge(('ROOT', './main.exe'))
        print_graph()


class DependencyGraph:
    """ A class implementing a dependency graph. """
    def __init__(self, dg=None):
        """ Constructor. Optionally pass a Dgraph as argument.  """
        global VERBOSE
        self.dg = dg
        if self.dg == None:
            self.dg = DGraph()
        self.verbose = VERBOSE

    def add_node(self, node, attrs=None):
        """ Add a node. """
        if self.verbose:
            print "ADD_NODE: " + node
        self.dg.add_node(node, attrs=attrs)

    def del_node(self, node):
        """ Delete a node and related edges. """
        self.dg.del_node(node)

    def has_node(self, node):
        """ Returns whether the graph contains the node. """
        return self.dg.has_node(node)

    def add_edge(self, src, dst):
        """ Add an edge. """
        if self.verbose:
            print "ADD_EDGE: " + src + " " + dst
        self.dg.add_edge((src, dst))

    def del_edge(self, src, dst):
        """ Delete an edge. """
        self.dg.del_edge((src, dst))

    def has_edge(self, src, dst):
        """ Returns whether the graph contains the edge. """
        return self.dg.has_edge((src, dst))

    def nodes(self):
        """ Returns the list of nodes. """
        return self.dg.nodes()

    def edges(self):
        """ Returns the list of edges. """
        return self.dg.edges()

    def graph(self):
        """ Get the graph as a nodes, edges map. """
        return {'nodes': self.nodes(), 'edges': self.edges()}

    def node_attributes(self):
        """ Get the node attributes. """
        return self.dg.node_attrs()

    def get_makedep(self):
        """ Get a makefile like output. """
        mk = ""
        for node in self.dg.nodes():
            mk = mk + node + ": " + " ".join(self.dg.neighbors(node)) + "\n"
        return mk

    def get_targets(self):
        """ Get the list of targets. """
        targets = []
        for node in self.dg.neighbors("ROOT"):
            for attr, value in self.node_attributes()[node]:
                if attr == "target":
                    targets.append(value)
        return targets

    def get_objects(self):
        """ Get the list of object files. """
        objects = []
        for node in self.dg.nodes():
            target = None
            dep = None
            for attr, value in self.node_attributes()[node]:
                if attr == "target":
                    target = value
                if attr == "dependency":
                    dep = value
            if dep and dep['kind'] == "CC":
                objects.append(target)
        return objects

    def get_lto_opts(self):
        """ Get the list of options that should be passed to linker
        in case of LTO build. """
        def is_lto_opt(arg):
            return (arg.startswith('-m') or arg.startswith('-f')
                    or arg.startswith('-O'))
        optflags = []
        for node in self.dg.nodes():
            for attr, value in self.node_attributes()[node]:
                if attr != 'dependency' or value['kind'] != 'CC': continue
                optflags += [x for x in value['command']['args']
                             if is_lto_opt(x) and x not in optflags]
        return optflags

    def common_relative_profdir_prefix(self):
        """ Get the common path prefix of all targets of cc commands designated
        with a relative path. """
        outputs = []
        for node in self.dg.nodes():
            for attr, value in self.node_attributes()[node]:
                if attr != 'dependency': continue
                if value['kind'] == 'CCLD':
                    # consider that gcda files can be generated in cwd
                    # (CCLD commands could be ignored here if no source
                    #  files in input)
                    outputs.append(value['command']['cwd'])
                elif value['kind'] == 'CC':
                    output_value = atos_lib.get_output_option_value(
                        value['command']['args'])
                    # ignore output if designated with an absolute path
                    # (profdir will be prof_dir/full_path)
                    if output_value and os.path.isabs(output_value): continue
                    outputs.extend(value['outputs'])
                    # no common prefix longer than cwd
                    outputs.append(value['command']['cwd'])
                else: pass
        return os.path.commonprefix(outputs)

    def get_profdir_suffix(self, value):
        """ Get the profile dir suffix for a CC/CCLD dependency """
        if not hasattr(self, 'common_profdir_prefix_len'):
            self.common_profdir_prefix_len = len(
                self.common_relative_profdir_prefix())
        if value['kind'] == "CC":
            output_value = atos_lib.get_output_option_value(
                value['command']['args'])
            if output_value and os.path.isabs(output_value): return ''
        if value['kind'] == "CC" or value['kind'] == "CCLD":
            return value['command']['cwd'][self.common_profdir_prefix_len:]
        else: assert 0

    def get_compilers(self):
        """ Get the list of compilers. """
        compilers = set()
        for node in self.dg.nodes():
            for attr, value in self.node_attributes()[node]:
                if attr != 'dependency' or value['kind'] not in ["CC", "CCLD"]:
                    continue
                compilers.add(value['command']['arg0'])
        return list(compilers)

    def recipe_args(self, dependency):
        """ Fixup some options that may not support mixed .c and .o files. """
        # TODO: we may build a response file when detecting large lines
        args = dependency['command']['args']
        i = 0
        new_args = []
        while i < len(args):
            m = re.search("^--hash-style", args[i])
            if m != None:
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
        for node in self.dg.nodes():
            target = node
            recipe = None
            for attr, value in self.node_attributes()[node]:
                if attr == "target":
                    target = value
                if attr == "dependency":
                    # TODO: handle quotes in command
                    recipe = (
                        "$(QUIET)cd " + value['command']['cwd'] +
                        " && $(ATOS_DRIVER) " +
                        " ".join(self.recipe_args(value)))
                    recipe = re.sub(r'(["\'])', r'\\\1', recipe)
            deps = []
            for dep in self.dg.neighbors(node):
                for attr, value in self.node_attributes()[dep]:
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
        m = re.search(os.path.normpath(target) + "$", output)
        return m != None

    def build_graph(self):
        """ Builds Add a dependency consisting of a node
        and input/output lists. """
        self.graph.add_node("ROOT")
        referenced_outputs = set()
        if self.targets == "all" or self.targets == "last":
            for i in range(len(self.deplist)):
                dependency = self.deplist[len(self.deplist) - i - 1]
                if len(dependency['outputs']) != 1:
                    continue
                if dependency['kind'] == "CCLD" and len(dependency[
                        'outputs']) == 1:
                    referenced_outputs.add(dependency['outputs'][0])
                    if self.targets == "last":
                        break
            targets = list(referenced_outputs)
        else:
            targets = self.targets
        unmatched_targets = targets[:]  # keep targets untouched
        available_inputs = set()
        last_target_node = None
        referenced_outputs = set()

        for i in range(len(self.deplist)):
            dependency = self.deplist[len(self.deplist) - i - 1]
            if len(dependency['outputs']) != 1:
                continue
            output = dependency['outputs'][0]
            found = False
            for target in unmatched_targets:
                if self.target_match(target, output):
                    if output in referenced_outputs:
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
                    for inp in dependency['inputs']:
                        available_inputs.add(inp)
                        if not self.graph.has_node(inp):
                            self.graph.add_node(inp, attrs=[('target', inp)])
                        if not self.graph.has_edge(output, inp):
                            self.graph.add_edge(output, inp)
            if not found:
                if output in available_inputs:
                    if output in referenced_outputs:
                        raise Exception(
                            "Output file referenced several times: " + output)
                    referenced_outputs.add(output)
                    available_inputs.remove(output)
                    if not self.graph.has_node(output):
                        raise Exception(
                            "Expected to have seen output in dependencies: " +
                            output)
                    self.graph.node_attributes()[output] = [
                        ('target', output), ('dependency', dependency)]
                    for inp in dependency['inputs']:
                        available_inputs.add(inp)
                        if not self.graph.has_node(inp):
                            self.graph.add_node(inp, attrs=[('target', inp)])
                        if not self.graph.has_edge(output, inp):
                            self.graph.add_edge(output, inp)
        # Check for unmatched targets
        if len(unmatched_targets) > 0:
            for target in unmatched_targets:
                print >> sys.stderr, "warning: unmatched target executable, " \
                    "will not be optimized: " + target
        # Prune nodes with no recipe (remove speculated inputs)
        for node in self.graph.nodes():
            if node == "ROOT":
                continue
            real = False
            for attr, value in self.graph.node_attributes()[node]:
                if attr == "dependency":
                    real = True
            if not real:
                self.graph.del_node(node)

    def get_graph(self):
        """ Returns the dependency graph. """
        return self.graph

class DependencyListBuilder:
    """ Class for building dependency list. """
    def __init__(self):
        """ Constructor. """
        self.deps = []

    def add_dependency(self, command, kind, inputs, outputs):
        """ Add a dependency consisting of a node and input/output lists. """
        dependency = {'command': command, 'kind': kind,
                      'inputs': inputs, 'outputs': outputs}
        self.deps.append(dependency)

    def get_dependencies(self):
        """ Returns the dependency list. """
        return self.deps

class SimpleCmdInterpreter:
    """ Returns information on a command line for compilations tools. """
    def __init__(self):
        """ Constructor. """

    def select_interpreter(self, command):
        """ Returns a suitable interpreter for the given command. """
        basename = os.path.basename(command['args'][0])
        # TODO: put these regexps in a configuration file
        m = re.search(globals.DEFAULT_DRIVER_CC_PYREGEXP, basename)
        if m != None and m.group(1) != None:
            return SimpleCCInterpreter(command)
        m = re.search(globals.DEFAULT_DRIVER_AR_PYREGEXP, basename)
        if m != None and m.group(1) != None:
            return SimpleARInterpreter(command)
        raise Exception("unrecognized command: " + basename)

    def get_kind(self, command):
        """ Get command kind from command line args. """
        return self.select_interpreter(command).get_kind()

    def get_input_files(self, command):
        """ Get input files from command line args. """
        return self.select_interpreter(command).get_input_files()

    def get_output_files(self, command):
        """ Get output files from command line args. """
        return self.select_interpreter(command).get_output_files()

class SimpleCCInterpreter:
    """ Returns information on a command line for a CC compiler driver.
    There are a number of limitations:
    - only well known extensions are searched for input files
    - output file is matched only in case of -o option, no stdout support
    """
    def __init__(self, command):
        """ Constructor. """
        self.command = command
        self.kind = None
        self.input_files = None
        self.output_files = None
        self.expanded_args = None

    def get_expanded_args(self):
        """ Returns the exanded args list, after response file expansion. """
        if self.expanded_args == None:
            self.expanded_args = atos_lib.expand_response_file(
                self.command['args'])
        return self.expanded_args

    def get_kind(self):
        """ Returns the command kind. """
        if self.kind != None:
            return self.kind
        args = self.get_expanded_args()
        kind = "CCLD"
        for i in range(len(args[1:])):
            m = re.search("^(-c)$", args[i + 1])
            if m != None:
                kind = "CC"
        self.kind = kind
        return kind

    def get_input_files(self):
        """ Get input files from a CC command line args
        (C/C++ sources or object files). """
        if self.input_files != None:
            return self.input_files
        kind = self.get_kind()
        args = self.get_expanded_args()
        cwd = self.command['cwd']
        static_link = False
        inputs = []
        lpath = []
        i = 0
        while i + 1 < len(args):
            i = i + 1
            m = re.search("^-o(.*)$", args[i])
            if m != None:
                if m.group(1) == "":
                    i = i + 1
                continue
            m = re.search("\\.(c|cc|cxx|cpp|c\+\+|C|i|ii|o|os|a)$", args[i])
            if m != None:
                inputs.append(os.path.normpath(os.path.join(cwd, args[i])))
                continue
            if kind == "CCLD" and args[i] == "-static":
                static_link = True
                continue
            m = re.search("^-L(.*)$", args[i])
            if kind == "CCLD" and m != None:
                path = m.group(1)
                if path == "":
                    if i + 1 < len(args):
                        path = args[i + 1]
                if path != "":
                    lpath.append(os.path.normpath(os.path.join(cwd, path)))
                continue
            m = re.search("^-l(.*)$", args[i])
            if kind == "CCLD" and m != None:
                lib = m.group(1)
                if lib == "":
                    if i + 1 < len(args):
                        lib = args[i + 1]
                    i = i + 1
                if lib != "":
                    for path in lpath:
                        # TODO: this way of finding archives is approximate, we
                        # should use an enhanced PRoot plugin for detecting
                        # actual dependencies at build audit time.
                        file_base = os.path.join(path, "lib" + lib)
                        if not static_link and os.access(
                                file_base + ".so", os.R_OK):
                            # Skip shared objects for now
                            break
                        if os.access(file_base + ".a", os.R_OK):
                            inputs.append(file_base + ".a")
                            break
                continue
        self.input_files = inputs
        return inputs

    def get_output_files(self):
        """ Get output files from CC command line args. """
        if self.output_files != None:
            return self.output_files
        args = self.get_expanded_args()
        cwd = self.command['cwd']
        output = atos_lib.get_output_option_value(args)
        outputs = [
            os.path.normpath(os.path.join(cwd, output))] if output else []
        if len(outputs) == 0 and len(self.get_input_files()) > 0:
            if self.get_kind() == "CC":
                outputs = []
                for inp in self.get_input_files():
                    outputs.append(os.path.normpath(os.path.join(cwd, re.sub(
                                    "\\.[^.]+$", ".o",
                                    os.path.basename(inp)))))
            elif self.get_kind() == "CCLD":
                outputs = [os.path.normpath(os.path.join(cwd, "a.out"))]
            else:
                raise Exception(
                    "Can't determine output from input files in command: " +
                    str(self.command))
        self.output_files = outputs
        return outputs


class SimpleARInterpreter:
    """ Returns information on a command line for a AR archiver.
    There are a number of limitations:
    - only .o files are searched for input
    - only 'ar ...r... input_files...' form is recognized
    """
    def __init__(self, command):
        """ Constructor. """
        self.command = command
        self.input_files = None
        self.output_files = None
        self.expanded_args = None

    def get_expanded_args(self):
        """ Returns the exanded args list, after response file expansion. """
        if self.expanded_args == None:
            self.expanded_args = atos_lib.expand_response_file(
                self.command['args'])
        return self.expanded_args

    def get_kind(self):
        """ Returns the command kind. """
        return "AR"

    def get_input_files(self):
        """ Get input files from AR command line (object files only). """
        if self.input_files != None:
            return self.input_files
        args = self.get_expanded_args()
        cwd = self.command['cwd']
        inputs = []
        for i in range(len(args[1:])):
            m = re.search("\\.(o)$", args[i + 1])
            if m != None and m.group(1) != None and i >= 2:
                    inputs.append(
                        os.path.normpath(os.path.join(cwd, args[i + 1])))
        self.input_files = inputs
        return inputs

    def get_output_files(self):
        """ Get output file from AR command line args. """
        if self.output_files != None:
            return self.output_files
        args = self.get_expanded_args()
        cwd = self.command['cwd']
        outputs = []
        update = False
        for i in range(len(args[1:])):
            if i == 0:
                m = re.search("r", args[i + 1])
                if m != None:
                    update = True
            elif i == 1 and update:
                outputs = [os.path.normpath(os.path.join(cwd, args[i + 1]))]
            else:
                break
        self.outputs = outputs
        return outputs

class CommandDependencyListFactory:
    """ Creates a build dependency from a command parser and a
    command interpreter. """
    def __init__(self, parser, interpreter):
        """ Constructor. """
        self.deps = DependencyListBuilder()
        self.parser = parser
        self.interpreter = interpreter

    def get_dependencies(self):
        """ Returns the build dependencies. """
        return self.deps.get_dependencies()

    def build_dependencies(self):
        """ Compute dependencies.  """
        self.parser.parse()
        commands = self.parser.get_commands()
        for command in commands:
            input_files = self.interpreter.get_input_files(command)
            output_files = self.interpreter.get_output_files(command)
            kind = self.interpreter.get_kind(command)
            self.deps.add_dependency(command, kind, input_files, output_files)

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
