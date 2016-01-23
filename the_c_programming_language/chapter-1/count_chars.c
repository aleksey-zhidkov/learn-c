#include <stdio.h>

void main() {
  double cnt;
  for (cnt = 0; getchar() != EOF; ++cnt)
    ;
  printf("%.0f\n", cnt);
}
