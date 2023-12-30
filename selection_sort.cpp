#include <iostream>

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        // Find the minimum element in the unsorted part of the array
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]);
        }
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

    selectionSort(arr, size);

    std::cout << "Sorted array: ";
    displayArray(arr, size);

    return 0;
}
