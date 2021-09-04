#include <stdlib.h>

#include "snake.h"

queue snake;
int snake_dir = RIGHT;

void init_snake(void)
{
    struct node *nodes[8];
    int i, x, y;

    x = 5;
    y = 5;

    for (i = 0; i < 8; i++) {
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
