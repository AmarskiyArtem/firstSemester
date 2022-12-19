#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char operation;
    int operand;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Tree {
    Node* root;
} Tree;

bool isEmpty(Tree* tree) {
    return tree->root == NULL;
}

