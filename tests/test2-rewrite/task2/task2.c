#include <stdio.h>

#include "set.h"

bool tests(void) {
    Set* set = createSet();
    makeSet(set, 7);
    makeSet(set, 9);
    makeSet(set, 12);
    unionSet(set, 7, 12);
    bool result = isTheSameSet(set, 7, 12) && !isTheSameSet(set, 9, 7);
    deleteSet(set);
    return result;
}


void main(void) {
    if (!tests()) {
        printf("tests failed");
        return;
    }
    Set* set = createSet();
    if (set == NULL) {
        return;
    }
    makeSet(set, 3);
    makeSet(set, 4);
    unionSet(set, 3, 4);
    isTheSameSet(set, 3, 4) ? printf("YES") : printf("NO");
}