#include <iostream>
#include "structures.h"

int main(){
  Stack* stack = new Stack;
  stack->push(10);
  std::cout << stack->pop(); 
  return 1;
}