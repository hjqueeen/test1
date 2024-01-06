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
    new->next = NULL;

    if (isEmpty(list)) {
        // add list item to the list as first item
        list->first = new;
    } else {
        // add list item to end of the list
        ListItem *current = list->first;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new;
    }

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
    int listSize = size(list);
    if (isEmpty(list) || position < 1 || listSize < position) {
        return NULL;
    }

    int i = 1;
    ListItem *current = list->first;
    while (i < position && current != NULL) {
        current = current->next;
        i++;
    }
    if (current == NULL) {
        return NULL;
    } else {
        return current->ptr;
    }
}

int contains(List *list, void *ptr) {
    assert(list != NULL); // Validation list
    int count = 1;
    ListItem *current = list->first;
    while (current != NULL) {
        if (*((int *) current->ptr) == *((int *) ptr)) {
            printf("List has %dth element\n", count);
            return count;
        } else {
            count++;
            current = current->next;
        }
    }
    printf("List has not this element\n");
    return -1;
}

void *removeItem(List *list, int position) {
    assert(list != NULL); // Validation list
    int listSize = size(list);
    if (isEmpty(list) || position < 1 || listSize < position) {
        return NULL;
    }

    ListItem *prev = NULL;
    ListItem *current = list->first;
    void *data = NULL;
    int i = 1;
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
        printf("%d, ", *((int *) current->ptr));
        current = current->next;
    }
    printf("\n");
}

int testList(List *myList) {
    assert(myList != NULL);
    for (int i = 1; i <= 20; i++) {
        int *data = (int *) malloc(sizeof(int));
        *data = i;
        add(myList, data);
    }
    for (int i = 1; i <= size(myList); i++) {
        void *data = get(myList, i);
        printf("%d, ", *(int *) data);
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
        printf("7 - Contains?\n");
        printf("8 - Fill the list from 1 until 20\n");
        printf("Command:");
        scanf("%d", &selection);

        int position = 0;
        int *data = NULL;
        int *value = (int *) malloc(sizeof(int));

        switch (selection) {
            case 0:
                deleteList(myList);
                free(value);
                return 0;
            case 1:
                printf("Value: ");
                scanf("%d", value);
                add(myList, value);
                break;
            case 2:
                printf("Position: ");
                scanf("%d", &position);
                data = get(myList, position);
                if (data == NULL) {
                    printf("No such value.\n");
                } else {
                    printf("Value: %d\n", *data);
                }
                break;
            case 3:
                printf("Position: ");
                scanf("%d", &position);
                data = removeItem(myList, position);
                if (data == NULL) {
                    printf("No such value.\n");
                } else {
                    printf("Value: %d removed!\n", *data);
                }
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
                printf("Value: ");
                scanf("%d", value);
                contains(myList, value);
                break;
            case 8:
                testList(myList);
                break;
            default:
                printf("Invalid command!\n");
        }
        printf("----------------\n");
    } while (selection);


    return 0;
}