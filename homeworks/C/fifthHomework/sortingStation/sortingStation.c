#pragma once
#include <stdio.h>
#include <string.h>

#include "../stack/stack.h"

#define MAX_MATH_EXPRESSION_LENGTH 1000


bool isCorrectMathExpression(char* expression) {
    char correctSymbols[] = " 0123456789+-*/()";
    for (int i = 0; i < strlen(expression) - 1; ++i) {
        if (strchr(correctSymbols, expression[i]) == NULL) {
            return false;
        }
    }
    return true;
}

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

void infixToPostfix(char* infixExpression, char* postfixExpression, int* errorCode) {
    *errorCode = 0;
    if ((!isCorrectMathExpression(infixExpression)) || (strlen(infixExpression) - 1 == 0)) {
        *errorCode = -3;
        return false;
    }
    Stack* stack = createStack();
    if (stack == NULL) {
        *errorCode = -2;
        return;
    }
    int postfixIndex = 0;
    char numbers[] = "0123456789";
    char operations[] = "+-*/";
    for (int i = 0; i < strlen(infixExpression); ++i) {
        if (strchr(numbers, infixExpression[i]) != NULL) {
            postfixExpression[postfixIndex++] = infixExpression[i];
            postfixExpression[postfixIndex++] = ' ';
            continue;
        }
        if (infixExpression[i] == '(') {
            push(stack, infixExpression[i]);
            continue;
        }
        if (infixExpression[i] == ')') {
            while (!isEmpty(stack) && top(stack) != '(') {
                postfixExpression[postfixIndex++] = top(stack);
                postfixExpression[postfixIndex++] = ' ';
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
        if (strchr(operations, infixExpression[i]) != NULL) {
            int currentPriority = operationsPriory(infixExpression[i]);
            while ((!isEmpty(stack)) && (operationsPriory(top(stack)) >= currentPriority)) {
                postfixExpression[postfixIndex++] = top(stack);
                postfixExpression[postfixIndex++] = ' ';
                pop(stack);
            }
            push(stack, infixExpression[i]);
        }
    }
    if (!isEmpty(stack)) {
        postfixExpression[postfixIndex++] = top(stack);
        pop(stack);
        postfixExpression[postfixIndex] = '\0';
    }
    else {
        *errorCode = -1;
    }
    if (!isEmpty(stack)) {
        *errorCode = -1;
    }
    postfixExpression[postfixIndex] = '\0';
    deleteStack(stack);
}

bool tests(void) {
    char testOne[] = "(5 + 3)*(1 +2)";
    char testTwo[] = "(3 + 4";
    char testThree[] = "7 - 8)";
    char testFour[] = "4 - 2*8 / 6 + 1";
    char resultOne[MAX_MATH_EXPRESSION_LENGTH] = { 0 };
    char resultTwo[MAX_MATH_EXPRESSION_LENGTH] = { 0 };
    char resultThree[MAX_MATH_EXPRESSION_LENGTH] = { 0 };
    char resultFour[MAX_MATH_EXPRESSION_LENGTH] = { 0 };
    int errorCodeOne = 0;
    int errorCodeTwo = 0;
    int errorCodeThree = 0;
    int errorCodeFour = 0;
    infixToPostfix(&testOne[0], &resultOne[0], &errorCodeOne);
    infixToPostfix(&testTwo[0], &resultTwo[0], &errorCodeTwo);
    infixToPostfix(&testThree[0], &resultThree[0], &errorCodeThree);
    infixToPostfix(&testFour[0], &resultFour[0], &errorCodeFour);
    return strcmp(&resultOne[0], "5 3 + 1 2 + *") == 0 && errorCodeTwo != 0 && errorCodeThree != 0
        && strcmp(&resultFour[0], "4 2 8 * 6 / - 1 +") == 0;
}

void main() {
    if (!tests()) {
        printf("tests failed");
        return;
    }
    printf("Enter the math expression in infix form:\n");
    char mathExpressionInInfixForm[MAX_MATH_EXPRESSION_LENGTH] = { 0 };
    fgets(mathExpressionInInfixForm, MAX_MATH_EXPRESSION_LENGTH, stdin);
    int errorCode = 0;
    char mathExpressionInPostfixForm[MAX_MATH_EXPRESSION_LENGTH] = { 0 };
    infixToPostfix(&mathExpressionInInfixForm[0], &mathExpressionInPostfixForm[0], &errorCode);
    errorCode != 0 ? printf("Incorrect math expression") : printf("Postfix form: %s", mathExpressionInPostfixForm);
}