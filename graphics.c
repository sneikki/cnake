#include <ncurses.h>
#include <time.h>
#include <stdio.h>

#include "graphics.h"
#include "constants.h"

static void init_colors(void);

void init_graphics(void)
{
    initscr();
    keypad(stdscr, true);
    cbreak();
    noecho();
    nodelay(stdscr, true);
    curs_set(0);
    init_colors();
    clear();
}

int check_win_size(void)
{
    int wx, wy;

    wx = getmaxx(stdscr);
    wy = getmaxy(stdscr);

    return !(wx < MIN_WINDOW_WIDTH || wy < MIN_WINDOW_HEIGHT);
}

void draw_arena(int width, int height)
{
    attron(COLOR_PAIR(WALL_COLOR));

    int i, j;

    for (i = 0; i < width + 2; i++) {
        addstr("\u2585");
    }
    addstr("\n");

    for (j = 0; j < height; j++) {
        addstr("\u2588");

        for (i = 0; i < width; i++) {
            addch(' ');
        }

        addstr("\u2588\n");
    }

    addstr("\u2588");
    for (i = 0; i < width; i++) {
        addstr("\u2585");
    }
    addstr("\u2588");

    attroff(COLOR_PAIR(WALL_COLOR));
}

void draw_apple(int x, int y)
{
    attron(COLOR_PAIR(APPLE_COLOR));
    move(y, x);
    addch('o');
    attroff(COLOR_PAIR(APPLE_COLOR));
}

void draw_snake(queue *snake)
{
    attron(COLOR_PAIR(SNAKE_COLOR));
    
    struct node *p = snake->first;

    for (; p; p = p->next) {
        int x = p->x;
        int y = p->y;

        move(y, x);
        addch('*');
    }

    attroff(COLOR_PAIR(SNAKE_COLOR));
}

void draw_text(char *text)
{
    addstr(text);
}

void close(void)
{
    endwin();
}

static void init_colors(void)
{
    start_color();
    init_pair(WALL_COLOR, WALL_COLOR, COLOR_BLACK);
    init_pair(SNAKE_COLOR, SNAKE_COLOR, COLOR_BLACK);
    init_pair(APPLE_COLOR, APPLE_COLOR, COLOR_BLACK);
    init_pair(5, COLOR_WHITE, COLOR_RED);
}

void color_on(int color)
{
    attron(COLOR_PAIR(color));
}

void color_off(int color)
{
    attroff(COLOR_PAIR(WALL_COLOR));
}
