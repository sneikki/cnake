#include <stdlib.h>
#include <ncurses.h>

#include "game.h"
#include "graphics.h"
#include "apple.h"
#include "snake.h"

#define FPS 5
#define INPUT_RATE 60

static double cur;
static int speed = FPS;
static char text_buffer[32];
static int score;
static int state = RUNNING;

int run(void)
{
    timeout(1000.0 / INPUT_RATE);

    generate_apple(ARENA_WIDTH, ARENA_HEIGHT);
    init_snake();

    while (true) {
        if (process() == QUIT) {
            return QUIT;
        }
    }

    struct node *p;

    do {
        p = queue_pop(&snake);
        free(p);
    } while(p);
}

int process(void)
{
    switch (input()) {
        case QUIT:
            return QUIT;
        case RESTART:
            break;
        case PAUSE:
            state = state == PAUSE ? RUNNING : PAUSE;
            break;
    }

    update();

    return RUNNING;
}

int input(void)
{
    int ch = getch();

    switch (ch) {
        case 'q':
            return QUIT;
        case 'r':
            return RESTART;
        case 'p':
            return PAUSE;
        case KEY_UP:
            if (snake_dir != DOWN)
                snake_dir = UP;
            break;
        case KEY_DOWN:
            if (snake_dir != UP)
                snake_dir = DOWN;
            break;
        case KEY_LEFT:
            if (snake_dir != RIGHT)
                snake_dir = LEFT;
            break;
        case KEY_RIGHT:
            if (snake_dir != LEFT)
                snake_dir = RIGHT;
            break;
    }

    return RUNNING;
}

void update(void)
{
    if (state == PAUSE) {
        return;
    }
    
    
    cur += 1000.0 / INPUT_RATE;
    if (cur >= 1.0 / speed * 1000) {
        cur = 0;

        update_snake();

        erase();
        draw();
        refresh();
    }
}

void draw(void)
{
    draw_arena(ARENA_WIDTH, ARENA_HEIGHT);

    /* print score */
    sprintf(text_buffer, "\n\n  Score: %d", score);
    draw_text(text_buffer);
    draw_apple(apple_x, apple_y);
    draw_snake(&snake);
}
