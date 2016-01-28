#include "lines.c"

#define MAXLINE 1000
#define SPACES_PER_TAB 4

void map(char c, char res[]);

void main() {
  
  int len;
  char line[MAXLINE];
  char mapped_char[SPACES_PER_TAB + 1];
  while ((len = get_line(line, MAXLINE)) > 0) {
    for (int i = 0; i < len; i++) {
      map(line[i], mapped_char);
      printf("%s", mapped_char);
    }
  }
}

void map(char c, char res[]) {
  if (c == '\t') {
    int i = 0;
    for (;i < SPACES_PER_TAB; i++) {
      res[i] = ' ';
    }
    res[i] = '\0';
  } else {
    res[0] = c;
    res[1] = '\0';
  }
}
