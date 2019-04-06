#include <stdio.h>

void addTwo(float *j, float *k, float *m);

int main() {
  float j;
  float k;
  float m;

  printf("Enter first number:");
  scanf("%f", &j);

  printf("Enter first number:");
  scanf("%f", &k);

  addTwo(&j, &k, &m);

  printf("address: %p, value: %f\n", &m, m);

  return 0;
}

void addTwo(float *j, float *k, float *m) {
  *m = *j + *k;
}
