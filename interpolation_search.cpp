#include <iostream>

int interpolation_search(int arr[], int value, int len) {
    int low = 0, high, mid;
    high = len - 1;

    while (arr[low] <= value && arr[high] >= value) {
        mid = (low +
               ((value - arr[low]) * (high - low)) / (arr[high] - arr[low]));
        if (arr[mid] > value)
            high = mid - 1;
        else if (arr[mid] < value)
            low = mid + 1;
        else
            return mid;
    }

    if (arr[low] == value)
        return low;

    return -1;
}

int main() {
    int n, value, re;

    std::cout << "Enter the size of array(less than 100) : ";
    std::cin >> n;

    int *array = new int[n];

    std::cout << "array in ascending (increasing) order : " << std::endl;

    for (int i = 0; i < n; i++) std::cin >> array[i];

    std::cout << "Enter the value you want to search : ";
    std::cin >> value;

    re = interpolation_search(array, value, n);

    if (re == -1)
        std::cout << "Entered value is not in the array" << std::endl;
    else
        std::cout << "The value is at the position " << re << std::endl;

    delete[] array;
    return 0;
}
