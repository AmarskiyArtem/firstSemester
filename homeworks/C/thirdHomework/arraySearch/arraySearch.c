#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define TEST_ARRAY_SIZE 10
#define TEST_KEYS_ARRAY_SIZE 5

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

bool isInArray(int* array, int arrayLength, int lookedFor) {
    int left = 0;
    int right = arrayLength;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (array[middle] == lookedFor)
            return true;
        if (array[middle] < lookedFor)
            left = middle + 1;
        else
            right = middle - 1;
    }
    return false;
}

bool test(void) {
    int testArray[] = { 18, 23, 18, 21, 9, 21, 10, 16, 28, 18 };
    int testKeysArray[] = { 20, 28, 21, 3, 8 };
    bool results[] = { false, true, true, false, false };
    for (int i = 0; i < TEST_KEYS_ARRAY_SIZE; ++i) {
        if (isInArray(&testArray[0], TEST_ARRAY_SIZE, testKeysArray[i]) != results[i]) {
            return false;
        }
    }
    return true;
}

void main() {
    srand((unsigned)time(NULL));
    if (!test()) {
        printf("test failed");
        return;
    }
    printf("Enter array length (n)\n");
    int arrayLength = 0;
    scanf_s("%d", &arrayLength);
    int* array = (int*)calloc(arrayLength, sizeof(int));
    if (array == NULL) {
        printf("MEMORY PANICC");
        return;
    }
    printf("Generated array: \n");
    for (int i = 0; i < arrayLength; ++i) {
        array[i] = rand() % 30;
        printf("%d ", array[i]);
    }
    
    printf("\nEnter amount of numbers (k)\n");
    int amountOfNumbers = 0;
    scanf_s("%d", &amountOfNumbers);
    int* arrayWithKNumbers = (int*)calloc(amountOfNumbers, sizeof(int));
    if (arrayWithKNumbers == NULL) {
        free(array);
        printf("MEMORY PANICC(2)");
        return;
    }
    quickSort(&array[0], 0, arrayLength - 1);
    printf("K generated numbers:\n");
    for (int i = 0; i < amountOfNumbers; ++i) {
        arrayWithKNumbers[i] = rand() % 30;
        printf("%d ", arrayWithKNumbers[i]);
    }
    printf("\n");
    for (int i = 0; i < amountOfNumbers; ++i) {
        isInArray(&array[0], arrayLength, arrayWithKNumbers[i]) ?
            printf("%d in generated array\n", arrayWithKNumbers[i]) :
            printf("%d not in generated array\n", arrayWithKNumbers[i]);
    }
    free(arrayWithKNumbers);
    free(array);
}