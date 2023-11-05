#include <iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
	int size1 = mid - left+1;
	int size2 = right - mid;
	int arr1[size1];
	int arr2[size2]; // copies of subarrays made
	
	// transferring contents of subarrays into their copies
	for(int i = 0; i < size1; i++) {
		arr1[i] = arr[left+i]; 
	}
	for(int i = 0; i < size2; i++) {
		arr2[i] = arr[mid+1+i];
	}
	
	// indexes
	int i, j, k;
	i = 0;  // index for copy of first subarray
	j = 0; // index for copy of second subarray
	k = left; // index for array in which we'll copy and merge subarrays
	
	// merging
	while(i < size1 && j < size2) {
		if(arr1[i] <= arr2[j]) { 
			arr[k] = arr1[i];
			i++;
		} else {
			arr[k] = arr2[j];
			j++;
		}
		k++;
	}
	
	// if second subarray finished, copy all contents of first subarray into sorted array
	while(i < size1) {
		arr[k] = arr1[i];
		i++;
		k++;
	}
	
	// if first subarray finished, copy all contents of second subarray into sorted array
	while(j < size2) {
		arr[k] = arr2[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int left, int right) {
	if(left < right) {
		int mid = (left + right)/2; // mid is the point where array is divided into subarrays
		mergeSort(arr, left, mid); // first subarray from start to mid
		mergeSort(arr, mid+1, right); // second subarray after mid to end
		merge(arr, left, mid, right); // to merge the sorted subarrays into one array
	}
}

void print(int arr[], int size) {
	for(int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}

int main() {
	int arr[10] = {3, 6, 10, 1, 4, 7, 5, 9, 8, 2};
	int size = 10;
	mergeSort(arr, 0, size - 1);
	print(arr, size);
}