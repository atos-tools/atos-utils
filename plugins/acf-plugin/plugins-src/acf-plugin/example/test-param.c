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

#define TAB_SIZE 128

#define BODY \
  int i, res = 0; \
L1: \
  for (i = 0; i < TAB_SIZE; i++) \
    res += (i&(i+1))-(i&(i-1)); \
 L2: \
  return (res == 0) ? (&&L2-&&L1) : 0;

int func_unroll1() {
  BODY
}

int func_unroll2() {
  BODY
}

int func_unroll4() {
  BODY
}
