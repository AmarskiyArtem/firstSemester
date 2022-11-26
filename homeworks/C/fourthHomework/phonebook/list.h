#pragma once

typedef struct List List;

int readFromFile(char* fileName, List* list);

List* createList(void);

void deleteList(List* list);

int printList(List* list);

int add(List* list, char* name, char* number);

int saveToFile(char* fileName, List* list);

char* findByName(List* list, char* name);

char* findByNumber(List* list, char* number);