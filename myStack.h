#ifndef TESTVORBEREITEN_MYSTACK_H
#define TESTVORBEREITEN_MYSTACK_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct StackItem {
    int data;
    struct StackItem *next;
} StackItem;

typedef struct Stack {
    StackItem *top;
} Stack;

 Stack *initStack();

void push( Stack *stack, int data);

int pop( Stack *stack, int *err);

int top( Stack *stack, int *err);

int isEmptyStack( Stack *stack);

int sizeStack(Stack *stack);

void deleteStack( Stack *stack);

int startStack();

#endif //TESTVORBEREITEN_MYSTACK_H
