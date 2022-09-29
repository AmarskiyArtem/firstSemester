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

void main() {
    srand((unsigned)time(NULL));
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