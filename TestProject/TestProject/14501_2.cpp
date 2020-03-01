#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int>> v;
int mx;
void dfs(int idx, int sum, int sum1) {
	if (idx == n) {
		cout << "idx == n" << '\n';
		cout << "sum: " << sum << '\n';
		mx = max(mx, sum);
		return;
	}
	else if (idx > n) {
		cout << "idx > n" << '\n';
		cout << "idx: " << idx << " sum - sum1: " << sum - sum1 << '\n';
		mx = max(mx, sum - sum1);
		return;
	}
	for (int i = idx; i < v.size(); i++) {
		int t = v[i].first;
		int p = v[i].second;
		cout << "i: " << i << " t: " << t << '\n';
		dfs(i + t, sum + p, p);
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	dfs(0, 0, 0);
	cout << mx;
	return 0;
}