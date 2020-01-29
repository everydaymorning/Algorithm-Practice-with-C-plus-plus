#include <bits/stdc++.h>
using namespace std;
long long dp[1000001];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int t, n;
	cin >> t;

	while (t--) {
		cin >> n;
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		for (int i = 4; i <= n; i++) {
			dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1]) % 1000000009;
		}

		cout << dp[n] % 1000000009 << '\n';
	}

	return 0;
}