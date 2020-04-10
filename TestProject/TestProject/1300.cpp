#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, k;
	cin >> n;
	cin >> k;
	
	int low = 1;
	int high = k;
	int ans = 0;
	while (low <= high) {
		int mid = (low + high) / 2;
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			int cnt = min(mid / i, n);
			sum += cnt;
		}

		if (sum < k) {
			low = mid + 1;
		}
		else {
			ans = mid;
			high = mid - 1;
		}
	}
	cout << ans;
	return 0;
}