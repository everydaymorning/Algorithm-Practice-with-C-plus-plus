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
	sort(v.begin(), v.end());
	int low = 0;
	int high = *max_element(v.begin(), v.end());
	int res = 0;
	while (low <= high) {
		int mid = (low + high) / 2;
		int sum = 0;

		for (int i = 0; i < v.size(); i++) {
			if (mid > v[i]) sum += v[i];
			else sum += mid;
		}
		cout << "mid: " << mid << '\n';
		cout << "sum: " << sum << '\n';
		if (sum <= m) {
			if (res < mid) res = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	cout << "low: " << low << " high: " << high << '\n';
	cout << "res: " << res;
	
	return 0;
}