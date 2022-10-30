#pragma once
#include "cycleList.h"
#include <stdio.h>

void main() {
    int n = 3;
    CycleList* cycleList = createCycleList(n);
    printf("%d", top(cycleList));
}