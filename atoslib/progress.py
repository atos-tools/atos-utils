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

import globals
import atos_lib
import process
import logger
import generators


def setup(kwargs):
    """
    Configure the ATOS progress logger.
    """
    config.setup(kwargs)

class config:
    """
    Configuration for this module.
    """
    # display of exploration progress messages
    progress_enabled = True

    # display of build/run progress messages
    timer_progress_enabled = True

    # number of run for each iteration exploration
    nb_runs = 1

    @staticmethod
    def setup(kwargs):

        # no progress message in quiet mode
        config.progress_enabled = not kwargs.get('quiet', False)

        if os.getenv("ATOS_NO_PROGRESS"): config.progress_enabled = False

        # disable update of progress line if stdout is redirected or piped
        config.timer_progress_enabled = (
            config.progress_enabled and sys.stdout.isatty())

        # get number of runs from command line if any, else from config.json
        args_nb_runs = kwargs.get(
            'nbruns', None)
        args_configuration_path = kwargs.get(
            'configuration_path', globals.DEFAULT_CONFIGURATION_PATH)
        config.nb_runs = args_nb_runs if args_nb_runs is not None else int(
            atos_lib.get_config_value(args_configuration_path,
                                      "default_values.nb_runs", 1))

# display on stdout a progress status line looking like:
#    Remaining exploration time: 00:00:07, 65.8% done (expl-func 57/60,
#        variant 2/2, expl-staged 8/8, stage 4/4).
#        Current build remaining time: 00:00:01 (4.5% done).
def _display_progress(expl_stage="update", timer_stage="update"):

    def remaining_time_str(remaining):
        if remaining is None: return '??:??:??'
        remaining = int(remaining)
        hours, remaining = divmod(remaining, 3600)
        minutes, seconds = divmod(remaining, 60)
        return '%2d:%02d:%02d' % (hours, minutes, seconds)

    assert(expl_stage in ["init", "update", "end"])
    assert(timer_stage in ["init", "update", "end"])
    status_str = ""

    explorations = exploration_progress.explorations()
    if len(explorations) > 0:
        main_progress = explorations[0]
        main_completion = (1.0 if main_progress.maxval == 0 else
                           min(
                float(main_progress.value) / main_progress.maxval, 1.0))
        main_remaining_nb = main_progress.remaining()
        main_estimated = main_progress.estimated()

        if expl_stage == "init":
            status = "Estimated time: %s," % (
                remaining_time_str(main_estimated))
        elif expl_stage == "update":
            status = "Remaining time: %s," % (
                remaining_time_str(main_estimated))
        elif expl_stage == "end":  # pragma: branch_always
            status = "Elapsed time: %s," % (
                remaining_time_str(main_progress.elapsed()))
        status_str += "%s %3.0f%% done" % (status, main_completion * 100)

        progress_details = (  # remove last exploration progresses (??)
            explorations[0:1] + explorations[1:-1])
        progress_strings = []
        for progress_detail in progress_details:
            progress_strings += ["%s %d/%d" % (
                    progress_detail.descr,
                    min(progress_detail.value + 1, progress_detail.maxval),
                    progress_detail.maxval)]
        status_str += " (%s)." % ", ".join(progress_strings)

    # no line update if stdout is not a tty
    if sys.stdout.isatty():  # pragma: uncovered
        for timer in timer_progress.timers():
            estimated = timer.estimated()
            if not estimated:
                continue
            elapsed = timer.elapsed()
            completion = (1.0 if timer_stage == "end" else
                          min(elapsed / estimated, 1.0))
            remaining = (0.0 if timer_stage == "end" else
                         max(estimated - elapsed, 0.0))
            status = "%16s: %s remaining, %3.0f%% done." % (
                "Current " + timer.progress_type(),
                remaining_time_str(remaining),
                completion * 100.0)
            if status_str != "": status_str += " "
            status_str += status
        # pad with space to clear previous message and
        # clamp msg to terminal width,
        with os.popen("tput cols", "r") as tput:
            cols = int(tput.readline())
        nb_spaces = max(cols - len(status_str), 0)
        status_str += nb_spaces * " "
        status_str = status_str[:cols]
        last_char = "\n" if expl_stage != "update" else "\r"
        status_str = "\r" + status_str + last_char
    else:
        status_str += "\n"

    sys.stdout.write(status_str)
    sys.stdout.flush()

