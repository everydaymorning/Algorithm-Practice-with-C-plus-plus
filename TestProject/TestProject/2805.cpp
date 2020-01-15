#include <bits/stdc++.h>
using namespace std;
long long arr[1000001];
int n, m;
long long h;
long long binarySearch(int s, int e, int target) {
	while (s <= e) {
		long long mid = (s + e) / 2;
		long long sum = 0;

		for (int i = 0; i < n; i++) {
			if(mid < arr[i]) sum += (arr[i] - mid);
		}

		if (sum >= m) {
			if (h < mid) h = mid;
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}

	return h;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
	long long mx = *max_element(arr, arr + n);
	cout << binarySearch(0, mx, m);

	return 0;


}