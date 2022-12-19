#pragma once
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct Tree Tree;

typedef enum ErrorCode {
    ok,
    treeIsEmpty,
    memoryAllocationError, 
    zeroDivision
} ErrorCode;

Tree* createTree(void);

ErrorCode fillTree(Tree* tree, const char* string);

int calculate(Tree* tree, ErrorCode* errorCode);

void deleteTree(Tree* tree);

ErrorCode printTree(Tree* tree);