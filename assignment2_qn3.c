#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "SwinGame.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 700

struct sample {
	int value;
	color clr;
};


color get_color(int num);
void fill_array(struct sample array[]);
void draw_bar(struct sample array[]);
void quickSort(int arr[], int low, int high);
void swap(int* a, int* b);
int partition (int arr[], int low, int high);

int main()
{
    // open the window and set colors
	open_graphics_window("Assignment 2 - Q. 3 - Array Rectangles", WINDOW_WIDTH, WINDOW_HEIGHT);
	load_default_colors();
	clear_screen(ColorWhite);

    // srand for random numbers
    srand(time(NULL));
    // initialize pointer and array and then set memory
    struct sample *arrayPtr, array[1];
    arrayPtr = (struct sample*) malloc(800 * sizeof(array[1]));

    // fill the array
    fill_array(arrayPtr);
    // window will re-render only when shouldDraw is set to 0
    int shouldDraw = 1;

    // do while the user didn't close the window
    do {
        // a is left
        // d is right
        // s is refresh

        // when `s` key is clicked quick sort
        if (key_typed(SKEY)) {
            int data[WINDOW_WIDTH-1];
            for (int i = 0; i < WINDOW_WIDTH-1; ++i) {
                data[i] = arrayPtr[i].value;
            }
            quickSort(data, 0, WINDOW_WIDTH - 1);
            for (int j = 0; j < WINDOW_WIDTH-1; ++j) {
                arrayPtr[j].value = data[j];
            }
            shouldDraw = 1;
        } else if (key_typed(RKEY)) {
            // when `r` key is clicked quick sort and inverse the data
            int data[WINDOW_WIDTH-1];
            for (int i = 0; i < WINDOW_WIDTH-1; ++i) {
                data[i] = arrayPtr[i].value;
            }
            quickSort(data, 0, WINDOW_WIDTH - 1);
            int new_data[WINDOW_WIDTH-1];
            for (int j = 0; j < WINDOW_WIDTH-1; ++j) {
                new_data[WINDOW_WIDTH-(j+1)] = data[j-1];
            }
            for (int k = 0; k < WINDOW_WIDTH-1; ++k) {
                arrayPtr[k].value = new_data[k];
            }
            shouldDraw = 1;
        } else if (key_typed(FKEY)) {
            // when `f` key is clicked fill it with new data
            fill_array(arrayPtr);
            shouldDraw = 1;
        }

        // checks is all should re-render
        if (shouldDraw == 1) {
            // clears screen, draws bar and sets shouldDraw to 0
            clear_screen(ColorWhite);
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

/**
 * Returns a random color
 * @param num
 * @return color
 */
color get_color(int num)
{
    float hue = num / (float) WINDOW_HEIGHT;
    return hsbcolor(hue, 0.7, 0.8);
}

/**
 * Fills the array with random numbers and color
 * @param array
 */
void fill_array(struct sample array[])
{
    for (int i = 0; i < WINDOW_WIDTH-1; ++i) {
        array[i].value = rand()%WINDOW_HEIGHT;
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
    for (int i = 0; i < WINDOW_WIDTH-1; ++i) {
        x = rectwidth * i;
        y = WINDOW_HEIGHT - array[i].value;
        fill_rectangle(array[i].clr, x, y, rectwidth, array[i].value);
    }
}


// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
