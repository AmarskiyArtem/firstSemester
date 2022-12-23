#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
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

Tree* createTree(void) {
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
        if (getBalance(node->right) == -1) {

            node->right = rightRotation(node->right);
        }
        node = leftRotation(node);
        return node;
    }
    if (node->balance == -2) {
        if (getBalance(node->right) == 1) {
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
    newNode->key = malloc(strlen(key) + 1);
    if (newNode->key == NULL) {
        free(newNode);
        *errorCode = memoryAllocationError;
        return NULL;
    }
    strcpy(newNode->key, key);
    newNode->value = malloc(strlen(value) + 1);
    if (newNode->value == NULL) {
        free(newNode->key);
        free(newNode);
        *errorCode = memoryAllocationError;
        return NULL;
    }
    strcpy(newNode->value, value);
    newNode->balance = 0;
    newNode->parent = parentNode;
    return newNode;
}

bool addValueRecursive(Node** node, const char* key, const char* value, ErrorCode* errorCode) {
    *errorCode = ok;
    if (strcmp(key, (*node)->key) == 0) {
        free((*node)->value);
        (*node)->value = malloc(strlen(value) + 1);
        if ((*node)->value == NULL) {
            *errorCode = memoryAllocationError;
            return false;
        }
        strcpy((*node)->value, value);
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
    if (strcmp(key, (*node)->key) > 0) {
        if ((*node)->right == NULL) {
            Node* newNode = createNode(*node, key, value, errorCode);
            (*node)->right = newNode;
            (*node)->balance += 1;
            *node = balance(*node);
            return ((*node)->balance != 0);
        }
        if (addValueRecursive(&((*node)->right), key, value, errorCode)) {
            ++((*node)->balance);
            *node = balance(*node);
            return ((*node)->balance != 0);
        }
        return false;
    }
    return true;
}

ErrorCode addValue(Tree* tree, const char* key, const char* value) {
    char* newValue = malloc(strlen(value) + 1);
    if (newValue == NULL) {
        return memoryAllocationError;
    }
    char* newKey = malloc(strlen(key) + 1);
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

char* getValueRecursive(Node* node, char* key) {
    if (node == NULL) {
        return NULL;
    }
    if (strcmp(key, node->key) == 0) {
        return node->value;
    }
    return (strcmp(key, node->key) < 0) ? getValueRecursive(node->left, key) : 
        getValueRecursive(node->right, key);
}

char* getValue(Tree* tree, char* key) {
    return getValueRecursive(tree->root, key);
}

bool isKeyInTree(Tree* tree, const char* key) {
    return getValueRecursive(tree->root, key) != NULL;
}

Node* mostRight(Node* node) {
    while (node->right != NULL) {
        node = node->right;
    }
    return node;
}

Node* deleteNodeRecursive(Node* node, char* key, ErrorCode* errorCode, bool* result) {
    if (node == NULL) {
        *result = true;
        return NULL;
    }
    if (strcmp(key, node->key) == 0) {
        if (node->left != NULL && node->right != NULL) {
            Node* mostRightChild = mostRight(node->left);
            char* newValue = calloc(sizeof(mostRightChild->value) + 1, sizeof(char*));
            if (newValue == NULL) {
                *errorCode = memoryAllocationError;
                *result = true;
                return NULL;
            }
            char* newKey = calloc(sizeof(mostRightChild->key) + 1, sizeof(char*));
            if (newKey == NULL) {
                free(newValue);
                *errorCode = memoryAllocationError;
                *result = true;
                return NULL;
            }
            strcpy(newValue, mostRightChild->value);
            strcpy(newKey, mostRightChild->key);
            node->value = newValue;
            node->key = newKey;
            node->balance = mostRightChild->balance - 1;
            mostRightChild = deleteNodeRecursive(mostRightChild, mostRightChild->key, errorCode, result);
            node = balance(node);
            *result = (node->balance != -1 && node->balance != 1);
            return node;
        }
        if (node->right == NULL) {
            if (node->left != NULL) {
                node->left->parent = node->parent;
            }
            if (strcmp(key, node->parent->key) <= 0) {
                node->parent->left = node->left;
            }
            else {
                node->parent->right = node->left;
            }
        }
        else {
            node->right->parent = node->parent;
            if (strcmp(key, node->parent->key) <= 0) {
                node->parent->left = node->right;
            }
            else {
                node->parent->right = node->right;
            }
        }
        free(node->value);
        free(node->key);
        free(node);
        *result = true;
        return NULL;
    }
    if(strcmp(key, node->key) < 0) {
        node->left = deleteNodeRecursive(node->left, key, errorCode, result);
        if (*result) {
            ++(node->balance);
            node = balance(node);
            *result = node->balance != -1 && node->balance != 1;
            return node;
        }
        *result = false;
        return node;
    }
    node->right = deleteNodeRecursive(node->right, key, errorCode, result);
    if (*result) {
        node->balance -= 1;
        node = balance(node);
        *result = node->balance != -1 && node->balance != 1;
        return node;
    }
    *result = false;
    return node;
}

Node* deleteRoot(Tree* tree, ErrorCode* errorCode, bool* result) {
    if (tree->root->left != NULL && tree->root->right != NULL) {
        Node* mostRightChild = mostRight(tree->root->left);
        char* newValue = calloc(sizeof(mostRightChild->value) + 1, sizeof(char));
        if (newValue == NULL) {
            *errorCode = memoryAllocationError;
            return NULL;
        }
        char* newKey = calloc(sizeof(mostRightChild->value) + 1, sizeof(char));
        if (newKey == NULL) {
            free(newValue);
            *errorCode = memoryAllocationError;
            return NULL;
        }
        strcpy(newValue, mostRightChild->value);
        tree->root->value = newValue;
        strcpy(newKey, mostRightChild->key);
        tree->root->key = newKey;
        mostRightChild = deleteNodeRecursive(mostRightChild, mostRightChild->key, errorCode, result);
        --(tree->root->balance);
        tree->root = balance(tree->root);
        return tree->root;
    }
    Node* newRoot = NULL;
    if (tree->root->left != NULL) {
        newRoot = tree->root->left;
    }
    else {
        newRoot = tree->root->right;
    }
    if (newRoot != NULL)
    {
        newRoot->parent = NULL;
    }
    free(tree->root->key);
    free(tree->root->value);
    free(tree->root);
    tree->root = balance(newRoot);
    return newRoot;
}

ErrorCode deleteValue(Tree* tree, char* key) {
    bool result = true;
    if (isEmpty(tree)) {
        return treeIsEmpty;
    }
    ErrorCode errorCode = ok;
    if (strcmp(key, tree->root->key) == 0) {
        tree->root = deleteRoot(tree, &errorCode, &result);
        return errorCode;
    }
    tree->root = deleteNodeRecursive(tree->root, key, &errorCode, &result);
    return errorCode;
}

void deleteTreeRecursive(Node* node) {
    if (node == NULL) {
        return;
    }
    deleteTreeRecursive(node->left);
    deleteTreeRecursive(node->right);
    free(node);
}

void deleteTree(Tree** tree) {
    deleteTreeRecursive((*tree)->root);
    free(*tree);
    tree = NULL;
}

int getHeight(Node* node, bool* balanceIsOk) {
    if (node->left == NULL && node->right == NULL) {
        return 0;
    }
    if (node->left == NULL || node->right == NULL) {
        return 1;
    }
    //if (node->left != NULL && node->right == NULL) {
    //    return getHeight(node->left, balanceIsOk);
    //}
    //if (node->right != NULL && node->left == NULL) {
    //    return getHeight(node->right, balanceIsOk);
    //}
    int heightLeft = getHeight(node->left, balanceIsOk);
    int heightRight = getHeight(node->right, balanceIsOk);
    if (heightLeft > heightRight) {
        *balanceIsOk = abs(heightLeft - heightRight) < 2;
    }
    else {
        *balanceIsOk = abs(heightRight - heightLeft) < 2;
    }
    return (heightLeft > heightRight) ? heightLeft : heightRight + 1;
}

bool isBalanced(Tree* tree) {
    bool balanceIsOk = true;
    int height = getHeight(tree->root, &balanceIsOk);
    return balanceIsOk;
}

char* intToString(int number) {
    char result[10] = { '\0' };
    int numberLength = 0;
    while (number > 0) {
        result[numberLength] = (number % 10) + '0';
        ++numberLength;
        number /= 10;
    }
    result[numberLength] = '\0';
    char temp = 0;
    for (int i = 0; i < numberLength / 2; ++i) {
        temp = result[i];
        result[i] = result[numberLength - 1 - i];
        result[numberLength - 1 - i] = temp;
    }
    return &result[0];
}

bool tests(void) {
    Tree* tree = createTree();
    if (tree == NULL) {
        return false;
    }
    if (addValue(tree, "cdef", "root") != ok) {
        deleteTree(&tree);
        return false;
    }
    if (addValue(tree, "bcd", "rootLSon") != ok) {
        deleteTree(&tree);
        return false;
    }
    if (addValue(tree, "rs", "rootRSon") != ok) {
        deleteTree(&tree);
        return false;
    }
    if (addValue(tree, "aaaa", "LLSon") != ok) {
        deleteTree(&tree);
        return false;
    }
    if (addValue(tree, "bdder", "LRSon") != ok) {
        deleteTree(&tree);
        return false;
    }
    if (strcmp(getValue(tree, "aaaa"), "LLSon") != 0 || !isKeyInTree(tree, "cdef") || isKeyInTree(tree, "root")) {
        deleteTree(&tree);
        return false;
    }
    if (addValue(tree, "hgv", "RLSon") != ok) {
        deleteTree(&tree);
        return false;
    }
    if (addValue(tree, "zzzzzz", "RRSon") != ok) {
        deleteTree(&tree);
        return false;
    }
    if (addValue(tree, "efg", "RLL") != ok) {
        deleteTree(&tree);
        return false;
    }
    if (addValue(tree, "ddddddd", "root") != ok) {
        deleteTree(&tree);
        return false;
    }
    if (!isBalanced(tree)) {
        deleteTree(&tree);
        return false;
    }
    deleteTree(&tree);
    Tree* newTree = createTree();
    for (int i = 0; i < 100000; ++i) {
        char* temp = intToString(i);
        if (addValue(newTree, temp, "a") != ok) {
            deleteTree(&newTree);
            return false;
        }
    }
    if (!isBalanced(newTree)) {
        deleteTree(&newTree);
        return false;
    }
    deleteTree(&newTree);
    return true;
}

