#ifndef SNAKE_H
#define SNAKE_H

#include "queue.h"

#define SNAKE_MIN_LENGTH 3

enum direction {
    UP, DOWN,
    LEFT, RIGHT
};

extern queue snake;
extern int snake_dir;

void init_snake(void);
void update_snake(void);
void insert_snake_node(int x, int y);
int snake_has_eaten(int apple_x, int apple_y);

#endif
