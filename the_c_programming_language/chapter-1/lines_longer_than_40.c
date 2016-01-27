#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int max_line);

/* print lines longer than 40 */
void main() {
  int len;
  int max = 0;
  char line[MAXLINE];
  char longest[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    if (len > 40) {
      printf("%s", line);
    }
  }
}

int get_line(char s[], int lim) {
  int i = 0;
  int c;
  while ((c=getchar()) != EOF && c != '\n') {
    if (i < lim - 1) {
      s[i] = c;
    }
    i++;
  }
  int null_idx = (i < lim - 1) ? i + 1 : lim - 1;
  if (c == '\n') {
    s[null_idx - 1] = c;
    i++;
  }
  s[null_idx] = '\0';
  return i;
}
