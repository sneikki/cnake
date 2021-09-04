#include <stdlib.h>
#include <ncurses.h>

#include "graphics.h"

int apple_x, apple_y;

void generate_apple(int arena_width, int arena_height)
{
    apple_x = (rand() % arena_width) + 1;
    apple_y = (rand() % arena_height) + 1;
}
