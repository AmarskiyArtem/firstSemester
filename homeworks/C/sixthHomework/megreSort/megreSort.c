#pragma once
#include "mergeSort.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 256

typedef struct Node {
    char name[MAX_SIZE];
    char number[MAX_SIZE];
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
} List;

List* createList(void) {
    List* list = malloc(sizeof(list));
    if (list == NULL) {
        return NULL;
    }
    list->head = NULL;
    return list;
}

bool isEmpty(List* list) {
    return list->head == NULL;
}

void deleteList(List* list) {
    Node* head = list->head;
    while (!isEmpty(list)) {
        list->head = list->head->next;
        free(head);
    }
}

