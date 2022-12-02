#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include "list.h"
#include "tests.h"
#include <stdio.h>

void main(void) {
    if (!isPassed()) {
        printf("Tests failed");
        return;
    }
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("File not found");
        return;
    }
    List* list = createList();
    if (list == NULL) {
        printf("Problems with memory allocation");
        return;
    }
    while (true) {
        int number = 0;
        if (fscanf(file, "%d", &number) != EOF) {
            push(list, number);
        }
        else {
            break;
        }
    }
    fclose(file);
    printf("Set of numbers: ");
    printList(list);
    isSymmetric(list) ? printf("is symmetric") : printf("is not symmetric");
    deleteList(list);
}