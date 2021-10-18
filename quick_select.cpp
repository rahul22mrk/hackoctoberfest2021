#include <iostream>

using namespace std;

void swap(int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int *arr, int lo, int hi, int pivot) {
    int i = lo, j = lo;

    while (i <= hi) {
        if (arr[i] <= pivot) {
            swap(arr, i, j);
            i++;
            j++;
        }
        else {
            i++;
        }
    }
    
    return j-1;
}

int quick_select(int *arr, int lo, int hi, int mini) {
    if (lo < hi) {
        int pivot = partition(arr, 0, hi, arr[hi]);
        if (mini < pivot) {
            return quick_select(arr, lo, pivot-1, mini);
        }
        else if (mini > pivot) {
            return quick_select(arr, pivot + 1, hi, mini);
        }
        else {
            return pivot-1;
        }
    }
}

int main()
{
    int size;
    cout << "Enter the size of array\n>";
    cin >> size;

    int *arr = new int[size];
    cout << "\nEnter the elements of array :\n";
    for (int i=0 ; i<size ; i++) {
        cin >> arr[i];
    }

    cout << "\nWhich smallest element is to be selected ?\n>";
    int mini;
    cin >> mini;

    cout << "\nThe number is : " << arr[quick_select(arr, 0, size - 1, mini)] << endl;
    return 0;
}