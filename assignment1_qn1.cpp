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
	draw_text(name, ColorYellow, "arial.ttf", 15, x, y+10);
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

void draw_green_bus() {
    fill_rectangle(ColorGreen, 50, 50+50, 200, 100);
    fill_circle(ColorBlue, 100, 150+50, 20);
    fill_circle(ColorBlue, 200, 150+50, 20);
}

void draw_red_bus() {
    fill_rectangle(ColorRed, 50+500, 50+50, 200, 100);
    fill_circle(ColorBlue, 100+500, 150+50, 20);
    fill_circle(ColorBlue, 200+500, 150+50, 20);
}

void draw_face() {
    fill_circle(ColorRed, 150+250, 100+50, 100);
    fill_rectangle(ColorGreen, 110+250, 60+50, 10, 10);
    fill_rectangle(ColorBlue, 200+250, 60+50, 10, 10);
    fill_triangle(ColorMagenta, 140+250, 100+50, 160+250, 100+50, 150+250, 70+50);
    fill_ellipse(ColorBlack, 125+250, 140+50, 60, 25);
}

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

void drawAllTheButtons() {
	draw_button(COLOR_RED, "Button1", 0, 0, 50, 50);
	draw_button(COLOR_RED, "Button2", WINDOW_WIDTH-50, 0, 50, 50);
}


int main() {
	open_graphics_window("Assignment 1 - Q. 1", WINDOW_WIDTH, WINDOW_HEIGHT);
	load_default_colors();
	clear_screen(COLOR_BLACK);
	drawAllTheButtons();
	int WhatShouldIDo = 0;
	int deg = 0;
	/**
	 * 0 is nothing
	 * 1 is button 1
	 * 2 is button 2
	 */
	refresh_screen(30);
	do {
		if (button_clicked(0, 0, 50, 50) == true) WhatShouldIDo = 1;
		if (button_clicked(WINDOW_WIDTH-50, 0, 50, 50) == true) WhatShouldIDo = 2;
		switch(WhatShouldIDo) {
			case 0:
				break;
			case 1:
				WhatShouldIDo = 0;
				clear_screen(COLOR_BLACK);
				drawAllTheButtons();
				draw_red_bus();
				draw_face();
				draw_green_bus();
				refresh_screen(30);
				break;
			case 2:
				WhatShouldIDo = 3;
				deg = 0;
				clear_screen(COLOR_BLACK);
				drawAllTheButtons();
				draw_star(ColorGreen, 100,100, 100, 100);// top left
			    draw_star(ColorRed, 600,100, 100, 100);// top right
			    draw_star(ColorBlue, 100,400, 100, 100);// bottom left
			    draw_star(ColorOrange, 600,400, 100, 100);// bottom right
			    draw_tyre(250, 150, deg);
			    refresh_screen(30);
				break;
			case 3:
				deg++;
				draw_tyre(250, 150, deg);
				refresh_screen(30);
				break;
			default:
				WhatShouldIDo = 0;
				break;
		}
		delay(50);
	} while (window_close_requested() == false);
	release_all_resources();
	return 0;
}
