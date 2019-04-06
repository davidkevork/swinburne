#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "SwinGame.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 700

struct sample
{
    int value;
    color clr;
};

void fillData(int data[], struct sample *arrayPtr);
void fillArray(int data[], struct sample *arrayPtr);
color get_color(int num);
void fill_array(struct sample array[]);
void draw_bar(struct sample array[]);
void draw_button(color clr, const char *name, float x, float y, int w, int h);
bool button_clicked(int xValue, int yValue, int btnWidth, int btnHeight);
void drawAllTheButtons();
void bubbleSort(int arr[]);
void selectionSort(int arr[]);
void insertionSort(int arr[]);
void countSort(int arr[], int low, int high);
void mergeSort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int *a, int *b);

int main()
{
    // open the window and set colors
    open_graphics_window("Assignment 2 - Q. 1 - Sorting Algorithm", WINDOW_WIDTH, WINDOW_HEIGHT);
    load_default_colors();
    clear_screen(ColorWhite);

    // srand for random numbers
    srand(time(NULL));
    // initialize pointer and array and then set memory
    struct sample *arrayPtr, array[1];
    arrayPtr = (struct sample *)malloc(800 * sizeof(array[1]));

    // fill the array
    fill_array(arrayPtr);
    // window will re-render only when shouldDraw is set to 0
    int shouldDraw = 1;

    // do while the user didn't close the window
    do
    {
        if (key_typed(BKEY) || button_clicked(15, 35, 100, 30))
        {
            // when `b` key is clicked for bubble sort
            int data[WINDOW_WIDTH - 1];
            fillData(data, arrayPtr);
            bubbleSort(data);
            fillArray(data, arrayPtr);
            shouldDraw = 1;
        }
        else if (key_typed(QKEY) || button_clicked(485, 35, 100, 30))
        {
            // when `q` key is clicked quick sort
            int data[WINDOW_WIDTH - 1];
            fillData(data, arrayPtr);
            quickSort(data, 0, WINDOW_WIDTH - 1);
            fillArray(data, arrayPtr);
            shouldDraw = 1;
        }
        else if (key_typed(SKEY) || button_clicked(130, 35, 110, 30))
        {
            // when `s` key is clicked selection sort
            int data[WINDOW_WIDTH - 1];
            fillData(data, arrayPtr);
            selectionSort(data);
            fillArray(data, arrayPtr);
            shouldDraw = 1;
        }
        else if (key_typed(IKEY) || button_clicked(255, 35, 100, 30))
        {
            // when `i` key is clicked insertion sort
            int data[WINDOW_WIDTH - 1];
            fillData(data, arrayPtr);
            insertionSort(data);
            fillArray(data, arrayPtr);
            shouldDraw = 1;
        }
        else if (key_typed(CKEY) || button_clicked(600, 35, 100, 30))
        {
            // when `c` key is clicked count sort
            int data[WINDOW_WIDTH - 1];
            fillData(data, arrayPtr);
            countSort(data, 0, WINDOW_WIDTH - 1);
            fillArray(data, arrayPtr);
            shouldDraw = 1;
        }
        else if (key_typed(MKEY) || button_clicked(370, 35, 100, 30))
        {
            // when `m` key is clicked merge sort
            int data[WINDOW_WIDTH - 1];
            fillData(data, arrayPtr);
            mergeSort(data, 0, WINDOW_WIDTH - 1);
            fillArray(data, arrayPtr);
            shouldDraw = 1;
        }
        else if (key_typed(FKEY) || button_clicked(715, 35, 80, 30))
        {
            // when `f` key is clicked fill it with new data
            fill_array(arrayPtr);
            shouldDraw = 1;
        }

        // checks is all should re-render
        if (shouldDraw == 1)
        {
            // clears screen, draws bar and sets shouldDraw to 0
            clear_screen(ColorWhite);
            drawAllTheButtons();
            draw_bar(arrayPtr);
            shouldDraw = 0;
        }

        // fps set to 60
        refresh_screen(60);
        delay(60);
    } while (!window_close_requested());

    // free memory and quit
    free(arrayPtr);
    release_all_resources();
    return 0;
}

void fillData(int data[], struct sample *arrayPtr)
{
    for (size_t i = 0; i < WINDOW_WIDTH - 1; ++i)
    {
        data[i] = arrayPtr[i].value;
    }
}

void fillArray(int data[], struct sample *arrayPtr)
{
    for (size_t j = 0; j < WINDOW_WIDTH - 1; ++j)
    {
        arrayPtr[j].value = data[j];
    }
}

/**
 * Returns a random color
 * @param num
 * @return color
 */
color get_color(int num)
{
    float hue = num / (float)WINDOW_HEIGHT;
    return hsbcolor(hue, 0.7, 0.8);
}

/**
 * Fills the array with random numbers and color
 * @param array
 */
void fill_array(struct sample array[])
{
    for (size_t i = 0; i < WINDOW_WIDTH - 1; ++i)
    {
        array[i].value = rand() % (WINDOW_HEIGHT - 100);
        array[i].clr = get_color(array[i].value);
    }
}

