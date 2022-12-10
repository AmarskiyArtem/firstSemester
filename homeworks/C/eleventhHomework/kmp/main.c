#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "kmp.h"

#define MAX_SUBSTRING_LENGTH 100

char* readFromFile(const char* filename) {
    int stringLength = 0;
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }
    char temp = '0';
    while (fscanf_s(file, "%c", &temp, 1) != EOF) {
        ++stringLength;
    }
    if (stringLength == 0) {
        fclose(file);
        return NULL;
    }
    fseek(file, 0, SEEK_SET);
    char* string = calloc(stringLength, sizeof(char));
    if (string == NULL) {
        fclose(file);
        return NULL;
    }
    for (int i = 0; i < stringLength - 1; ++i) {
        fscanf_s(file, "%c", &string[i], 1);
    }
    fclose(file);
    return string;
}

bool readFromFileTest(void) {
    int testStringLength = 0;
    char* testString = readFromFile("test.txt");
    if (strcmp(testString, "nvfdsnvs\nnewrg") != 0) {
        free(testString);
        return false;
    }
    free(testString);
    return true;
}

bool kmpTest(void) {
    return searchForOccurrences("fhsduavp", "sd") == 2 &&
        searchForOccurrences("nebhvbovb", "aaa") == -1 &&
        searchForOccurrences("abababbaba", "abba") == 4;
}

bool tests(void) {
    return readFromFileTest() && kmpTest();
}

void main() {
    if (!tests()) {
        printf("tests failed");
        return;
    }
    char* string = readFromFile("input.txt");
    if (string == NULL) {
        printf("File missing");
        return;
    }
    printf("Text from file:\n%s", string);
    printf("\nInput the substring:\n");
    char* substring = calloc(MAX_SUBSTRING_LENGTH, sizeof(char));
    if (substring == NULL) {
        printf("Memory allocation error");
        return;
    }
    scanf_s("%100s", substring, (unsigned)sizeof(substring));
    const int result = searchForOccurrences(string, substring);
    result >= 0 ?
        printf("The first occurrence of the symbol begins with %d index", result) :
        printf("The substring does not occur in the file");
    free(substring);
}