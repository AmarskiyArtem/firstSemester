#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#define ARRAY_SIZE 256

void countOfRepetition(FILE* file, int* numberOfRepetition) {
    while (!feof(file)) {
        int k = fgetc(file);
        ++numberOfRepetition[k];
    }
}

int testArray[ARRAY_SIZE] = { 0 };
bool tests(void) {
    FILE* testFile = fopen("test.txt", "r");
    if (testFile == NULL) {
        printf("Файл не найден");
        return false;
    }
    countOfRepetition(testFile, &testArray);
    if (testArray[97] == 1 && testArray[111] == 1 && testArray[98] == 2) {
        return true;
    }
    return false;
}

int numberOfRepetition[ARRAY_SIZE] = { 0 };
void main() {
    setlocale(LC_ALL, "RU");
    if (!tests()) {
        printf("Тесты не прошли");
        return;
    }
    FILE* file = fopen("result.txt", "r");
    if (file == NULL) {
        printf("Файл не найден");
        return;
    }
    countOfRepetition(file, &numberOfRepetition);
    fclose(file);
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (numberOfRepetition[i] > 0) {
            if (i == '\n') {
                printf("Перенос на следующую строку встречается %d раз\n", numberOfRepetition[i]);
                continue;
            }
            if (i == '\t') {
                printf("Знак табуляции встречается %d раз\n", numberOfRepetition[i]);
                continue;
            }
            if (i == '\b') {
                printf("Знак bip (это же так называется?) встречается %d раз\n", numberOfRepetition[i]);
                continue;
            }
            printf("Символ %c встречается %d раз(a)\n", i, numberOfRepetition[i]);
        }
    }
}