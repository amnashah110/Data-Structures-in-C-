#include <iostream>
using namespace std;

void binarySearch(int arr[], int low, int high, int search) {
	while(low <= high) {
		int mid = (low+high)/2;
		if(arr[mid] == search) {
			cout << "Found at position " << mid+1;
			return;
		}
		if(search < arr[mid]) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
}

int main() {
	int arr[10] = {2, 5, 6, 1, 3, 4, 7, 10, 9, 8};
	binarySearch(arr, 0, 10, 4);
}