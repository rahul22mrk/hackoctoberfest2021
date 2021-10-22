#include<cstdlib>
#include<iostream>
#include<time.h>

using namespace std;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int pivot(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = low - 1;

	for (int j = low; j < high; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[high]);

	return (i+1);
}

int partition_r(int arr[], int low, int high){
	srand(time(NULL));
	int random = low + rand() % (high - low);

	swap(&arr[random], &arr[high]);

	return pivot(arr, low, high);
}

void quickSort(int arr[], int low, int high) {
	if (low < high){

		int p = partition_r(arr, low, high);

		quickSort(arr, low, p - 1);
		quickSort(arr, p + 1, high);
	}
}

int main()
{
	cout << "Enter the number of elements to be entered : ";
	int n;
	cin >> n;

	int arr[n];
	cout << "Enter the elements\n";
	for (int i=0 ; i<n ; i++){
		printf("%d). ",i+1);
		cin >> arr[i];
	}

	quickSort(arr, 0, n - 1);
	cout << "\nSorted list of elements are : ";
	for (int i=0 ; i<n ; i++)
		cout << arr[i] << " ";

	cout << "\n";

	return 0;
}
