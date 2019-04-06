#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <cstdlib>
#include <math.h>
#include "SwinGame.h"

#define WIDTH 100
#define HEIGHT 100
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define TYRE "tyre.png"

// get random color
color random_colors(int r) {
	color C[4] = {COLOR_RED, COLOR_BLUE, COLOR_YELLOW, COLOR_GREEN};
	return C[r];
}

// draw the star
void draw_star(color clr, double x, double y, int width, int height) {
    double x2=x+width;
    double y2=y+height;
    double left_x=x-width;
    double mid_y=y+height/2;
    double mid_x=x+width/2;
    double right_x=x2+width;
    double top_y=y-height;
    double bottom_y=y2+height;
    fill_triangle(clr, x, y, x2, y, mid_x, top_y);
    fill_triangle(clr, x, y, x, y2, left_x, mid_y);
    fill_triangle(clr, x2, y, x2, y2, right_x, mid_y);
    fill_triangle(clr, x, y2, x2, y2, mid_x, bottom_y);
    fill_rectangle(clr, x, y, width, height);
}

int main() {
	open_graphics_window("Assignment 1 - Q. 2", WINDOW_WIDTH, WINDOW_HEIGHT);
	load_default_colors();
	clear_screen(COLOR_WHITE);
	int n = 1, p;
	int x=50, y=50; // x and y axis where the star drawing will start

	srand(time(NULL));
	// start the magic of drawing stars
	while (n <= 10) {
		p = 1;
		while(p <= n) {
			// random_colors(rand()%4) is used to get a random color
			draw_star(random_colors(rand()%4), x+p*40, y+n*40, 10, 10); // draw star
			p++; // update x position
		}
		n++; // update y position
	}
	refresh_screen(30);
	// wait for the user to close the app
	do {
		delay(50);
	} while (window_close_requested() == false);
	release_all_resources();
	return 0;
}
