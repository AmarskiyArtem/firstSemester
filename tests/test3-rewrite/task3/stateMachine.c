#include <string.h>
#include <ctype.h>

#include "stateMachine.h"

typedef enum State {
    start,
    symbolBeforeAt,
    at,
    symbolAfterAt,
    dot,
} State;

bool correctSymbolBeforeAt(const char symbol) {
    return isdigit(symbol) || (symbol >= 'A' && symbol <= 'Z') ||
        strchr("._%+-", symbol) != NULL;
}

bool correctSymbolAfterAt(const char symbol) {
    return isdigit(symbol) || (symbol >= 'A' && symbol <= 'Z') ||
        symbol == '-';
}

bool isCorrectRegularExpression(const char* string) {
    const int stringLength = strlen(string);
    State state = start;
    for (int i = 0; i <= stringLength; ++i) {
        switch (state) {
            case start: {
                if (correctSymbolBeforeAt(string[i])) {
                    state = symbolBeforeAt;
                    break;
                }
                return false;
            }
            case symbolBeforeAt: {
                if (correctSymbolBeforeAt(string[i])) {
                    state = symbolBeforeAt;
                    break;
                }
                if (string[i] == '@') {
                    state = at;
                    break;
                }
                return false;
            }
            case at: {
                if (correctSymbolAfterAt(string[i])) {
                    state = symbolAfterAt;
                    break;
                }
                return false;
            }
            case symbolAfterAt: {
                if (correctSymbolAfterAt(string[i])) {
                    state = symbolAfterAt;
                    break;
                }
                if (string[i] == '.') {
                    state = dot;
                    break;
                }
                return false;
            }
            case dot: {
                if (string[i] >= 'A' && string[i] <= 'Z') {
                    return i + 1 == stringLength;
                }
                return false;
            }
        }
    }
    return false;
}

bool tests(void) {
    return !isCorrectRegularExpression("%D@@9F.V") && isCorrectRegularExpression("VBDSH@VBHBVO.D")
        && !isCorrectRegularExpression("SC.+CSC%-.K") && isCorrectRegularExpression("SC.+CSC%-.K@G.L") &&
        !isCorrectRegularExpression("SC.+CSC%-.K@G.5");
}