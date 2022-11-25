#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include "mergeSort.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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
    Node* head = list->head;
    while (!isEmpty(list)) {
        list->head = list->head->next;
        free(head);
    }
}



int readFromFile(char* fileName, List* list) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        return -1;
    }
    char name[MAX_SIZE] = { 0 };
    char number[MAX_SIZE] = { 0 };
    while (!feof(file)) {
        fscanf(file, "%s", name);
        fscanf(file, "%s", number);
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