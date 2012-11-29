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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "acf_plugin.h"

// Parse a .csv file of attributes per functions of the form:
// func_name, filename, attribute_name, attribute_arguments.
// For C++ functions, the mangled name must be used.
// Only the 1st entry (function name) and 3rd entry (attribute name)
// are mandatory.
// Malformed lines are discarded.
// All entries after attribute name are considered attribute arguments.
// There are two types of attribute arguments:
// - strings (default without extra syntax)
// - integers with extra '#' at begining of value (no spaces allowd before '#')
// Attribute arguments parsing is stopped at first NULL argument. Following
// arguments are discarded but line is not.
// Examples:
// square,,optimize,O3
// main,file1.c,optimize,Os
// _Z5func2Pi,,noinline,file2.cpp
// _Z5func1Pi,/path1/path2/file2.cpp,noinline,
// _Z5func1Pi,/path1/path2/file2.cpp,nonnull,#1,#3,#7,#9
// _Z5func1Pi,/path1/path2/file2.cpp,section,.mysectionname
// _Z5func1Pi,,optimize,tree-parallelize-loops=12
// _Z5func1Pi,,optimize,fp-contract=fast
// GCC --param option support: When "param" keyword is used
// as attribute name, the two following attribute arguments are
// considered as a GCC parameter name and its value.
// Example:
// _Z5func1Pi,,param,max-unroll-times,#4
// _Z5func1Pi,,param,max-inline-insns,#400

// Usage: acf_ftable_size = acf_parse_csv(csv_file,  &acf_ftable, verbose);


#define MAX_LINE_SIZE 5000

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

struct csv_list parsed_csv;

int acf_ftable_size = 0;

void csv_list_init(struct csv_list *clist) {
    clist->rows_number = 0;
    clist->rows = (struct csv_row *) NULL;
    clist->last_row = (struct csv_row *) NULL;

    return;
}

void add_row(struct csv_list *clist) {
    struct csv_row *row_entry;

    row_entry = (struct csv_row *) malloc(sizeof(struct csv_row));
    row_entry->next_row = (struct csv_row *) NULL;
    row_entry->columns = (struct csv_column *) NULL;
    row_entry->last_column = (struct csv_column *) NULL;
    row_entry->columns_number = 0;

    if (clist->rows_number == 0) {
	clist->rows = row_entry;
	clist->last_row = row_entry;
    } else {
	clist->last_row->next_row = row_entry;
	clist->last_row = row_entry;
    }
    clist->rows_number++;

    return;
}

void add_column(struct csv_list *clist, char *value) {
    struct csv_column *col_entry;

    col_entry = (struct csv_column *) malloc(sizeof(struct csv_column));
    col_entry->next_column = (struct csv_column *) NULL;
    col_entry->csv_entry = (char *) malloc(strlen(value) + 1);
    strcpy(col_entry->csv_entry, value);

    if (clist->last_row->columns_number == 0) {
	clist->last_row->columns = col_entry;
	clist->last_row->last_column = col_entry;
    } else {
	clist->last_row->last_column->next_column = col_entry;
	clist->last_row->last_column = col_entry;
    }
    clist->last_row->columns_number++;

    return;
}

void csv_list_display(struct csv_list *clist) {
    struct csv_row *crow;
    struct csv_column *ccol;

    PRINTF("Number of rows: %d\n",clist->rows_number);
    if (clist->rows_number == 0) {
	PRINTF("CSV list empty\n");
	return;
    } else {
	crow = clist->rows;
    }

    while (crow != NULL) {
	if (crow->columns_number == 0) {
	    PRINTF("\n");
	} else {
	    ccol = crow->columns;
	    while (ccol != NULL) {
		PRINTF("{%s},", ccol->csv_entry);
		ccol = ccol->next_column;
	    }
	    PRINTF("\n");
	}
	crow = crow->next_row;
    }

    return;
}

void acf_ftable_display(acf_ftable_entry_t *acf_ftable) {
    int table_r, i;

#if CSV_READER_DEBUG
    DEBUG("Number of entries: %d\n", acf_ftable_size);
#endif

  for (table_r = 0; table_r < acf_ftable_size; table_r++) {
      PRINTF("%s,", acf_ftable[table_r].func_name);
      PRINTF("%s,", (acf_ftable[table_r].opt_file != NULL ?
		      acf_ftable[table_r].opt_file : "(null)"));
      PRINTF("%s,", acf_ftable[table_r].opt_attr);
      if (acf_ftable[table_r].attr_arg_number == 0) {
	  PRINTF("(no arguments)");
      }
      for (i = 0; i < acf_ftable[table_r].attr_arg_number; i++) {
	  switch (acf_ftable[table_r].opt_args[i].arg_type) {
	  case NO_TYPE:
	      break;
	  case STR_TYPE:
	      PRINTF("\'%s\',", (acf_ftable[table_r].opt_args[i].av.str_arg != NULL ?
			     acf_ftable[table_r].opt_args[i].av.str_arg : "(null),"));
	      break;
	  case INT_TYPE:
	      PRINTF("(#)%d,", acf_ftable[table_r].opt_args[i].av.int_arg);
	      break;
	  }
      }
      PRINTF("\n");
  }

  return;
}

