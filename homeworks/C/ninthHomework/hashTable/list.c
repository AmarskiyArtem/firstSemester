#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Node {
    int frequency;
    char* value;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
} List;

List* createList(void) {
    List* list = malloc(sizeof(Node));
    if (list == NULL) {
        return NULL;
    }
    list->head = NULL;
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

int push(List* list, char* value) {
    if (isEmpty(list)) {
        Node* newNode = malloc(sizeof(Node));
        if (newNode == NULL) {
            return -1;
        }
        char* newValue = calloc(strlen(value) + 1, sizeof(char));
        if (newValue == NULL) {
            return -1;
        }
        strcpy(newValue, value);
        newNode->value = newValue;
        newNode->next = NULL;
        newNode->frequency = 1;
        list->head = newNode;
        return 0;
    }
    Node* node = findNodeWithSameValue(list->head, value);
    if (node == NULL) {
        Node* newNode = malloc(sizeof(Node));
        if (newNode == NULL) {
            return -1;
        }
        char* newValue = calloc(strlen(value) + 1, sizeof(char));
        if (newValue == NULL) {
            return -1;
        }
        strcpy(newValue, value);
        newNode->value = newValue;
        newNode->next = list->head;
        newNode->frequency = 1;
        list->head = newNode;
        return 0;
    }
    ++(node->frequency);
    return 0;
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
}