#include<iostream>
using namespace std;

int main() {
    int *a = new int;
    int *b = new int;
    int *temp = new int;

    *a = 5;
    *b = 10;

    *temp = *a;
    *a = *b;
    *b = *temp;

    cout << "a: " << *a << ", b: " << *b << endl;

    delete a;
    delete b;
    delete temp;

    return 0;
}
