#include <stdio.h>

#include "list.h"

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
} List;

List* createList(void) {
    return calloc(1, sizeof(List));
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

ErrorCode push(List* list, int value) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        return memoryAllocationError;
    }
    newNode->value = value;
    newNode->next = list->head;
    list->head = newNode;
    return ok;
}

ErrorCode printList(List* list) {
    if (isEmpty(list)) {
        return listIsEmpty;
    }
    Node* currentNode = list->head;
    while (currentNode != NULL) {
        printf("%d ", currentNode->value);
        currentNode = currentNode->next;
    }
    return ok;
}


void deleteOdd(List* list) {
    if (list->head->value % 2 != 0) {
        Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
    Node* currentNode = list->head;
    Node* previousNode = currentNode;
    while (currentNode != NULL) {
        if (currentNode->value % 2 != 0) {
            previousNode->next = currentNode->next;
            free(currentNode);
            currentNode = previousNode->next;
            continue;
        }
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
}

bool tests(void) {
    List* testList = createList();
    if (testList == NULL) {
        return false;
    }
    if (push(testList, 13) != ok) {
        deleteList(testList);
        return false;
    }
    if (push(testList, 45) != ok) {
        deleteList(testList);
        return false;
    }
    if (push(testList, 7) != ok) {
        deleteList(testList);
        return false;
    }
    if (push(testList, 10) != ok) {
        deleteList(testList);
        return false;
    }
    if (push(testList, 20) != ok) {
        deleteList(testList);
        return false;
    }
    if (push(testList, 15) != ok) {
        deleteList(testList);
        return false;
    }
    deleteOdd(testList);
    if (testList->head->value != 20 || testList->head->next->value != 10 || testList->head->next->next != NULL) {
        deleteList(testList);
        return false;
    }
    deleteList(testList);
    return true;
}