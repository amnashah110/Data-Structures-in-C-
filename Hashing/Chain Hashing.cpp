// each cell of hashtable points to a linked list
#include <iostream>
using namespace std;

class Node {
public:
	Node *next;
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
		for(int i = 0; i < size; i++) {
			buckets[i] = nullptr;
		}
	}
	
	int hashFunction(int key) {
		return key % size;
	}
	
	void insert(int id, string n, string d, int p) {
		int index = hashFunction(id);
		Node* newNode = new Node(id, n, d, p);
		
		if(!buckets[index]) {
			buckets[index] = newNode;
		} else {
			Node* current = buckets[index];
			while(current->next) {
				current = current->next;
			}
			current->next = newNode;
 		}
 		newNode->next = nullptr;
	}
	
	void display() {
		for(int i = 0; i < size; i++) {
			cout << i << ":  ";
			Node* current = buckets[i];
			while(current) {
				cout << current->ID;
				if(current->next != nullptr) {
					cout << " --> ";
				}
				current = current->next;
			}
			cout << endl;
		}
	}
	
	void search(int ID) {
		int index = hashFunction(ID);
		if(buckets[index] == 0) {
			cout << "Item not found";
		} else {
			Node* current = buckets[index];
			while(current->ID != ID && current != nullptr) {
				current = current->next;
			}
			if(!current) {
				cout << "Item not found";
			} else {
				cout << "Product found: " << endl;
				cout << "ID: " << current->ID << endl;
				cout << "Name: " << current->name << endl;
				cout << "Description: " << current->description << endl;
				cout << "Price: " << current->price << endl;
			}
		}
	}
	void remove(int ID) {
		int index = hashFunction(ID);
		if(buckets[index] == 0) {
			cout << "Item not found";
		} else {
			Node* current = buckets[index];
			Node* prev = nullptr;
			while(current != nullptr && current->ID != ID) {
				prev = current;
				current = current->next;
			}
			if(current == nullptr) {
				cout << "Item not found";
			} else {
				if(prev == nullptr) {
					buckets[index] = current->next;
				} else {
					prev->next = current->next;
				}
				delete current;
				cout << ID << " Deleted";
			}
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
	hash.remove(1214);
	cout << endl << endl;
	hash.display();
 }