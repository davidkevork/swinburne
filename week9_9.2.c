#include <stdio.h>

void AddTwo(float *f, float *s, float *t);

int main(){
 int x = 10;
 int y = 20;
 int sum;
 AddTwo(&x, &y, &sum);
 printf("x: %d, y: %d, sum: %d\n", x, y, sum);
}

void AddTwo(float *f, float *s, float *t) {
  *t = *f + *s;
}
