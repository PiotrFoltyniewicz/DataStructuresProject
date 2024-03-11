#include <iostream>
#include "structures.cpp"
#include "filemgmt.cpp"

int main()
{
  if (validateText("test.txt"))
  {
    std::cout << "Valid";
  }
  else
  {
    std::cout << "Not valid";
  }

  return 1;
}