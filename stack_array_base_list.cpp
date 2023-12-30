#include <iostream>

class Stack {
private:
    static const int MAX_SIZE = 100;  
    int arr[MAX_SIZE];
    int top;

public:
    Stack() : top(-1) {}

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int value) {
        if (isFull()) {
            std::cout << "Stack overflow! Cannot push element.\n";
            return;
        }
        arr[++top] = value;
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Stack underflow! Cannot pop element.\n";
            return;
        }
        --top;
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot peek.\n";
            return -1;  
        }
        return arr[top];
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Stack is empty.\n";
            return;
        }
        std::cout << "Stack elements: ";
        for (int i = 0; i <= top; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    Stack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    std::cout << "Top element: " << myStack.peek() << "\n";

    myStack.display();

    myStack.pop();
    myStack.display();

    return 0;
}
