#pragma once
#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

#define MAX_BRACKET_STRING_LENGTH 100

bool isCorrectBracketSequence(int length, char* string) {
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

bool tests(void) {
    return !isCorrectBracketSequence(5, "({})[") && isCorrectBracketSequence(6, "[()]{}") &&
        isCorrectBracketSequence(4, "()()") && !isCorrectBracketSequence(6, "({[}])") &&
        !isCorrectBracketSequence(6, "{}}(){");
}

void main() {
    setlocale(LC_ALL, "RU");
    if (!tests()) {
        printf("Тесты упали");
        return;
    }
    printf("Введите длину скобочной последовательности:\n");
    int bracketsStringLength = 0;
    scanf_s("%d", &bracketsStringLength);
    if (bracketsStringLength <= 0) {
        printf("Верная скобочная последовательность");
        return;
    }
    printf("Введите скобочную последовательность:\n");
    char bracketsString[MAX_BRACKET_STRING_LENGTH] = { 0 };
    scanf_s("%100s", bracketsString, (unsigned)sizeof(bracketsString));
    bool result = isCorrectBracketSequence(bracketsStringLength, &bracketsString[0]);
    result ? printf("Верная скобочная последовательность") : printf("Неверная скобочная последовательность");
}