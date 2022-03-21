#include <stdio.h>

int main() {
  FILE *in = fopen("in_file", "r");
  int a, b;
  scanf("%d%d", &a, &b);
  printf("%d\n", a + b);
  return 0;
}
