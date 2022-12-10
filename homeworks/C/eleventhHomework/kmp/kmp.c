﻿#include <string.h>
#include <stdlib.h>

#include "kmp.h"

int* makePrefix(char* string) {
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

int searchForOccurrences(char* string, char* substring) {
    int* prefix = makePrefix(substring);
    int i = 0;
    int j = 0;
    while (i < strlen(string)) {
        if (string[i] == substring[j]) {
            ++i;
            ++j;
            if (j == strlen(substring)) {
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
    return -1;
}