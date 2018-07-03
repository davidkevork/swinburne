#include <stdio.h>

void swap(int *p1, int *p2);

int main() {
  int x = 50;
  int y = 60;

  swap(&x, &y);

  // Should print out x: 50, y: 60
  printf("x: %d, y: %d\n", x, y);

  return 0;
}

void swap(int *p1, int *p2) {
  int temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}
