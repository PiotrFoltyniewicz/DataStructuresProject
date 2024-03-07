#include <ctype.h>
#include "structures.h"
#include <stddef.h>
#include <stdlib.h>

int clamp(int *value, int min, int max){
  if(*value < min) *value = min;
  else if(*value > max) *value = max;
  return *value;
}

struct StackNode* convertToFileStack(char filename[]){
  struct StackNode* stack = NULL;
  FILE *file = fopen(filename, 'r');
  if(file == NULL){
    return 0;
  }
  char num[3] = "---";
  int numInd = 0;
  do{
    char c = fgetc(file);
    if(isdigit(c)){
      num[numInd] = c;
      numInd++;
      if(numInd == 3){
        push(&stack, atoi(num));
        num[0] = '-';
        num[1] = '-';
        num[2] = '-';
        numInd = 0;
      }
    }
    else if (!isdigit(c) && num[0] != '-'){
      push(&stack, clamp(atoi(num), 0, 255));
      num[0] = '-';
      num[1] = '-';
      num[2] = '-';
      numInd = 0;
      if(c == '('){
        push(&stack, -1000);
      }
      else if(c == ')'){
        push(&stack, 1000);
      }
    }
  }while(feof(file));

  fclose(file);
  return stack;
}