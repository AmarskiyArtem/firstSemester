#pragma once
#include <stdbool.h>

typedef struct List List;

//возвращает указатель на пустой список, NULL, если проблемы с выделением памяти
List* createList(void);

//удаляет список
void deleteList(List* list);

//добавляет элемент в голову, возвращает 0, если успешно, -1 - в противном случае (проблемы с выделением памяти)
int push(List* list, int value);

//выводит список на экран
void printList(List* list);

//проверяет список на симметричность 
bool isSymmetric(List* list);