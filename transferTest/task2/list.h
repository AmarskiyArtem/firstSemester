#pragma once

#include <stdbool.h>
#include <stdlib.h>


typedef struct List List;

typedef enum ErrorCode {
    ok,
    memoryAllocationError,
    listIsEmpty
} ErrorCode;

// Create a list, return NULL, if memory allocation error
List* createList(void);

// Delete the list
void deleteList(List* list);

// Add an element to the tail of the list
ErrorCode push(List* list, int value);

// Print list from head
ErrorCode printList(List* list);

// Delete all odd elements
void deleteOdd(List* list);

// Tests
bool tests(void);
