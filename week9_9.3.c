#include <stdio.h>

void reorder(int *a, int *b, int *c);
void swap(int *p1, int *p2);

int main(){
 int a;
 int b;
 int c;

 printf("Enter 3 numbers to reorder: ");
 scanf("%d %d %d", &a, &b, &c);
 reorder(&a, &b, &c);
 printf("a: %d, b: %d, c: %d\n", a, b, c);
}

void swap(int *p1, int *p2) {
  if (*p1 < *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
  }
}

void reorder(int *a, int *b, int *c) {
  int temp;
  swap(c, b);
  swap(b, a);
  swap(c, b);
}
