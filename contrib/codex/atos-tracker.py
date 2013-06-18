#! /usr/bin/env python
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
# Query ATOS codex bugs tracker
#
# Usage:
#   atos-tracker.py
#      --predef=open_bugs|open_enhs|fixed_open
#   atos-tracker.py
#      --filter="severity:(blocking|serious),type:bug"
#      --fields=artifact_id,type,severity,status_id,resolution_id,summary
#      --sortedby=severity,status_id



import sys, os, re, commands, operator, optparse


# ATOS project name and tracker/report ids
codex_project = "atos"
codex_tracker_id = 5270
codex_report_id = 7284

# codex server address
codex_host = "hostname/soap/codendi.wsdl.php?wsdl"

# directory containing codendi.php script
codendi_cli_dir = "/sw/st/gnu_compil/comp/scripts/codendi_cli-1.5.0"

# php executable to use
php_bin = os.getenv("PHP", "") or "/usr/bin/php"

# codex user name (can be different than $USER)
codex_user = os.getenv("USER", "")

# list of fields displayed by default
default_fields = [
    'artifact_id', 'type', 'severity', 'status_id', 'resolution_id',
    'summary', 'assigned_to', 'submitted_by', 'version']

# default sorting order
default_sortedby = [
    'type', 'severity', 'artifact_id'
    ]

# list of predefined queries/reports
predefined_reports = {
    "open_bugs": {
        "filter": "type:bug,status_id:open,resolution_id:None",
        "fields": "artifact_id,severity,summary",
        "sortedby": "severity,artifact_id"
        },
    "open_enhs": {
        "filter": "type:enhancement,status_id:open,resolution_id:None",
        "fields": "artifact_id,severity,summary",
        "sortedby": "severity,artifact_id"
        },
    "fixed_open": {
        "filter": "status_id:open,resolution_id:Fixed",
        "fields": "artifact_id,severity,summary,submitted_by",
        "sortedby": "artifact_id"
        }
    }


def login(opts):
    command = [
        php_bin, os.path.join(codendi_cli_dir, "codendi.php"),
        "login",
        "--host=" + codex_host, "--secure",
        "--project=" + codex_project,
        "--username=" + opts.user,
        ]
    print " ".join(command)
    return os.system(" ".join(command))


def logout(opts):
    command = [
        php_bin, os.path.join(codendi_cli_dir, "codendi.php"),
        "logout"]
    return os.system(" ".join(command))


def report(opts):

    #
    # login if necessary
    #

    command = [
        php_bin, os.path.join(codendi_cli_dir, "codendi.php"),
        "myprojects"
        ]
    status, output = commands.getstatusoutput(" ".join(command))
    if status: login(opts)

    #
    # query for all project artifacts
    #

    command = [
        php_bin, os.path.join(codendi_cli_dir, "codendi.php"),
        "tracker",
        "reportlist",
        "--tracker_id=" + str(codex_tracker_id),
        "--report_id=" + str(codex_report_id),
        ]
    status, output = commands.getstatusoutput(" ".join(command))

    assert status == 0

    #
    # build results list from output
    #

    # +---------------+-------------------------------------------------------+
    # |  field_name   |                      field_value                      |
    # +---------------+-------------------------------------------------------+
    # | resolution_id | None                                                  |
    # | field_30      | 2.0                                                   |
    # | severity      | Serious                                               |
    # | status_id     | Open                                                  |
    # | field_62      | Bug                                                   |
    # | artifact_id   | 218281                                                |
    # | summary       | atos-explore-acf misbehaviour with some function name |
    # | open_date     | 1371201402                                            |
    # | assigned_to   | moynault                                              |
    # | submitted_by  | herve_knochel                                         |
    # +---------------+-------------------------------------------------------+

    all_artifacts = []

    output_tables = output.strip().split("\n\n")
    # skip the 2 first tables
    output_tables = output_tables[2:]
    for artifact_table in output_tables:
        artifact = {}
        table_lines = artifact_table.split("\n")
        # skip the 4 1st lines and the last line
        table_lines = table_lines[4:-1]
        for table_line in table_lines:
            words = table_line.split()
            key = words[1]
            # field_id replacements
            key = key.replace("field_30", "version")
            key = key.replace("field_62", "type")
            # skip | separators
            value = " ".join(words[3:-1])
            artifact[key] = value
        all_artifacts.append(dict(artifact))

    #
    # filter results
    #

    query = opts.filter and dict(
        map(lambda x: x.split(':'), opts.filter.split(','))) or {}

    selected_artifacts = (
        filter(lambda x: all(map(
                    lambda (k, v): re.match(
                        '^%s$' % v, x.get(k, ''), flags=re.I),
                    query.items())), all_artifacts))

    if not selected_artifacts: return

    #
    # print results
    #

    fields = (
        opts.fields and opts.fields.split(',') or default_fields)

    sortedby = (
        opts.sortedby and opts.sortedby.split(',') or default_sortedby)

    sorted_results = sorted(
        selected_artifacts, key=operator.itemgetter(*sortedby))

    field_width = {}
    for field in fields:
        values = ['*%s*' % field] + map(
            operator.itemgetter(field), sorted_results)
        field_width[field] = max(map(len, values))

    # | *artifact_id* | *severity* | *summary*                               |
    # | 218474        | Blocking   | LibAV: missing dependencies             |
    # | 172790        | Minor      | mibench/telecom/gsm cannot be audited   |
    # | 172791        | Minor      | Missing build dependency on mibench/    |

    print >>sys.stdout, '|',
    for field in fields:
        fmt = ('%%-%ds' % (field_width[field]))
        print >>sys.stdout, fmt % ('*%s*' % (field)),
        print >>sys.stdout, '|',
    print >>sys.stdout, ''

    for result in sorted_results:
        print >>sys.stdout, '|',
        for field in fields:
            fmt = ('%%-%ds' % (field_width[field]))
            print >>sys.stdout, fmt % ('%s' % (result[field])),
            print >>sys.stdout, '|',
        print >>sys.stdout, ''


if __name__ == "__main__":

    parser = optparse.OptionParser()

    # predefined reports
    parser.add_option(
        '--predef', dest='predef_report', action='store', default=None,
        help='predefined report (default: None, choices: %s)' %
        str(predefined_reports.keys()))

    # results queries
    parser.add_option(
        '--filter', dest='filter', action='store', default=None,
        help='filter results (ex: status_id:open,severity:(blocking|serious))')
    parser.add_option(
        '--fields', dest='fields', action='store',
        default=",".join(default_fields),
        help='listed fields (default: all: %s)' % ",".join(default_fields))
    parser.add_option(
        '--sortedby', dest='sortedby', action='store',
        default=",".join(default_sortedby),
        help='sorted fields order (default: %s)' % ",".join(default_sortedby))

    # codex login/logout info
    parser.add_option(
        '--login', dest='login', action='store_true',
        help="codex login before query")
    parser.add_option(
        '--logout', dest='logout', action='store_true',
        help="codex logout after query")
    parser.add_option(
        '--user', dest='user', action='store', default=codex_user,
        help='help: codex user name (default: %s)' % codex_user)

    opts, args = parser.parse_args()

    if opts.predef_report:
        for (key, val) in (
            predefined_reports[opts.predef_report].items()):
            exec "opts.%s = \"%s\"" % (key, val)

    if opts.login: login(opts)

    report(opts)

    if opts.logout: logout(opts)
