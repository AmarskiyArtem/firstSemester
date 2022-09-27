#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>

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

void insertionSort(int* array, int arrayLength) {
    for (int i = 1; i < arrayLength; ++i) {
        int currentPosition = i;
        while (currentPosition > 0 && array[currentPosition - 1] > array[currentPosition]) {
            swap(&array[currentPosition], &array[currentPosition - 1]);
            --currentPosition;
        }
    }
}

void quickSort(int* array, int arraySize) {

}

void main() {
    srand((unsigned)time(NULL));

    int arrayLength = 3 + rand() % 30;
    arrayLength = 10;
    int* array = (int*)calloc(arrayLength, sizeof(int));
    if (array == NULL)
    {
        printf("Всё очень плохо :(");
        return;
    }
    printf("original array: \n");
    for (int i = 0; i < arrayLength; ++i) {
        array[i] = -100 + rand() % 200;
        printf("%d ", array[i]);
    }

    insertionSort(&array[0], arrayLength);
    printf("\nsorted Array:\n");
    arrayPrint(&array[0], arrayLength);
}