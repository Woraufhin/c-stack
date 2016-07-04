/*

Check for basic syntax errors in stdin.

*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void checkIfRight(stack_handler st, char c);
int main(void) {

    stack_handler symbols;
    symbols = stack_create(1000);
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '[' || c == '{' || c == '(') {
            push(symbols, c);
        }
        if (c == ']' || c == '}' || c == ')') {
            checkIfRight(symbols, c);
        }
    }
    if (stack_is_empty(symbols)) {
        printf("No syntax errors\n");
    } else {
        printf("Syntax error, open %c but no closing statement\n", peek(symbols));
    }
    stack_destroy(symbols);
    return 0;
}

void checkIfRight(stack_handler st, char c) {
    char i = peek(st);
    if ((c == ']' && i == '[') ||
        (c == '}' && i == '{') ||
        (c == ')' && i == '(')) 
    {
        pop(st);
    } else {
        printf("Syntax error, open %c but closing %c\n", peek(st), c);
        exit(1);
    }
}
