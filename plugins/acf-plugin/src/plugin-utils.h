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

#ifndef GUARD__PLUGIN_UTILS_H
#define GUARD__PLUGIN_UTILS_H

#include "gcc-plugin.h"
#include "tree.h"
#include "tm.h"
#include "langhooks.h"
#include "function.h"
#include "rtl.h"
#include "emit-rtl.h"

/*

######### How to use pattern matching ? #########

MATCH(expression,matcher);
or
MATCH_TYPE(type,expression,matcher);

* type is the type used to store expression value. MATCH will use
the __typeof__ operator to guess it.
* expression is the value you want to match. It may have side-effect
(like ++'ing for example) and the pattern matching framework
will garanty that this value is evaled once and only once.
* matcher if C code sequence.

The returned value is the value returned by matcher (ie the value of the
last statement of matcher (block statement is a C extension)).

generic match:
type matched_result=MATCH(my_expression,
	if(first_pattern_matcher){
		//actions if the first pattern matched
	}else if(second_pattern){
		//actions if the second pattern matched
	...
	}else if(nth_pattern){
		//actions if the nth pattern matched
	}else{
		//default pattern actions here
	}

	result;
)

######## More about matchers ##########

A matcher is a macro that accepts a fix number (defined by the macro) of
input arguments and a fix number (defined by the macro) of output submatched
values.

Input arguments are useful to perform a parametered check on the
current matched value, and it awaits real C expression. For example
the following pattern will match strings equal to "a string":
	same_string("a string")
where "a string" is an input argument. A matcher may have as many input
argument as needed (or none).

Output submatched values are useful to continue the match deeper if
the upper level match succeded. This allows to match subcomponent values
against complex subpattern. For example, knowing that my matched
tree value is a declaration, i may need to check that this decl is named
"my_declaration". I'll then use the following pattern:
	tree_decl_named(same_string("my_declaration"))

Of course, we could have just defined this as an input argument,
but output argument offers much more possibilities. For example, i may
need to match "my_declaration1" or "my_declaration2":
	tree_decl_named(same_string("my_declaration1")||same_string("my_declaration2"))

If i need to match any declaration, but i will need to easily access
the declaration name if the pattern match, i'll use:
	const char *my_declaration_name;
	MATCH(my_tree),
		...

		if(tree_decl_named(MATCH_ASSIGN(my_declaration_name))){
			printf("A declaration name %s was matched.\n",my_declaration_name);
		}

		...
	)

Note that MATCH_ASSIGN always matches.

Moreover, if i need to store the declaration name, but check that it is
either "my_declaration1" or "my_declaration2" or "my_declaration3":
	const char *my_declaration_name;
	MATCH(my_tree,
		...

		if(tree_decl_named(
			(
				same_string("my_declaration1")||same_string("my_declaration2")||same_string("my_declaration3")
			)&&MATCH_ASSIGN(my_declaration_name);
		)){
			printf("A declaration name %s was matched.\n",my_declaration_name);
		}

		...
	)

Not that you could also have used an anonymous matcher by using a
block statement:
	const char *my_declaration_name;
	MATCH(my_tree,
		...

		if(tree_decl_named(
			({
				MATCH_ASSIGN(my_declaration_name);

				same_string("my_declaration1")||same_string("my_declaration2")||same_string("my_declaration3")
			)}
		)){
			printf("A declaration name %s was matched.\n",my_declaration_name);
		}

		...
	)

In the last example, my_declaration_name is always assigned if the tree is a declaration,
even if the decl name do not match. You can easily add side effects for partial matches or
custom matches with anonymous block statement matchers.

In fact, a matcher may do everything, what matters is the returned value.

Use MATCH_ANYTHING (without input arguments or output submatchers) which always
match as a default matcher.

*/

#define MATCHING __matching__
#define MATCH_TEMP_INPUT MATCHING##__temp_input__
#define MATCH_INPUT MATCHING##__input__
#define MATCHED MATCHING##__matched__

#define MATCH_TYPE(type,value,matcher) \
	({ \
		type MATCH_TEMP_INPUT=(value); \
		type MATCH_INPUT=MATCH_TEMP_INPUT; \
		matcher; \
	})
/* MATCH_TEMP_INPUT seems useless here, but is not. Indeed value may */
/* depend on MATCHED. In C, the following doesn't work : */
/* int a=1; */
/* { */
/* 	int a=a*2; */
/* 	printf("%i\n",a); */
/* } */

/* You should use a temporary: */
/* int a=1; */
/* { */
/* 	int b=a; */
/* 	int a=b*2; */
/* 	printf("%i\n",a); */
/* } */

#define MATCH(value,matchers) MATCH_TYPE(__typeof__(value),value,matchers)

#define MATCH_ANYTHING \
	({ \
		(void)MATCH_INPUT; \
		true; \
	})

#define MATCH_ASSIGN(lhs) \
	({ \
		(lhs)=MATCH_INPUT; \
		true; \
	})

/* return non zero in C mode */
int is_gcc();

/* return non zero in C++ mode */
int is_gpp();

/* return non zero in LTO mode */
int is_lto();

