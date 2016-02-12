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

class DGraph:
    """
    A class implementing a directed graph.
    """
    def __init__(self):
        self.nodes_succs_ = {}
        self.edges_attrs_ = {}
        self.nodes_attrs_ = {}

    def add_node(self, node, attrs=None):
        assert(node not in self.nodes_attrs_)
        if attrs == None: attrs = []
        self.nodes_attrs_[node] = attrs
        # Some edges may have been created before
        # the actual node insertion
        if node not in self.nodes_succs_:
            self.nodes_succs_[node] = []

    def has_node(self, node):
        return node in self.nodes_attrs_

    def del_node(self, node):
        assert(node in self.nodes_attrs_)
        for (edge, _) in self.edges_attrs_.items():
            src, dst = edge
            if src == node or dst == node:
                self.nodes_succs_[src].remove(dst)
                self.edges_attrs_.pop(edge)
        self.nodes_succs_.pop(node)
        self.nodes_attrs_.pop(node)

    def add_edge(self, src, dst, attrs=None):
        edge = (src, dst)
        assert(edge not in self.edges_attrs_)
        if attrs == None: attrs = []
        self.edges_attrs_[edge] = attrs
        if src not in self.nodes_succs_:
            self.nodes_succs_[src] = []
        self.nodes_succs_[src].append(dst)

    def has_edge(self, src, dst):
        edge = (src, dst)
        return edge in self.edges_attrs_

    def del_edge(self, src, dst):
        edge = (src, dst)
        assert(edge in self.edges_attrs_)
        self.edges_attrs_.pop(edge)
        self.nodes_succs_[src].remove(dst)

    def nodes(self):
        return self.nodes_attrs_.keys()

    def edges(self):
        return self.edges_attrs_.keys()

    def succs(self, node):
        return self.nodes_succs_[node]

    def nodes_attrs(self):
        return self.nodes_attrs_

    def edges_attrs(self):
        return self.edges_attrs_

    def node_attrs(self, node):
        return self.nodes_attrs_[node]

    def edge_attrs(self, edge):
        return self.edges_attrs_[edge]

    def set_node_attrs(self, node, attrs):
        assert(node in self.nodes_attrs_)
        if attrs == None: attrs = []
        self.nodes_attrs_[node] = attrs

    def set_edge_attrs(self, edge, attrs):
        assert(edge in self.edges_attrs_)
        if attrs == None: attrs = []
        self.edges_attrs_[edge] = attrs

    @staticmethod
    def test():
        def print_graph():
            print "test graph:"
            for node in dg.nodes():
                print "node: %s : " % str(node),
                print " ".join(
                    [str(x) for x in dg.node_attrs(node)]) + " : ",
                print " ".join(dg.succs(node))
            for edge in dg.edges():
                print "edge: %s :" % str(edge),
                print " ".join([str(x) for x in dg.edge_attrs(edge)])

        print "TESTING DGraph..."
        dg = DGraph()
        print_graph()
        dg.add_node('ROOT')
        dg.add_node('./file1.o', [
                ('target', 'file1.o'), ('srcs', ['file1.c', 'file3.h'])])
        dg.add_node('./file2.o', [
                ('target', 'file2.o'), ('srcs', ['file2.c', 'file3.h'])])
        assert(len(dg.nodes_attrs()) == 3)
        assert(len(dg.nodes_succs_) == 3)
        assert(len(dg.nodes()) == 3)
        assert(len(dg.edges()) == 0)
        dg.add_edge('./main.exe', './file1.o')
        dg.add_edge('./main.exe', './file2.o')
        dg.add_edge('./file2.o', './file3.h')
        dg.add_edge('./file1.o', './file3.h')
        assert(len(dg.edges_attrs()) == 4)
        assert(len(dg.edges()) == 4)
        assert(len(dg.nodes_attrs()) == 3)
        assert(len(dg.nodes_succs_) == 4)
        assert(len(dg.succs('./main.exe')) == 2)
        assert(dg.succs('./main.exe')[0] == './file1.o')
        assert(len(dg.nodes_succs_['./file2.o']) == 1)
        dg.add_node('./file3.h', [
                ('target', 'file3.h'), ('srcs', ['file3.h.in'])])
        dg.add_node('./main.exe')
        dg.add_edge('ROOT', './main.exe')
        assert(len(dg.edges_attrs()) == 5)
        assert(len(dg.nodes_succs_) == 5)
        assert(len(dg.nodes_attrs()) == 5)
        dg.set_node_attrs('./main.exe', [('target', 'main.exe'),
                                         ('srcs', ['file1.o', 'file2.o'])])
        dg.set_edge_attrs(('ROOT', './main.exe'),
                          [('kind', 'phony')])
        print_graph()
        if dg.has_node('./file1.o'): dg.del_node('./file1.o')
        assert(len(dg.edges_attrs()) == 3)
        assert(len(dg.nodes_succs_) == 4)
        assert(len(dg.nodes_attrs()) == 4)
        dg.del_edge('ROOT', './main.exe')
        assert(len(dg.edges_attrs()) == 2)
        assert(len(dg.nodes_succs_) == 4)
        assert(len(dg.nodes_attrs()) == 4)
        print_graph()
        print "SUCCESS DGraph"
        return True

if __name__ == "__main__":
    passed = DGraph.test()
    if not passed: sys.exit(1)
