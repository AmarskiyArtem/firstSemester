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
    int errorCode = 0;
    printf("%d", top(sortedlist, 0, &errorCode));
}