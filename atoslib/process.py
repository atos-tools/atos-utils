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
import cStringIO, StringIO
import __builtin__
import tempfile
import atexit
import time
import shutil
import logger

def cmdline2list(cmd):
    """
    Returns a list of args from the given shell command string.
    This supports unicode strings, but they are first converted
    to bare ASCII strings.
    """
    assert(isinstance(cmd, (str, unicode)))
    try:
        return shlex.split(str(cmd))
    except ValueError:
        logger.internal_error("malformed command (%s) '%s'" % (
                str(sys.exc_info()[1]), cmd))
    except: raise

def list2cmdline(args, **kwargs):
    """
    Returns a quoted string suitable for execution from a shell.
    Original version from:
    http://stackoverflow.com/questions/967443/
    python-module-to-shellquote-unshellquote.
    """
    assert(isinstance(args, list))

    def emacs_quote(arg):
        r"""
        This is the logic emacs uses.
        >>> quote('\t')
        '\\\t'
        >>> print quote('foo bar')
        foo\ bar
        >>> print quote("foo'and'bar")
        foo\'and\'bar
        """
        if arg:
            return _quote_pos.sub('\\\\', arg).replace('\n', "'\n'")
        else:
            return "''"

    def sh_quote(arg):
        r"""
        Can be used in scripts where over quoting is not an issue.
        In a shell, using '...' for quoting ensure no interpretation of
        any char. Also, arguments can be created by contiguous quoted
        parts.
        Thus we just have to split around ' into parts that we quote
        with '...' and join again around a "'" sequence.
        >>> sh_quote('\t')
        "'\t'"
        >>> print sh_quote('foo bar')
        'foo bar'
        >>> print sh_quote("foo'and'bar")
        'foo'"'"'and'"'"'bar'
        """
        return "\"'\"".join(["'" + x + "'" for x in arg.split("'")])

    _quote_pos = re.compile('(?=[^-0-9a-zA-Z_./\n])')
    quote = sh_quote if kwargs.get('sh_quote', False) else emacs_quote
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
        # wait for new data availability
        while in_files:
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
        # nothing left to read, return
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
    assert(isinstance(cmd, (list, str, unicode)))
    assert(not shell or not isinstance(cmd, list))
    cmd_list = cmdline2list(cmd) if isinstance(cmd, (str, unicode)) else cmd
    if not shell: cmd = cmd_list
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
    try:
        process = subprocess.Popen(cmd, shell=shell, **popen_kwargs)
        if get_output:
            _process_output(
                process, output_file=outputf, print_output=print_output,
                output_stderr=output_stderr)
        status = process.wait()
    except OSError, e:
        print >>sys.stderr, "%s: %s" % (cmd_list[0], e.strerror)
        status = 1
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
           output_stderr=False, shell=False, stdin_str=False, no_debug=False):
    """
    Executes given command.
    Given command can be a string or a list or arguments.
    """
    printable_cmd = cmd
    if isinstance(cmd, list):
        printable_cmd = list2cmdline(cmd)
    if _dryrun:
        logging.info(printable_cmd)
        return get_output and (0, "") or 0
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
        if not no_debug:
            logging.debug('\n  | ' + '\n  | '.join(output.split('\n')))
        logging.debug('command [%s] -> %s' % (printable_cmd, str(status)))
    if check_status:
        assert status == 0
        return get_output and output or None
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
        logging.debug('mkdir -p ' + dirname)
        if os.path.isdir(dirname): return
        if _dryrun: return
        os.makedirs(dirname)

    @staticmethod
    def touch(filename):
        # http://stackoverflow.com/questions/1158076/
        #   implement-touch-using-python
        logging.debug('touch ' + filename)
        if _dryrun: return
        with file(filename, 'a'):
            os.utime(filename, None)

    @staticmethod
    def chmod(path, mode):
        logging.debug('chmod %s %s' % (str(mode), path))
        if _dryrun: return
        os.chmod(path, mode)

    @staticmethod
    def rmtree(path):
        logging.debug('rm -rf %s' % (path))
        if _dryrun: return
        if not os.path.exists(path): return
        if os.path.isdir(path) and not os.path.islink(path):
            shutil.rmtree(path)
        else:
            os.unlink(path)

    @staticmethod
    def unlink(path):
        logging.debug('rm -f %s' % (path))
        if _dryrun: return
        if os.path.exists(path):
            os.unlink(path)

    @staticmethod
    def copyfile(src, dst):
        logging.debug('cp %s %s' % (src, dst))
        if _dryrun: return
        shutil.copyfile(src, dst)

    @staticmethod
    def chdir(path):
        logging.debug('cd %s' % (path))
        os.chdir(path)

    @staticmethod
    def which(execname):
        if os.path.dirname(execname) != "":
            if os.access(execname, os.X_OK):
                return os.path.abspath(execname)
        else:
            env_PATH = os.environ.get('PATH', None)
            if not env_PATH: return None
            for p in env_PATH.split(os.pathsep):
                if p == "": continue
                p = os.path.join(p, execname)
                if os.access(p, os.X_OK):
                    return os.path.abspath(p)
        return None

    @staticmethod
    def test():
        def test_which(tmpdir):
            commands.chdir(tmpdir)
            oldpath = None
            if 'PATH' in os.environ:
                oldpath = os.environ.pop('PATH')
            tmpfile = tempfile.NamedTemporaryFile(dir=tmpdir, delete=False)
            tmpname = tmpfile.name
            execname = os.path.basename(tmpname)
            # Full path, but not executable
            assert(commands.which(tmpname) == None)
            # No PATH defined
            assert(commands.which(execname) == None)
            commands.chmod(tmpname, 0755)
            # Full path, and  executable
            assert(commands.which(tmpname) == tmpname)
            # Relative path, and  executable
            assert(commands.which("./%s" % execname) == tmpname)
            # No PATH defined
            assert(commands.which(execname) == None)
            os.environ['PATH'] = ""
            # No matching PATH
            assert(commands.which(execname) == None)
            os.environ['PATH'] = "/undef::%s" % tmpdir
            # Matching PATH and executable
            assert(commands.which(execname) == tmpname)
            os.environ['PATH'] = ":/usr//../%s" % tmpdir
            # Matching PATH is canonicalized
            assert(commands.which(execname) == tmpname)
            if oldpath == None:
                os.environ.pop('PATH')
            else:
                os.environ['PATH'] = oldpath
            return True

        print "TESTING process.commands..."
        cwd = os.getcwd()
        tmpdir = tempfile.mkdtemp()
        try:
            test_which(tmpdir)
        finally:
            commands.chdir(cwd)
            commands.rmtree(tmpdir)
        print "SUCCESS process.commands"
        return True

if __name__ == "__main__":
    passed = commands.test()
    if not passed: sys.exit(1)
