#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j == 0 || j == i) dp[i][j] = 1;
			else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] % 10007;
		}
	}
	
	cout << dp[n][k] % 10007;
	return 0;
}