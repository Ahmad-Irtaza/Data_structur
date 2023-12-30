#include <iostream>
using namespace std;
class node {
public:
  int data;
  node *next;
  node(int val) {
    data=val;
      }
};
class stack {
  node *top;
  bool isempty() { return (top == nullptr); }
  
    void push(int value) {
        node* newNode = new node(value);
        newNode->next = top;
        top = newNode;
    }
    
};