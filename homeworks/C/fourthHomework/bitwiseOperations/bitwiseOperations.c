#include <stdio.h>
#include <locale.h>

const int sizeOfArrayWithBinaryNumber = sizeof(char) * 8;

void arrayPrint(int* array, int arraySize) {
    for (int i = 0; i < arraySize; ++i) {
        printf("%d ", array[i]);
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

void main() {
    setlocale(LC_ALL, "RU");
    printf("Введите число:\n");
    int number = 0;
    scanf_s("%d", &number);
    int binaryNumber[8] = { 0 };
    binaryConverter(&binaryNumber[0], number);
    printf("Число в двоичном представлении: \n");
    arrayPrint(&binaryNumber[0], sizeOfArrayWithBinaryNumber);
}