#include <stdio.h>

#include "list.h"

void main(void) {
    if (!tests()) {
        printf("tests failed");
        return;
    }
    List* list = createList();
    if (list == NULL) {
        printf("Memory allocation error");
        return;
    }
    if (push(list, 5) != ok) {
        deleteList(list);
        printf("Memory allocation error");
        return;
    }
    if (push(list, 6) != ok) {
        deleteList(list);
        printf("Memory allocation error");
        return;
    }
    if (push(list, 7) != ok) {
        deleteList(list);
        printf("Memory allocation error");
        return;
    }
    if (push(list, 10) != ok) {
        deleteList(list);
        printf("Memory allocation error");
        return;
    }
    if (push(list, 1) != ok) {
        deleteList(list);
        printf("Memory allocation error");
        return;
    }
    printf("Original list\n");
    printList(list);
    deleteOdd(list);
    printf("\nList after applying the function\n");
    printList(list);
    deleteList(list);
}