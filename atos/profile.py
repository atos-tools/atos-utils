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
#
# Usage: get usage with atos-acf-oprofile -h
#

import sys, os, re, tempfile, commands
from logging import debug, info, warning, error


# ####################################################################


def check_format(oprof_output):
    profile_formats = [
        # vma samples  %   image name  symbol name
        # 04004c0 1424923 85.6763  a.out main
        r'vma +samples +% +image[ _]name +symbol[ _]name *',
        # vma samples  %  linenr info      image name  symbol name
        # 0c144 20626 20.3311 (no localization information)  a.out main
        r'vma +samples +% +linenr[ _]info +image[ _]name +symbol[ _]name *',
        # vma samples  %  linenr info      image name  app name   symbol name
        # 0x19e 22583 0.0312813 (no location info) libxx.so libxx.so func1
        r'vma +samples +% +linenr[ _]info +image[ _]name '
        '+app[ _]name +symbol[ _]name *',
        # vma samples  %  image name  app name   symbol name
        # 0x19e 22583 0.0312813 libxx.so libxx.so func1
        r'vma +samples +% +image[ _]name +app[ _]name +symbol[ _]name *',
        # Overhead Samples Command Shared Object Symbol
        # 0.84%     1      hello.u /tmp/hello.u  0x000000000670 d [.] func1
        r'# +Overhead +Samples +Command +Shared Object +Symbol *',
        ]
    for line in open(oprof_output):
        for num, rexp in enumerate(profile_formats):
            if re.match(rexp, line): return num + 1
    return None


def parse_binary_list(oprof_output, oprofile_format, binary, bin_path):
    def find_binary_in_path(image_name, bin_path):
        for path in bin_path.split(':'):
            if os.path.isfile(os.path.join(path, image_name)):
                return os.path.join(path, image_name)
        return None

    binary_list = []
    for line in open(oprof_output):
        if (oprofile_format == 5):
            # perf profiling format
            # Handle:  30.25%  36 hello.u /lib/libc-2.11.1.so \
            #          0x00000000000453a0 u [.] __GI_vfprintf
            if not re.match(
                r'^ +[\d\.]+% +\d+ +.* +.* +[0-9a-fA-Fx]+ +[\w!\.] '
                '+\[[\.kguH]\] +\w+.*', line): continue
            # we're on a symbol line:
            words = line.split()
            image_name = os.path.basename(words[3])
        else:  # oprofile format
            if not re.match(r'^[0-9a-fA-F]+ +\d+ +[\d\.]+ +.*', line):
                continue
            # we're on a symbol line:
            words = line.split()
            if oprofile_format == 1 or oprofile_format == 4:
                image_name = words[3]
            elif oprofile_format == 2 or oprofile_format == 3:
                # handle (no-location-information) case
                #   0000000 156636 9.4180 (no location information) no-vmlinux
                image_name = (words[3] == '(no') and words[6] or words[4]

        # detect if we are in an interesting region of the profile file
        if image_name != 'anon':
            if os.path.basename(image_name) == os.path.basename(binary):
                # Handle -e <binary> option
                if not (image_name, binary) in binary_list:
                    binary_list += [(image_name, binary)]
            else:
                ret_path = find_binary_in_path(image_name, bin_path)
                if ret_path and not (image_name, ret_path) in binary_list:
                    binary_list += [(image_name, ret_path)]
    return binary_list


