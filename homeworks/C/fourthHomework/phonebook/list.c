#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "list.h"

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
    bool isContinue = true;
    while (true) {
        if (fscanf(file, "%s%s", name, number) == EOF) {
            break;
        };
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

int add(List* list, char* name, char* number) {
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        return -1;
    }
    strcpy(newNode->name, name);
    strcpy(newNode->number, number);
    newNode->next = list->head;
    list->head = newNode;
    return 0;
}

int saveToFile(char* fileName, List* list) {
    FILE* file = fopen(fileName, "w");
    if (file == NULL) {
        return -1;
    }
    Node* currentNode = list->head;
    while (currentNode != NULL) {
        fprintf(file, "%s %s\n", currentNode->name, currentNode->number);
        currentNode = currentNode->next;
    }
    fclose(file);
    return 0;
}

char* findByName(List* list, char* name) {
    Node* currentNode = list->head;
    while (currentNode != NULL) {
        if (strcmp(name, currentNode->name) == 0) {
            return currentNode->number;
        }
        currentNode = currentNode->next;
    }
    return NULL;
}

char* findByNumber(List* list, char* number) {
    Node* currentNode = list->head;
    while (currentNode != NULL) {
        if (strcmp(number, currentNode->number) == 0) {
            return currentNode->name;
        }
        currentNode = currentNode->next;
    }
    return NULL;
}