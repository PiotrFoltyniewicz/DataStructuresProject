#ifndef filemgmt_cpp
#define filemgmt_cpp

#include "structures.cpp"
#include <fstream>
#include <string>
#include <iostream>

bool validateText(std::string filename)
{
    std::fstream file;
    file.open(filename, std::ios::in);
    if (file.bad())
    {
        std::cout << "Bad";
        return false;
    }
    Stack<char> stack = Stack<char>();
    char c;
    while (file >> c)
    {
        if (c == '(')
        {
            stack.push(c);
        }
        else if (c == ')')
        {
            if (stack.isEmpty())
            {
                return false;
            }
            stack.pop();
        }
    }
    file.close();
    if (stack.isEmpty())
    {
        return true;
    }
    return false;
}

#endif
