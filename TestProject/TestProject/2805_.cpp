#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

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

		if (sum > m) {
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