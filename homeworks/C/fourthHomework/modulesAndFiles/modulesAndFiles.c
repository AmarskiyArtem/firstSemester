#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>
#include <malloc.h>

#include "qSort.h"
#include "theMostCommonElement.h"

int* readingFromFile(const char* fileName, int* dataLength) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        return NULL;
    }
    *dataLength = 0;
    int temp = 0;
    while (fscanf(file, "%d", &temp) == 1) {
        ++(*dataLength);
    }
    if (dataLength == 0) {
        fclose(file);
        return NULL;
    }
    fseek(file, 0, SEEK_SET);
    int* data = (int*)calloc(*dataLength, sizeof(int));
    if (data == NULL) {
        fclose(file);
        return NULL;
    }

    for (int i = 0; i < *dataLength; ++i) {
        fscanf_s(file, "%d", &data[i]);
    }
    fclose(file);
    return data;
}

bool readingFromFileTest(void) {
    int testDataLegth = 0;
    int* testData = readingFromFile("test.txt", &testDataLegth);
    int rightArray[] = { 65, 22, 41, 67, 1 };
    if (testDataLegth != 5) {
        return false;
    }

    for (int i = 0; i < testDataLegth; ++i) {
        if (testData[i] != rightArray[i]) {
            free(testData);
            return false;
        }
    }

    free(testData);
    return true;
}

bool mostCommonTest(void) {
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
    return mostCommonTest() && readingFromFileTest();
}

void main() {
    setlocale(LC_ALL, "RU");
    if (!tests()) {
        printf("Тесты упали");
        return;
    }
    int dataLength = 0;
    int* data = readingFromFile("arrayForSorting.txt", &dataLength);
    if (data == NULL) {
        return;
    }
    printf("Массив: \n");
    for (int i = 0; i < dataLength; ++i) {
        printf("%d ", data[i]);
    }
    quickSort(&data[0], 0, dataLength - 1);
    int result = mostCommon(&data[0], dataLength);
    printf("\nСамый частый элемент в файле: %d", result);
    free(data);
}