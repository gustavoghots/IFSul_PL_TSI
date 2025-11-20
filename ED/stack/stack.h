//
// Created by gusta on 12/09/2025.
//

#ifndef ED_STACK_H
#define ED_STACK_H

// Status codes
#define SUCCESS 0
#define STACK_EMPTY 1
#define STACK_FULL 2
#define NOT_FOUND 3

// Max elements
#define MAX_NODES 5

// Stack structure
typedef struct {
    int node[MAX_NODES];
    int top;
} Stack;

// Operations
void initStack(Stack *stack);
int isStackEmpty(Stack stack);
int isStackFull(Stack stack);
int pushStack(Stack *stack, int value);
int popStack(Stack *stack, int *value);
int peekStack(Stack stack, int *value);
void printStack(Stack stack);
int searchStack(Stack stack, int value);

#endif // ED_STACK_H
