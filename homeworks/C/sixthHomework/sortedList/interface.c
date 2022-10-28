#pragma once
#include "sortedList.h"
#include <stdio.h>
#include <stdbool.h>

int main() {
    SortedList* sortedlist = createSortedList();
    if (sortedlist == NULL) {
        printf("All bad");
        return;
    }
    bool isContinue = true;
    while (isContinue) {
        int currentAction = 0;

        scanf_s("%d", &currentAction);
        switch () {
        default:
            break;
        }
    }
}