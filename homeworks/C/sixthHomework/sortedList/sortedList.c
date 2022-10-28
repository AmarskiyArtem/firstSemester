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

int push(SortedList* list, int value) {
    Node* temp = malloc(sizeof(Node));
    if (temp == NULL) {
        return -1;
    }
    if (isEmpty(list)) {
        temp->value = value;
        temp->next = list->head;
        list->head = temp;
        return 0;
    }
    Node* currentNode = list->head;
    while (currentNode->next != NULL && value > currentNode->value) {
        currentNode = currentNode->next;
    }
    if (currentNode->next == NULL && value > currentNode->value) {
        temp->value = value;
        temp->next = currentNode->next;
        currentNode->next = temp;
        return 0;
    }
    if (currentNode->next == NULL) {
        temp->value = value;
        temp->next = currentNode;
        list->head = temp;
        return 0;
    }
    temp->value = value;
    temp->next = currentNode->next;
    currentNode->next = temp;
    return 0;
}

int printSortedList(SortedList* list) {
    if (isEmpty(list)) {
        return -1;
    }
    Node* currentNode = list->head;
    do {
        printf("%d\n", currentNode->value);
        currentNode = currentNode->next;
    } while (currentNode != NULL);
    return 0;
}