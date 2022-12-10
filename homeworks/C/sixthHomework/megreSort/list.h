#pragma once

#include <stdbool.h>
#include <stdlib.h>

typedef struct Node Node;

typedef struct List List;

typedef enum SortBy {
    byName,
    byPhone
} SortBy;

typedef enum ErrorCode {
    ok,
    fileMissing,
    memoryAllocationError,
    listIsEmpty
} ErrorCode;

List* createList(void);

void deleteList(List* list);

ErrorCode readFromFile(char* fileName, List* list);

ErrorCode printList(List* list);

Node* getFirstNode(List* list);
