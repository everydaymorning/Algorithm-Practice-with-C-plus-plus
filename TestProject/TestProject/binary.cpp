#include <bits/stdc++.h>
using namespace std;

bool binary__(int* arr, int start, int end, int target) {
	while (start <= end) {
		int mid = (start + end) / 2;

		if (arr[mid] == target) {
			return true;
		}
		if (arr[mid] < target) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return false;
}
int main() {
	int m;
	cin >> m;

	int arr[10] = { 1,3,2,5,10,23,0,6,9,22 };
	sort(arr, arr + 10);
	if (binary__(arr, 0, 10, m)) cout << "found" << "\n";
	else cout << "not found" << '\n';

	return 0;

}