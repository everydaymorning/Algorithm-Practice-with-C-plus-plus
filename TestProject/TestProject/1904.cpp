#include <bits/stdc++.h>
using namespace std;
long long dp[1000001];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 2] + dp[i - 1] % 15746;
	}

	cout << dp[n] % 15746;

	return 0;
}