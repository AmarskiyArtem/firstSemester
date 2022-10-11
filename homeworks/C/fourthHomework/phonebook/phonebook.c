#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

void main() {
    setlocale(LC_ALL, "RU");
    bool isContinue = true;
    while (isContinue) {
        int currentAction = 0;
        printf("Введите действие\n");
        scanf_s("%d", &currentAction);
        switch (currentAction) {
        case 0:
        {
            isContinue = false;
            break;
        }
        case 1: 
        {
            break;
        }
        case 2:
        {
            break;
        }
        case 3:
        {
            break;
        }
        case 4:
        {
            break;
        }
        case 5:
        {
            break;
        }
        default:
            printf("Неверный формат ввода\n");
            break;
        }
    }
}