#include <iostream>
#include "structures.cpp"
#include "filemgmt.cpp"

int main()
{

  if (validateText("test.txt"))
  {
    std::cout << "File is valid\n";
    Tree<int> tree = textToTree("test.txt");
    tree.printTree();
    treeToHTML(tree, "test.html");
  }
  else
  {
    std::cout << "File is not valid\n";
  }
  return 1;
}