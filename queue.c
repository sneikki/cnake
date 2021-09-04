#include "queue.h"

void queue_push(queue *queue, struct node *node)
{
    if (!queue->first) {
        queue->first = node;
        queue->size = 1;
    } else {
        queue->last->next = node;
        queue->size++;
    }

    queue->last = node;
}

struct node *queue_pop(queue *queue)
{
    if (!queue->first) {
        return NULL;
    }

    struct node *ret = queue->first;

    if (queue->first->next) {
        queue->first = queue->first->next;
        queue->size--;
    } else {
        queue->first = NULL;
        queue->last = NULL;
        queue->size = 0;
    }

    return ret;
}

size_t queue_size(queue *queue)
{
    return queue->size;
}

int queue_empty(queue *queue) {
    return queue->size == 0;
}
