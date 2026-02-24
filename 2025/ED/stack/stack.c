//
// Created by gusta on 12/09/2025.
//

#include "stack.h"

#include <stdio.h>

void initStack(Stack *stack) {
    stack->top = -1;
}

int isStackEmpty(const Stack stack) {
    if (stack.top == -1) {
        return STACK_EMPTY;
    }
    return 0;
}

int isStackFull(const Stack stack) {
    if (stack.top==MAX_NODES-1) {
        return STACK_FULL;
    }
    return 0;
}

int pushStack(Stack *stack, const int value) {
    if (isStackFull(*stack)) {
       return STACK_FULL;
    }
    stack->top++;
    stack->node[stack->top] = value;
    return SUCCESS;
}

int popStack(Stack *stack, int *value) {
    if (isStackEmpty(*stack)) {
        return STACK_EMPTY;
    }
    *value = stack->node[stack->top];
    stack->top--;
    return  SUCCESS;
}

int peekStack(Stack stack, int *value) {
    if (isStackEmpty(stack)) {
        return STACK_EMPTY;
    }
    *value = stack.node[stack.top];
    return SUCCESS;
}

int searchStack(const Stack stack,const int value) {
    for (int i = 0; i < stack.top; i++) {
        if (stack.node[i] == value) {
            return SUCCESS;
        }
    }
    return NOT_FOUND;
}

void printStack(Stack stack) {
    if (isStackEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack (top -> bottom):\n");
    for (int i = stack.top; i >= 0; i--) {
        printf("%d\n", stack.node[i]);
    }
}