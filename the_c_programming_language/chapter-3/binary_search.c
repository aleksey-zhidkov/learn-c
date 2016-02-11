#include <stdio.h>

int arr1[] = {0, 1, 3, 4, 6, 7, 8, 9, 11};

int binary_search(int x, int data[], int n);

void check(int x, int expected);

void main() {
  check(-1, -1);
  check(0, 0);
  check(1, 1);
  check(3, 2);
  check(5, -1);
  check(8, 6);
  check(9, 7);
  check(10, -1);
  check(11, 8);
  printf("All tests passed\n");
}

int binary_search(int x, int data[], int n) {
  int low = 0;
  int high = n;
  while (low < high - 1) {
    int mid = (low + high) / 2;
    if (x < data[mid]) {
      high = mid;
    } else {
      low = mid;
    }
  }

  if (data[low] == x) {
    return low;
  } else {
    return -1;
  }
}

void check(int x, int expected) {
  printf("checking %d\n", x);
  int res = binary_search(x, arr1, 9);
  if (res != expected) {
    printf("%d != %d\n", res, expected);
    exit(-1);
  }
}
