#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int number) {
    if (number < 2) {
        return false;
    }
    for (int i = 2; i < sqrt(number + 1); ++i) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

void printAllPrimes(int number) {
    if (number < 2) {
        printf("No primes numbers before %d", number);
    }
    for (int i = 0; i <= number; ++i) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }
}

bool test(void) {
    return isPrime(2) && isPrime(997) && !isPrime(1) && !isPrime(14);
}

void main(void) {
    if (!test()) {
        printf("tests failed");
        return;
    }
    int number = 0;
    printf("Input a number\n");
    scanf_s("%d", &number);
    printAllPrimes(number);
}