/* add a include unit (must be called upon PLUGIN_UNIT_START) */
void cpp_include(const char *file);

/* check if this decl is fully targetable from command line */
bool is_targetable_decl(tree decl);

#define natural greater_or_equal(0)

#define negative_natural lower_or_equal(0)

#define positive greater(0)

#define negative lower(0)

#define compare_matcher(operator,reference) (MATCH_INPUT operator (reference))

#define greater_or_equal(reference) compare_matcher(>=,reference)

#define greater(reference) compare_matcher(>,reference)

#define lower_or_equal(reference) compare_matcher(<=,reference)

#define lower(reference) compare_matcher(<,reference)

#define equal_to(reference) compare_matcher(==,reference)

#define different_from(reference) compare_matcher(!=,reference)

#define match_empty_string (MATCH_INPUT==NULL||*MATCH_INPUT=='\0')

#define match_non_empty_string (!match_empty_string)

#define same_string(reference) (MATCH_INPUT!=NULL&&!strcmp(MATCH_INPUT,(reference)))

#define different_string(reference) (!same_string(reference))

#define match_tree_code(code_matcher) (MATCH(TREE_CODE(MATCH_INPUT),code_matcher))

#define gimple_assign(lhs_matcher,subcode_matcher) (MATCH_INPUT!=NULL&&gimple_code(MATCH_INPUT)==GIMPLE_ASSIGN&&MATCH(gimple_assign_lhs(MATCH_INPUT),lhs_matcher)&&MATCH(gimple_expr_code(MATCH_INPUT),subcode_matcher))

#define tree_decl (MATCH_INPUT!=NULL&&DECL_P(MATCH_INPUT))

#define nonjump_insn(content_matcher) (NONJUMP_INSN_P(MATCH_INPUT)&&MATCH(PATTERN(MATCH_INPUT),content_matcher))

#define note_insn(note_kind_matcher,data_matcher) (NOTE_P(MATCH_INPUT)&&MATCH(NOTE_KIND(MATCH_INPUT),note_kind_matcher)&&MATCH(NOTE_DATA(MATCH_INPUT),data_matcher))

#define rtx_code(code_matcher) (MATCH(GET_CODE(MATCH_INPUT),code_matcher))

#define rtx_mode(mode_matcher) (MATCH(GET_MODE(MATCH_INPUT),mode_matcher))

#define rtx_mode_class(mode_class_matcher) (MATCH(GET_MODE_CLASS(GET_MODE(MATCH_INPUT)),mode_class_matcher))

#define const_int_rtx(intval_matcher) (CONST_INT_P(MATCH_INPUT)&&MATCH(INTVAL(MATCH_INPUT),intval_matcher))

#define reg_rtx (REG_P(MATCH_INPUT))

#define parallel_rtx (GET_CODE(MATCH_INPUT)==PARALLEL)

#define set_rtx(src_matcher,dest_matcher) (GET_CODE(MATCH_INPUT)==SET&&MATCH(SET_SRC(MATCH_INPUT),src_matcher)&&MATCH(SET_DEST(MATCH_INPUT),dest_matcher))

#define binary_rtx(input_code,op1_matcher,op2_matcher) (GET_CODE(MATCH_INPUT)==(input_code)&&MATCH(XEXP(MATCH_INPUT,0),op1_matcher)&&MATCH(XEXP(MATCH_INPUT,1),op2_matcher))

#define any_parallel(operand_matcher) \
	({ \
		bool MATCHED=false; \
		int MATCHING##__max__=XVECLEN(MATCH_INPUT,0); \
		 \
		for(int MATCHING##__i__=0;MATCHING##__i__<MATCHING##__max__;++MATCHING##__i__){ \
			MATCHED=MATCH(XVECEXP(MATCH_INPUT,0,MATCHING##__i__),operand_matcher); \
			 \
			if(MATCHED){ \
				break; \
			} \
		} \
		 \
		MATCHED; \
	})

#define clobber_rtx(op_matcher) (GET_CODE(MATCH_INPUT)==CLOBBER&&MATCH(XEXP(MATCH_INPUT,0),op_matcher))

bool comparison_set_rtx_1(rtx match_input,rtx *cc_op,rtx *op1,rtx *op2);

/* true if a SET rxt actually enclose a COMPARE RTX setting condition code */
#define comparison_set_rtx(cc_op_matcher,op1_matcher,op2_matcher) \
	({ \
		bool MATCHED=false; \
		rtx MATCHING##__cc_op__=NULL_RTX; \
		rtx MATCHING##__op1__=NULL_RTX; \
		rtx MATCHING##__op2__=NULL_RTX; \
		 \
		if(comparison_set_rtx_1(MATCH_INPUT,&MATCHING##__cc_op__,&MATCHING##__op1__,&MATCHING##__op2__)){ \
			MATCHED=MATCH(MATCHING##__cc_op__,cc_op_matcher)&&MATCH(MATCHING##__op1__,op1_matcher)&&MATCH(MATCHING##__op2__,op2_matcher); \
		} \
		 \
		MATCHED; \
	})

#endif
