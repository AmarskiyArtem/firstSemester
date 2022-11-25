#pragma once
#include "mergeSort.h"
#include "list.h"
#include <stdio.h>

void main(void) {
    List* list = createList();
    readFromFile("input.txt", list);
    
}