#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "sortedList.h"

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

ErrorCode push(SortedList* list, int value) {
    Node* temp = malloc(sizeof(Node));
    if (temp == NULL) {
        return memoryAllocationError;
    }
    temp->value = value;
    if (isEmpty(list)) {
        temp->next = NULL;
        list->head = temp;
        return ok;
    }
    Node* currentNode = list->head;
    Node* previousNode = list->head;
    while (currentNode->next != NULL && value > currentNode->value) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    if (currentNode == previousNode) {
        temp->next = currentNode;
        list->head = temp;
        return ok;
    }
    if (currentNode->next == NULL && value > currentNode->value) {
        temp->next = NULL;
        currentNode->next = temp;
        return ok;
    }
    if (currentNode->next == NULL) {
        temp->next = currentNode;
        previousNode->next = temp;
        return ok;
    }
    temp->next = currentNode;
    previousNode->next = temp;
    return ok;
}

ErrorCode printSortedList(SortedList* list) {
    if (isEmpty(list)) {
        return listIsEmpty;
    }
    Node* currentNode = list->head;
    do {
        printf("%d\n", currentNode->value);
        currentNode = currentNode->next;
    } while (currentNode != NULL);
    return ok;
}

ErrorCode pop(SortedList* list, int value) {
    if (isEmpty(list)) {
        return listIsEmpty;
    }
    Node* currentNode = list->head;
    Node* previousNode = list->head;
    while (currentNode->next != NULL && value != currentNode->value) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    if (value != currentNode->value) {
        return elementMissing;
    }
    if (currentNode == previousNode) {
        list->head = currentNode->next;
        free(currentNode);
        return ok;
    }
    previousNode->next = currentNode->next;
    free(currentNode);
    return ok;
}

void deleteSortedList(SortedList* list) {
    while (list->head != NULL) {
        Node* head = list->head;
        list->head = list->head->next;
        free(head);
    }
    free(list);
}

bool tests(void) {
    SortedList* list = createSortedList();
    if (list == NULL) {
        return false;
    }
    if (push(list, 5) != ok) {
        deleteSortedList(list);
        return false;
    }
    if (list->head->value != 5) {
        deleteSortedList(list);
        return false;
    }
    if (push(list, 1) != ok) {
        deleteSortedList(list);
        return false;
    }
    if (list->head->value != 1 || list->head->next->value != 5) {
        deleteSortedList(list);
        return false;
    }
    if (push(list, 3) != ok) {
        deleteSortedList(list);
        return false;
    }
    if (list->head->next->value != 3) {
        deleteSortedList(list);
        return false;
    }
    if (pop(list, 3) != ok || pop(list, 8) != elementMissing) {
        deleteSortedList(list);
        return false;
    }
    if (list->head->value != 1 || list->head->next->value != 5 || list->head->next->next != NULL) {
        deleteSortedList(list);
        return false;
    }
    deleteSortedList(list);
    return true;
}