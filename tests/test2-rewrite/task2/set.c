#include <stdlib.h>
#include <stdbool.h>

#include "set.h"

typedef struct Set {
    int parent[1000];
    int size[1000];
} Set;

void swap(int* a, int* b) {
    if (a == b) {
        return;
    }
    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *a ^ *b;
}

Set* createSet(void) {
    Set* set = malloc(sizeof(Set));
    return set;
}

void makeSet(Set* set, int value) {
    set->parent[value] = value;
    set->size[value] = 1;
}

int findSet(Set* set, int value) {
    if (value == set->parent[value]) {
        return value;
    }
    return findSet(set, set->parent[value]);
}

void unionSet(Set* set, int firstValue, int secondValue) {
    firstValue = findSet(set, firstValue);
    secondValue = findSet(set, secondValue);
    if (firstValue != secondValue) {
        if (set->size[firstValue] < set->size[secondValue]) {
            swap(&firstValue, &secondValue);
        }
        set->parent[secondValue] = firstValue;
        set->size[firstValue] += set->size[secondValue];
    }
}

bool isTheSameSet(Set* set, int firstValue, int secondValue) {
    return findSet(set, firstValue) == findSet(set, secondValue);
}

void deleteSet(Set* set) {
    free(set);
}