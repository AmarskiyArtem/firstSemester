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
            push(stack, expression[i] - '0');
        }
        if (strchr(operations, expression[i]) != NULL) {
            int firstValue = 0;
            int secondValue = 0;
            ErrorCode stackErrorCode = ok;
            secondValue = top(stack, &stackErrorCode);
            if (stackErrorCode == ok) {
                pop(stack);
            }
            else {
                *errorCode = -1;
                deleteStack(stack);
                return result;
            }
            
            firstValue = top(stack, &stackErrorCode);
            if (stackErrorCode == ok) {
                pop(stack);
            }
            else {
                *errorCode = -1;
                deleteStack(stack);
                return result;
            }

            switch (expression[i]) {
                case '+': {
                    if (push(stack, firstValue + secondValue) != ok) {
                        deleteStack(stack);
                        *errorCode = -1;
                        return result;
                    }
                    break;
                }
                case '-': {
                    if (push(stack, firstValue - secondValue) != ok) {
                        deleteStack(stack);
                        *errorCode = -1;
                        return result;
                    }
                    break;
                }
                case '*': {
                    if (push(stack, firstValue * secondValue) != ok) {
                        deleteStack(stack);
                        *errorCode = -1;
                        return result;
                    }
                    break;
                }
                case '/': {
                    if (secondValue == 0 || push(stack, firstValue / secondValue) != ok) {
                        deleteStack(stack);
                        *errorCode = -1;
                        return result;
                    }
                    break;
                }
            }
        }
    }
    ErrorCode stackErrorCode = ok;
    result = top(stack, &stackErrorCode);
    if (stackErrorCode != ok) {
        *errorCode = -1;
        deleteStack(stack);
        return result;
    }
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
    return testErrorCode == 0 && testResult == 9;
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