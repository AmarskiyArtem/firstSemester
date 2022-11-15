#pragma once
#include <stdio.h>
#include "list.h"

void main() {
    List* list = createList();
    isEmpty(list) ? printf("Yes") : printf("No");
    char *a = "fioobnsdf";
    push(list, a);
    char* b = "fhpuranvpon";
    push(list, b);
    printf("\n%s", top(list));
    deleteList(list);
}