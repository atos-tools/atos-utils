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

#include "gcc-plugin.h"
#include "plugin-version.h"
#include "coretypes.h"
#include "tm.h"
#include "tree.h"
#include "flags.h"
#include "plugin-utils.h"
#include "tree-pass.h"
#include "function.h"
#include "diagnostic.h"
#include "langhooks.h"

#include "acf_plugin.h"

acf_ftable_entry_t *acf_ftable;
const char *acf_csv_file_key="csv_file";
char *acf_csv_file;

const char *verbose_key="verbose";
bool verbose = false;

int plugin_is_GPL_compatible;
static const char *plugin_name;

#ifdef PRINT_PASS_LIST
static void do_indent(int tab_number){
    int i;
    for(i=0;i<tab_number;++i){
	printf("\t");
    }
}

static void print_pass_list(struct opt_pass *pass,int tab_number){
    do_indent(tab_number);
    printf("%d: ", pass->static_pass_number);
    switch(pass->type){
    case GIMPLE_PASS:
	printf("GIMPLE_PASS");
	break;
    case RTL_PASS:
	printf("RTL_PASS");
	break;
    case SIMPLE_IPA_PASS:
	printf("SIMPLE_IPA_PASS");
	break;
    case IPA_PASS:
	printf("IPA_PASS");
	break;
    }
    printf(": %s\n",pass->name);
    if(pass->sub){
	print_pass_list(pass->sub,tab_number+1);
    }
    if(pass->next){
	print_pass_list(pass->next,tab_number);
    }
}
#endif /* PRINT_PASS_LIST */

static void event_callback(void *gcc_data,void *data){
    (void)gcc_data;
    fprintf(stderr,"%s called\n",plugin_event_name[*(int*)data]);
}

extern void cplus_decl_attributes(tree *, tree, int) __attribute__((weak));

typedef void (*decl_attributes_func_type)
    (tree *decl,tree attributes,int flags);
static decl_attributes_func_type decl_attributes_func;

void attribute_injector_start_unit_callback(void *gcc_data ATTRIBUTE_UNUSED,
					    void *data ATTRIBUTE_UNUSED){
    if(is_gcc()){
	decl_attributes_func=(decl_attributes_func_type)(&decl_attributes);
    }else{
	decl_attributes_func=&cplus_decl_attributes;
    }
}

extern tree maybe_constant_value (tree) __attribute__((weak));


/* Replaces any constexpr expression that may be into the attributes
   arguments with their reduced value.  */

static void
my_cp_check_const_attributes (tree attributes)
{
  tree attr;
  for (attr = attributes; attr; attr = TREE_CHAIN (attr))
    {
      tree arg;
      for (arg = TREE_VALUE (attr); arg; arg = TREE_CHAIN (arg))
	{
	  tree expr = TREE_VALUE (arg);
	  if (EXPR_P (expr))
	    TREE_VALUE (arg) = maybe_constant_value (expr);
	}
    }
}

static int parse_ftable_csv_file(acf_ftable_entry_t **acf_ftable_p,
				 char *csv_file, bool verbose)
{
  int nb = 0;

  nb = acf_parse_csv(csv_file, acf_ftable_p, verbose);

  return nb;
}

/* Check if opt_file from csv configuration file matches
   current compiled file */
static bool source_file_match(char *opt_file, char *input_file)
{
    bool ret;

    if (opt_file == NULL || input_file == NULL) {
#if ACF_DEBUG
	fprintf(stderr, "Source file %s, %s: unspecified\n",
		(opt_file == NULL?"(null)":opt_file),
		(input_file == NULL?"(null)":input_file));
#endif
	return true;
    }
    /* if opt_file name without path, just compare it to basename
       of input_file name.
       Otherwise compare full path. */
    if (strcmp(basename(opt_file), opt_file) == 0) {
	ret = !strcmp(opt_file, basename(input_file));
    } else {
	ret = !strcmp(opt_file, input_file);
    }
#if ACF_DEBUG
    fprintf(stderr, "Source file %s, %s: %s\n", opt_file, input_file,
	    (ret?"matching":"not matching"));
#endif
    return ret;
}

int func_number = 0;
bool csv_parsed = false;

