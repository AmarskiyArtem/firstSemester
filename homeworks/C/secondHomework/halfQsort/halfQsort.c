#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<locale.h>
#include<stdbool.h>


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

void halfQsort(int* array, int arraySize) {
    int left = 0;
    int right = arraySize - 1;
    while (left < right) {
        if (array[left] < array[0]) {
            ++left;
        }
        else if (array[right] >= array[0]) {
            --right;
        }
        else {
            swap(&array[right], &array[left]);
            ++left;
            --right;
        }
    }
}

void main() {
    setlocale(LC_ALL, "RU");
    srand(time(NULL));
    int arraySize = 10 + rand() % 10;
    printf("Исходный массив:\n");
    int* array = (int*)calloc(arraySize, sizeof(int));
    if (array == NULL)
    {
        printf("Всё очень плохо :(");
        return;
    }
    for (int i = 0; i < arraySize; ++i) {
        array[i] = rand() % 100;
        printf("%d ", array[i]);
    }
    halfQsort(&array, arraySize);
    printf("\nМассив после изменений:\n");
    arrayPrint(&array, arraySize);
}