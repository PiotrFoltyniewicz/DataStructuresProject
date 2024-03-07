struct StackNode{
  int value;
  struct StackNode* next;
};

void clamp(int *value, int min, int max){
  if(*value < min) *value = min;
  else if(*value > max) *value = max;
}

void push(struct StackNode** root, int value){
  clamp(&value, 0, 255);
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