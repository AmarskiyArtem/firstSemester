#include <stdio.h>

#include "mergeSort.h"
#include "list.h"

bool tests(void) {
    return listTests() && sortTest();
}

void main(void) {
    if (!tests()) {
        printf("tests failed");
        return;
    }
    List* list = createList();
    if (list == NULL) {
        return;
    }
    readFromFile("input.txt", list);
    printf("Phone book before sorting:\n");
    printList(list);
    int action = 0;
    printf("==================\n"
        "Input type of sorting\n"
        "1 - by name\n2 - by number\n");
    scanf_s("%d", &action);
    while (!((action == 1) || (action == 2))) {
        printf("Incorrect input\n");
        printf("Input type of sorting\n"
            "1 - by name\n2 - by number\n");
        scanf_s("%d", &action);
    }
    SortBy sortBy = action;
    list = mergeSort(list, sortBy);
    printf("Phone book after sorting:\n");
    printList(list);
    deleteList(list);
}
