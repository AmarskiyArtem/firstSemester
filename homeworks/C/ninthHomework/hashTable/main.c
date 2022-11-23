#pragma once
#include <stdio.h>
#include "list.h"

void main() {
    List* list = createList();
    char* a = "fioobnsdf";
    push(list, a);
    char* b = "fhpuranvpon";
    push(list, b);
    push(list, b);
    char *c = "csdjpvnpb";
    push(list, c);
    printList(list);
    deleteList(list);
}