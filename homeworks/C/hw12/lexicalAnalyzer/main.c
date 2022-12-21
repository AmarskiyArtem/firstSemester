#include <stdio.h>

#include "lexicalAnalyzer.h"

#define MAX_STRING_LENGTH 100

bool tests(void) {
    return !isNumber("345E+2.3") && isNumber("24.5E+1") && !isNumber("35.2+2");
}

void main(void) {
    if (!tests()) {
        printf("Tests failed");
        return;
    }
    printf("Input string:\n");
    char string[MAX_STRING_LENGTH] = { 0 };
    scanf_s("%100s", &string, (unsigned)sizeof(string));
    printf(isNumber(&string[0]) ? "Is number" : "Not a number");
}