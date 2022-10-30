#pragma once
#include "cycleList.h"
#include <stdio.h>

void main() {
    printf("Input (n) amount of warriors:\n");
    int n = 0;
    scanf_s("%d", &n);
    if (n <= 0) {
        printf("Incorrect input");
        return;
    }
    printf("Input m:\n");
    int m = 0;
    scanf_s("%d", &m);
    if (n == 1) {
        printf("1 warrior will be the last");
        return;
    }
    int exitCode = -1;
    int position = 1;
    CycleList* cycleList = createCycleList(n);
    while (exitCode != 0) {
        position = deleteElement(cycleList, position, m, &exitCode);
    }
    printf("%d warrior will be the last", position);
}