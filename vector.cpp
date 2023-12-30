#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> a1;
    int size;
    int ele;
    
    cout << "Enter the size: ";
    cin >> size;

    for (int i = 0; i < size; i++) {
        cout << "Enter the element: ";
        cin >> ele;
        a1.push_back(ele);
    }

    // Display the vector elements before popping
    cout << "Vector elements before popping: ";
    for (int i = 0; i < a1.size(); i++) {
        cout << a1[i] << " ";
    }

    // Use pop_back to remove the last element
    if (!a1.empty()) {
        a1.pop_back();
    }

    // Display the vector elements after popping
    cout << "\nVector elements after popping: ";
    for (int i = 0; i < a1.size(); i++) {
        cout << a1[i] << " ";
    }

    return 0;
}
