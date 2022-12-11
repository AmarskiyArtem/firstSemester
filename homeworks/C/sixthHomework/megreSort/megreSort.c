#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "mergeSort.h"
#include "list.h"

#define MAX_SIZE 256

void addElements(List* parentList, List* childList, int quantity) {
    for (int i = 0; i < quantity; ++i) {
        addNode(childList, getNameFromHead(parentList), getNumberFromHead(parentList));
        deleteHead(parentList);
    }
}

List* merge(List* firstList, List* secondList, SortBy sortBy) {
    List* newList = createList();
    if (newList == NULL) {
        return NULL;
    }
    while (listLength(firstList) != 0 && listLength(secondList) != 0) {
        int comparisonResult = 0;
        if (sortBy == name) {
            comparisonResult = strcmp(getNameFromHead(firstList), getNameFromHead(secondList));
        }
        else {
            comparisonResult = strcmp(getNumberFromHead(firstList), getNumberFromHead(secondList));
        }
        comparisonResult < 0 ? addElements(firstList, newList, 1) : addElements(secondList, newList, 1);
    }
    listLength(secondList) == 0 ? addElements(firstList, newList, listLength(firstList)) :
        addElements(secondList, newList, listLength(secondList));
    deleteList(firstList);
    deleteList(secondList);
    return newList;
}

List* mergeSort(List* list, SortBy sortBy) {
    const int length = listLength(list);
    if (length <= 1) {
        return list;
    }
    List* leftList = createList();
    if (leftList == NULL) {
        return NULL;
    }
    addElements(list, leftList, length / 2);
    List* rightList = createList();
    if (rightList == NULL) {
        return NULL;
    }
    addElements(list, rightList, length - length / 2);
    deleteList(list);
    leftList = mergeSort(leftList, sortBy);
    rightList = mergeSort(rightList, sortBy);
    return merge(leftList, rightList, sortBy);
}

bool sortTest(void) {
    List* testList = createList();
    if (testList == NULL) {
        return false;
    }
    if (readFromFile("test.txt", testList) != ok) {
        deleteList(testList);
        return false;
    }
    testList = mergeSort(testList, name);
    if (testList == NULL) {
        deleteList(testList);
        return false;
    }
    if (strcmp(getNameFromHead(testList), "aName") != 0) {
        deleteHead(testList);
        return false;
    }
    deleteList(testList);
    return true;
}