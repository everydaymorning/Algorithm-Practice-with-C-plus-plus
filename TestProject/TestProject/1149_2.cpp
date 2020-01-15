#include <bits/stdc++.h>
using namespace std;
int dp[1001][3];
int s[1001][3];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i][0] >> s[i][1] >> s[i][2];
	}

	dp[0][0] = s[0][0];
	dp[0][1] = s[0][1];
	dp[0][2] = s[0][2];
	for (int i = 1; i < n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + s[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + s[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + s[i][2];
	}

	int res = min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
	cout << res;

	return 0;
}