def parse_profile(oprof_output, oprofile_format, binary_list):
    # read couples of (address, sample_count) from oprofile output
    samples = {}
    for line in open(oprof_output):
        if (oprofile_format == 5):
            # perf profiling format
            # Handle:  30.25%  36 hello.u /lib/libc-2.11.1.so \
            #          0x00000000000453a0 u [.] __GI_vfprintf
            # Discard compiler generated symbols:
            #           0.01%   1 sha1-c  ./sha1-c            \
            #          0x00000000000005c3 d [.] printf@plt
            if not re.match(
                r'^ +[\d\.]+% +\d+ +.* +.* +[0-9a-fA-Fx]+ '
                '+[\w!\.] +\[[\.kguH]\] +\w+$', line):
                continue
            # we're on a symbol line:
            words = line.split()
            image_name = os.path.basename(words[3])
        else:  # oprofile format
            if not re.match(r'^[0-9a-fA-F]+ +\d+ +[\d\.]+ +.*', line):
                continue
            # we're on a symbol line:
            words = line.split()
            # handle (no-location-information) case
            #   0000000 156636 9.4180 (no location information) no-vmlinux
            if words[3] == '(no':
                words[3] = ' '.join(words[3:6])
                del words[4:6]
            image_name = (
                (oprofile_format == 1 or oprofile_format == 4)
                and words[3] or words[4])

        # detect if we are in an interesting region of the profile file
        for (bin, path) in binary_list:
            in_binary_region = (
                os.path.basename(image_name) == os.path.basename(bin))
            if not in_binary_region: continue

            if (oprofile_format == 5):
                # Remove trailing '%'
                percent = words[0][:-1]
                samps = words[1]
                vma = words[4]
                linenr = ' '
                app_name = words[2]
                sym = words[7]
            else:  # oprofile format
                vma, samps, percent = words[0:3]
                linenr, app_name = ' ', ' '
                if oprofile_format == 3:
                    app_name = words.pop(5)
                elif oprofile_format == 4:
                    app_name = words.pop(4)
                if oprofile_format in [2, 3]:
                    linenr = words.pop(3)
                if oprofile_format in [1, 2, 3, 4]:
                    sym = words[4]

            # merge multiple entries for same image_name/sym
            sym_found = False
            sym = sym.split('.')[0]
            if image_name in samples.keys():
                for (vma_c, samps_c, percent_c, linenr_c, image_name_c,
                     app_name_c, sym_c) in samples[image_name]:
                    if sym_c != sym: continue
                    # accumulate samples and update list
                    samples[image_name].remove(
                        (vma_c, samps_c, percent_c,
                         linenr_c, image_name_c, app_name_c, sym_c))
                    samples[image_name].insert(
                        0, (vma, str(int(samps) + int(samps_c)), str(
                                float(percent) + float(percent_c)), linenr,
                            image_name, app_name, sym))
                    sym_found = True
                    break
            if not sym_found:
                samples.setdefault(image_name, []).append(
                    (vma, samps, percent, linenr, image_name, app_name, sym))
            break
    return samples


def create_debug_info_lists(samples, binary_list, addr2line="addr2line"):
    def create_debug_info_list(binary_file, addr_file_path, addr2line):
        dbg_info = {}
        status, res = commands.getstatusoutput(
            '%s --functions --exe %s @%s' % (
                addr2line, binary_file, addr_file_path))
        addr_file = open(addr_file_path)
        odd = False
        for line in res.split('\n'):
            # addr2line --functions returns 2 lines for each address:
            # <function_name>\n<file>:<line>
            # If address doesn't match debug information, it returns '??' for
            # <function_name> and<file>, 0 for <line>
            if not odd:
                # We are on a <function_name> line
                current_addr = addr_file.readline().rstrip('\n')
                current_func = line
                odd = True
            else:
                # We are on a <file>:<line> line
                odd = False
                if not re.match('^.*:\d+$', line):
                    warning('malformed debug information (address= '
                            + current_addr + '): discarding ' + line)
                    continue
                words = line.split(':')
                dbg_info[current_addr] = (current_func, words[0], words[1])
        addr_file.close()
        return dbg_info
    debug_infos = {}
    for image_name in samples.keys():
        # Get debug information for functions in current binary if available
        # Source file information is used to avoid ambiguities between
        # functions with same name in different binaries/libraries inside
        # the GNU acf-plugin
        for (bin, path) in binary_list:
            if bin != image_name: continue
            # Store all relevant function addresses in a temporary file
            # to get debug information
            address_file = tempfile.NamedTemporaryFile(delete=False)
            ### TODO: Remove duplicate addresses
            address_file.write(
                '\n'.join(map(lambda x: x[0], samples[image_name])))
            address_file.close()
            debug_infos[image_name] = create_debug_info_list(
                path, address_file.name, addr2line)
            os.remove(address_file.name)
            break
    return debug_infos


def get_file(debug_info, vma):
    # returns the basename of the file
    (debug_func, debug_file, debug_line) = debug_info[vma]
    if debug_func == '??' or debug_file == '??':
        # Debug information was not found for this address
        source_file = None
    else:
        # addr2line sometimes returns the demangled function name while not
        # requested, adding a ~ leading character.
        # Only check if debug_func is part of funcname, first removing extra ~
        ### The check fails for functions inlined in .h files for which readelf
        ### and addr2line report a different function for a given address...
        # if not debug_func.lstrip('~') in sym:
        #     print 'Warning: Incorrect debug information'
        source_file = os.path.basename(debug_file)
    return source_file


