#pragma once
#include <stdbool.h>

typedef struct Stack Stack;

//create the stack, return NULL if problems with memory allocation
Stack* createStack();

//add element to head, return 0 if addition successful, -1 if not
int push(Stack* stack, int element);

//delete head element, return 0 if deletion successful, -1 if not
int pop(Stack* stack);

//check if stack empty
bool isEmpty(Stack* stack);

//delete the stack
void deleteStack(Stack* stack);

//return value of head element
int top(Stack* stack);

