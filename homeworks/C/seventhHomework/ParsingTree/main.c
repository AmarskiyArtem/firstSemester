#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tree.h"
#include <string.h>

#define MAX_STRING_LENGTH 50

char* getStringFromFile(const char* fileName) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        return NULL;
    }
    char* string = calloc(MAX_STRING_LENGTH, sizeof(char));
    if (string == NULL) {
        fclose(file);
        return NULL;
    }
    fgets(string, MAX_STRING_LENGTH, file);
    return string;
}

bool isCorrectMathExpression(const char* string) {
    const char correctSymbols[] = "0123456789/*-+() ";
    int stringLength = strlen(string) - 1;
    for (int i = 0; i < stringLength; ++i) {
        if (strchr(correctSymbols, string[i]) == NULL) {
            return false;
        }
    }
    return true;
}

