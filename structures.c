#include <stdlib.h>
#include <stddef.h>

struct StackNode{
  int value;
  struct StackNode* next;
};

void push(struct StackNode** root, int value){
  struct StackNode* newNode = (struct StackNode*)(malloc(sizeof(struct StackNode)));
  newNode->value = value;
  newNode->next = *root;
  *root = newNode;
}

int pop(struct StackNode** root){
  if(*root == NULL){
    return -100;
  }
  struct StackNode* temp = *root;
  int poppedValue = temp->value;
  *root = temp->next;
  free(temp);
  return poppedValue;
}

int peek(struct StackNode* root){
  if(root == NULL){
    return -100;
  }
  return root->value;
}