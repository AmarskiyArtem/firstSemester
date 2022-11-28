﻿#pragma once
#include "../stack/stack.h"
#include <stdio.h>
#include <string.h>
#define maxMathExpressionLength 1000

int operationsPriory(char operation) {
    switch (operation) {
    case '+':
    case '-': {
        return 1;
    }
    case '(': {
        return 0;
    }
    default: {
        return 2;
    }
    }
}

void postfixToInfix(char postfixExpression[maxMathExpressionLength], char* infixExpression, int* errorCode) {
    *errorCode = 0;
    Stack* stack = createStack();
    if (stack == NULL) {
        *errorCode = -2;
        return;
    }
    int infixIndex = 0;
    char numbers[] = "0123456789";
    char operations[] = "+-*/";
    for (int i = 0; i < strlen(postfixExpression); ++i) {
        if (strchr(numbers, postfixExpression[i]) != NULL) {
            infixExpression[infixIndex++] = postfixExpression[i];
            infixExpression[infixIndex++] = ' ';
            continue;
        }
        if (postfixExpression[i] == '(') {
            push(stack, postfixExpression[i]);
            continue;
        }
        if (postfixExpression[i] == ')') {
            while (!isEmpty(stack) && top(stack) != '(') {
                infixExpression[infixIndex++] = top(stack);
                infixExpression[infixIndex++] = ' ';
                pop(stack);
            }
            if (isEmpty(stack)) {
                *errorCode = -1;
                deleteStack(stack);
                return;
            }
            pop(stack);
            continue;
        }
        if (strchr(operations, postfixExpression[i]) != NULL) {
            int currentPriority = operationsPriory(postfixExpression[i]);
            while ((!isEmpty(stack)) && (operationsPriory(top(stack)) >= currentPriority)) {
                infixExpression[infixIndex++] = top(stack);
                infixExpression[infixIndex++] = ' ';
                pop(stack);
            }
            push(stack, postfixExpression[i]);
        }
    }
    if (!isEmpty(stack)) {
        infixExpression[infixIndex++] = top(stack);
        pop(stack);
        infixExpression[infixIndex] = '\0';
    }
    else {
        *errorCode = -1;
    }
    if (!isEmpty(stack)) {
        *errorCode = -1;
    }
    infixExpression[infixIndex] = '\0';
    deleteStack(stack);
}

bool expressionChecker(char expression[maxMathExpressionLength]) {
    char correctSymbols[] = " 0123456789+-*/()";
    for (int i = 0; i < strlen(expression) - 1; ++i) {
        if (strchr(correctSymbols, expression[i]) == NULL) {
            printf("%c", expression[i]);
            return false;
        }
    }
    return true;
}

void main() {
    printf("Enter the math expression in postfix form:\n");
    char mathExpressionInPostfixForm[maxMathExpressionLength] = { 0 };
    fgets(mathExpressionInPostfixForm, maxMathExpressionLength, stdin);
    if ((!expressionChecker(mathExpressionInPostfixForm)) || (strlen(mathExpressionInPostfixForm) - 1 == 0)) {
        printf("Incorrect math expression");
        return;
    }
    int errorCode = 0;
    char mathExpressionInInfixForm[maxMathExpressionLength] = { 0 };
    postfixToInfix(mathExpressionInPostfixForm,&mathExpressionInInfixForm[0], &errorCode);
    if (errorCode != 0) {
        printf("Error code problem\n");
        printf("Incorrect math expression\n"); 
    }
    else {
        printf("Infix form: %s", mathExpressionInInfixForm);
    }
}