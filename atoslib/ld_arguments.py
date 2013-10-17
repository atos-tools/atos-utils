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

import sys
import re

class LDArgumentsDesc:

    # Output kind as inferred from the command line, with mapping
    # to cc_phase name for generating it or None.
    output_phase = {
        'nooutput': None,       # Command kind is LD --version for instance
        'relocatable': "LD",    # Command kind is LD -r
        'executable': "LD"      # Command kind is LD without -r
        }

    # Executable kind as inferred from command line, with
    # mapping to link kind, one of "LDMAIN" or "LDSO"
    exec_kind = {
        'program': "LDMAIN",    # Command kind is LD
        'shared': "LDSO",       # Command kind is LD -shared
        }

    # Options description as a list of map.
    # Note that the list is not exhaustive, though
    # all options with floating argument should be
    # specified such that actual input files can
    # be inferred.
    # re: regexp for the option
    # nargs: arguments number, 0 or 1 [default: 0]
    # next: True if option argument is necessarily
    # the next argument (i.e. cannot be joined) [default: False]
    # sep: optional separator between option and argument,
    # mandatory if specified [default: None]
    # optsep: optional separator between option and argument,
    # if not present, argument is next [default: None]
    # action: function to call [default: None]
    options_desc = [
        # Overall options
        # Ref: http://linux.die.net/man/1/ld
        {'re': r"@.*"},  # response file: treated separately
        {'str': "-a", 'nargs': 1, 'dest': "opt_a"},
        {'str': "--audit", 'nargs': 1, 'optsep': "="},
        {'str': "-A", 'nargs': 1},
        {'str': "--architecture", 'nargs': 1, 'optsep': "="},
        {'str': "-b", 'nargs': 1},
        {'str': "--format", 'nargs': 1, 'optsep': "="},
        {'str': "-c", 'nargs': 1},
        {'str': "--mri-script", 'nargs': 1, 'optsep': "="},
        {'str': "-d"},
        {'str': "-dc"},
        {'str': "-dp"},
        {'str': "-P", 'nargs': 1},
        {'str': "--depaudit", 'nargs': 1, 'optsep': "="},
        {'str': "-e", 'nargs': 1},
        {'str': "--entry", 'nargs': 1, 'optsep': "="},
        {'str': "--exclude-libs", 'nargs': 1, 'optsep': "="},
        {'str': "--exclude-modules-for-implib", 'nargs': 1, 'optsep': "="},
        {'str': "-E"},
        {'str': "--export-dynamic"},
        {'str': "--no-export-dynamic"},
        {'str': "-EB"},
        {'str': "-EL"},
        {'str': "-f", 'nargs': 1},
        {'str': "--auxiliary", 'nargs': 1, 'optsep': "="},
        {'str': "-F", 'nargs': 1},
        {'str': "--filter", 'nargs': 1, 'optsep': "="},
        {'str': "--fini", 'nargs': 1, 'optsep': "="},
        {'str': "-g"},
        {'str': "-G", 'nargs': 1},
        {'str': "--gpsize", 'nargs': 1, 'optsep': "="},
        {'str': "-h", 'nargs': 1},
        {'str': "--soname", 'nargs': 1, 'optsep': "="},
        {'str': "-i", 'dest': "opt_r"},
        {'str': "-l", 'nargs': 1, 'dest': "opt_l"},
        {'str': "--library", 'nargs': 1, 'optsep': "=", 'dest': "opt_l"},
        {'str': "-L", 'nargs': 1, 'dest': "opt_L"},
        {'str': "--library-path", 'nargs': 1, 'optsep': "=", 'dest': "opt_L"},
        {'str': "-m", 'nargs': 1},
        {'str': "-M"},
        {'str': "--print-map"},
        {'str': "-n"},
        {'str': "--nmagic"},
        {'str': "-N"},
        {'str': "--omagic"},
        {'str': "--no-omagic"},
        {'str': "-o", 'nargs': 1, 'dest': "opt_o"},
        {'str': "--output", 'nargs': 1, 'optsep': "=", 'dest': "opt_o"},
        {'str': "-O", 'nargs': 1},
        {'str': "-q", 'nargs': 1},
        {'str': "--emit-relocs", 'nargs': 1, 'optsep': "="},
        {'str': "--force-dynamic"},
        {'str': "-r", 'dest': "opt_r"},
        {'str': "--relocatable", 'dest': "opt_r"},
        {'str': "-R", 'nargs': 1},
        {'str': "--just-symbols", 'nargs': 1, 'optsep': "="},
        {'str': "-s"},
        {'str': "--strip-all"},
        {'str': "-S"},
        {'str': "--strip-debug"},
        {'str': "-t"},
        {'str': "--trace"},
        {'str': "-T", 'nargs': 1},
        {'str': "--script", 'nargs': 1, 'optsep': "="},
        {'str': "-dT", 'nargs': 1},
        {'str': "--default-script", 'nargs': 1, 'optsep': "="},
        {'str': "-u", 'nargs': 1},
        {'str': "--undefined", 'nargs': 1, 'optsep': "="},
        {'str': "-Ur"},
        {'str': "--unique"},
        {'re': r"--unique=.*"},
        {'str': "-v", 'dest': "opt_version"},
        {'str': "-V", 'dest': "opt_version"},
        {'str': "--version", 'dest': "opt_version"},
        {'str': "-x"},
        {'str': "--discard-all"},
        {'str': "-X"},
        {'str': "--discard-locals"},
        {'str': "-y", 'nargs': 1},
        {'str': "--trace-symbol", 'nargs': 1, 'optsep': "="},
        {'str': "-Y", 'nargs': 1, 'dest': "opt_L"},
        {'str': "-z", 'nargs': 1},
        {'str': "-\("},  # need \ as str is used in a regexp
        {'str': "--start-group"},
        {'str': "-\)"},  # need \ as str is used in a regexp
        {'str': "--end-group"},
        {'str': "--accept-unknown-input-arch"},
        {'str': "--no-accept-unknown-input-arch"},
        {'str': "--as-needed"},
        {'str': "--no-as-needed"},
        {'str': "--add-needed"},
        {'str': "--no-add-needed"},
        {'str': "-assert", 'nargs': 1},
        {'str': "-Bdynamic", 'dest': "opt_dynamic"},
        {'str': "-dy", 'dest': "opt_dynamic"},
        {'str': "-call_shared", 'dest': "opt_dynamic"},
        {'str': "-Bgroup"},
        {'str': "-Bstatic", 'dest': "opt_static"},
        {'str': "-dn", 'dest': "opt_static"},
        {'str': "-non_shared", 'dest': "opt_static"},
        {'str': "-static", 'dest': "opt_static"},
        {'str': "-Bsymbolic"},
        {'str': "-Bsymbolic-functions"},
        {'str': "--dynamic-list", 'nargs': 1, 'optsep': "="},
        {'str': "--dynamic-list-data"},
        {'str': "--dynamic-list-cpp-new"},
        {'str': "--dynamic-list-cpp-typeinfo"},
        {'str': "--check-sections"},
        {'str': "--no-check-sections"},
        {'str': "--copy-dt-needed-entries"},
        {'str': "--no-copy-dt-needed-entries"},
        {'str': "--cref"},
        {'str': "--no-define-common"},
        {'str': "--defsym", 'nargs': 1, 'optsep': "="},
        {'str': "--demangle"},
        {'re': r"--demangle=.*"},
        {'str': "--no-demangle"},
        {'str': "-I", 'nargs': 1},
        {'str': "--dynamic-linker", 'nargs': 1, 'optsep': "="},
        {'str': "--fatal-warnings"},
        {'str': "--no-fatal-warnings"},
        {'str': "--force-exe-suffix"},
        {'str': "--gc-sections"},
        {'str': "--no-gc-sections"},
        {'str': "--print-gc-sections"},
        {'str': "--no-print-gc-sections"},
        {'str': "--help", 'dest': "opt_help"},
        {'str': "--target-help", 'dest': "opt_help"},
        {'str': "-Map", 'nargs': 1, 'optsep': "="},
        {'str': "--no-keep-memory"},
        {'str': "--no-undefined"},
        # -z defs: subsummed by -z arg
        {'str': "--allow-multiple-definition"},
        # -z muldefs: subsummed by -z arg
        {'str': "--allow-shlib-undefined"},
        {'str': "--no-allow-shlib-undefined"},
        {'str': "--no-undefined-version"},
        {'str': "--default-symver"},
        {'str': "--default-imported-symver"},
        {'str': "--no-warn-mismatch"},
        {'str': "--no-warn-search-mismatch"},
        {'str': "--no-whole-archive"},
        {'str': "--noinhibit-exec"},
        {'str': "-nostdlib"},
        {'str': "--oformat", 'nargs': 1, 'optsep': "="},
        {'str': "-pie"},
        {'str': "--pic-executable"},
        {'str': "-qmagic"},
        {'str': "-Qy"},
        {'str': "--relax"},
        {'str': "--retain-symbols-file", 'nargs': 1, 'optsep': "="},
        {'str': "-rpath", 'nargs': 1, 'optsep': "="},
        {'str': "-rpath-link", 'nargs': 1, 'optsep': "="},
        {'str': "-shared", 'dest': "opt_shared"},
        {'str': "-Bshareable", 'dest': "opt_shared"},
        {'str': "--sort-common"},
        {'re': r"--sort-common=.*"},
        {'str': "--sort-section", 'nargs': 1, 'optsep': "="},
        {'str': "--split-by-file"},
        {'re': r"--split-by-file=.*"},
        {'str': "--split-by-reloc"},
        {'re': r"--split-by-reloc=.*"},
        {'str': "--stats"},
        {'str': "--sysroot", 'nargs': 1, 'optsep': "="},
        {'str': "--traditional-format"},
        {'str': "--section-start", 'nargs': 1, 'optsep': "="},
        {'str': "-Tbss", 'nargs': 1, 'optsep': "="},
        {'str': "-Tdata", 'nargs': 1, 'optsep': "="},
        {'str': "-Ttext", 'nargs': 1, 'optsep': "="},
        {'str': "-Ttext-segment", 'nargs': 1, 'optsep': "="},
        {'str': "--unresolved-symbols", 'nargs': 1, 'optsep': "="},
        {'str': "--verbose"},
        {'str': "--dll-verbose"},
        {'str': "--version-script", 'nargs': 1, 'optsep': "="},
        {'str': "--warn-common"},
        {'str': "--warn-constructors"},
        {'str': "--warn-multiple-gp"},
        {'str': "--warn-once"},
        {'str': "--warn-section-align"},
        {'str': "--warn-shared-textrel"},
        {'str': "--warn-alternate-em"},
        {'str': "--warn-unresolved-symbols"},
        {'str': "--error-unresolved-symbols"},
        {'str': "--whole-archive"},
        {'str': "--wrap", 'nargs': 1, 'optsep': "="},
        {'str': "--eh-frame-hdr"},
        {'str': "--enable-new-dtags"},
        {'str': "--disable-new-dtags"},
        {'str': "--hash-size", 'nargs': 1, 'optsep': "="},
        {'str': "--hash-style", 'nargs': 1, 'optsep': "="},
        {'str': "--reduce-memory-overheads"},
        {'str': "--build-id"},
        {'re': r"--build-id=.*"},

        # Other unknown options
        {'re': r"-.*", 'dest': "opt_other"},
        ]

    @staticmethod
    def test():
        print "TESTING LDArgumentsDesc..."
        args_desc = LDArgumentsDesc
        str_set = set()
        for desc in args_desc.options_desc:
            assert(isinstance(desc, dict))
            for key in desc:
                assert(key in ['str', 're', 'nargs', 'sep', 'optsep',
                               'next', 'dest'])
            assert('re' in desc or 'str' in desc)
            assert(not ('re' in desc and 'str' in desc))
            assert('nargs' not in desc or (
                    desc['nargs'] == 0 or desc['nargs'] == 1))
            assert('dest' not in desc or isinstance(desc['dest'], str))
            assert('sep' not in desc or isinstance(desc['sep'], str))
            assert('optsep' not in desc or isinstance(desc['optsep'], str))
            assert('next' not in desc or isinstance(desc['next'], bool))
            assert(not ('nargs' in desc and desc['nargs'] == 0) or not (
                    'sep' in desc or 'optsep' in desc or 'next' in desc))
            assert(not ('sep' in desc and 'optsep' in desc))
            assert(not ('sep' in desc and 'next' in desc))
            assert(not ('optsep' in desc and 'next' in desc))
            if 'str' in desc:
                assert(desc['str'] not in str_set)
                str_set.add(desc['str'])
                assert(re.match(r"--?[\w\D][-\w]*", desc['str']))
            # Check that str or re can compile
            if 'str' in desc: re.compile(desc['str'])
            if 're' in desc: re.compile("^%s$" % desc['re'])
        print "SUCCESS LDArgumentsDesc"
        return True

if __name__ == "__main__":
    passed = LDArgumentsDesc.test()
    if not passed: sys.exit(1)
