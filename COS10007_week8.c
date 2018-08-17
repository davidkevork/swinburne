#include <stdio.h>

int linearSearch(int array[], int size, int search)
{
  for(size_t i = 0; i < size; i++)
  {
    if (array[i] == search) {
      return i;
    }
  }
  return -1;
}

int binarySearch(int array[], int size, int low, int search)
{
  int index = -1;
  if (size > 1)
  {
    int mid = low + (size - low) / 2;
    if (array[mid] == search) {
      return mid;
    } else if (array[mid] > search) {
      return binarySearch(array, mid-1, low, search);
    } else {
      return binarySearch(array, size, mid+1, search);
    }
  }
}

int main()
{
  int linearArray[] = {5, 8, 10, 13, 18, 22, 27, 35, 37, 40, 41, 48, 50, 53, 59, 66, 78, 81, 96, 100};
  int lsize = sizeof(linearArray) / sizeof(linearArray[0]);
  printf("The element 48 is at index: %d\n", linearSearch(linearArray, lsize, 48));

  int binaryArray[] = {5, 8, 10, 13, 18, 22, 27, 35, 37, 40, 41, 48, 50, 53, 59, 66, 78, 81, 96, 100};
  int bsize = sizeof(binaryArray) / sizeof(binaryArray[0]);
  printf("The element 48 is at index: %d\n", binarySearch(linearArray, lsize, 0, 48));

  return 0;
}
