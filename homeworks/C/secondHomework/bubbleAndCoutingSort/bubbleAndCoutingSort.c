#include<stdio.h>
#include<locale.h>
#include<malloc.h>
#include<stdbool.h>
#include<stdlib.h>

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

bool equalityTest(void) {
    for (int j = 0; j < 5; ++j) {
        int arraysSize = 5 + rand() % 30;
        int* arrayOne = (int*)calloc(arraysSize, sizeof(int));
        if (arrayOne == NULL)
        {
            printf("Всё очень плохо :(");
            return false;
        }
        int* arrayOneCopy = (int*)calloc(arraysSize, sizeof(int));
        if (arrayOneCopy == NULL)
        {
            printf("Всё очень плохо :(");
            return false;
        }
        for (int i = 0; i < arraysSize; ++i) {
            arrayOne[i] = -100 + rand() % 200;
        }
        for (int i = 0; i < arraysSize; ++i) {
            arrayOneCopy[i] = arrayOne[i];
        }
        bubbleSort(&arrayOne, arraysSize);
        countingSort(&arrayOneCopy, arraysSize);
        for (int i = 0; i < arraysSize; ++i) {
            if (arrayOne[i] != arrayOneCopy[i]) {
                free(arrayOne);
                free(arrayOneCopy);
                return false;
            }
        }
        free(arrayOne);
        free(arrayOneCopy);
    }
    return true;
}


void main() {
    srand(time(NULL));
    bool x = equalityTest();
    x ? printf("YES") : printf("NO");
}