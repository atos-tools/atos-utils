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
#include "params.h"
#include "cgraph.h"
#include "opts.h"

#include "acf_plugin.h"

/* ============================================================ */
/* Setting of global macros
/* ============================================================ */

#ifdef param_values
#define USE_GLOBAL_PARAMS

#ifdef HWI_SHIFT
#undef param_values
#define param_values (*(int **) (((char *) &(global_options.x_param_values)) + hwi_shift))
#undef PARAM_VALUE
#define PARAM_VALUE(ENUM) \
    ((int) ((*(int **) (((char *) &(global_options.x_param_values)) + hwi_shift))[(int) ENUM]))
#endif

#else
#undef USE_GLOBAL_PARAMS
#endif

acf_ftable_entry_t *acf_ftable;
const char *acf_csv_file_key="csv_file";
char *acf_csv_file;

const char *verbose_key="verbose";
bool verbose = false;

#ifdef HWI_SHIFT
const char *hwi_size="host_wide_int";
int gcc_runtime_hwi = 0;
int hwi_shift = 0;
#endif

int plugin_is_GPL_compatible;
static const char *plugin_name;

#ifdef PRINT_PASS_LIST
static void do_indent(int tab_number){
    int i;
    for(i=0;i<tab_number;++i){
	PRINTF("\t");
    }
}

static void print_pass_list(struct opt_pass *pass,int tab_number){
    do_indent(tab_number);
    PRINTF("%d: ", pass->static_pass_number);
    switch(pass->type){
    case GIMPLE_PASS:
	PRINTF("GIMPLE_PASS");
	break;
    case RTL_PASS:
	PRINTF("RTL_PASS");
	break;
    case SIMPLE_IPA_PASS:
	PRINTF("SIMPLE_IPA_PASS");
	break;
    case IPA_PASS:
	PRINTF("IPA_PASS");
	break;
    }
    PRINTF(": %s\n",pass->name);
    if(pass->sub){
	print_pass_list(pass->sub,tab_number+1);
    }
    if(pass->next){
	print_pass_list(pass->next,tab_number);
    }
}
#endif /* PRINT_PASS_LIST */

static void trace_attached_acf(acf_ftable_entry_t *acf_entry, const char *acf_type, const char *func_name) {
    const char *sep = "";
    int i;
    VERBOSE("%s: Attaching %s to "
	    "function %s: %s ",
	    plugin_name, acf_type, func_name, acf_entry->opt_attr);
    for (i = 0; i < acf_entry->attr_arg_number; i++) {
	switch (acf_entry->opt_args[i].arg_type) {
	case NO_TYPE:
	    break;
	case STR_TYPE:
	    VERBOSE("%s%s", sep, (acf_entry->opt_args[i].av.str_arg != NULL ?
				  acf_entry->opt_args[i].av.str_arg : "(null),"));
	    break;
	case INT_TYPE:
	    VERBOSE("%s#%d", sep, acf_entry->opt_args[i].av.int_arg);
	    break;
	}
	sep = ",";
    }
    if (acf_entry->opt_file == NULL)
	VERBOSE("\n");
    else
	VERBOSE(" (file: %s)\n", acf_entry->opt_file);
}

/* ============================================================ */
/* Add attributes to function during function parsing
/* ============================================================ */

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

typedef void (*decl_attributes_func_type)
    (tree *decl,tree attributes,int flags);
static decl_attributes_func_type decl_attributes_func;

static void
add_decl_attribute(const char *cur_func_name, acf_ftable_entry_t *acf_entry, tree decl) {
    tree attribute_identifier = get_identifier(acf_entry->opt_attr);;
    tree attribute_list = NULL_TREE;
    tree argument = NULL_TREE;
    tree argument_list = NULL_TREE;
    int i;

    if (verbose)
	trace_attached_acf(acf_entry, "attribute", cur_func_name);

    if (acf_entry->attr_arg_number != 0) {
	for (i = 0; i < acf_entry->attr_arg_number; i++) {
	    switch (acf_entry->opt_args[i].arg_type) {
	    case NO_TYPE:
		break;
	    case STR_TYPE:
		argument = build_string(strlen(acf_entry->opt_args[i].av.str_arg),
					acf_entry->opt_args[i].av.str_arg);
		argument_list =  tree_cons(NULL_TREE, argument, argument_list);
		break;
	    case INT_TYPE:
		argument =  build_int_cst (NULL_TREE, acf_entry->opt_args[i].av.int_arg);
		argument_list =  tree_cons(NULL_TREE, argument, argument_list);
		break;
	    }
	}
    } else {
	argument_list = NULL_TREE;
    }

    attribute_list = tree_cons(attribute_identifier, argument_list,
			       attribute_list);

    my_cp_check_const_attributes (attribute_list);
    if (attribute_list != NULL_TREE) {
	decl_attributes_func(&decl,attribute_list,
			     ATTR_FLAG_TYPE_IN_PLACE);
    }
}

