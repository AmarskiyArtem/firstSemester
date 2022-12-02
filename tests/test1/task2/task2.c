#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

bool sortHonestIndexChecker(int* array, int arraySize) {
    for (int i = 0; i < arraySize - 2; i += 2) {
        if (array[i] > array[i + 2]) {
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

void swap(int* a, int* b) {
    if (a == b) {
        return;
    }
    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *a ^ *b;
}

void insertionSortOfHonestIndex(int* array, int arrayLength) {
    for (int i = 2; i < arrayLength; i += 2) {
        int currentPosition = i;
        while (currentPosition > 0 && array[currentPosition - 2] > array[currentPosition]) {
            swap(&array[currentPosition], &array[currentPosition - 2]);
            currentPosition -= 2;
        }
    }
}

bool tests(void) {
    for (int i = 0; i < 3; ++i) {
        int arrayForTestsLength = 3 + rand() % 40;
        int* arrayForTests = (int*)calloc(arrayForTestsLength, sizeof(int));
        if (arrayForTests == NULL) {
            printf("MEMORY PANICCCC(2)");
            return false;
        }
        int* arrayForTestsCopy = (int*)calloc(arrayForTestsLength, sizeof(int));
        if (arrayForTestsCopy == NULL) {
            printf("MEMORY PANICCCC(3)");
            free(arrayForTests);
            return false;
        }
        for (int i = 0; i < arrayForTestsLength; ++i) {
            arrayForTests[i] = -100 + rand() % 200;
            arrayForTestsCopy[i] = arrayForTests[i];
        }

        insertionSortOfHonestIndex(&arrayForTests[0], arrayForTestsLength);
        if (!sortHonestIndexChecker(&arrayForTests[0], arrayForTestsLength)) {
            printf("Sorting error\n Origin array:\n");
            arrayPrint(&arrayForTestsCopy[0], arrayForTestsLength);
            printf("\nWrong sorted array:\n");
            arrayPrint(&arrayForTests[0], arrayForTestsLength);
            free(arrayForTests);
            free(arrayForTestsCopy);
            return false;
        }
        else {
            free(arrayForTests);
            free(arrayForTestsCopy);
        }
    }
    return true;
}

void main() {
    srand((unsigned)time(NULL));
    if (!tests()) {
        return;
    }
    int arrayLength = 5 + rand() % 5;
    int* array = (int*)calloc(arrayLength, sizeof(int));
    if (array == NULL) {
        printf("MEMORY PANICC(1)");
        return;
    }
    printf("Original array: \n");
    for (int i = 0; i < arrayLength; ++i) {
        array[i] = -20 + rand() % 40;
        printf("%d ", array[i]);
    }
    insertionSortOfHonestIndex(&array[0], arrayLength);
    printf("\n'Sorted' array:\n");
    arrayPrint(&array[0], arrayLength);
    free(array);
}