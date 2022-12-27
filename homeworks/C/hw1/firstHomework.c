#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <math.h>
#include <string.h>

#define maxArrayLength 1000
#define maxStringLength 100

void swap(void)      //1st task
{
    int a = 0;
    int b = 0;
    printf("Введите число a\n");
    scanf_s("%d", &a);
    printf("Введите число b\n");
    scanf_s("%d", &b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("Переменные поменялись местами! Теперь a = %d b = %d \n", a, b);
}

void zeroElementsInArray(void)      //2nd task
{
    int arrayLength = 0;
    printf("Введите длину массива\n");
    scanf_s("%d", &arrayLength);
    int array[maxArrayLength] = { 0 };
    for (int i = 0; i < arrayLength; ++i)
    {
        printf("Введите %d элемент массива ", i + 1);
        scanf_s("%d", &array[i]);
    }
    int zeroCounter = 0;
    for (int i = 0; i < arrayLength; ++i)
    {
        if (array[i] == 0)
        {
            ++zeroCounter;
        }
    }
    printf("Нулевых элементов в массиве = %d \n", zeroCounter);
}

void division(void)     //3rd task
{
    int dividend = 0;
    int divisor = 0;
    printf("Введите делимое \n");
    scanf_s("%d", &dividend);
    printf("Введите делитель \n");
    scanf_s("%d", &divisor);

    if (divisor == 0)
    {
        printf("Деление на ноль detected, такое тут не любят\n");
        return;
    }
    if (dividend == 0)
    {
        printf("частное = 0, остаток = %d\n", divisor);
        return;
    }

    if (dividend > 0 && divisor > 0)
    {
        int quotient = 0;
        while (dividend - divisor >= 0)
        {
            ++quotient;
            dividend -= divisor;
        }
        printf("частное = %d, остаток = %d\n", quotient, dividend);
        return;
    }
    if (dividend > 0 && divisor < 0)
    {
        divisor *= -1;
        int quotient = 0;
        while (dividend - divisor >= 0)
        {
            ++quotient;
            dividend -= divisor;
        }
        printf("частное = %d, остаток = %d\n", -quotient, dividend);
        return;
    }
    if (dividend < 0 && divisor > 0)
    {
        int dividendClone = -dividend;
        int quotient = 0;
        while (dividendClone - divisor >= 0)
        {
            ++quotient;
            dividendClone -= divisor;
        }
        if (dividendClone == 0)
        {
            printf("частное = %d, остаток = 0\n", -quotient);
        }
        else
        {
            quotient = -quotient - 1;
            int remainder = dividend - divisor * quotient;
            printf("частное = %d, остаток = %d\n", quotient, remainder);
        }
        return;
    }
    if (dividend < 0 && divisor < 0)
    {
        int dividendClone = -dividend;
        int divisorClone = -divisor;
        int quotient = 0;
        while (dividendClone - divisorClone >= 0)
        {
            ++quotient;
            dividendClone -= divisorClone;
        }
        if (dividendClone == 0)
        {
            printf("частное = %d, остаток = 0\n", quotient);
        }
        else
        {
            ++quotient;
            int remainder = dividend - divisor * quotient;
            printf("частное = %d, остаток = %d\n", quotient, remainder);
        }
        return;
    }
}

void happyTickets(void)     //4th task
{
    int countOfAllPossibleSums[28] = { 0 };
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            for (int k = 0; k < 10; ++k)
            {
                ++countOfAllPossibleSums[i + j + k];
            }
        }
    }
    int numberOfTickets = 0;
    for (int i = 0; i < 28; ++i)
    {
        numberOfTickets += countOfAllPossibleSums[i] * countOfAllPossibleSums[i];
    }
    printf("Общее количество 6-ти значных счастливых билетов = %d\n", numberOfTickets);
}

void bracketsBalance(void)     //5th task
{
    int bracketsStringLength = 0;
    char bracketsString[maxStringLength];
    printf("Введите количество скобок (длину скобочной последовательности)\n");
    scanf_s("%d", &bracketsStringLength);
    printf("Введите последовательность скобок ");
    scanf_s("%100s", bracketsString, (unsigned)sizeof(bracketsString));

    if (bracketsStringLength % 2 == 1)
    {
        printf("Неверная скобочная последовательность\n");
        return;
    }
    int bracketsBalanceCounter = 0;
    for (int i = 0; i < bracketsStringLength; ++i)
    {
        if (bracketsString[i] == '\0')
        {
            break;
        }
        if (bracketsString[i] == '(')
        {
            ++bracketsBalanceCounter;
        }
        else
        {
            --bracketsBalanceCounter;
        }
    }
    if (bracketsBalanceCounter == 0)
    {
        printf("Верная скобочная последовательность\n");
    }
    else
    {
        printf("Неверная скобочная последовательность\n");
    }
}

