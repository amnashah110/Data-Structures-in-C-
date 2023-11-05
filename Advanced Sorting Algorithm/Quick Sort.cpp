#include <iostream>
using namespace std;

void swap(int *a, int *b) { // function to swap elements
  int t = *a;
  *a = *b;
  *b = t;
}

void print(int arr[], int size) {
	for(int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}

int partition(int arr[], int low, int high) {
	int pivot = arr[high]; // making the rightmost element of the array the pivot
	int i = low - 1; // setting the second ptr at greater
	
	for(int j = low; j < high; j++) { // traversing till we reach pivot/high
		if(arr[j] <= pivot) {
			i++;
			swap(&arr[i], &arr[j]); // compare each element j with pivot and swap when element at j is smaller
		}
	}
	swap(&arr[i+1], &arr[high]); // swap pivot with current i
	return (i+1);
}

void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi-1); // sort left side
		quickSort(arr, pi+1, high); // sort right side
	}
}

int main() {
	int arr[10] = {3, 6, 10, 1, 4, 7, 5, 9, 8, 2};
	quickSort(arr, 0, 9);
	print(arr, 10);
}