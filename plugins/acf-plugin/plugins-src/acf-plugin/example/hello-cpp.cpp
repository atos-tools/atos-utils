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

int toto = 10;
int tutu;
int tata[100];

#define TAB_SIZE 100
int tab[TAB_SIZE];

void tab_init (int *tab) {
    int res, i;

    for (i = 0; i < TAB_SIZE; i++) {
	tab[i] = 1;	
    }
}

int square(int val) {
    return val*val;
}

void tab_print (int *tab) {
    int res, i;

    printf("tab[0..%d]= {", TAB_SIZE);
    for (i = 0; i < TAB_SIZE; i++) {
	printf("%d,",tab[i]);	
    }
    printf("}\n");

}

int func1 (int *tab) {
    int res, i;

    for (i = 0; i < TAB_SIZE; i++) {
	tab[i] = tab[i] * 8;	
    }

    return 1;
}

int func2 (int *tab) {
    int res, i;

    for (i = 0; i < TAB_SIZE; i++) {
	tab[i] = square(tab[i]) + i;	
    }

    return 2;
}

int main(int argc, char **argv) {
    int titi = 11;
    int i, res;

    if (argc > 1) {
	for (i = 1; i < argc; i++)
	    printf("arg[%d]= %s  ", i, argv[i]);
	printf("\n");
    } else {
	printf("No argument passed...\n");
    }

    printf("Hello World: toto= %d (10?), tutu=%d (0?), titi= %d (11?)\n", toto , tutu , titi);

    if (toto == 10) {
	printf("toto(=%d) == 10 is TRUE (OK)\n", toto);
    } else {
	printf("toto(=%d) == 10 is FALSE (BADDDD)\n", toto);
    }

    if (toto == 1) {
	printf("toto(=%d) == 1 is TRUE (BADDDD)\n", toto);
    } else {
	printf("toto(=%d) == 1 is FALSE (OK)\n", toto);
    }

    if (toto != 1) {
	printf("toto(=%d) != 1 is TRUE (OK)\n", toto);
    } else {
	printf("toto(=%d) != 1 is FALSE (BADDDD)\n", toto);
    }

    if (1) {
	int error = 0;
	int j;
    for (j = 0; j < 100; j++) {
	if (tata[j] != 0) {
	    printf("Error: bss may be not cleared!\n");
	    error = 1;
	    break;
	}
    }
    if (!error)
	printf("tata[100]={0...0} bss probably cleared\n");
    }

    tab_init(tab);
    tab_print(tab);

    res = func1(tab);
    tab_print(tab);

    res = func2(tab);
    tab_print(tab);

    return 0;
}
