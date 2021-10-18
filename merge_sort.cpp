#include <bits/stdc++.h>

using namespace std;

void merge(int arr[], int left, int mid, int right) {
	int leftSize = mid - left + 1;
	int rightSize = right - mid;

	int L[leftSize];
	int R[rightSize];

	for (int i = 0; i < leftSize; i++)
		L[i] = arr[left + i];

	for (int j = 0; j < rightSize; j++)
		R[j] = arr[mid + 1 + j];

	int i = 0;
	int j = 0;
	int k = left;

	while (i < leftSize && j < rightSize) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < leftSize) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < rightSize) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r) {
	if (l >= r)
		return;

	int mid = (l + r - 1) / 2;

	mergeSort(arr, l, mid);
	mergeSort(arr, mid + 1, r);
	merge(arr, l, mid, r);
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

	mergeSort(arr, 0, n - 1);
	cout << "Sorted list of elements is : ";
	for (int i=0 ; i<n ; i++)
		cout << arr[i] << " ";

	cout << "\n";

	return 0;
}