#pragma once
#include "stack.h"
#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define maxBracketsStringLength 100

bool balanceChecker(int length, char string[maxBracketsStringLength]) {
    if (length % 2 == 1) {
        return false;
    }
    Stack* stack = createStack();
    if (stack == NULL) {
        printf("MEMORY PANIC");
        return false;
    }
    for (int i = 0; i < length; ++i) {
        if (string[i] == '{' || string[i] == '(' || string[i] == '[') {
            push(stack, string[i]);
        }
        else {
            if (isEmpty(stack)) {
                return false;
            }
            else {
                char openBracket = top(stack);
                if ((openBracket == '(' && string[i] == ')') || (openBracket == '{' && string[i] == '}') ||
                    (openBracket == '[' && string[i] == ']')) {
                    pop(stack);
                }
                else {
                    return false;
                }
            }
        }
    }
    if (isEmpty(stack)) {
        return true;
    }
    deleteStack(stack);
    return false;
}

void main() {
    setlocale(LC_ALL, "RU");
    printf("Введите длину скобочной последовательности:\n");
    int bracketsStringLength = 0;
    scanf_s("%d", &bracketsStringLength);
    if (bracketsStringLength <= 0) {
        printf("Верная скобочная последовательность");
        return;
    }
    printf("Введите скобочную последовательность:\n");
    char bracketsString[maxBracketsStringLength] = { 0 };
    scanf_s("%100s", bracketsString, (unsigned)sizeof(bracketsString));
    bool result = balanceChecker(bracketsStringLength, bracketsString);
    result ? printf("Верная скобочная последовательность") : printf("Неверная скобочная последовательность");
}