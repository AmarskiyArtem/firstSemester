#pragma once
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
    Node* next = stack->head->next;
    free(stack->head);
    stack->head = next;
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