void readCSV(FILE *file, struct csv_list *clist) {
    char line1[MAX_LINE_SIZE];
    char line2[MAX_LINE_SIZE];
    char line3[MAX_LINE_SIZE];
    char *stptr;
    int idx = 0;
    int lcount = 0; /* Cell Seperator */

    /* Get a line from file */
    while (fgets(line1,sizeof line1,file) != NULL) {
	lcount = 0;

	/* Replace trailing '\n' if any by '\0' */
	if (line1[strlen(line1) - 1] == '\n') {
	    line1[strlen(line1) - 1] = '\0';
	}

	strcpy(line2,line1);
	stptr = line2;

	add_row(clist);

	/* Ignore lines whose first character is % */
	if (line1[0] == '%')
	    continue;

	/* start going character by character thro the line */
	while (*stptr != '\0')
	    { lcount++;
		/* If field begins with " */
		if (*stptr == '"')
		    {
			int flag = 0;
			idx = 0;
			while (flag == 0)
			    {
				stptr++;
				/* Find corresponding closing " */
				while (*stptr != '"')
				    { line3[idx] = *stptr;
					idx++;
					stptr++;
				    }
				stptr++;
				if (*stptr != '\0' && *stptr == ',')
				    {
					line3[idx] = '\0';
					add_column(clist, line3);
					flag = 1;
				    }
				else if (*stptr != '\0' && *stptr == '"')
				    { line3[idx] = *stptr;
					idx++;
				    }
				else
				    {
					line3[idx] = '\0';
					add_column(clist, line3);
					flag = 1;
				    }
			    }
		    }
		else
		    { idx = 0;
			while (*stptr != '\0' && *stptr != ',')
			    { line3[idx] = *stptr;
				idx++;
				stptr++;
			    }
			line3[idx] = '\0';
			add_column(clist, line3);
		    }
		if (*stptr != '\0' && *stptr == ',')
		    stptr++;
		memmove(line2, stptr, strlen(stptr)+1);
		stptr = line2;
	    }
    }
}

