#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>

typedef struct {
    struct node *first;
    struct node *last;
    size_t size;
} queue;

struct node {
    struct node *next;

    int x;
    int y;
};

void queue_push(queue *queue, struct node *node);
struct node *queue_pop(queue *queue);
size_t queue_size(queue *queue);
int queue_empty(queue *queue);

#endif
