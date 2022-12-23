#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "list.h"

typedef struct Node {
    int frequency;
    char* value;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
    int length;
} List;

List* createList(void) {
    List* list = calloc(1, sizeof(List));
    return list;
}

bool isEmpty(List* list) {
    return list->head == NULL;
}

Node* findNodeWithSameValue(Node* node, char* value) {
    while (node != NULL) {
        if (strcmp(value, node->value) == 0) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

ErrorCode push(List* list, char* value) {
    if (isEmpty(list)) {
        Node* newNode = malloc(sizeof(Node));
        if (newNode == NULL) {
            return memoryAllocationError;
        }
        char* newValue = calloc(strlen(value) + 1, sizeof(char));
        if (newValue == NULL) {
            return memoryAllocationError;
        }
        strcpy(newValue, value);
        newNode->value = newValue;
        newNode->next = NULL;
        newNode->frequency = 1;
        list->head = newNode;
        ++(list->length);
        return ok;
    }
    Node* node = findNodeWithSameValue(list->head, value);
    if (node == NULL) {
        Node* newNode = malloc(sizeof(Node));
        if (newNode == NULL) {
            return memoryAllocationError;
        }
        char* newValue = calloc(strlen(value) + 1, sizeof(char));
        if (newValue == NULL) {
            return memoryAllocationError;
        }
        strcpy(newValue, value);
        newNode->value = newValue;
        newNode->next = list->head;
        newNode->frequency = 1;
        list->head = newNode;
        ++(list->length);
        return ok;
    }
    ++(node->frequency);
    return ok;
}

void printList(List* list) {
    Node* node = list->head;
    while (node != NULL) {
        printf("%s occurs %d times\n", node->value, node->frequency);
        node = node->next;
    }
}

void deleteList(List* list) {
    while (!isEmpty(list)) {
        Node* currentHead = list->head;
        list->head = list->head->next;
        free(currentHead->value);
        free(currentHead);
    }
    free(list);
}

int getLength(List* list) {
    return list->length;
}

char* getValueFromHead(List* list) {
    if (isEmpty(list)) {
        return NULL;
    }
    return list->head->value;
}

void deleteHead(List* list) {
    if (isEmpty(list)) {
        return;
    }
    Node* newHead = list->head->next;
    free(list->head->value);
    free(list->head);
    list->head = newHead;
}