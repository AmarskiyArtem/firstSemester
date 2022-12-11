#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#include "list.h"

#define MAX_SIZE 256

typedef struct Node {
    char* name;
    char* number;
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

ErrorCode addNode(List* list, char* name, char* number) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        return memoryAllocationError;
    }
    list->length++;
    newNode->name = calloc(MAX_SIZE, sizeof(char));
    if (newNode->name == NULL) {
        return memoryAllocationError;
    }
    newNode->number = calloc(MAX_SIZE, sizeof(char));
    if (newNode->number == NULL) {
        return memoryAllocationError;
    }
    strcpy(newNode->name, name);
    strcpy(newNode->number, number);
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

char* getNameFromHead(List* list) {
    if (isEmpty(list)) {
        return NULL;
    }
    return list->head->name;
}

char* getNumberFromHead(List* list) {
    if (isEmpty(list)) {
        return NULL;
    }
    return list->head->number;
}

int listLength(List* list) {
    return list->length;
}

void deleteHead(List* list) {
    if (isEmpty(list)) {
        return;
    }
    list->length--;
    Node* newHead = list->head->next;
    free(list->head->name);
    free(list->head->number);
    free(list->head);
    list->head = newHead;
}

ErrorCode readFromFile(char* fileName, List* list) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        return fileMissing;
    }
    char name[MAX_SIZE] = { 0 };
    char number[MAX_SIZE] = { 0 };
    bool isContinue = true;
    while (true) {
        if (fscanf_s(file, "%s%s", name, MAX_SIZE, number, MAX_SIZE) == EOF) {
            break;
        }
        if (addNode(list, &name[0], &number[0]) != ok) {
            fclose(file);
            return memoryAllocationError;
        }
    }
    fclose(file);
    return ok;
}

ErrorCode printList(List* list) {
    if (isEmpty(list)) {
        return listIsEmpty;
    }
    Node* currentNode = list->head;
    while (currentNode != NULL) {
        printf("%s %s\n", currentNode->name, currentNode->number);
        currentNode = currentNode->next;
    }
    return ok;
}