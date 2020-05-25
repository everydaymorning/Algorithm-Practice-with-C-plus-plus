#include <bits/stdc++.h>
using namespace std;

int binarySearch(int n, int* arr, int key) {
	int location, low, high, mid;
	low = 1;
	high = n;
	location = 0;

	while (low <= high && location == 0) {
		mid = (low + high) / 2;

		if (arr[mid] == key) {
			location = mid;
			break;
		}
		else if (arr[mid] > key) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return location;
}

int binarySearchRecursion(int low, int high, int* arr, int key) {
	int mid;
	if (low > high) return 0;
	else {
		mid = (low + high) / 2;
		if (arr[mid] == key) {
			return mid;
		}
		else if (arr[mid] > key) {
			binarySearchRecursion(low, mid - 1, arr, key);
		}
		else {
			binarySearchRecursion(mid + 1, high, arr, key);
		}
	}
	
}
int main() {
	int arr[5] = { 1,2,4,5,6 };
	int n = 5;
	int key = 6;

	int index = binarySearch(n, arr, key);
	int idx = binarySearchRecursion(0, n, arr, key);
	cout << index << '\n';
	cout << idx << '\n';
	return 0;
}