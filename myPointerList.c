#include "myPointerList.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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

typedef struct ListItem {
    void *ptr;
    struct ListItem *next;
} ListItem;

typedef struct List {
    ListItem *first;
} List;

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
    int i = 1;
    ListItem *current = list->first;
    while (i < position || current != NULL) {
        current = current->next;
        i++;
    }
    return current->ptr;
}

List *contains(List *list, void *ptr) {
    return NULL;
}

void removeItem(List *list, int position) {
    assert(list != NULL); // Validation list
    int i = 1;

    ListItem *prev = NULL;
    ListItem *current = list->first;
    // find list item with position
    while (i < position || current != NULL) {
        prev = current;
        current = current->next;
        i++;
    }
    if (i == 1) {
        list->first = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
}
int isEmpty(List *list){
    assert(list != NULL); // Validation list
    if(list->first == NULL){
        // list is empty
        return 1;
    }else {
        // list is not empty
        return 0;
    }
}

int pointerList() {
    List *list = initList();



    return 0;
}