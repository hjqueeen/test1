#include "myPointerList.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

// Entwickeln Sie eine Liste, die void Pointer in einer bestimmten Reihenfolge speichert,
// so dass sie eine beliebige Datenstruktur speichern kann. Die Liste sollte mindestens
// folgende Funktionen haben.
// a. Add – Fügt ein Element am Ende der Liste hinzu.
// b. Get – Gibt ein Element an einer bestimmten Position zurück.
// c. Contains – Überprüft, ob ein Element in der Liste gespeichert ist und gibt die
//        Position zurück.
// d. Remove – Entfernt das Element an der angegebenen Position.
// e. IsEmpty – Überprüft, ob die Liste leer ist.
// f. Size – Überprüft, wie viele Elemente in der Liste gespeichert sind.

List *initList() {
    List *list = (List *) malloc(sizeof(List));
    if (list == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    list->first = NULL;
    return list;
}

void add(List *list, void *ptr) {
    assert(list != NULL); // Validation list
    ListItem *new = (ListItem *) malloc(sizeof(ListItem));
    if (new == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new->ptr = ptr;
    new->next = list->first;
    list->first = new;
}

int size(List *list) {
    assert(list != NULL); // Validation list
    size_t listSize = 0;
    ListItem *current = list->first;
    while (current != NULL) {
        listSize++;
        current = current->next;
    }
    return listSize;
}

void *get(List *list, int position) {
    assert(list != NULL); // Validation list
    int i = 0;
    ListItem *current = list->first;
    while (i < position && current != NULL) {
        current = current->next;
        i++;
    }
    return current->ptr;
}

List *contains(List *list, void *ptr) {
    return NULL;
}

void *removeItem(List *list, int position) {
    assert(list != NULL); // Validation list
    int i = 1;

    ListItem *prev = NULL;
    ListItem *current = list->first;
    void *data = NULL;
    // find list item with position
    while (i < position && current != NULL) {
        prev = current;
        current = current->next;
        i++;
    }
    if (i == 1) {
        list->first = current->next;
    } else {
        prev->next = current->next;
    }
    data = current->ptr;
    free(current);
    return data;
}

int isEmpty(List *list) {
    assert(list != NULL); // Validation list
    if (list->first == NULL) {
        // list is empty
        return 1;
    } else {
        // list is not empty
        return 0;
    }
}

void deleteList(List *list) {
    assert(list != NULL); // Validation list
    ListItem *current = list->first;
    ListItem *temp = NULL;
    while (current != NULL) {
        temp = current;
        free(current->ptr);
        current = current->next;
        free(temp);
    }
    free(list);
}

void printList(List *list) {
    assert(list != NULL); // Validation list
    ListItem *current = list->first;

    while (current != NULL) {
        printf("%f", *((double *) current->ptr));
        current = current->next;

    }
}

int testList(List *myList) {
    assert(myList != NULL);

    for (int i = 20; i > 0; i--) {
        int *data = (int *) malloc(sizeof(int));
        *data = i;
        add(myList, data);
    }

    for (int i = 0; i < size(myList); i++) {
        void *data = get(myList, i);
        printf("%d\n", *(int *) data);
    }


    return 0;
}


int pointerList() {
    List *myList = initList();
    int selection;
    do {
        printf("0 - Exit program\n");
        printf("1 - Add value\n");
        printf("2 - Get value via it's position\n");
        printf("3 - Remove value via it's posiotion\n");
        printf("4 - Check if list is empty\n");
        printf("5 - Get list size\n");
        printf("6 - Print list\n");
        printf("7 - Fill the list until 20\n");
        printf("Command: ");
        scanf("%d", &selection);
        int err = 0;
        int position = 0;
        int *data = NULL;
        int *n = (int *) malloc(sizeof(int));
        switch (selection) {
            case 0:
                deleteList(myList);
                return 0;
            case 1:
                printf("Value: ");
                scanf("%d", &n);
                add(myList, n);
                break;
            case 2:
                printf("Position: ");
                scanf("%d", &position);
                data = get(myList, position);
                printf("Value: %d\n", *data);
                break;
            case 3:
                printf("Position: ");
                scanf("%d", &position);
                data = removeItem(myList, position);
                printf("Value: %d removed!\n", *data);
                break;
            case 4:
                printf(isEmpty(myList) ? "List is empty\n" : "List is not empty\n");
                break;
            case 5:
                printf("Size: %d\n", size(myList));
                break;
            case 6:
                printList(myList);
                break;
            case 7:
                testList(myList);
                break;
            default:
                printf("Invalid command!\n");
        }
        printf("----------------\n");
    } while (selection);


    return 0;
}