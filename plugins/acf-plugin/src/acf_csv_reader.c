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
// func_name, attribute_name, attribute_arguments
// For C++ functions, the mangled name must be used
// Only the 3rd entry (attribute_argument) and 4th entry (source file)
// are optional.
// Malformed lines are discarded.
// Examples:
// square,optimize,O3
// main,optimize,Os
// _Z5func2Pi,noinline,file2.cpp
// _Z5func1Pi,noinline,/path1/path2/file1.c

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

    printf("Number of rows: %d\n",clist->rows_number);
    if (clist->rows_number == 0) {
	printf("CSV list empty\n");
	return;
    } else {
	crow = clist->rows;
    }

    while (crow != NULL) {
	if (crow->columns_number == 0) {
	    printf("\n");
	} else {
	    ccol = crow->columns;
	    while (ccol != NULL) {
		printf("{%s},", ccol->csv_entry);
		ccol = ccol->next_column;
	    }
	    printf("\n");
	}
	crow = crow->next_row;
    }

    return;
}

void acf_ftable_display(acf_ftable_entry_t *acf_ftable) {
    int table_r;

#if CSV_READER_DEBUG
    printf("Number of entries: %d\n", acf_ftable_size);
#endif

  for (table_r = 0; table_r < acf_ftable_size; table_r++) {
      printf("%s,", acf_ftable[table_r].func_name);
      printf("%s,", acf_ftable[table_r].opt_attr);
      printf("%s,", (acf_ftable[table_r].opt_arg != NULL ?
		     acf_ftable[table_r].opt_arg : "(null)"));
      printf("%s\n", (acf_ftable[table_r].opt_file != NULL ?
		      acf_ftable[table_r].opt_file : "(null)"));
  }

  return;
}

