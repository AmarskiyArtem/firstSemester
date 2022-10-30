#pragma once
#include <stdbool.h>

typedef struct CycleList CycleList;

//return filled cycle list (1..n), return NULL if problems with memory allocation
CycleList* createCycleList(int amountOfWarriors);

//delete m-th element, return the position from which the next countdown
int deleteElement(CycleList* list, int position, int m);

bool isAlone(CycleList* list);

int top(CycleList* list);