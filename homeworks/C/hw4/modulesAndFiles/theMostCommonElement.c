#include "theMostCommonElement.h"

int mostCommon(int* array, int arrayLength) {
    int mostCommonElement = array[0];
    int currentInARow = 1;
    int maxInARow = 1;
    for (int i = 1; i < arrayLength; ++i) {
        if (array[i] == array[i - 1]) {
            currentInARow += 1;
        }
        else {
            currentInARow = 1;
        }
        if (currentInARow >= maxInARow) {
            maxInARow = currentInARow;
            mostCommonElement = array[i];
        }
    }
    return mostCommonElement;
}