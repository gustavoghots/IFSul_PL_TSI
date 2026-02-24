//
// Created by gusta on 09/11/2025.
//

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void queue_init(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

int queue_isEmpty(const Queue *q) {
    if (q->front == NULL)
        return EMPTY;
    return SUCCESS;
}

int queue_size(const Queue *q) {
    return q->size;
}

QueueNode *queue_createNode(const Order order) {
    QueueNode *newNode = malloc(sizeof(QueueNode));
    if (!newNode)
        return NULL;

    newNode->order = order;
    newNode->next = NULL;
    return newNode;
}

int queue_enqueue(Queue *q, const Order order) {
    QueueNode *newNode = queue_createNode(order);
    if (!newNode)
        return MEMORY_FULL;

    if (queue_isEmpty(q)) {
        q->front = newNode;
    } else {
        q->rear->next = newNode;
    }

    q->rear = newNode;
    q->size++;

    return SUCCESS;
}


int queue_dequeue(Queue *q, Order *out) {
    if (queue_isEmpty(q))
        return EMPTY;

    QueueNode *temp = q->front;
    *out = temp->order;
    q->front = temp->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    q->size--;
    return SUCCESS;
}

int queue_front(const Queue *q, Order *out) {
    if (queue_isEmpty(q))
        return EMPTY;

    *out = q->front->order;
    return SUCCESS;
}
