#include <bits/stdc++.h>

using namespace std;

void bubbleSort(int arr[], int n) {
	for (int count=0 ; count<n-1 ; count++) {
		for (int i=0 ; i<n-1 ; i++) {
			if (arr[i] > arr[i+1]) {
				int temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		}
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

	bubbleSort(arr, n);
	cout << "Sorted list of elements is : ";
	for (int i=0 ; i<n ; i++)
		cout << arr[i] << " ";

	cout << "\n";
	
	return 0;
}