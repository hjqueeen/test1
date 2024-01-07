//
// Referenz
// bubble sort list: https://dream-and-develop.tistory.com/61
// selection, insertion sort list: https://eunjinii.tistory.com/80
//

#ifndef TESTVORBEREITEN_MYPOINTERLIST_H
#define TESTVORBEREITEN_MYPOINTERLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "sort.h"

typedef struct ListItem {
    void *data;
    struct ListItem *next;
} ListItem;

typedef struct List {
    ListItem *first;
} List;

List *initList();

void add(List *list, void *ptr);

size_t sizeList(List *list);

void *get(List *list, int position);

int contains(List *list, void *ptr);

void *removeItem(List *list, int position);

int isEmpty(List *list);

void deleteList(List *list);

void printList(List *list);

int testList(List *myList);

int pointerList();

#endif //TESTVORBEREITEN_MYPOINTERLIST_H
