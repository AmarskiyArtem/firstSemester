#define _CRT_SECURE_NO_WARNINGS

#include "tree.h"

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

int stringToNumber(const char* string, int* index) {
    int result = 0;
    while (string[*index] >= '0' && string[*index] <= '9') {
        result = result * 10 + string[*index] - '0';
        ++(*index);
    }
    return result;
}

bool isOperation(const char symbol, const char nextSymbol) {
    if (strchr("+*/", symbol) != NULL) {
        return true;
    }
    if (symbol == '-') {
        return '9' - nextSymbol < 0 || nextSymbol - '0' < 0;
    }
    return false;
}

Tree* createTree(void) {
    Tree* tree = calloc(1, sizeof(Tree));
    return tree;
}

Node* fillTreeRecursive(const char* string, int* index, ErrorCode* errorCode) {
    if (*errorCode != ok) {
        return NULL;
    }
    int stringLength = strlen(string) - 1;
    ++(*index);
    while (*index != stringLength && strchr(" ()", string[*index]) != NULL) {
        ++(*index);
    }
    Node* newNode = calloc(1, sizeof(Node));
    if (newNode == NULL) {
        *errorCode = memoryAllocationError;
        return NULL;
    }
    if (isOperation(string[*index], string[*index + 1])) {
        newNode->operation = string[*index];
        newNode->left = fillTreeRecursive(string, index, errorCode);
        newNode->right = fillTreeRecursive(string, index, errorCode);
    }
    else {
        if (string[*index] == '-') {
            ++(*index);
            newNode->operand = -stringToNumber(string, index); ////!!!!!!!!
        }
        else {
            newNode->operand = stringToNumber(string, index);
        }
    }
    return newNode;
}

ErrorCode fillTree(Tree* tree, const char* string) {
    int index = -1;
    ErrorCode errorCode = ok;
    tree->root = fillTreeRecursive(string, &index, &errorCode);
    return errorCode;
}

int calculateRecursive(Node* node, ErrorCode* errorCode) {
    if (node->left == NULL && node->right == NULL) {
        return node->operand;
    }
    const int firstOperand = calculateRecursive(node->left, errorCode);
    const int secondOperand = calculateRecursive(node->right, errorCode);
    switch (node->operation) {
        case '+': {
            return firstOperand + secondOperand;
        }
        case '-': {
            return firstOperand - secondOperand;
        }
        case '/': {
            if (secondOperand == 0) {
                *errorCode = zeroDivision;
                return -1;
            }
            return firstOperand / secondOperand;
        }
        default: {
            return firstOperand * secondOperand;
        }
    }
}

int calculate(Tree* tree, ErrorCode* errorCode) {
    return calculateRecursive(tree->root, errorCode);
}

void deleteNodeAndAllChildren(Node* node) {
    if (node == NULL) {
        return;
    }
    deleteNodeAndAllChildren(node->left);
    deleteNodeAndAllChildren(node->right);
    free(node);
}

void deleteTree(Tree* tree) {
    deleteNodeAndAllChildren(tree->root);
    free(tree);
}

void printTreeRecursive(Node* node) {
    if (node->left == NULL && node->right == NULL)
    {
        printf("%d", node->operand);
        return;
    }
    printf("( %c ", node->operation);
    printTreeRecursive(node->left);
    printf(" ");
    printTreeRecursive(node->right);
    printf(" )");
}

ErrorCode printTree(Tree* tree) {
    if (isEmpty(tree)) {
        return treeIsEmpty;
    }
    printTreeRecursive(tree->root);
    return ok;
}