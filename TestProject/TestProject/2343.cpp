#include <bits/stdc++.h>
using namespace std;
int arr[100001];
int main() {
	int n, m;
	cin >> n >> m;

	int low = 0;
	int high = 0;
	int ans = 2147483647;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		high += arr[i];
	}
	low = *max_element(arr, arr + n);
	while (low <= high) {
		int mid = (low + high) / 2;
		int cnt = 0;
		int sum = 0;
		cout << "mid: " << mid << '\n';
		for (int i = 0; i < n; i++) {
			if (sum + arr[i] > mid) {
				cnt++;
				sum = 0;
			}
			sum += arr[i];
			cout << "sum: " << sum << '\n';
		}
		cout << "cnt: " << cnt << '\n';
		if (m <= cnt) {
			low = mid + 1;
		}
		else {
			if (ans > mid) ans = mid;
			cout << "ans: " << ans << '\n';
			high = mid - 1;
		}

	}
	cout << low;
	return 0;
}