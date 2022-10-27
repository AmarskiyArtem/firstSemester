#pragma once

typedef struct SortedList SortedList;

//create a sorted list, return NULL if problems with memory allocation
SortedList* createSortedList();

//add element in sorted list (in right position). return 0 if succesfull, -1 if not
int push(SortedList* list, int value);

//delete element from list, return 0 if succesfull, -1 if not (no such element in list)
int pop(SortedList* list, int value);

//delete all elements
void deleteSortedList(SortedList* list);

//return element with given index, errorCode = 0 if succesfull, -1 if not (no such index) 
int top(SortedList* list, int index, int* errorCode);

//print all elements, return 0 succesfull, -1 if not (list is empty)
int printSortedList(SortedList* list);