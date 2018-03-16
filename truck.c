#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "SwinGame.h"

void draw_green_bus();
void draw_red_bus();

int main()
{
    open_graphics_window("Hello World", 800, 600);
    show_swin_game_splash_screen();
    
    do
    {
        process_events();
        
        clear_screen_to(ColorWhite);
        draw_framerate_with_simple_font(0,0);
        draw_green_bus();
        refresh_screen(60);
        delay(5000);
        
        clear_screen_to(ColorWhite);
        draw_red_bus();
        refresh_screen(60);
        delay(5000);
        return 0;

    } while ( ! window_close_requested() );
    
    return 0;
}

void draw_green_bus() {
    draw_rectangle(ColorGreen, 50, 50, 200, 100);
    fill_rectangle(ColorGreen, 50, 50, 200, 100);
    draw_circle(ColorBlack, 100, 150, 20);
    fill_circle(ColorBlack, 100, 150, 20);
    draw_circle(ColorBlack, 200, 150, 20);
    fill_circle(ColorBlack, 200, 150, 20);
}

void draw_red_bus() {
    draw_rectangle(ColorRed, 50, 50, 200, 100);
    fill_rectangle(ColorRed, 50, 50, 200, 100);
    draw_circle(ColorBlack, 100, 150, 20);
    fill_circle(ColorBlack, 100, 150, 20);
    draw_circle(ColorBlack, 200, 150, 20);
    fill_circle(ColorBlack, 200, 150, 20);
}