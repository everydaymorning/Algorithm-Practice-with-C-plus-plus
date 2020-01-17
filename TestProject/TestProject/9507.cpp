#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		long long dp[68] = { 0 };
		dp[0] = 1;
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		for (int i = 4; i <= n; i++) {
			dp[i] = dp[i - 4] + dp[i - 3] + dp[i - 2] + dp[i - 1];
		}

		cout << dp[n] << '\n';
	}

	return 0;
}