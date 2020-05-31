#include <bits/stdc++.h>
using namespace std;

int number = 10;
int arr2[10];
void quicksort(int* data, int start, int end);

void merge(int* arr, int low, int high) {
	int mid = (low + high) / 2;
	int i = low;
	int j = mid + 1;
	int k = low;

	while (i <= mid && j <= high) {
		if (arr[i] <= arr[j]) {
			arr2[k++] = arr[i++];
		}
		else {
			arr2[k++] = arr[j++];
		}
	}

	int tmp = i > mid ? j : i;

	if (i > mid) {
		for (int a = j; a <= high; a++) {
			arr2[k++] = arr[a];
		}
	}
	else {
		for (int a = i; a <= mid; a++) {
			arr2[k++] = arr[a];
		}
	}

	for (int a = low; a <= high; a++) {
		arr[a] = arr2[a];
	}
}
void partition(int* arr, int low, int high) {
	if (low >= high) return;

	int mid = (low + high) / 2;

	partition(arr, low, mid);
	partition(arr, mid + 1, high);
	merge(arr, low, high);
}
int main() {
	int arr[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

	partition(arr, 0, 9);
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
}

void quicksort(int* data, int start, int end) {
	if (start >= end) {
		return;
	}

	int key = start;
	int i = start + 1;
	int j = end;
	int tmp;

	while (i <= j) {
		while (i <= end && data[i] <= data[key]) {
			i++;
		}
		while (j > start && data[j] >= data[key]) {
			j--;
		}

		if (i > j) {
			tmp = data[j];
			data[j] = data[key];
			data[key] = tmp;
		}
		else {
			tmp = data[i];
			data[i] = data[key];
			data[key] = tmp;
		}
	}

	quicksort(data, start, j - 1);
	quicksort(data, j + 1, end);
}
