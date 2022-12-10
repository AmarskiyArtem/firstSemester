#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "mergeSort.h"
#include "list.h"

#define MAX_SIZE 256

List* merge(List* firstList, List* secondList, SortBy sortBy, ErrorCode errorCode) {
    errorCode = ok;
    List* newList = createList();
    if (newList == NULL) {
        errorCode = memoryAllocationError;
    }
}



List* mergeSort(List* list){
    
}