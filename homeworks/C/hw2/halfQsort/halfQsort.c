#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <time.h>
#include <malloc.h> 

#define ARRAY_LENGTH 10

void swap(int* a, int* b) {
    if (a == b) {
        return;
    }
    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *a ^ *b;
}

void arrayPrint(int* array, int arraySize) {
    for (int i = 0; i < arraySize; ++i) {
        printf("%d ", array[i]);
    }
}

void halfQSort(int* array, int arraySize, int pivot) {
    int leftIndex = 0;
    int rightIndex = arraySize - 1;
    while (leftIndex <= rightIndex) {
        while (leftIndex < arraySize && array[leftIndex] < pivot) {
            leftIndex++;
        }
        while (rightIndex >= 0 && array[rightIndex] >= pivot) {
            rightIndex--;
        }
        if (leftIndex <= rightIndex) {
            swap(&array[leftIndex], &array[rightIndex]);
            leftIndex++;
            rightIndex--;
        }
    }
}

bool isHalfing(int* array, int arraySize, int pivot) {
    int i = 0;
    while (array[i] < pivot) {
        ++i;
    }
    while (i < arraySize && array[i] >= pivot) {
        ++i;
    }
    return i == arraySize;
}

bool tests(void) {
    int testArray[ARRAY_LENGTH] = { 0 };
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < ARRAY_LENGTH; ++j) {
            testArray[j] = 20 + rand() % 100;
        }
        int pivot = testArray[0];
        halfQSort(&testArray[0], ARRAY_LENGTH, pivot);
        if (!isHalfing(&testArray[0], ARRAY_LENGTH, pivot)) {
            return false;
        }
    }
    return true;
}
    
void main() {
    setlocale(LC_ALL, "RU");
    srand((unsigned)time(NULL));
    if (!tests()) {
        printf("Тесты упали");
        return;
    }
    int array[ARRAY_LENGTH] = { 0 };
    printf("Исходный массив:\n");
    for (int i = 0; i < ARRAY_LENGTH; ++i) {
        array[i] = rand() % 100;
        printf("%d ", array[i]);
    }
    halfQSort(&array[0], ARRAY_LENGTH, array[0]);
    printf("\nМассив после изменений:\n");
    arrayPrint(&array[0], ARRAY_LENGTH);
}