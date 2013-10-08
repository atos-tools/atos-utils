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

#ifndef ACF_PLUGIN_PLUGIN_SRC_PLUGIN_UTILS_H_
#define ACF_PLUGIN_PLUGIN_SRC_PLUGIN_UTILS_H_

#include "gcc-plugin.h"
#include "tree.h"
#include "langhooks.h"

/* return non zero in C mode */
extern int is_gcc(void);

/* return non zero in C++ mode */
extern int is_gpp(void);

/* return non zero in LTO mode */
extern int is_lto(void);

#endif /* ACF_PLUGIN_PLUGIN_SRC_PLUGIN_UTILS_H_ */
