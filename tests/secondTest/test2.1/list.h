#pragma once
#include <stdbool.h>

typedef struct List List;

//return empty list, NULL, if problems with memory allocation
List* createList(void);

//delete the list
void deleteList(List* list);

//add element to the head. return 0 if successfully, -1 if not (problems with memory allocation)
int push(List* list, int value);

//outputs the list to the console
void printList(List* list);

//checks the list for symmetry
bool isSymmetric(List* list);