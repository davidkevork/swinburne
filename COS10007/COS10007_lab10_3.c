#include <iostream>

#define M_PI 3.14159

float sphereVolume(float r)
{
  return ((4 / 3) * M_PI * r * r * r);
}

int main(int argc, char const *argv[])
{
  float radius;
  std::cout << "Enter circle radius: ";
  std::cin >> radius;
  std::cout << "The volume of the sphere is " << sphereVolume(radius) << std::endl;
  return 0;
}
