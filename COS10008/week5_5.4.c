#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "SwinGame.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

#define BATMAN "batman.png"
#define SPIDERMAN "spiderman.png"
#define SUPERMAN "superman.png"
#define ARROWHIT "Arrow+Hit+1.wav"

int main()
{
    open_graphics_window("week5 5.4", WINDOW_WIDTH, WINDOW_HEIGHT);
    load_default_colors();
    clear_screen(COLOR_WHITE);

    bitmap _BATMAN = load_bitmap_named(BATMAN, BATMAN);
    bitmap _SPIDERMAN = load_bitmap_named(SPIDERMAN, SPIDERMAN);
    bitmap _SUPERMAN = load_bitmap_named(SUPERMAN, SUPERMAN);
    sound_effect _ARROWHIT = load_sound_effect_named(ARROWHIT, ARROWHIT);

    srand(time(NULL));

    float player_x, player_y;
    float enemy1_x, enemy1_y;
    float enemy2_x, enemy2_y;
    int player_speed = 5;

    player_x = WINDOW_WIDTH / 2;
    player_y = WINDOW_HEIGHT / 2;

    enemy1_x = rand() % WINDOW_WIDTH;
    enemy1_y = rand() % WINDOW_HEIGHT;

    enemy2_x = rand() % WINDOW_WIDTH;
    enemy2_y = rand() % WINDOW_HEIGHT;

    refresh_screen(60);

    do {
        process_events();
        clear_screen(COLOR_WHITE);

        draw_bitmap_named(SPIDERMAN, player_x, player_y);
        draw_bitmap_named(BATMAN, enemy1_x, enemy1_y);
        draw_bitmap_named(SUPERMAN, enemy2_x, enemy2_y);

        enemy1_x += 3;
        enemy1_y += 2;

        enemy2_x += 3;
        enemy2_y += 2;

        if (key_down(UP_KEY) || key_down(WKEY)) { player_y -= player_speed; }
        if (key_down(DOWN_KEY) || key_down(SKEY)) { player_y += player_speed; }
        if (key_down(LEFT_KEY) || key_down(AKEY)) { player_x -= player_speed; }
        if (key_down(RIGHT_KEY) || key_down(DKEY)) { player_x += player_speed; }

        if (player_x > WINDOW_WIDTH
            || player_y > WINDOW_HEIGHT
            || player_x < 0
            || player_y < 0)
        {
            player_x = WINDOW_WIDTH / 2;
            player_y = WINDOW_HEIGHT / 2;
            play_sound_effect(ARROWHIT);
            delay(10);
        }

        if (enemy1_x > WINDOW_WIDTH) { enemy1_x = 0; }
        if (enemy1_y > WINDOW_HEIGHT) { enemy1_y = 0; }

        if (enemy2_x > WINDOW_WIDTH) { enemy2_x = 0; }
        if (enemy2_y > WINDOW_HEIGHT) { enemy2_y = 0; }

        if (bitmap_collision(_SPIDERMAN, player_x, player_y, _BATMAN, enemy1_x, enemy1_y)
            || bitmap_collision(_SPIDERMAN, player_x, player_y, _SUPERMAN, enemy2_x, enemy2_y)) {
            player_x = WINDOW_WIDTH / 2;
            player_y = WINDOW_HEIGHT / 2;
            play_sound_effect(ARROWHIT);
            delay(10);
        }

        refresh_screen(60);
        delay(60);
    } while (!window_close_requested());

    release_all_resources();
    return 0;
}
