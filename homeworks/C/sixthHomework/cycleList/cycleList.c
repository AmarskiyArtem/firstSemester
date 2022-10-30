#pragma once
#include "cycleList.h"
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct CycleList {
    struct Node* head;
} CycleList;



CycleList* createCycleList(int amountOfWarriors) {
    CycleList* cycleList = malloc(sizeof(Node));
    if (cycleList == NULL) {
        return NULL;
    }
    Node* firstElement = malloc(sizeof(Node));
    if (firstElement == NULL) {
        return NULL;
    }
    firstElement->value = 1;
    firstElement->next = firstElement;
    cycleList->head = firstElement;
    Node* currentNode = cycleList->head;
    for (int i = 2; i <= amountOfWarriors; ++i) {
        Node* temp = malloc(sizeof(Node));
        if (temp == NULL) {
            return NULL;
        }
        temp->value = i;
        temp->next = cycleList->head;
        currentNode->next = temp;
        currentNode = currentNode->next;
    }
    return cycleList;
}

int top(CycleList* list) {
    return list->head->next->next->next->value;
}