#include <iostream>
#include "structures.cpp"
#include "filemgmt.cpp"

int main()
{

  if (validateText("test.txt"))
  {
    std::cout << "Valid\n";
    Tree<int> tree = textToTree("test.txt");
    tree.printTree();
  }
  else
  {
    std::cout << "Not valid\n";
  }
  return 1;
}