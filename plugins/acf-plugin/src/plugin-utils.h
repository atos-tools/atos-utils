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
#include "langhooks.h"

/* return non zero in C mode */
int is_gcc();

/* return non zero in C++ mode */
int is_gpp();

/* return non zero in LTO mode */
int is_lto();

#endif
