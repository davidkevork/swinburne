#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "SwinGame.h"

int main()
{
    open_graphics_window("Hello World", 800, 600);
    show_swin_game_splash_screen();
    
    do
    {
        process_events();

        clear_screen_to(ColorWhite);
        draw_framerate_with_simple_font(0,0);

        draw_circle(ColorRed, 150, 100, 100);
        fill_circle(ColorRed, 150, 100, 100);

        draw_rectangle(ColorGreen, 110, 60, 10, 10);
        fill_rectangle(ColorGreen, 110, 60, 10, 10);

        draw_rectangle(ColorBlue, 200, 60, 10, 10);
        fill_rectangle(ColorBlue, 200, 60, 10, 10);

        draw_triangle(ColorMagenta, 140, 100, 160, 100, 150, 70);
        fill_triangle(ColorMagenta, 140, 100, 160, 100, 150, 70);

        draw_ellipse(ColorBlack, 125, 140, 60, 25);
        fill_ellipse(ColorBlack, 125, 140, 60, 25);

        refresh_screen(60);

    } while ( ! window_close_requested() );
    
    return 0;
}
