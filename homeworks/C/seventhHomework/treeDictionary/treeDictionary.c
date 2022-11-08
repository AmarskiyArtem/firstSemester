#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "treeDictionary.h"
#include <malloc.h>
#include <string.h>

typedef struct Node {
    int key;
    char* value;
    struct Node* left;
    struct Node* right;
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

int insert(Node* node, int key, char* value) {
    if (key == node->key) {
        free(node->value);
        node->value = value;
        return 0;
    }
    if (key < node->key) {
        if (node->left == NULL) {
            Node* temp = malloc(sizeof(Node));
            if (temp == NULL) {
                return -1;
            }
            char* newValue = calloc(strlen(value), sizeof(char));
            if (newValue == NULL) {
                return -1;
            }
            strcpy(newValue, value);
            temp->key = key;
            temp->value = newValue;
            temp->parent = NULL;
            temp->right = NULL;
            temp->left = NULL;
            node->left = temp;
            return 0;
        }
        if (insert(node->left, key, value) != 0) {
            return -1;
        }
    }
    if (key > node->key) {
        if (node->right == NULL) {
            Node* temp = malloc(sizeof(Node));
            if (temp == NULL) {
                return -1;
            }
            char* newValue = calloc(strlen(value), sizeof(char));
            if (newValue == NULL) {
                return -1;
            }
            strcpy(newValue, value);
            temp->key = key;
            temp->value = newValue;
            temp->parent = node;
            temp->right = NULL;
            temp->left = NULL;
            node->right = temp;
            return 0;
        }
        if (insert(node->right, key, value) != 0) {
            return -1;
        }
    }
    return 0;
}

int addKey(Tree* tree, int key, char* value) {
    if (isEmpty(tree)) {
        Node *temp = malloc(sizeof(Node));
        if (temp == NULL) {
            return -1;
        }
        char* newValue = calloc(strlen(value), sizeof(char));
        if (newValue == NULL) {
            return -1;
        }
        strcpy(newValue, value);
        temp->key = key;
        temp->value = newValue;
        temp->parent = NULL;
        temp->right = NULL;
        temp->left = NULL;
        tree->root = temp;
        return 0;
    }
    if (insert(tree->root, key, value) != 0) {
        return -1;
    }
    return 0;
}

