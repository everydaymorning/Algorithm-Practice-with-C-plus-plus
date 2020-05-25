#include <bits/stdc++.h>
using namespace std;
int arr[5] = { 1,3,4,2,6 };

int sequential_search(int location, int n, int key) {
	while (location < n && arr[location] != key) {
		location++;
		if (location >= n) location = 0;
	}
	return location;
}
int main() {
	int key = 6;
	int location = 0;
	int n = 5;
	int index = sequential_search(location, n, key);
	cout << index;
	return 0;
}