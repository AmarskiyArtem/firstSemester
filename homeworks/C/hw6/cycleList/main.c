#include <stdio.h>

#include "cycleList.h"

int lastAlive(int n, int m) {
    int exitCode = -1;
    CycleList* cycleList = createCycleList(n);
    Position position = getFirstPosition(cycleList);
    while (exitCode != 0) {
        position = deleteElement(cycleList, position, m, &exitCode);
        //printList(cycleList);
    }
    int result = getValue(position);
    deleteList(&cycleList);
    return result;
}

bool tests(void) {
    return lastAlive(6, 4) == 5 && lastAlive(2, 8) == 1 && lastAlive(5, 5) == 2;
}

void main() {
    if (!tests()) {
        printf("Tests failed");
        return;
    }
    printf("Input amount of warriors (n):\n");
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
    int result = lastAlive(n, m);
    printf("%d warrior will be the last", result);
}