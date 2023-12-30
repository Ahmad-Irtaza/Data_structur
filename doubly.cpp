#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (!head) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteNode(int value) {
        Node* current = head;
        while (current) {
            if (current->data == value) {
                if (current->prev) {
                    current->prev->next = current->next;
                } else {
                    // If deleting the head
                    head = current->next;
                    if (head) {
                        head->prev = nullptr;
                    }
                }

                if (current->next) {
                    current->next->prev = current->prev;
                } else {
                    // If deleting the tail
                    tail = current->prev;
                    if (tail) {
                        tail->next = nullptr;
                    }
                }

                delete current;
                return; // Node found and deleted, exit the function
            }
            current = current->next;
        }

        std::cout << "Node with value " << value << " not found.\n";
    }

    void displayForward() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
    }

    void displayBackward() {
        Node* current = tail;
        while (current) {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << "\n";
    }

    ~DoublyLinkedList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    DoublyLinkedList dll;

    dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(3);
    dll.insertAtEnd(4);

    std::cout << "Original List:\n";
    std::cout << "Forward: ";
    dll.displayForward();
    std::cout << "Backward: ";
    dll.displayBackward();

    dll.deleteNode(2);

    std::cout << "\nAfter Deleting Node with Value 2:\n";
    std::cout << "Forward: ";
    dll.displayForward();
    std::cout << "Backward: ";
    dll.displayBackward();

    return 0;
}
