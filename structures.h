#ifndef structures_hpp
#define structures_hpp

class Stack
{
  private:
    struct Node;
    Node *topNode;
  public:
    void push(int value);
    bool isEmpty();
    int pop();
    int peek();
};

#endif