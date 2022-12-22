#pragma once

#include <stdbool.h>

typedef enum ErrorCode {
    ok,
    treeIsEmpty,
    memoryAllocationError,
    nodeIsNull
} ErrorCode;

typedef struct Tree Tree;

Tree* createTree();

ErrorCode addValue(Tree* tree, const char* key, const char* value);

char* getValue(Tree* tree, char* key);

ErrorCode deleteValue(Tree* tree, char* key, bool* result);

void deleteTree(Tree** tree);

bool isKeyInTree(Tree* tree, const char* key);

