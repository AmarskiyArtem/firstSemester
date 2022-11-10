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

bool isSorted(int* array, int arraySize) {
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

int mostCommon(int* array, int arrayLength) {
    int mostCommonElement = array[0];
    int currentInARow = 1;
    int maxInARow = 1;
    for (int i = 1; i < arrayLength; ++i) {
        if (array[i] == array[i - 1]) {
            currentInARow += 1;
        }
        else {
            currentInARow = 1;
        }
        if (currentInARow >= maxInARow) {
            maxInARow = currentInARow;
            mostCommonElement = array[i];
        }
    }
    return mostCommonElement;
}

bool qSortTests(void) {
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

bool mostCommonTests(void) {
    int testArray1[] = { 0, 1, 7, 4, 6, 3, 6, 8, 9, 5, 4, 9, 3, 6, 2 }; 
    int testArray2[] = { 5, 8, 2, 3, 7, 3, 4, 7, 0, 0, 5, 9, 2, 3, 8 };
    int testArray3[] = { 7, 2, 0, 9, 6, 1, 7, 2, 3, 7, 1, 1, 6, 3, 8 };
    int testArray[3][15] = { {0, 1, 7, 4, 6, 3, 6, 8, 9, 5, 4, 9, 3, 6, 2},
                        { 5, 8, 2, 3, 7, 3, 4, 7, 0, 0, 5, 9, 2, 3, 8 },
                        { 7, 2, 0, 9, 6, 1, 7, 2, 3, 7, 1, 1, 6, 3, 8 } };
    int results[] = { 6, 3, 7 };
    for (int i = 0; i < 3; ++i) {
        quickSort(&testArray[i][0], 0, 14);
        if ((mostCommon(&testArray[i][0], 15)) != results[i]) {
            return false;
        }
    }
    return true;
}

bool tests(void) {
    return mostCommonTests() && qSortTests();
}


void main() {
    srand((unsigned)time(NULL));
    if (!tests()) {
        printf("tests failed");
        return;
    }
    int arrayLength = 15;
    int* array = (int*)calloc(arrayLength, sizeof(int));
    if (array == NULL) {
        printf("MEMORY PANICC");
        return;
    }
    printf("Generated array: \n");
    for (int i = 0; i < arrayLength; ++i) {
        array[i] = rand() % 10;
        printf("%d ", array[i]);
    }
    quickSort(&array[0], 0, arrayLength - 1);
    printf("\nSorted array\n"); 
    for (int i = 0; i < arrayLength; ++i) {
        printf("%d ", array[i]);
    }
    printf("\nThe most common element: %d", mostCommon(&array[0], arrayLength));
    free(array);
}