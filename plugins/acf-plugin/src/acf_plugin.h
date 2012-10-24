/*
 * Copyright (C) STMicroelectronics Ltd. 2012
 *
 * This file is part of ATOS.
 *
 * ATOS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License v2.0
 * as published by the Free Software Foundation
 *
 * ATOS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * v2.0 along with ATOS. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef ACF_PLUGIN_DEFINED
#define ACF_PLUGIN_DEFINED_DEFINED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Maximum number of arguments for a function attribute or gcc param */
/* arguments may be strings/integers */
#define MAX_ARGS 10

#define CSV_MAX_ENTRIES (3 + MAX_ARGS)
#define CSV_REQ_ENTRIES 3 /* Only funcname and attribute required but
			     filename in 2nd position */

typedef enum {FUNCNAME, FILENAME, ATTRIBUTE, FIRST_ARG} acf_columns;

typedef enum {
    NO_TYPE,
    STR_TYPE,
    INT_TYPE
} attr_arg_type;

typedef union {
    char *str_arg;
    int int_arg;
} attr_arg_val;

typedef struct {
    attr_arg_type arg_type;
    attr_arg_val av;
} attr_arg;

typedef struct acf_ftable_entry {
    char *func_name;
    char *opt_file;
    char *opt_attr; /* gcc function attribute or "param" for parameters */
    int attr_arg_number; /* number of args of the attribute/param */
    attr_arg opt_args[MAX_ARGS];  /* list of args of the attribute/param */
} acf_ftable_entry_t;

#define IS_CSV_PARAM(acf_entry) (strcmp("param", acf_entry->opt_attr) == 0)

#ifdef __cplusplus
extern "C" {
#endif

/* Return number of functions if cvs file parsing ok, negative value otherwise */
int acf_parse_csv(char *filename, acf_ftable_entry_t **acf_ftable_p, int verbose);

#ifdef __cplusplus
}
#endif

#endif
