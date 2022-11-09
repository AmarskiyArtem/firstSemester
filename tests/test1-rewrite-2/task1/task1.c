#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool isPalindrome(char* string, int stringLength) {
    if (strcmp(string, "") == 0) {
        return true;
    }
    for (int i = 0; i < stringLength / 2; ++i) {
        if (string[i] != string[stringLength - i - 1]) {
            return false;
        }
    }
    return true;
}


bool test1() {
    char string[6] = "abccba";
    return isPalindrome(string, 6);
}

bool test2() {
    char string[6] = "abcbca";
    return !isPalindrome(string, 6);
}

bool test3() {
    char* string = "";
    return isPalindrome(string, 0);
}


void main() {
    if (!(test1() && test2() && test3())) {
        printf("Test problems");
        return;
    }
    int stringLength = 0;
    int scanResult = 0;
    while (!scanResult && stringLength <= 0) {
        printf("Enter the length of the string: ");
        scanResult = scanf("%d", &stringLength);
        if (!scanResult) {
            printf("Number (>0) is required! Try again!");
            scanf("%*[^\n]");
        }
    }
    char* string = (char*)calloc(stringLength + 1, sizeof(char));
    if (string == NULL) {
        printf("problems with memory allocation");
        return;
    }
    printf("Enter the string: ");
    scanf("%s", string);
    if (isPalindrome(string, stringLength)) {
        free(string);
        printf("Your string is palindrome!\n");
        return;
    }
    printf("Your string is NOT palindrome!\n");
    free(string);
    return;
}