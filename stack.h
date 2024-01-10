

#ifndef TESTVORBEREITEN_STACK_H
#define TESTVORBEREITEN_STACK_H

typedef struct Node{
    void *data;
    struct Node *next;
    int type; // 0: int, 1: float, 2: double, 3: Man
}Node;

typedef struct Stack{
    Node *first;
}Stack;

int isStackEmpty(Stack *stack);
#endif //TESTVORBEREITEN_STACK_H
