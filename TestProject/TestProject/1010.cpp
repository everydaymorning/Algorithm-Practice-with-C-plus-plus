#include <bits/stdc++.h>
using namespace std;
int dp[31][31];
int func(int a, int b) {
	if (a == b || b == 0) return 1;
	if (dp[a][b]) return dp[a][b];
	return dp[a][b] = func(a - 1, b - 1) + func(a - 1, b);
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, m, t;
	cin >> t;
	while (t--) {
		cin >> n >> m;

		int res = func(m, n);

		cout << res << '\n';
	}
	

	return 0;
}