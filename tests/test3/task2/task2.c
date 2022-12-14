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
    if (pushBack(list, "acvdfond") != ok) {
        deleteList(list);
        printf("Memory allocation error");
        return;
    }
    if (pushBack(list, "vdfn") != ok) {
        deleteList(list);
        printf("Memory allocation error");
        return;
    }
    if (pushBack(list, "jj") != ok) {
        deleteList(list);
        printf("Memory allocation error");
        return;
    }
    if (pushBack(list, "avreyb") != ok) {
        deleteList(list);
        printf("Memory allocation error");
        return;
    }
    printf("List before function application\n");
    printList(list);
    if (aStringAdder(list) != ok) {
        deleteList(list);
        printf("Memory allocation error");
        return;
    }
    printf("\nList afer function application\n");
    printList(list);
    deleteList(list);
}