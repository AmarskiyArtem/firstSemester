#include <stdio.h>

#include "mergeSort.h"
#include "list.h"

void main(void) {
    List* list = createList();
    if (list == NULL) {
        return;
    }
    char* fileName = "input.txt";
    readFromFile("input.txt", list);

}