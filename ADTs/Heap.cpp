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
		largest = arr[left];
	}
	if(right < size && arr[right] > arr[largest]) {
		largest = arr[right];
	}
	if(largest != i) {
		swap(arr[i], arr[largest]);
		maxHeapify(arr, size, largest);
	}
}

void minHeapify(int arr[], int size, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	
	if(left < size && arr[left] < arr[largest]) {
		largest = arr[left];
	}
	if(right < size && arr[right] < arr[largest]) {
		largest = arr[right];
	}
	if(largest != i) {
		swap(arr[i], arr[largest]);
		minHeapify(arr, size, largest);
	}
}

void constructMax(int arr[], int size) {
	int nonLeaf = (size/2) - 1;
	for(int i = nonLeaf; i >= 0; i--) {
		maxHeapify(arr, size, i);
	}
}

void constructMin(int arr[], int size) {
	int nonLeaf = (size/2) + 1;
	for(int i = nonLeaf; i >= 0; i--) {
		minHeapify(arr, size, i);
	}
}

int maxDelete(int arr[], int &size, int num) {
	int i = 0;
	for(i = 0; i < size; i++) {
		if(arr[i] == num) {
			break;
		}
	}
	swap(arr[i], arr[size-1]);
	size -= 1;
	maxHeapify(arr, size, 0);
	return size;
}

int minDelete(int arr[], int &size, int num) {
	int i = 0;
	for(i = 0; i < size; i++) {
		if(arr[i] == num) {
			break;
		}
	}
	swap(arr[i], arr[size-1]);
	size -= 1;
	minHeapify(arr, size, 0);
	return size;
}

void print(int arr[], int size) {
	for(int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}

int main() {
	int arr[5] = {1, 5, 3, 4, 2};
	int size = 5;
	constructMax(arr, size);
	print(arr, maxDelete(arr, size, 5));
}