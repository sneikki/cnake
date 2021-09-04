#include <stdlib.h>

#include "snake.h"

queue snake;
int snake_dir = RIGHT;

void init_snake(void)
{
    struct node *nodes[SNAKE_MIN_LENGTH];
    int i, x, y;

    x = 5;
    y = 5;

    for (i = 0; i < SNAKE_MIN_LENGTH; i++) {
        nodes[i] = (struct node *) malloc(sizeof(struct node));

        nodes[i]->x = x + i;
        nodes[i]->y = y;

        queue_push(&snake, nodes[i]);
    }
}

void update_snake(void)
{
    struct node *tail = queue_pop(&snake);
    struct node *head = snake.last;

    switch (snake_dir) {
        case UP:
            tail->x = head->x;
            tail->y = head->y - 1;
            tail->next = NULL;
            queue_push(&snake, tail);

            break;
        case DOWN:
            tail->x = head->x;
            tail->y = head->y + 1;
            tail->next = NULL;
            queue_push(&snake, tail);

            break;
        case LEFT:
            tail->x = head->x - 1;
            tail->y = head->y;
            tail->next = NULL;
            queue_push(&snake, tail);

            break;
        case RIGHT:
            tail->x = head->x + 1;
            tail->y = head->y;
            tail->next = NULL;
            queue_push(&snake, tail);

            break;
    }
}

void insert_snake_node(int x, int y)
{
    struct node *new = (struct node *) malloc(sizeof(struct node));
    new->x = x;
    new->y = y;

    switch (snake_dir) {
        case UP:
            new->y--;
            break;
        case DOWN:
            new->y++;
            break;
        case LEFT:
            new->x--;
            break;
        case RIGHT:
            new->x++;
            break;
    }

    new->next = NULL;

    queue_push(&snake, new);
}

int snake_has_eaten(int apple_x, int apple_y)
{
    int x, y;

    x = snake.last->x;
    y = snake.last->y;

    return x == apple_x && y == apple_y;
}
