#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void arrayPrint(int* array, int arraySize) {
    for (int i = 0; i < arraySize; ++i) {
        printf("%d ", array[i]);
    }
}

int* readingFromFile(const char* fileName, int* arrayLength) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        return NULL;
    }
    *arrayLength = 0;
    int temp = 0;
    while (fscanf_s(file, "%d", &temp) == 1) {
        ++(*arrayLength);
    }
    if (arrayLength == 0) {
        fclose(file);
        return NULL;
    }
    fseek(file, 0, SEEK_SET);
    int* array = (int*)calloc(*arrayLength, sizeof(int));
    if (array == NULL) {
        fclose(file);
        return NULL;
    }

    for (int i = 0; i < *arrayLength; ++i) {
        fscanf_s(file, "%d", &array[i]);
    }
    fclose(file);
    return array;
}

int writeToFileInReverseOrder(const char* fileName, int* array, int arrayLength) {
    FILE* file = fopen(fileName, "w");
    if (file == NULL) {
        return -1;
    }
    for (int i = arrayLength - 1; i >= 0; --i) {
        if (fprintf(file, "%d ", array[i]) < 0) {
            fclose(file);
            return -1;
        }
    }
    fclose(file);
    return 0;
}

bool readingFromFileTest(void) {
    int testArrayLength = 0;
    int* testArray = readingFromFile("test.txt", &testArrayLength);
    if (testArray == NULL) {
        return false;
    }
    int rightArray[] = { 65, 22, 41, 67, 1 };
    if (testArrayLength != 5) {
        return false;
    }

    for (int i = 0; i < testArrayLength; ++i) {
        if (testArray[i] != rightArray[i]) {
            free(testArray);
            return false;
        }
    }
    free(testArray);
    return true;
}

int prepareToTest(void) {
    int arrayLength = 5;
    int array[] = { 1, 2, 3, 4, 5 };
    FILE* file = fopen("recordTest.txt", "w");
    if (file == NULL) {
        return -1;
    }
    for (int i = 0; i < arrayLength; ++i) {
        if (fprintf(file, "%d ", array[i]) < 0) {
            fclose(file);
            return -1;
        }
    }
    fclose(file);
    return 0;
}

bool recordToFileTest(void) {
    if (prepareToTest() != 0) {
        return false;
    }
    int testArrayLength = 0;
    int* testArray = readingFromFile("recordTest.txt", &testArrayLength);
    if (testArray == NULL) {
        return false;
    }
    if (writeToFileInReverseOrder("recordTest.txt", testArray, testArrayLength) != 0) {
        free(testArray);
        return false;
    }
    free(testArray);
    testArray = readingFromFile("recordTest.txt", &testArrayLength);
    if (testArray == NULL) {
        return false;
    }
    int rightArray[] = {5, 4, 3, 2, 1};
    for (int i = 0; i < testArrayLength; ++i) {
        if (rightArray[i] != testArray[i]) {
            free(testArray);
            return false;
        }
    }
    free(testArray);
    return true;
}

bool tests(void) {
    return readingFromFileTest() && recordToFileTest();
}

void main(void) {
    if (!tests()) {
        printf("tests failed");
        return;
    }
    int arrayLength = 0;
    int* array = readingFromFile("input.txt", &arrayLength);
    if (array == NULL) {
        return;
    }
    printf("Original file:\n");
    arrayPrint(array, arrayLength);
    if (writeToFileInReverseOrder("input.txt", array, arrayLength) != 0) {
        free(array);
        return;
    }
    free(array);
    array = readingFromFile("input.txt", &arrayLength);
    if (array == NULL) {
        return;
    }
    printf("\nFile after function:\n");
    arrayPrint(array, arrayLength);
    free(array);
}