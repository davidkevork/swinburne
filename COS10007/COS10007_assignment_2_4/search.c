#include <stdlib.h>
#include "common.h"

// linear search
int linearSearch(USELESS uselessArray[], unsigned int size, int uselessInt)
{
  for(size_t i = 0; i < size; ++i)
  {
    if (uselessArray[i].uselessInt == uselessInt) {
      return i;
    }
  }
  return -1;
}

// binary search
int binarySearch(USELESS uselessArray[], unsigned int size, int low, int uselessInt)
{
  if (size >= 1)
  {
    int mid = low + (size - low) / 2;
    if (uselessArray[mid].uselessInt == uselessInt) {
      return mid;
    } else if (uselessArray[mid].uselessInt > uselessInt) {
      return binarySearch(uselessArray, mid-1, low, uselessInt);
    } else {
      return binarySearch(uselessArray, size, mid+1, uselessInt);
    }
  }
  return -1;
}