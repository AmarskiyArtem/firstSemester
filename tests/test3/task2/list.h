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

//Create a list, return NULL, if memory allocation error
List* createList(void);

//Delete the list
void deleteList(List* list);

//Add an element to the tail of the list
ErrorCode pushBack(List* list, char* value);

//Print list from head
ErrorCode printList(List* list);

//Adds lines that start with a go to the end of the list
ErrorCode aStringAdder(List* list);

//tests
bool tests(void);