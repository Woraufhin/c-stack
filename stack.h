#ifndef _STACK_H
#define _STACK_H

#include <stdbool.h>

typedef void* stack_handler;

// Define type for contents of stack
typedef char stackContent;

// Initializes an empty stack
stack_handler stack_create(int max_size);

// Destroys stack and frees memory
void stack_destroy(stack_handler st);

// Returns if stack is empty
bool stack_is_empty(stack_handler st);

// Returns if stack is full
bool stack_is_full(stack_handler st);

// Pushes an element to the stack
void push(stack_handler st, stackContent element);

// Pops an element from stack
stackContent pop(stack_handler st);

// Peek last content, doesn't move top
stackContent peek(stack_handler st);

#endif  /* not defined _STACK_H */
