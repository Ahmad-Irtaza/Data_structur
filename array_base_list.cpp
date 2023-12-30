#include <iostream>
using namespace std;

int main() {
    // Creating an array
    int myArray[] = {1, 2, 3, 4, 5};

    // Accessing elements
    cout << "Element at index 2: " << myArray[2] << endl;

    // Insertion at the end
    myArray[5] = 6;
    cout << "After inserting 6 at the end: ";
    for (int i = 0; i < 6; ++i) {
        cout << myArray[i] << " ";
    }
    cout << endl;

    // Insertion at a specific index
    int newSize = 7;
    for (int i = newSize - 1; i > 2; --i) {
        myArray[i] = myArray[i - 1];
    }
    myArray[2] = 10;
    cout << "After inserting 10 at index 2: ";
    for (int i = 0; i < newSize; ++i) {
        cout << myArray[i] << " ";
    }
    cout << endl;

    // Deletion by value
    int valueToDelete = 4;
    for (int i = 0; i < newSize; ++i) {
        if (myArray[i] == valueToDelete) {
            for (int j = i; j < newSize - 1; ++j) {
                myArray[j] = myArray[j + 1];
            }
            newSize--;
            break;
        }
    }
    cout << "After removing 4: ";
    for (int i = 0; i < newSize; ++i) {
        cout << myArray[i] << " ";
    }
    cout << endl;

    // Searching for an element
    int elementToSearch = 3;
    for (int i = 0; i < newSize; ++i) {
        if (myArray[i] == elementToSearch) {
            cout << elementToSearch << " found at index " << i << endl;
            break;
        }
    }

    // Time complexity of operations
    // Access: O(1)
    // Insertion/Deletion: O(n)

    return 0;
}
