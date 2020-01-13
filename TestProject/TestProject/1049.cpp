#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	int aa = 1001;
	int bb = 1001;
	vector<pair<int, int>> v;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
		aa = min(aa, a);
		bb = min(bb, b);
	}
	int tmp_min = 0;
	if (n < 6) {
		tmp_min = min(aa, bb * n);
	}
	else {
		int t = n / 6;
		int r = n % 6;
		tmp_min = min(aa * (t + 1), min(aa * t + bb * r, bb * n));
	}

	cout << tmp_min;

	return 0;
}