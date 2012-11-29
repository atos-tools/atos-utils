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


class re_utils():
    """
    Namespace for regexp check and conversion functions.
    The regexps accepted by audit tools have to be
    converted to Posix basic regexps for the PRoot
    plugins.
    This class provides static methods for converting
    python regexps into Posix regexps.
    """

    @staticmethod
    def re_check(regexp):
        """
        Check that a regexp is acceptable for conversion
        to Posix regexps.
        Actually does the conversion and check if it is ok.
        """
        return re_utils.re_to_cregexp(regexp) != None

    @staticmethod
    def re_to_cregexp(regexp):
        """
        Transform a python regexp to a POSIX
        basic regexp for the regcomp(3) function.
        We do support only \,.,?,*,+,|,(,),^,$
        regexp chars.
        """
        cnoquote = ['?', '+', '|', '(', ')']
        cquote = ['\\', '.', '*', '^', '$']
        cregexp = ""
        i = 0
        while i < len(regexp):
            if regexp[i] == '\\':
                if i + 1 >= len(regexp):
                    return None
                if regexp[i + 1] in cquote:
                    cregexp += '\\' + regexp[i + 1]
                elif regexp[i + 1] in cnoquote:
                    # C regexps do not need backquote
                    # for some backquoted in python
                    cregexp += regexp[i + 1]
                else:
                    return None
                i += 2
            else:
                if regexp[i] in cnoquote:
                    # C regexps always backquote some
                    # special regexp chars that do not
                    # need backquote in python
                    cregexp += "\\" + regexp[i]
                else:
                    cregexp += regexp[i]
                i += 1
        return cregexp

    @staticmethod
    def test():
        print "TESTING re_utils..."
        t = re_utils.re_check("string")
        assert(t)
        t = re_utils.re_check("\\U")
        assert(not t)
        t = re_utils.re_check("\\")
        assert(not t)
        t = re_utils.re_to_cregexp("\\\\\\.\\*\\^\\$")
        assert(t == "\\\\\\.\\*\\^\\$")
        t = re_utils.re_to_cregexp("\\?\\+\\(\\)\\|")
        assert(t == "?+()|")
        t = re_utils.re_to_cregexp(
            "^(clang|(.+-)?gcc|(.+-)?g\+\+|.*cc|.*c\+\+)$")
        assert(t == "^\(clang\|\(.\+-\)\?gcc"
               "\|\(.\+-\)\?g++\|.*cc\|.*c++\)$")
        print "SUCCESS re_utils..."
        return True

if __name__ == "__main__":
    passed = re_utils.test()
    if not passed: sys.exit(1)
