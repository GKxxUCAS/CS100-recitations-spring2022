#include <stdio.h>

int main() {
  FILE *in = fopen("testcase.in", "r");
  FILE *out = fopen("testcase.out", "w");
  int a, b;
  fscanf(in, "%d%d", &a, &b);
  fprintf(out, "%d\n", a + b);
  fclose(in);
  fclose(out);
  return 0;
}
