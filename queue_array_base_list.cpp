#include <iostream>

class Queue {
private:
    static const int MAX_SIZE = 100;  
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    Queue() : front(-1), rear(-1) {}

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;
    }

    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Queue overflow! Cannot enqueue element.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }

        arr[rear] = value;
    }

    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue underflow! Cannot dequeue element.\n";
            return;
        }

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot peek.\n";
            return -1; 
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            return;
        }

        std::cout << "Queue elements: ";
        int i = front;
        do {
            std::cout << arr[i] << " ";
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);

        std::cout << "\n";
    }
};

int main() {
    Queue myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    std::cout << "Front element: " << myQueue.peek() << "\n";

    myQueue.display();

    myQueue.dequeue();
    myQueue.display();

    return 0;
}