# ####################################################################


def get_samples(imgpath=None, oprof_output="./oprof.out"):
    is_binary = not os.path.isdir(imgpath.split(':')[0])
    binary, bin_path = '', ''
    if is_binary: binary = imgpath
    else: bin_path = imgpath
    if binary and not os.path.isfile(binary):
        error('binary file not found: "%s"' % binary)
        return None, None
    if not os.path.isfile(oprof_output):
        error('profile file not found: "%s"' % oprof_output)
        return None, None
    oprofile_format = check_format(oprof_output)
    if not oprofile_format:
        error('oprofile output format not supported')
        return None, None
    binary_list = parse_binary_list(
        oprof_output, oprofile_format, binary, bin_path)
    # {image_name: [(vma, samps, percent, linenr, image_name, app_name, sym)]}
    samples = parse_profile(oprof_output, oprofile_format, binary_list)
    return samples, binary_list


def partition_symbols(samples, hot_th=50):
    partitions = {}
    for image_name in samples.keys():
        image_samples = sorted(samples[image_name], key=lambda x: int(x[1]))
        image_total_count = sum(map(lambda x: int(x[1]), image_samples))
        image_cold_part = int(
            float(image_total_count) * float(100 - hot_th) / 100.0)
        image_sym_list = list(set(map(lambda x: (x[-1], x[0]), image_samples)))

        image_cold_list, curr_count = [], 0
        for (vma, count, _, _, _, _, sym) in image_samples:
            curr_count += int(count)
            if curr_count > image_cold_part: break
            image_cold_list.append((sym, vma))

        image_hot_list = filter(
            lambda x: x not in image_cold_list, image_sym_list)

        partitions[image_name] = (image_cold_list, image_hot_list)
    return partitions


def partition_objects(sym_part, fct_map):
    # list of all hot function for all images
    hot_functions = []
    for (cold, hot) in sym_part.values():
        hot_functions.extend(hot)
    # hot files are files that contains hot functions)
    hot_files = []
    for (sym, vma) in hot_functions:
        hot_files.extend(fct_map.get(sym, []))
    hot_files = list(set(hot_files))
    # cold files are all other files
    file_list = list(
        set(sum(fct_map.values(), [])))
    cold_files = filter(
        lambda x: x not in hot_files, file_list)
    return cold_files, hot_files


def get_localized_symbols_partition(hot_cold_partition, debug_infos):
    new_cold_list, new_hot_list = [], []
    for image_name in hot_cold_partition.keys():
        cold_list, hot_list = hot_cold_partition[image_name]
        for (sym, vma) in hot_list:
            source_file = get_file(debug_infos[image_name], vma)
            new_hot_list.append((sym, source_file))
        for (sym, vma) in cold_list:
            source_file = get_file(debug_infos[image_name], vma)
            new_cold_list.append((sym, source_file))
    return new_cold_list, new_hot_list


# ####################################################################


def partition_symbols_loc(imgpath, hot_th):
    samples, binary_list = get_samples(imgpath=imgpath)
    if not samples: return [], []
    debug_infos = create_debug_info_lists(samples, binary_list)
    hot_cold_partition = partition_symbols(samples, int(hot_th))
    cold_list, hot_list = get_localized_symbols_partition(
        hot_cold_partition, debug_infos)
    return cold_list, hot_list


def partition_object_files(imgpath, hot_th, fct_map):
    samples, _ = get_samples(imgpath=imgpath)
    if not samples: return [], []
    hot_cold_partition = partition_symbols(samples, int(hot_th))
    cold_list, hot_list = partition_objects(hot_cold_partition, fct_map)
    return cold_list, hot_list


def read_function_to_file_map(mapfile):
    fct_map = {}
    for line in open(mapfile):
        words = line.split()
        if len(words) < 2: continue
        obj, fct = words[:2]
        fct_map.setdefault(fct, []).append(obj)
    return fct_map


def get_image_pathes(exes=None, configuration_path='atos-configuration'):
    imgpath = exes and exes.split()
    targets_filename = os.path.join(configuration_path, "targets")
    if not imgpath and os.path.isfile(targets_filename):
        with open(targets_filename) as targets_file:
            imgpath = map(
                lambda x: os.path.dirname(x.strip()), targets_file.readlines())
            imgpath = ":".join(list(set(imgpath)))
    return imgpath