// Return number of functions if csv file parsing ok, negative value otherwise
int acf_parse_csv(char *filename, acf_ftable_entry_t **acf_ftable_p,
		  int verbose) {
    FILE *file;
    int cur_line;
    int table_r;
    struct csv_row *crow;
    struct csv_column *ccol;

    if (!(file = fopen(filename, "r"))) {
        fprintf(stderr, "acf_plugin error: CSV file not found: %s\n", filename);
	return -1;
    }

    csv_list_init(&parsed_csv);
    readCSV(file, &parsed_csv);

    // Populate acf_ftable
    if (parsed_csv.rows_number == 0) {
	if (verbose)
	    VERBOSE("acf_plugin warning: No entry found in CSV file : %s\n",
		    filename);
	return -1;
    } else {
	int tsize = parsed_csv.rows_number * sizeof(acf_ftable_entry_t);

	*acf_ftable_p = (acf_ftable_entry_t *) malloc(tsize);
	if (*acf_ftable_p == NULL) {
	    fprintf(stderr, "acf_plugin error: malloc() failed: size= %d\n", tsize);
	    return -1;
	}
    }

    acf_ftable_entry_t *acf_ftable = *acf_ftable_p;

    cur_line = 1;
    table_r = 0;

    crow = parsed_csv.rows;
    for(; crow != NULL; crow = crow->next_row, cur_line++) {
	int j;

	if(crow->columns_number) {
	    ccol = crow->columns;
	    int table_c = 0;
	    /* Discard empty or imcomplete lines (only argument and
	       source file are optional) */
	    int discard = 0;
	    int argument_nb = 0;
	    int file_null = 0;
	    size_t len;

	    for(;ccol != NULL; ccol = ccol->next_column) {
		switch (table_c) {
		case FUNCNAME:
		    if (strcmp ((char *) ccol->csv_entry, "") == 0) {
			if (verbose)
			    VERBOSE("acf_plugin warning: discarded line %d: "
				    "function name unspecified\n",
				    cur_line);
			discard = 1;
		    }
		    break;
		case FILENAME:
		    if (strcmp((char *) ccol->csv_entry, "") == 0) {
			file_null = 1;
		    }
		    break;
		case ATTRIBUTE:
		    if (strcmp((char *) ccol->csv_entry, "") == 0) {
			if (verbose)
			    VERBOSE("acf_plugin warning: discarded line %d: "
				    "attribute unspecified\n",
				    cur_line);
			discard = 1;
		    }
		    break;
		case FIRST_ARG:
		    for (j = 0; j < MAX_ARGS && ccol != NULL; j++, ccol = ccol->next_column) {
			if (strcmp((char *) ccol->csv_entry, "") != 0) {
			    argument_nb++;
			    table_c++;
			} else {
			    /* Stop at first null entry. */
			    break;
			}
		    }
		    if (ccol && ccol->next_column != NULL) {
			if (verbose)
			    VERBOSE("acf_plugin warning: line %d: discarded entries "
				    "after null argument\n", cur_line);
		    }
		    break;
		default:
		    break;
		}
		table_c++;

		if (ccol == NULL)
		    break;
	    }

	    if (discard)
		continue;

	    if (table_c < CSV_REQ_ENTRIES) {
		if (verbose)
		    VERBOSE("acf_plugin warning: discard icomplete line %d\n",
			    cur_line);
		continue;
	    }
	    if (table_c > CSV_MAX_ENTRIES) {
		if (verbose)
		    VERBOSE("acf_plugin warning: discarded line %d: "
			    "more than %d entries\n",
			    cur_line, CSV_MAX_ENTRIES);
		continue;
	    }

	    ccol = crow->columns;
	    table_c = 0;
	    for(;ccol != NULL; ccol = ccol->next_column) {
#if CSV_READER_DEBUG_ALLOC
		DEBUG("{%s} ", ccol->csv_entry);
#endif
		switch (table_c) {
		case FUNCNAME:
		    len = strlen(ccol->csv_entry);
                    acf_ftable[table_r].func_name_len = len;
		    acf_ftable[table_r].func_name = (char *)
			malloc(len + 1);
		    strcpy (acf_ftable[table_r].func_name,
			    (char *) ccol->csv_entry);
		    break;
		case FILENAME:
		    if (file_null) {
			// Initialize empty source file information
			acf_ftable[table_r].opt_file = (char *) NULL;
		    } else {
		        len = strlen(ccol->csv_entry);
                        acf_ftable[table_r].opt_file_len = len;
			acf_ftable[table_r].opt_file = (char *)
			    malloc(len + 1);
			strcpy (acf_ftable[table_r].opt_file,
				(char *)ccol->csv_entry);
		    }
		    break;
		case ATTRIBUTE:
		    acf_ftable[table_r].opt_attr = (char *)
			malloc(strlen(ccol->csv_entry) + 1);
		    strcpy (acf_ftable[table_r].opt_attr,
			    (char *) ccol->csv_entry);
		    break;
		case FIRST_ARG:
		    if (argument_nb == 0) {
			// Initialize empty argument
			acf_ftable[table_r].attr_arg_number = 0;
			acf_ftable[table_r].opt_args[0].arg_type = NO_TYPE;
		    } else {
			acf_ftable[table_r].attr_arg_number = argument_nb;
			for (j = 0; j < argument_nb && ccol != NULL ; j++, ccol = ccol->next_column) {
			    /* Check if argument is integer (starts with #) */
			    if (ccol->csv_entry[0] == '#') { /* argument is an integer */
				acf_ftable[table_r].opt_args[j].arg_type = INT_TYPE;
				acf_ftable[table_r].opt_args[j].av.int_arg = (int)
				    atoi(ccol->csv_entry + 1); /* skip # */

			    } else { /* argument is a string */
				acf_ftable[table_r].opt_args[j].arg_type = STR_TYPE;
				acf_ftable[table_r].opt_args[j].av.str_arg = (char *)
				    malloc(strlen(ccol->csv_entry) + 1);
				strcpy (acf_ftable[table_r].opt_args[j].av.str_arg,
					(char *) ccol->csv_entry);
			    }
			    table_c++;
			}
		    }
		    break;
		}
		table_c++;

		if (ccol == NULL)
		    break;
	    }
	    // Initialize empty argument
	    if (table_c == FIRST_ARG) {
		acf_ftable[table_r].attr_arg_number = 0;
		acf_ftable[table_r].opt_args[0].arg_type = NO_TYPE;
	    }
	    table_r++;
	}
#if CSV_READER_DEBUG_ALLOC
	DEBUG("\n");
#endif
    }
    acf_ftable_size = table_r;

    return acf_ftable_size;
}

#if CSV_READER_DEBUG
int main(int argc, char **argv) {
    char *filename = argv[1];
    int status = 0;
    acf_ftable_entry_t *acf_ftable;
    FILE *file;

    if (!(file = fopen(filename, "r"))) {
        fprintf(stderr, "acf_plugin error: CSV file not found: %s\n", filename);
	return -1;
    }

    status = acf_parse_csv(filename, &acf_ftable, 1);
    DEBUG("acf_parse_csv() return value: %d\n", status);

    DEBUG("========================================\n");
    /* Display content of intermediate csv list */
    DEBUG("CSV list content:\n");
    csv_list_display(&parsed_csv);
    DEBUG("========================================\n");

    DEBUG("C table content:\n");
    if (status >= 0) {
	if (status != acf_ftable_size) {
	    DEBUG("Error in acf_parse_csv(): returned value(%d) != "
		   "acf_ftable_size (%d)\n", status, acf_ftable_size);
	}

	acf_ftable_display(acf_ftable);
	DEBUG("acf_ftable_size= %d\n", acf_ftable_size);
    }
    else
	DEBUG("C table not available: status= %d\n", status);

    return 0;
}
#endif
