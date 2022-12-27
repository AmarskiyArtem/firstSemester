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
        (fabs(exponentiationStandart(5, -1) - 0.2) < 0.0001) && (fabs(exponentiationStandart(2, -2) - 0.25) < 0.001));
}

bool testsForExponentiationFast(void) {
    return (exponentiationFast(5, 1) == 5 && exponentiationFast(4, 0) == 1 && exponentiationFast(3, 4) == 81 && 
        (fabs(exponentiationStandart(5, -1) - 0.2) < 0.0001) && (fabs(exponentiationStandart(2, -2) - 0.25) < 0.001));
}
//tests block end

void main() {
    setlocale(LC_ALL, "RU");
    if (!testsForExponentiationStandart()) {
        printf("АААААААА ПАНИКА 1 ТЕСТ НЕ ПРОШЕЛ\n");
        return;
    }
    if (!testsForExponentiationFast()) {
        printf("АААААААА ПАНИКА 2 ТЕСТ НЕ ПРОШЕЛ\n");
        return;
    }
    int number = 0;
    printf("Введите число\n");
    scanf_s("%d", &number);
    printf("Введите степень\n");
    int power = 0;
    scanf_s("%d", &power);
    double result = exponentiationFast(number, power);
    result >= 1 ? printf("%d в степени %d = %d", number, power, (int)result) : printf("%d в степени %d = %lf", number, power, result);
}