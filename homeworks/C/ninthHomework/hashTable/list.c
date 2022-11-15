#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "list.h"
#include <stdlib.h>
#include <string.h>

typedef struct Node {
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

int push(List* list, char* value) {
    Node* node = malloc(sizeof(Node));
    if (node == NULL) {
        return -1;
    }
    char* newValue = calloc(strlen(value) + 1, sizeof(char));
    if (newValue == NULL) {
        return -1;
    }
    strcpy(newValue, value);
    node->value = newValue;
    if (isEmpty(list)) {
        node->next = NULL;
        list->head = node;
        return 0;
    }
    node->next = list->head;
    list->head = node;
    return 0;
}

char* top(List* list) {
    return list->head->value;
}



void deleteList(List* list) {
    while (!isEmpty(list)) {
        Node* currentHead = list->head;
        list->head = list->head->next;
        free(currentHead->value);
        free(currentHead);
    }
}