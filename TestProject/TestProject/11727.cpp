#include <bits/stdc++.h>
using namespace std;

long long dp[1001];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;

	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = (2 * dp[i - 2] + dp[i - 1]) % 10007;
	}

	cout << dp[n] % 10007;

	return 0;
}