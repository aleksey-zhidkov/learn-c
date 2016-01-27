#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int max_line);
int remove_trailing_blanks(char line[], int len);

/* remove trailing blanks and tabs and delete entirely blank lines */
void main() {
  int len;
  int max = 0;
  char line[MAXLINE];
  char longest[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    int new_len = remove_trailing_blanks(line, len);
    if (new_len > 0) {
      printf("%s\n", line);
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

int remove_trailing_blanks(char line[], int len) {
  int i = len - 1;
  for (; i >= 0; i--) {
    if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n') {
      break;
    }
  }
  line[i + 1] = '\0';
  return i + 1;
}
