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
import os
import logging
import traceback
from logging import debug, info, warning

class _ConsoleLogFormatter():
    """
    Formatter for console log messages.

    In debug mode, print detailled log messages including date and caller
    location. Simply print messages in normal mode.
    """
    def __init__(self, handler, fmt=None, datefmt=None):
        self.full_formatter = logging.Formatter(
            fmt, datefmt)
        self.light_formatter = logging.Formatter(
            '%(customprefix)s%(message)s')
        self._handler = handler

    def format(self, record):
        if self._handler.level >= logging.INFO:
            progname = os.path.basename(sys.argv[0])
            if record.levelno >= logging.ERROR:
                customprefix = '%s: error: ' % progname
            elif record.levelno >= logging.WARNING:
                customprefix = '%s: warning: ' % progname
            else: customprefix = ''
            record.customprefix = customprefix
            return self.light_formatter.format(record)
        return self.full_formatter.format(record)

class _ModuleLogFilter():
    """
    Filter for log messages.

    Filter messages which come from a given module.
    """
    def __init__(self, module=None):
        self.module = module

    def filter(self, record):
        filtered_out = (
            self.module and self.module != record.module)
        return not filtered_out

_debug = False
_quiet = False

def setup(kwargs):
    """
    Configure the root logger for atos.
    """
    global _quiet, _debug
    _debug = kwargs.get('debug', False) or os.getenv("ATOS_DEBUG")
    dryrun = kwargs.get('dryrun', False) or os.getenv("ATOS_DRYRUN")
    log_file = kwargs.get('log_file', None) or os.getenv("ATOS_DEBUG_FILE")
    _quiet = kwargs.get('quiet', False)

    log_fmt = (
        '# [%(asctime)-15s] [%(filename)s:%(lineno)s,%(funcName)s]'
        ' %(levelname)s: %(message)s')
    log_datefmt = '%d-%m-%y %H:%M:%S'

    root_logger = logging.getLogger()
    root_logger.setLevel(logging.DEBUG)

    console_log_level = logging.INFO
    if _debug: console_log_level = logging.DEBUG
    if _quiet: console_log_level = logging.ERROR

    console_log_handler = logging.StreamHandler()
    if dryrun:
        console_log_handler.setFormatter(logging.Formatter())
        console_log_handler.addFilter(_ModuleLogFilter('process'))
    else:
        console_log_handler.setFormatter(
            _ConsoleLogFormatter(console_log_handler, log_fmt, log_datefmt))
        console_log_handler.setLevel(console_log_level)
    root_logger.addHandler(console_log_handler)

    if log_file:
        file_log_logger = logging.FileHandler(log_file, mode='a')
        file_log_logger.setFormatter(
            logging.Formatter(log_fmt, log_datefmt))
        root_logger.addHandler(file_log_logger)

def error(msg, exit_status=None, *args, **kwargs):
    """ Log an error message on the ATOS logger. """
    logging.error(msg, *args, **kwargs)
    if exit_status: sys.exit(exit_status)

def message(msg):
    """ Print an info message on stdout if quiet mode is not set. """
    logging.debug(msg)
    if not _quiet: print msg

def internal_error(msg, exit_status=1):
    progname = os.path.basename(sys.argv[0])
    try:
        exc_type, exc_value, exc_traceback = sys.exc_info()
        last_trace = traceback.extract_tb(exc_traceback)[-1]
        loc_str = "(%s:%d): " % (
            os.path.basename(last_trace[0]), last_trace[1])

    except:
        loc_str = ""
    print >>sys.stderr, '%s: internal error: %s%s' % (progname, loc_str, msg)
    if exit_status: sys.exit(exit_status)
