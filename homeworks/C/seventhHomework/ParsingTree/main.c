#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "tree.h"


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
    int stringLength = (int)(strlen(string) - 1);
    for (int i = 0; i < stringLength; ++i) {
        if (strchr(correctSymbols, string[i]) == NULL) {
            return false;
        }
    }
    return true;
}

void main(void) {
    char* s = getStringFromFile("input.txt");
    Tree* tree = createTree();
    fillTree(tree, s);
    printf("%d", calculate(tree, ok));
}