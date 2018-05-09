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

int main() {
	open_graphics_window("Assignment 2 - Q. 3 - Array Rectangles", WINDOW_WIDTH, WINDOW_HEIGHT);
	load_default_colors();
	clear_screen(ColorWhite);

    srand(time(NULL));
    struct sample *arrayPtr, array[1];
    arrayPtr = (struct sample*) malloc(800 * sizeof(array[1]));

    do {
        clear_screen(ColorWhite);
        fill_array(arrayPtr);
        draw_bar(arrayPtr);
        refresh_screen(60);
		delay(2000);
	} while (!window_close_requested());

	free(arrayPtr);
	release_all_resources();
	return 0;
}

color get_color(int num) {
    float hue = num / (float) WINDOW_HEIGHT;
    return hsbcolor(hue, 0.7, 0.8);
}

void fill_array(struct sample array[]) {
    for (int i = 0; i < WINDOW_WIDTH-1; ++i) {
        array[i].value = rand()%WINDOW_HEIGHT;
        array[i].clr = get_color(array[i].value);
    }
}

void draw_bar(struct sample array[]) {
    float x, y, rectwidth = 1;
    for (int i = 0; i < WINDOW_WIDTH-1; ++i) {
        x = rectwidth * i;
        y = WINDOW_HEIGHT - array[i].value;
        fill_rectangle(array[i].clr, x, y, rectwidth, array[i].value);
    }
}
