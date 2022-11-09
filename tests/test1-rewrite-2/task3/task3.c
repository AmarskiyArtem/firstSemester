#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>



char* deletingExtraSymbols(char* string, char* resultString, int resultStringMaxSize) {
    int currentIndex = 0;
    resultString[currentIndex++] = string[0];
    for (int i = 1; i < resultStringMaxSize; ++i) {
        if (string[i - 1] == string[i]) {
            continue;
        }
        resultString[currentIndex++] = string[i];
    }
    return resultString;
}

bool test(void) {
    FILE* file = fopen("test.txt", "r");
    if (file == NULL) {
        return false;
    }
    int dataLength = 0;
    char temp = '\0';
    while (fscanf(file, "%c", &temp) == 1) {
        ++dataLength;
    }
    if (dataLength == 0) {
        return false;
    }
    fseek(file, 0, SEEK_SET);
    dataLength += 1;
    char* data = (char*)calloc(dataLength, sizeof(char));
    if (data == NULL) {
        return false;
    }
    for (int i = 0; i < dataLength; ++i) {
        fscanf(file, "%c", &data[i]);
    }
    fclose(file);
    int testStringMaxSize = (int)strlen(data);
    char* resultString = calloc(testStringMaxSize, sizeof(char));
    if (resultString == NULL) {
        return false;
    }
    resultString = deletingExtraSymbols(data, resultString, testStringMaxSize);
    char rigthAnswer[] = "afgba";
    if (strcmp(resultString, rigthAnswer) == 0) {
        free(data);
        free(resultString);
        return true;
    }
    free(data);
    free(resultString);
    return false;
}

void main(void) {
    if (!test()) {
        printf("test problems");
        return;
    }
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("file is not found");
        return;
    }
    int dataLength = 0;
    char temp = '\0';
    while (fscanf(file, "%c", &temp) == 1) {
        ++dataLength;
    }
    if (dataLength == 0) {
        printf("file is empty");
        return;
    }
    fseek(file, 0, SEEK_SET);
    dataLength += 1;
    char* data = (char*)calloc((dataLength), sizeof(char));
    if (data == NULL) {
        printf("problem with memory allocation\n");
        return;
    }
    for (int i = 0; i < dataLength; ++i) {
        fscanf(file, "%c", &data[i]);
    }
    fclose(file);
    int resultStringMaxSize = (int) strlen(data);
    char* resultString = calloc(resultStringMaxSize, sizeof(char));
    if (resultString == NULL) {
        printf("problem with memory allocation\n");
        return;
    }
    resultString = deletingExtraSymbols(data, resultString, resultStringMaxSize);
    printf("Origin string: %s\n", data);
    printf("New string: %s\n", resultString);
    free(data);
    free(resultString);
}