#pragma once
#include "sortedList.h"
#include <stdio.h>

int main() {
    SortedList* sortedlist = createSortedList();
    if (sortedlist == NULL) {
        printf("All bad");
        return;
    }
    push(sortedlist, 100);
    push(sortedlist, 200);
    push(sortedlist, 50);
    push(sortedlist, 400);
    int errorCode = 0;
    printSortedList(sortedlist);
}