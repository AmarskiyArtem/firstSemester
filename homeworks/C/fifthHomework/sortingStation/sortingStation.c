#pragma once
#include "../stack/stack.h"
#include <stdio.h>
#include <string.h>
#define maxMathExpressionLength 1000

void postfixToInfix(char* InfixExpression, char* postfixExpression, int* errorCode) {
    
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
    char mathExpressionInPostfixForm[maxMathExpressionLength] = { 0 };
    postfixToInfix(&mathExpressionInInfixForm[0], &mathExpressionInPostfixForm[0], &errorCode);
    if (errorCode != 0) {
        printf("Incorrect math expression");
    }
    else {
        printf("Infix form: %s", mathExpressionInInfixForm);
    }
}