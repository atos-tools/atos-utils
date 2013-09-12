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





bool comparison_set_rtx_1(rtx match_input,rtx *cc_op,rtx *op1,rtx *op2){
	if(GET_CODE(match_input)==SET){
		rtx compare=SET_SRC(match_input);
		*cc_op=SET_DEST(match_input);

		if(GET_MODE_CLASS(GET_MODE(*cc_op))==MODE_CC&&GET_CODE(compare)==COMPARE){
			/* operation that just sets condition codes (in fact, testing if
			   the destination is a condition code register might be useless,
			   as a COMPARE RTL can only be used to set condition code). */

			*op1=XEXP(compare,0);
			*op2=XEXP(compare,1);

			return true;
		}
	}

	return false;
}
