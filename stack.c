/*

Stack library

*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct {
    stackContent *contents;
    int top;
    int max_size;
} stack;

/*

Initializes an empty stack

*/
stack_handler stack_create(int max_size) {
    stack* new_stack = (stack*) malloc(sizeof(stack));
    if (!new_stack) {
        fprintf(stderr, "Insufficient memory to initialize stack.\n");
        exit(1);
    }

    stackContent *new_contents;
    new_contents = (stackContent *)malloc(sizeof(stackContent) * max_size);
    if (new_contents == NULL) {
        fprintf(stderr, "Insufficient memory to initialize stack.\n");
        exit(1);
    }
    new_stack->contents = new_contents;
    new_stack->max_size = max_size;
    new_stack->top = -1;

    return new_stack;
}

/*

Destroys stack and frees memory

*/
void stack_destroy(stack_handler st) {
    free(((stack*)st)->contents);
    free(st);
}

/*

Returns if stack is empty

*/
bool stack_is_empty(stack_handler st) {
    return ((stack*)st)->top < 0;
}

/*

Returns if stack is full

*/
bool stack_is_full(stack_handler st) {
    return ((stack*)st)->top == (((stack*)st)->max_size - 1);
}

/*

Pushes an element to the stack

*/
void push(stack_handler st, stackContent element) {
    if (stack_is_full(st)) {
        fprintf(stderr, "Can't push element on stack: stack is full.\n");
        exit(1);
    }
    ((stack*)st)->contents[++((stack*)st)->top] = element;
}

/*

Pops an element from stack

*/
stackContent pop(stack_handler st) {
    if (stack_is_empty(st)) {
        fprintf(stderr, "Can't pop element; stack is empty.\n");
        exit(1);
    }
    return ((stack*)st)->contents[((stack*)st)->top--];
}

/*

Peek last content, doesn't move top

*/
stackContent peek(stack_handler st) {
    return ((stack*)st)->contents[((stack*)st)->top];
}
