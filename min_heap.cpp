#include <bits/stdc++.h>

using namespace std;

void Swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

class BinaryHeap {
private:
	int cap;
	int size;
	int *arr;

public:
	BinaryHeap(int capacity);

	static int parent(int i) { return ((i - 1) / 2); }

	static int left(int i) { return ((2 * i) + 1); }

	static int right(int i) { return ((2 * i) + 2); }

	void insertKey(int key);

	void heapify(int i);

	int getMin() const { return arr[0]; }

	int extractMin();
};

BinaryHeap::BinaryHeap(int capacity) {
	cap = capacity;
	arr = new int[cap];
	size = 0;
}

void BinaryHeap::insertKey(int key) {
	if (size == cap) {
		cout << "The heap is full. Cannot insert" << endl;
		return;
	}

	arr[size] = key;
	int i = size;
	size++;

	while (i != 0 && arr[parent(i)] > arr[i]) {
		Swap(&arr[parent(i)], &arr[i]);
		i = parent(i);
	}
}

void BinaryHeap::heapify(int i) {
	int l = left(i);
	int r = right(i);

	int small = i;

	if (l < size && arr[l] < arr[small]) {
		small = l;
	}

	if (r < size && arr[r] < arr[small]) {
		small = r;
	}

	if (small != i) {
		Swap(&arr[small], &arr[i]);
		heapify(small);
	}
}

int BinaryHeap::extractMin() {
	if (size == 0) {
		cout << "There are 0 elements in heap!\n";
		return -1;
	}

	if (size == 1) {
		size--;
		return arr[0];
	}

	int min = arr[0];

	arr[0] = arr[size - 1];
	size--;

	heapify(0);
	return min;
}

int main()
{
	BinaryHeap h(5);

	h.heapify(0);
	h.insertKey(7);
	h.insertKey(6);
	h.insertKey(2);
	h.insertKey(1);
	h.insertKey(4);

	cout << h.extractMin() << "\n";
	cout << h.extractMin() << "\n";
	cout << h.extractMin() << "\n";
	cout << h.extractMin() << "\n";
	cout << h.extractMin() << "\n";

	return 0;
}

