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
import time
import types

import atos_lib
import process
import logger
import generators


# display of exploration progress messages
_progress_enabled = True

# display of build/run progress messages
_timer_progress_enabled = True

def setup(kwargs):
    """
    Configure the ATOS progress logger.
    """
    global _progress_enabled, _timer_progress_enabled

    # no progress message in quiet mode
    _progress_enabled = not kwargs.get('quiet', False)

    if os.getenv("ATOS_NO_PROGRESS"): _progress_enabled = False

    # disable update of progress line if stdout is redirected or piped
    _timer_progress_enabled = (
        _progress_enabled and sys.stdout.isatty())

# lists of current exploration and build/run progresses
_exploration_progresses = []
_timer_progresses = []

# estimated time for 1 build + 1 run
_one_iteration_est = None

# the timer for regular update of build/run progress message
_timer = None

def _start_progress_timer():
    global _timer
    if not _timer: _timer = atos_lib.repeattimer(
        _display_progress, 1.0).start()

# display on stdout a progress status line looking like:
#    Remaining exploration time: 00:00:07, 65.8% done (expl-func 57/60,
#        variant 2/2, expl-staged 8/8, stage 4/4).
#        Current build remaining time: 00:00:01 (4.5% done).
def _display_progress(last_iter=False, timer_completed=False):

    def remaining_time_str(remaining):
        if remaining is None: return '??:??:??'
        remaining = int(remaining)
        hours, remaining = divmod(remaining, 3600)
        minutes, seconds = divmod(remaining, 60)
        return '%02d:%02d:%02d' % (hours, minutes, seconds)

    status_str = ""

    if _exploration_progresses:
        main_progress = _exploration_progresses[0]
        main_completion = min(
            float(main_progress.value) / float(main_progress.maxval), 1.0)
        main_remaining_nb = (
            main_progress.maxval - main_progress.value + 1)
        main_remaining = _one_iteration_est and (
            main_remaining_nb * _one_iteration_est) or None
        status = "Remaining exploration time: %s, %3.0f%% done" % (
            remaining_time_str(main_remaining), main_completion * 100)
        status_str += status

        progress_details = (  # remove last exploration progresses (??)
            _exploration_progresses[0:1] + _exploration_progresses[1:-1])
        progress_strings = []
        for progress_detail in progress_details:
            progress_strings += ["%s %d/%d" % (
                    progress_detail.descr,
                    min(progress_detail.value + 1, progress_detail.maxval),
                    progress_detail.maxval)]  # max+1 on last update
        if progress_strings:
            status_str += " (%s)" % ", ".join(progress_strings)
    status_str += "."

    if sys.stdout.isatty():  # no line update if stdout is not a tty
        for timer_progress in _timer_progresses:
            estimated = timer_progress.estimated()
            if not estimated:
                continue
            elapsed = timer_progress.elapsed()
            completion = (1.0 if timer_completed else
                          min(elapsed / estimated, 1.0))
            remaining = (0.0 if timer_completed else
                         max(estimated - elapsed, 0.0))
            status = "%16s: %s remaining, %3.0f%% done." % (
                "Current " + timer_progress.progress_type,
                remaining_time_str(remaining),
                completion * 100.0)
            status_str += " " + status
        # clear previous msg and fill the line
        cols = int(os.popen("tput cols", "r").readline())
        nb_spaces = cols - len(status_str) - 1
        last_char = "\n" if last_iter else "\r"
        status_str = "\r" + status_str + nb_spaces * " " + last_char
    else:
        status_str += "\n"

    if status_str and _exploration_progresses:
        sys.stdout.write(status_str)
        sys.stdout.flush()

class exploration_progress():

    def __init__(
        self, descr=None, maxval=100, value=0, visible=True):
        if not _progress_enabled: return
        self.visible = visible
        if not self.visible: return
        self.descr = descr
        self.maxval = maxval
        self.value = value
        self.is_main_exploration = (len(_exploration_progresses) == 0)
        _exploration_progresses.append(self)
        if self.is_main_exploration:
            _display_progress()

    def update(self, value=None, maxval=None):
        if not _progress_enabled: return
        if not self.visible: return
        if self.value is None:
            self.value = 0
        if value is not None:
            self.value = value
        else:
            self.value += 1
        if maxval is not None:
            self.maxval = maxval
        if self.is_main_exploration:
            _display_progress()

    def end(self):
        if not _progress_enabled: return
        if not self.visible: return
        if self.is_main_exploration:
            _display_progress(last_iter=(len(_exploration_progresses) == 1))
        _exploration_progresses.remove(self)

class timer_progress():

    est_build_time, est_run_time = None, None

    def __init__(self, progress_type=None, variant_id=None, config_path=None):
        if not _progress_enabled: return
        if not _timer_progress_enabled: return
        assert progress_type in ["build", "run"]
        timer_progress.load_estimation_times(config_path)
        self.progress_type = progress_type
        self.variant_id = variant_id
        self.time_file = os.path.join(config_path, progress_type + '.time')
        self.estimated_time_ = timer_progress.load_estimation_time(
            self.time_file)
        self.start_time_ = time.time()
        _timer_progresses.append(self)
        _start_progress_timer()
        _display_progress()

    def end(self, status=0):
        if not _progress_enabled: return
        if not _timer_progress_enabled: return
        if status == 0 and not os.path.exists(self.time_file):
            open(self.time_file, "w").write("%f\n" % (self.elapsed()))
        _display_progress(timer_completed=True)
        _timer_progresses.remove(self)

    def elapsed(self):
        """ Returns elapsed time since timer creation. """
        return time.time() - self.start_time_

    def estimated(self):
        """ Returns currently estimated time or None. """
        return self.estimated_time_

    @staticmethod
    def load_estimation_times(config_path):
        global _one_iteration_est
        if _one_iteration_est:
            return
        timer_progress.est_build_time = (
            timer_progress.est_build_time or
            timer_progress.load_estimation_time(
            os.path.join(config_path, 'build.time')))
        timer_progress.est_run_time = (
            timer_progress.est_run_time or
            timer_progress.load_estimation_time(
            os.path.join(config_path, 'run.time')))
        if timer_progress.est_build_time and timer_progress.est_run_time:
            _one_iteration_est = (
                timer_progress.est_build_time + timer_progress.est_run_time)

    @staticmethod
    def load_estimation_time(time_file):
        estimated_time = os.path.exists(time_file) and float(
            open(time_file).readline().strip()) or None
        return estimated_time
