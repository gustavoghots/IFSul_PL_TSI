#ifndef ED_STACK_H
#define ED_STACK_H

#include "../util.h"

void stack_init(Stack *s);

int stack_isEmpty(const Stack *s);

int stack_size(const Stack *s);

StackNode *stack_createNode(Order order);

int stack_push(Stack *s, Order order);

int stack_pop(Stack *s, Order *out);

int stack_top(const Stack *s, Order *out);

#endif //ED_STACK_H
