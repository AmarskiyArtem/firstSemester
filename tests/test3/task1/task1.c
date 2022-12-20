#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INT_SIZE 10

bool isCorrectBinaryNumber(char* number) {
    int stringLength = strlen(number) - 1;
    char correctSymbols[] = "01";
    for (int i = 0; i < stringLength; ++i) {
        if (strchr(correctSymbols, number[i]) == NULL) {
            return false;
        }
    }
    return true;
}

char* intToString(int number) {
    char* result = calloc(MAX_INT_SIZE, sizeof(char));
    if (result == NULL) {
        return NULL;
    }
    int numberLength = 0;
    while (number > 0) {
        result[numberLength] = (number % 10) + '0';
        ++numberLength;
        number /= 10;
    }
    result[numberLength] = '\0';
    char temp = 0;
    for (int i = 0; i < numberLength / 2; ++i) {
        temp = result[i];
        result[i] = result[numberLength - 1 - i];
        result[numberLength - 1 - i] = temp;
    }
    return result;
}

char* binaryToDecimal(char* binaryNumber) {
    int number = 0;
    int pow = 1;
    int binaryNumberLength = strlen(binaryNumber) - 1;
    for (int i = binaryNumberLength; i >= 0; --i) {
        if (binaryNumber[i] == '1') {
            number += pow;
        }
        pow *= 2;
    }
    return intToString(number); 
}

bool tests(void) {
    char testNumberOne[] = "101010";
    char testNumberTwo[] = "11111111";
    char* resultOne = binaryToDecimal(&testNumberOne[0]);
    char* resultTwo = binaryToDecimal(&testNumberTwo[0]);
    if (resultOne == NULL || resultTwo == NULL
        || strcmp(resultOne, "42") != 0 || strcmp(resultTwo, "255") != 0) {
        free(resultOne);
        free(resultTwo);
        return false;
    }
    free(resultOne);
    free(resultTwo);
    return true;
}

void main(void) {
    if (!tests()) {
        printf("tests failed");
        return;
    }
    char binaryNumber[] = "11110011001010";
    if (!isCorrectBinaryNumber(&binaryNumber[0])) {
        printf("%s is incorrect binary number", binaryNumber);
        return;
    }
    char* result = binaryToDecimal(&binaryNumber[0]);
    if (result == NULL) {
        printf("Memory allocation error");
        return;
    }
    printf("Number in binary: %s\nIn decimal: %s", binaryNumber, result);
    free(result);
}