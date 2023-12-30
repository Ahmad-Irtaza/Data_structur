#include <iostream>
using namespace std;

class MaxHeap {
private:
    int* arr;
    int size;

    void maxHeapify(int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && arr[left] > arr[largest])
            largest = left;

        if (right < size && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            maxHeapify(largest);
        }
    }

public:
    MaxHeap(int inputArr[], int n) {
        size = n;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = inputArr[i];
        }

        buildMaxHeap();
    }

    void buildMaxHeap() {
        for (int i = size / 2 - 1; i >= 0; i--) {
            maxHeapify(i);
        }
    }

    void displayHeap() {
        cout << "Max Heap: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~MaxHeap() {
        delete[] arr;
    }
};

int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create MaxHeap object
    MaxHeap maxHeap(arr, n);

    // Display the max heap
    maxHeap.displayHeap();

    return 0;
}
