//
// Referenz
// bubble sort list: https://dream-and-develop.tistory.com/61
// selection, insertion sort list: https://eunjinii.tistory.com/80
// quick sort list: https://visu4l.tistory.com/entry/Quick-Sort-linked-list%EB%A5%BC-%ED%80%B5%EC%A0%95%EB%A0%AC%EB%A1%9C-%EC%A0%95%EB%A0%AC%ED%95%98%EA%B8%B0
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

ListItem *getTail(ListItem *cur);
void moveNode(ListItem **destRef, ListItem **sourceRef);
#endif //TESTVORBEREITEN_MYPOINTERLIST_H
