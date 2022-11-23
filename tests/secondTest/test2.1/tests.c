#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "tests.h"
#include "list.h"
#include <stdio.h>

bool emptyTest(void) {
    FILE* file = fopen("emptyInput.txt", "r");
    if (file == NULL) {
        printf("file not found");
        return false;
    }
    List* list = createList();
    if (list == NULL) {
        printf("Problems with memory allocation");
        return false;
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
    return isSymmetric(list) == true;
}

bool evenTest(void) {
    FILE* file = fopen("testInput1.txt", "r");
    if (file == NULL) {
        printf("file not found");
        return false;
    }
    List* list = createList();
    if (list == NULL) {
        printf("Problems with memory allocation");
        return false;
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
    return isSymmetric(list) == true;
}

bool unevenTest(void) {
    FILE* file = fopen("testInput2.txt", "r");
    if (file == NULL) {
        printf("file not found");
        return false;
    }
    List* list = createList();
    if (list == NULL) {
        printf("Problems with memory allocation");
        return false;
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
    return isSymmetric(list) == false;
}

bool isPassed(void) {
    return emptyTest() && evenTest() && unevenTest();
}