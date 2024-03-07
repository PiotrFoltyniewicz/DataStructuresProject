#ifndef structures
#define structures

#include "structures.c"

void push(struct StackNode** root, int value);

int pop(struct StackNode** root);

int peek(struct StackNode* root);

#endif structures