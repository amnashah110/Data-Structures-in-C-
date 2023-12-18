#include <iostream>
using namespace std;

class hashTable {
	static const int size = 10;
	int *buckets;

public:
	hashTable() {
		buckets = new int[size];
		for(int i = 0; i < size; i++) {
			buckets[i] = 0;
		}
	}
	
	int hashFunction(int key) {
		return key % 10;
	}
	
	void insert(int key) {
		int index = hashFunction(key);
		int i = 1;
		while(buckets[index] != 0) {
			index = (index + i * i) % 10;
			i++;
		}
		buckets[index] = key;
	}
	
	void search(int key) {
		int index = hashFunction(key);
		int i = 1;
		while(buckets[index] != 0 && buckets[index] != key) {
			index = (index + i * i) % 10;
			i++;
		}
		if(buckets[index] != key) {
			cout << "Value not found";
		} else {
			cout << "Value found";
		}
	}
	
	void display() {
		for (int i = 0; i < size; i++) {
			cout << i << ": " << buckets[i] << endl;
		}
	}
	
	void remove(int key) {
		int index = hashFunction(key);
		int i = 1;
		while(buckets[index] != key) {
			index = (index + i * i) % 10;
			i++;
		}
		buckets[index] = 0;
	}
};

int main() {
	hashTable hash;
	hash.insert(2);
	hash.insert(7);
	hash.insert(3);
	hash.insert(22);
	hash.remove(2);
	hash.display();
}
