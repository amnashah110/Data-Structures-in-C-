#include <iostream>
using namespace std;

class Node {
public:
    string name, description;
    int ID, price;

    Node(int id = 0, string n = "", string d = "", int p = 0) {
        ID = id;
        name = n;
        description = d;
        price = p;
    }
};

class hashTable {
    static const int size = 10;
    Node* buckets[size];

public:
    hashTable() {
        for (int i = 0; i < size; i++) {
            buckets[i] = nullptr;
        }
    }

    int hashFunction(int key) {
        return key % size;
    }

    void insert(int id, string n, string d, int p) {
        int index = hashFunction(id);

        // Linear probing
        while (buckets[index] != nullptr) {
            index = (index + 1) % size;
        }

        buckets[index] = new Node(id, n, d, p);
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << ":  ";
            if (buckets[i] != nullptr) {
                cout << buckets[i]->ID;
            }
            cout << endl;
        }
    }

    void search(int ID) {
        int index = hashFunction(ID);

        while (buckets[index] != nullptr && buckets[index]->ID != ID) {
            index = (index + 1) % size;
        }

        if (buckets[index] == nullptr) {
            cout << "Item not found";
        } else {
            cout << "Product found: " << endl;
            cout << "ID: " << buckets[index]->ID << endl;
            cout << "Name: " << buckets[index]->name << endl;
            cout << "Description: " << buckets[index]->description << endl;
            cout << "Price: " << buckets[index]->price << endl;
        }
    }

    void remove(int ID) {
        int index = hashFunction(ID);

        while (buckets[index] != nullptr && buckets[index]->ID != ID) {
            index = (index + 1) % size;
        }

        if (buckets[index] == nullptr) {
            cout << "Item not found";
        } else {
            delete buckets[index];
            buckets[index] = nullptr;
            cout << ID << " Deleted";
        }
    }
};

int main() {
    hashTable hash;
    hash.insert(1234, "Clothes", "To wear", 100);
    hash.insert(1214, "Food", "To eat", 500);
    hash.insert(1111, "Food", "To eat", 500);

    hash.search(1111);
    cout << endl;

    //hash.remove(1214);
    cout << endl << endl;

    hash.display();
}
