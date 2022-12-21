#pragma once

#include <stdbool.h>

typedef struct CycleList CycleList;

typedef struct Node Node;

typedef Node* Position;

//return filled cycle list (1..n), return NULL if problems with memory allocation
CycleList* createCycleList(int amountOfWarriors);

//delete m-th element, return the position from which the next countdown 
Position deleteElement(CycleList* list, Position position, int m, int* exitCode);

Position getFirstPosition(CycleList* list);

int getValue(Position position);

void deleteList(CycleList** list);

void printList(CycleList* list);