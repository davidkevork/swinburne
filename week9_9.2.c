#include <stdio.h>

void AddTwo(float *f, float *s, float *t);

int main(){
 float j;
 float k;
 float m;
 printf("Enter 2 numbers to add: ");
 scanf("%f %f", &j, &k);
 AddTwo(&j, &k, &m);
 printf("j: %f, k: %f, m: %f\n", j, k, m);
}

void AddTwo(float *f, float *s, float *t) {
  *t = *f + *s;
}
