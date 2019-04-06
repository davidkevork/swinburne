#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "SwinGame.h"

#define WIDTH 100
#define HEIGHT 100
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int x(int x, int i) {
    int y = x + i;
    if (y+WIDTH <= WINDOW_WIDTH && y >= 0) {
        return y;
    } else {
        return x;
    }
}

int y(int y, int i) {
    int x = y + i;
    if (x+HEIGHT <= WINDOW_HEIGHT && x >= 0) {
        return x;
    } else {
        return y;
    }
}

int main() {
    open_graphics_window("Star Drawing", WINDOW_WIDTH, WINDOW_HEIGHT);
    load_default_colors(COLOR_WHITE);
    clear_screen(COLOR_WHITE);
    int xo = 350, yo = 250;
    int xn = 0, yn = 0;
    fill_rectangle(COLOR_RED, xo, yo, 100, 100);
    refresh_screen(30);
    do {
        delay(100);
        xn = xo;
        yn = yo;
        if (key_down(VK_LEFT)) xn = x(xn,-10);
        if (key_down(VK_RIGHT)) xn = x(xn,10);
        if (key_down(VK_UP)) yn = y(yn,-10);
        if (key_down(VK_DOWN)) yn = y(yn,10);
        if (xn != xo || yn != yo) {
            clear_screen(COLOR_WHITE);
            fill_rectangle(COLOR_RED, xn, yn, WIDTH, HEIGHT);
            refresh_screen(30);
        }
        xo = xn;
        yo = yn;
    } while (window_close_requested() == false);

    getchar();
}
