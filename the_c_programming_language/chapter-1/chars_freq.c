#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define CHARS_COUNT 26

void main() {
  int lower_chars_freqs[CHARS_COUNT];
  int upper_chars_freqs[CHARS_COUNT];
  for (int i = 0; i < CHARS_COUNT; i++) {
    lower_chars_freqs[i] = 0;
    upper_chars_freqs[i] = 0;
  }
  
  int max_freq = 0;
  int c;
  while ((c = getchar()) != EOF) {
    if (c >= 'a' && c <= 'z') {
      int freq = lower_chars_freqs[c - 'a']++;
      if (freq > max_freq) {
	max_freq = freq;
      }
    }
    if (c >= 'A' && c <= 'Z') {
      int freq = upper_chars_freqs[c - 'A']++;
      if (freq > max_freq) {
	max_freq = freq;
      }
    }
  }

  for (int i = max_freq; i > 0; i--) {
    for (int j = 0; j < CHARS_COUNT; j++) {
      if (i <= upper_chars_freqs[j]) {
	putchar('=');
      } else {
	putchar(' ');
      }
    }
    for (int j = 0; j < CHARS_COUNT; j++) {
      if (i <= lower_chars_freqs[j]) {
	putchar('=');
      } else {
	putchar(' ');
      }
    }
    putchar('\n');
  }
  for (int i = 0; i < CHARS_COUNT * 2; i++) {
    putchar('-');
  }
  putchar('\n');
  for (int i = 0; i < CHARS_COUNT; i++) {
    putchar(i + 'A');
  }
  for (int i = 0; i < CHARS_COUNT; i++) {
    putchar(i + 'a');
  }

}
