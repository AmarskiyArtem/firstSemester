#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

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
    List* list = malloc(sizeof(List));
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
    free(list);
}

ErrorCode readFromFile(char* fileName, List* list) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        return fileMissing;
    }
    char name[MAX_SIZE] = { '\0' };
    char number[MAX_SIZE] = { '\0' };
    while (true) {
        if (fscanf(file, "%s", name) == EOF) {
            break;
        }
        if (fscanf(file, "%s", number) == EOF) {
            break;
        }
        Node* newNode = malloc(sizeof(Node));
        if (newNode == NULL) {
            return memoryAllocationError;
        }
        strcpy(newNode->name, name);
        strcpy(newNode->number, number);
        newNode->next = list->head;
        list->head = newNode;
    }
    fclose(file);
    return ok;
}

ErrorCode printList(List* list) {
    if (isEmpty(list)) {
        return listIsEmpty;
    }
    Node* node = list->head;
    while (node != NULL) {
        printf("%s %s\n", node->name, node->number);
        node = node->next;
    }
    return ok;
}

Node* getFirstNode(List* list) {
    return list->head;
}

Node* getNextNode(Node* node) {

}