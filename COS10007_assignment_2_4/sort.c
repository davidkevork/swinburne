#include <stdlib.h>
#include <string.h>
#include "common.h"

// swap two structures
void swap(USELESS* a, USELESS* b)
{
    USELESS temp;
    strcpy(temp.uselessString, a->uselessString);
    temp.uselessInt = a->uselessInt;
    temp.uselessFloat = a->uselessFloat;

    strcpy(a->uselessString, b->uselessString);
    a->uselessInt = b->uselessInt;
    a->uselessFloat = b->uselessFloat;

    strcpy(b->uselessString, temp.uselessString);
    b->uselessInt = temp.uselessInt;
    b->uselessFloat = temp.uselessFloat;
}

// reverse the order of the array
void reverse(USELESS* uselessArray, int n)
{
    USELESS newUselessArray[n];
    for(size_t i = 0; i < n; ++i)
    {
        newUselessArray[i] = uselessArray[i];
    }
    for(size_t j = 0; j < n; ++j)
    {
        uselessArray[n - j - 1] = newUselessArray[j];
    }
}

// bubble sort
void bubbleSort(USELESS* uselessArray, int n, int order, int uselessType)
{
    for(size_t i = 0; i < n - 1; i++)
    {
        for(size_t j = 0; j < n - i - 1; j++)
        {
            if (uselessType == 0)
            {
                if (uselessArray[j].uselessInt > uselessArray[j + 1].uselessInt)
                {
                    swap(&uselessArray[j], &uselessArray[j + 1]);
                }
            } else {
                if (uselessArray[j].uselessFloat > uselessArray[j + 1].uselessFloat)
                {
                    swap(&uselessArray[j], &uselessArray[j + 1]);
                }
            }
        }
    }
    if (order == 1) {
        reverse(uselessArray, n);
    }
}

// selection sort by choosing the last element
void selectionSort(USELESS* uselessArray, int n, int order, int uselessType)
{
    for(size_t i = n - 1; i > 0; i--)
    {
        int max = i;
        for(size_t j = i; j > 0; j--)
        {
            if (uselessType == 0)
            {
                if (uselessArray[j].uselessInt > uselessArray[j + 1].uselessInt)
                {
                    max = j;
                }
            } else {
                if (uselessArray[j].uselessFloat > uselessArray[j + 1].uselessFloat)
                {
                    max = j;
                }
            }
        }
        swap(&uselessArray[i], &uselessArray[max]);
    }
    if (order == 1) {
        reverse(uselessArray, n);
    }
}

// insertion sort
void insertionSort(USELESS* uselessArray, int n, int order, int uselessType)
{
    for(size_t i = 0; i < n; ++i)
    {
        USELESS elm = uselessArray[i];
        int j = i - 1;
        if (uselessType == 0)
        {
            while (j >= 0 && uselessArray[j].uselessInt > elm.uselessInt)
            {
                uselessArray[j + 1] = uselessArray[j];
                j = j - 1;
            }
            uselessArray[j + 1] = elm;
        } else {
            while (j >= 0 && uselessArray[j].uselessFloat > elm.uselessFloat)
            {
                uselessArray[j + 1] = uselessArray[j];
                j = j - 1;
            }
            uselessArray[j + 1] = elm;
        }
    }
    if (order == 1) {
        reverse(uselessArray, n);
    }
}