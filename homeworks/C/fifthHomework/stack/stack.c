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

int push(Stack* stack, int value) {
    Node* temp = malloc(sizeof(Node));
    if (temp == NULL) {
        printf("MEMORY PANICCC");
        return -1;
    }
    temp->value = value;
    temp->next = stack->head;
    stack->head = temp;
    return 0;
}

int top(Stack* stack) {
    return stack->head->value;
}

int pop(Stack* stack) {
    if (stack->head == NULL) {
        return -1;
    }
    Node* head = stack->head;
    stack->head = stack->head->next;
    free(head);
    return 0;
}

bool isEmpty(Stack* stack) {
    return stack->head == NULL;
}

void deleteStack(Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
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