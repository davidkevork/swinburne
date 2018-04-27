#include <stdio.h>

void swap(int *p1, int *p2);

int main(){
 int x = 10;
 int y = 20;
 swap(&x, &y);
 // Should print out x: 20, y: 10
 printf("x: %d, y: %d\n", x, y);
}

void swap(int *p1, int *p2) {
  if (*p1 < *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
  }
}
