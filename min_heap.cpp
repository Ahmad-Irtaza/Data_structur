#include <iostream>

class MinHeap {
private:
    int* heap;
    int capacity;
    int size;

    void heapifyUp() {
        int index = size - 1;
        while (index > 0) {
            int parentIndex = (index - 1) / 2; 
            if (heap[index] < heap[parentIndex]) {
                std::swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    void heapifyDown() {
        int index = 0;

        while (2 * index + 1 < size) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int minIndex = index;

            if (leftChild < size && heap[leftChild] < heap[minIndex]) {
                minIndex = leftChild;
            }

            if (rightChild < size && heap[rightChild] < heap[minIndex]) {
                minIndex = rightChild;
            }

            if (minIndex != index) {
                std::swap(heap[index], heap[minIndex]);
                index = minIndex;
            } else {
                break;
            }
        }
    }

public:
    MinHeap(int capacity) : capacity(capacity), size(0) {
        heap = new int[capacity];
    }

    ~MinHeap() {
        delete[] heap;
    }

    void insert(int value) {
        if (size == capacity) {
            std::cout << "Heap is full. Cannot insert element.\n";
            return;
        }

        heap[size] = value;
        size++;
        heapifyUp();
    }

    int extractMin() {
        if (size == 0) {
            std::cout << "Heap is empty.\n";
            return -1;
        }

        int min = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown();
        return min;
    }

    void display() {
        std::cout << "Min Heap elements: ";
        for (int i = 0; i < size; ++i) {
            std::cout << heap[i] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    MinHeap minHeap(5);

    minHeap.insert(10);
    minHeap.insert(20);
    minHeap.insert(5);
    minHeap.insert(15);
    minHeap.insert(25);

    minHeap.display();

    std::cout << "Min element extracted: " << minHeap.extractMin() << "\n";

    minHeap.display();

    return 0;
}
