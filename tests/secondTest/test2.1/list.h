#pragma once
#include <stdbool.h>

typedef struct List List;

List* createList(void);

void deleteList(List* list);

int push(List* list, int value);

void printList(List* list);

int listLength(List* list);

bool isSymmetric(List* list);