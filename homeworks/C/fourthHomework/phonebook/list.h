#pragma once
#include <stdbool.h>

typedef struct List List;

//выполняет чтение из файла в список, возвращает -1, если не удалось найти файл, 0 если чтение успешно
int readFromFile(char* fileName, List* list);

//возвращает указатель на пустой список
List* createList(void);

//удаляет список
void deleteList(List* list);

//выводит список в консоль
int printList(List* list);

//добавляет элемент в голову списка, возвращает 0 в случае проблем с выделением памяти
int add(List* list, char* name, char* number);

//сохраняет данные из списка в файл, затирая уже имеющиеся, возвращает -1 если не удалось найти файл, 0 если запись успешна
int saveToFile(char* fileName, List* list);

//возвращает указатель на первую найденную строку с совпадающим именем, NULL, если совпадений нет
char* findByName(List* list, char* name);

//возвращает указатель на первую найденную строку с совпадающим номером, NULL, если совпадений нет
char* findByNumber(List* list, char* number);

//тесты...
bool tests(void);