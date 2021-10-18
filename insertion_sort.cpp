#include <bits/stdc++.h>

using namespace std;

void insertionSort(int arr[], int n) {
	int key;
	int j;

	for (int i = 0; i < n; i++) {
		key = arr[i];
		j = i-1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j -= 1;
		}

		arr[j + 1] = key;
	}
}

int main()
{
	cout << "Enter the number of elements to be entered : ";
	int n;
	cin >> n;

	int arr[n];
	cout << "Enter the elements : \n";
	for (int i=0 ; i<n ; i++)
		cin >> arr[i];

	insertionSort(arr, n);
	cout << "Sorted list of elements is : ";
	for (int i=0 ; i<n ; i++)
		cout << arr[i] << " ";

	cout << "\n";

	return 0;
}