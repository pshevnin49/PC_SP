
#ifndef _QUEUE_H
#define _QUEUE_H

#include "vector.h"

typedef struct _queue {
  vector_t *queue;
  int begin, end;
} queue_t;

queue_t *queue_create();

int queue_init(queue_t *q);

void in_queue(queue_t *q, int x);

int from_queue(queue_t *q);

void queue_destroy(queue_t **poor);

#endif