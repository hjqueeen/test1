#include "myStack.h"
#include <stdio.h>
#include <stdlib.h>

struct Stack* initStack() {
    struct Stack *stack = (struct Stack *) malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}
void push(struct Stack *stack, int data) {
    struct StackItem *temp = (struct StackItem *) malloc(sizeof(struct
            StackItem));
    temp->ptr = stack->top;
    temp->data = data;
    stack->top = temp;
}
int pop(struct Stack *stack) {
    if (stack->top == NULL)
        return -1;
    struct StackItem *temp = stack->top->ptr;
    int popped = stack->top->data;
    free(stack->top);
    stack->top = temp;
    return popped;
}
int top(struct Stack *stack) {
    if (stack->top == NULL)
        return -1;
    return stack->top->data;
}
int isEmpty(struct Stack *stack) {
    return stack->top == NULL;
}
int size(struct Stack *stack) {
    struct StackItem *itemPtr = stack->top;
    int size = 0;
    while (itemPtr != NULL) {
        size++;
        itemPtr = itemPtr->ptr;
    }
    return size;
}
void deleteStack(struct Stack *stack) {
    while (!isEmpty(stack))
        pop(stack);
    free(stack);
}
int stack() {
    struct Stack *stack = initStack();
    int selection;
    do {
        printf("0 - Programm beenden\n");
        printf("1 - Wert hinzufuegen\n");
        printf("2 - Wert ausgeben\n");
        printf("3 - Wert ausgeben und entfernen\n");
        printf("4 - Pruefen, ob der Stapel leer ist\n");
        printf("5 - Groesse auslesen\n");
        printf("Befehl: ");
        scanf("%d", &selection);
        int n = 0;
        switch (selection) {
            case 0:
                deleteStack(stack);
                return 0;
            case 1:
                printf("Wert: ");
                scanf("%d", &n);
                push(stack, n);
                break;
            case 2:
                n = top(stack);
                if (n == -1) {
                    printf("Stapel ist leer.");
                } else {
                    printf("Wert: %d\n", n);
                }
                break;
            case 3:
                n = pop(stack);
                if (n == -1) {
                    printf("Stapel ist leer.");
                } else {
                    printf("Wert: %d\n", n);
                    printf("Letzter Wert wurde entfernt!\n");
                }
                break;
            case 4:
                printf(isEmpty(stack) ? "Stapel ist leer\n" : "Stapel ist nicht leer\n");
                break;
            case 5:
                printf("Groesse: %d\n", size(stack));
                break;
            default:
                printf("Ungueltiger Befehl!\n");
        }
        printf("----------------\n");
    } while (selection);
    return 0;
}