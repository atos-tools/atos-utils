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

#include "gcc-plugin.h"
#include "plugin-version.h"
#include "tree-pass.h"
#include "diagnostic.h"
#include "params.h"
#include "cgraph.h"
#include "opts.h"

#include "plugin-utils.h"
#include "acf_plugin.h"

#define GCC_PLUGIN_VERSION "v0.1"

/* Help info about the plugin if one were to use gcc's --version --help */
static struct plugin_info acf_plugin_info = {
    version : "Gcc-Plugin-ACF version " GCC_PLUGIN_VERSION
        " (Base - revision " xstr(SHA1_VERSION) ")",
    help : "ACF Plugin: "
    "Pass GCC options and parameters at function level through ACF files."
};


/* ============================================================ */
/* Other external declarations */
/* ============================================================ */
/* Function error() is not always declared in gcc headers. */
extern void error(const char *, ...);

/* ============================================================ */
/* Setting of global macros */
/* ============================================================ */

#ifdef param_values
#define USE_GLOBAL_PARAMS
#else
#undef USE_GLOBAL_PARAMS
#endif

static acf_ftable_entry_t *acf_ftable;
static const char *acf_csv_file_key="csv_file";
#define ACF_CSV_FILES_MAX 128
static char *acf_csv_files[ACF_CSV_FILES_MAX];
static int acf_csv_files_num = 0;

static bool register_acf_file(const char *plugin_name,
                              char * acf_csv_filename) {
    FILE *fcsv;

    acf_csv_files_num++;
    if (acf_csv_files_num > ACF_CSV_FILES_MAX) {
        error("%s: too many csv files to register(%d): %s\n",
              plugin_name, acf_csv_files_num, acf_csv_filename);
        return false;
    }

    if ((fcsv = fopen(acf_csv_filename, "r")) == NULL) {
        error("%s: csv file not found: %s\n", plugin_name, acf_csv_filename);
        return false;
    }

    fclose(fcsv);
    acf_csv_files[acf_csv_files_num-1] = acf_csv_filename;

    return true;
}

static const char *verbose_key="verbose";
static bool verbose = false;

int plugin_is_GPL_compatible;
static const char *plugin_name;
#ifdef PRINT_PASS_LIST
static void do_indent(int tab_number) {
    int i;
    for (i = 0; i < tab_number; ++i) {
        PRINTF("\t");
    }
}

