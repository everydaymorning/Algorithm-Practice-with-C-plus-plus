#include <bits/stdc++.h>
using namespace std;
int arr[1001];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, l;
	cin >> n >> l;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int cnt = 1;
	int tmp = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] - tmp + 1 > l) {
			cnt++;
			tmp = arr[i];
		}
	}

	cout << cnt;
	return 0;
}