//#include "myStack.h"
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//
//Stack *initStack() {
//    Stack *stack = (Stack *) malloc(sizeof(Stack));
//    if (stack == NULL) {
//        printf("Memory allocation failed\n");
//        exit(1);
//    }
//    stack->top = NULL;
//    return stack;
//}
//
//void push(Stack *stack, int data) {
//    assert(stack != NULL); // Validate that the 'stack' pointer is not NULL.
//
//    StackItem *new = (StackItem *) malloc(sizeof(StackItem));
//    if (new == NULL) {
//        printf("Memory allocation failed\n");
//        exit(1);
//    }
//    // add new item to stack as first value
//    new->next = stack->top;
//    new->data = data;
//    stack->top = new;
//}
//
//int pop(Stack *stack, int *err) {
//    assert(stack != NULL); // Validate that the 'stack' pointer is not NULL.
//
//    if (stack->top == NULL) {
//        *err = 1;
//        return 0;
//    }
//    *err = 0;
//    StackItem *temp = stack->top->next;
//    int popped = stack->top->data;
//    free(stack->top);
//    stack->top = temp;
//    return popped;
//}
//
//int top(Stack *stack, int *err) {
//    assert(stack != NULL); // Validate that the 'stack' pointer is not NULL.
//
//    if (stack->top == NULL) {
//        *err = 1;
//        return 0;
//    }
//    *err = 0;
//    return stack->top->data;
//}
//
//int isEmpty(Stack *stack) {
//    assert(stack != NULL); // Validate that the 'stack' pointer is not NULL.
//
//    return stack->top == NULL;
//}
//
//int size(Stack *stack) {
//    assert(stack != NULL); // Validate that the 'stack' pointer is not NULL.
//
//    StackItem *current = stack->top;
//    int size = 0;
//    while (current != NULL) {
//        size++;
//        current = current->next;
//    }
//    return size;
//}
//
//void deleteStack(Stack *stack) {
//    assert(stack != NULL); // Validate that the 'stack' pointer is not NULL.
//
//    while (!isEmpty(stack)) {
//        int err;
//        pop(stack, &err);
//    }
//    free(stack);
//}
//
//int main() {
//    Stack *stack = initStack();
//    int selection;
//    do {
//        printf("0 - Exit program\n");
//        printf("1 - Add value\n");
//        printf("2 - Display top value\n");
//        printf("3 - Display and remove top value\n");
//        printf("4 - Check if stack is empty\n");
//        printf("5 - Get stack size\n");
//        printf("Command: ");
//        scanf("%d", &selection);
//        int n = 0, err = 0;
//        switch (selection) {
//            case 0:
//                deleteStack(stack);
//                return 0;
//            case 1:
//                printf("Value: ");
//                scanf("%d", &n);
//                push(stack, n);
//                break;
//            case 2:
//                n = top(stack, &err);
//                if (err) {
//                    printf("Stack is empty.\n");
//                } else {
//                    printf("Value: %d\n", n);
//                }
//                break;
//            case 3:
//                n = pop(stack, &err);
//                if (err) {
//                    printf("Stack is empty.\n");
//                } else {
//                    printf("Value: %d\n", n);
//                    printf("Top value removed!\n");
//                }
//                break;
//            case 4:
//                printf(isEmpty(stack) ? "Stack is empty\n" : "Stack is not empty\n");
//                break;
//            case 5:
//                printf("Size: %d\n", size(stack));
//                break;
//            default:
//                printf("Invalid command!\n");
//        }
//        printf("----------------\n");
//    } while (selection);
//    return 0;
//}