void readCSV(FILE *file, struct csv_list *clist) {
    char line1[MAX_LINE_SIZE];
    char line2[MAX_LINE_SIZE];
    char line3[MAX_LINE_SIZE];
    char *stptr;
    int flag = 0;
    int idx = 0;
    int lcount = 0; /* Cell Seperator */
    int lines = 0; /* number of lines in file */

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
	printf("acf_plugin error: CSV file not found: %s\n", filename);
	return -1;
    }

    csv_list_init(&parsed_csv);
    readCSV(file, &parsed_csv);

    // Populate acf_ftable
    if (parsed_csv.rows_number == 0) {
	if (verbose)
	    printf("acf_plugin warning: No entry found in CSV file : %s\n",
		   filename);
	return -1;
    } else {
	int tsize = parsed_csv.rows_number * sizeof(acf_ftable_entry_t);

	*acf_ftable_p = (acf_ftable_entry_t *) malloc(tsize);
	if (*acf_ftable_p == NULL) {
	    printf("acf_plugin error: malloc() failed: size= %d\n", tsize);
	    return -1;
	}
    }

    acf_ftable_entry_t *acf_ftable = *acf_ftable_p;

    cur_line = 1;
    table_r = 0;

    crow = parsed_csv.rows;
    for(; crow != NULL; crow = crow->next_row, cur_line++) {
	if(crow->columns_number) {
	    ccol = crow->columns;
	    int table_c = 0;
	    /* Discard empty or imcomplete lines (only argument and
	       source file are optional) */
	    int discard = 0;
	    int argument_null = 0;
	    int file_null = 0;

	    for(;ccol != NULL; ccol = ccol->next_column) {
		switch (table_c) {
		case 0:
		    if (strcmp ((char *) ccol->csv_entry, "") == 0) {
			if (verbose)
			    printf("acf_plugin warning: discarded line %d: "
				   "function name unspecified\n",
				   cur_line);
			discard = 1;
		    }
		    break;
		case 1:
		    if (strcmp((char *) ccol->csv_entry, "") == 0) {
			if (verbose)
			    printf("acf_plugin warning: discarded line %d: "
				   "attribute unspecified\n",
				   cur_line);
			discard = 1;
		    }
		    break;
		case 2:
		    if (strcmp((char *) ccol->csv_entry, "") == 0) {
			argument_null = 1;
		    }
		    break;
		case 3:
		    if (strcmp((char *) ccol->csv_entry, "") == 0) {
			file_null = 1;
		    }
		    break;
		default:
		    break;
		}
		table_c++;
	    }

	    if (discard)
		continue;

	    if (table_c < CSV_REQ_ENTRIES) {
		if (verbose)
		    printf("acf_plugin warning: discard icomplete line %d\n",
			   cur_line);
		continue;
	    }
	    if (table_c > CSV_MAX_ENTRIES) {
		if (verbose)
		    printf("acf_plugin warning: discarded line %d: "
			   "more than %d entries\n",
			   cur_line, CSV_MAX_ENTRIES);
		continue;
	    }

	    ccol = crow->columns;
	    table_c = 0;
	    for(;ccol != NULL; ccol = ccol->next_column) {
#if CSV_READER_DEBUG_ALLOC
		printf("{%s} ", ccol->csv_entry);
#endif
		switch (table_c) {
		case 0:
		    acf_ftable[table_r].func_name = (char *)
			malloc(strlen(ccol->csv_entry) + 1);
		    strcpy (acf_ftable[table_r].func_name,
			    (char *) ccol->csv_entry);
		    break;
		case 1:
		    acf_ftable[table_r].opt_attr = (char *)
			malloc(strlen(ccol->csv_entry) + 1);
		    strcpy (acf_ftable[table_r].opt_attr,
			    (char *) ccol->csv_entry);
		    break;
		case 2:
		    if (argument_null) {
			// Initialize empty argument
			acf_ftable[table_r].opt_arg = (char *) NULL;
		    } else {
			acf_ftable[table_r].opt_arg = (char *)
			    malloc(strlen(ccol->csv_entry) + 1);
			strcpy (acf_ftable[table_r].opt_arg,
				(char *)ccol->csv_entry);
		    }
		    break;
		case 3:
		    if (file_null) {
			// Initialize empty source file information
			acf_ftable[table_r].opt_file = (char *) NULL;
		    } else {
			acf_ftable[table_r].opt_file = (char *)
			    malloc(strlen(ccol->csv_entry) + 1);
			strcpy (acf_ftable[table_r].opt_file,
				(char *)ccol->csv_entry);
		    }
		    break;
		default:
		    if (verbose)
			printf("acf_plugin warning: CSV entry with more "
			       "than %d entries\n", CSV_MAX_ENTRIES);
		}
		table_c++;
	    }
	    // Initialize empty argument and source file
	    if (table_c == 2) {
		acf_ftable[table_r].opt_arg = (char *) NULL;
		acf_ftable[table_r].opt_file = (char *) NULL;
	    }
	    if (table_c == 3) {
		acf_ftable[table_r].opt_file = (char *) NULL;
	    }
	    table_r++;
	}
#if CSV_READER_DEBUG_ALLOC
	printf("\n");
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
	printf("acf_plugin error: CSV file not found: %s\n", filename);
	return -1;
    }

    status = acf_parse_csv(filename, &acf_ftable, 1);
    printf("acf_parse_csv() return value: %d\n", status);

    printf("========================================\n");
    /* Display content of intermediate csv list */
    printf("CSV list content:\n");
    csv_list_display(&parsed_csv);
    printf("========================================\n");

    printf("C table content:\n");
    if (status >= 0) {
	if (status != acf_ftable_size) {
	    printf("Error in acf_parse_csv(): returned value(%d) != "
		   "acf_ftable_size (%d)\n", status, acf_ftable_size);
	}

	acf_ftable_display(acf_ftable);
	printf("acf_ftable_size= %d\n", acf_ftable_size);
    }
    else
	printf("C table not available: status= %d\n", status);

    return 0;
}
#endif
