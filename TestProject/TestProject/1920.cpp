#include <bits/stdc++.h>
using namespace std;
int arr[100001];

bool bin_search(int len, int key) {
	int start = 0;
	int end = len - 1;
	int mid = 0;

	while (end - start >= 0) {
		mid = (start + end) / 2;

		if (arr[mid] == key) return true;
		else if (arr[mid] > key) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}

	return false;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int t;
		cin >> t;
		if (bin_search(n, t)) printf("1");
		else printf("0");
		printf("\n");
	}

	return 0;
}