/* ============================================================ */
/* Add attributes to function in LTO pass
/* ============================================================ */

static struct cl_optimization loc_save_options, *save_options;

static void
add_lto_attribute(const char *cur_func_name, acf_ftable_entry_t *acf_entry) {

    // if starts with "no-", remove it. Then add "f" -->
    // find_opt("fmove-loop-invariants", 1<<13) = 665
    if (!strcmp("optimize", acf_entry->opt_attr)) {
	char opt_name[128];
	int opt_value = 1;
	char *opt_str = NULL;
	size_t opt_index;

	strcpy(opt_name, "-f");
	if (!strncmp("no-", acf_entry->opt_args[0].av.str_arg, strlen("no-"))) {
	    opt_value = 0;
	    strcat(opt_name, acf_entry->opt_args[0].av.str_arg + strlen("no-"));
	}
	else {
	  if ((opt_str = strchr(acf_entry->opt_args[0].av.str_arg, '=')) != NULL) {
	    opt_str ++;
	    opt_value = atoi(opt_str);
	  }
	  else
	    opt_value = 1;
	  strcat(opt_name, acf_entry->opt_args[0].av.str_arg);
	}

	opt_index = find_opt(opt_name+1, CL_OPTIMIZATION);

#ifdef USE_GLOBAL_PARAMS
	if ((opt_index >= cl_options_count) ||
	    cl_options[opt_index].alias_target == OPT_SPECIAL_ignore)
	    return;
#endif

	if (verbose)
	    trace_attached_acf(acf_entry, "attribute", cur_func_name);

	if (save_options == NULL) {
	    save_options = &loc_save_options;
#ifdef USE_GLOBAL_PARAMS
	    cl_optimization_save(save_options, &global_options);
#else
	    cl_optimization_save(save_options);
#endif
	}

#ifdef USE_GLOBAL_PARAMS
	{
	    struct cl_option_handlers handlers;
	    set_default_handlers (&handlers);
	    handle_generated_option(&global_options, &global_options_set, opt_index, opt_str, opt_value,
				    CL_OPTIMIZATION, DK_UNSPECIFIED, UNKNOWN_LOCATION, &handlers, NULL);
	}
#else
	set_option(&cl_options[opt_index], opt_value, opt_str == NULL ? NULL : xstrdup(opt_str));
#endif
    }

    // An example for --param max-unroll-times=4
    //    opt_index = 67;
    //    opt_arg="max-unroll-times=4";
    //    opt_value=4;
}

/* ============================================================ */
/* Add params to function in backend or LTO pass
/* ============================================================ */

static char **csv_param_name  = NULL;
static int   *csv_param_value = NULL;
static size_t csv_param_index = 0;
static int   *csv_param_set   = NULL;

// Get the index for a PARAM name
static bool get_param_idx(char *opt_param, size_t *idx) {
    size_t i, num_compiler_params = get_num_compiler_params();

    for (i = 0; i < num_compiler_params; ++i) {
	if (strcmp (compiler_params[i].option, opt_param) == 0) {
	    *idx = i;
	    return true;
	}
    }
    return false;
}

static void save_and_set_param(char *opt_param, int value) {
    size_t param_idx;

    if (!get_param_idx(opt_param, &param_idx))
	return;

    // Save current param value
    csv_param_name[csv_param_index] = opt_param;
    csv_param_value[csv_param_index] = PARAM_VALUE(param_idx);
    csv_param_index ++;

#if defined(USE_GLOBAL_PARAMS) && defined (HWI_SHIFT) && defined(ACF_DEBUG)
    if (hwi_shift)
	DEBUG("Default x_param_value address= %p, \n" \
	      "Shifted x_param_value= %p\n",
	      &(global_options.x_param_values), param_values);
#endif

    // Set new param value
#ifdef USE_GLOBAL_PARAMS
    set_param_value(opt_param, value, param_values, csv_param_set);
#else
    set_param_value(opt_param, value);
#endif
}

