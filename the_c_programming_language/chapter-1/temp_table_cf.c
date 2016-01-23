#include <stdio.h>

void main() {
  // f = 32 + c / (5 / 9)
  float lower = -50;
  float upper = 50;
  float step = 10;

  for (float temp = lower; temp <= upper; temp += step) {
    float farh = 32.0 + temp / (5.0 / 9.0);
    printf("%3.0f %6.1f\n", temp, farh);
  }
}
