#include "structures.h"

struct Stack::Node{
    int value;
    Node *next = nullptr;
  };

  void Stack::push(int value){
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = topNode;
    topNode = newNode;
  }
  bool Stack::isEmpty(){
    return !Stack::topNode;
  }
  int Stack::pop(){
    if(isEmpty()){
      return NULL;
    }
    Node *temp = topNode;
    topNode = topNode->next;
    int poppedValue = temp->value;
    delete temp;
    return poppedValue;
  }
  int Stack::peek(){
    if(isEmpty()){
      return NULL;
    }
    return topNode->value;
  }