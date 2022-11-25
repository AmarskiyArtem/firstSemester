#pragma once
#include "mergeSort.h"
#include "list.h"
#include <stdio.h>

void main(void) {
    List* list = createList();
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
    //sorting
    printf("Phone book after sorting:\n");
    printList(list);
    deleteList(list);
}