#include <bits/stdc++.h>

using namespace std;

Node* sortTwoLinkedLists(Node* list1, Node* list2){
  Node* dummynode= new Node(-1);
  Node* temp= dummynode;
  while(list1!=nullptr && list2!=nullptr){
    if(list1->data <= list2->data){
      temp->next=list1;
      list1= lis1->next;
      
    }
    else{
      temp->next= list2;
      list2= list2->next; 
    }
    temp= temp->next;
    if (list1 != nullptr) {
        temp->next = list1;
    } else {
        temp->next = list2;
    }
    return dummyNode->next;
  }
}
