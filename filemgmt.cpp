#ifndef filemgmt_cpp
#define filemgmt_cpp

#include "structures.cpp"
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>

bool validateText(std::string filename)
{
    std::fstream file;
    file.open(filename, std::ios::in);
    if (file.bad())
        return false;
    Stack<char> stack = Stack<char>();
    char c;
    while (file >> c)
    {
        if (c == '(')
            stack.push(c);
        else if (c == ')')
        {
            if (stack.isEmpty())
                return false;
            stack.pop();
        }
    }
    file.close();
    if (stack.isEmpty())
        return true;
    return false;
}

Tree<int> textToTree(std::string filename)
{
    std::fstream file;
    file.open(filename, std::ios::in);
    if (file.bad())
        return Tree<int>();
    Tree<int> tree = Tree<int>();
    char c;
    std::string temp = "";
    Tree<int>::Node *currentNode = tree.root;
    while (file >> c)
    {
        if (temp.length() > 0 && (c == ')' || c == '('))
        {
            currentNode->value = stoi(temp);
            temp = "";
        }
        if (c == '(')
        {
            currentNode = tree.addChild(currentNode, -1);
        }
        else if (c == ')')
        {
            currentNode = currentNode->parent;
        }
        else if (isdigit(c))
        {
            temp += c;
        }
    }
    file.close();
    return tree;
}

void nodeToDiv(Tree<int>::Node* node, std::string* text)
{
  std::string color = "rgb(" + std::to_string(node->value) + ","
                             + std::to_string(node->value) + ","
                             + std::to_string(node->value) + ")";
  *text += "<div style='background-color:" + color + "; width: 90%'>\n" + std::to_string(node->value) + "\n";
  for(int i = 0; i < node->children.size(); i++){
    nodeToDiv(node->children[i], text);
  }
  *text += "</div>\n";
}

void treeToHTML(Tree<int> tree, std::string newFilename)
{
  std::fstream newFile;
  newFile.open(newFilename, std::ios::out);
  std::string text = 
  "<!DOCTYPE html>\n"
  "<html>\n"
  " <head>\n"
  "   <style>\n"
  "     body{height:300px;}\n"
  "     div{width:90%;height:90%;display:flex;flex-direction:row;align-items:center;justify-content: center;}\n"
  "   </style>\n"
  " </head>\n"
  "<body>\n";
  nodeToDiv(tree.root, &text);
  text += "</body>\n</html>";
  newFile << text;
  newFile.close();
  std::cout << "HTML created\n";
}

#endif
