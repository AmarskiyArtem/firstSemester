#include<stdio.h>
#include<locale.h>
#include<malloc.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

#define arrayLength 30000

void swap(int* a, int* b) {
    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *a ^ *b;
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

void arrayPrint(int* array, int arraySize) {
    for (int i = 0; i < arraySize; ++i) {
        printf("%d ", array[i]);
    }
}
bool sortChecker(int* array, int arraySize) {
    for (int i = 0; i < arraySize - 1; ++i) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}
bool bubbleSortTests(void) {
    int arrayOne[15] = { 6, 8, 24, 67, 544, 53, 23, 63, 94, 13, 33, 1, 4, -5, 34 };
    bubbleSort(&arrayOne, 15);
    if (!sortChecker(&arrayOne, 15)) {
        return false;
    }
    int arrayTwo[20] = { 68, 36, 46, 89, 96, 45, 67, 29, 91, 66, 40, 20, 84, 17, 97, 47, 40, 81, 72, 84 };
    bubbleSort(&arrayTwo, 20);
    if (!sortChecker(&arrayTwo, 20)) {
        return false;
    }
    return true;
}

bool countingSortTests(void) {
    int arrayOne[15] = { 6, 8, 24, 67, 544, 53, 23, 63, 94, 13, 33, 1, 4, -5, 34 };
    countingSort(&arrayOne, 15);
    if (!sortChecker(&arrayOne, 15)) {
        return false;
    }
    int arrayTwo[20] = { 68, 36, 46, 89, 96, 45, 67, 29, 91, 66, 40, 20, 84, 17, 97, 47, 40, 81, 72, 84 };
    countingSort(&arrayTwo, 20);
    if (!sortChecker(&arrayTwo, 20)) {
        return false;
    }
    return true;
}



void main() {
    srand(time(NULL));
    setlocale(LC_ALL, "RU");
    if (!bubbleSortTests()) { 
        printf("ААААА ПАНИКА НЕ РАБОТАЕТ"); 
    }
    if (!countingSortTests()) {
        printf("ААААА ПАНИКА НЕ РАБОТАЕТ(2)");
    }
    
    int arrayForBubbleSort[arrayLength] = { 0 };
    for (int i = 0; i < arrayLength; ++i) {
        arrayForBubbleSort[i] = -1000 + rand() % 2000;
    }
    clock_t startBubble;
    clock_t stopBubble;
    startBubble = clock();
    bubbleSort(&arrayForBubbleSort, arrayLength);
    stopBubble = clock();
    printf("Bubble sort required %f seconds\n", (stopBubble - startBubble) / CLK_TCK);
    
    int arrayForCountingSort[arrayLength] = { 0 };
    for (int i = 0; i < arrayLength; ++i) {
        arrayForCountingSort[i] = -1000 + rand() % 2000;
    }
    clock_t startCounting;
    clock_t stopCounting;
    startCounting = clock();
    countingSort(&arrayForCountingSort, arrayLength);
    stopCounting = clock();
    printf("Counting sort required %f seconds\n", (stopCounting - startCounting) / CLK_TCK);
}