#pragma once
#include "sortedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct SortedList {
    Node* head;
} SortedList;

SortedList* createSortedList(void) {
    SortedList* sortedList = malloc(sizeof(Node));
    if (sortedList == NULL) {
        return NULL;
    }
    sortedList->head = NULL;
    return sortedList;
}

bool isEmpty(SortedList* list) {
    return list->head == NULL;
}

//int push(SortedList* list, int value) {
//    Node* temp = malloc(sizeof(Node));
//    if (temp == NULL) {
//        return -1;
//    }
//    if (isEmpty(list)) {
//        temp->value = value;
//        temp->next = list->head;
//    }
//}
