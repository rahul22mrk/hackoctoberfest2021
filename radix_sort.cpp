#include <bits/stdc++.h>

using namespace std;

void countSort(vector<int> &arr, int n, int exp) {
	int size = (*max_element(arr.begin(), arr.end()) 
					- *min_element(arr.begin(), arr.end())) + 1;

	vector<int> count(size, 0);
	vector<int> sol(n);

	for (int i = 0; i < n; i++) {
		count[(arr[i] / exp) % 10]++;
	}

	for (int i = 1; i < count.size(); i++) {
		count[i] += count[i - 1];
	}

	for (int i = n - 1; i >= 0; i--) {
		sol[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (int i = 0; i < n; i++) {
		arr[i] = sol[i];
	}
}

void radixSort(vector<int> &arr, int n) {
	int max = *max_element(arr.begin(), arr.end());

	for (int exp = 1; max / exp > 0; exp *= 10) {
		countSort(arr, n, exp);
	}
}

int main()
{
	cout << "Enter the number of elements to be entered : ";
	int n;
	cin >> n;

	vector<int> arr(n, 0);
	cout << "Enter the elements : \n";
	for (int i=0 ; i<n ; i++)
		cin >> arr[i];

	radixSort(arr, n);
	cout << "Sorted list of elements is : ";
	for (int i=0 ; i<n ; i++)
		cout << arr[i] << " ";

	cout << "\n";

	return 0;
}