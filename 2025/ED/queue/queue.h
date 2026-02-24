//
// Created by gusta on 13/09/2025.
//

#ifndef ED_QUEUE_H
#define ED_QUEUE_H

#define QUEUE_MAXSIZE 5
#define SUCCESS 0
#define QUEUE_EMPTY 1
#define QUEUE_FULL 2

typedef struct {
    int size;
    int node[QUEUE_MAXSIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue *queue);
int isQueueEmpty(const Queue *queue);
int isQueueFull(const Queue *queue);
int enQueue(Queue *queue, int item);
int deQueue(Queue *queue, int *value);
int frontQueue(const Queue *queue, int *value);
int popSearchQueue(Queue *queue,int value);

#endif //ED_QUEUE_H