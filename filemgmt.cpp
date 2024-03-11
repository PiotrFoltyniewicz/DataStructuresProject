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

void treeToHTML(Tree<std::string> tree)
{
}

#endif
