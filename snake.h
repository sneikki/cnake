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

int init_snake(void);
void empty_snake(void);
void update_snake(void);
void turn_snake(int direction, int opposite, int *dir_changed);
int grow_snake(void);
void insert_snake_node(struct node *new);
int snake_has_eaten(int apple_x, int apple_y);
int check_snake_location(int arena_Width, int arena_height);
int check_snake_collision(void);

#endif
