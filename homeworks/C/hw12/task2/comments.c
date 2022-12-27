#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef enum State {
    notPrint,
    waitForStar,
    print,
    waitForSlash
} State;

typedef enum Symbol {
    slash,
    star,
    any
} Symbol;

Symbol whichSymbol(char symbol) {
    switch (symbol) {
        case '/': {
            return slash;
        }
        case '*': {
            return star;
        }
        default: {
            return any;
        }
    }
}

void getTable(const char* fileName, int* table) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        return;
    }
    for (int i = 0; i < 12; ++i) {
        fscanf(file, "%d", &table[i]);
        fgetc(file);
    }
    fclose(file);
}

State move(State state, char chr, int* table) {
    Symbol symbol = whichSymbol(chr);
    int m = state;
    int n = symbol;

    State newState = table[m * 3 + n];
    return newState;
}

void printComments(char* string) {
    int table[12] = { 0 };
    getTable("table.txt", table);
    if (table == NULL) {
        return;
    }
    int index = 0;
    char currentSymbol = string[index];
    ++index;
    State state = notPrint;
    State prevState = notPrint;
    while (currentSymbol != '\0') {
        prevState = state;
        state = move(state, currentSymbol, table);
        if (prevState == waitForStar && state == print) {
            printf("/");
        }
        if (state == print || state == waitForSlash) {
            printf("%c", currentSymbol);
        }
        if (prevState == waitForSlash && state == notPrint) {
            printf("/");
        }
        currentSymbol = string[index];
        ++index;
    }
} 

