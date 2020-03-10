#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int n, s, cnt;

void dfs(int idx, int sum) {
	int tmp = sum + v[idx];
	cout << "idx: " << idx << " sum: " << sum << " tmp: " << tmp << '\n';

	if (tmp == s) cnt++;
	if (idx == n-1) return;
	dfs(idx + 1, sum);
	dfs(idx + 1, tmp);
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	dfs(0, 0);
	cout << cnt;
	return 0;
}