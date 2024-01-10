#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <limits.h>

#define NAME_LENGTH 50

typedef enum {
    RED, ORANGE, YELLOW, GREEN, BLUE
} Color;

typedef struct Human {
    char firstname[NAME_LENGTH];
    char lastname[NAME_LENGTH];
    Color favorite;
} Human;

Stack *initStack() {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    stack->first = NULL;
    return stack;
}

void pushStack(Stack *stack, void *data, int type) {
    assert(stack != NULL);
    Node *new = (Node *) malloc(sizeof(Node));
    if (new == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new->next = NULL;
    new->data = data;
    new->type = type; // type of data

    Node *current = stack->first;
    // find last of stack
    while (current != NULL && current->next != NULL) {
        current = current->next;
    }

    if (current == NULL) // stack is empty
        stack->first = new;
    else // current is second to last from stack.
        current->next = new; // new is last of stack
}

// return 1, if stack is empty
int isStackEmpty(Stack *stack) {
    return stack->first == NULL ? 1 : 0;
}

Stack *popStack(Stack *stack) {
    assert(stack != NULL);
    if (isStackEmpty(stack)) {
        printf("Stack is empty\n");
        return NULL;
    } else {
        // delete first of stack
        Node *temp = stack->first;
        stack->first = temp->next;
        free(temp->data);
        free(temp);
        return stack;
    }
}

void printNode(Node *node, int type) {
    Human person;
    switch (type) {
        case 0: // data is int
            printf("Value: %d", *(int *) node->data);
            break;
        case 1: // data is float
            printf("Value: %.1f", *(float *) node->data);
            break;
        case 2: // data is double
            printf("Value: %.2lf", *(double *) node->data);
            break;
        case 3: // data is Man
            person = *(Human *) node->data;
            printf("Name: %s %s\n", person.firstname, person.lastname);
            printf("Favorite Color: %u", person.favorite);
            break;
        default:
            printf("Unknowned data type\n");
            break;
    }
}

void peekStack(Stack *stack, int type) {
    assert(stack != NULL);
    if (isStackEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    } else {
        printNode(stack->first, type);
    }
}

void printStack(Stack *stack) {
    if (stack != NULL && !isStackEmpty(stack)) {
        Node *current = stack->first;
        while (current != NULL) {
            printNode(current, current->type);
            current = current->next;
        }
    }
}

void searchNode(Stack *stack, void *search, int type) {
    if (stack != NULL && !isStackEmpty(stack)) {
        Node *current = stack->first;
        Human person;
        Human toSearch;
        while (current != NULL) {
            switch (type) {
                case 0: // type is int
                    if (*(int *) search == *((int *) current->data)) {
                        printNode(current, current->type);
                        return;
                    }
                    break;
                case 1: // type is float
                    if (*(float *) search == *((float *) current->data)) {
                        printNode(current, current->type);
                        return;
                    }
                    break;
                case 2: // type is double
                    if (*(double *) search == *((double *) current->data)) {
                        printNode(current, current->type);
                        return;
                    }
                    break;
                case 3:
                    person = *((Human *) current->data);
                    toSearch = *(Human *) search;
                    if (strcmp(toSearch.firstname, person.firstname) == 0 &&
                        strcmp(toSearch.lastname, person.lastname) == 0) {
                        printNode(current, current->type);
                        return;
                    }
                    break;
                default:
                    break;
            }
            current = current->next;
        }
        printf("Value not found.\n");
    }
}

void deleteStack(Stack *stack) {
    if (stack != NULL) {
        while (stack->first != NULL) {
            stack = popStack(stack);
        }
        free(stack);
    }
}

int startStact() {
    Stack *stack = initStack();
    int selection = -1;
    do {
        printf("0 - Exit program\n");
        printf("1 - Add a value\n");
        printf("2 - Get a value by its position (starting from 1)\n");
        printf("3 - Remove a value by its position (starting from 1)\n");
        printf("4 - Check if the stack is empty\n");
        printf("5 - Get the size of the stack\n");
        printf("6 - Print the stack\n");
        printf("7 - Check if a value exists in the stack\n");
        printf("8 - Fill the stack with values from 1 to 20\n");
        printf("9 - Fill the stack with 20 random values\n");
        printf("10 - Sort the stack in ascending order (Bubble Sort)\n");
        printf("11 - Sort the stack in ascending order (Selection Sort)\n");
        printf("12 - Sort the stack in ascending order (Insertion Sort)\n");
        printf("13 - Sort the stack in ascending order (Quick Sort)\n");
        printf("14 - Write the stack in file\n");
        printf("15 - Load the stack from file\n");
        printf("Command: ");
        scanf("%d", &selection);

        int position = 0;
        int type;
        void *value= NULL;
        int *intValue = NULL;
//        float *floatValue = NULL;
//        double *doubleValue = NULL;
//        Human *humanValue = NULL;

        switch (selection) {
            case 0 :
                deleteStack(stack);
                free(value);
//                free(intValue);
//                free(doubleValue);
//                free(floatValue);
//                free(humanValue);
                break;
            case 1:
                printf("Data type: (0: Interger, 1: Float, 2: Double, 3: Human) \n");
                scanf("%d", &type);
                if (type < 0 || type > 3) {
                    printf("Invalid values. Try again.\n");
                    continue;
                }
                printf("Enter Value: \n");
                switch (type) {
                    case 0:

                        value = (int *) malloc(sizeof(int));
                        intValue = (int *) malloc(sizeof(int));
                        scanf("%d", (int *) value);
                        scanf("%d", intValue);
                        pushStack(stack, value, type);
                        pushStack(stack, (void *) intValue, type);


                        break;
                    case 1:
                        value = (float *) malloc(sizeof(float));


                        break;
                    case 2:
                        value = (double *) malloc(sizeof(double));


                        break;
                    case 3:
                        value = (Human *) malloc(sizeof(Human));


                        break;

                }
                pushStack(stack, (void *) value, type);
                break;
            case :
                break;
            case :
                break;
            case :
                break;
            case :
                break;
            case :
                break;
            case :
                break;
            case :
                break;


        }
        printf("----------------\n");
    } while (selection);
    return 0;
}