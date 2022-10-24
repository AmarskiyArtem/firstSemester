#pragma once
#include "../stack/stack.h"
#include <stdio.h>
#include <string.h>
#define maxMathExpressionLength 1000

//int postfixCalc(char expression[maxMathExpressionLength]) {
//    int result = 0;
//    char numbers[] = "0123456789";
//    char operations[] = "+-*/";
//    for (int i = 0; i < strlen(expression) - 1; ++i) {
//        if ()
//    }
//    return result;
//}

bool expressionChecker(char expression[maxMathExpressionLength]) {
    char correctSymbols[] = " 0123456789+-*/";
    for (int i = 0; i < strlen(expression) - 1; ++i) {
        if (strchr(correctSymbols, expression[i]) == NULL) {
            return false;
        }
    }
    return true;
}
void main() {
    char mathExpression[maxMathExpressionLength] = { 0 };
    fgets(mathExpression, maxMathExpressionLength, stdin);
    printf("%zd\n", strlen(mathExpression));
    if (!expressionChecker(mathExpression)) {
        printf("Incorrect math expression\n");
        return;
    }
}