#pragma once
#include<stdbool.h>

typedef struct Tree Tree;

Tree* createTree(void);

void deleteTree(Tree* tree);

int deleteKey(Tree* tree, int key);

int addKey(Tree* tree, int key, char* value);

bool isKeyInTree(Tree* tree, int key);

bool isEmpty(Tree* tree);

char* getValue(Tree* tree, int key);