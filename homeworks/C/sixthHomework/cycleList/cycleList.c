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

Position deleteElement(CycleList* list, Position position, int m, int* exitCode) {
    *exitCode = -1;
   /* Node* currentNode = list->head;
    Node* previousNode = list->head;
    while (currentNode->number != position) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }*/
    Node* currentNode = position;
    //Node* previousNode = position;
    for (int i = 0; i < m - 2 ; ++i) {
        //previousNode = currentNode;
        currentNode = currentNode->next;
    }
    position = currentNode->next;
    if (currentNode->next == currentNode) {
        *exitCode = 0;
        return position;
    }
    Node* temp = currentNode->next;
    currentNode->next = currentNode->next->next;
    if (list->head == temp) {
        list->head = temp->next;
        free(temp);
        return currentNode->next;
        /*Node* temp = list->head;
        while (temp->next != currentNode->next) {
            temp = temp->next;
        }
        temp->next = list->head;*/
    }
    //previousNode->next = currentNode->next;
    free(temp);
    return currentNode->next;
}

int getValue(Position position) {
    return position->number;
}

Position getFirstPosition(CycleList* list) {
    return list->head;
}

void deleteList(CycleList** list) {
    free((*list)->head);
    free((*list));
    list = NULL;
}

void printList(CycleList* list) {
    Node* node = list->head;
    do {
        printf("%d ", node->number);
        node = node->next;
    } while (node != list->head);
    printf("\n");
}