#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>

double exponentiationStandart(int number, int power) {
    double result = 1;
    for (int i = 1; i <= abs(power); ++i) {
        result *= number;
    }
    return (power < 0) ? (1 / result) : result;
}

double exponentiationFast(int number, int power) {
    double result = 1;
    int absPower = abs(power);
    while (absPower > 0) {
        if (absPower % 2 == 1) {
            result *= number;
        }
        number *= number;
        absPower /= 2;
    }
    return (power < 0) ? (1 / result) : result;
}

//tests block
bool testsForExponentiationStandart(void) {
    return (exponentiationStandart(5, 1) == 5 && exponentiationStandart(4, 0) == 1 && exponentiationStandart(3, 4) == 81 && 
        exponentiationStandart(5, -1) == 0.2 && exponentiationStandart(2, -2) == 0.25);
}

bool testsForExponentiationFast(void) {
    return (exponentiationFast(5, 1) == 5 && exponentiationFast(4, 0) == 1 && exponentiationFast(3, 4) == 81 && 
        exponentiationFast(5, -1) == 0.2 && exponentiationFast(2, -2) == 0.25);
}
//tests block end

void main() {
    setlocale(LC_ALL, "RU");
    srand(time(NULL));

    if (!testsForExponentiationStandart()) {
        printf("АААААААА ПАНИКА 1 ТЕСТ НЕ ПРОШЕЛ\n");
    }
    if (!testsForExponentiationFast()) {
        printf("АААААААА ПАНИКА 2 ТЕСТ НЕ ПРОШЕЛ\n");
    }
    int number = 0;
    printf("Введите число\n");
    scanf_s("%d", &number);
    printf("Введите степень\n");
    int power = 0;
    scanf_s("%d", &power);
    long double result = exponentiationFast(number, power);
    result >= 0 ? printf("%d в степени %d = %Lf", number, power, result) : printf("%d в степени %d = %Lf", number, power, result);
}