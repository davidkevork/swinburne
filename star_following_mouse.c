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
    load_default_colors(COLOR_RED);
    clear_screen(COLOR_WHITE);
    int x = 0, y = 0;
    draw_star(COLOR_RED, x, y, 50, 50);
    //fill_rectangle(COLOR_RED, x, y, 50, 50);
    refresh_screen(20);
    do {
        delay(250);
        if(x != mouse_x() || y != mouse_y()) {
            x = mouse_x();
            y = mouse_y();
            clear_screen(COLOR_WHITE);
            draw_star(COLOR_RED, x, y, 50, 50);
            //fill_rectangle(COLOR_RED, x, y, 50, 50);
            refresh_screen(20);
        }
    } while (window_close_requested() == false);

    getchar();
}
