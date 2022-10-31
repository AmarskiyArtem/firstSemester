#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#define sizeOfArrayWithBinaryNumber sizeof(int) * 8

void arrayPrint(int* array, int arraySize) {
    for (int i = 0; i < arraySize; ++i) {
        printf("%d", array[i]);
    }
}

void binaryConverter(int* binaryNumber, int number) {
    int bitChecker = 1;
    for (int i = sizeOfArrayWithBinaryNumber - 1; i >= 0; --i) {
        binaryNumber[i] = (number & bitChecker) ? 1 : 0;
        bitChecker = bitChecker << 1;
    }
}

int decimalConverter(int* binaryNumber) {
    int number = 0;
    int power = 1;
    for (int i = sizeOfArrayWithBinaryNumber - 1; i >= 0; --i) {
        number += binaryNumber[i] * power;
        power *= 2;
    }
    return number;
}
void sumOfTwoBinaryNumbers(int* firstNumber, int* secondNumber, int* sumResult) {
    int extraUnit = 0;
    for (int i = sizeOfArrayWithBinaryNumber - 1; i >= 0; --i) {
        int currentSum = firstNumber[i] + secondNumber[i] + extraUnit;
        sumResult[i] = (currentSum) % 2;
        extraUnit = (currentSum) / 2;
    }
}

bool converterTest(void) {
    int number[sizeOfArrayWithBinaryNumber] = { 0 };
    binaryConverter(&number[0], 5);
    return (number[sizeOfArrayWithBinaryNumber - 1] == 1) && (number[sizeOfArrayWithBinaryNumber - 2] == 0) 
        && (number[sizeOfArrayWithBinaryNumber - 3] == 1);
}

bool decimalTest(void) {
    int number[sizeOfArrayWithBinaryNumber] = { 0 };
    binaryConverter(&number[0], 10);
    return (decimalConverter(&number[0]) == 10);
}
bool tests(void) {
    return converterTest() && decimalTest();
}

void main() {
    setlocale(LC_ALL, "RU");
    if (!tests()) {
        printf("Тесты не робят");
        return;
    }
    printf("Введите первое число:\n");
    int firstNumber = 0;
    scanf_s("%d", &firstNumber);
    printf("Введите второе число:\n");
    int secondNumber = 0;
    scanf_s("%d", &secondNumber);

    int firstBinaryNumber[sizeOfArrayWithBinaryNumber] = { 0 };
    binaryConverter(&firstBinaryNumber[0], firstNumber);
    int secondBinaryNumber[sizeOfArrayWithBinaryNumber] = { 0 };
    binaryConverter(&secondBinaryNumber[0], secondNumber);
    printf("Первое число в двоичном представлении:\n");
    arrayPrint(&firstBinaryNumber[0], sizeOfArrayWithBinaryNumber);
    printf("\nВторое число в двоичном представлении:\n");
    arrayPrint(&secondBinaryNumber[0], sizeOfArrayWithBinaryNumber);

    int resultOfSumOfBinaryNumbers[sizeOfArrayWithBinaryNumber] = { 0 };
    sumOfTwoBinaryNumbers(&firstBinaryNumber[0], &secondBinaryNumber[0], &resultOfSumOfBinaryNumbers[0]);
    printf("\nИх сумма в двоичном представлении:\n");
    arrayPrint(&resultOfSumOfBinaryNumbers[0], sizeOfArrayWithBinaryNumber);
    int decimalResult = decimalConverter(&resultOfSumOfBinaryNumbers[0]);
    printf("\nВ десятичном:\n%d", decimalResult);
}