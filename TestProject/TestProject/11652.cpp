#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int n;
	cin >> n;
	vector<long long> v;
	for (int i = 0; i < n; i++) {
		long long t;
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	long long ans = v.at(0);
	int cnt = 1;
	int cnt2 = 1;
	for (int i = 1; i < n; i++) {
		if (v.at(i) == v.at(i - 1)) {
			cnt++;
		}
		else cnt = 1;
		if (cnt2 < cnt) {
			cnt2 = cnt;
			ans = v.at(i);
		}

	}

	cout << ans;

	return 0;
}