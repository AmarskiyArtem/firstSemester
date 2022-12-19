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
    fclose(file);
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

bool readFromFileTest(void) {
    char* testString = getStringFromFile("test.txt");
    if (testString == NULL) {
        return false;
    }
    if (strcmp(testString, "(* (+ 1 1) 2)") != 0) {
        free(testString);
        return false;
    }
    free(testString);
    return true;
}

bool calculationTest(void) {
    char* testString = getStringFromFile("test.txt");
    if (testString == NULL) {
        return false;
    }
    if (!isCorrectMathExpression(testString)) {
        free(testString);
        return false;
    }
    Tree* testTree = createTree();
    if (testTree == NULL) {
        free(testString);
        return false;
    }
    if (fillTree(testTree, testString) != ok) {
        free(testString);
        deleteTree(testTree);
        return false;
    }
    ErrorCode errorCode = ok;
    int result = calculate(testTree, &errorCode);
    free(testString);
    deleteTree(testTree);
    return errorCode == ok && result == 4;
}

bool tests(void) {
    return calculationTest() && readFromFileTest();
}

void main(void) {
    if (!tests()) {
        printf("tests failed");
        return;
    }
    char* string = getStringFromFile("input.txt");
    if (string == NULL) {
        printf("File not found");
        return;
    }
    if (!isCorrectMathExpression(string)) {
        printf("Incorrect math expression");
        return;
    }
    Tree* tree = createTree();
    if (tree == NULL) {
        printf("Memory allocation error");
        return;
    }
    if (fillTree(tree, string) != ok) {
        printf("Something went wrong");
        deleteTree(tree);
        return;
    }
    free(string);
    ErrorCode errorCode = ok;
    int result = calculate(tree, &errorCode);
    if (errorCode != ok) {
        printf("Something went wrong");
        deleteTree(tree);
        return;
    }
    printTree(tree);
    printf("= %d", result);
    deleteTree(tree);
}