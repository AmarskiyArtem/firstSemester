#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

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

bool isSorted(int* array, int arraySize) {
    for (int i = 0; i < arraySize - 1; ++i) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}

void insertionSort(int* array, int arrayLength) {
    for (int i = 1; i < arrayLength; ++i) {
        int currentPosition = i;
        while (currentPosition > 0 && array[currentPosition - 1] > array[currentPosition]) {
            swap(&array[currentPosition], &array[currentPosition - 1]);
            --currentPosition;
        }
    }
}

int partition(int* array, int low, int high) {
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(int* array, int low, int high) {
    if (low < high) {
        int border = partition(array, low, high);
        quickSort(array, low, border - 1);
        quickSort(array, border + 1, high);
    }
}

bool tests(void) {
    int arrayForTestsLength = 3 + rand() % 40;
    int* arrayForTests = (int*)calloc(arrayForTestsLength, sizeof(int));
    if (arrayForTests == NULL) {
        printf("MEMORY PANICCCC");
        return false;
    }
    int* arrayForTestsCopy = (int*)calloc(arrayForTestsLength, sizeof(int));
    if (arrayForTestsCopy == NULL) {
        printf("MEMORY PANICCCC");
        free(arrayForTests);
        return false;
    }
    for (int i = 0; i < 3; ++i) {
        for (int i = 0; i < arrayForTestsLength; ++i) {
            arrayForTests[i] = -100 + rand() % 200;
            arrayForTestsCopy[i] = arrayForTests[i];
        }
        arrayForTestsLength <= 10 ? insertionSort(&arrayForTests[0], arrayForTestsLength) : 
            quickSort(&arrayForTests[0], 0, arrayForTestsLength - 1);
        
        if (!isSorted(&arrayForTests[0], arrayForTestsLength)) {
            printf("Sorting error\n Origin array:\n");
            arrayPrint(&arrayForTestsCopy[0], arrayForTestsLength);
            printf("\nWrong sorted array:\n");
            arrayPrint(&arrayForTests[0], arrayForTestsLength);
            free(arrayForTests);
            free(arrayForTestsCopy);
            return false;
        }
    }
    free(arrayForTests);
    free(arrayForTestsCopy);
    return true;
}

void main() {
    srand((unsigned)time(NULL));
    if (!tests()) {
        printf("tests failed");
        return;
    }

    int arrayLength = 3 + rand() % 20;
    int* array = (int*)calloc(arrayLength, sizeof(int));
    if (array == NULL) {
        printf("MEMORY PANICC");
        return;
    }
    printf("Original array: \n");
    for (int i = 0; i < arrayLength; ++i) {
        array[i] = -100 + rand() % 200;
        printf("%d ", array[i]);
    }

    arrayLength <= 10 ? insertionSort(&array[0], arrayLength) : quickSort(&array[0], 0, arrayLength - 1);
    printf("\nSorted Array:\n");
    arrayPrint(&array[0], arrayLength);
    free(array);
}