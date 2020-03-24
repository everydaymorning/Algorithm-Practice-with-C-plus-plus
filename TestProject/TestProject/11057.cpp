#include <bits/stdc++.h>
using namespace std;
int dp[1001][10];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;

	for (int i = 0; i <= n; i++) {
		dp[i][0] = 1;
	}

	for (int i = 0; i < 10; i++) {
		dp[0][i] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 9; j++) {
			dp[i][j + 1] = (dp[i - 1][j + 1] + dp[i][j]) % 10007;
		}
	}

	cout << dp[n][9] % 10007;
	return 0;
}