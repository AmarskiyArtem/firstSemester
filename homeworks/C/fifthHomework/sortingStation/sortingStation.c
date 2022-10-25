#include "../stack/stack.h"
#include <stdio.h>

void main() {
    Stack* stack = createStack();
    push(stack, 200);
    printf("%d", top(stack));
}