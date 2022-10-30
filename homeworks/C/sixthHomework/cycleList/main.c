#pragma once
#include "cycleList.h"
#include <stdio.h>

void main() {
    int n = 3;
    CycleList* cycleList = createCycleList(n);
    top(cycleList);
    printf("\n");
    deleteElement(cycleList, 1, 2); 
    top(cycleList);
    printf("\n");
    deleteElement(cycleList, 3, 2);
    top(cycleList);
    //printf("\n");
    //deleteElement(cycleList, 3, 2);
    //isAlone(cycleList) ? printf("YES") : printf("NO");
}