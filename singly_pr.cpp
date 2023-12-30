#include <iostream>
using namespace std;
class node {
public:
  int data;
  node *next;

  node(int val) {

    data = val;
    next=nullptr;
  }
};
class list {
public:
  node *head;
  list() { head = nullptr; }


    void insert(int val) {
    node *newnode = new node(val);
    if (head == NULL) {
      head = newnode;
      return;
    }
    node *current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next=newnode;
  }
  void display() {
    node *current = head;
    while (current->next != nullptr) {
      cout<<current->data<<" ";
    
    }
  }
  void deleteNode(int value) {
        node* current = head;

        if (current != nullptr && current->data == value) {
            head = current->next;
            delete current;
            return;
        }

        while (current != nullptr && current->next != nullptr && current->next->data != value) {
            current = current->next;
        }

        if (current != nullptr && current->next != nullptr) {
            node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    ~list() {
        node* current = head;
        node* nextNode;
        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }
    
  };
