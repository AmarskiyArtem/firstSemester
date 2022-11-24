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

char* getValue(Tree* tree, int key) {
    Node* node = findNodeByKey(tree->root, key);
    if (node == NULL) {
        return NULL;
    }
    return node->value;
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

void deleteRoot(Tree* tree) {
    if (tree->root->left == NULL && tree->root->right == NULL) {
        free(tree->root->value);
        free(tree->root);
        tree->root = NULL;
        return;
    }
    if (tree->root->left != NULL) {
        if (tree->root->left->right != NULL) {
            Node* mostRightParent = tree->root->left;
            Node* mostRight = tree->root->left->right;
            while (mostRight->right != NULL) {
                mostRightParent = mostRight;
                mostRight = mostRight->right;
            }
            mostRightParent->right = mostRight->left;
            free(tree->root->value);
            tree->root->value = mostRight->value;
            tree->root->key = mostRight->key;
            free(mostRight);
            return;
        }
        tree->root->left->right = tree->root->right;
        Node* newRoot = tree->root->left;
        free(tree->root->value);
        free(tree->root);
        tree->root = newRoot;
        return;
    }
    Node* newRoot = tree->root->right;
    free(tree->root->value);
    free(tree->root);
    tree->root = newRoot;
}

int deleteKey(Tree* tree, int key) {
    if (isEmpty(tree)) {
        return -1;
    }
    if (tree->root->key == key) {
        deleteRoot(tree);
        return 0;
    }
    Node* nodeForDeleting = tree->root;
    Node* nodeForDeletingParent = tree->root;
    while (nodeForDeleting != NULL) {
        if (nodeForDeleting->key == key) {
            break;
        }
        nodeForDeletingParent = nodeForDeleting;
        (nodeForDeleting->key < key) ?
            (nodeForDeleting = nodeForDeleting->right) :
            (nodeForDeleting = nodeForDeleting->left);
    }
    if (nodeForDeleting == NULL) {
        return -1;
    }
    if (nodeForDeleting->left == NULL && nodeForDeleting->right == NULL) {
        (nodeForDeletingParent->right == nodeForDeleting) ?
            (nodeForDeletingParent->right = NULL) :
            (nodeForDeletingParent->left = NULL);
        free(nodeForDeleting->value);
        free(nodeForDeleting);
        return 0;
    }
    if (nodeForDeleting->left != NULL && nodeForDeleting->right == NULL) {
        (nodeForDeletingParent->right == nodeForDeleting) ?
            (nodeForDeletingParent->right = nodeForDeleting->left) :
            (nodeForDeletingParent->left = nodeForDeleting->left);
        free(nodeForDeleting->value);
        free(nodeForDeleting);
        return 0;
    }
    if (nodeForDeleting->right != NULL && nodeForDeleting->left == NULL) {
        (nodeForDeletingParent->right == nodeForDeleting) ?
            (nodeForDeletingParent->right = nodeForDeleting->right) :
            (nodeForDeletingParent->left = nodeForDeleting->right);
        free(nodeForDeleting->value);
        free(nodeForDeleting);
        return 0;
    }
    if (nodeForDeleting->left->right != NULL) {
        Node* mostRightParent = nodeForDeleting->left;
        Node* mostRight = nodeForDeleting->left->right;
        while (mostRight->right != NULL) {
            mostRightParent = mostRight;
            mostRight = mostRight->right;
        }
        mostRightParent->right = mostRight->left;
        free(nodeForDeleting->value);
        nodeForDeleting->value = mostRight->value;
        nodeForDeleting->key = mostRight->key;
        free(mostRight);
        return 0;
    }
    free(nodeForDeleting->value);
    Node* temp = nodeForDeleting->left;
    nodeForDeleting->value = temp->value;
    nodeForDeleting->left = temp->left;
    free(temp);
    return 0;
}

void deleteNode(Node* node) {
    if (node == NULL) {
        return;
    }
    deleteNode(node->left);
    deleteNode(node->right);
    free(node->value);
    free(node);
}

void deleteTree(Tree* tree) {
    deleteNode(tree->root);
}