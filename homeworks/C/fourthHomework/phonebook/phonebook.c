#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>

#include "list.h"

#define MAX_STRING_LENGTH 256

void printListOfActions(void) {
    printf("--------------------------------------\n"
        "0 - выйти\n"
        "1 - добавить запись(имя и телефон)\n"
        "2 - распечатать все имеющиеся записи\n"
        "3 - найти телефон по имени\n"
        "4 - найти имя по телефону\n"
        "5 - сохранить текущие данные в файл\n"
        "--------------------------------------\n");
}

void main() {
    setlocale(LC_ALL, "RU");
    List* list = createList();
    readFromFile("storage.txt", list);
    bool isContinue = true;
    while (isContinue) {
        int currentAction = 0;
        printf("Введите действие (999 - справка)\n");
        scanf_s("%d", &currentAction);
        switch (currentAction) {
            case 0: {
                printf("До свидания!");
                isContinue = false;
                break;
            }
            case 1: {
                printf("Введите имя:\n");
                char name[MAX_STRING_LENGTH] = { 0 };
                scanf_s("%256s", name, (unsigned)sizeof(name));
                printf("Введите номер:\n");
                char phoneNumber[MAX_STRING_LENGTH] = { 0 };
                scanf_s("%256s", phoneNumber, (unsigned)sizeof(phoneNumber));
                add(list, &name[0], &phoneNumber[0]) != 0 ?
                    printf("Проблемы с выделением памяти\n") :
                    printf("Запись успешно добавлена\n");
                
                break;
            }
            case 2: {
                printList(list);
                break;
            }
            case 3: {
                printf("Введите имя:\n");
                char name[MAX_STRING_LENGTH] = { 0 };
                scanf_s("%256s", name, (unsigned)sizeof(name));
                char* number = findByName(list, name);
                number == NULL ? printf("Записи с таким именем нет\n") :
                    printf("У %s номер %s\n", name, number);
                break;
            }
            case 4: {
                printf("Введите номер:\n");
                char phoneNumber[MAX_STRING_LENGTH] = { 0 };
                scanf_s("%256s", phoneNumber, (unsigned)sizeof(phoneNumber));
                char* name = findByNumber(list, phoneNumber);
                name == NULL ? printf("Записи с таким номером нет\n") :
                    printf("%s номер у %s\n", phoneNumber, name);
                break;
            }
            case 5: {
                saveToFile("storage.txt", list) != 0 ?
                    printf("Файл не найден\n") :
                    printf("Данные успешно сохранены\n");
                break;
            }
            case 999: {
                printListOfActions();
                break;
            }
            default: {
                printf("Неверный формат ввода\n");
                break; 
            }
        }
    }
    deleteList(list);
}