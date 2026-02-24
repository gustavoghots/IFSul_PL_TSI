//
// Created by gusta on 13/09/2025.
//

#include "queue.h"

#include <stdio.h>

void initQueue(Queue *queue) {
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
}

int isQueueEmpty(const Queue *queue) {
    if (queue->front == queue->rear) {
        return QUEUE_EMPTY;
    }
    return 0;
}

int isQueueFull(const Queue *queue) {
    if (queue->size == QUEUE_MAXSIZE) {
        return QUEUE_FULL;
    }
    return 0;
}

int frontQueue(const Queue *queue, int *value) {
    if (isQueueEmpty(queue)) {
        return QUEUE_EMPTY;
    }
    *value = queue->node[queue->front];
    return SUCCESS;
}

int enQueue(Queue *queue, const int item) {
    if (isQueueFull(queue)) {
        return QUEUE_FULL;
    }
    queue->rear = (queue->rear + 1) % QUEUE_MAXSIZE;
    queue->node[queue->rear] = item;
    queue->size++;
    return SUCCESS;
}

int deQueue(Queue *queue, int *value) {
    if (isQueueEmpty(queue)) {
        return QUEUE_EMPTY;
    }
    queue->front = (queue->front + 1) % QUEUE_MAXSIZE;
    *value = queue->node[queue->front];
    queue->size--;
    return SUCCESS;
}

int popSearchQueue(Queue *queue,int value) {
    int try;
    if (isQueueEmpty(queue)) {
        return QUEUE_EMPTY;
    }
    while (!isQueueEmpty(queue)) {
        deQueue(queue, &try);
        if (try == value) {
            return SUCCESS;
        }
    }
    return QUEUE_EMPTY;
}