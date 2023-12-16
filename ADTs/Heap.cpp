#include <iostream>
using namespace std;

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void maxHeapify(int arr[], int size, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	
	if(left < size && arr[left] > arr[largest]) {
		largest = left;
	}
	if(right < size && arr[right] > arr[largest]) {
		largest = right;
	}
	if(largest != i) {
		swap(arr[i], arr[largest]);
		maxHeapify(arr, size, largest);
	}
}

void minHeapify(int arr[], int size, int i) {
	int smallest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	
	if(left < size && arr[left] < arr[smallest]) {
		smallest = left;
	}
	if(right < size && arr[right] < arr[smallest]) {
		smallest = right;
	}
	if(smallest != i) {
		swap(arr[smallest], arr[i]);
		minHeapify(arr, size, smallest);
	}
}

void constructMax(int arr[], int size) {
	int nonLeaf = (size/2) - 1;
	for(int i = nonLeaf; i >= 0; i--) {
		maxHeapify(arr, size, i);
	}
}

void constructMin(int arr[], int size) {
	int nonLeaf = (size/2) - 1;
	for(int i = nonLeaf; i >= 0; i--) {
		minHeapify(arr, size, i);
	}
}

void minDelete(int arr[], int &size, int num) {
	int i = 0;
	for(int i = 0; i < size; i++) {
		if(arr[i] == num) {
			swap(arr[i] , arr[size - 1]);
			size -= 1;
			minHeapify(arr, size, i);
			return;
		}
	}
	cout << "Not Found" << endl;
}

void maxDelete(int arr[], int &size, int num) {
	int i = 0; 
	for(int i = 0; i < size; i++) {
		if(arr[i] == num) {
			swap(arr[i], arr[size - 1]);
			size -= 1;
			maxHeapify(arr, size, i);
			return;
		}
	}
	cout << "Not Found" << endl;
}

void minInsert(int arr[], int &size, int num) {
	size += 1;
	arr[size - 1] = num;
	constructMin(arr, size);
}

void maxInsert(int arr[], int &size, int num) {
	size += 1;
	arr[size - 1] = num;
	constructMax(arr, size);
}

void printHeap(int arr[], int size) {
	for(int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[5] = {5, 3, 7, 4, 6};
	int size = 5;
	constructMin(arr, size);
	printHeap(arr, size);
	minInsert(arr, size, 2);
	printHeap(arr, size);
}
