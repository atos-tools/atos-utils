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

import os
import sys
import re
import shlex
import logging
import subprocess
import select
import fcntl
import signal
import cStringIO, StringIO
import __builtin__
import tempfile
import atexit

def cmdline2list(cmd):
    """
    Returns a list of args from the given shell command string.
    """
    return shlex.split(str(cmd))

def list2cmdline(args):
    """
    Returns a quoted string suitable for execution from a shell.
    Ref to http://stackoverflow.com/questions/967443/
      python-module-to-shellquote-unshellquote.
    """
    _quote_pos = re.compile('(?=[^-0-9a-zA-Z_./\n])')

    def quote(arg):
        r"""
        >>> quote('\t')
        '\\\t'
        >>> quote('foo bar')
        'foo\\ bar'
        """
        # This is the logic emacs uses
        if arg:
            return _quote_pos.sub('\\\\', arg).replace('\n', "'\n'")
        else:
            return "''"
    return ' '.join([quote(a) for a in args])

def _process_output(process, output_file, print_output, output_stderr):
    """
    Handles outputs in stdout/stderr until process end.
    """
    def setfl(fil, flg=None, msk=None):
        # set given flags/mask and return initial flag list
        if not fil: return
        flags = flg or fcntl.fcntl(fil, fcntl.F_GETFL)
        new_flags = msk and (flags | msk) or flags
        if not fil.closed:
            fcntl.fcntl(fil, fcntl.F_SETFL, new_flags)
        return flags
    # set flags to get non-blocking read of stdio/stderr
    errflags = setfl(process.stderr, msk=os.O_NONBLOCK)
    outflags = setfl(process.stdout, msk=os.O_NONBLOCK)
    in_files = filter(bool, [process.stderr, process.stdout])
    try:
        while True:
            # wait for new data avalaible or process end
            ready = select.select(in_files, [], [])[0]
            if process.stderr in ready:
                data = process.stderr.read()
                if data and output_stderr: output_file.write(data)
                if data and print_output: sys.stderr.write(data)
                if not data: in_files.remove(process.stderr)
            if process.stdout in ready:
                data = process.stdout.read()
                if data: output_file.write(data)
                if data and print_output: sys.stdout.write(data)
                if not data: in_files.remove(process.stdout)
            if process.poll() is not None:
                break
            if not in_files:  # nothing to read, wait for end
                process.wait()
                break
    finally:
        # reset initial flags
        setfl(process.stdout, flg=outflags)
        setfl(process.stderr, flg=errflags)

def _subcall(cmd, get_output=False, print_output=False, output_stderr=False,
             shell=False, stdin_str=False):
    """
    Executes given command.
    Returns exit_code and output.

    Returned output will be None unless get_output argument is set.
    Stderr will be included in returned output if output_stderr is set.
    Outputs will not be printed on stdout/stderr unless print_output is set.
    """
    if isinstance(cmd, (str, unicode)):
        cmd = cmdline2list(cmd)
    if shell and isinstance(cmd, list):
        cmd = ' '.join(cmd)  # list2cmd quotes redirection chars < >
    outputf = get_output and cStringIO.StringIO()
    popen_kwargs = {}
    if get_output and output_stderr and not print_output:
        popen_kwargs.update(
            {'stdout': subprocess.PIPE, 'stderr': subprocess.STDOUT})
    elif get_output or not print_output:
        popen_kwargs.update(
            {'stdout': subprocess.PIPE, 'stderr': subprocess.PIPE})
    if stdin_str:
        stdin_tmp = tempfile.TemporaryFile()
        stdin_tmp.write(stdin_str)
        stdin_tmp.seek(0)
        popen_kwargs.update({'stdin': stdin_tmp})
    process = subprocess.Popen(cmd, shell=shell, **popen_kwargs)
    while True:
        try:
            if get_output:
                _process_output(
                    process, output_file=outputf, print_output=print_output,
                    output_stderr=output_stderr)
            else:
                process.wait()
            break
        except KeyboardInterrupt:
            process.send_signal(signal.SIGINT)
        except: raise
    status = process.poll()
    if get_output:
        output = outputf.getvalue()
        outputf.close()
    else: output = None
    if stdin_str: stdin_tmp.close()  # trigger tmpfile deletion
    return (status, output)

_initialized = False
_dryrun = False
_real_open = None

def setup(kwargs):
    """
    Configure the process launcher module.
    Must be called before any thread creation.
    """
    global _initialized, _dryrun, _real_open
    if _initialized: return
    _initialized = True

    def replace_open(fake_open):
        def restore_open(real_open):
            __builtin__.open = real_open

        atexit.register(restore_open, __builtin__.open)
        real_open = __builtin__.open
        __builtin__.open = fake_open
        return real_open

    _dryrun = kwargs.get('dryrun', False)
    if _dryrun:
        _real_open = replace_open(_open)

def system(cmd, check_status=False, get_output=False, print_output=False,
           output_stderr=False, shell=False, stdin_str=False):
    """
    Executes given command.
    Given command can be a string or a list or arguments.
    """
    printable_cmd = cmd
    if isinstance(cmd, list):
        printable_cmd = list2cmdline(cmd)
    if _dryrun:
        logging.info(printable_cmd)
        return get_output and (0, None) or 0
    logging.debug('command [%s]' % printable_cmd)
    root_logger = logging.getLogger()
    debug_mode = root_logger.isEnabledFor(logging.DEBUG)
    quiet_mode = not root_logger.isEnabledFor(logging.INFO)
    print_output = print_output and not quiet_mode
    get_output_ = get_output or debug_mode
    status, output = _subcall(
        cmd, print_output=print_output,
        get_output=get_output_, output_stderr=output_stderr,
        shell=shell, stdin_str=stdin_str)
    if get_output:
        logging.debug('\n  | ' + '\n  | '.join(output.split('\n')))
        logging.debug('command [%s] -> %s' % (printable_cmd, str(status)))
    if check_status and status: sys.exit(status)
    return get_output and (status, output) or status

def open_locked(filename, mode='r'):
    while True:
        outf = open(filename, mode)
        if _dryrun and not isinstance(outf, file):
            return outf
        try:
            fcntl.flock(outf, fcntl.LOCK_EX | fcntl.LOCK_NB)
            return outf
        except: outf.close()
        time.sleep(1)

def _open(name, *args):
    if not _dryrun:
        return _real_open(name, *args)
    modes = set(args[0]) if args else None
    if not modes:
        return _real_open(name, *args)
    if not (modes & set(["w", "a", "+"])):
        return _real_open(name, *args)
    logging.debug('# open-write ' + name)
    return CtxStringIO()

def debug(msg, *args, **kwargs):
    """ Log a process debug message on the ATOS logger. """
    logging.debug(msg, *args, **kwargs)

class CtxStringIO(StringIO.StringIO):
    """ StringIO with context manager support class """

    def __exit__(self, exc_type, exc_val, exc_tb): self.close()

    def __enter__(self): return self

class commands():

    @staticmethod
    def mkdir(dirname):
        if os.path.isdir(dirname): return
        logging.debug('# mkdir -p ' + dirname)
        if _dryrun: return
        os.makedirs(dirname)

    @staticmethod
    def touch(filename):
        # http://stackoverflow.com/questions/1158076/
        #   implement-touch-using-python
        logging.debug('# touch ' + filename)
        if _dryrun: return
        with file(filename, 'a'):
            os.utime(filename, None)

    @staticmethod
    def chmod(path, mode):
        logging.debug('# chmod %s %s' % (str(mode), path))
        if _dryrun: return
        os.chmod(path, mode)