static void attribute_injector_finish_decl_callback(void *gcc_data,void *data){
    tree decl=(tree)gcc_data;
    const char *decl_fullname;
    tree attribute_identifier;
    tree attribute_list=NULL_TREE;
    tree argument = NULL_TREE;
    tree argument_list=NULL_TREE;
    volatile tree def_opts;
    volatile tree opts;
    const char *cur_func_name = NULL;
    int i;
#if ACF_REMOTE_DEBUG
    int acf_remote_debug = 1;
#endif

#if ACF_TRACE
    if(DECL_P(decl)&&is_targetable_decl(decl) &&
       MATCH(decl, match_tree_code(equal_to(FUNCTION_DECL)))) {
	decl_fullname=lang_hooks.decl_printable_name(decl,2);
	fprintf(stderr,"acf_plugin: Processing function %s (%s)\n",
		decl_fullname,
		IDENTIFIER_POINTER (DECL_ASSEMBLER_NAME (cfun->decl)));
    }
#endif /* ACF_TRACE */

#if ACF_REMOTE_DEBUG
    while (acf_remote_debug)
	sleep(2);
#endif
    cur_func_name = IDENTIFIER_POINTER (DECL_ASSEMBLER_NAME (cfun->decl));

    if (!csv_parsed) {
	func_number = parse_ftable_csv_file(&acf_ftable,
					    acf_csv_file, verbose);
	csv_parsed = true;
    }

    if (func_number < 0){
	/* Error already reported */
	return;
    }
    for (i = 0; i < func_number; i++){
	char *func_name = acf_ftable[i].func_name;
	char *opt_attr = acf_ftable[i].opt_attr;
	char *opt_arg = acf_ftable[i].opt_arg;
	char *opt_file = acf_ftable[i].opt_file;

	attribute_identifier =  get_identifier(opt_attr);
	if ((strcmp (func_name, cur_func_name) == 0) &&
	    source_file_match(opt_file, (char *) main_input_filename)) {
	    if (verbose) {
		fprintf(stdout, "acf_plugin: Attaching attribute to "
			"function %s: %s %s",
			cur_func_name, opt_attr, opt_arg);
		if (opt_file == NULL)
		    fprintf(stdout, "\n");
		else
		    fprintf(stdout, " (file: %s)\n",opt_file);
	    }
	    if (opt_arg != NULL) {
		argument = build_string(strlen(opt_arg), opt_arg);
		argument_list =  tree_cons(NULL_TREE, argument, argument_list);
	    } else {
		argument_list = NULL_TREE;
	    }

	    attribute_list = tree_cons(attribute_identifier, argument_list,
				       attribute_list);

	    my_cp_check_const_attributes (attribute_list);
	    if(attribute_list != NULL_TREE){
		decl_attributes_func(&decl,attribute_list,
				     ATTR_FLAG_TYPE_IN_PLACE);
	    }
	} else {
	    /*	fprintf(stderr, "NOT optimizing %s\n", cur_func_name); */
	}
    }
}

static int pre_genericize=PLUGIN_PRE_GENERICIZE;
static int start_unit=PLUGIN_START_UNIT;
static int finish_unit=PLUGIN_START_UNIT;

int plugin_init(struct plugin_name_args *plugin_na,
		struct plugin_gcc_version *version){
    plugin_name=plugin_na->base_name;
    FILE *fcsv;
    int csv_arg_pos = -1;
    bool bad = false;
    int i;

#if 0
    /* higly strict version checking : plugin is built by the
       same gcc revision that loads it. */
    if(!plugin_default_version_check(version,&gcc_version)){
	error("%s: build gcc and load gcc version mismatch.", plugin_name);
	return 1;
    }
#endif

#if ACF_DEBUG
    fprintf(stderr, "---------------------\n");
    fprintf(stderr,"Hello World from the %s !\n", plugin_name);
    if (plugin_na->argc >= 1)
	fprintf(stderr, "args number= %d\n", plugin_na->argc);
    for (i = 0; i < plugin_na->argc; i++) {
	fprintf(stderr, "key_arg= (%s) -> arg_value= (%s)\n",
		plugin_na->argv[i].key, plugin_na->argv[i].value);
    }
    fprintf(stderr, "---------------------\n");
#endif

    /* Check options */
    switch (plugin_na->argc) {
    case 0:
	bad = true;
	break;
    case 1:
	if (strcmp(plugin_na->argv[0].key, acf_csv_file_key) == 0) {
	    csv_arg_pos = 0;
	} else {
	    bad = true;
	}
	break;
    case 2:
	for (i = 0; i < plugin_na->argc; i++) {
	    if (strcmp(plugin_na->argv[i].key, verbose_key) == 0) {
		verbose = true;
	    }
	    if (strcmp(plugin_na->argv[i].key, acf_csv_file_key) == 0) {
		csv_arg_pos = i;
	    }
	}
	if (!verbose || csv_arg_pos == -1) {
	    bad = true;
	}
	break;
    default:
	bad = true;
	break;
    }

    if (bad) {
	fprintf(stderr,
		"Usage for %s: -fplugin=<path>/%s.so -fplugin-arg-%s-%s="
		"<path-to-csv-file> [-fplugin-arg-%s-%s]\n",
		plugin_name, plugin_name,
		plugin_name, acf_csv_file_key,
		plugin_name, verbose_key);
	return 1;
    }

    if (strcmp(plugin_na->argv[csv_arg_pos].key, acf_csv_file_key) == 0) {
	acf_csv_file = plugin_na->argv[csv_arg_pos].value;
	if ((fcsv = fopen(acf_csv_file, "r")) == NULL) {
	    fprintf(stderr,"Error in %s: csv file not found: %s\n",
		    plugin_name, acf_csv_file);
	    bad = true;
	} else {
	    fclose(fcsv);
	}
    } else {
	fprintf(stderr,"Error in %s: Unknown option %s\n", plugin_name,
		plugin_na->argv[csv_arg_pos].key);
	return 1;
    }

    register_callback(plugin_na->base_name,
		      PLUGIN_START_UNIT,
		      &attribute_injector_start_unit_callback,NULL);
    register_callback(plugin_na->base_name,
		      PLUGIN_PRE_GENERICIZE,
		      &attribute_injector_finish_decl_callback,
		      &pre_genericize);

#ifdef PRINT_PASS_LIST
    printf("\n####### ALL PASSES LIST #######\n");
    print_pass_list(all_passes,0);
    printf("\n\n####### ALL SMALL IPA PASSES LIST #######\n");
    print_pass_list(all_small_ipa_passes,0);
    printf("\n\n####### ALL REGULAR IPA PASSES LIST #######\n");
    print_pass_list(all_regular_ipa_passes,0);
    printf("\n\n####### ALL LOWERING PASSES LIST #######\n");
    print_pass_list(all_lowering_passes,0);
    printf("\n\n####### ALL LTO GEN PASSES LIST #######\n");
    print_pass_list(all_lto_gen_passes,0);
#endif /* PRINT_PASS_LIST */

    return 0;
}
