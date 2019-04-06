#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "SwinGame.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int roll_dice();
int random_number(int min, int max);
void draw_button(color clr, const char* name, float x, float y, int  w, int h);
bool button_clicked(int xValue, int yValue, int btnWidth, int btnHeight);
void play_game(int (*dice)[6][6]);
void empty_dice(int (*dice)[6][6]);
void show_results(int (*dice)[6][6], int *sum);
int get_sum(int (*dice)[6][6]);

int main()
{
    open_graphics_window("week6_6.5", WINDOW_WIDTH, WINDOW_HEIGHT);
    load_default_colors();
    clear_screen(COLOR_GREEN);

    srand(time(NULL));

    int dice[6][6], sum = 0;
    empty_dice(&dice);
    play_game(&dice);

    draw_button(COLOR_RED, "Play Game", 300, 50, 120, 30);
    sum = get_sum(&dice);
    show_results(&dice, &sum);
    refresh_screen(60);

    do {
        if (button_clicked(300, 50, 120, 30)) {
            empty_dice(&dice);
            play_game(&dice);

            draw_button(COLOR_RED, "Play Game", 300, 50, 120, 30);
            sum = get_sum(&dice);
            show_results(&dice, &sum);
        }

        // fps set to 60
        refresh_screen(60);
        delay(60);
    } while (!window_close_requested());

    release_all_resources();
    return 0;
}

void show_results(int (*dice)[6][6], int *sum)
{
    char str[6];
    for (int i = 0; i < 6; ++i) {
        sprintf(str, "%i", i+1);
        draw_button(COLOR_GREY, str, 250+i*50, 100, 50, 40);
    }
    for (int j = 0; j < 6; ++j) {
        sprintf(str, "%i", j+1);
        draw_button(COLOR_GREY, str, 200, 140+j*40, 50, 40);
    }
    for (int k = 0; k < 6; ++k) {
        for (int l = 0; l < 6; ++l) {
            sprintf(str, "%i", (*dice)[k][l]);
            draw_button(COLOR_YELLOW, str, 250+l*50, 140+k*40, 50, 40);
        }
    }
    char s[20] = "Sum is ";
    sprintf(str, "%i", *sum);
    strcat(s, str);
    draw_button(COLOR_GREY, s, 560, 240, 120, 40);
    if (*sum >= 6000) {
        draw_button(COLOR_RED, "Player Wins", 300, 400, 120, 30);
    } else {
        draw_button(COLOR_RED, "Player Losses", 300, 400, 120, 30);
    }
}

void play_game(int (*dice)[6][6])
{
    int dice_1, dice_2;
    for (int i = 0; i < 36000; i++) {
        dice_1 = roll_dice();
        dice_2 = roll_dice();
        (*dice)[dice_1][dice_2] += 1;
    }
}

void empty_dice(int (*dice)[6][6])
{
    for (int j = 0; j < 6; ++j) {
        for (int i = 0; i < 6; ++i) {
            (*dice)[i][j] = 0;
        }
    }
}

int get_sum(int (*dice)[6][6])
{
    return (*dice)[0][0]
            + (*dice)[1][1]
            + (*dice)[2][2]
            + (*dice)[3][3]
            + (*dice)[4][4]
            + (*dice)[5][5];
}

void draw_button(color clr, const char* name, float x, float y, int  w, int h) {
    fill_rectangle(clr, x, y, w, h);
    draw_text(name, COLOR_BLACK, "arial.ttf", 15, x+10, y+10);
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

int roll_dice()
{
    return random_number(0, 5);
}

int random_number(int min, int max)
{
    return rand()%(max-min+1)+min;
}
