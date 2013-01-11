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
