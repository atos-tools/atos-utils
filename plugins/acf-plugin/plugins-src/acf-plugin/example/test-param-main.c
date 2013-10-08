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

#include <stdio.h>

extern int func_unroll1(void);
extern int func_unroll2(void);
extern int func_unroll4(void);

int main(int argc, char **argv) {

  int size_unroll1, size_unroll2, size_unroll4;

  size_unroll1 = func_unroll1();
  size_unroll2 = func_unroll2();
  size_unroll4 = func_unroll4();

  if ((size_unroll1 == 0) || (size_unroll2 == 0) || (size_unroll4 == 0)) {
    printf("Not functional, or could not compute loop size. Error.\n");
    return 1;
  }

  if ((size_unroll1 >= size_unroll2) || (size_unroll2 >= size_unroll4)) {
    printf("loop size: unroll=1 size=%d, unroll=2 size=%d, unroll=4 size=%d\n",
	   size_unroll1, size_unroll2, size_unroll4);
    printf("--param max-unroll-times not used. Error.\n");
    return 1;
  }

  printf("Success\n");

  return 0;
}
