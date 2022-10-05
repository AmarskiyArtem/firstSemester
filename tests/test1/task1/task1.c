#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

int betterSumOfHonestFibonacciNumbers(int rightBoard) {
    int result = 0;
    if (rightBoard < 3) {
        return result;
    }
    int currentFibonacciNumber = 2;
    int fibonacciArray[2] = { 1, 1 };
    for (int i = 0; true; ++i) {
        if (currentFibonacciNumber > rightBoard) {
            break;
        }
        if (currentFibonacciNumber % 2 == 0) {
            result += currentFibonacciNumber;
        }

        fibonacciArray[0] = fibonacciArray[1];
        fibonacciArray[1] = currentFibonacciNumber;
        currentFibonacciNumber = fibonacciArray[0] + fibonacciArray[1];
    }
    return result;
}

//первая версия реализации, каждый раз заново вычисляет число, кажется, это не очень хорошо
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

int sumOfHonestFibonacciNumbers(int rightBoard) {
    int result = 0;
    int currentFibonacciIndex = 1;
    while (true) {
        int currentFibonacciNumber = iterativeFibonacci(currentFibonacciIndex);
        if (currentFibonacciNumber > rightBoard) {
            break;
        }
        if (currentFibonacciNumber % 2 == 0) {
            result += currentFibonacciNumber;
        }
        ++currentFibonacciIndex;
    }
    return result;
}

bool tests(void) {
    if (sumOfHonestFibonacciNumbers(200) != 188) {
        printf("Первый тест не прошел");
        return false;
    }

    if (sumOfHonestFibonacciNumbers(15000) != 14328) {
        printf("Второй тест не прошел");
        return false;
    }

    if (sumOfHonestFibonacciNumbers(0) != 0) {
        printf("Третий тест не прошел");
        return false;
    }

    if (sumOfHonestFibonacciNumbers(10) != 10) {
        printf("Четвертый тест не прошел");
        return false;
    }
}

bool testsForBetterFunction(void) {
    if (betterSumOfHonestFibonacciNumbers(200) != 188) {
        printf("Первый тест не прошел");
        return false;
    }

    if (betterSumOfHonestFibonacciNumbers(15000) != 14328) {
        printf("Второй тест не прошел");
        return false;
    }

    if (betterSumOfHonestFibonacciNumbers(0) != 0) {
        printf("Третий тест не прошел");
        return false;
    }

    if (betterSumOfHonestFibonacciNumbers(10) != 10) {
        printf("Четвертый тест не прошел");
        return false;
    }
}

void main() {
    setlocale(LC_ALL, "RU");
    if (!tests()) {
        return;
    }
    if (!testsForBetterFunction()) {
        return;
    }
    printf("Сумма четных чисел Фибоначчи меньших миллиона = %d", betterSumOfHonestFibonacciNumbers(1000000));
}