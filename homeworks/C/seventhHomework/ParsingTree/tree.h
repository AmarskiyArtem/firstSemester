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

// Creates the tree
Tree* createTree(void);

// Fill tree by given string
ErrorCode fillTree(Tree* tree, const char* string);

// Calculate the math expression in tree
int calculate(Tree* tree, ErrorCode* errorCode);

// Delete tree
void deleteTree(Tree* tree);

// Print tree
ErrorCode printTree(Tree* tree);