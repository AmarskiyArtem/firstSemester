#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "mergeSortAndList.h"

#define MAX_SIZE 256

typedef struct Node {
    char name[MAX_SIZE];
    char number[MAX_SIZE];
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
} List;

List* createList(void) {
    List* list = malloc(sizeof(list));
    if (list == NULL) {
        return NULL;
    }
    list->head = NULL;
    return list;
}

bool isEmpty(List* list) {
    return list->head == NULL;
}

int compare(Node* firstElement, Node* secondElement, int key) {
    if (key == 1) { 
        return strcmp(firstElement->name, secondElement->name);
    }
    return strcmp(firstElement->number, secondElement->number);
}

void deleteList(List* list) {
    while (!isEmpty(list)) {
        Node* currentHead = list->head;
        list->head = list->head->next;
        free(currentHead);
    }
}

int readFromFile(char* fileName, List* list) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        return -1;
    }
    char name[MAX_SIZE] = { 0 };
    char number[MAX_SIZE] = { 0 };
    while (true) {
        if (fscanf(file, "%s", name) == EOF) {
            break;
        }
        if (fscanf(file, "%s", number) == EOF) {
            break;
        }
        Node* newNode = malloc(sizeof(Node));
        if (newNode == NULL) {
            return -1;
        }
        strcpy(newNode->name, name);
        strcpy(newNode->number, number);
        newNode->next = list->head;
        list->head = newNode;
    }
    fclose(file);
    return 0;
}

int printList(List* list) {
    if (isEmpty(list)) {
        return -1;
    }
    Node* node = list->head;
    while (node != NULL) {
        printf("%s %s\n", node->name, node->number);
        node = node->next;
    }
    return 0;
}

