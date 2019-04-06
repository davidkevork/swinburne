#include <stdio.h>

unsigned int swaps = 0;

// swap two integers
void swap(int *a, int *b)
{
  ++swaps;
  int temp = *a;
  *a = *b;
  *b = temp;
}

// bubble sort
void bubbleSort(int array[], int n)
{
  for(size_t i = 0; i < n - 1; i++)
  {
    for(size_t j = 0; j < n - i - 1; j++)
    {
      if (array[j] > array[j + 1])
      {
        swap(&array[j], &array[j + 1]);
      }
    } 
  }
}

// selection sort by choosing the last element
void selectionSort(int array[], int n)
{
  for(size_t i = n - 1; i > 0; i--)
  {
    int max = i;
    for(size_t j = i; j > 0; j--)
    {
      if (array[j - 1] > array[max]) {
        max = j - 1;
      }
    }
    swap(&array[i], &array[max]);
  }
}

void insertionSort(int array[], int n)
{
  for(size_t i = 1; i < n; i++)
  {
    int elm = array[i];
    int j = i - 1;
    while (j >= 0 && array[j] > elm)
    {
      array[j + 1] = array[j];
      j = j - 1;
    }
    array[j + 1] = elm;
  }
}

void countSort(int array[], int n, int low, int high)
{
  int list[high - low];
  for(size_t i = 0; i < (high - low); i++)
  {
    list[i] = 0;
  }
  for(size_t j = 0; j < n; j++)
  {
    list[array[j]]++;
  }
  int k = 0;
  for(size_t l = 0; l < (high - low); l++)
  {
    if (list[l] > 0) {
      for(size_t m = 0; m < list[l]; m++)
      {
        array[k] = l;
        k++;
      }
    }
  }
}

void printArray(int array[], int n)
{
  for(size_t i = 0; i < n; i++)
  {
    printf("%d -> ", array[i]);
  }
  printf("NULL\n");
}

void printSwaps()
{
  printf("Number of swaps: %u\n", swaps);
}

int main()
{
  swaps = 0;
  int bubbleArray[] = {21, 38, 40, 11, 18, 64, 62, 48, 30, 9, 98, 27, 96, 61, 38, 6, 78, 69, 12, 33};
  unsigned int bsize = sizeof(bubbleArray) / sizeof(bubbleArray[0]);
  printArray(bubbleArray, bsize);
  bubbleSort(bubbleArray, bsize);
  printArray(bubbleArray, bsize);
  printSwaps();
  
  swaps = 0;
  int insertionArray[] = {21, 38, 40, 11, 18, 64, 62, 48, 30, 9, 98, 27, 96, 61, 38, 6, 78, 69, 12, 33};
  unsigned int isize = sizeof(insertionArray) / sizeof(insertionArray[0]);
  printArray(insertionArray, isize);
  insertionSort(insertionArray, isize);
  printArray(insertionArray, isize);
  printSwaps();

  swaps = 0;
  int selectionArray[] = {21, 38, 40, 11, 18, 64, 62, 48, 30, 9, 98, 27, 96, 61, 38, 6, 78, 69, 12, 33};
  unsigned int ssize = sizeof(selectionArray) / sizeof(selectionArray[0]);
  printArray(selectionArray, ssize);
  selectionSort(selectionArray, ssize);
  printArray(selectionArray, ssize);
  printSwaps();

  swaps = 0;
  int countArray[] = {21, 38, 40, 11, 18, 64, 62, 48, 30, 9, 98, 27, 96, 61, 38, 6, 78, 69, 12, 33};
  unsigned int csize = sizeof(countArray) / sizeof(countArray[0]);
  printArray(countArray, csize);
  countSort(countArray, csize, 0, 100);
  printArray(countArray, csize);
  printSwaps();

  return 0;
}
