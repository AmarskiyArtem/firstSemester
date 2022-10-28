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
    temp->value = value;
    if (isEmpty(list)) {
        temp->next = list->head;
        list->head = temp;
        return 0;
    }
    Node* currentNode = list->head;
    Node* previousNode = list->head;
    while (currentNode->next != NULL && value > currentNode->value) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    if (currentNode->next == NULL && value > currentNode->value) {
        temp->next = NULL;
        currentNode->next = temp;
        return 0;
    }
    if (currentNode->next == NULL) {
        temp->next = currentNode;
        previousNode->next = temp;
        return 0;
    }
    if (currentNode == previousNode) {
        temp->next = currentNode;
        list->head = temp;
        return 0;
    }
    temp->next = currentNode;
    previousNode->next = temp;
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

int pop(SortedList* list, int value) {
    if (isEmpty(list)) {
        return -1;
    }
    Node* currentNode = list->head;
    Node* previousNode = list->head;
    while (currentNode->next != NULL && value != currentNode->value) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    if (value != currentNode->value) {
        return -1;
    }
    if (currentNode == previousNode) {
        list->head = currentNode->next;
        free(currentNode);
        return 0;
    }
    previousNode->next = currentNode->next;
    free(currentNode);
    return 0;
}