class exploration_progress():
    """
    Holder for an exploration progress status.
    Call constructor (resp. end()) before (resp. after) exploration.
    Call update() after each exploration step.
    """
    explorations_ = []

    def __init__(
        self, descr=None, maxval=100, value=0, visible=True, config_path=None):
        """
        Creates a new exploration with the given estimated maxval iterations.
        If nested, only the first exploration progress will be displayed.
        """
        if not config.progress_enabled: return
        self.visible = visible
        if not self.visible: return
        self.descr = descr
        self.maxval = maxval
        self.value = value
        self.estimate_ = estimated_times(config_path)
        self.start_time_ = time.time()
        self.is_main_exploration = len(exploration_progress.explorations_) == 0
        exploration_progress.explorations_.append(self)
        if self.is_main_exploration:
            _display_progress(expl_stage="init")

    def update(self, value=None, maxval=None):
        """
        Updates the current exploration value and maxval, or increment value.
        Displays the progress status.
        """
        if not config.progress_enabled: return
        if not self.visible: return
        if value is None:
            self.value += 1
        else:
            self.value = value
        if maxval is not None:
            self.maxval = maxval
        if self.is_main_exploration:
            _display_progress()

    def end(self):
        """ Completes the exploration and emit completion message. """
        if not config.progress_enabled: return
        if not self.visible: return
        if self.is_main_exploration:
            _display_progress(expl_stage=(
                    "end" if len(exploration_progress.explorations_) == 1 else
                    "update"))
        exploration_progress.explorations_.remove(self)

    def elapsed(self):
        """ Returns the curretly elapsed time for the exploration. """
        return time.time() - self.start_time_

    def remaining(self):
        """ Returns the number of remaining iterations. """
        return max(self.maxval - self.value, 0)

    def estimated(self):
        """ Returns the estimated remaining time or None. """
        iteration_estimate = self.estimated_iteration()
        if iteration_estimate != None:
            return iteration_estimate * self.remaining()
        else:
            return None

    def estimated_iteration(self):
        """ Get currently estimated iteration time (build+run) or None. """
        build_time = self.estimate_.get_estimated_time('build')
        run_time = self.estimate_.get_estimated_time('run')
        if build_time and run_time:
            return build_time + run_time * config.nb_runs
        else:
            return None

    @staticmethod
    def explorations():
        """
        Returns the list of current explorations.
        The initial creation order is preserved.
        """
        return exploration_progress.explorations_

class timer_progress():
    """
    Holder for build/run progress timer.
    """

    timers_ = []
    timer_ = None

    def __init__(self, progress_type=None, variant_id=None, config_path=None):
        """
        Creates a new timer object for a build or run.
        Displays starting progress message and
        launches the display timer thread if not active
        """
        if not config.progress_enabled: return
        assert progress_type in ["build", "run"]
        self.progress_type_ = progress_type
        self.variant_id_ = variant_id
        self.estimate_ = estimated_times(config_path)
        self.start_time_ = time.time()
        if config.timer_progress_enabled:
            timer_progress.timers_.append(self)
            timer_progress.start_progress_timer_()
            _display_progress(timer_stage="init")

    def end(self, status=0):
        """ Completes the timer object and display completion message. """
        if not config.progress_enabled: return
        if status == 0:
            self.estimate_.set_estimated_time(self.progress_type_,
                                              self.elapsed())
        if config.timer_progress_enabled:
            _display_progress(timer_stage="end")
            timer_progress.timers_.remove(self)

    def elapsed(self):
        """ Returns elapsed time since timer creation. """
        return time.time() - self.start_time_

    def estimated(self):  # pragma: uncovered (not isatty)
        """ Returns currently estimated time or None. """
        return self.estimate_.get_estimated_time(self.progress_type_)

    def progress_type(self):  # pragma: uncovered (not isatty)
        """ Returns the progress type as passed in the constructor. """
        return self.progress_type_

    @staticmethod
    def timers():  # pragma: uncovered (not isatty)
        """ Returns the currently active list of timers. """
        return timer_progress.timers_

    @staticmethod
    def start_progress_timer_():
        """ Starts the display update thread if not active. """
        if not timer_progress.timer_:
            timer_progress.timer_ = atos_lib.repeattimer(
                _display_progress, 1.0).start()

class estimated_times():
    """
    Cache for build/run time estimations.
    """

    def __init__(self, config_path):
        """ Creates a cache object for time estimations. """
        assert(config_path != None)
        self.config_path_ = config_path
        self.progress_time_ = {'build': None, 'run': None}

    def set_estimated_time(self, progress_type, elapsed):
        """ Set estimated time if not already done. """
        assert(progress_type in ["build", "run"])
        self.store_time_once_("%s.time" % progress_type, elapsed)

    def get_estimated_time(self, progress_type):
        """ Get currently estimated time or return None. """
        assert(progress_type in ["build", "run"])
        if self.progress_time_[progress_type] == None:
            self.progress_time_[progress_type] = (
                self.load_time_("%s.time" % progress_type))
        return self.progress_time_[progress_type]

    def load_time_(self, object_id):
        """ Load time from object storage or return None. """
        time_file = os.path.join(self.config_path_, object_id)
        if os.path.exists(time_file):
            with open(time_file) as f:
                estimated_time = float(f.readline().strip())
        else:
            estimated_time = None
        return estimated_time

    def store_time_once_(self, object_id, elapsed):
        """ Store to object storage if not available. """
        time_file = os.path.join(self.config_path_, object_id)
        if not os.path.exists(time_file):
            with open(time_file, "w") as f:
                f.write("%f\n" % (elapsed))
