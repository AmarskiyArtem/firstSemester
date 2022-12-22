#include <stdio.h>

#include "stateMachine.h"

void main(void) {
    if (!tests()) {
        printf("tests failed");
        return;
    }
    const char string[] = "AMARSKIY@GMAIL.C";
    printf("%s ", string);
    printf(isCorrectRegularExpression(&string[0]) ? "valid regular expression" : "invalid regular expression");
}