#include <iostream>

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
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

    bubbleSort(arr, size);

    std::cout << "Sorted array: ";
    displayArray(arr, size);

    return 0;
}
