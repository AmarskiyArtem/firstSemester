#include <stdlib.h>
#include <stdio.h>

#include "cycleList.h"

typedef struct Node {
    int number;
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
    firstElement->number = 1;
    firstElement->next = firstElement;
    cycleList->head = firstElement;
    Node* currentNode = cycleList->head;
    for (int i = 2; i <= amountOfWarriors; ++i) {
        Node* temp = malloc(sizeof(Node));
        if (temp == NULL) {
            return NULL;
        }
        temp->number = i;
        temp->next = cycleList->head;
        currentNode->next = temp;
        currentNode = currentNode->next;
    }
    return cycleList;
}

int deleteElement(CycleList* list, int position, int m, int* exitCode) {
    *exitCode = -1;
    Node* currentNode = list->head;
    Node* previousNode = list->head;
    while (currentNode->number != position) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    for (int i = 1; i < m; ++i) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    position = currentNode->next->number;
    if (currentNode->next == previousNode) {
        *exitCode = 0;
        free(currentNode);
        free(previousNode);
        return position;
    }
    if (list->head == currentNode) {
        list->head = currentNode->next;
        Node* temp = list->head;
        while (temp->next != currentNode) {
            temp = temp->next;
        }
        temp->next = list->head;
    }
    previousNode->next = currentNode->next;
    free(currentNode);
    return position;
}
