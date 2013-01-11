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
