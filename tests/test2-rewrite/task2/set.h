#pragma once
#include <stdbool.h>

typedef struct Set Set;

//Создает "множество" сетов
Set* createSet();

//"Присоединияет" сеты 
void unionSet(Set* set, int firstValue, int secondValue);

//Создает сет
void makeSet(Set* set, int value);

//Проверят, являются ли сеты подмножествами одного сета
bool isTheSameSet(Set* set, int firstValue, int secondValue);

//Удаляет "множество" сетов
void deleteSet(Set* set);