#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include "qSort.h"
#include "theMostCommonElement.h"
#include <malloc.h>

int arrayLength(int* array) {
    int length = 0;
    int i = 0;
    while (array[i] != NULL) {
        ++length;
        ++i;
    }
    return length;
}

int main() {
    setlocale(LC_ALL, "RU");
    FILE *file = fopen("arrayForSorting.txt", "r");
    if (file == NULL) {
        printf("файл не найден\n");
        return;
    }
    char* data[100] = { 0 };
    int linesRead = 0;
    while (!feof(file)) {
        char* buffer = malloc(sizeof(char) * 100);
        const int readBytes = fscanf(file, "%s", buffer);
        if (readBytes < 0) {
            break;
        }
        data[linesRead] = buffer;
        ++linesRead;
    }
    fclose(file);

    for (int i = 0; i < 15; ++i) {
        printf("%s\n", data[i]);
    }
    int dataLength = arrayLength(&data[0]);
    //printf("%d", dataLength);
    //quickSort(&data[0], 0, dataLength - 1);
    //int result = mostCommon(&data[0], dataLength);
    //printf("Самый частый элемент в файле: %d", result);
}