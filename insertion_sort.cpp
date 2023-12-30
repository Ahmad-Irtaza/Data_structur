#include <iostream>

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Place key at its correct position
        arr[j + 1] = key;
    }
}

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    const int size = 6;
    int arr[size] = {64, 34, 25, 12, 22, 11};

    std::cout << "Original array: ";
    displayArray(arr, size);

    insertionSort(arr, size);

    std::cout << "Sorted array: ";
    displayArray(arr, size);

    return 0;
}