static void
add_param(const char *cur_func_name, acf_ftable_entry_t *acf_entry) {
    char *opt_param;
    int opt_value;
    bool bad = false;

    /* Check --param X=n syntax */
    if (acf_entry->attr_arg_number != 2)
	bad = true;
    if (acf_entry->opt_args[0].arg_type != STR_TYPE)
	bad = true;
    if (acf_entry->opt_args[1].arg_type != INT_TYPE)
	bad = true;

    if (bad) {
	fprintf(stderr,"%s: Warning: wrong --param setting.\n", plugin_name);
	return;
    }

    opt_param = acf_entry->opt_args[0].av.str_arg;
    opt_value = acf_entry->opt_args[1].av.int_arg;

    if (verbose)
	trace_attached_acf(acf_entry, "param", cur_func_name);

    save_and_set_param(opt_param, opt_value);
}

static void restore_param_values() {
    size_t i;

    for ( i = 0; i < csv_param_index; i++) {
#ifdef USE_GLOBAL_PARAMS
	set_param_value(csv_param_name[i], csv_param_value[i], param_values, csv_param_set);
#else
	set_param_value(csv_param_name[i], csv_param_value[i]);
#endif
    }
}

/* ============================================================ */
/* Read CSV file and set attributes and params
/* ============================================================ */

static int parse_ftable_csv_file(acf_ftable_entry_t **acf_ftable_p,
				 char *csv_file, bool verbose)
{
  int nb = 0;

  nb = acf_parse_csv(csv_file, acf_ftable_p, verbose);

  return nb;
}

#define MATCH_TOKEN(match, tok, tok_len) ((strlen(match) == tok_len) && (strncmp(match, tok, tok_len) == 0))

static bool func_name_match(const char *acf_func, const char *cur_func) {
    /* GCC function cloning rename functions with a suffix that starts
       with a '.', and that contains fields separated with '.', that
       can be numbers or one of "clone", "isra", "constprop" or
       "part". */
    const char *suffix, *token, *next_token;
    size_t token_len;

    if (strncmp(cur_func, acf_func, strlen(acf_func)))
	return false;

    suffix = cur_func+strlen(acf_func);

    if (*suffix == '\0') {
#ifdef ACF_DEBUG
	DEBUG("func_name_match is true for function %s\n", cur_func);
#endif
	return true;
    }

    if (*suffix != '.') {
#ifdef ACF_DEBUG
	DEBUG("For function %s, suffix %s does not match cloning suffix\n",
	      acf_func, suffix);
#endif
	return false;
    }

    next_token = suffix;
    do {
	token = next_token + 1;
	next_token = strchr(token, '.');
	token_len = (next_token == NULL) ? strlen(token) : next_token-token;

	if (!((token_len == 0) ||
	      (strspn(token, "0123456789") == token_len) ||
	      MATCH_TOKEN("part", token, token_len) ||
	      MATCH_TOKEN("isra", token, token_len) ||
	      MATCH_TOKEN("clone", token, token_len) ||
	      MATCH_TOKEN("constprop", token, token_len))) {
#ifdef ACF_DEBUG
	    DEBUG("For function %s, suffix %s does not match cloning suffix\n",
		   acf_func, suffix);
#endif
	    return false;
	}
    } while (next_token != NULL);

#ifdef ACF_DEBUG
    DEBUG("func_name_match is true for function %s\n", cur_func);
#endif
    return true;
}

/* Check if opt_file from csv configuration file matches
   current compiled file */
