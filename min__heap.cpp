#include <iostream>
using namespace std;
class minheap {
  int size;
  int *arr;

public:
  void min_heap(int i) {
    int smallest = i;   
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left < size && arr[left] < arr[smallest]) {
      smallest=left;
    }
    if (right < size && arr[right] < arr[smallest]) {
      smallest=right;
    }
    if (smallest != i) {
      swap(arr[i], arr[smallest]);
      min_heap(smallest);
      
    }
      }
      minheap(int inputarr[], int n) {
    size = n;
    arr = new int[size];
    for (int i = 0; i < size; i++) {
      arr[i]=inputarr[i];
    }
        bulidminheap();
}
    void bulidminheap() {
    for (int i = size / 2 ; i >= 0; i--) {
      min_heap(i);
      
    }
    }
    void display() {
    cout << "min heap" << endl;
    for (int i = 0; i < size; i++) {
      cout<<arr[i]<<" ";
    
    }
    }

      };
     int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    minheap minHeap(arr, n);

    minHeap.display();

    return 0;
}