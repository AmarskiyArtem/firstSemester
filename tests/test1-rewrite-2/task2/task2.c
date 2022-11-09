#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

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

void bubbleSort(int* array, int arraySize) {
    for (int i = 0; i < arraySize - 1; ++i) {
        for (int j = arraySize - 1; j > i; --j) {
            if (array[j - 1] > array[j]) {
                swap(&array[j - 1], &array[j]);
            }
        }
    }
}

void insert(int* array, int* evenArray, int arraySize) {
    int currentEvenArrayIndex = 0;
    for (int i = 0; i < arraySize; ++i) {
        if (array[i] % 2 == 0) {
            array[i] = evenArray[currentEvenArrayIndex++];
        }
    }
}

int evenElementsBubbleSort(int* array, int arrayLength) {
    int* onlyEven = (int*)calloc(arrayLength, sizeof(int));
    if (onlyEven == NULL) {
        return -1;
    }
    int currentIndex = 0;
    for (int i = 0; i < arrayLength; ++i) {
        if (array[i] % 2 == 0) {
            onlyEven[currentIndex++] = array[i];
        }
    }
    bubbleSort(&onlyEven[0], currentIndex);
    insert(&array[0], &onlyEven[0], arrayLength);
    free(onlyEven);
    return 0;
}

int main(void) {
    srand((unsigned)time(NULL));
    int arrayLength = 5 + rand() % 5;
    int* array = (int*)calloc(arrayLength, sizeof(int));
    if (array == NULL) {
        printf("MEMORY PANICC");
        return;
    }
    printf("Original array:\n");
    for (int i = 0; i < arrayLength; ++i) {
        array[i] = -100 + rand() % 200;
        printf("%d ", array[i]);
    }
    if (evenElementsBubbleSort(&array[0], arrayLength) != 0) {
        printf("MEMORY PANICC");
        return;
    }
    printf("\nNew array:\n");
    arrayPrint(&array[0], arrayLength);
    free(array);
}