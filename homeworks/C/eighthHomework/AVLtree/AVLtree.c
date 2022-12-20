#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "AVLtree.h"

typedef struct Node {
    struct Node* left;
    struct Node* right;
    struct Node* parent;
    char* key;
    char* value;
    int balance;
} Node;

typedef struct Tree {
    Node* root;
} Tree;

Tree* createTree() {
    return calloc(1, sizeof(Tree));
}

bool isEmpty(Tree* tree) {
    return tree->root == NULL;
}

Node* leftRotation(Node* root) {
    Node* base = root->right;
    root->right = base->left;
    if (base->left != NULL) {
        base->left->parent = root;
    }
    base->parent = root->parent;
    if (root->parent != NULL) {
        if (root->parent->right == root) {
            root->parent->right = base;
        }
        else {
        root->parent->left = base;
        }
    }
    base->left = root;
    root->parent = base;
    if (base->balance == 0) {
        root->balance = 1;
        base->balance = -1;
    }
    else {
        root->balance = 0;
        base->balance = 0;
    }
    return base;
}

Node* rightRotation(Node* root) {
    Node* base = root->left;
    root->left = base->right;
    base->parent = root->parent;
    if (base->right != NULL) {
        base->right->parent = root;
    }
    base->parent = root->parent;
    if (root->parent != NULL) {
        if (root->parent->left == root) {
            root->parent->left = base;
        }
        else {
            root->parent->right = base;
        }
    }
    base->right = root;
    root->parent = base;
    if (base->balance == 0) {
        root->balance = -1;
        base->balance = 1;
    }
    else {
        root->balance = 0;
        base->balance = 0;
    }
    return base;
}

int getBalance(Node* node) {
    return node == NULL ? 0 : node->balance;
}

Node* balance(Node* node) {
    if (node == NULL) {
        return node;
    }
    if (node->balance == 2) {
        if (getBalance(node->right == -1)) {
            node->right = rightRotation(node->right);
        }
        node = leftRotation(node);
        return node;
    }
    if (node->balance == -2) {
        if (getBalance(node->right == 1)) {
            node->left = leftRotation(node->left);
        }
        node = rightRotation(node);
        return node;
    }
    return node;
}

Node* createNode(Node* parentNode, const char* key, const char* value, ErrorCode* errorCode) {
    *errorCode = ok;
    Node* newNode = calloc(1, sizeof(Node));
    if (newNode == NULL) {
        *errorCode = memoryAllocationError;
        return NULL;
    }
    newNode->key = key;
    newNode->value = value;
    newNode->balance = 0;
    newNode->parent = parentNode;
    return newNode;
}

bool addValueRecursive(Node** node, const char* key, const char* value, ErrorCode* errorCode) {
    *errorCode = ok;
    if (strcmp(key, (*node)->key) == 0) {
        free((*node)->value);
        (*node)->value = value;
        return false;
    }
    if (strcmp(key, (*node)->key) < 0) {
        if ((*node)->left == NULL) {
            Node* newNode = createNode(*node, key, value, errorCode);
            (*node)->left = newNode;
            --(*node)->balance;
            *node = balance(*node);
            return (*node)->balance != 0;
        }
        if (addValueRecursive(&((*node)->left), key, value, errorCode)) {
            (*node)->balance -= 1;
            *node = balance(*node);
            return ((*node)->balance != 0);
        }
        return false;
    }
    else {
        if ((*node)->right == NULL) {
            Node* newNode = createNode(*node, key, value, errorCode);
            (*node)->right = newNode;
            (*node)->balance += 1;
            *node = balance(*node);
            return ((*node)->balance != 0);
        }
        if (addValueRecursive(&((*node)->right), key, value, errorCode)) {
            (*node)->balance += 1;
            *node = balance(*node);
            return ((*node)->balance != 0);
        }
        return false;
    }
    return true;
}

ErrorCode addValue(Tree* tree, const char* key, const char* value) {
    char* newValue = malloc(strlen(value));
    if (newValue == NULL) {
        return memoryAllocationError;
    }
    char* newKey = malloc(strlen(key));
    if (newKey == NULL) {
        free(newValue);
        return memoryAllocationError;
    }
    strcpy(newValue, value);
    strcpy(newKey, key);
    ErrorCode errorCode = ok;
    if (isEmpty(tree)) {
        Node* newRoot = createNode(NULL, newKey, newValue, &errorCode);
        if (errorCode != ok) {
            return memoryAllocationError;
        }
        tree->root = newRoot;
        return ok;
    }
    addValueRecursive(&(tree->root), newKey, newValue, &errorCode);
    return errorCode == ok ? ok : memoryAllocationError;
}

