#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>
#include<time.h>
#define ARRAY_LENGTH 8

void swap(int* a, int* b) {
    if (a == b) {
        return;
    }
    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *a ^ *b;
}

bool sortChecker(int* array, int arraySize) {
    for (int i = 0; i < arraySize - 1; ++i) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}

void arrayPrint(int* array, int arraySize) {
    for (int i = 0; i < arraySize; ++i) {
        printf("%d ", array[i]);
    }
}

void bogoSort(int* array, int arraySize) {
    int firstIndex = rand() % arraySize;
    int secondIndex = rand() % arraySize;
    swap(&array[firstIndex], &array[secondIndex]);
}


bool test(void) {
    int arrayForTest[4] = { 5, 8, 9, 4 };
    while (!sortChecker(&arrayForTest[0], 4)) {
        bogoSort(&arrayForTest[0], 4);
    }
    if (!sortChecker(&arrayForTest[0], 4)) {
        return false;
    }
    return true;
}

int arrayForBogoSort[ARRAY_LENGTH] = { 0 };
void main() {
    setlocale(LC_ALL, "RU");
    if (!test()) {
        printf("Проблемы с тестом");
        return;
    }
    srand((unsigned)time(NULL));
    printf("Сгенерированный массив: \n");
    for (int i = 0; i < ARRAY_LENGTH; ++i) {
        arrayForBogoSort[i] = -10 + rand() % 20;
        printf("%d ", arrayForBogoSort[i]);
    }
    while (!sortChecker(&arrayForBogoSort[0], ARRAY_LENGTH)) {
        bogoSort(&arrayForBogoSort[0], ARRAY_LENGTH);
    }
    printf("\nОтсортированный массив:\n");
    arrayPrint(&arrayForBogoSort[0], ARRAY_LENGTH);
}