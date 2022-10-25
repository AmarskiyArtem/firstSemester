#pragma once
#include "../stack/stack.h"
#include <stdio.h>
#include <string.h>
#define maxMathExpressionLength 1000

int postfixCalc(char expression[maxMathExpressionLength], int *errorCode) {
    *errorCode = 0;
    int result = 0;
    Stack* stack = createStack();
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
                return result;
            }
            if (!isEmpty(stack)) {
                firstValue = top(stack);
                pop(stack);
            }
            else {
                *errorCode = -1;
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
        deleteStack(stack);
        return result;
    }
    deleteStack(stack);
    return result;
}

bool expressionChecker(char expression[maxMathExpressionLength]) {
    char correctSymbols[] = " 0123456789+-*/";
    for (int i = 0; i < strlen(expression) - 1; ++i) {
        if (strchr(correctSymbols, expression[i]) == NULL) {
            printf("%c", expression[i]);
            return false;
        }
    }
    return true;
}
void main() {
    printf("Enter the math expression:\n");
    char mathExpression[maxMathExpressionLength] = { 0 };
    fgets(mathExpression, maxMathExpressionLength, stdin);
    if ((!expressionChecker(mathExpression)) || (strlen(mathExpression) - 1 == 0)) {
        printf("Incorrect math expression");
        return;
    }
    int errorCode = 0;
    int result = postfixCalc(mathExpression, &errorCode);
    if (errorCode != 0) {
        printf("Incorrect math expression");
    }
    else {
        printf("Expression result is %d", result);
    }
}