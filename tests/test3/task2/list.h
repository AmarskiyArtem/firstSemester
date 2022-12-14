#pragma once

#include <stdbool.h>
#include <stdlib.h>

typedef struct Node Node;

typedef struct List List;

typedef enum ErrorCode {
    ok,
    memoryAllocationError,
    listIsEmpty
} ErrorCode;

List* createList(void);

void deleteList(List* list);

ErrorCode addNode(List* list, char* value);

ErrorCode printList(List* list);

ErrorCode aStringAdder(List* list);

bool tests(void);