static bool source_file_match(char *opt_file, char *input_file)
{
    bool ret;

    if (opt_file == NULL || input_file == NULL) {
#ifdef ACF_DEBUG
	DEBUG("Source file %s, %s: unspecified\n",
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
#ifdef ACF_DEBUG
    DEBUG("Source file %s, %s: %s\n", opt_file, input_file,
	  (ret?"matching":"not matching"));
#endif
    return ret;
}

static void fill_csv_options(tree decl, int pass) {
    const char *cur_func_name = NULL;
    int i;

    static int func_number = 0;
    static bool csv_parsed = false;

    if (!csv_parsed) {
	func_number = parse_ftable_csv_file(&acf_ftable, acf_csv_file, verbose);
	csv_parsed = true;
    }
    if (func_number < 0){
	/* Error already reported */
	return;
    }

    cur_func_name = IDENTIFIER_POINTER (DECL_ASSEMBLER_NAME (cfun->decl));

    for (i = 0; i < func_number; i++){
	acf_ftable_entry_t *acf_entry = &acf_ftable[i];

	// TBD: Do not match input_file_name if is_lto()
	if (!func_name_match(acf_entry->func_name, cur_func_name) ||
	    !source_file_match(acf_entry->opt_file, (char *) main_input_filename))
	    continue;

	switch (pass) {
	case 1:
	    // Do not handle --param when called on function parsing
	    if (!IS_CSV_PARAM(acf_entry))
		add_decl_attribute(cur_func_name, acf_entry, decl);
	    break;
	case 2:
	    // No need to handle optimize attribute in backend if not
	    // in lto mode
	    if (IS_CSV_PARAM(acf_entry))
		add_param(cur_func_name, acf_entry);
	    else  if (is_lto())  /* !CSV_PARAM */
		add_lto_attribute(cur_func_name, acf_entry);
	    break;
	default:
	    // Unkonwn pass
	    return;
	}
    }
}

/* ============================================================ */
/* Add ACF callbacks to GCC
/* ============================================================ */

extern void cplus_decl_attributes(tree *, tree, int) __attribute__((weak));

void attribute_injector_start_unit_callback(void *gcc_data ATTRIBUTE_UNUSED,
					    void *data ATTRIBUTE_UNUSED){
    if(is_gcc()){
	decl_attributes_func=(decl_attributes_func_type)(&decl_attributes);
    }else if (is_gpp()){
	decl_attributes_func=&cplus_decl_attributes;
    }
    else
	decl_attributes_func=NULL;
}

static void attribute_injector_finish_decl_callback(void *gcc_data,void *data){
    tree decl=(tree)gcc_data;
    const char *decl_fullname;
#ifdef ACF_REMOTE_DEBUG
    int acf_remote_debug = 1;
#endif

#if ACF_TRACE
    if(DECL_P(decl)&&is_targetable_decl(decl) &&
       MATCH(decl, match_tree_code(equal_to(FUNCTION_DECL)))) {
	decl_fullname=lang_hooks.decl_printable_name(decl,2);
	DEBUG("%s: Processing function %s (%s)\n",
	      plugin_name, decl_fullname,
	      IDENTIFIER_POINTER (DECL_ASSEMBLER_NAME (cfun->decl)));
    }
#endif /* ACF_TRACE */

#ifdef ACF_REMOTE_DEBUG
    while (acf_remote_debug)
	sleep(2);
#endif

    fill_csv_options(decl, 1);
}

static void param_injector_start_passes_callback(void *gcc_data,void *data) {

    if (csv_param_name == NULL) {
	csv_param_name  = (char **)xmalloc(sizeof(char *)*get_num_compiler_params());
	csv_param_value = (int *)xmalloc(sizeof(int) *get_num_compiler_params());
    }

#ifdef USE_GLOBAL_PARAMS
    if (csv_param_set == NULL)
	csv_param_set = (int *)xmalloc(sizeof(int)*get_num_compiler_params());
#endif

    csv_param_index = 0;
    save_options = NULL;
    fill_csv_options(NULL, 2);
}

static void param_injector_end_passes_callback(void *gcc_data,void *data) {

    if (csv_param_index > 0)
	restore_param_values();
    if (save_options != NULL)
#ifdef USE_GLOBAL_PARAMS
	cl_optimization_restore(&global_options, save_options);
#else
        cl_optimization_restore(save_options);
#endif
}

static void lto_clean_optimize_callback(void) {
    struct cgraph_node *node;

    //    if (verbose)
    //	VERBOSE("New pass lto_clean_optimize_callback\n");

    for (node = cgraph_nodes; node; node = node->next) {
	tree decl_node = node->decl;
	// Remove the optimization node that cannot be emited as
	// GIMPLE bytecode for gcc < 4.7
	DECL_FUNCTION_SPECIFIC_OPTIMIZATION(decl_node) = NULL;
    }
}

static int pre_genericize=PLUGIN_PRE_GENERICIZE;
static int start_unit=PLUGIN_START_UNIT;
static int finish_unit=PLUGIN_START_UNIT;

static struct ipa_opt_pass_d lto_clean_optimize_pass = {
    {
	IPA_PASS,
	"lto_clean_optimize",	        /* name */
	NULL,				/* gate */
	NULL,        	                /* execute */
	NULL,				/* sub */
	NULL,				/* next */
	0,				/* static_pass_number */
	TV_NONE,			/* tv_id */
	0,	                        /* properties_required */
	0,				/* properties_provided */
	0,				/* properties_destroyed */
	0,            			/* todo_flags_start */
	0                               /* todo_flags_finish */
    },
    &lto_clean_optimize_callback,       /* generate_summary */
    NULL,				/* write_summary */
    NULL,		         	/* read_summary */
#ifdef USE_GLOBAL_PARAMS
    NULL,				/* write_optimization_summary */
    NULL,				/* read_optimization_summary */
#else
    NULL,                               /* function_read_summary */
#endif
    NULL,				/* stmt_fixup */
    0,					/* TODOs */
    NULL,			        /* function_transform */
    NULL				/* variable_transform */
};

static struct register_pass_info lto_clean_optimize_info = {
    (struct opt_pass *)&lto_clean_optimize_pass,
    "lto_decls_out",
    0,
    PASS_POS_INSERT_BEFORE
};

int plugin_init(struct plugin_name_args *plugin_na,
		struct plugin_gcc_version *version){

    plugin_name=plugin_na->base_name;
    FILE *fcsv;
    int csv_arg_pos = -1;
#ifdef HWI_SHIFT
    int hwi_arg_pos = -1;
    HOST_WIDE_INT hwi_size_var;
    bool hwi_ok;
    int plugin_buildtime_hwi = 0;
#endif
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

#ifdef ACF_DEBUG
    DEBUG("---------------------\n");
    DEBUG("Hello World from the %s !\n", plugin_name);
    if (plugin_na->argc >= 1)
	DEBUG("args number= %d\n", plugin_na->argc);
    for (i = 0; i < plugin_na->argc; i++) {
	DEBUG("key_arg= (%s) -> arg_value= (%s)\n",
	      plugin_na->argv[i].key, plugin_na->argv[i].value);
    }
    DEBUG("---------------------\n");
#endif

    // Check the plugin is used with appropriate compiler version
    // regarding access to PARAM values
#ifndef USE_GLOBAL_PARAMS
    if (!((version->basever[0] < '4') ||
	  ((version->basever[0] == '4') && (version->basever[2] < '6')))) {
	error("%s: build gcc and load gcc versions are incompatible.", plugin_name);
	return 1;
    }
#else
    if ((version->basever[0] < '4') ||
	((version->basever[0] == '4') && (version->basever[2] < '6'))) {
	error("%s: build gcc and load gcc versions are incompatible.", plugin_name);
	return 1;
    }
#endif

    /* Check options */
    switch (plugin_na->argc) {
    case 0:
	bad = true;
	break;
    case 1:
	if (strcmp(plugin_na->argv[0].key, "test") == 0) {
	  PRINTF("test OK\n");
	  return 0;
	} else if (strcmp(plugin_na->argv[0].key, acf_csv_file_key) == 0) {
	    csv_arg_pos = 0;
	} else {
	    bad = true;
	}
	break;
    case 2:
    case 3:
	for (i = 0; i < plugin_na->argc; i++) {
	    if (strcmp(plugin_na->argv[i].key, verbose_key) == 0) {
		verbose = true;
	    }
#ifdef HWI_SHIFT
	    if (strcmp(plugin_na->argv[i].key, hwi_size) == 0) {
		hwi_arg_pos = i;
	    }
#endif
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
		"Usage for %s: -fplugin=<path>/%s.so "
		"-fplugin-arg-%s-%s= <path-to-csv-file> "
#ifdef HWI_SHIFT
		"[-fplugin-arg-%s-%s= <size_in_bytes>] "
#endif
		"[-fplugin-arg-%s-%s]\n",
		plugin_name, plugin_name,
		plugin_name, acf_csv_file_key,
#ifdef HWI_SHIFT
		plugin_name, hwi_size,
#endif
		plugin_name, verbose_key);
	return 1;
    }

    if (strcmp(plugin_na->argv[csv_arg_pos].key, acf_csv_file_key) == 0) {
	acf_csv_file = plugin_na->argv[csv_arg_pos].value;
	if ((fcsv = fopen(acf_csv_file, "r")) == NULL) {
	    error("%s: csv file not found: %s\n", plugin_name, acf_csv_file);
	    bad = true;
	} else {
	    fclose(fcsv);
	}
    } else {
	error("%s: Unknown option %s\n", plugin_name,
	      plugin_na->argv[csv_arg_pos].key);
	return 1;
    }

#ifdef HWI_SHIFT
    hwi_ok = false;
    if (hwi_arg_pos != -1 && strcmp(plugin_na->argv[hwi_arg_pos].key, hwi_size) == 0) {
	if (plugin_na->argv[hwi_arg_pos].value &&
	    strcmp(plugin_na->argv[hwi_arg_pos].value, "") != 0) {
	    errno = 0;
	    gcc_runtime_hwi = strtol(plugin_na->argv[hwi_arg_pos].value, NULL, 0);
	    if (!errno) {
#ifdef ACF_DEBUG
		DEBUG("gcc HOST_WIDE_INT size from parameters: %d\n", gcc_runtime_hwi);
#endif
		hwi_ok = true;

		/* Get plugin HOST_WIDE_INT size */
		plugin_buildtime_hwi = sizeof(hwi_size_var);
#ifdef ACF_DEBUG
		DEBUG("Plugin HOST_WIDE_INT size: %d\n", plugin_buildtime_hwi);
#endif

		if (gcc_runtime_hwi != plugin_buildtime_hwi) {
		    /* Correct offset of x_param_values in global_options structure
		       due to 2 fields of type HOST_WIDE_INT at its begining*/
		    hwi_shift = (2 * (gcc_runtime_hwi - plugin_buildtime_hwi));
		}
#ifdef ACF_DEBUG
		if (hwi_shift)
		    DEBUG("HOST_WIDE_INT shift: %d\n", hwi_shift);
#endif
	    }
	}
    }
#ifdef ACF_DEBUG
    if (!hwi_ok)
	DEBUG("Warning: No HOST_WIDE_TYPE size in parameters\n");
#endif
#endif /* HWI_SHIFT */

    register_callback(plugin_na->base_name,
		      PLUGIN_START_UNIT,
		      &attribute_injector_start_unit_callback,NULL);
    register_callback(plugin_na->base_name,
		      PLUGIN_PRE_GENERICIZE,
		      &attribute_injector_finish_decl_callback,
		      &pre_genericize);

    register_callback(plugin_na->base_name,
		      PLUGIN_ALL_PASSES_START,
		      &param_injector_start_passes_callback, NULL);
    register_callback(plugin_na->base_name,
		      PLUGIN_ALL_PASSES_END,
		      &param_injector_end_passes_callback, NULL);

    // For GCC versions earlier than 4.7, remove the optimization node
    // that cannot be emitted as GIMPLE bytecode
    if (flag_generate_lto &&
	((version->basever[0] < '4') ||
	 ((version->basever[0] == '4') && (version->basever[2] < '7'))))
	    register_callback (plugin_na->base_name,
			       PLUGIN_PASS_MANAGER_SETUP,
			       NULL, &lto_clean_optimize_info);

#ifdef PRINT_PASS_LIST
    PRINTF("\n####### ALL PASSES LIST #######\n");
    print_pass_list(all_passes,0);
    PRINTF("\n\n####### ALL SMALL IPA PASSES LIST #######\n");
    print_pass_list(all_small_ipa_passes,0);
    PRINTF("\n\n####### ALL REGULAR IPA PASSES LIST #######\n");
    print_pass_list(all_regular_ipa_passes,0);
    PRINTF("\n\n####### ALL LOWERING PASSES LIST #######\n");
    print_pass_list(all_lowering_passes,0);
    PRINTF("\n\n####### ALL LTO GEN PASSES LIST #######\n");
    print_pass_list(all_lto_gen_passes,0);
#endif /* PRINT_PASS_LIST */

    return 0;
}
