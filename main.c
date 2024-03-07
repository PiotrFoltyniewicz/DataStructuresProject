#include <stdio.h>
#include <stdlib.h>
#include "structures.c"
#include "sorting.c"
#include "filemgmt.c"

int main(){
  struct StackNode* stack = NULL;
  push(&stack, 10);
  push(&stack, 1000);
  printf("%d",peek(stack));
  return 0;
}