/**
 * Draws the bars on the screen
 * @param array
 */
void draw_bar(struct sample array[])
{
    float x, y, rectwidth = 1;
    for (size_t i = 0; i < WINDOW_WIDTH - 1; ++i)
    {
        x = rectwidth * i;
        y = (WINDOW_HEIGHT - array[i].value);
        fill_rectangle(array[i].clr, x, y, rectwidth, array[i].value);
    }
}

/**
 * draws a button on the screen
 */
void draw_button(color clr, const char *name, float x, float y, int w, int h)
{
    fill_rectangle(clr, x, y, w, h);
    draw_text(name, ColorWhite, "arial.ttf", 15, x + 10, y + 5);
}

/**
 * Checks if a button is clicked
 */
bool button_clicked(int xValue, int yValue, int btnWidth, int btnHeight)
{
    float rightValue, bottomValue;
    rightValue = xValue + btnWidth;
    bottomValue = yValue + btnHeight;
    if (mouse_clicked(LEFT_BUTTON))
    {
        if ((mouse_x() >= xValue) && (mouse_x() <= rightValue) && (mouse_y() >= yValue) && (mouse_y() <= bottomValue))
        {
            return true;
        }
    }
    return false;
}

/**
 * Draws all buttons on the screen
 */
void drawAllTheButtons()
{
    // x, y - w, h
    draw_button(ColorBlue, "Bubble Sort", 15, 35, 100, 30);
    draw_button(ColorBlue, "Selection Sort", 130, 35, 110, 30);
    draw_button(ColorBlue, "Insertion Sort", 255, 35, 100, 30);
    draw_button(ColorBlue, "Merge Sort", 370, 35, 100, 30);
    draw_button(ColorBlue, "Quick Sort", 485, 35, 100, 30);
    draw_button(ColorBlue, "Count Sort", 600, 35, 100, 30);
    draw_button(ColorBlue, "Reset", 715, 35, 80, 30);
}

/**
 * This is bubble sort which takes an element
 * and iterated thought each element and orders them
 * it is one of the slowest sort algorithm
 * and one of the simplest algorithm
 */
void bubbleSort(int arr[])
{
    for (size_t i = 0; i < WINDOW_WIDTH; i++)
    {
        for (size_t j = 0; j < WINDOW_WIDTH - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

/**
 * Selection sort works by selecting
 * the smallest element in the index
 * starting from the last element
 * and adding it at the start of the
 * array.
 */
void selectionSort(int arr[])
{
    for (size_t i = WINDOW_WIDTH - 1; i > 0; i--)
    {
        int max = i;
        for (size_t j = i; j > 0; j--)
        {
            if (arr[j - 1] > arr[max])
            {
                max = j - 1;
            }
        }
        swap(&arr[i], &arr[max]);
    }
}

/**
 * Insertion sort is a simple sorting algorithm
 * that works the way we sort playing cards in our hands.
 * Algorithm
 * Sort an arr[] of size n
 * insertionSort(arr, n)
 * Loop from i = 1 to n-1.
 * Pick element arr[i] and insert it into sorted sequence arr[0…i-1]
 */
void insertionSort(int arr[])
{
    for (size_t i = 1; i < WINDOW_WIDTH; i++)
    {
        int elm = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > elm)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = elm;
    }
}

void countSort(int arr[], int low, int high)
{
    int list[WINDOW_HEIGHT-100];
    // set value 0 for all index so we can increment
    for (int i = 0; i < WINDOW_HEIGHT-100; i++)
    {
        list[i] = 0;
    }
    for (int j = 0; j < WINDOW_WIDTH-1; j++)
    {
        list[arr[j]]++;
    }
    int k = 0;
    for (int low = 0; low < WINDOW_HEIGHT-100; low++)
    {
        if (list[low] > 0)
        {
            for (int mid = 0; mid < list[low]; mid++)
            {
                arr[k] = low;
                k++;
            }
        }
    }
}

/**
 * merge sort is similar to quick sort
 * which uses divide and conquer method
 */
void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

/**
 * merges 2 sorted elements together
 */
void merge(int arr[], int low, int mid, int high)
{
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int left[n1], right[n2];

    // Copy data to temp arrays left[] and right[]
    for (i = 0; i < n1; i++)
    {
        left[i] = arr[low + i];
    }
    for (j = 0; j < n2; j++)
    {
        right[j] = arr[mid + 1 + j];
    }

    i = 0;   // Initial index of first subarray
    j = 0;   // Initial index of second subarray
    k = low; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of left[], if there
       are any */
    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of right[], if there
       are any */
    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

/**
 * This function takes last element as pivot, places
 * the pivot element at its correct position in sorted
 * array, and places all smaller (smaller than pivot)
 * to left of pivot and all greater elements to right
 * of pivot
 */
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/**
 * The main function that implements QuickSort
 * arr[] --> Array to be sorted,
 * low  --> Starting index,
 * high  --> Ending index
 */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/**
 * A utility function to swap two elements
 */
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
