#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int max_line);
int reverse(char line[], int len);

/* reverse lines */
void main() {
  int len;
  int max = 0;
  char line[MAXLINE];
  char longest[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    reverse(line, len);
    printf("%s\n", line);
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

int reverse(char line[], int len) {
  int middle = len / 2;
  for (int i = 0; i < middle; i++) {
    char tmp = line[i];
    line[i] = line[len - i - 1];
    line[len - i - 1] = tmp;
  }
}
