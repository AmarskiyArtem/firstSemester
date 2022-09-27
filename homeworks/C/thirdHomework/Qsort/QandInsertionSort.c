#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>


//почему-то через такой свап не работает qSort, причем только он

/*void swap(int* a, int* b) {     
    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *a ^ *b;
}*/


void swap(int* a, int* b) {
    int temporary = *a;
    *a = *b;
    *b = temporary;
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

void main() {
    srand((unsigned)time(NULL));
    int arrayLength = 3 + rand() % 20;
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

    arrayLength <= 10 ? insertionSort(&array[0], arrayLength) : quickSort(&array[0], 0, arrayLength - 1);
    printf("\nsorted Array:\n");
    arrayPrint(&array[0], arrayLength);
    free(array);
}