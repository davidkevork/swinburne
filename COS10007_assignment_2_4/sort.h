
#include "common.h"

#ifndef COS10007_SORT_H
#define COS10007_SORT_H

void swap(USELESS* a, USELESS* b);
void reverse(USELESS* uselessArray, int n);
void bubbleSort(USELESS* uselessArray, int n, int order, int uselessType);
void selectionSort(USELESS* uselessArray, int n, int order, int uselessType);
void insertionSort(USELESS* uselessArray, int n, int order, int uselessType);

#endif