#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int number) {
    int originalNumber = number;
    int reverseNumber = 0;
    while (number > 0) {
        reverseNumber = reverseNumber * 10 + number % 10;
        number /= 10;
    }
    return originalNumber == reverseNumber;
}

bool tests(void) {
    return isPalindrome(1001) && isPalindrome(12321) && !isPalindrome(123432)
        && !isPalindrome(12412);
}

void main(void) {
    if (!tests()) {
        printf("tests failed");
        return;
    }
    printf("Input a number:\n");
    int number = 0;
    scanf_s("%d", &number);
    isPalindrome(number) ? printf("%d is palindome", number) : printf("%d not a palindome", number);
}