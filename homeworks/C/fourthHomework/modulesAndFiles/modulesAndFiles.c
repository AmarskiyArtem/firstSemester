#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>
#include "qSort.h"
#include "theMostCommonElement.h"
#include <malloc.h>

bool test(void) {
    FILE* file = fopen("test.txt", "r");
    if (file == NULL) {
        printf("Файл не найден");
        return false;
    }
    int dataLength = 0;
    int temp = 0;
    while (fscanf(file, "%d", &temp) == 1) {
        ++dataLength;
    }
    fseek(file, 0, SEEK_SET);
    int* data = (int*)calloc(dataLength, sizeof(int));
    if (data == NULL) {
        printf("MEMORY PANICCC");
        return false;
    }
    for (int i = 0; i < dataLength; ++i) {
        fscanf_s(file, "%d", &data[i]);
    }
    fclose(file);
    quickSort(&data[0], 0, dataLength - 1);
    int result = mostCommon(&data[0], dataLength);
    return result == 65;
}

int main() {
    setlocale(LC_ALL, "RU");
    if (!test()) {
        printf("Тесты упали");
        return;
    }
    FILE *file = fopen("arrayForSorting.txt", "r");
    if (file == NULL) {
        printf("Файл не найден");
        return;
    }
    int dataLength = 0;
    int temp = 0;
    while (fscanf(file, "%d", &temp) == 1) {
        ++dataLength;
    }
    if (dataLength == 0) {
        printf("Файл не содержит элементов");
        return;
    }
    fseek(file, 0, SEEK_SET);
    int* data = (int*)calloc(dataLength, sizeof(int));
    if (data == NULL) {
        printf("MEMORY PANICCC");
        return;
    }

    for (int i = 0; i < dataLength; ++i) {
        fscanf_s(file, "%d", &data[i]);
    }
    fclose(file);
    printf("Массив: \n");
    for (int i = 0; i < dataLength; ++i) {
        printf("%d ", data[i]);
    }
    quickSort(&data[0], 0, dataLength - 1);
    int result = mostCommon(&data[0], dataLength);
    printf("\nСамый частый элемент в файле: %d", result);
    free(data);
}