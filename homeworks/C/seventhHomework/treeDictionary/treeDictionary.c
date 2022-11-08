#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "treeDictionary.h"
#include <malloc.h>
#include <string.h>

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

Node* findNode(Tree* tree, int key) {
    Node* currentNode = tree->root;
}

bool isEmpty(Tree* tree) {
    return tree->root == NULL;
}