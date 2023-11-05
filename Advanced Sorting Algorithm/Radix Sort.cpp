#include <iostream>
using namespace std;

void print(int arr[], int size) {
	for(int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}

int getMax(int arr[], int size) {
	int max = arr[0];
	for(int i = 1; i < size; i++) {
		if(arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

void countingSort(int arr[], int size, int place) {
	int count[10] = {0}; // frequency
	int output[size]; // to store sorted elements
	
	// calculate count
	for(int i = 0; i < size; i++) {
		count[(arr[i]/place) % 10]++;
	}
	
	// cumulative sum
	for(int i = 1; i < 10; i++) {
		count[i] += count[i-1];
	}
	
	// place elements in sorted order
	for(int i = size-1; i >= 0; i--) {
		output[count[(arr[i]/place) % 10] - 1] = arr[i];
		count[(arr[i]/place) % 10]--;
	}
	
	// copy output into main array
	for(int i = 0; i < size; i++) {
		arr[i] = output[i];
	}
}

void radixSort(int arr[], int size) {
	int max = getMax(arr, size);
	for(int place = 1; max/place > 0; place *= 10) {
		countingSort(arr, size, place);
	}
}

int main() {
	int arr[10] = {123, 541, 761, 324, 910, 512, 650, 150, 329, 100};
	radixSort(arr, 10);
	print(arr, 10);
}