#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#include "list.h"

#define MAX_SIZE 256

typedef struct Node {
    char* value;
    struct Node* next;
} Node;

typedef struct List {
    int length;
    Node* head;
    Node* tail;
} List;

List* createList(void) {
    List* list = malloc(sizeof(List));
    if (list == NULL) {
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
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
    free(list);
}

ErrorCode pushBack(List* list, char* value) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        return memoryAllocationError;
    }
    list->length++;
    newNode->value = calloc(MAX_SIZE, sizeof(char));
    if (newNode->value == NULL) {
        return memoryAllocationError;
    }
    strcpy(newNode->value, value);
    newNode->next = NULL;
    if (isEmpty(list)) {
        list->head = newNode;
        list->tail = newNode;
        return ok;
    }
    list->tail->next = newNode;
    list->tail = newNode;
    return ok;
}


ErrorCode aStringAdder(List * list) {
    Node* currentNode = list->head;
    int originalListLength = list->length;
    for (int i = 0; i < originalListLength; ++i) {
        if (currentNode->value[0] == 'a') {
            if (pushBack(list, currentNode->value) != ok) {
                return memoryAllocationError;
            }
        }
        currentNode = currentNode->next;
    }
    return ok;
}

ErrorCode printList(List* list) {
    if (isEmpty(list)) {
        return listIsEmpty;
    }
    Node* currentNode = list->head;
    while (currentNode != NULL) {
        printf("%s\n", currentNode->value);
        currentNode = currentNode->next;
    }
    return ok;
}

bool tests(void) {
    List* testList = createList();
    if (testList == NULL) {
        return false;
    }
    if (pushBack(testList, "atf") != ok) {
        deleteList(testList);
        return false;
    }
    if (pushBack(testList, "apple") != ok) {
        deleteList(testList);
        return false;
    }
    if (pushBack(testList, "") != ok) {
        deleteList(testList);
        return false;
    }
    if (pushBack(testList, "green") != ok) {
        deleteList(testList);
        return false;
    }
    if (strcmp(testList->tail->value, "green") != 0 || testList->length != 4 
        || strcmp(testList->head->value, "atf") != 0) {
        deleteList(testList);
        return false;
    }
    if (aStringAdder(testList) != ok) {
        deleteList(testList);
        return false;
    }
    if (strcmp(testList->tail->value, "apple") != 0 || testList->length != 6) {
        deleteList(testList);
        return false;
    }
    if (pushBack(testList, "aNode") != ok) {
        deleteList(testList);
        return false;
    }
    if (aStringAdder(testList) != ok) {
        deleteList(testList);
        return false;
    }
    if (strcmp(testList->tail->value, "aNode") != 0 || testList->length != 12) {
        deleteList(testList);
        return false;
    }
    deleteList(testList);
    return true;
}

