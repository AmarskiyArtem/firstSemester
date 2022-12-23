#include <stdio.h>

#include "treeDictionary.h"

#define MAX_ARRAY_LENGTH 100

void printActions(void) {
    printf("ACTIONS:\n"
        "0 - exit\n"
        "1 - add value by key\n"
        "2 - get value by key\n"
        "3 - check if key in tree\n"
        "4 - delete key\n");
}

//void main() {
//    Tree* tree = createTree();
//    //isEmpty(tree) ? printf("YES") : printf("NO");
//    int a = 6;
//    char b[] = "vnfdj";
//    addKey(tree, a, b);
//    int a1 = 4;
//    char c[] = "vjanvnjs";
//    addKey(tree, a1, c);
//    a1 = 8;
//    char c2[] = "vjanvs";
//    addKey(tree, a1, c2);
//    a1 = 5;
//    char c3[] = "vnvnjs";
//    addKey(tree, a1, c3);
//    a1 = 1;
//    char c4[] = "ncj";
//    addKey(tree, a1, c4);
//    a1 = 2; 
//    char cc[] = "npjvna";
//    addKey(tree, a1, cc);
//    a1 = 7;
//    char cc1[] = "cbdsh";
//    addKey(tree, a1, cc1);
//    a1 = 12;
//    char cc4[] = "cwqcnioq";
//    addKey(tree, a1, cc4);
//    //printf("%s", getValue(tree, 3));
//    isKeyInTree(tree, 6) ? printf("YES") : printf("NO");
//    deleteKey(tree, 6);
//    isKeyInTree(tree, 6) ? printf("YES") : printf("NO");
//    deleteKey(tree, 1);
//    isKeyInTree(tree, 1) ? printf("YES") : printf("NO");
//    deleteTree(tree);
//}

void main() {
    if (!tests()) {
        printf("tests failed");
        return;
    }
    bool isContinue = true;
    Tree* tree = createTree();
    printActions();
    while (isContinue) {
        int currentAction = 0;
        printf("Input action:\n");
        scanf_s("%d", &currentAction);
        switch (currentAction) {
            case 0: {
                isContinue = false;
                printf("Good Bye!");
                break;
            }
            case 1: {
                int key = 0;
                printf("Input key:\n");
                scanf_s("%d", &key);
                char value[MAX_ARRAY_LENGTH] = { 0 };
                printf("Input value:\n");
                scanf_s("%100s", value, (unsigned)sizeof(value));
                addKey(tree, key, value);
                break;
            }
            case 2: {
                int key = 0;
                printf("Input key:\n");
                scanf_s("%d", &key);
                char* value = getValue(tree, key);
                (value == NULL) ? printf("No such key in tree\n") : printf("%s\n", value);
                break; 
            }
            case 3: {
                int key = 0;
                printf("Input key:\n");
                scanf_s("%d", &key);
                isKeyInTree(tree, key) ? printf("Key is in the tree\n") : printf("Key is not in the tree\n");
                break;
            }
            case 4: {
                int key = 0;
                printf("Input key:\n");
                scanf_s("%d", &key);
                (deleteKey(tree, key) == 0) ? printf("Successful deletion\n") : printf("No such key in tree\n");
                break;
            }
            default: {
                printf("Incorrect input\n");
                break;
            }
        }
    }
    deleteTree(tree);
}