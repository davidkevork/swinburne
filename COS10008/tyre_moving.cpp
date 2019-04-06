#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "SwinGame.h"

#define WIDTH 100
#define HEIGHT 100
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define TYRE "tyre.png"

void draw_button(color clr, const char* name, float x, float y, int  w, int h) {
	fill_rectangle(clr, x, y, w, h);
	draw_text(name, ColorYellow, "arial.ttf", 15, x+10, y+10);
}

bool button_clicked(int xValue, int yValue, int btnWidth, int btnHeight) {
	float rightValue, bottomValue;
	rightValue = xValue + btnWidth;
	bottomValue = yValue + btnHeight;
	if (mouse_clicked(LEFT_BUTTON)) {
		if ((mouse_x() >= xValue) && (mouse_x() <= rightValue) && (mouse_y() >= yValue) && (mouse_y() <= bottomValue)) {
			return true;
		}
	}
	return false;
}

void draw_tyre(int x, int y, float tyre_angle) {
	draw_bitmap_named_with_opts_byval(TYRE, x, y, option_rotate_bmp_angle(tyre_angle));
}

void drawAllTheButtons(const char* name) {
	draw_button(COLOR_RED, name, 150, 30, 100, 30);
	draw_button(COLOR_RED, "Reverse", 50, 90, 100, 30);
	draw_button(COLOR_RED, "Drive", 250, 90, 100, 30);
}

int main() {
	open_graphics_window("Tyre Moving", WINDOW_WIDTH, WINDOW_HEIGHT);
	load_default_colors();
	clear_screen(COLOR_BLACK);
	int start = 0;
	drawAllTheButtons("Start");
	int WhatShouldIDo = 0;
	float deg = 0;
	/**
	 * 0 is nothing
	 * 1 is start/stop
	 * 2 is drive
	 * 3 is reverse
	 */
	refresh_screen(30);
	do {
		if (button_clicked(150, 30, 100, 30) == true) WhatShouldIDo = 1;
		if (button_clicked(50, 90, 100, 30) == true) WhatShouldIDo = 3;
		if (button_clicked(250, 90, 100, 30) == true) WhatShouldIDo = 2;
		switch(WhatShouldIDo) {
			case 0:
				break;
			case 1:
				if (start == 1) {
					clear_screen(COLOR_BLACK);
					drawAllTheButtons("Start");
					start = 0;
				} else if (start == 0) {
					clear_screen(COLOR_BLACK);
					drawAllTheButtons("Stop");
					draw_tyre(70, 150, deg);
					start = 1;
				}
				WhatShouldIDo = 0;
				break;
			case 2:
				deg++;
				draw_tyre(70, 150, deg);
				break;
			case 3:
				deg--;
				draw_tyre(70, 150, deg);
				break;
			default:
				break;
		}
		refresh_screen(30);
		delay(100);
	} while (window_close_requested() == false);
	release_all_resources();
	return 0;
}
