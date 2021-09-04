#ifndef SNAKE_H
#define SNAKE_H

#include "queue.h"

#define MIN_LENGTH 3

enum direction {
    UP, DOWN,
    LEFT, RIGHT
};

extern queue snake;
extern int snake_dir;

void init_snake(void);
void update_snake(void);

#endif
