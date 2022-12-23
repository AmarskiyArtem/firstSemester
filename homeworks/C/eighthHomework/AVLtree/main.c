#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#include "AVLtree.h"

#define MAX_STRING_LENGTH 30

void actions(void) {
    printf("===================\nACTIONS:\n"
        "0 - exit\n"
        "1 - add value by key\n"
        "2 - get  value by key\n"
        "3 - check if key in tree\n"
        "4 - delete key and value\n"
        "5 - see list of actions\n"
        "===================\n");
}

void main(void) {
    if (!tests()) {
        printf("Tests failed");
        return;
    }
    bool isContinue = true;
    Tree* tree = createTree();
    if (tree == NULL) {
        printf("Memory allocarion error");
        return;
    }
    actions();
    while (isContinue) {
        int action = 0;
        printf("Input action\n");
        scanf_s("%d", &action);
        switch (action) {
            case 0: {
                printf("Good bye!");
                isContinue = false;
                break;
            }
            case 1: {
                char value[MAX_STRING_LENGTH] = { 0 };
                char key[MAX_STRING_LENGTH] = { 0 };
                printf("Input key\n");
                scanf_s("%s", key, MAX_STRING_LENGTH);
                printf("Input value\n");
                scanf_s("%s", value, MAX_STRING_LENGTH);
                addValue(tree, &key[0], &value[0]) != ok ? printf("error\n") : 
                    printf("Successful addition\n");
                break;
            }
            case 2: {
                char key[MAX_STRING_LENGTH] = { 0 };
                printf("Input key\n");
                scanf_s("%s", key, MAX_STRING_LENGTH);
                char* value = getValue(tree, &key[0]);
                value == NULL ? printf("No such key in tree\n") : printf("%s\n", value);
                break;
            }
            case 3: {
                char key[MAX_STRING_LENGTH] = { 0 };
                printf("Input key\n");
                scanf_s("%s", key, MAX_STRING_LENGTH);
                printf(isKeyInTree(tree, &key[0]) ? "key in tree\n" : "key not in tree\n");
                break;
            }
            case 4: {
                char key[MAX_STRING_LENGTH] = { 0 };
                printf("Input key\n");
                scanf_s("%s", key, MAX_STRING_LENGTH);
                deleteValue(tree, &key[0]);
                break;
            }
            default: {
                printf("Incorrect input\n");
                break;
            }
        }
    }

    deleteTree(&tree);
}

