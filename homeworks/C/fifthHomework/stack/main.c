#pragma once
#include "stack.h"
#include <stdio.h>

void main() {
    Stack* stack = createStack();
    push(stack, '2');
    int a = top(stack)-'0';
    printf("%d", a);
}