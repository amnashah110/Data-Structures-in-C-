#include <iostream>
using namespace std;

void intSearch(int arr[], int low, int high, int search) {
	while(low <= high && search >= arr[low] && search <= arr[high]) {
		int pos = low + ((double)(high-low)/(arr[high]-arr[low]) * (search - arr[low])); 
		if(arr[pos] == search) {
			cout << "Found at position " << pos+1;
			return;
		}
		if(search < arr[pos]) {
			high = pos - 1;
		} else {
			low = pos + 1;
		}
	}
}

int main() {
	int arr[10] = {2, 5, 6, 1, 3, 4, 7, 10, 9, 8};
	intSearch(arr, 0, 9, 4);
}