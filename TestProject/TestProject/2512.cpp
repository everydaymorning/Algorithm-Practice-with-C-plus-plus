#include <bits/stdc++.h>
using namespace std;
int n, m;
long long arr[10001];
long long res;
long long binary_func(long long start, long long end) {
	while (start <= end) {
		long long mid = (start + end) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] < mid) sum += arr[i];
			else sum += mid;
		}
		if (sum <= m) {
			if (res < mid) res = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return res;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int mx = *max_element(arr, arr + n);
	cin >> m;
	cout << binary_func(0, mx);

	return 0;
}