static void print_pass_list(struct opt_pass *pass, int tab_number) {
    do_indent(tab_number);
    PRINTF("%d: ", pass->static_pass_number);
    switch (pass->type) {
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
    PRINTF(": %s\n", pass->name);
    if (pass->sub) {
        print_pass_list(pass->sub, tab_number + 1);
    }
    if (pass->next) {
        print_pass_list(pass->next, tab_number);
    }
}
#endif /* PRINT_PASS_LIST */

static void trace_attached_acf(acf_ftable_entry_t *acf_entry,
                               const char *acf_type,
                               const char *func_name,
                               const char *acf_pass_name) {
    const char *sep = "";
    int i;
    VERBOSE("%s: %s for function %s, attaching %s: %s ",
            plugin_name, acf_pass_name, func_name, acf_type,
            acf_entry->opt_attr);
    for (i = 0; i < acf_entry->attr_arg_number; i++) {
        switch (acf_entry->opt_args[i].arg_type) {
        case NO_TYPE:
            break;
        case STR_TYPE:
            VERBOSE("%s%s", sep, (acf_entry->opt_args[i].av.str_arg != NULL ?
                                  acf_entry->opt_args[i].av.str_arg :
                                  "(null),"));
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
/* Add attributes to function during function parsing */
/* ============================================================ */

extern tree maybe_constant_value(tree) __attribute__((weak));


/* Replaces any constexpr expression that may be into the attributes
   arguments with their reduced value.  */
static void my_cp_check_const_attributes(tree attributes) {
    tree attr;
    for (attr = attributes; attr; attr = TREE_CHAIN(attr)) {
        tree arg;
        for (arg = TREE_VALUE(attr); arg; arg = TREE_CHAIN(arg)) {
            tree expr = TREE_VALUE(arg);
            if (EXPR_P(expr))
                TREE_VALUE(arg) = maybe_constant_value(expr);
        }
    }
}

typedef void (*decl_attributes_func_type)
(tree *decl, tree attributes, int flags);
static decl_attributes_func_type decl_attributes_func;

/* Will modifiy the attributes flags stored into the tree decl. */

static void
add_decl_attribute(const char *cur_func_name, acf_ftable_entry_t *acf_entry,
                   tree decl, const char *acf_pass_name) {
    tree attribute_identifier = get_identifier(acf_entry->opt_attr);
    tree attribute_list = NULL_TREE;
    tree argument = NULL_TREE;
    tree argument_list = NULL_TREE;
    int i;

    if (verbose)
        trace_attached_acf(acf_entry, "attribute",
                           cur_func_name, acf_pass_name);

    if (acf_entry->attr_arg_number != 0) {
        for (i = 0; i < acf_entry->attr_arg_number; i++) {
            switch (acf_entry->opt_args[i].arg_type) {
            case NO_TYPE:
                break;
            case STR_TYPE:
                argument =
                    build_string(strlen(acf_entry->opt_args[i].av.str_arg),
                                 acf_entry->opt_args[i].av.str_arg);
                argument_list =
                    tree_cons(NULL_TREE, argument, argument_list);
                break;
            case INT_TYPE:
                argument = build_int_cst(NULL_TREE,
                                         acf_entry->opt_args[i].av.int_arg);
                argument_list = tree_cons(NULL_TREE,
                                           argument, argument_list);
                break;
            }
        }
    } else {
        argument_list = NULL_TREE;
    }

    attribute_list = tree_cons(attribute_identifier, argument_list,
                               attribute_list);

    my_cp_check_const_attributes(attribute_list);
    if (attribute_list != NULL_TREE) {
        decl_attributes_func(&decl, attribute_list,
                             ATTR_FLAG_TYPE_IN_PLACE);
    }
}

/* ============================================================ */
/* Add attributes to function in LTO pass */
/* ============================================================ */

/* Save and restore compiler option context */

static struct cl_optimization loc_save_options, *save_options = NULL;
#ifdef USE_GLOBAL_PARAMS
static int save_optimize_fast;
#endif

static void save_global_attribute_values() {
    if (save_options == NULL) {
        save_options = &loc_save_options;
#ifdef USE_GLOBAL_PARAMS
        cl_optimization_save(save_options, &global_options);
        save_optimize_fast = global_options.x_optimize_fast;
#else
        cl_optimization_save(save_options);
#endif
    }
}

static void restore_global_attribute_values() {
    if (save_options != NULL) {
#ifdef USE_GLOBAL_PARAMS
        cl_optimization_restore(&global_options, save_options);
        global_options.x_optimize_fast = save_optimize_fast;
#else
        cl_optimization_restore(save_options);
#endif
        save_options = NULL;
    }
}

/* Will update the global_options variable, after it has been
   initialized by a copy of the flags in the tree decl. If not in lto,
   add_decl_attribute has already been executed and the ACF flags have
   been stored into the decl tree, and thus already copied into the
   gobal_options struct.
*/

static void
add_global_attribute(const char *cur_func_name,
                     acf_ftable_entry_t *acf_entry,
                     const char *acf_pass_name) {
#ifdef USE_GLOBAL_PARAMS
    struct cl_option_handlers handlers;
#endif
    // if starts with "no-", remove it. Then add "f" -->
    // find_opt("fmove-loop-invariants", 1<<13) = 665
    if (!strcmp("optimize", acf_entry->opt_attr)) {
        char opt_name[128];
        int opt_value = 0;
        char *opt_str = NULL;
        size_t opt_index;

        // The optimize attribute only accepts the following options :
        // O<num>, <num> => -O<num>
        // Os, Ofast => -Os, -Ofast
        // <option> => -f<option>
        if (acf_entry->opt_args[0].av.str_arg[0] == 'O') {
            /* O<num> */
            if ((acf_entry->opt_args[0].av.str_arg[1] >= '0') &&
                (acf_entry->opt_args[0].av.str_arg[1] <= '9')) {
                snprintf(opt_name, sizeof(opt_name), "O");
                opt_str = acf_entry->opt_args[0].av.str_arg + 1;
            } else if (acf_entry->opt_args[0].av.str_arg[1] == '\0') {
                opt_value = 1;
            } else {
                /* Os, Ofast */
                snprintf(opt_name, sizeof(opt_name), "%s",
                         acf_entry->opt_args[0].av.str_arg);
            }
        } else if ((acf_entry->opt_args[0].av.str_arg[0] >= '0') &&
                 (acf_entry->opt_args[0].av.str_arg[0] <= '9')) {
            /* <num> */
            snprintf(opt_name, sizeof(opt_name), "O");
            opt_str = acf_entry->opt_args[0].av.str_arg;
        } else {
            /* <option> */
            if (!strncmp("no-", acf_entry->opt_args[0].av.str_arg,
                         strlen("no-"))) {
                snprintf(opt_name, sizeof(opt_name), "f%s",
                         acf_entry->opt_args[0].av.str_arg + strlen("no-"));
                opt_value = 0;
            } else {
                snprintf(opt_name, sizeof(opt_name), "f%s",
                         acf_entry->opt_args[0].av.str_arg);
                if ((opt_str = strchr(acf_entry->opt_args[0].av.str_arg, '='))
                    != NULL)
                    opt_str++;
                else
                    opt_value = 1;
            }
        }

        if (opt_str)
            opt_value = atoi(opt_str);

        opt_index = find_opt(opt_name, CL_OPTIMIZATION);

#ifdef USE_GLOBAL_PARAMS
        if ((opt_index >= cl_options_count) ||
            cl_options[opt_index].alias_target == OPT_SPECIAL_ignore)
            return;
#endif

        if (verbose)
            trace_attached_acf(acf_entry, "attribute",
                               cur_func_name, acf_pass_name);

        save_global_attribute_values();

#ifdef USE_GLOBAL_PARAMS
        set_default_handlers(&handlers);
        switch (opt_index) {
        case OPT_O:
            global_options.x_optimize = opt_value;
            if ((unsigned int) global_options.x_optimize > 255)
                global_options.x_optimize = 255;
            global_options.x_optimize_size = 0;
            global_options.x_optimize_fast = 0;
            break;
        case OPT_Os:
            global_options.x_optimize = 2;
            global_options.x_optimize_size = 1;
            global_options.x_optimize_fast = 0;
            break;
        case OPT_Ofast:
            global_options.x_optimize = 3;
            global_options.x_optimize_size = 0;
            global_options.x_optimize_fast = 1;
            break;
        default:
            handle_generated_option(&global_options, &global_options_set,
                                    opt_index, opt_str, opt_value,
                                    CL_OPTIMIZATION, DK_UNSPECIFIED,
                                    UNKNOWN_LOCATION, &handlers, NULL);
        }
#else
        switch (opt_index) {
        case OPT_O:
            optimize = opt_value;
            if ((unsigned int) optimize > 255)
                optimize = 255;
            optimize_size = 0;
            break;
        case OPT_Os:
            optimize = 2;
            optimize_size = 1;
            break;
        default:
            set_option(&cl_options[opt_index], opt_value, opt_str == NULL ?
                       NULL : xstrdup(opt_str));
        }
#endif
    }

    // An example for --param max-unroll-times=4
    //    opt_index = 67;
    //    opt_arg="max-unroll-times=4";
    //    opt_value=4;
}

/* ============================================================ */
/* Add params to function in backend or LTO pass */
/* ============================================================ */

static char **csv_param_name  = NULL;
static int   *csv_param_value = NULL;
static size_t csv_param_index = 0;
#ifdef USE_GLOBAL_PARAMS
static int   *csv_param_set   = NULL;
#endif

// Get the index for a PARAM name
static bool get_param_idx(char *opt_param, size_t *idx) {
    size_t i, num_compiler_params = get_num_compiler_params();

    for (i = 0; i < num_compiler_params; ++i) {
        if (strcmp(compiler_params[i].option, opt_param) == 0) {
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
    csv_param_index++;

    // Set new param value
#ifdef USE_GLOBAL_PARAMS
    set_param_value(opt_param, value, param_values, csv_param_set);
#else
    set_param_value(opt_param, value);
#endif
}

static void
add_global_param(const char *cur_func_name, acf_ftable_entry_t *acf_entry,
                 const char *acf_pass_name) {
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
        fprintf(stderr, "%s: Warning: wrong --param setting.\n", plugin_name);
        return;
    }

    opt_param = acf_entry->opt_args[0].av.str_arg;
    opt_value = acf_entry->opt_args[1].av.int_arg;

    if (verbose)
        trace_attached_acf(acf_entry, "param", cur_func_name, acf_pass_name);

    save_and_set_param(opt_param, opt_value);
}

static void restore_global_param_values() {
    size_t i;

    for (i = 0; i < csv_param_index; i++) {
#ifdef USE_GLOBAL_PARAMS
        set_param_value(csv_param_name[i], csv_param_value[i],
                        param_values, csv_param_set);
#else
        set_param_value(csv_param_name[i], csv_param_value[i]);
#endif
    }
    csv_param_index = 0;
}

#define MATCH_TOKEN(match, tok, tok_len)                                \
    ((strlen(match) == tok_len) && (strncmp(match, tok, tok_len) == 0))

static bool func_name_match(const acf_ftable_entry_t *acf_entry,
                            const char *cur_func) {
    /* GCC function cloning rename functions with a suffix that starts
       with a '.', and that contains fields separated with '.', that
       can be numbers or one of "clone", "isra", "constprop" or
       "part". */
    const char *suffix, *token, *next_token;
    size_t token_len;
    const char *acf_func = acf_entry->func_name;
    size_t acf_func_len = acf_entry->func_name_len;
    size_t cur_func_len = strlen(cur_func);

    if (cur_func_len < acf_func_len ||
        memcmp(cur_func, acf_func, acf_func_len) != 0)
        return false;

    suffix = cur_func+acf_func_len;

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
static bool source_file_match(const acf_ftable_entry_t *acf_entry,
                              const char *input_file) {
    bool ret;
    const char *opt_file = acf_entry->opt_file;

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
    if (basename(opt_file) == opt_file) {
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

static const char *pass_names[] = { "unknown",
                                    "dcl passes",
                                    "all_passes",
                                    "ipa_passes"};

static bool fill_csv_options(tree decl, int acf_pass) {
    const char *cur_func_name = NULL;
    const char *acf_pass_name = pass_names[acf_pass];
    bool done = false;
    int i;

    static int func_number = 0;
    static bool csv_parsed = false;

    if (!csv_parsed) {
        struct csv_list parsed_csv;

        initCSV(&parsed_csv);

        for (i = 0; i < acf_csv_files_num; i++) {
            if (!readCSV(acf_csv_files[i], &parsed_csv))
                return false;
        }

        func_number = parseCSV(&parsed_csv, &acf_ftable, verbose);
        csv_parsed = true;
    }
    if (func_number < 0) {
        /* Error already reported */
        return false;
    }

    /* TBD: Use current_function_decl instead ?? */
    cur_func_name = IDENTIFIER_POINTER(DECL_ASSEMBLER_NAME(cfun->decl));

    for (i = 0; i < func_number; i++) {
        acf_ftable_entry_t *acf_entry = &acf_ftable[i];

        // TBD: Do not match input_file_name if is_lto()
        if (!func_name_match(acf_entry, cur_func_name) ||
            !source_file_match(acf_entry, main_input_filename))
            continue;

        switch (acf_pass) {
        case 1: /* DECL pass */
            // Do not handle --param when called on function parsing
            if (!IS_CSV_PARAM(acf_entry)) {
                done = true;
                add_decl_attribute(cur_func_name, acf_entry, decl,
                                   acf_pass_name);
            }
            break;
        case 2: /* ALL passes */
        case 3: /* IPA passes */
            if (IS_CSV_PARAM(acf_entry))
                add_global_param(cur_func_name, acf_entry, acf_pass_name);
            // Need to handle optimize attribute in backend only in
            // lto mode for versions before 4.7.0
#if !defined(GCCPLUGIN_VERSION) || (GCCPLUGIN_VERSION < 4007)
            else  if (is_lto())  /* !CSV_PARAM */
                add_global_attribute(cur_func_name, acf_entry, acf_pass_name);
#endif
            done = true;
            break;
        default:
            // Unkonwn pass
            return done;
        }
    }
    return done;
}

/* ============================================================ */
/* Add ACF callbacks to GCC */
/* ============================================================ */

extern void cplus_decl_attributes(tree *, tree, int) __attribute__((weak));

static void
attribute_injector_start_unit_callback(void *gcc_data ATTRIBUTE_UNUSED,
                                       void *data ATTRIBUTE_UNUSED) {
    if (is_gcc()) {
        decl_attributes_func = (decl_attributes_func_type)&decl_attributes;
    } else if (is_gpp()) {
        decl_attributes_func = &cplus_decl_attributes;
    } else {
        decl_attributes_func = NULL;
    }
}

static void attribute_injector_finish_decl_callback(void *gcc_data,
                                                    void *data) {
    tree decl=(tree)gcc_data;
#ifdef ACF_REMOTE_DEBUG
    int acf_remote_debug = 1;
#endif

#if ACF_TRACE
    DEBUG("%s: Processing function %s \n",
          plugin_name,
          IDENTIFIER_POINTER(DECL_ASSEMBLER_NAME(current_function_decl)));
#endif /* ACF_TRACE */

#ifdef ACF_REMOTE_DEBUG
    while (acf_remote_debug)
        sleep(2);
#endif

    fill_csv_options(decl, 1);
}

static void param_injector_start_all_passes_callback(void *gcc_data,
                                                     void *data) {
    if (csv_param_name == NULL) {
        csv_param_name  = (char **)
            xmalloc(sizeof(*csv_param_name) * get_num_compiler_params());
        csv_param_value = (int *)
            xmalloc(sizeof(*csv_param_value) * get_num_compiler_params());
    }

#ifdef USE_GLOBAL_PARAMS
    if (csv_param_set == NULL)
        csv_param_set = (int *)
            xmalloc(sizeof(*csv_param_set) * get_num_compiler_params());
#endif

    csv_param_index = 0;
    save_options = NULL;
    fill_csv_options(NULL, 2);
}

static void param_injector_end_passes_callback(void *gcc_data, void *data) {
    restore_global_param_values();
    restore_global_attribute_values();
}

/*
  For small_ipa_passes and all_regular_ipa_passes, the events
  PLUGIN_EARLY_GIMPLE_PASSES_START and PLUGIN_EARLY_GIMPLE_PASSES_END
  are triggered when entering and exiting a sequence of GIMPLE
  passes. These GIMPLE passes are executed all together one function
  at a time. Thus we want to call fill_csv_options each time a
  sequence of GIMPLE_PASS is executed in the context of a function.

  So as to be as portable as possible from one GCC version to another,
  we do as follows :

  - On PLUGIN_EARLY_GIMPLE_PASSES_START, we register
  PLUGIN_PASS_EXECUTION so that we are called when the next pass is
  called.

  - On PLUGIN_PASS_EXECUTION we cancel this callback, and we add a
  pass just before the current pass. This pass will be executed as
  the first pass of a GIMPLE IPA sequence, and will make a call to
  fill_csv_function.

  - On PLUGIN_EARLY_GIMPLE_PASSES_END, we just restore the default
  context to avoid a particular function context to be used
  elsewhere.
*/

// Called when entering a sequence of GIMPLE_PASS in IPA lists

static unsigned int ipa_gimple_per_func_callback(void) {
    if (csv_param_name == NULL) {
        csv_param_name  = (char **)
            xmalloc(sizeof(*csv_param_name) * get_num_compiler_params());
        csv_param_value = (int *)
            xmalloc(sizeof(*csv_param_value) * get_num_compiler_params());
    }

#ifdef USE_GLOBAL_PARAMS
    if (csv_param_set == NULL)
        csv_param_set = (int *)
            xmalloc(sizeof(*csv_param_set) * get_num_compiler_params());
#endif

    restore_global_param_values();
    restore_global_attribute_values();

    fill_csv_options(NULL, 3);

    return 0;
}

// Called on the first pass after PLUGIN_EARLY_GIMPLE_PASSES_START was
// triggered

static void ipa_gimple_init_per_func_callback(void *gcc_data,
                                              void *data) {
    // New pass to be inserted before the first GIMPLE_PASS in an IPA list

    static struct gimple_opt_pass static_pass_ipa_gimple_per_func = {
        {
            GIMPLE_PASS,
            "ipa_gimple_per_func",            /* name */
#if defined(GCCPLUGIN_VERSION) && (GCCPLUGIN_VERSION >= 4008)
            OPTGROUP_NONE,                    /* optinfo_flags */
#endif
            NULL,                             /* gate */
            &ipa_gimple_per_func_callback,    /* execute */
            NULL,                             /* sub */
            NULL,                             /* next */
            0,                                        /* static_pass_number */
            TV_NONE,                          /* tv_id */
            0,                                        /* properties_required */
            0,                                        /* properties_provided */
            0,                                        /* properties_destroyed */
            0,                                        /* todo_flags_start */
            0                                 /* todo_flags_finish */
        }
    };

    unregister_callback(plugin_name, PLUGIN_PASS_EXECUTION);

    // Check if the pass has not already been inserted (is it possible ?)
    if (strcmp(current_pass->name, "ipa_gimple_per_func") != 0) {
        // We cannot insert the new pass before current one since the
        // caller has a pointer on the current pass. So we insert it after, and
        // we permute the first two passes.
        struct gimple_opt_pass *pass_ipa_gimple_per_func;
        struct register_pass_info *ipa_gimple_per_func_info;

        pass_ipa_gimple_per_func = (struct gimple_opt_pass *)
            xmalloc(sizeof(struct gimple_opt_pass));
        memcpy(pass_ipa_gimple_per_func, &static_pass_ipa_gimple_per_func,
               sizeof(struct gimple_opt_pass));

        ipa_gimple_per_func_info = (struct register_pass_info *)
            xmalloc(sizeof(struct register_pass_info));
        ipa_gimple_per_func_info->pass = (struct opt_pass *)
            pass_ipa_gimple_per_func;
        ipa_gimple_per_func_info->reference_pass_name = current_pass->name;
        ipa_gimple_per_func_info->ref_pass_instance_number =
            current_pass->static_pass_number;
        ipa_gimple_per_func_info->pos_op = PASS_POS_INSERT_AFTER;

        register_callback(plugin_name,
                          PLUGIN_PASS_MANAGER_SETUP,
                          NULL, ipa_gimple_per_func_info);

        // Permute the first two passes
        struct opt_pass copy_current, *next_pass = current_pass->next;
        memcpy(&copy_current, current_pass, sizeof(struct opt_pass));
        memcpy(current_pass, next_pass, sizeof(struct opt_pass));
        memcpy(next_pass, &copy_current, sizeof(struct opt_pass));
        next_pass->next = current_pass->next;
        current_pass->next = next_pass;
    }
}

// Called when PLUGIN_EARLY_GIMPLE_PASSES_START is triggered

static void ipa_gimple_passes_start_callback(void *gcc_data, void *data) {
    register_callback(plugin_name,
                      PLUGIN_PASS_EXECUTION,
                      &ipa_gimple_init_per_func_callback, NULL);
}

// Called when PLUGIN_EARLY_GIMPLE_PASSES_END is triggered

static void ipa_gimple_passes_end_callback(void *gcc_data, void *data) {
    // In case ipa_gimple_init_per_func_callback was not called after
    // ipa_gimple_passes_start_callback
    unregister_callback(plugin_name, PLUGIN_PASS_EXECUTION);
    restore_global_param_values();
    restore_global_attribute_values();
}

#if !defined(GCCPLUGIN_VERSION) || (GCCPLUGIN_VERSION < 4007)
static void lto_clean_optimize_callback(void) {
    struct cgraph_node *node;

    for (node = cgraph_nodes; node; node = node->next) {
        tree decl_node = node->decl;
        // Remove the optimization node that cannot be emited as
        // GIMPLE bytecode for gcc < 4.7
        DECL_FUNCTION_SPECIFIC_OPTIMIZATION(decl_node) = NULL;
    }
}
#endif

static int pre_genericize = PLUGIN_PRE_GENERICIZE;

#ifdef USE_GLOBAL_PARAMS
static int plugin_test_global_params(void) {
    // Check that compiler and plugin do see the same gcc_options struct.

    // Make sure the plugin do not allocate a struct smaller than the
    // one from the compiler, take twice the siwe of the plugin size.
    struct gcc_options tmp_opt[2], tmp_opt_set[2];
    int i, plugin_offset_param_values, gcc_offset_param_values;
    plugin_offset_param_values = (int)offsetof(struct gcc_options,
                                               x_param_values);

    gcc_offset_param_values = -1;
    init_options_struct(tmp_opt, tmp_opt_set);
    for (i = 0;
         i < (int)(sizeof(struct gcc_options)/sizeof(int *)); // NOLINT
         i++) {
        if (((int **)tmp_opt_set)[i] != 0) {
            gcc_offset_param_values = i * sizeof(int *); // NOLINT
            break;
        }
    }

    if (plugin_offset_param_values != gcc_offset_param_values) {
        if (gcc_offset_param_values == -1) {
            error("%s: unable to check offset of field x_param_values in "
                  "struct gcc_options\n", plugin_name);
        } else {
            error("%s: offset of field x_param_values in struct gcc_options "
                  "does not match between compiler (%d) and plugin (%d).\n",
                  plugin_name,
                  gcc_offset_param_values, plugin_offset_param_values);
        }
        return 1;
    }
    return 0;
}
#else /* !USE_GLOBAL_PARAMS */
static int plugin_test_global_params(void) {
    return 0;
}
#endif

static int plugin_test(void) {
    int status;

    status = plugin_test_global_params();
    return status;
}

int plugin_init(struct plugin_name_args *plugin_na,
                struct plugin_gcc_version *version) {
    bool bad_arguments;
    int i;

    /* higly strict version checking : plugin is built by the
       same gcc revision that loads it. */
    if (!plugin_default_version_check(version, &gcc_version)) {
        /* We do not want to be that restrictive.
           Do nothing, but keep check in order to reference gcc_version. */
        // error("%s: build gcc and load gcc version mismatch.", plugin_name);
        // return 1;
        (void)NULL;
    }

    plugin_name = plugin_na->base_name;

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
        error("%s: build gcc and load gcc versions are incompatible.",
              plugin_name);
        return 1;
    }
#else
    if ((version->basever[0] < '4') ||
        ((version->basever[0] == '4') && (version->basever[2] < '6'))) {
        error("%s: build gcc and load gcc versions are incompatible.",
              plugin_name);
        return 1;
    }
#endif

    /* Check options */
    bad_arguments = false;
    acf_csv_files_num = 0;

    for (i = 0; i < plugin_na->argc; i++) {
        if (strcmp(plugin_na->argv[i].key, "test") == 0) {
            if ((i > 0) || (plugin_na->argc > 1)) {
                bad_arguments = true;
                break;
            }
            int status = plugin_test();
            PRINTF("%s: plugin test.\n", status == 0 ? "PASSED": "FAILED");
            return status;
        } else if (strcmp(plugin_na->argv[i].key, "version") == 0) {
            printf("%s\n", acf_plugin_info.version);
            return 0;
        } else if (strcmp(plugin_na->argv[i].key, verbose_key) == 0) {
            verbose = true;
        } else if (strcmp(plugin_na->argv[i].key, acf_csv_file_key) == 0) {
            if (!register_acf_file(plugin_name, plugin_na->argv[i].value)) {
                bad_arguments = true;
                break;
            }
        } else {
            error("%s: Unknown option %s\n", plugin_name,
                  plugin_na->argv[i].key);
            return 1;
        }
    }

    if ((plugin_na->argc == 0) || (acf_csv_files_num == 0))
        bad_arguments = true;

    if (bad_arguments) {
        fprintf(stderr,
                "Usage for %s: -fplugin=<path>/%s.so "
                "-fplugin-arg-%s-%s=<path-to-csv-file> "
                "[-fplugin-arg-%s-%s"
                " | -fplugin-arg-%s-%s"
                " | -fplugin-arg-%s-%s]\n",
                plugin_name, plugin_name,
                plugin_name, acf_csv_file_key,
                plugin_name, verbose_key,
                plugin_name, "version",
                plugin_name, "test");
        return 1;
    }

    // Attach function attributes to function node
    register_callback(plugin_na->base_name,
                      PLUGIN_START_UNIT,
                      &attribute_injector_start_unit_callback, NULL);
    register_callback(plugin_na->base_name,
                      PLUGIN_PRE_GENERICIZE,
                      &attribute_injector_finish_decl_callback,
                      &pre_genericize);

    // Load function context for all_passes optimizations
    register_callback(plugin_na->base_name,
                      PLUGIN_ALL_PASSES_START,
                      &param_injector_start_all_passes_callback, NULL);
    register_callback(plugin_na->base_name,
                      PLUGIN_ALL_PASSES_END,
                      &param_injector_end_passes_callback, NULL);

    // Load function context for the ipa (regular and small_ipa) passes
    register_callback(plugin_na->base_name,
                      PLUGIN_EARLY_GIMPLE_PASSES_START,
                      &ipa_gimple_passes_start_callback, NULL);
    register_callback(plugin_na->base_name,
                      PLUGIN_EARLY_GIMPLE_PASSES_END,
                      &ipa_gimple_passes_end_callback, NULL);

#if !defined(GCCPLUGIN_VERSION) || (GCCPLUGIN_VERSION < 4007)
    // For GCC versions earlier than 4.7, remove the optimization node
    // that cannot be emitted as GIMPLE bytecode
    if ((version->basever[0] > '4') ||
        ((version->basever[0] == '4') && (version->basever[2] >= '7'))) {
        error("%s: build gcc and load gcc versions are incompatible.",
              plugin_name);
        return 1;
    }

    if (flag_generate_lto) {
        static struct ipa_opt_pass_d lto_clean_optimize_pass = {
            {
                IPA_PASS,
                "lto_clean_optimize",           /* name */
                NULL,                           /* gate */
                NULL,                           /* execute */
                NULL,                           /* sub */
                NULL,                           /* next */
                0,                              /* static_pass_number */
                TV_NONE,                        /* tv_id */
                0,                              /* properties_required */
                0,                              /* properties_provided */
                0,                              /* properties_destroyed */
                0,                              /* todo_flags_start */
                0                               /* todo_flags_finish */
            },
            &lto_clean_optimize_callback,       /* generate_summary */
            NULL,                             /* write_summary */
            NULL,                             /* read_summary */
#ifdef USE_GLOBAL_PARAMS
            NULL,                             /* write_optimization_summary */
            NULL,                             /* read_optimization_summary */
#else
            NULL,                               /* function_read_summary */
#endif
            NULL,                             /* stmt_fixup */
            0,                                        /* TODOs */
            NULL,                             /* function_transform */
            NULL                              /* variable_transform */
        };

        static struct register_pass_info lto_clean_optimize_info = {
            (struct opt_pass *)&lto_clean_optimize_pass,
            "lto_decls_out",
            0,
            PASS_POS_INSERT_BEFORE
        };

        register_callback(plugin_na->base_name,
                          PLUGIN_PASS_MANAGER_SETUP,
                          NULL, &lto_clean_optimize_info);

        register_callback(plugin_na->base_name,
                          PLUGIN_INFO,
                          NULL, &acf_plugin_info);
    }
#endif

#ifdef PRINT_PASS_LIST
    PRINTF("\n####### ALL PASSES LIST #######\n");
    print_pass_list(all_passes, 0);
    PRINTF("\n\n####### ALL SMALL IPA PASSES LIST #######\n");
    print_pass_list(all_small_ipa_passes, 0);
    PRINTF("\n\n####### ALL REGULAR IPA PASSES LIST #######\n");
    print_pass_list(all_regular_ipa_passes, 0);
    PRINTF("\n\n####### ALL LOWERING PASSES LIST #######\n");
    print_pass_list(all_lowering_passes, 0);
    PRINTF("\n\n####### ALL LTO GEN PASSES LIST #######\n");
    print_pass_list(all_lto_gen_passes, 0);
#endif /* PRINT_PASS_LIST */

    return 0;
}
