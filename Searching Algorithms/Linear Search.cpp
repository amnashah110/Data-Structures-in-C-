#include <iostream>
using namespace std;

void linearSearch(int arr[], int size, int search) {
	bool found = false;
	int i = 0;
	while(!found && i < size) {
		if(arr[i] == search) {
			found = true;
		}
		i++;
	}
	if(found) {
		cout << "Found at position " << i << endl;
	} else {
		cout << "Not found" << endl;
	}
}

int main() {
	int arr[10] = {2, 5, 6, 1, 3, 4, 7, 10, 9, 8};
	linearSearch(arr, 10, 4);
}