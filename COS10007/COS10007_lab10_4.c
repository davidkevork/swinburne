#include <iostream>

int doubleByValue(int n)
{
  return n * n;
}

void doubleByReference(int *n)
{
  *n = (*n) * (*n);
}

int main(int argc, char const *argv[])
{
  int n = 10;
  std::cout << doubleByValue(n) << std::endl;;
  doubleByReference(&n);
  std::cout << n << std::endl;
  return 0;
}
