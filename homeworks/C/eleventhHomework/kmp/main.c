#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "kmp.h"

char* readFromFile(const char* filename) {
    int stringLength = 0;
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }
    char temp = '0';
    while (fscanf_s(file, "%c", &temp, 1) != EOF) {
        ++stringLength;
    }
    if (stringLength == 0) {
        fclose(file);
        return NULL;
    }
    fseek(file, 0, SEEK_SET);
    char* string = calloc(stringLength, sizeof(char));
    if (string == NULL) {
        fclose(file);
        return NULL;
    }
    for (int i = 0; i < stringLength - 1; ++i) {
        fscanf_s(file, "%c", &string[i], 1);
    }
    fclose(file);
    return string;
}

void main() {
    
}