#include <bits/stdc++.h>

using namespace std;

void countingSort(vector<int> &arr, int n) {
	int max = *max_element(arr.begin(), arr.end());
	int min = *min_element(arr.begin(), arr.end());

	int range = max - min + 1;

	vector<int> count (range);
	vector<int> sol(n);

	for (int i = 0; i < arr.size(); i++) {
		count[arr[i] - min]++;
	}

	for (int i = 1; i < count.size(); i++) {
		count[i] += count[i - 1];
	}

	for (int i = arr.size() - 1; i >= 0; i--) {
		sol[count[arr[i] - min] - 1] = arr[i];
		count[arr[i] - min]--;
	}

	for (int i = 0; i < sol.size(); i++) {
		cout << sol[i] << " ";
	}
}

int main()
{
	cout << "Enter the number of elements to be entered : ";
	int n;
	cin >> n;

	vector<int> arr(n, 0);
	cout << "Enter the elements : \n";
	for (int i=0 ; i<n ; i++) {
		cin >> arr[i];
	}

	cout << "Sorted list of elements is : ";
	countingSort(arr, n);

	cout << "\n";

	return 0;
}