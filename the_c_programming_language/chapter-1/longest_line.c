#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int max_line);
void copy(char to[], char from[]);

/* print longest input line */
void main() {
  int len;
  int max = 0;
  char line[MAXLINE];
  char longest[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }

  if (max > 0) {
    printf("%d: %s", max, longest);
  }
}

int get_line(char s[], int lim) {
  int i = 0;
  int c;
  for (; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; i++) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    i++;
  }
  s[i] = '\0';
  return i;
}

void copy(char to[], char from[]) {
  int i = 0;
  while ((to[i] = from[i]) != '\0') {
    i++;
  }
}
     
