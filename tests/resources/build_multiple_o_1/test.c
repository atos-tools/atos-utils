#include <stdio.h>

#define STRINGIZE(x) #x
#define STR(x) STRINGIZE(x)

int FOO(void) {
  printf("Hello, I'm %s\n", STR(FOO));
  return 0;
}
