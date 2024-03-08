#ifndef structures_cpp
#define structures_cpp

class Stack
{
private:
  struct Node
  {
    int value;
    Node *next = nullptr;
  };
  Node *topNode;

public:
  void push(int value)
  {
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = topNode;
    topNode = newNode;
  }
  bool isEmpty()
  {
    return !Stack::topNode;
  }
  int pop()
  {
    if (isEmpty())
    {
      return -1;
    }
    Node *temp = topNode;
    topNode = topNode->next;
    int poppedValue = temp->value;
    delete temp;
    return poppedValue;
  }
  int peek()
  {
    if (isEmpty())
    {
      return -1;
    }
    return topNode->value;
  }
};

#endif