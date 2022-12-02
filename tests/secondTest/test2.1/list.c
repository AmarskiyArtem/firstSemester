#pragma once
#include "list.h"
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
    struct Node* previous;
} Node;

typedef struct List {
    Node* head;
} List;

List* createList(void) {
    List* list = malloc(sizeof(List));
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
    while (!isEmpty(list)) {
        Node* currentHead = list->head;
        list->head = list->head->next;
        free(currentHead);
    }
}

int push(List* list, int value) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        return -1;
    }
    newNode->value = value;
    newNode->next = list->head;
    newNode->previous = NULL;
    if (!isEmpty(list)) {
        list->head->previous = newNode;
    }
    list->head = newNode;
    return 0;
}

void printList(List* list) {
    Node* node = list->head;
    while (node != NULL) {
        printf("%d ", node->value);
        node = node->next;
    }
}

int listLength(List* list) {
    int length = 0;
    Node* currentNode = list->head;
    while (currentNode != NULL) {
        ++length;
        currentNode = currentNode->next;
    }
    return length;
}

Node* getLastNode(List* list) {
    Node* currentNode = list->head;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    return currentNode;
}

bool isSymmetric(List* list) {
    if (listLength(list) <= 1) {
        return true;
    }
    Node* currentNodeFromHead = list->head;
    Node* currentNodeFromTail = getLastNode(list);
    if (listLength(list) % 2 == 1) {
        while (currentNodeFromHead != currentNodeFromTail) {
            if (currentNodeFromHead->value != currentNodeFromTail->value) {
                return false;
            }
            currentNodeFromHead = currentNodeFromHead->next;
            currentNodeFromTail = currentNodeFromTail->previous;
        }
        return true;
    }
    while (currentNodeFromHead->next != currentNodeFromTail) {
        if (currentNodeFromHead->value != currentNodeFromTail->value) {
            return false;
        }
        currentNodeFromHead = currentNodeFromHead->next;
        currentNodeFromTail = currentNodeFromTail->previous;
    }
    return currentNodeFromHead->value == currentNodeFromTail->value;
}