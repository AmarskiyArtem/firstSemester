#include <stdio.h>

#include "comments.h"

void main() {
    char a[] = "//***//";
    printComments(&a[0]);
}