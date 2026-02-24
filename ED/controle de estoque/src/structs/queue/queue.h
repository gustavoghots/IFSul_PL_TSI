#ifndef QUEUE_H
#define QUEUE_H

#include "../structs/util.h"

void queue_init(Queue* q);

int queue_isEmpty(const Queue* q);

int queue_size(const Queue* q);

QueueNode* queue_createNode(Order order);

int queue_enqueue(Queue* q, Order order);

int queue_dequeue(Queue* q, Order* out);

int queue_front(const Queue* q, Order* out);

#endif
