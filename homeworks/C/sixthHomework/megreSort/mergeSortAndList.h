#pragma once

typedef struct List List;

int readFromFile(char* fileName, List* list);

List* createList(void);

void deleteList(List* list);

int printList(List* list);

