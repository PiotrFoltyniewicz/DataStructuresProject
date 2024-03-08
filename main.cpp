#include <iostream>
#include "structures.cpp"

int main()
{
  Stack stack = Stack();
  stack.push(10);
  std::cout << stack.pop() << '\n';
  std::cout << stack.pop() << '\n';
  return 1;
}