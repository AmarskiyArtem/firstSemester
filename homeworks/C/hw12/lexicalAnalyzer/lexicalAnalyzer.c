#include <string.h>
#include <ctype.h>

#include "lexicalAnalyzer.h"

bool isNumber(const char* string) {
    const int stringLength = strlen(string);
    int state = 0;
    for (int i = 0; i < stringLength + 1; ++i) {
        switch (state) {
            case 0: {
                if (isdigit(string[i])) {
                    state = 1;
                    break;
                }
                return false;
            }
            case 1: {
                if (isdigit(string[i])) {
                    state = 1;
                    break;
                }
                if (string[i] == '.') {
                    state = 2;
                    break;
                }
                if (string[i] == 'E') {
                    state = 4;
                    break;
                }
                return i == stringLength;
            }
            case 2: {
                if (isdigit(string[i])) {
                    state = 3;
                    break;
                }
                return false;
            }
            case 3: {
                if (isdigit(string[i])) {
                    state = 3;
                    break;
                }
                if (string[i] == 'E') {
                    state = 4;
                    break;
                }
                return i == stringLength;
            }
            case 4: {
                if (isdigit(string[i])) {
                    state = 5;
                    break;
                }
                if (strchr("+-", string[i]) != NULL) {
                    state = 6;
                    break;
                }
                return false;
            }
            case 5: {
                if (isdigit(string[i])) {
                    state = 5;
                    break;
                }
                return i == stringLength;
            }
            case 6: {
                if (isdigit(string[i])) {
                    state = 5;
                    break;
                }
                return false;
            }
                
        }
    }
}

