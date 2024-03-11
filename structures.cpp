#ifndef structures_cpp
#define structures_cpp

#include <stdexcept>
#include <iostream>
#include <vector>

template <typename T>
class Stack
{
private:
  struct Node
  {
    T value;
    Node *next = nullptr;
  };
  Node *topNode;

public:
  void push(T value)
  {
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = topNode;
    topNode = newNode;
  }
  bool isEmpty()
  {
    return !topNode;
  }
  T pop()
  {
    if (isEmpty())
    {
      return -1;
    }
    Node *temp = topNode;
    topNode = topNode->next;
    T poppedValue = temp->value;
    delete temp;
    return poppedValue;
  }
  T peek()
  {
    if (isEmpty())
    {
      return -1;
    }
    return topNode->value;
  }
};

template <typename T>
class Queue
{
private:
  struct Node
  {
    char value;
    Node *next = nullptr;
  };
  Node *topNode;
  Node *root;

public:
  void enqueue(T value)
  {

    Node *newNode = new Node;
    newNode->value = value;
    if (isEmpty())
    {
      root = newNode;
      topNode = root;
    }
    else
    {
      root->next = newNode;
      root = newNode;
    }
  }
  bool isEmpty()
  {
    return !root;
  }
  T dequeue()
  {
    if (isEmpty())
    {
      return -1;
    }
    Node *temp = topNode;
    topNode = topNode->next;
    T poppedValue = temp->value;
    delete temp;
    return poppedValue;
  }
  T peek()
  {
    if (isEmpty())
    {
      return -1;
    }
    return topNode->value;
  }
};

template <typename T>
class LinkedList
{
private:
  struct Node
  {
    T value;
    Node *next;
  };
  Node *start;

public:
  void push(T value)
  {

    Node *newNode = new Node;
    newNode->value = value;
    Node *temp = start;

    if (start == nullptr)
    {
      start = newNode;
    }
    else
    {
      while (temp->next != nullptr)
      {
        temp = temp->next;
      }
      temp->next = newNode;
    }
  }
  void insert(int index, T value)
  {
    int i = 0;
    Node *newNode = new Node;
    newNode->value = value;
    Node *temp = start;
    Node *current = nullptr;

    if (start == nullptr)
    {
      start = newNode;
      return;
    }

    while (temp != nullptr && i < index)
    {
      temp = temp->next;
      i++;
    }
    if (temp == nullptr)
    {
      throw std::out_of_range("Index out of range");
    }
    current = temp;
    temp = temp->next;
    current->next = newNode;
    newNode->next = temp;
  }
  void remove(int index)
  {
    int i = 0;
    Node *temp = start;
    Node *current = nullptr;
    if (start == nullptr)
    {
      throw std::out_of_range("Index out of range");
    }
    else if (index == 0 && start != nullptr)
    {
      delete temp;
      start = nullptr;
      return;
    }
    else
    {
      while (i < index && temp->next != nullptr)
      {
        if (i + 1 == index)
        {
          current = temp;
          temp = temp->next;
          current->next = temp->next;
          delete temp;
          return;
        }
        temp = temp->next;
        i++;
      }
    }
    throw std::out_of_range("Index out of range");
  }
  int length()
  {
    Node *temp = start;
    int length = 0;
    while (temp != nullptr)
    {
      length++;
      temp = temp->next;
    }
    return length;
  }
  bool isEmpty()
  {
    return !start;
  }
  Node *peek()
  {
    Node *temp = start;
    while (temp->next != nullptr)
    {
      temp = temp->next;
    }
    return temp;
  }
};

template <typename T>
class Tree
{
private:
public:
  struct Node
  {
    T value;
    Node *parent = nullptr;
    std::vector<Node *> children = {};
  };
  Node *root = nullptr;
  Node *addChild(Node *parentNode, T value)
  {
    Node *newNode = new Node;
    newNode->value = value;
    if (parentNode == nullptr)
    {
      root = newNode;
      return root;
    }
    newNode->parent = parentNode;
    parentNode->children.push_back(newNode);
    return newNode;
  }

  void printSubtree(Node *node, int depth)
  {
    if (node == nullptr)
      return;

    for (int i = 0; i < depth; ++i)
      std::cout << "  ";
    std::cout << node->value << std::endl;

    for (Node *child : node->children)
    {
      printSubtree(child, depth + 1);
    }
  }

  void printTree()
  {
    if (root == nullptr)
    {
      std::cout << "Tree is empty." << std::endl;
      return;
    }

    std::cout << "Tree Contents:" << std::endl;
    printSubtree(root, 0);
  }
};

#endif