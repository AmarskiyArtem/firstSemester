#pragma once
#include "treeDictionary.h"
#include <malloc.h>

typedef struct Node {
    int key;
    char* value;
    struct Node* left;
    struct Node* rigth;
    struct Node* parent;
}Node;

typedef struct Tree {
    struct Node* root;
} Tree;

Tree* createTree(void) {
    Tree* tree = malloc(sizeof(Node));
    if (tree == NULL) {
        return NULL;
    }
    tree->root = NULL;
    return tree;
}

