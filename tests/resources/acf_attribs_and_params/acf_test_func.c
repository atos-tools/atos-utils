#include <stdio.h>

#ifdef LTO

extern int toto;
extern int tutu;
extern int tata[100];

#define TAB_SIZE 100
extern int tab[TAB_SIZE];

void tab_init (int *tab);
void tab_print (int *tab);
int func1 (int *tab);

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
