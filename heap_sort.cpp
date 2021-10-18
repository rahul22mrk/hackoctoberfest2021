#include <bits/stdc++.h>

using namespace std;

void heapify(int arr[], int i, int n) {
	int l = 2*i + 1;
	int r = 2*i + 2;

	int smallest = i;

	if (l < n && arr[l] < arr[smallest])
		smallest = l;

	if (r < n && arr[r] < arr[smallest])
		smallest = r;

	if (smallest != i) {
		swap(arr[i], arr[smallest]);
		heapify(arr, smallest, n);
	}
}

void heapSort(int arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, i, n);
	}

	for (int i = n - 1; i > 0; i--) {
		swap(arr[i], arr[0]);

		heapify(arr, 0, i);
	}
}

int main() {
	int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    heapSort(arr, n);
 
    cout << "Sorted array is \n";

    for (int i = n - 1; i >= 0; i--) {
    	cout << arr[i] << "\t";
    }
    cout << endl;

    return 0;
}