#include <iostream>
using namespace std;

void delnode(Node* node){
  node->val= node->next->val;
  node->next= node->next->next;
  
} 
