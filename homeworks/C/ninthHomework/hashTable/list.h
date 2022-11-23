#pragma once
#include <stdbool.h>

typedef struct List List;

List* createList(void);

void deleteList(List* list);

int push(List* list, char* value);

void printList(List* list);