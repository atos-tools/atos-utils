/*
 * Copyright (C) 2012-2013 STMicroelectronics
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef ACF_PLUGIN_PLUGIN_SRC_ACF_PLUGIN_H_
#define ACF_PLUGIN_PLUGIN_SRC_ACF_PLUGIN_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Maximum number of arguments for a function attribute or gcc param */
/* arguments may be strings/integers */
#define MAX_ARGS 10

#define CSV_MAX_ENTRIES (3 + MAX_ARGS)
/* Only funcname and attribute required but filename in 2nd position */
#define CSV_REQ_ENTRIES 3

struct csv_list {
    struct csv_row *rows;
    struct csv_row *last_row; /* Direct access for row addition */
    int rows_number;
};

struct csv_row {
    struct csv_row *next_row;
    struct csv_column *columns;
    struct csv_column *last_column;
    int columns_number;
};

struct csv_column {
    struct csv_column *next_column;
    char *csv_entry;
};

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
    size_t func_name_len;
    char *opt_file;
    size_t opt_file_len;
    char *opt_attr; /* gcc function attribute or "param" for parameters */
    int attr_arg_number; /* number of args of the attribute/param */
    attr_arg opt_args[MAX_ARGS];  /* list of args of the attribute/param */
} acf_ftable_entry_t;

#define IS_CSV_PARAM(acf_entry) (strcmp("param", acf_entry->opt_attr) == 0)

#ifdef __cplusplus
extern "C" {
#endif

#define PRINTF(...) fprintf(stderr, __VA_ARGS__)
#define VERBOSE(...) fprintf(stderr, __VA_ARGS__)
#define DEBUG(...) fprintf(stderr, __VA_ARGS__)
#define xstr(s) str(s)
#define str(s) #s

#ifdef __cplusplus
}
#endif

void initCSV(struct csv_list *clist);
bool readCSV(char *filename, struct csv_list *clist);
/* Return number of functions if cvs file parsing is ok.
   Negative value otherwise.
*/
int parseCSV(struct csv_list *clist, acf_ftable_entry_t **acf_ftable_p,
             int verbose);

#endif /* ACF_PLUGIN_PLUGIN_SRC_ACF_PLUGIN_H_ */