bool isSimple(int x)       //extra func for 6th task
{
    if (x > 1)
    {
        for (int i = 2; i * i < (x + 1); ++i)
        {
            if (x % i == 0)
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
    return true;
}

void simpleNumbers(void)    //6th task
{
    int rightNumericalBorder = 0;
    printf("Введите число ");
    scanf_s("%d", &rightNumericalBorder);
    if (rightNumericalBorder <= 1)
    {
        printf("на промежутке от минус бесконечности до одного (включительно) простых чисел нет \n");
        return;
    }
    for (int i = 0; i <= rightNumericalBorder; ++i)
    {
        if (isSimple(i))
        {
            printf("%d ", i);
        }
    }
    printf("\nПростые числа кончились \n");
}

void substringEntryCounter(void)   //7th task
{
    char string[maxStringLength] = { "\0" };
    int stringLength = 0;
    char substring[maxStringLength] = { "\0" };
    int substringLength = 0;
    printf("Введите длину строки \n");
    scanf_s("%d", &stringLength);
    printf("Введите строку\n");
    scanf_s("%100s", &string, (unsigned)sizeof(string));
    printf("Введите длину подстроки \n");
    scanf_s("%d", &substringLength);
    printf("Введите подстроку\n");
    scanf_s("%100s", &substring, (unsigned)sizeof(substring));

    int entryCounter = 0;
    if (stringLength < substringLength || stringLength < 1)
    {
        printf("подстрока %s входит в строку %s %d раз\n", substring, string, entryCounter);
        return;
    }
    for (int i = 0; i < stringLength; ++i)
    {
        if (substring[0] == string[i])
        {
            bool isGood = true;
            for (int j = 0; j < substringLength; ++j)
            {
                if (string[i + j] != substring[j])
                {
                    isGood = false;
                    break;
                }
            }
            if (isGood)
            {
                ++entryCounter;
            }
        }
    }
    printf("подстрока %s входит в строку %s %d раз(a)\n", substring, string, entryCounter);
}

void swapVar(int* a, int* b) {
    if (a == b) {
        return;
    }
    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *a ^ *b;
}

void swapElements(int* array, int border) {
    for (int i = 0; i < border / 2; ++i) {
        swapVar(&array[i], &array[border - i - 1]);
    }
}

void partSwapArray(void)  //8th task
{
    int m = 0;
    int n = 0;
    int array[maxArrayLength] = { 0 };
    printf("Введите число m\n");
    scanf_s("%d", &m);
    printf("Введите число n\n");
    scanf_s("%d", &n);
    int arrayLength = m + n;

    for (int i = 0; i < m + n; ++i)
    {
        printf("Введите %d элемент массива ", i + 1);
        scanf_s("%d", &array[i]);
    }

    printf("Массив до изменений:\n");
    for (int i = 0; i < arrayLength; ++i)
    {
        printf("%d ", array[i]);
    }

    swapElements(&array[0], m);
    swapElements(&array[0], arrayLength);
    swapElements(&array[0], n);

    //for (int i = 0; i < m / 2; ++i)
    //{
    //    int temporaryVariableForSwap = array[i];
    //    array[i] = array[m - i - 1];
    //    array[m - i - 1] = temporaryVariableForSwap;
    //}

    //for (int i = 0; i < arrayLength / 2; ++i)
    //{
    //    int temporaryVariableForSwap = array[i];
    //    array[i] = array[arrayLength - i - 1];
    //    array[arrayLength - i - 1] = temporaryVariableForSwap;
    //}

    //for (int i = 0; i < n / 2; ++i)
    //{
    //    int temporaryVariableForSwap = array[i];
    //    array[i] = array[n - i - 1];
    //    array[n - i - 1] = temporaryVariableForSwap;
    //}

    printf("\nМассив после изменений:\n");
    for (int i = 0; i < arrayLength; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void main()
{
    setlocale(LC_ALL, "RU");
    bool exitFlag = true;
    while (exitFlag)
    {
        int taskNumber = 0;
        printf("%s", "Введите номер задачи, которую хотите проверить (от 1 до 8), для выхода наберите 6759 \n");
        scanf_s("%d", &taskNumber);
        switch (taskNumber)
        {
        case 1:
        {
            swap();
            break;
        }
        case 2:
        {
            zeroElementsInArray();
            break;
        }
        case 3:
        {
            division();
            break;
        }
        case 4:
        {
            happyTickets();
            break;
        }
        case 5:
        {
            bracketsBalance();
            break;
        }
        case 6:
        {
            simpleNumbers();
            break;
        }
        case 7:
        {
            substringEntryCounter();
            break;
        }

        case 8:
        {
            partSwapArray();
            break;
        }
        case 6759:
        {
            exitFlag = false;
            break;
        }
        default:
        {
            printf("Неверный формат ввода\n");
            break;
        }
        }
    }
}