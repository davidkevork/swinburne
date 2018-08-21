#include <stdio.h>

#define M_PI 3.14159

float sphereVolume(float r)
{
  return ((4 / 3) * M_PI * r * r * r);
}

int main(int argc, char const *argv[])
{
  float radius;
  printf("Enter circle radius: ");
  scanf("%.2f", &radius);
  printf("The volume of the sphere is %.2f\n", sphereVolume(radius));
  return 0;
}
