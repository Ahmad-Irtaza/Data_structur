#include <iostream>

class MaxHeap {
private:
    int* heap;
    int capacity;
    int size;

    void heapifyUp() {
        int index = size - 1;
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] > heap[parentIndex]) {
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
            int maxIndex = index;

            if (leftChild < size && heap[leftChild] > heap[maxIndex]) {
                maxIndex = leftChild;
            }

            if (rightChild < size && heap[rightChild] > heap[maxIndex]) {
                maxIndex = rightChild;
            }

            if (maxIndex != index) {
                std::swap(heap[index], heap[maxIndex]);
                index = maxIndex;
            } else {
                break;
            }
        }
    }

public:
    MaxHeap(int capacity) : capacity(capacity), size(0) {
        heap = new int[capacity];
    }

    ~MaxHeap() {
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

    int extractMax() {
        if (size == 0) {
            std::cout << "Heap is empty.\n";
            return -1;
        }

        int max = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown();
        return max;
    }

    void display() {
        std::cout << "Max Heap elements: ";
        for (int i = 0; i < size; ++i) {
            std::cout << heap[i] << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    MaxHeap maxHeap(5);

    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(5);
    maxHeap.insert(15);
    maxHeap.insert(25);

    maxHeap.display();

    std::cout << "Max element extracted: " << maxHeap.extractMax() << "\n";

    maxHeap.display();

    return 0;
}
