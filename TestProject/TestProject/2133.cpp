#include <bits/stdc++.h>
using namespace std;
long long dp[31];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;
	for (int i = 3; i <= n; i++) {
		if (i % 2 == 0) {
			dp[i] = dp[i - 2] * 3;
			for (int j = 4; j <= i; j += 2) {
				dp[i] += 2 * dp[i-j];
			}
			
		}
	}

	cout << dp[n];
	return 0;
}