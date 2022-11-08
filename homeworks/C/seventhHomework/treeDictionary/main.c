#pragma once
#include "treeDictionary.h"
#include <stdio.h>
#define MAX_ARRAY_LENGTH 100

void printActions(void) {
    printf("ACTIONS:\n"
        "0 - exit\n"
        "1 - add value by key\n"
        "2 - get value by key\n"
        "3 - check if key in tree\n"
        "4 - delete key\n");
}

void main() {
    Tree* tree = createTree();
    //isEmpty(tree) ? printf("YES") : printf("NO");
    int a = 6;
    char b[] = "vnfdj";
    addKey(tree, a, b);
}

//void main() {
//    bool isContinue = true;
//    Tree* tree = createTree();
//    while (isContinue) {
//        int currentAction = 0;
//        printf("Input action:\n");
//        scanf_s("%d", &currentAction);
//        switch (currentAction) {
//            case 0: {
//                isContinue = false;
//                printf("Good Bye");
//                break;
//            }
//            case 1: {
//                int key = 0;
//                printf("Input key:\n");
//                scanf_s("%d", &key);
//                char value[MAX_ARRAY_LENGTH] = { 0 };
//                printf("Input value:\n");
//                scanf_s("%100s", value, (unsigned)sizeof(value));
//                //добавление элемента
//                break;
//            }
//            case 2: {
//                int key = 0;
//                printf("Input key:\n");
//                scanf_s("%d", &key);
//                char value[MAX_ARRAY_LENGTH] = { 0 };
//                printf("Input value:\n");
//                scanf_s("%100s", value, (unsigned)sizeof(value));
//                //поиск элемента
//                break; 
//            }
//            case 3: {
//                int key = 0;
//                printf("Input key:\n");
//                scanf_s("%d", &key);
//                //проверка нахождения в дереве
//                break;
//            }
//            case 4: {
//                int key = 0;
//                printf("Input key:\n");
//                scanf_s("%d", &key);
//                //удаление
//                break;
//            }
//        }
//    }
//    //deleteTree(tree);
//}