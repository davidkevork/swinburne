#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "SwinGame.h"

void draw_star (color clr, double x, double y, int width, int height) {
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
    open_graphics_window("Star Drawing", 800, 600);
    clear_screen(ColorWhite);
    draw_star(ColorGreen, 100,100, 100, 100);// top left
    draw_star(ColorRed, 600,100, 100, 100);// top right
    draw_star(ColorBlue, 100,400, 100, 100);// bottom left
    draw_star(ColorOrange, 600,400, 100, 100);// bottom right
    refresh_screen(60);
    delay(5000);
    return 0;
}