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

#include <stdlib.h>
#include "plugin-utils.h"
#include "cpplib.h"

static int is_gcc_cache=-1;
static int is_gpp_cache=-1;
static int is_lto_cache=-1;

int is_gcc(){
	if(is_gcc_cache==-1){
		is_gcc_cache=!strcmp(lang_hooks.name,"GNU C");
	}

	return is_gcc_cache;
}

int is_gpp(){
	if(is_gpp_cache==-1){
		is_gpp_cache=!strcmp(lang_hooks.name,"GNU C++");
	}

	return is_gpp_cache;
}

int is_lto(){
	if(is_lto_cache==-1){
		is_lto_cache=!strcmp(lang_hooks.name,"GNU GIMPLE");
	}

	return is_lto_cache;
}





#if __GCC_VERSION__>=40600
bool is_targetable_decl(tree decl){
	#if __GCC_VERSION__>40700
		return DECL_NAME(decl)!=NULL_TREE&&!DECL_NAMELESS(decl)&&(DECL_FILE_SCOPE_P(decl)||(is_gpp()&&(DECL_NAMESPACE_SCOPE_P(decl)||(DECL_CLASS_SCOPE_P(decl)&&((TREE_CODE(decl)==FUNCTION_DECL&&DECL_FUNCTION_MEMBER_P(decl))||DECL_THIS_STATIC(decl))))));
	#else
		// Some C++ specific definition are not visible as cp/cp-tree.h can't
		// be included
		return DECL_NAME(decl)!=NULL_TREE&&!DECL_NAMELESS(decl)&&(DECL_FILE_SCOPE_P(decl)||is_gpp());
	#endif
}

bool is_targetable_type(tree type){
	return TYPE_NAME(type)!=NULL_TREE&&!TYPE_NAMELESS(type)&&TYPE_FILE_SCOPE_P(type);
}
#endif

bool comparison_set_rtx_1(rtx match_input,rtx *cc_op,rtx *op1,rtx *op2){
	if(GET_CODE(match_input)==SET){
		rtx compare=SET_SRC(match_input);
		*cc_op=SET_DEST(match_input);

		if(GET_MODE_CLASS(GET_MODE(*cc_op))==MODE_CC&&GET_CODE(compare)==COMPARE){
			//operation that just sets condition codes (in fact, testing if
			//the destination is a condition code register might be useless,
			//as a COMPARE RTL can only be used to set condition code).

			*op1=XEXP(compare,0);
			*op2=XEXP(compare,1);

			return true;
		}
	}

	return false;
}
