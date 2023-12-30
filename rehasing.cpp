#include <iostream>
using namespace std;
class HashTable {
private:
    int* table;
    int size;
    int currentSize;
    double loadFactorThreshold;

public:
    HashTable(int initialSize) : size(initialSize), currentSize(0), loadFactorThreshold(0.7) {
        table = new int[size];
        for (int i = 0; i < size; ++i) {
            table[i] = -1;
        }
    }

    ~HashTable() {
        delete[] table;
    }

    int hashFunction(int key) {
        return key % size;
    }

    void insert(int key) {
        if (static_cast<double>(currentSize) / size >= loadFactorThreshold) {
            rehash();
        }

        int index = hashFunction(key);

        while (table[index] != -1) {
            index = (index + 1) % size;
        }

        table[index] = key;
        currentSize++;
    }

    void rehash() {
        int newSize = 2 * size;
        int* newTable = new int[newSize];

        for (int i = 0; i < newSize; ++i) {
            newTable[i] = -1;
        }

        for (int i = 0; i < size; ++i) {
            if (table[i] != -1) {
                int newIndex = findNextEmptyIndex(newTable, hashFunction(table[i]), newSize);
                newTable[newIndex] = table[i];
            }
        }

        delete[] table;
        table = newTable;
        size = newSize;
    }

    int findNextEmptyIndex(const int* newTable, int index, int newSize) {
        for (int attempt = 0; newTable[index] != -1; ++attempt) {
            index = (index + 1) % newSize;
        }
        return index;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            if (table[i] != -1) {
                cout << "Element at[" << i << "] : " << table[i] << endl;
            }
        }
        cout << endl;
    }
};

int main() {
    HashTable Htable(7);

    Htable.insert(13);
    Htable.insert(15);
    Htable.insert(24);
    Htable.insert(6);

    cout << "Hash Table before rehashing:" << endl;
    Htable.display();

    Htable.insert(23);

    cout << "Hash Table after rehashing:" << endl;
    Htable.display();

    return 0;
}
