#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int>> v;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	for (int i = 0; i < n; i++) {
		int sum = 0;
		int t = v[i].first;
		int p = v[i].second;
		if (t + i > n) continue;
		sum += p;
		for (int j = i + t - 1; j < n; j++) {
			int t1 = v[j].first;
			int p1 = v[j].second;
			if (t1 + j > n) continue;
			sum += p1;
			for (int k = j + 1; k < n; k++) {
				int t2 = v[k].first;
				int p2 = v[k].second;
				if (t2 + k > n) continue;
				sum += p2;
			}
		}
		mx = max(sum, mx);

	}
	cout << mx;
	return 0;
}