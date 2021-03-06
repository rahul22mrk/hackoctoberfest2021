#include <bits/stdc++.h>

using namespace std;

void selectionSort(int arr[], int n) {
	int min = 0;
	
	for (int count = 0; count < n-1; count++) {
		int min = count;
		for (int i = count+1; i < n; ++i) {
			if (arr[i] < arr[min])
				min = i;
		}

		int temp = arr[min];
		arr[min] = arr[count];
		arr[count] = temp;
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

	selectionSort(arr, n);
	cout << "Sorted list of elements is : ";
	for (int i=0 ; i<n ; i++)
		cout << arr[i] << " ";

	cout << "\n";
	return 0;
}