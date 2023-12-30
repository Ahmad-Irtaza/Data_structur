#include<iostream>
using namespace std;
class node {
public:
  int data;
  node* next;

  node(int val) {
    data = val;
    next=nullptr;
      }
};
class list {
      node *head;

    public:
      list() { head = nullptr; }

      void insert(int val) {
    node *newnode = new node(val);
    if (head == nullptr) {
      head = newnode;
      return;
    }
    node *current = head;
    while (current->next!=nullptr) {
    current=current->next;
    }
    current->next=newnode;
      }
      void display() {
    node *current = head;
    while (current!= nullptr) {
    cout<<current->data<<" ";
    current=current->next;
    }
    cout<<endl;

      }
};

int main() {
      list a;
      a.insert(1);
      a.insert(2);
      a.insert(3);
      a.insert(4);
      a.display();
}