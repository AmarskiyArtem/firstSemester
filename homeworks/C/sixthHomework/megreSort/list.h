#pragma once

#include <stdbool.h>
#include <stdlib.h>

typedef struct Node Node;

typedef struct List List;

typedef enum SortBy {
    name,
    number
} SortBy;

typedef enum ErrorCode {
    ok,
    fileMissing,
    memoryAllocationError,
    listIsEmpty
} ErrorCode;

List* createList(void);

void deleteList(List* list);

ErrorCode addNode(List* list, char* name, char* number);

char* getNameFromHead(List* list);

char* getNumberFromHead(List* list);

int listLength(List* list);

void deleteHead(List* list);

ErrorCode readFromFile(char* fileName, List* list);

