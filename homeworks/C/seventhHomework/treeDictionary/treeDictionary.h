#pragma once

#include <stdbool.h>

typedef struct Tree Tree;

// Creates the tree
Tree* createTree(void);

// Delete the tree
void deleteTree(Tree* tree);

// Delete tree element by key
int deleteKey(Tree* tree, int key);

// Delete value abd key 
int addKey(Tree* tree, int key, char* value);

// Checks if key in tree
bool isKeyInTree(Tree* tree, int key);

// Checks if tree is empty
bool isEmpty(Tree* tree);

// Return value by key
char* getValue(Tree* tree, int key);

// Tests
bool tests(void);
