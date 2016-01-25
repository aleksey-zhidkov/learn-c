#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

void main() {
  bool print_new_line = false;
  int8_t c;
  while ((c = getchar()) != EOF) {
    if ((c == ' ' || c == '\t' || c == '\n')) {
      if (print_new_line) {
	putchar('\n');
	print_new_line = false;
      }
    } else {
      putchar(c);
      print_new_line = true;
    }
  }
}
