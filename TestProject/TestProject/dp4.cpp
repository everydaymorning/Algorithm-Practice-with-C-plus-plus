#include <bits/stdc++.h>
using namespace std;
int dp[101][101];
int main() {
	int m, n;
	cin >> m >> n;
	vector<vector<int>> puddles;
	puddles.push_back({ 2,2 });
	for (int i = 0; i < puddles.size(); i++) {
		dp[puddles[i][1] - 1][puddles[i][0] - 1] = -1;
	}
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 && j == 0) continue;
			if (dp[i][j] == -1) {
				dp[i][j] = 0;
				continue;
			}
			if (i == 0) {
				dp[i][j] += dp[i][j - 1] % 1000000007;
			}
			else if (j == 0) {
				dp[i][j] += dp[i - 1][j] % 1000000007;
			}
			else {
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
			}
		}
	}
	cout << dp[n - 1][m - 1] % 1000000007;
	return 0;

}