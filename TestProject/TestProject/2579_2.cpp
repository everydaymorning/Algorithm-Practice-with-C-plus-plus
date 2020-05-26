#include <bits/stdc++.h>
using namespace std;
int s[301];
int dp[301][3];
int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}

	dp[1][1] = s[1];
	dp[1][2] = 0;

	for (int i = 2; i <= n; i++) {
		dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + s[i];
		dp[i][2] = dp[i - 1][1] + s[i];
	}

	cout << max(dp[n][1], dp[n][2]);
	return 0;
}