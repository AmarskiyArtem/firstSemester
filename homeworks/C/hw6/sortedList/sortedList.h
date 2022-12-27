#pragma once

typedef struct SortedList SortedList;

typedef enum ErrorCode {
    ok,
    memoryAllocationError,
    listIsEmpty,
    elementMissing
} ErrorCode;

//create a sorted list, return NULL if problems with memory allocation
SortedList* createSortedList();

//add element in sorted list (in right position). return 0 if succesfull, -1 if not
ErrorCode push(SortedList* list, int value);

//delete element from list, return 0 if succesfull, -1 if not (no such element in list)
ErrorCode deleteValue(SortedList* list, int value);

//delete all elements
void deleteSortedList(SortedList** list);

//print all elements, return 0 succesfull, -1 if not (list is empty)
ErrorCode printSortedList(SortedList* list);

//tests
bool tests(void);