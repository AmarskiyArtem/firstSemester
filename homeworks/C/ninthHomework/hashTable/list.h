#pragma once
#include <stdbool.h>

typedef struct List List;

typedef enum ErrorCode {
    ok,
    memoryAllocationError
} ErrorCode;

List* createList(void);

void deleteList(List* list);

ErrorCode push(List* list, char* value);

void printList(List* list);

int getLength(List* list);

bool isEmpty(List* list);

char* getValueFromHead(List* list);

void deleteHead(List* list);