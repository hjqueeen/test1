//
// Created by 518597 on 06.01.2024.
//

#ifndef TESTVORBEREITEN_MYPOINTERLIST_H
#define TESTVORBEREITEN_MYPOINTERLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct ListItem {
    void *ptr;
    struct ListItem *next;
} ListItem;

typedef struct List {
    ListItem *first;
} List;

List *initList();

void add(List *list, void *ptr);

int size(List *list);

void *get(List *list, int position);

List *contains(List *list, void *ptr);

void *removeItem(List *list, int position);

int isEmpty(List *list);

void deleteList(List *list);

void printList(List *list);

int testList(List *myList);

int pointerList();

#endif //TESTVORBEREITEN_MYPOINTERLIST_H
