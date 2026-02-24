//
// Created by gusta on 13/10/2025.
//

#include "stack.h"
#include <stdlib.h>

void stack_init(Stack *s) {
    s->top = NULL;
    s->size = 0;
}

int stack_isEmpty(const Stack *s) {
    return s->top == NULL;
}

int stack_size(const Stack *s) {
    return s->size;
}

StackNode *stack_createNode(const Order order) {
    StackNode *newNode = malloc(sizeof(StackNode));
    if (!newNode)
        return NULL;

    newNode->order = order;
    newNode->next = NULL;
    return newNode;
}

int stack_push(Stack *s, const Order order) {
    StackNode *newNode = stack_createNode(order);
    if (!newNode)
        return MEMORY_FULL;

    newNode->next = s->top;
    s->top = newNode;
    s->size++;

    return SUCCESS;
}

int stack_pop(Stack *s, Order *out) {
    if (stack_isEmpty(s))
        return EMPTY;

    StackNode *removed = s->top;
    *out = removed->order;

    s->top = removed->next;
    free(removed);
    s->size--;

    return SUCCESS;
}

int stack_top(const Stack *s, Order *out) {
    if (stack_isEmpty(s))
        return EMPTY;

    *out = s->top->order;
    return SUCCESS;
}
