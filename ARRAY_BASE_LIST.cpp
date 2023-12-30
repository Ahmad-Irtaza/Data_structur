
#include<iostream>
using namespace std;

class arrlist {
private:
    int *arr;
    int size;
    int elements;

public:
    arrlist(int size);
    void inser(int x);
    void delete_ele();
    void insertp(int p, int x);
    void print();
    void removebyp(int x);
    void val(arrlist &a);
    void insertionby_P(int x);
    ~arrlist();
};

arrlist::arrlist(int s) {
    this->size = s;
    arr = new int[size];
    elements = 0;
}

void arrlist::inser(int x) {
    if (size == elements) {
        cout << "list is full " << endl;
        return;
    }

    arr[elements] = x;
    elements++;
}

void arrlist::delete_ele() {
    elements--;
}

void arrlist::insertp(int p, int x) {
    if (p > elements + 1 || p < 1) {
        cout << "position does not exist" << endl;
        return;
    }

    int *curr = arr + elements;
    int *insertPos = arr + p - 1;

    while (curr >= insertPos) {
        *(curr + 1) = *curr;
        curr--;
    }

    *insertPos = x;
    elements++;
}

void arrlist::print() {
    int *curr = arr;

    for (int i = 1; i <= elements; i++) {
        cout << *curr << endl;
        curr++;
    }
}

void arrlist::removebyp(int x) {
    if (x < 0 || x >= elements) {
        cout << "not available" << endl;
        return;
    }

    int *p = arr + x - 1;
    int *end = arr + elements - 1;

    while (p < end) {
        *p = *(p + 1);
        p++;
    }

    elements--;
}

void arrlist::val(arrlist &a) {
    int *a1 = arr;
    int *b = a.arr;

    for (int i = 1; i <= elements; i++) {
        b = a.arr;
        for (int j = 1; j <= a.elements; j++) {
            if (*a1 == *b) {
                inser(*a1);
                break;
            }
            b++;
        }
        a1++;
    }
}

void arrlist::insertionby_P(int x) {
    if (elements == 0) {
        inser(x);
        return;
    }

    int *curr = arr;

    int i;
    for (i = 1; i <= elements; i++) {
        if (*curr > x) {
            insertp(i, x);
            return;
        }
        curr++;
    }

    insertp(i, x);
}

arrlist::~arrlist() {
    delete[] arr;
}

int main() {
    arrlist l1(4);
    arrlist l2(4);

    for (int i = 1; i <= 4; i++) {
        l1.inser(i);
        l2.inser(i + 1);
    }

    l1.val(l2);
    l1.print();

    return 0;
}
