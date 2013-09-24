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

#include "plugin-utils.h"

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
