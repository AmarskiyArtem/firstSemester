#include<stdio.h>
#include<locale.h>
#include<malloc.h>

void swap(int* a, int* b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void bubbleSort(int *array, int arraySize) {
    for (int i = 0; i < arraySize - 1; ++i) {
        for (int j = arraySize - 1; j > i; --j) {
            if (array[j - 1] > array[j]) {
                swap(&array[j - 1], &array[j]);
            }
        }
    }
}

void countingSort(int* array, int arraySize) {
    int maxArrayElement = array[0];
    int minArrayElement = array[0];
    for (int i = 1; i < arraySize; ++i) {
        if (array[i] > maxArrayElement) {
            maxArrayElement = array[i];
        }
        if (array[i] < minArrayElement) {
            minArrayElement = array[i];
        }
    }
    int arrayForCountingSize = maxArrayElement - minArrayElement + 1;
    int* arrayForCounting = (int*)calloc(arrayForCountingSize, sizeof(int)); 
    if (arrayForCounting == NULL)
    {
        printf("Всё очень плохо :(");
        return;
    }
    for (int i = 0; i < arraySize; ++i) {
        ++arrayForCounting[array[i] - minArrayElement];
    }
    int temp = 0;
    for (int i = 0; i < arrayForCountingSize; ++i) {
        for (int j = 0; j < arrayForCounting[i]; ++j) {
            array[temp++] = i + minArrayElement;
        }
    }
    free(arrayForCounting);
}

void main() {
    int a[5] = {6, 3, 7, 4, 2};
    countingSort(a, 5);
    for (int i = 0; i < 5; ++i) {
        printf("%d ", a[i]);
    }
}