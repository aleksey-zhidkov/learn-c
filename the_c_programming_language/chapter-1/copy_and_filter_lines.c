#include <stdio.h>

void main() {
  int c;
  int print_space = 0;
  int print_slash = 0;
  while ((c = getchar()) != EOF) {
      if (c == ' ') {
	print_space = 1;
	continue;
      } else if (c == '\t') {
	c = 't';
	print_slash = 1;
      } else if (c == '\b') {
	c = 'b';
	print_slash = 1;
      } 

      if (print_space) {
	printf(" ");
	print_space = 0;
      }
      if (print_slash) {
	putchar('\\');
	print_slash = 0;
      }

      putchar(c);
    }
}
