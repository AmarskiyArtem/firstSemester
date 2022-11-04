#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "treeDictionary.h"
#include <stdio.h>
#define MAX_ARRAY_LENGTH 100

void printActions(void) {
    printf("ACTIONS:\N"
        "0 - exit"
        "1 - add value by key"
        "2 - get value by key"
        "3 - check if key in tree"
        "4 - delete key");
}

void main() {
    bool isContinue = true;
    Tree* tree = createTree();
    while (isContinue) {
        int currentAction = 0;
        printf("Input action:\n");
        scanf_s("%d", &currentAction);
        switch (currentAction) {
            case 0: {
                isContinue = false;
                printf("Good Bye");
                break;
            }
            case 1: {
                int key = 0;
                printf("Input key:\n");
                scanf_s("%d", &key);
                char value = 0;
                printf("Input value:\n");
                scanf_s("%c", value);
                //добавление элемента
                break;
            }
            case 2: {
                int key = 0;
                printf("Input key:\n");
                scanf_s("%d", &key);
                char value = 0;
                printf("Input value:\n");
                scanf_s("%c", value);
                //поиск элемента
                break;
            }
            case 3: {
                int key = 0;
                printf("Input key:\n");
                scanf_s("%d", &key);
                //проверка нахождения в дереве
                break;
            }
            case 4: {
                int key = 0;
                printf("Input key:\n");
                scanf_s("%d", &key);
                //удаление
                break;
            }
        }
    }
    deleteTree(tree);
}