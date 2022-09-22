#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

//начиная с 37 числа уже заметна разница между рекурсивным и итеративным решением, начиная с 40 разница составляет уже несколько секунд
int recursiveFibonacci(int nFibonacciNumber) {
    if (nFibonacciNumber < 3) {
        return 1;
    }
    return recursiveFibonacci(nFibonacciNumber - 1) + recursiveFibonacci(nFibonacciNumber - 2);
}

//47-е число уже не влазит в инт
int iterativeFibonacci(int nFibonacciNumber) {
    if (nFibonacciNumber < 3) {
        return 1;
    }
    int currentFibonacciNumber = 2;
    int fibonacciArray[2] = { 1, 1 };
    for (int i = 3; i < nFibonacciNumber; ++i) {
        fibonacciArray[0] = fibonacciArray[1];
        fibonacciArray[1] = currentFibonacciNumber;
        currentFibonacciNumber = fibonacciArray[0] + fibonacciArray[1];
    }
    return currentFibonacciNumber;
}

//блок тестов
bool recursiveFibonacciTest(void) {
    return (recursiveFibonacci(7) == 13) && (recursiveFibonacci(-1) == 1) && (recursiveFibonacci(1) == 1) && (recursiveFibonacci(2) == 1);
}

bool iterativeFibonacciTest(void) {
    return (iterativeFibonacci(7) == 13) && (iterativeFibonacci(-1) == 1) && (iterativeFibonacci(1) == 1) && (iterativeFibonacci(2) == 1);
}


bool functionsEquality(void) {
    for (int i = 0; i < 30; ++i) {
        if (recursiveFibonacci(i) != iterativeFibonacci(i)) {
            return false;
        }
    }
    return true;
}
//блок тестов закончился


void main() {
    setlocale(LC_ALL, "RU");
    if (recursiveFibonacciTest() == false) {
        printf("ААААААА ПАНИКА НЕ РАБОТАЕТ ПЕРВЫЙ ТЕСТ");
        return;
    }
    if (iterativeFibonacciTest() == false) {
        printf("ААААААА ПАНИКА НЕ РАБОТАЕТ ВТОРОЙ ТЕСТ");
        return;
    }
    if (functionsEquality() == false) {
        printf("ААААААА ПАНИКА НЕ РАБОТАЕТ ТРЕТИЙ ТЕСТ");
        return;
    }
    int fibonacciNumber = 0;
    printf("Введите номер числа\n");
    scanf_s("%d", &fibonacciNumber);
    printf("%d-е число Фибоначчи = %d", fibonacciNumber, iterativeFibonacci(fibonacciNumber));
    //printf("%d-е число Фибоначчи = %d", fibonacciNumber, recursiveFibonacci(fibonacciNumber));
}