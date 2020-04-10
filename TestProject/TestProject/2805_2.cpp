#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<long long> v;
	for (int i = 0; i < n; i++) {
		long long a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	long long low = 0;
	long long high = *max_element(v.begin(), v.end());
	long long ans = 0;
	while (low <= high) {
		long long mid = (low + high) / 2;
		long long sum = 0;
		for (int i = 0; i < v.size(); i++) {
			long long tmp = v[i] - mid;
			if (tmp > 0) sum += tmp;
		}

		if (sum >= m) {
			ans = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	cout << ans;
	return 0;
}