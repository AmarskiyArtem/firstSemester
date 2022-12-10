#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "kmp.h"

void main() {
    printf("%d", searchForOccurrences("zdsababbababa", "abab"));
}