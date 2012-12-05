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

import re

class CCArgumentsDesc:
    # Source kind as inferred by the compiler.
    # Ref: http://gcc.gnu.org/onlinedocs/gcc/Overall-Options.html
    # desc: textual description of the source kind
    # re: regular expression matching the file suffix
    source_kind = {
        'SRC_C': {
            'desc': "C source code",
            're': r".*\.c"},
        'SRC_I': {
            'desc': "C source code, should not be preprocessed",
            're': r".*\.i"},
        'SRC_II': {
            'desc': "C++ source code, should not be preprocessed",
            're': r".*\.ii"},
        'SRC_M': {
            'desc': "Objective-C source code",
            're': r".*\.m"},
        'SRC_MI': {
            'desc': "Objective-C source code, should not be preprocessed",
            're': r".*\.mi"},
        'SRC_MM': {
            'desc': "Objective-C++ source code",
            're': r".*\.(mm|M)"},
        'SRC_MII': {
            'desc': "Objective-C++ source code, should not be preprocessed",
            're': r".*\.mii"},
        'SRC_H': {
            'desc': "C, C++, Objective-C or Objective-C++ header file to be "
            "turned into a precompiled header or ADA spec",
            're': r".*\.h"},
        'SRC_CC': {
            'desc': "C++ source code",
            're': r".*\.(cc|cp|cxx|cpp|CPP|c\+\+|C)"},
        'SRC_HH': {
            'desc': "C++ header file to be turned into a precompiled header "
            "or ADA spec",
            're': r".*\.(hh|H|hp|hxx|hpp|HPP|h\+\+|tcc)"},
        'SRC_F': {
            'desc': "Fortran source code, should not be preprocessed",
            're': r".*\.(f|for|ftn)"},
        'SRC_FPP': {
            'desc': "Fortran source code, , should be preprocessed",
            're': r".*\.(F|FOR|fpp|FPP|FTN)"},
        'SRC_F9X': {
            'desc': "Free form fortran source code, should not be "
            "preprocessed",
            're': r".*\.(f90|f95|f03|f08)"},
        'SRC_FPP9X': {
            'desc': "Free form fortran source code, , should be preprocessed",
            're': r".*\.(F90|F95|F03|F08)"},
        'SRC_GO': {
            'desc': "GO source code",
            're': r".*\.go"},
        'SRC_ADS': {
            'desc': "ADA library unit declaration",
            're': r".*\.ads"},
        'SRC_ADB': {
            'desc': "ADA library unit body",
            're': r".*\.adb"},
        'SRC_S': {
            'desc': "Assembler source code",
            're': r".*\.s"},
        'SRC_SPP': {
            'desc': "Assembler source code, should be preprocessed",
            're': r".*\.(S|sx)"},
        'SRC_JAVA': {
            'desc': "Java source code",
            're': r".*\.java"},
        }

    # Phase lists common to some source files
    cc_phases = ["CPP", "CC", "AS", "LD"]
    as_phases = ["CPP", "AS", "LD"]

    # Mapping from C/C++/ASM source kinds to consuming phases.
    cc_source_phases = {'SRC_C': cc_phases,
                        'SRC_CC': cc_phases,
                        'SRC_SPP': as_phases,
                        'SRC_I': cc_phases[1:],
                        'SRC_II': cc_phases[1:],
                        'SRC_S': cc_phases[2:],
                        'SRC_LNK': cc_phases[3:]
                        }

    # Output kind as inferred from the command line, with mapping
    # to cc_phase name for generating it or None.
    output_phase = {
        'nooutput': None,       # Command kind is CC --version for instance
        'preprocessed': "CPP",  # Command kind is CC -E
        'assembly': "CC",       # Command kind is CC -S
        'object': "AS",	        # Command kind is CC -c
        'relocatable': "LD",    # Command kind is CC -r
        'executable': "LD",     # Command kind is CC without any of -E/-c/-S
        'dependencies': None    # Command kind is CC -M / CC -MM
        }

    # Executable kind as inferred from command line, with
    # mapping to link kind, one of "CCLDMAIN" or "CCLDSO"
    exec_kind = {
        'program': "CCLDMAIN",  # Command kind is CC
        'shared': "CCLDSO",     # Command kind is CC -shared
        }

    # Languages as understood by the -x language option.
    # Ref: http://gcc.gnu.org/onlinedocs/gcc/Overall-Options.html
    # kind: source kind key from source_kind map.
    language_kind = {
        'c': "SRC_C",
        'c-header': "SRC_H",
        'cpp-output': "SRC_I",
        'c++': "SRC_CC",
        'c++-header': "SRC_HH",
        'c++cpp-output': "SRC_II",
        'objective-c': "SRC_M",
        'objective-c-header': "SRC_H",
        'objective-c-cpp-output': "SRC_MI",
        'objective-c++': "SRC_MM",
        'objective-c++-header': "SRC_H",
        'objective-c++-cpp-output': "SRC_MII",
        'assembler': "SRC_S",
        'assembler-with-cpp': "SRC_SPP",
        'ada': "SRC_ADB",
        'f77': "SRC_F",
        'f77-cpp-input': "SRC_FPP",
        'f95': "SRC_F9X",
        'f95-cpp-input': "SRC_FPP9X",
        'go': "SRC_GO",
        'java': "SRC_JAVA"
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
        # Ref: http://gcc.gnu.org/onlinedocs/gcc/Overall-Options.html
        {'str': "-x", 'nargs': 1, 'dest': "opt_x"},
        {'str': "-c", 'dest': "opt_c"},
        {'str': "-S", 'dest': "opt_S"},
        {'str': "-E", 'dest': "opt_E"},
        {'str': "-o", 'nargs': 1, 'dest': "opt_o"},
        {'str': "-r", 'dest': "opt_r"},
        {'str': "-pass-exit-codes"},
        {'str': "-v"},
        {'str': "-###"},
        {'str': "-pipe"},
        {'str': "--help", 'dest': "opt_help"},
        {'str': "--target-help", 'dest': "opt_help"},
        {'re': r"--help=.*", 'dest': "opt_help"},
        {'str': "-no-canonical-prefixes"},
        {'str': "--version", 'dest': "opt_version"},
        {'str': "-wrapper", 'nargs': 1, 'next': True},
        {'str': "-fplugin", 'nargs': 1, 'sep': "="},
        {'re': r"-fplugin-arg-.*", 'nargs': 1, 'sep': "="},
        {'str': "-fdump-ada-spec"},
        {'str': "-fdump-ada-spec-slim"},
        {'str': "-fdump-go-spec", 'nargs': 1, 'sep': "="},
        {'re': r"@.*", 'dest': "opt_response_file"},

        # Options Controlling C Dialect
        # http://gcc.gnu.org/onlinedocs/gcc/C-Dialect-Options.html
        {'str': "-ansi"},
        {'str': "-std", 'nargs': 1, 'sep': "="},
        {'str': "-fgnu89-inline"},
        {'str': "-aux-info", 'nargs': 1, 'optsep': "="},
        {'str': "-fallow-parameterless-variadic-functions"},
        {'str': "-fno-asm"},
        {'str': "-fno-builtin"},
        {'re': r"-fno-builtin-.*"},
        {'str': "-fhosted"},
        {'str': "-ffreestanding"},
        {'str': "-fopenmp"},
        {'str': "-fgnu-tm"},
        {'str': "-fms-extensions"},
        {'str': "-fplan9-extensions"},
        {'str': "-trigraphs"},
        {'str': "-traditional"},
        {'str': "-traditional-cpp"},
        {'str': "-fcond-mismatch"},
        {'str': "-flax-vector-conversions"},
        {'str': "-funsigned-char"},
        {'str': "-fsigned-char"},
        {'str': "-fsigned-bitfields"},
        {'str': "-funsigned-bitfields"},
        {'str': "-fno-signed-bitfields"},
        {'str': "-fno-unsigned-bitfields"},

        # Options Controlling C++ Dialect
        # http://gcc.gnu.org/onlinedocs/gcc/C_002b_002b-Dialect-Options.html
        {'re': r"-fabi-version=.*"},
        {'str': "-fno-access-control"},
        {'str': "-fcheck-new"},
        {'re': r"-fconstexpr-depth=.*"},
        {'str': "-ffriend-injection"},
        {'str': "-fno-elide-constructors"},
        {'str': "-fno-enforce-eh-specs"},
        {'str': "-ffor-scope"},
        {'str': "-fno-for-scope"},
        {'str': "-fno-gnu-keywords"},
        {'str': "-fno-implicit-templates"},
        {'str': "-fno-implicit-inline-templates"},
        {'str': "-fno-implement-inlines"},
        # {'str': "-fms-extensions"}, # Also present in C dialect options
        {'str': "-fno-nonansi-builtins"},
        {'str': "-fnothrow-opt"},
        {'str': "-fno-operator-names"},
        {'str': "-fno-optional-diags"},
        {'str': "-fpermissive"},
        {'str': "-fno-pretty-templates"},
        {'str': "-frepo"},
        {'str': "-fno-rtti"},
        {'str': "-fstats"},
        {'re': r"-ftemplate-backtrace-limit=.*"},
        {'re': r"-ftemplate-depth=.*"},
        {'str': "-fno-threadsafe-statics"},
        {'str': "-fuse-cxa-atexit"},
        {'str': "-fno-weak"},
        {'str': "-nostdinc\+\+"},
        {'str': "-fno-default-inline"},
        {'str': "-fvisibility-inlines-hidden"},
        {'str': "-fvisibility-ms-compat"},
        {'str': "-fext-numeric-literals"},
        {'str': "-Wabi"},
        {'str': "-Wconversion-null"},
        {'str': "-Wctor-dtor-privacy"},
        {'str': "-Wdelete-non-virtual-dtor"},
        {'str': "-Wliteral-suffix"},
        {'str': "-Wnarrowing"},
        {'str': "-Wnoexcept"},
        {'str': "-Wnon-virtual-dtor"},
        {'str': "-Wreorder"},
        {'str': "-Weffc\+\+"},
        {'str': "-Wstrict-null-sentinel"},
        {'str': "-Wno-non-template-friend"},
        {'str': "-Wold-style-cast"},
        {'str': "-Woverloaded-virtual"},
        {'str': "-Wno-pmf-conversions"},
        {'str': "-Wsign-promo"},

        # Options Controlling Objective C/C++ Dialect
        # http://gcc.gnu.org/onlinedocs/gcc/
        # Objective_002dC-and-Objective_002dC_002b_002b-Dialect-Options.html
        {'re': r"-fconstant-string-class=.*"},
        {'str': "-fgnu-runtime"},
        {'str': "-fnext-runtime"},
        {'str': "-fno-nil-receivers"},
        {'re': r"-fobjc-abi-version=.*"},
        {'str': "-fobjc-call-cxx-cdtors"},
        {'str': "-fobjc-direct-dispatch"},
        {'str': "-fobjc-exceptions"},
        {'str': "-fobjc-gc"},
        {'str': "-fobjc-nilcheck"},
        {'re': r"-fobjc-std=.*"},
        {'str': "-freplace-objc-classes"},
        {'str': "-fzero-link"},
        {'str': "-gen-decls"},
        {'str': "-Wassign-intercept"},
        {'str': "-Wno-protocol"},
        {'str': "-Wselector"},
        {'str': "-Wstrict-selector-match"},
        {'str': "-Wundeclared-selector"},

        # Language independent options
        # http://gcc.gnu.org/onlinedocs/gcc/Language-Independent-Options.html
        {'re': r"-fmessage-length=.*"},
        {'re': r"-fdiagnostics-show-location=.*"},
        {'str': "-fno-diagnostics-show-option"},
        {'str': "-fno-diagnostics-show-caret"},

        # Warning options
        # http://gcc.gnu.org/onlinedocs/gcc/Option-Summary.html
        # No need to specify all -W.* options, they are
        # handled below in other unspecified options.
        {'str': "-fsyntax-only"},
        {'re': r"-fmax-errors=.*"},
        {'str': "-w"},
        {'str': "-Werror"},
        {'re': r"-Werror=.*"},
        {'str': "-Wfatal-errors"},
        {'str': "-Wpedantic"},
        {'str': "-pedantic"},
        {'str': "-pedantic-errors"},
        {'str': "-Wall"},
        {'str': "-Wextra"},
        {'str': "-W"},

        # Options for Debugging
        # http://gcc.gnu.org/onlinedocs/gcc/Debugging-Options.html
        # All other debugging -g.* -f.* -d.* options are
        # handled in other unspecified options.
        {'str': "-g"},
        {'str': "-p"},
        {'str': "-pg"},
        {'str': "-Q"},
        {'str': "--coverage"},
        {'str': "-save-temps"},
        {'re': r"-save-temps=.*"},
        {'str': "-time"},
        {'re': r"-time=.*"},
        {'re': r"-print-.*", 'dest': "opt_print"},
        {'re': r"-dump.*", 'dest': "opt_dump"},

        # Optimization options
        # http://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html
        # All other -f.* options are handled in other unspecified
        # options.
        {'str': "-O"},
        {'re': r"-O[0123gs]"},
        {'str': "-Ofast"},
        # Instrumentation options
        {'re': r"-f(no-)?omit-frame-pointer"},
        {'re': r"-f(no-)?address-sanitizer"},
        {'re': r"-f(no-)?mudflap.*"},
        # Semantic options
        {'re': r"-f(no-)?strict-aliasing"},
        {'re': r"-f(no-)?strict-overflow"},
        # LTO options
        {'re': r"-f(no-)?whole-program"},
        {'re': r"-f(no-)?lto"},
        {'re': r"-flto=.*"},
        {'re': r"-flto-partition=.*"},
        {'re': r"-flto-compression-level=.*"},
        {'re': r"-f(no-)?lto-report"},
        {'re': r"-f(no-)?use-linker-plugin"},
        {'re': r"-f(no-)?fat-lto-objects"},
        # Profiling options
        {'re': r"-f(no-)?profile-arcs"},
        {'re': r"-f(no-)?branch-probabilities"},
        {'re': r"-f(no-)?profile-values"},
        {'re': r"-f(no-)?vpt"},
        {'re': r"-f(no-)?tracer"},
        {'re': r"-f(no-)?profile-correction"},
        {'re': r"-fprofile-dir=.*"},
        {'re': r"-f(no-)profile-generate"},
        {'re': r"-fprofile-generate=.*"},
        {'re': r"-f(no-)profile-use"},
        {'re': r"-fprofile-use=.*"},
        # Section garbage collection
        {'re': r"-f(no-)function-sections"},
        {'re': r"-f(no-)data-sections"},
        # Params
        {'str': "--param", 'nargs': 1, 'optsep': "="},
        #  RVCT Optimizaition options
        {'re': r"-O(time|size)"},

        # Preprocessor options
        # http://gcc.gnu.org/onlinedocs/gcc/Preprocessor-Options.html
        # All cpp related warning options are handled in
        # warning options and other unspecified options.
        # Options -x, -ansi, -std=.*, -traditional-.*, -trigraphs
        # are treated in dialect options and general options.
        # The case of the '-version' option (one dash only) is
        # ommited as it is not recognized directly by the driver.
        {'str': "-Wp", 'nargs': 1, 'sep': ",", 'dest': "opt_preprocessor"},
        {'str': "-Xpreprocessor", 'nargs': 1, 'next': True,
         'dest': "opt_preprocessor"},
        {'str': "-no-integrated-cpp"},
        {'str': "-D", 'nargs': 1},
        {'str': "-U", 'nargs': 1},
        {'str': "-undef"},
        {'str': "-I-"},
        {'str': "-I"},
        # Options -M/-MM imply -E
        {'str': "-M", 'dest': "opt_M"},
        {'str': "-MM", 'dest': "opt_MM"},
        # Options controlling -M/-MM/-MD
        {'str': "-MF", 'nargs': 1},
        {'str': "-MG"},
        {'str': "-MP"},
        {'str': "-MT", 'nargs': 1},
        {'str': "-MQ", 'nargs': 1},
        # Options -MD/-MMD do not imply -E
        {'str': "-MD"},
        {'str': "-MMD"},
        # Pre compiled headers
        {'str': "-fpch-deps"},
        {'str': "-fpch-preprocess"},
        {'str': "-nostdinc"},
        # {'str': "-nostdinc++"}, # Also in C++ dialect options
        # Options with arguments
        {'str': "-include", 'nargs': 1},
        {'str': "-imacros", 'nargs': 1},
        {'str': "-idirafter", 'nargs': 1},
        {'str': "-iprefix", 'nargs': 1},
        {'str': "-iwithprefix", 'nargs': 1},
        {'str': "-iwithprefixbefore", 'nargs': 1},
        {'str': "-isysroot", 'nargs': 1},
        {'str': "-imultilib", 'nargs': 1},
        {'str': "-isystem", 'nargs': 1},
        {'str': "-iquote", 'nargs': 1},
        {'str': "-fdirectives-only"},
        {'str': "-fdollars-in-identifiers"},
        {'str': "-fextended-identifiers"},
        {'str': "-fpreprocessed"},
        {'re': r"-ftabstop=.*"},
        {'str': "-fdebug-cpp"},
        {'re': r"-ftrack-macro-expansion(=.$)?"},
        {'re': r"-fexec-charset=.*"},
        {'re': r"-fwide-exec-charset=.*"},
        {'re': r"-finput-charset=.*"},
        {'str': "-fworking-directory"},
        {'str': "-fno-show-column"},
        {'str': "-A", 'nargs': 1},
        {'re': r"-d[MDNIU]"},
        {'str': "-P"},
        {'str': "-C"},
        {'str': "-CC"},
        {'str': "-remap"},
        {'str': "-H"},

        # Assembler options
        # http://gcc.gnu.org/onlinedocs/gcc/Assembler-Options.html
        {'str': "-Wa", 'nargs': 1, 'sep': ",", 'dest': "opt_assembler"},
        {'str': "-Xassembler", 'nargs': 1, 'next': True,
         'dest': "opt_assembler"},

        # Linker options
        # http://gcc.gnu.org/onlinedocs/gcc/Link-Options.html
        # Any input file (i.e. a non option argument and not
        # an option param) is treated like a linker input.
        # If the linker is not run, gcc emits a warning.
        # We actually can consider this as an error until
        # we find a motivating case
        # If -c/-S/-E option are used or any option implying
        # them; the linker is not run.
        {'str': "-Wl", 'nargs': 1, 'sep': ",", 'dest': "opt_linker"},
        {'str': "-Xlinker", 'nargs': 1, 'next': True, 'dest': "opt_linker"},
        {'str': "-l", 'nargs': 1, 'dest': "opt_l"},
        {'str': "-nostartfiles"},
        {'str': "-nodefaultlibs"},
        {'str': "-nostdlib"},
        {'str': "-pie"},
        {'str': "-rdynamic"},
        {'str': "-s"},
        {'str': "-static", 'dest': "opt_static"},
        {'str': "-shared", 'dest': "opt_shared"},
        {'str': "-static-libgcc"},
        {'str': "-shared-libgcc"},
        {'str': "-static-libstdc\+\+"},
        {'str': "-symbolic"},
        {'str': "-T", 'nargs': 1},
        {'str': "-u", 'nargs': 1},

        # Directory options
        # http://gcc.gnu.org/onlinedocs/gcc/Directory-Options.html
        # Some options are already described in CPP options
        {'str': "-B", 'nargs': 1},
        {'str': "-iplugindir", 'nargs': 1, 'sep': "="},
        {'str': "-iquotedir"},
        {'str': "-L", 'nargs': 1, 'dest': "opt_L"},
        {'str': "-specs", 'nargs': 1, 'optsep': "="},
        {'str': "--sysroot", 'nargs': 1, 'optsep': "="},
        {'str': "--no-sysroot-suffix"},

        # Machine dependent options
        # http://gcc.gnu.org/onlinedocs/gcc/Option-Summary.html
        # We assume that all machine dependent options are
        # no arguments options.
        # These -m.* options are handleed in other unspecified
        # options.

        # Code Generation Options
        # http://gcc.gnu.org/onlinedocs/gcc/Code-Gen-Options.html
        # All code generation options are non argument options
        # and start with -f. They are treated in other unspecified
        # options.

        # Other unspecified options
        # Note that the special -W.,.* phases options
        # must appear before -W.* warning options.
        {'re': r"-g.*", 'dest': "opt_g_other"},
        {'re': r"-d.*", 'dest': "opt_d_other"},
        {'re': r"-m.*", 'dest': "opt_m_other"},
        {'re': r"-f.*", 'dest': "opt_f_other"},
        {'re': r"-W.,.*", 'dest': "opt_Wp_other"},
        {'re': r"-W.*", 'dest': "opt_W_other"},
        {'re': r"-O.*", 'dest': "opt_O_other"},
        {'re': r"-.*", 'dest': "opt_other"},
        ]

    @staticmethod
    def test():
        print "TESTING CCArgumentsDesc..."
        args_desc = CCArgumentsDesc
        kind_set = set()
        for kind, desc in args_desc.source_kind.items():
            assert(not kind in kind_set)
            kind_set.add(kind)
            assert(isinstance(desc, dict))
            assert(isinstance(desc['desc'], str))
            assert(isinstance(desc['re'], str))
        kind_set = set()
        for kind, desc in args_desc.language_kind.items():
            assert(not kind in kind_set)
            kind_set.add(kind)
            assert(isinstance(desc, str))
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
        print "SUCCESS CCArgumentsDesc"
        return True

if __name__ == "__main__":
    passed = CCArgumentsDesc.test()
    if not passed: sys.exit(1)
