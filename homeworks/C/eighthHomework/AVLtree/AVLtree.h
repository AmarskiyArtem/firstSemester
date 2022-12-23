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
// Add value and key to tree
ErrorCode addValue(Tree* tree, const char* key, const char* value);

// Return char* by key, NULL if key not in tree
char* getValue(Tree* tree, char* key);

// Delete element by key
ErrorCode deleteValue(Tree* tree, char* key);

// Delete the tree
void deleteTree(Tree** tree);

// Checks if key in tree
bool isKeyInTree(Tree* tree, const char* key);

// Tests
bool tests(void);