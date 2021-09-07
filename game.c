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
static int prev_state;
static int dir_changed;
static int grow_snake_next;

int run(void)
{
    timeout(1000.0 / INPUT_RATE);

    generate_apple(ARENA_WIDTH, ARENA_HEIGHT);
    if (!init_snake()) {
        return QUIT;
    }

    while (true) {
        if (process() == QUIT) {
            return QUIT;
        }
    }

    struct node *p;

    empty_snake();
}

int process(void)
{
    switch (input()) {
        case QUIT:
            return QUIT;
        case RESTART:
            generate_apple(ARENA_WIDTH, ARENA_HEIGHT);
            score = 0;
            speed = FPS;

            empty_snake();
            init_snake();

            state = RUNNING;
            break;
        case PAUSE:
            state = state == PAUSE ? RUNNING : PAUSE;
            break;
    }

    if (!update()) {
        return QUIT;
    }

    return RUNNING;
}

int input(void)
{
    int ch = getch();

    switch (ch) {
        case QUIT_KEY:
            return QUIT;
        case RESTART_KEY:
            return RESTART;
        case PAUSE_KEY:
            return state == GAME_OVER ? GAME_OVER : PAUSE;
        case UP_KEY:
            turn_snake(UP, DOWN, &dir_changed);
            break;
        case DOWN_KEY:
            turn_snake(DOWN, UP, &dir_changed);
            break;
        case LEFT_KEY:
            turn_snake(LEFT, RIGHT, &dir_changed);
            break;
        case RIGHT_KEY:
            turn_snake(RIGHT, LEFT, &dir_changed);
            break;
    }

    return RUNNING;
}

int update(void)
{ 
    if (!check_win_size()) {

        if (state != INTERRUPT) {
            prev_state = state;
            state = INTERRUPT;
        }
    } else {
        if (state == INTERRUPT) {
            state = prev_state;
        }
    }

    cur += 1000.0 / INPUT_RATE;
    if (cur >= 1.0 / speed * 1000) {
        cur = 0;

        dir_changed = 0;

        if (!(state == PAUSE || state == GAME_OVER || state == INTERRUPT)) {
            if (grow_snake_next) {
                grow_snake_next = 0;
                if (!grow_snake()) {
                    return 0;
                }
            } else {
                update_snake();
            }

            if (snake_has_eaten(apple_x, apple_y)) {
                grow_snake_next = 1;

                generate_apple(ARENA_WIDTH, ARENA_HEIGHT);

                if (++score % 5 == 0) {
                    speed++;
                }
            }

            if (check_snake_location(ARENA_WIDTH, ARENA_HEIGHT)
                || check_snake_collision()) {
                state = GAME_OVER;
            }
        }

        erase();
        draw();
        refresh();
    }

    return 1;
}

void draw(void)
{
    draw_arena(ARENA_WIDTH, ARENA_HEIGHT);

    sprintf(text_buffer, "\n\n  Score: %d", score);
    draw_text(text_buffer);

    draw_text("\n\n  r - restart\n  q - quit");

    if (state == GAME_OVER) {
        color_on(5);
        move(ARENA_HEIGHT / 2 + 1, ARENA_WIDTH / 2 - 4);
        draw_text(" GAME OVER ");
        color_off(5);
    } else if (state == PAUSE) {
        move(ARENA_HEIGHT / 2 + 1, ARENA_WIDTH / 2 - 3);
        draw_text("PAUSED");
    } else if (state == INTERRUPT) {
        move(ARENA_HEIGHT / 2 + 1, ARENA_WIDTH / 2 - 6);
        draw_text("WIN TOO SMALL");
    }

    draw_apple(apple_x, apple_y);
    draw_snake(&snake);
}
