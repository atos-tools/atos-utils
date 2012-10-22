#!/usr/bin/env python

import sys, os

# This file is installed in PREFIX/tests/resources/acf_attribs_and_params
DIRNAME = os.path.dirname(__file__)
SRCDIR = os.getenv('SRCDIR', os.path.abspath(
        os.path.join(DIRNAME, '..', '..', '..')))
ROOT = os.getenv('ROOT', SRCDIR)
PYTHONDIR = os.path.join(ROOT, 'lib', 'atos', 'python')
sys.path.insert(0, PYTHONDIR)

from atos import generators

#
# generate csv files for all flags
#

def open_csv_file(dirname, flagname, count):
    csv_name = 'acf_test_'
    if flagname.startswith('-f'):
        csv_name += flagname[1:]
    elif flagname.startswith('--param '):
        csv_name += 'p' + flagname[8:]
    else:
        csv_name += flagname.replace('-', '_')
    csv_name = csv_name.replace(' ', '').replace('=', '')
    csv_name += str(count)
    csv_file = open(dirname + '/' + csv_name + '.csv', 'w')
    return csv_file

def write_csv_flag(csv_file, funcname, flagval, ignoreO):
    flagval = flagval.replace('--param ', 'PARAM_')
    for opt in flagval.split(' '):
        if opt.startswith('-f'):
            opt = 'optimize,' + opt[2:]
        elif opt.startswith('-O'):
            ## Do not write -O dependencies, they are passed as options
            if (ignoreO):
                continue
            opt = 'optimize,' + opt[1:]
        elif opt.startswith('-'):
            opt = opt[1:]
        csv_file.write(funcname + ',' + opt.replace('=', ',') + '\n')

def close_csv_file(csv_file):
    csv_file.close()

def get_dependency(flagval, optlist, skip=0):
    eqidx = flagval.find('=')
    if eqidx != -1:
        flagval = flagval[:eqidx + 1]
    occur = 0
    for (k, v) in optlist.dependencies.items():
        vstr = map(str, v)
        if flagval in vstr:
            if (occur == skip):
                return k
            occur += 1
    return None


if __name__ == '__main__':

    import optparse
    parser = optparse.OptionParser(
        description='generation of csv test files for acf')
    parser.add_option('--flags', dest='flags',
                     action='store', type='string', default=None,
                     help='flags list file name (default: None)')
    parser.add_option('--csvdir', dest='csvdir',
                     action='store', type='string', default=None,
                     help='directory for csv files (default: None)')
    parser.add_option('--cfunc', dest='funcname',
                     action='store', type='string', default=None,
                     help='function name (default: None)')
    (opts, args) = parser.parse_args()

    optlist = opts.flags and generators.optim_flag_list(opts.flags)

    # Generator for optimize attributes
    # modify nbvalues to generate fewer test files

    if not os.path.isdir(opts.csvdir):
        os.mkdir(opts.csvdir)

    for flag in optlist.flag_list:
        count = 0
        for flagval in flag.values():
            depflag = get_dependency(flagval, optlist)
            if not depflag:
                csv_file = open_csv_file(opts.csvdir, flag.optname(), count)
                #  write_csv_flag(csv_file, optlevel);
                write_csv_flag(csv_file, opts.funcname, flagval, 0)
                close_csv_file(csv_file)
                count += 1
            else:
                skip = 0
                while depflag:
                    csv_file = open_csv_file(opts.csvdir, flag.optname(), count)
                    #  write_csv_flag(csv_file, optlevel);
                    while depflag:
                        write_csv_flag(csv_file, opts.funcname, depflag, 1)
                        depflag = get_dependency(depflag, optlist)
                    write_csv_flag(csv_file, opts.funcname, flagval, 0)
                    close_csv_file(csv_file)
                    skip += 1
                    count += 1
                    depflag = get_dependency(flagval, optlist, skip)

    sys.exit(0)
