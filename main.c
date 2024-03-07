#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "structures.h"
#include "sorting.c"
#include "filemgmt.c"

int main(){
  struct StackNode* stack = convertToFileStack("test.txt");
  while(stack != NULL){
    printf("%d", pop(&stack));
  }
  return 1;
}