#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* head;
} Stack;

Stack* createStack(void) {
    Stack* stack = malloc(sizeof(Node));
    if (stack == NULL) {
        return NULL;
    }
    stack->head = NULL;
    return stack;
}

ErrorCode push(Stack* stack, int value) {
    Node* temp = malloc(sizeof(Node));
    if (temp == NULL) {
        return memoryAllocationError;
    }
    temp->value = value;
    temp->next = stack->head;
    stack->head = temp;
    return ok;
}

int top(Stack* stack, ErrorCode* errorCode) {
    *errorCode = ok;
    if (isEmpty(stack)) {
        *errorCode = stackIsEmpty;
        return 0;
    }
    return stack->head->value;
}

ErrorCode pop(Stack* stack) {
    if (stack->head == NULL) {
        return stackIsEmpty;
    }
    Node* next = stack->head->next;
    free(stack->head);
    stack->head = next;
    return ok;
}

bool isEmpty(Stack* stack) {
    return stack->head == NULL;
}

void deleteStack(Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
    free(stack);
}

bool tests(void) {
    Stack* testStack = createStack();
    if (testStack == NULL) {
        return false;
    }
    if (!isEmpty(testStack)) {
        deleteStack(testStack);
        return false;
    }
    if (push(testStack, 10) != 0) {
        deleteStack(testStack);
        return false;
    }
    if (testStack->head->value != 10 || top(testStack) != 10) {
        deleteStack(testStack);
        return false;
    }
    if (push(testStack, 20)) {
        deleteStack(testStack);
        return false;
    }
    if (testStack->head->value != 20 || top(testStack) != 20 || testStack->head->next->value != 10) {
        deleteStack(testStack);
        return false;
    }
    if (pop(testStack) != 0) {
        deleteStack(testStack);
        return false;
    }
    if (top(testStack) != 10) {
        deleteStack(testStack);
        return false;
    }
    deleteStack(testStack);
    return true;
}