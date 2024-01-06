#ifndef TESTVORBEREITEN_MYSTACK_H
#define TESTVORBEREITEN_MYSTACK_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Stack {
    struct StackItem *top;
};
struct StackItem {
    int data;
    struct StackItem *next;
};

struct Stack* initStack();
void push(struct Stack *stack, int data);
int pop(struct Stack *stack, int *err) ;
int top(struct Stack *stack, int *err) ;
int isEmpty(struct Stack *stack);
int size(struct Stack *stack) ;
void deleteStack(struct Stack *stack);
int stack();

#endif //TESTVORBEREITEN_MYSTACK_H
