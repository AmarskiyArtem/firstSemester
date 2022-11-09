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

bool isEmpty(Tree* tree) {
    return tree->root == NULL;
}

int insert(Node* node, int key, char* value) {
    if (key == node->key) {
        free(node->value);
        char* newValue = calloc(strlen(value) + 1, sizeof(char));
        if (newValue == NULL) {
            return -1;
        }
        strcpy(newValue, value);
        node->value = newValue;
        return 0;
    }
    if (key < node->key) {
        if (node->left == NULL) {
            Node* temp = malloc(sizeof(Node));
            if (temp == NULL) {
                return -1;
            }
            char* newValue = calloc(strlen(value) + 1, sizeof(char));
            if (newValue == NULL) {
                return -1;
            }
            strcpy(newValue, value);
            temp->key = key;
            temp->value = newValue;
            temp->parent = node;
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
            char* newValue = calloc(strlen(value) + 1, sizeof(char));
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
        char* newValue = calloc(strlen(value) + 1, sizeof(char));
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

Node* findNodeByKey(Node* node, int key) {
    while (true) {
        if (node == NULL) {
            return NULL;
        }
        if (node->key == key) {
            return node;
        }
        (key < node->key) ? (node = node->left) : (node = node->right);
    }
    return NULL;
}

char* findValueFromNode(Node* node, int key) {
    Node* temp = findNodeByKey(node, key);
    if (temp == NULL) {
        return NULL;
    }
    return temp->value;
}

char* getValue(Tree* tree, int key) {
    return findValueFromNode(tree->root, key);
}

bool isKeyInTree(Tree* tree, int key) {
    return findNodeByKey(tree->root, key) != NULL;
}

Node* getMostRight(Node* node) {
    if (node->right == NULL) {
        return node;
    }
    getMostRight(node);
}

int deleteKey(Tree* tree, int key) {
    Node* nodeForDeleting = findNodeByKey(tree->root, key);
    if (nodeForDeleting == NULL) {
        return -1;
    }
    if (nodeForDeleting->left == NULL && nodeForDeleting->right == NULL) {
        if (nodeForDeleting->parent->left == nodeForDeleting) {
            nodeForDeleting->parent->left = NULL;
            free(nodeForDeleting->value);
            free(nodeForDeleting);
            return 0;
        }
        nodeForDeleting->parent->right = NULL;
        free(nodeForDeleting->value);
        free(nodeForDeleting);
        return 0;
    }
    if (nodeForDeleting->left == NULL && nodeForDeleting->right != NULL) {
        if (nodeForDeleting->parent->left == nodeForDeleting) {
            nodeForDeleting->parent->left = nodeForDeleting->right;
            free(nodeForDeleting->value);
            free(nodeForDeleting);
            return 0;
        }
        nodeForDeleting->parent->right = nodeForDeleting->right;
        free(nodeForDeleting->value);
        free(nodeForDeleting);
        return 0;
    }
    if (nodeForDeleting->left != NULL && nodeForDeleting->right == NULL) {
        if (nodeForDeleting->parent->left == nodeForDeleting) {
            nodeForDeleting->parent->left = nodeForDeleting->left;
            free(nodeForDeleting->value);
            free(nodeForDeleting);
            return 0;
        }
        nodeForDeleting->parent->right = nodeForDeleting->left;
        free(nodeForDeleting->value);
        free(nodeForDeleting);
        return 0;
    }
    Node* mostRight = getMostRight(nodeForDeleting);
    free(nodeForDeleting->value);
    nodeForDeleting->value = mostRight->value;
    if (mostRight->left != NULL) {
        mostRight->left->parent = mostRight->parent;
    }
    if (mostRight->parent == nodeForDeleting) {
        mostRight->parent->left = mostRight->left;
    }
    else {
        mostRight->parent->right = mostRight->left;
    }
    free(mostRight);
    return 0;
}

