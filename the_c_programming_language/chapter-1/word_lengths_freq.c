#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 32

void main() {
  int word_length[MAX_WORD_LENGTH];
  for (int i = 0; i < MAX_WORD_LENGTH; i++) word_length[i] = 0;
  
  int8_t c;
  int cur_word_length;
  while ((c = getchar()) != EOF) {
    if ((c == ' ' || c == '\t' || c == '\n')) {
      if (cur_word_length > 0) {
	word_length[cur_word_length]++;
      }
      cur_word_length = 0;
    } else {
      cur_word_length++;
    }
  }

  for (int i = 1; i < MAX_WORD_LENGTH; i++) {
    printf("%2d - ", i);
    for (int j = 0; j < word_length[i]; j++) {
      putchar('-');
    }
    printf("\n");
  }
}
