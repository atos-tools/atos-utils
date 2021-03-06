#include <stdio.h>

int toto = 10;
int tutu;
int tata[100];

#define TAB_SIZE 100
int tab[TAB_SIZE];

extern void tab_init (int *tab);
extern void tab_print (int *tab);
extern int func1 (int *tab);

#ifndef LTO
void tab_init (int *tab) {
    int res, i;

    for (i = 0; i < TAB_SIZE; i++) {
	tab[i] = 1;	
    }
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
#endif

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

    return 0;
}
