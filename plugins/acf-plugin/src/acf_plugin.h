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

typedef struct acf_ftable_entry {
    char *func_name;
    char *opt_attr;
    char *opt_arg;
    char *opt_file;
} acf_ftable_entry_t;

#define CSV_MAX_ENTRIES 4
#define CSV_REQ_ENTRIES 2

#ifdef __cplusplus
extern "C" {
#endif

/* Return number of functions if cvs file parsing ok, negative value otherwise */
int acf_parse_csv(char *filename, acf_ftable_entry_t **acf_ftable_p, int verbose);

#ifdef __cplusplus
}
#endif

#endif
