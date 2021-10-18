#include <bits/stdc++.h>

using namespace std;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int pivot(int arr[], int left, int right) {
	int p = arr[right];
	int i = left - 1;

	for (int j = left; j < right; j++) {
		if (arr[j] < p) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[right]);

	return i+1;
}

void quickSort(int arr[], int left, int right) {
	if (left > right)
		return;

	int p = pivot(arr, left, right);

	quickSort(arr, left, p - 1);
	quickSort(arr, p + 1, right);
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

	quickSort(arr, 0, n - 1);
	cout << "Sorted list of elements is : ";
	for (int i=0 ; i<n ; i++)
		cout << arr[i] << " ";

	cout << "\n";

	return 0;
}