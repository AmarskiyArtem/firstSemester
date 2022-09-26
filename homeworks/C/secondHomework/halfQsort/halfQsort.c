#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<stdbool.h>
#include<time.h>

#define arrayLength 20

void swap(int* a, int* b) {
    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *a ^ *b;
}

void arrayPrint(int* array, int arraySize) {
    for (int i = 0; i < arraySize; ++i) {
        printf("%d ", array[i]);
    }
}

void halfQsort(int* array, int arraySize) {
    int left = 0;
    int right = arraySize - 1;
    while (left < right) {
        if (array[left] < array[0]) {
            ++left;
        }
        else if (array[right] >= array[0]) {
            --right;
        }
        else {
            swap(&array[right], &array[left]);
            ++left;
            --right;
        }
    }
}

void main() {
    setlocale(LC_ALL, "RU");
    srand((unsigned)time(NULL));
    int array[arrayLength] = { 0 };
    printf("Исходный массив:\n");
    for (int i = 0; i < arrayLength; ++i) {
        array[i] = rand() % 100;
        printf("%d ", array[i]);
    }
    halfQsort(&array[0], arrayLength);
    printf("\nМассив после изменений:\n");
    arrayPrint(&array[0], arrayLength);
}