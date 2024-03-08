#ifndef structures_cpp
#define structures_cpp

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
class Tree
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

#endif