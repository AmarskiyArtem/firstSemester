#include <string.h>
#include <stdlib.h>

#include "kmp.h"

int* makePrefix(const char* string) {
    int* prefix = (int*)calloc(strlen(string), sizeof(int));
    if (prefix == NULL) {
        return NULL;
    }
    int begin = 0;
    int end = 1;
    while (end < strlen(string) - 1) {
        if (string[begin] == string[end]) {
            prefix[end] = ++begin;
            ++end;
        }
        else {
            if (begin == 0) {
                prefix[end] = 0;
                ++end;
            }
            else {
                begin = prefix[begin - 1];
            }
        }
    }
    return prefix;
}

int searchForOccurrences(const char* string, const char* substring) {
    const int* prefix = makePrefix(substring);
    int i = 0;
    int j = 0;
    while (i < strlen(string)) {
        if (string[i] == substring[j]) {
            ++i;
            ++j;
            if (j == strlen(substring)) {
                free(prefix);
                return i - strlen(substring);
            }
        }
        else {
            if (j > 0) {
                j = prefix[j - 1];
            }
            else {
                ++i;
            }
        }
    }
    free(prefix);
    return -1;
}