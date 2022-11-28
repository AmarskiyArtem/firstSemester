#pragma once
#include <stdio.h>
#include <string.h>

#include "../stack/stack.h"

#define MAX_MATH_EXPRESSION_LENGTH 1000

bool isCorrectMathExpression(char* expression) {
    char correctSymbols[] = " 0123456789+-*/";
    for (int i = 0; i < strlen(expression) - 1; ++i) {
        if (strchr(correctSymbols, expression[i]) == NULL) {
            return false;
        }
    }
    return true;
}

int postfixCalc(char* expression, int *errorCode) {
    *errorCode = 0;
    int result = 0;
    if (!isCorrectMathExpression(expression) || strlen(expression) - 1 == 0) {
        *errorCode = -1;
        return result;
    }
    Stack* stack = createStack();
    if (stack == NULL) {
        *errorCode = -1;
        return result;
    }
    char numbers[] = "0123456789";
    char operations[] = "+-*/";
    for (int i = 0; i < strlen(expression) - 1; ++i) {
        if (strchr(numbers, expression[i]) != NULL) {
            push(stack, expression[i]-'0');
        }
        if (strchr(operations, expression[i]) != NULL) {
            int firstValue = 0;
            int secondValue = 0;
            if (!isEmpty(stack)) {
                secondValue = top(stack);
                pop(stack);
            }
            else {
                *errorCode = -1;
                deleteStack(stack);
                return result;
            }
            if (!isEmpty(stack)) {
                firstValue = top(stack);
                pop(stack);
            }
            else {
                *errorCode = -1;
                deleteStack(stack);
                return result;
            }
            switch (expression[i]) {
                case '+': {
                    push(stack, firstValue + secondValue);
                    break;
                }
                case '-': {
                    push(stack, firstValue - secondValue);
                    break;
                }
                case '*': {
                    push(stack, firstValue * secondValue);
                    break;
                }
                case '/': {
                    push(stack, firstValue / secondValue);
                    break;
                }
            }
        }
    }
    result = top(stack);
    pop(stack);
    if (!isEmpty(stack)) {
        *errorCode = -1;
    }
    deleteStack(stack);
    return result;
}

bool tests(void) {
    int testErrorCode = 0;
    int testResult = postfixCalc("5 g +", &testErrorCode);
    if (testErrorCode == 0) {
        return false;
    }
    testResult = postfixCalc("5 7 + 3 * 4 / ", &testErrorCode);
    if (testErrorCode != 0 || testResult != 9) {
        return false;
    }
    return true;
}

void main() {
    if (!tests()) {
        printf("Tests failed\n");
        return;
    }
    printf("Enter the math expression:\n");
    char mathExpression[MAX_MATH_EXPRESSION_LENGTH] = { 0 };
    fgets(mathExpression, MAX_MATH_EXPRESSION_LENGTH, stdin);
    int errorCode = 0;
    int result = postfixCalc(&mathExpression[0], &errorCode);
    errorCode != 0 ? printf("Incorrect math expression") : printf("Expression result is %d", result);
}